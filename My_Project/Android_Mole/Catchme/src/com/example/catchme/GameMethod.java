package com.example.catchme;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.Intent;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.support.v4.view.ViewPager;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;

public class GameMethod extends Activity{
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.game_method);
        ViewPager pager = (ViewPager)findViewById(R.id.pager);
        pager.setAdapter(new GameMethodSub(this));
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
		
		switch(item.getItemId()){
		case R.id.beep:
			am.setRingerMode(AudioManager.RINGER_MODE_NORMAL);
			am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
			break;
		case R.id.vibration:
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