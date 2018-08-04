package com.example.memocpcontract;

import android.net.Uri;

public class MemoContract {
	public static String AUTHORITY = "com.example.memocptest";
	public static String MEMO_ID = "_id";
	public static String MEMO_TITLE = "title";
	public static String MEMO_CONTENT = "content";
	public static String MEMO_DATE = "date";
	
	public static Uri CONTENT_URI = Uri.parse("content://" + AUTHORITY + "/memos");
	public static Uri CONTENT_TITLE_URI = Uri.parse("content://" + AUTHORITY + "/memos/" + MEMO_TITLE);
}