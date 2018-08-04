package com.example.catchme;

import android.content.Context;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.LayoutInflater;
import android.view.View;



public class GameMethodSub extends PagerAdapter{
	private LayoutInflater mInflater;
	
	
	public GameMethodSub(Context context){
		super();
		
		mInflater = LayoutInflater.from(context);
	}
	@Override
	public int getCount() {
		// TODO Auto-generated method stub
		return 9;
	}
	public Object instantiateItem(View pager, int position){
		
		View v = null;

		switch(position){
		case 0:
			v = mInflater.inflate(R.layout.screen_1, null);
			break;
		case 1:
			v = mInflater.inflate(R.layout.screen_2, null);
			break;
		case 2:
			v = mInflater.inflate(R.layout.screen_3, null);
			break;
		case 3:
			v = mInflater.inflate(R.layout.screen_4, null);
			break;
		case 4:
			v = mInflater.inflate(R.layout.screen_5, null);
			break;
		case 5:
			v = mInflater.inflate(R.layout.screen_6, null);
			break;
		case 6:
			v = mInflater.inflate(R.layout.screen_7, null);
			break;
		case 7:
			v = mInflater.inflate(R.layout.screen_8, null);
			break;
		case 8:
			v = mInflater.inflate(R.layout.screen_9, null);
			break;
			
		}

		((ViewPager)pager).addView(v, null);

		return v;
	}
	public void destroyItem(View pager, int position, Object view) {
        ((ViewPager)pager).removeView((View)view);
    }

	@Override
	public boolean isViewFromObject(View v, Object obj) {
		// TODO Auto-generated method stub
		return v == obj;
	}

}
