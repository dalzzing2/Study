package com.example.musicplayservicetest;

import java.util.ArrayList;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore.Audio;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends Activity {
	private ArrayList<Uri> musiclist;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		ListView lv = (ListView)findViewById(R.id.listView1);
		musiclist = new ArrayList<Uri>();
		
		lv.setAdapter(new MusicCursorAdapter(this, musiclist));
		lv.setOnItemClickListener(new OnItemClickListener(){
			public void onItemClick(AdapterView<?> parent, View itemview, int position, long id){
				Uri uri = musiclist.get(position);
				Intent intent = new Intent(MainActivity.this, MusicPlayService.class);
				intent.setData(uri);
				startService(intent);
			}
		});
	}
}
class MusicCursorAdapter extends BaseAdapter{
	private Cursor c;
	private Context ctx;
	private ArrayList<Uri> musiclist;
	
	public MusicCursorAdapter(Context context, ArrayList<Uri> musiclist){
		ctx = context;
		this.musiclist = musiclist;
		ContentResolver cr = context.getContentResolver();
		c = cr.query(Audio.Media.EXTERNAL_CONTENT_URI, null, null, null, null);
	}
	public int getCount() { return c.getCount(); }
	public Object getItem(int position) { return position; }
	public long getItemId(int position) { return position; }
	public View getView(int position, View convertView, ViewGroup parent){
		TextView textview;
		if(convertView == null){
			textview = new TextView(ctx);
			textview = (TextView)View.inflate(ctx, android.R.layout.simple_list_item_1, null);
		}
		else
			textview = (TextView) convertView;
		
		c.moveToPosition(position);
		Uri uri = Uri.withAppendedPath(
				Audio.Media.EXTERNAL_CONTENT_URI, c.getString(c.getColumnIndex(Audio.Media._ID)));
		musiclist.add(uri);
		textview.setText(c.getString(c.getColumnIndex(Audio.Media.DISPLAY_NAME)));
		
		return textview;
	}
}
