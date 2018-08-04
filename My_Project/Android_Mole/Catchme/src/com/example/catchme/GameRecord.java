package com.example.catchme;


import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.ListActivity;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.CursorAdapter;
import android.widget.SimpleCursorAdapter;

public class GameRecord extends ListActivity {
	
	GameDB GameDB;
	SimpleCursorAdapter adapter;
	SQLiteDatabase db;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        GameDB = new GameDB(this, null, 1);
        db = GameDB.getWritableDatabase();

        Cursor cursor =
            db.rawQuery("SELECT * FROM " + GameDB.tableName, null);
        cursor.moveToFirst();
        
        String[] selectionArgs = { GameDB.colName, GameDB.colScore, GameDB.colDate };	
        int[] selectionShapes = new int[]{R.id.txtdbName, R.id.txtdbScore, R.id.txtdbDate};
        
        adapter = new SimpleCursorAdapter(this,
        					R.layout.game_db, cursor,
                            selectionArgs, selectionShapes,
                            CursorAdapter.FLAG_REGISTER_CONTENT_OBSERVER );
        setListAdapter(adapter);
        getListView().setOnItemLongClickListener(ilcl);
    }
    
    private AdapterView.OnItemLongClickListener ilcl = new AdapterView.OnItemLongClickListener() {

		@Override
		public boolean onItemLongClick(AdapterView<?> parent, View view,
                int position, long id) {
			db.execSQL("DELETE FROM " + GameDB.tableName
					+ " WHERE " + GameDB.colID + " = " + id );

			Cursor cursor = db.rawQuery("SELECT * FROM "
					+ GameDB.tableName, null);
			adapter.changeCursor(cursor);
			adapter.notifyDataSetChanged();
			return true;
		}
    	
    };
    

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		super.onActivityResult(requestCode, resultCode, data); 
	    if (resultCode == RESULT_OK) {
	      if (data.getBooleanExtra("isEdited", true)) {   
	        long posId =
	          adapter.getItemId(data.getIntExtra("position", -1));
	        db.execSQL("UPDATE " + GameDB.tableName + " SET "
	               + GameDB.colName + " = '"
	                  + data.getStringExtra("name") + "', "
	               + GameDB.colScore + " = '"
	                  + data.getStringExtra("score") + "', "
	               + GameDB.colDate + " = '"
	                  + data.getStringExtra("date") +"'"
	               + " WHERE " + GameDB.colID + " = " + posId );
	      }
	      else {
	        db.execSQL("INSERT INTO " + GameDB.tableName
	      + " VALUES ( NULL, " + "'" + data.getStringExtra("title") + "', "
	      + "'" + data.getStringExtra("contents") + "', "
	      + "'" + data.getStringExtra("date") + "' ) "  );
	      }

	      
	      Cursor cursor =
	      db.rawQuery("SELECT * FROM " + GameDB.tableName, null);
	      adapter.changeCursor(cursor);
	      adapter.notifyDataSetChanged();

	    }
	    else if (resultCode == RESULT_CANCELED) {         
	    }
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		AudioManager am = (AudioManager)getSystemService(AUDIO_SERVICE);
		Vibrator vb = (Vibrator)getSystemService(VIBRATOR_SERVICE);
		
		switch(item.getItemId()){
		case R.id.beep:
			am.setRingerMode(AudioManager.RINGER_MODE_NORMAL);
			am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
			break;
		case R.id.vibration:
			//mp.stop();
			//vb.vibrate(100);
			am.setRingerMode(AudioManager.RINGER_MODE_VIBRATE);
			break;
		case R.id.silence:
			stopService(new Intent("android.intent.action.Game_Music"));
			am.setRingerMode(AudioManager.RINGER_MODE_SILENT);
			break;
		case R.id.startbackmusic:
			startService(new Intent("android.intent.action.Game_Music"));
			break;
		case R.id.stopbackmusic:
			stopService(new Intent("android.intent.action.Game_Music"));
			break;
		}
		return super.onOptionsItemSelected(item);
	}
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (event.getAction() == KeyEvent.ACTION_DOWN) {
			switch (keyCode) {
			case KeyEvent.KEYCODE_MENU:
				new DialogFragment() {
					public Dialog onCreateDialog(Bundle savedInstance) {
						AlertDialog.Builder builder = new AlertDialog.Builder(
								getActivity());
						builder.setMessage("       Copyright (C) 2014. ¹Ú¼±È£\n             all rights reserved. ");
						return builder.create();
					}
				}.show(getFragmentManager(), "AlertDialog");
				;
				break;
			}
		}
		return super.onKeyDown(keyCode, event);
	}
}
