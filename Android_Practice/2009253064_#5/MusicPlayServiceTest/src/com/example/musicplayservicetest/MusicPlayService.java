package com.example.musicplayservicetest;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.net.Uri;
import android.os.IBinder;

public class MusicPlayService extends Service{
	private MediaPlayer mp;
	public void onCreate(){
		super.onCreate();
		mp = new MediaPlayer();
	}
	public void onDestroy(){
		super.onDestroy();
		mp.release();
	}
	public int onStartCommand(Intent intent, int flags, int startId){
		final int _startId = startId;
		if(intent != null){
			Uri uri = intent.getData();
			try {
				mp.setOnCompletionListener(new OnCompletionListener(){
					public void onCompletion(MediaPlayer mp){
						MusicPlayService.this.stopSelf(_startId);
					}
				});
				mp.reset();
				mp.setDataSource(getApplicationContext(), uri);
				mp.prepare();
				mp.start();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		return super.onStartCommand(intent, flags, startId);
	}
	public IBinder onBind(Intent arg0) {return null;}
}
