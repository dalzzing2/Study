package com.example.fileexplorer;

import java.io.File;
import java.util.ArrayList;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends Activity implements OnItemClickListener{

	ArrayList<String> fileList;
	ArrayAdapter<String> adapter;
	File currentDir;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		currentDir = getExternalFilesDir(null);
		fileList = new ArrayList<String>();
		updateFileList();
		
		ListView lv = (ListView)findViewById(R.id.listView1);
		adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, fileList);
		lv.setAdapter(adapter);
		lv.setOnItemClickListener(this);
	}
	
	protected void onPause(){
		SharedPreferences settings = getSharedPreferences("currentDir", Context.MODE_PRIVATE);
		SharedPreferences.Editor editor = settings.edit();
		editor.putString("currentDir", currentDir.toString());
		editor.commit();
		
		super.onPause();
	}
	
	protected void onResume(){
		SharedPreferences settings = getSharedPreferences("currentDir", Context.MODE_PRIVATE);
		String path = settings.getString("currentDir", "");
		if(path != "")
		{
			currentDir = new File(path);
			updateFileList();
		}
		super .onResume();
	}
	public void updateFileList(){
		String[] arr = new String[1];
		arr[0] = "..";
		
		TextView tv = (TextView)findViewById(R.id.textView1);
		tv.setText(currentDir.getPath());
		
		if(currentDir.isDirectory()){
			File[] files = currentDir.listFiles();
			if(files != null && files.length > 0){
				arr = new String[files.length+1];
				
				int j = 0;
				arr[j++] = "..";
				for(int i = 0 ; i < files.length; i++, j++)
					arr[j] = files[i].getName();
			}
		}
		
		fileList.clear();
		for(String s : arr) fileList.add(s);
	}
	
	public void onItemClick(AdapterView<?> arg0, View arg1, int position, long id){
		String name;
		File f;
		if(position == 0){
			f = currentDir.getParentFile();
		}
		else {
			name = fileList.get(position);
			f = new File(currentDir, name);
		}
		
		if(f == null)
			f = currentDir;
		
		if(f.isDirectory()){
			currentDir = f;
			updateFileList();
			adapter.notifyDataSetChanged();
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
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
