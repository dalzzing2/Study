package com.example.weathertest;

import android.app.Activity;
import android.app.ListActivity;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.StrictMode;
import android.os.Vibrator;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.net.URL;
import java.util.ArrayList;

public class MainActivity extends ListActivity {
	final private String TAG = "PullParserTestActicity";
	ArrayList<Weather> weather = new ArrayList<Weather>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder().detectDiskReads().detectDiskWrites().detectNetwork().penaltyLog().build());
		temp();
		setListAdapter(new CustomRow(this));
	}
	public void temp(){
		try {
			URL url = new URL("http://www.kma.go.kr/XML/weather/sfc_web_map.xml");
			XmlPullParserFactory parserFactory = XmlPullParserFactory.newInstance();
			XmlPullParser parser = parserFactory.newPullParser();
			parser.setInput(url.openStream(), "utf-8");
			
			int parserEvent = parser.getEventType();
			String stnid = " ";
			String desc = " ";
			String ta = " ";
			String region = " ";
			
			String name = " ";
			while(parserEvent != XmlPullParser.END_DOCUMENT){
				switch(parserEvent){
				case XmlPullParser.START_DOCUMENT:
					Log.d(TAG, "Parser Start...!");
					break;
				case XmlPullParser.START_TAG:
					name = parser.getName();
					if(name != null && name.equals("local")){
						stnid = parser.getAttributeValue(null, "stn_id");
						desc = parser.getAttributeValue(null, "desc");
						ta = parser.getAttributeValue(null, "ta");
					}
					break;
				case XmlPullParser.TEXT:
					if(name != null && name.equals("local")){
						region = parser.getText();
						Log.i("PullParserTest", region);
					}
					break;
				case XmlPullParser.END_TAG:
					if(name != null && name.equals("local")){
						Weather w = new Weather(region, desc, ta, stnid);
						Log.i("PullParserTest", w.toString());
						weather.add(w);
					}
					name = " ";
					break;
				}
				parserEvent = parser.next();
			}
		}
		catch(Exception e){
			e.printStackTrace();
			Log.d(TAG, "error");
		}
	}

	class Weather{
		String region, desc, ta, stnid;
		
		public Weather(String region, String desc, String ta, String stnid){
			this.region = region;
			this.desc = desc;
			this.ta = ta;
			this.stnid = stnid;
		}
		
		public String toString(){
			return this.region + ", " + this.desc + ", " + this.ta + ", " + this.stnid;
		}
	}
	
	class CustomRow extends ArrayAdapter<Weather>{
		Activity context;
		public CustomRow(Activity c){
			super(c, R.layout.customcell, weather);
			this.context = c;
		}
		
		@Override
		public View getView(int position, View v, ViewGroup vg){
			LayoutInflater inf = context.getLayoutInflater();
			View customcell = inf.inflate(R.layout.customcell, null);
			
			TextView regionTextView = (TextView)customcell.findViewById(R.id.textView1);
			TextView conditionTextView = (TextView)customcell.findViewById(R.id.textView2);
			TextView taTextView = (TextView)customcell.findViewById(R.id.textView3);
			regionTextView.setText("지역 : "+weather.get(position).region);
			conditionTextView.setText("날씨 : "+weather.get(position).desc);
			taTextView.setText("기온 : "+weather.get(position).ta);
			
			return customcell;
		}
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.main, menu);
		return true;
	}
	
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		
		case R.id.update:
			temp();
			break;
		}
		return super.onOptionsItemSelected(item);
	}
}
