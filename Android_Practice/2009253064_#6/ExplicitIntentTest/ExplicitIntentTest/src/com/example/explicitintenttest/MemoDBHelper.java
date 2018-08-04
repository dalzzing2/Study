package com.example.explicitintenttest;

import java.util.Calendar;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class MemoDBHelper extends SQLiteOpenHelper {
	public static final String tableName = "memos";
	public static final String colID = "_id";
	public static final String colTitle = "title";
	public static final String colContent = "content";
	public static final String colDate = "date";
	
	public MemoDBHelper(Context context, CursorFactory factory, int version){
		super(context, tableName + ".db", factory, version);
	}	//»ý¼º
	
	public void onCreate(SQLiteDatabase db){
		db.execSQL("CREATE TABLE " + tableName + "(" + colID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
		colTitle + " TEXT, " +
		colContent + " TEXT, " +
		colDate + " TEXT )");
		
		String date = Calendar.getInstance().getTime().toString();
		
		
		db.execSQL("INSERT INTO " + tableName + " VALUES( NULL, 'Android', 'Activity, View, Menu, Dialog','"
				+ date + "') ");
		db.execSQL("INSERT INTO " + tableName + " VALUES( NULL, 'Java', 'Class, Package, Interface','"
				+ date + "') ");
	}
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		
	}
}
