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
		.setContentTitle("Made by SeonHo")			//����
		.setContentText("Your Score is Max")	//����
		.setSmallIcon(R.drawable.logo).build();	//������
		//�ε������� �ٸ� �����ϰų� �����
		//getSystemService �޼ҵ带 ���� NotificationManager �޾ƿ�
		NotificationManager nm = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0, n_msg);
	}
}