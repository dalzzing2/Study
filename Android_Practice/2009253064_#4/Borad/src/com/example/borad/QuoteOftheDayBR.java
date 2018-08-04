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
		.setContentTitle("SeonHo Android")			//����
		.setContentText(intent.getStringExtra("quote"))	//����
		.setSmallIcon(R.drawable.ic_launcher).build();	//������
		//�ε������� �ٸ� �����ϰų� �����
		//getSystemService �޼ҵ带 ���� NotificationManager �޾ƿ�
		NotificationManager nm = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0, n_msg);
	}
}
