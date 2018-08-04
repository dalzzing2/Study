package com.example.calculator_android;

import com.example.java.CalculatorEngine;

import android.app.Activity;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnKeyListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.view.KeyEvent;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.app.AlertDialog;

public class MainActivity extends Activity {

	private CalculatorEngine ce;
	private Button b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
	private Button bplus, bminus, bmul, bdiv, bres, bcle;
	private TextView tv;
	private int Sleep;
	
	double num = 0;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		            
		ce = new CalculatorEngine();
		
		
		
		b0 = (Button) findViewById(R.id.button1);
		b1 = (Button) findViewById(R.id.button5);
		b2 = (Button) findViewById(R.id.button6);
		b3 = (Button) findViewById(R.id.button7);
		b4 = (Button) findViewById(R.id.button9);
		b5 = (Button) findViewById(R.id.button10);
		b6 = (Button) findViewById(R.id.button11);
		b7 = (Button) findViewById(R.id.button13);
		b8 = (Button) findViewById(R.id.button14);
		b9 = (Button) findViewById(R.id.button15);
		bplus = (Button) findViewById(R.id.button16);
		bminus = (Button) findViewById(R.id.button12);
		bmul = (Button) findViewById(R.id.button8);
		bdiv = (Button) findViewById(R.id.button4);
		bcle = (Button) findViewById(R.id.button2);
		bres = (Button) findViewById(R.id.button3);

		tv = (TextView) findViewById(R.id.textView1);

		OnClickListener CL = new OnClickListener() {
			public void onClick(View v) {
				AudioManager am = (AudioManager)getSystemService(AUDIO_SERVICE);
				Vibrator vb = (Vibrator)getSystemService(VIBRATOR_SERVICE);
				
				if(Sleep == 0){
					am.setRingerMode(AudioManager.RINGER_MODE_NORMAL);
					am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
				}
				else if(Sleep == 1){
					vb.vibrate(100);
					am.setRingerMode(AudioManager.RINGER_MODE_VIBRATE);
					//am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
				}
				else if(Sleep == 2){
					am.setRingerMode(AudioManager.RINGER_MODE_SILENT);
					//am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
				}
				if (v == b0)
					ce.Enter("0");
				else if (v == b1)
					ce.Enter("1");
				else if (v == b2)
					ce.Enter("2");
				else if (v == b3)
					ce.Enter("3");
				else if (v == b4)
					ce.Enter("4");
				else if (v == b5)
					ce.Enter("5");
				else if (v == b6)
					ce.Enter("6");
				else if (v == b7)
					ce.Enter("7");
				else if (v == b8)
					ce.Enter("8");
				else if (v == b9)
					ce.Enter("9");
				else if (v == bplus)
					ce.Enter("+");
				else if (v == bminus)
					ce.Enter("-");
				else if (v == bmul)
					ce.Enter("*");
				else if (v == bdiv)
					ce.Enter("/");
				else if (v == bres)
					ce.Enter("=");
				else if (v == bcle)
					ce.Enter("C");
				tv.setText(Double.toString(ce.numberToDisplay()));
			}
		};

		b0.setOnClickListener(CL);
		b1.setOnClickListener(CL);
		b2.setOnClickListener(CL);
		b3.setOnClickListener(CL);
		b4.setOnClickListener(CL);
		b5.setOnClickListener(CL);
		b6.setOnClickListener(CL);
		b7.setOnClickListener(CL);
		b8.setOnClickListener(CL);
		b9.setOnClickListener(CL);

		bplus.setOnClickListener(CL);
		bminus.setOnClickListener(CL);
		bmul.setOnClickListener(CL);
		bdiv.setOnClickListener(CL);
		bcle.setOnClickListener(CL);
		bres.setOnClickListener(CL);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		AudioManager am = (AudioManager)getSystemService(AUDIO_SERVICE);
		Vibrator vb = (Vibrator)getSystemService(VIBRATOR_SERVICE);
				
		switch (item.getItemId()) {
		
		case R.id.sin:
			tv.setText(Double.toString(Math.sin(ce.numberToDisplay())));
			break;
		case R.id.cos:
			tv.setText(Double.toString(Math.cos(ce.numberToDisplay())));
			break;
		case R.id.tan:
			tv.setText(Double.toString(Math.tan(ce.numberToDisplay())));
			break;
		case R.id.pi:
			ce.setDisplay(3.141592653589793);
			tv.setText(Double.toString(ce.numberToDisplay()));
			break;
		case R.id.beep:
			Sleep = 0;
			am.setRingerMode(AudioManager.RINGER_MODE_NORMAL);
			am.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);
			break;
		case R.id.vibration:
			Sleep = 1;
			vb.vibrate(500);
			am.setRingerMode(AudioManager.RINGER_MODE_VIBRATE);
			break;
		case R.id.silence:
			Sleep = 2;
			am.setRingerMode(AudioManager.RINGER_MODE_SILENT);
			break;
		}
		return super.onOptionsItemSelected(item);
	}

	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (event.getAction() == KeyEvent.ACTION_DOWN) {
			switch (keyCode) {
			case KeyEvent.KEYCODE_BACK:
				new DialogFragment() {
					public Dialog onCreateDialog(Bundle savedInstance) {
						AlertDialog.Builder builder = new AlertDialog.Builder(
								getActivity());
						builder.setMessage("Do you want exit?")
								.setPositiveButton("Yes",
										new DialogInterface.OnClickListener() {
											public void onClick(
													DialogInterface dialog,
													int which) {
												getActivity().finish();
											}
										})
								.setNegativeButton("No",
										new DialogInterface.OnClickListener() {
											public void onClick(
													DialogInterface dialog,
													int which) {
												dismiss();
											}
										});
						return builder.create();
					}
				}.show(getFragmentManager(), "AlertDialog");
				;
				return true;
			}
		}
		return super.onKeyDown(keyCode, event);
	}
}
