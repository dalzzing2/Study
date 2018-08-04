package com.example.simplecursor;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.provider.Contacts.People;
import android.provider.MediaStore.Images;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.SimpleCursorAdapter;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		GridView gv = (GridView) findViewById(R.id.gridview);
		gv.setAdapter(new ImgCursorAdapter(this));
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
}

class ImgCursorAdapter extends BaseAdapter {
	private Cursor c;
	private Context ctx;

	public ImgCursorAdapter(Context context) {
		ctx = context;
		ContentResolver cr = ctx.getContentResolver();
		c = cr.query(Images.Thumbnails.EXTERNAL_CONTENT_URI, null, null, null,
				null);
	}

	public int getCount() {
		return c.getCount();
	}

	public Object getItem(int position) {
		return position;
	}

	public long getItemId(int position) {
		return position;
	}

	public View getView(int position, View cnvView, ViewGroup parent) {
		ImageView imageview;

		if (cnvView == null)
			imageview = new ImageView(ctx);
		else
			imageview = (ImageView) cnvView;

		c.moveToPosition(position);
		Uri uri = Uri.withAppendedPath(Images.Thumbnails.EXTERNAL_CONTENT_URI,
				c.getString(c.getColumnIndex(Images.Thumbnails._ID)));
		imageview.setImageURI(uri);
		imageview.setAdjustViewBounds(true);
		imageview.setScaleType(ImageView.ScaleType.CENTER_CROP);
		return imageview;
	}
}
