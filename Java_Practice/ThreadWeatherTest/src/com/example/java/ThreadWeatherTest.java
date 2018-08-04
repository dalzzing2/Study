package com.example.java;

import java.net.URL;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;


public class ThreadWeatherTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Thread t = new ThreadWeather();
		t.start();
		try {
			t.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Done...");
	}

}

class ThreadWeather extends Thread {

	public void run() {
		
		int i = 10;
		while ( i > 0 ) {
			System.out.println("...");
			try {
				URL url = new URL(
						"http://www.kma.go.kr/XML/weather/sfc_web_map.xml");
				XmlPullParserFactory parserFactory = XmlPullParserFactory
						.newInstance();
				XmlPullParser parser = parserFactory.newPullParser();
				parser.setInput(url.openStream(), "utf-8");

				int parserEvent = parser.getEventType();
				String stnid = "";
				String desc = "";
				String ta = "";
				String region = "";

				String name = "";
				while (parserEvent != XmlPullParser.END_DOCUMENT) {
					switch (parserEvent) {
					case XmlPullParser.START_DOCUMENT:
						break;
					case XmlPullParser.START_TAG:
						name = parser.getName();
						if (name != null && name.equals("local")) {
							stnid = parser.getAttributeValue(null, "stn_id");
							desc = parser.getAttributeValue(null, "desc");
							ta = parser.getAttributeValue(null, "ta");
						}
						break;
					case XmlPullParser.TEXT:
						if (name != null && name.equals("local")) {
							region = parser.getText();
						}
						break;
					case XmlPullParser.END_TAG:
						if (name != null && name.equals("local")) {

							if (region.equals("¿øÁÖ"))
								System.out.println(region + desc + ta + stnid);
						}
						name = "";
						break;
					}
					parserEvent = parser.next();
				}
			} catch (Exception e) {
				e.printStackTrace();
			}

			i--;
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}