package bean;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Required;

public class TestBean {
	private int data1;
	private DataBean data2;
	private DataBean data3;
	
	public int getData1() {
		return data1;
	}
	public void setData1(int data1) {
		this.data1 = data1;
	}
	public DataBean getData2() {
		return data2;
	}
	// xml에 obj1이라고 등록된 빈 객체를 생성하여 주입한다.
	@Autowired
	@Qualifier("obj1")
	public void setData2(DataBean data2) {
		this.data2 = data2;
	}
	public DataBean getData3() {
		return data3;
	}
	// xml에 등록되지 않은 빈을 주입하면 오류가 발생한다.
	// required=false를 넣어주면 빈이 없을 경우에는
	// 오류가 발생하지 않고 null을 주입한다.
	@Autowired(required=false)
	@Qualifier("obj2")
	public void setData3(DataBean data3) {
		this.data3 = data3;
	}
	
	
}









