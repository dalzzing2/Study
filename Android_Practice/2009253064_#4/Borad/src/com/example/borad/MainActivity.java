package com.example.borad;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
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
	public void onClick(View v){
		Log.i("MainActivity", "onClick");
		TextView tv = (TextView)findViewById(R.id.textView1);
		
		//intent ��ü ����
		Intent intent = new Intent();
		//�׼� ����, ������ �������� �׼�
		intent.setAction("android.intent.action.QUOTES_OF_THE_DAY_RECEIVED");
		//�ܾ� �ֱ�, quote�� tv�� ���ڿ��� �ٲ� ����
		intent.putExtra("quote", tv.getText().toString());
		//receiver ���� onReceive()ȣ��
		sendBroadcast(intent);
	}
}