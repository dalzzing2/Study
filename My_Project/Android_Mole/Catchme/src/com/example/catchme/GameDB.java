package com.example.catchme;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class GameDB extends SQLiteOpenHelper {
	public static final String tableName = "game";
	public static final String colID = "_id";
	public static final String colName = "name";
	public static final String colScore = "score";
	public static final String colDate = "date";
	
	public GameDB(Context context, CursorFactory factory, int version){
		super(context, tableName + ".db", factory, version);
	}	//»ý¼º
	
	public void onCreate(SQLiteDatabase db){
		db.execSQL("CREATE TABLE " + tableName + "(" + colID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
		colName + " TEXT, " +
		colScore + " TEXT, " +
		colDate + " TEXT )");
	}
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		
	}
}
