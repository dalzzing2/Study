package com.example.explicitintenttest;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MemoActivity extends Activity {

	private EditText title;
	private EditText memo;
	private Button done;
	private Button cancel;
	private boolean flag;
	private int position;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.edit);
		
		title = (EditText)findViewById(R.id.editText1);
		memo = (EditText)findViewById(R.id.editText2);
		done = (Button)findViewById(R.id.button1);
		cancel = (Button)findViewById(R.id.button2);
		
		Intent intent = getIntent();
		String action = intent.getAction();
		
		if ( action.equals("android.intent.action.CREATE") ) {
			title.setText("title");
			memo.setText("Type your memo here.");
			flag = false;
		}
		else if ( action.equals("android.intent.action.EDIT") ) {
			Log.i("MemoActivity",intent.getStringExtra("title"));
			title.setText(intent.getStringExtra("title"));
			memo.setText(intent.getStringExtra("contents"));
			position = intent.getIntExtra("position", -1);
			flag = true;
		}
		else
			finish();
	}

	public void onClick(View v) {
		if ( v == done ) {
			Intent intent = new Intent();
			intent.putExtra("title", title.getText().toString());
			intent.putExtra("contents", memo.getText().toString());
			intent.putExtra("isEdited", flag);
			if (flag)
				intent.putExtra("position", position);
			
			setResult(RESULT_OK, intent);
			finish();
			
			Log.i("MemoActivity", intent.toString());
		}
		else if ( v == cancel ) {
			Intent intent = new Intent();
			setResult(RESULT_CANCELED, intent);
			finish();
		}
	}
}
