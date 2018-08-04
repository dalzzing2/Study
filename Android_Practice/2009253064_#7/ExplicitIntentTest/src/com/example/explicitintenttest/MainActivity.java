package com.example.explicitintenttest;

import com.example.memocpcontract.MemoContract;
import com.example.memocptest.MemoContentProvider;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import android.app.ListActivity;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.CursorAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.SimpleCursorAdapter;

public class MainActivity extends ListActivity {
	
	SimpleCursorAdapter adapter;
	SQLiteDatabase db;
	    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		ContentResolver cr = getContentResolver();
		Cursor cursor = cr.query(MemoContract.CONTENT_URI,  null,  null,  null,  null);
		
		String[] selectionArgs = { MemoContract.MEMO_TITLE };
		adapter = new SimpleCursorAdapter(this, android.R.layout.simple_list_item_1,
				cursor, selectionArgs, new int[] {android.R.id.text1},
				CursorAdapter.FLAG_REGISTER_CONTENT_OBSERVER );
		
		setListAdapter(adapter);
		getListView().setOnItemLongClickListener(ilcl);
		
	}
    
	public void onDestroy() {
		super.onDestroy();
	}
    
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// TODO Auto-generated method stub
		super.onCreateOptionsMenu(menu);
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.menu, menu);
		return true;
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// TODO Auto-generated method stub
		Intent intent = new Intent();
		intent.setClassName("com.example.explicitintenttest", "com.example.explicitintenttest.MemoActivity");
		intent.setAction("android.intent.action.CREATE");
		startActivityForResult(intent, 0);
		return super.onOptionsItemSelected(item);
	}
	
	protected void onActivityResult(int requestCode, int resultCode, Intent data){
		super.onActivityResult(requestCode, resultCode, data);
		ContentResolver cr = getContentResolver();
		if(resultCode == RESULT_OK){
			if(data.getBooleanExtra("isEdited", true)){
				long posId = adapter.getItemId(data.getIntExtra("position", -1));
				
				ContentValues cv = new ContentValues();
				cv.put(MemoContract.MEMO_TITLE,  data.getStringExtra("title"));
				cv.put(MemoContract.MEMO_CONTENT,  data.getStringExtra("contents"));
				cv.put(MemoContract.MEMO_DATE, Calendar.getInstance().getTime().toString());
				
				cr.update(ContentUris.withAppendedId(MemoContract.CONTENT_URI, posId),  cv,  null,  null);
				
			}
			else{
				ContentValues cv = new ContentValues();
				cv.put(MemoContract.MEMO_TITLE,  data.getStringExtra("title"));
				cv.put(MemoContract.MEMO_CONTENT,  data.getStringExtra("contents"));
				cv.put(MemoContract.MEMO_DATE, Calendar.getInstance().getTime().toString());
				
				cr.insert(MemoContract.CONTENT_URI, cv);
			}
			Cursor cursor = cr.query(MemoContract.CONTENT_URI,  null,  null,  null,  null);
			adapter.changeCursor(cursor);
			adapter.notifyDataSetChanged();
		}
		else if( resultCode == RESULT_CANCELED){
			
			
		}
	}

	private AdapterView.OnItemLongClickListener ilcl = new AdapterView.OnItemLongClickListener(){
		public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id){
			ContentResolver cr = getContentResolver();
			cr.delete(ContentUris.withAppendedId(MemoContract.CONTENT_URI, id),  null,  null);
			
			Cursor cursor = cr.query(MemoContract.CONTENT_URI,  null,  null,  null,  null);
			adapter.changeCursor(cursor);
			adapter.notifyDataSetChanged();
			return true;
		}
	};
	
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		Cursor cursor = db.rawQuery("SELECT * FROM " + MemoDBHelper.tableName + " WHERE " + MemoDBHelper.colID + " = " + id , null );
		cursor.moveToFirst();
		
		Intent intent = new Intent();
		intent.setClassName("com.example.explicitintenttest",
						"com.example.explicitintenttest.MemoActivity");
		intent.setAction("android.intent.action.EDIT");
		intent.putExtra("title", cursor.getString(1));
		intent.putExtra("contents", cursor.getString(2));
		intent.putExtra("position", position);
		startActivityForResult(intent, 0);

		super.onListItemClick(l, v, position, id);
	}
}