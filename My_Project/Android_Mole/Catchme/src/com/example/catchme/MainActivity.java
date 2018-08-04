package com.example.catchme;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.Intent;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.WindowManager;
import android.widget.ImageButton;

public class MainActivity extends Activity {

	private ImageButton button1, button2, button3, button4;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		button1 = (ImageButton)findViewById(R.id.game_start);
		button2 = (ImageButton)findViewById(R.id.game_record);
		button3 = (ImageButton)findViewById(R.id.game_exit);
		button4 = (ImageButton)findViewById(R.id.game_method);

		button1.setOnClickListener(new ClickEventHandler());
		button2.setOnClickListener(new ClickEventHandler());
		button3.setOnClickListener(new ClickEventHandler());
		button4.setOnClickListener(new ClickEventHandler());
		
		startService(new Intent("android.intent.action.Game_Music"));
	}
	private class ClickEventHandler implements View.OnClickListener{
		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			switch(v.getId()){
			case R.id.game_start :
				Intent intent1 = new Intent(MainActivity.this, GameStart.class);
				startActivity(intent1);
				break;
			case R.id.game_record :
				Intent intent2 = new Intent(MainActivity.this, GameRecord.class);
				startActivity(intent2);
				break;
			case R.id.game_method :
				Log.i("a","a");
				Intent intent3 = new Intent(MainActivity.this, GameMethod.class);
				startActivity(intent3);
				break;
			case R.id.game_exit :
				stopService(new Intent("android.intent.action.Game_Music"));
				android.os.Process.killProcess(android.os.Process.myPid());
				break;
			}
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
/*
	public void onAttachedToWindow() {
	    super.onAttachedToWindow();
	    this.getWindow().setType(WindowManager.LayoutParams.TYPE_KEYGUARD);
	}
	*/
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
			case KeyEvent.KEYCODE_BACK:
				stopService(new Intent("android.intent.action.Game_Music"));
				android.os.Process.killProcess(android.os.Process.myPid());
				return true;
			case KeyEvent.KEYCODE_HOME:
				stopService(new Intent("android.intent.action.Game_Music"));
				android.os.Process.killProcess(android.os.Process.myPid());
				return true;
			}
		}
		return super.onKeyDown(keyCode, event);
	}
}
