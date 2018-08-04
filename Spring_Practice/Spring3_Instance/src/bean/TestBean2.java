package bean;

public class TestBean2 {
	// 직접 객체 생성을 하지 못하도록 막아준다.
	private TestBean2(){
		
	}
	
	public static TestBean2 newInstance(){
		// TestBean2의 객체를 생성한다.
		TestBean2 test = new TestBean2();
		// 코드 처리가 필요하다면 여기서 해준다....
		// 만들어진 객체를 반환한다.
		return test;
	}
}