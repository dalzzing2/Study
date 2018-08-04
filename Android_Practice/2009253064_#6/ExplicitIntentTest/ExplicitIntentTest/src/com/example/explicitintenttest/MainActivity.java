package com.example.explicitintenttest;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;

import android.app.ListActivity;
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
	
	MemoDBHelper memoDbHelper;
	SimpleCursorAdapter adapter;
	SQLiteDatabase db;
	    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        memoDbHelper = new MemoDBHelper(this, null, 1);
        db = memoDbHelper.getWritableDatabase();

        Cursor cursor =
            db.rawQuery("SELECT * FROM " + MemoDBHelper.tableName, null);

        String[] selectionArgs = { MemoDBHelper.colTitle };	

        adapter = new SimpleCursorAdapter(this,
                            android.R.layout.simple_list_item_1, cursor,
                            selectionArgs, new int[] { android.R.id.text1 },
                            CursorAdapter.FLAG_REGISTER_CONTENT_OBSERVER );
                 
        setListAdapter(adapter);
        getListView().setOnItemLongClickListener(ilcl);
    }
    
    private AdapterView.OnItemLongClickListener ilcl = new AdapterView.OnItemLongClickListener() {

		@Override
		public boolean onItemLongClick(AdapterView<?> parent, View view,
                int position, long id) {
			db.execSQL("DELETE FROM " + MemoDBHelper.tableName
					+ " WHERE " + MemoDBHelper.colID + " = " + id );

			Cursor cursor = db.rawQuery("SELECT * FROM "
					+ MemoDBHelper.tableName, null);
			adapter.changeCursor(cursor);
			adapter.notifyDataSetChanged();
			return true;
		}
    	
    };
    
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		Cursor cursor = db.rawQuery("SELECT * FROM " + MemoDBHelper.tableName + " WHERE " + MemoDBHelper.colID + " = " + id , null );
		cursor.moveToFirst();
		//클릭한부분으로 커서가 이동한다.
		
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
		intent.setClassName("com.example.explicitintenttest", 
				"com.example.explicitintenttest.MemoActivity");
		intent.setAction("android.intent.action.CREATE");
		startActivityForResult(intent, 0);
		
		return super.onOptionsItemSelected(item);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		super.onActivityResult(requestCode, resultCode, data); 
	    if (resultCode == RESULT_OK) {
	      if (data.getBooleanExtra("isEdited", true)) {   
	        long posId =
	          adapter.getItemId(data.getIntExtra("position", -1));
	        db.execSQL("UPDATE " + MemoDBHelper.tableName + " SET "
	               + MemoDBHelper.colTitle + " = '"
	                  + data.getStringExtra("title") + "', "
	               + MemoDBHelper.colContent + " = '"
	                  + data.getStringExtra("contents") + "', "
	               + MemoDBHelper.colDate + " = '"
	                  + Calendar.getInstance().getTime().toString() +"'"
	               + " WHERE " + MemoDBHelper.colID + " = " + posId );
	      }
	      else {
	        db.execSQL("INSERT INTO " + MemoDBHelper.tableName
	      + " VALUES ( NULL, " + "'" + data.getStringExtra("title") + "', "
	      + "'" + data.getStringExtra("contents") + "', "
	      + "'" + Calendar.getInstance().getTime().toString() + "' ) "  );
	      }

	      
	      Cursor cursor =
	      db.rawQuery("SELECT * FROM " + MemoDBHelper.tableName, null);
	      adapter.changeCursor(cursor);
	      adapter.notifyDataSetChanged();

	    }
	    else if (resultCode == RESULT_CANCELED) {         
	    }
	}
}
