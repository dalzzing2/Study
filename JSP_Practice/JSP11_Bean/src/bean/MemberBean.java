package bean;
/*
 * 자바 빈은 자바 애플리케이션의 작은 클래스 조각
 * 데이터를 관리하는 목적으로 사용
 */
public class MemberBean {
	// 모든 변수는 private로 선언한다.
	private String name;
	private int age;
	private int gender;
	// 데이터를 셋팅하는 메서드
	// set + 변수명(첫 글자는 대문자)
	// 데이터를 반환받는 메서드
	// get + 변수명(첫 글자를 대문자)
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getGender() {
		return gender;
	}
	public void setGender(int gender) {
		this.gender = gender;
	}
	
	
	
}















