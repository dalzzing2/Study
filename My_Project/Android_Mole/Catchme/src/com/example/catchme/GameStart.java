package com.example.catchme;

import java.util.Calendar;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Vibrator;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

public class GameStart extends Activity {
	private Handler mHandler = null;
	int mScore = 0;
	int mTime = 150;
	int mMaxScore = 0;
	int[] Value = new int[9];
	ImageButton[] dudoje = new ImageButton[9]; 
	GameDB GameDB;
	SQLiteDatabase db;
	int time=1000;
	GameBroad broad = new GameBroad();
	public static MediaPlayer mp_right, mp_wrong;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.game_start);

		mp_right = MediaPlayer.create(this, R.raw.r);
		mp_right.setLooping(false);

		mp_wrong = MediaPlayer.create(this, R.raw.w);
		mp_wrong.setLooping(false);

		GameDB = new GameDB(this, null, 1);
		db = GameDB.getWritableDatabase();

		mMaxScore = Max();

		ImageButton btnStart = (ImageButton)findViewById(R.id.btnstartStart);
		ImageButton btnStop = (ImageButton)findViewById(R.id.btnstartStop);
		ImageButton btnSave = (ImageButton)findViewById(R.id.btnstartSave);
		ImageButton btnBack = (ImageButton)findViewById(R.id.btnstartBack);

		final EditText txtName = (EditText)findViewById(R.id.txtName);
		final TextView txtTime = (TextView)findViewById(R.id.txtTime);
		final TextView txtScore = (TextView)findViewById(R.id.txtScore);
		final TextView txtMaxScore = (TextView)findViewById(R.id.txtMaxScore);

		dudoje[0] = (ImageButton)findViewById(R.id.imageButton1);
		dudoje[1] = (ImageButton)findViewById(R.id.imageButton2);
		dudoje[2] = (ImageButton)findViewById(R.id.imageButton3);
		dudoje[3] = (ImageButton)findViewById(R.id.imageButton4);
		dudoje[4] = (ImageButton)findViewById(R.id.imageButton5);
		dudoje[5] = (ImageButton)findViewById(R.id.imageButton6);
		dudoje[6] = (ImageButton)findViewById(R.id.imageButton7);
		dudoje[7] = (ImageButton)findViewById(R.id.imageButton8);
		dudoje[8] = (ImageButton)findViewById(R.id.imageButton9);

		txtMaxScore.setText("최고점수:" + mMaxScore);

		txtName.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				txtName.setText("");
			}
		});

		btnStart.setOnClickListener(new View.OnClickListener(){
			public void onClick(View v) {
				mScore = 0;
				mTime = 150;
				time = 1000;
				stopService(new Intent("android.intent.action.Game_Music"));
				mHandler.sendEmptyMessageDelayed(0, time);
			}
		});

		btnStop.setOnClickListener(new View.OnClickListener(){
			public void onClick(View v){
				mTime = 0;
			}
		});

		btnSave.setOnClickListener(new View.OnClickListener(){
			public void onClick(View v){
				Calendar time = Calendar.getInstance();
				int month = time.get(Calendar.MONTH);
				int day = time.get(Calendar.DATE);
				int hour = time.get(Calendar.HOUR_OF_DAY);
				int min = time.get(Calendar.MINUTE);
				int sec = time.get(Calendar.SECOND);

				String clock = Integer.toString(month) + " 월 " + Integer.toString(day) + " 일 " +Integer.toString(hour) + " : " + Integer.toString(min) + " : " + Integer.toString(sec);

				db.execSQL("INSERT INTO " + GameDB.tableName
						+ " VALUES ( NULL, " + "'" + txtName.getText().toString() + "', "
						+ "'" + Integer.toString(mScore) + "', "
						+ "'" + clock + "' ) "  );
				Log.i(Integer.toString(mScore), "insert mScore");
				
				int b_mMaxScore = mMaxScore;
				mMaxScore = Max();

				if(b_mMaxScore < mScore){
					Intent intentbroad = new Intent();
					intentbroad.setAction("android.intent.action.Game_Broad");
					sendBroadcast(intentbroad);
				}

				txtMaxScore.setText("최고점수:" + mMaxScore);

				Toast toast = Toast.makeText(getBaseContext(), 
						"저장되었습니다.", 100000);
				toast.show();
			}
		});
		btnBack.setOnClickListener(new View.OnClickListener(){
			public void onClick(View v){
				android.os.Process.killProcess(android.os.Process.myPid());
				Intent intent = new Intent(GameStart.this, MainActivity.class);
				startActivity(intent);
			}
		});
		for(int i=0; i<9; i++){
			final int arrayI = i;
			dudoje[i].setOnClickListener(new View.OnClickListener(){
				public void onClick(View v){
					dudoje[arrayI].setImageResource(R.drawable.grass);
					int check = 0;
					if(Value[arrayI] == 1){
						mp_right.start();
						mScore++;
						Value[arrayI] = 0;
					}
					if(Value[arrayI] == -1){
						mp_wrong.start();
						mScore--;
						Value[arrayI] = 0;
					}
					if(mScore == 30){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨2", 1000);
						if(check == 0){
							time = time - 100;
							check = 1;
						}
						toast.show();
					} 
					if(mScore == 60){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨3", 1000);
						if(check == 1){
							time = time - 100;
							check = 2;
						}
						toast.show();
					} 
					if(mScore == 90){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨4", 1000);
						if(check == 2){
							time = time - 100;
							check = 3;
						}
						toast.show();
					} 
					if(mScore == 120){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨5", 1000);
						if(check == 3){
							time = time - 100;
							check = 4;
						}
						toast.show();
					} 
					if(mScore == 150){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨6", 1000);
						if(check == 4){
							time = time - 100;
							check = 5;
						}
						toast.show();
					} 
					if(mScore == 180){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨7", 1000);
						if(check == 5){
							time = time - 100;
							check = 6;
						}
						toast.show();
					} 
					if(mScore == 210){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨8", 1000);
						if(check == 6){
							time = time - 100;
							check = 7;
						}
						toast.show();
					} 
					if(mScore == 240){
						Toast toast = Toast.makeText(getBaseContext(), 
								"레벨9", 1000);
						if(check == 7){
							time = time - 100;
							check = 8;
						}
						toast.show();
					}
					if(mScore == 280){
						Toast toast = Toast.makeText(getBaseContext(), 
								"최종레벨", 1000);
						if(check == 7){
							time = time - 100;
							check = 0;
						}
						toast.show();
					} 
				}
			});	        
		}
		mHandler = new Handler() {
			public void handleMessage(Message msg) {
				int check1 = (int)(Math.random()*2);
				int check2 = (int)(Math.random()*2);
				int check3 = (int)(Math.random()*2);
				int check4 = (int)(Math.random()*2);
				int check5 = (int)(Math.random()*2);
				int check6 = (int)(Math.random()*2);
				int check7 = (int)(Math.random()*2);
				int check8 = (int)(Math.random()*2);
				int check9 = (int)(Math.random()*2);
				
				int trick1 = (int)(Math.random()*5);
				int trick2 = (int)(Math.random()*5);
				int trick3 = (int)(Math.random()*5);
				int trick4 = (int)(Math.random()*5);
				int trick5 = (int)(Math.random()*5);
				int trick6 = (int)(Math.random()*5);
				int trick7 = (int)(Math.random()*5);
				int trick8 = (int)(Math.random()*5);
				int trick9 = (int)(Math.random()*5);
				
				txtTime.setText("카운트:" + mTime);
				txtScore.setText("점수:" + mScore);

				
				if(mTime== 0){
					Toast toast = Toast.makeText(getBaseContext(), 
							"종료", 100000);
					toast.show();
					return;
				}
				
				mHandler.sendEmptyMessageDelayed(0, time);
				mTime--;


				int index1 = (int)(Math.random() * 9);
				int index2 = (int)(Math.random() * 9);
				int index3 = (int)(Math.random() * 9);
				int index4 = (int)(Math.random() * 9);
				int index5 = (int)(Math.random() * 9);
				int index6 = (int)(Math.random() * 9);
				int index7 = (int)(Math.random() * 9);
				int index8 = (int)(Math.random() * 9);
				int index9 = (int)(Math.random() * 9);
				
				if(index1 == index2)
					index2 = (int)(Math.random() * 9);
				if(index1 == index3 || index2 == index3)
					index3 = (int)(Math.random() * 9);
				if(index1 == index4 || index2 == index4 || index3 == index4)
					index4 = (int)(Math.random() * 9);
				if(index1 == index5 || index2 == index5 || index3 == index5 || index4 == index5)
					index5 = (int)(Math.random() * 9);
				if(index1 == index6 || index2 == index6 || index3 == index6 || index4 == index6 || index5 == index6)
					index6 = (int)(Math.random() * 9);
				if(index1 == index7 || index2 == index7 || index3 == index7 || index4 == index7 || index5 == index7 || index6 == index7)
					index7 = (int)(Math.random() * 9);
				if(index1 == index8 || index2 == index8 || index3 == index8 || index4 == index8 || index5 == index8 || index6 == index8 || index7 == index8)
					index8 = (int)(Math.random() * 9);
				if(index1 == index9 || index2 == index9 || index3 == index9 || index4 == index9 || index5 == index9 || index6 == index9 || index7 == index9 || index8 == index9)
					index9 = (int)(Math.random() * 9);
				
				for(int i=0; i<9;i++){
					Value[i] = 0;
					dudoje[i].setImageResource(R.drawable.grass);
				}
				if(check1==0){
					if(trick1 != 3){
						Value[index1] = 1;
						dudoje[index1].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index1] = -1;
						dudoje[index1].setImageResource(R.drawable.snake);
					}
				}
				if(check2==0){
					if(trick2 != 3){
						Value[index2] = 1;
						dudoje[index2].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index2] = -1;
						dudoje[index2].setImageResource(R.drawable.snake);
					}
				}
				if(check3==0){
					if(trick3 != 3){
						Value[index3] = 1;
						dudoje[index3].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index3] = -1;
						dudoje[index3].setImageResource(R.drawable.snake);
					}
				}
				if(check4==0){
					if(trick4 != 3){
						Value[index4] = 1;
						dudoje[index4].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index4] = -1;
						dudoje[index4].setImageResource(R.drawable.snake);
					}
				}
				if(check5==0){
					if(trick5 != 3){
						Value[index5] = 1;
						dudoje[index5].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index5] = -1;
						dudoje[index5].setImageResource(R.drawable.snake);
					}
				}
				if(check6==0){
					if(trick6 != 3){
						Value[index6] = 1;
						dudoje[index6].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index6] = -1;
						dudoje[index6].setImageResource(R.drawable.snake);
					}
				}
				if(check7==0){
					if(trick7 != 3){
						Value[index7] = 1;
						dudoje[index7].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index7] = -1;
						dudoje[index7].setImageResource(R.drawable.snake);
					}
				}
				if(check8==0){
					if(trick8 != 3){
						Value[index8] = 1;
						dudoje[index8].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index8] = -1;
						dudoje[index8].setImageResource(R.drawable.snake);
					}
				}
				if(check9==0){
					if(trick4 != 3){
						Value[index9] = 1;
						dudoje[index9].setImageResource(R.drawable.dudoje);
					}
					else{
						Value[index9] = -1;
						dudoje[index9].setImageResource(R.drawable.snake);
					}
				}
			}
		};        
	}
	public int Max(){
		String sql = "SELECT max(" +GameDB.colScore+ ") FROM " +GameDB.tableName;
		Cursor cursor = db.rawQuery(sql, null);
		if(cursor == null){
			return -1;
		}
		if(!cursor.moveToFirst()){
			cursor.close();
			return -1;
		}
		try{
			String strScore = cursor.getString(0);
			Log.i(strScore, "max mScore");
			mMaxScore = Integer.parseInt(strScore);
		}catch(NumberFormatException e){
			e.printStackTrace();
		}
		cursor.close();

		return mMaxScore;
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
						builder.setMessage("       Copyright (C) 2014. 박선호\n             all rights reserved. ");
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