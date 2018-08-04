package bean;

public class TestBean {
	private int data1;
	private double data2;
	private String data3;
	private DataBean data4;
	// 기본 생성자
	public TestBean(){
		System.out.println("기본 생성자 호출");
	}
	// 매개 변수가 있는 생성자
	public TestBean(int data1){
		System.out.println("매개 변수가 하나만 있는 생성자");
		this.data1 = data1;
	}
	public TestBean(int data1, double data2){
		System.out.println("매개 변수가 두개인 생성자");
		this.data1 = data1;
		this.data2 = data2;
	}
	public TestBean(String data3){
		System.out.println("문자열을 받는 생성자");
		this.data3 = data3;
	}
	public TestBean(DataBean data4){
		System.out.println("객체를 매개 변수로 받는 생성자");
		this.data4 = data4;
	}
	public TestBean(int data1, double data2,
							String data3, DataBean data4){
		System.out.println("매개 변수 4개인 생성자");
		this.data1 = data1;
		this.data2 = data2;
		this.data3 = data3;
		this.data4 = data4;
	}
	
	public int getData1() {
		return data1;
	}
	public void setData1(int data1) {
		this.data1 = data1;
	}
	public double getData2() {
		return data2;
	}
	public void setData2(double data2) {
		this.data2 = data2;
	}
	public String getData3() {
		return data3;
	}
	public void setData3(String data3) {
		this.data3 = data3;
	}
	public DataBean getData4() {
		return data4;
	}
	public void setData4(DataBean data4) {
		this.data4 = data4;
	}
	
}








