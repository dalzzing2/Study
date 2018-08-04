package com.example.borad;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class QuoteOftheDayBR extends BroadcastReceiver{
	public QuoteOftheDayBR(){
		
	}
	public void onReceive(Context context, Intent intent){
		Notification n_msg = new Notification.Builder(context)
		.setContentTitle("SeonHo Android")			//제목
		.setContentText(intent.getStringExtra("quote"))	//내용
		.setSmallIcon(R.drawable.ic_launcher).build();	//아이콘
		//인디케이터 바를 설정하거나 출력함
		//getSystemService 메소드를 통해 NotificationManager 받아옴
		NotificationManager nm = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0, n_msg);
	}
}
