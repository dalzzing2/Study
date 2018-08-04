package bean;

import java.util.ArrayList;
import java.util.HashMap;

public class TestBean {
	private int data1;
	private String data2;
	private DataBean data3;
	
	private ArrayList<String> list1;
	private ArrayList<DataBean> list2;
	
	private HashMap<String, Object> map;
	
	// 기본 생성자
	public TestBean(){
		System.out.println("기본 생성자");
	}
	public TestBean(int data1, String data2, DataBean data3){
		System.out.println("매개 변수가 있는 생성자");
		this.data1 = data1;
		this.data2 = data2;
		this.data3 = data3;
	}

	public int getData1() {
		return data1;
	}

	public void setData1(int data1) {
		this.data1 = data1;
	}

	public String getData2() {
		return data2;
	}

	public void setData2(String data2) {
		this.data2 = data2;
	}

	public DataBean getData3() {
		return data3;
	}

	public void setData3(DataBean data3) {
		this.data3 = data3;
	}

	public ArrayList<String> getList1() {
		return list1;
	}

	public void setList1(ArrayList<String> list1) {
		this.list1 = list1;
	}

	public ArrayList<DataBean> getList2() {
		return list2;
	}

	public void setList2(ArrayList<DataBean> list2) {
		this.list2 = list2;
	}

	public HashMap<String, Object> getMap() {
		return map;
	}

	public void setMap(HashMap<String, Object> map) {
		this.map = map;
	}
	
	
}
