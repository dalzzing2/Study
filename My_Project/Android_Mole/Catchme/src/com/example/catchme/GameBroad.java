package com.example.catchme;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class GameBroad extends BroadcastReceiver{
	public GameBroad(){
		
	}
	public void onReceive(Context context, Intent intent){
		Notification n_msg = new Notification.Builder(context)
		.setContentTitle("Made by SeonHo")			//제목
		.setContentText("Your Score is Max")	//내용
		.setSmallIcon(R.drawable.logo).build();	//아이콘
		//인디케이터 바를 설정하거나 출력함
		//getSystemService 메소드를 통해 NotificationManager 받아옴
		NotificationManager nm = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0, n_msg);
	}
}