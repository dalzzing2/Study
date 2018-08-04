import org.springframework.beans.factory.xml.XmlBeanFactory;
import org.springframework.core.io.FileSystemResource;

import bean.DataBean;
import bean.TestBean;

public class Spring2_DI {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// bean factory 생성
		FileSystemResource res 
			= new FileSystemResource("applicationContext.xml");
		XmlBeanFactory factory = new XmlBeanFactory(res);
		// scope에 singleton을 넣어주거 scope 속성을 설정하지
		// 않은 bean은 싱글톤 객체로 처리된다.
		// 싱글톤 : 객체를 하나만 만들어서 계속 가져다 사용
		TestBean t1 = factory.getBean("test1", TestBean.class);
		TestBean t2 = factory.getBean("test1", TestBean.class);
		System.out.println("t1 : " + t1);
		System.out.println("t2 : " + t2);
		// scope에 prototype을 넣어주면 계속 새로운 객체를 생성
		TestBean t3 = factory.getBean("test2", TestBean.class);
		TestBean t4 = factory.getBean("test2", TestBean.class);
		System.out.println("t3 : " + t3);
		System.out.println("t4 : " + t4);
		// 매개 변수가 하나인 생성자를 사용
		TestBean t5 = factory.getBean("test3", TestBean.class);
		System.out.println("t5.data1 : " + t5.getData1());
		// 매개 변수가 두 개인 생성자를 사용
		TestBean t6 = factory.getBean("test4", TestBean.class);
		System.out.println("t6.data1 : " + t6.getData1());
		System.out.println("t6.data2 : " + t6.getData2());
		// 문자열을 받는 생성자를 사용
		TestBean t7 = factory.getBean("test5", TestBean.class);
		System.out.println("t7.data3 : " + t7.getData3());
		// 객체를 주입 받는 생성자를 사용
		TestBean t8 = factory.getBean("test6", TestBean.class);
		DataBean d1 = t8.getData4();
		System.out.println("d1.data100 : " + d1.getData100());
		
		TestBean t9 = factory.getBean("test7", TestBean.class);
		DataBean d2 = t9.getData4();
		System.out.println("d2.data100 : " + d2.getData100());
		// 4가지 데이터를 받는 생성자 선택
		TestBean t10 = factory.getBean("test8", TestBean.class);
		DataBean d3 = t10.getData4();
		System.out.println("t10.data1 : " + t10.getData1());
		System.out.println("t10.data2 : " + t10.getData2());
		System.out.println("t10.data3 : " + t10.getData3());
		System.out.println("d3.data100 : " + d3.getData100());
		// 세터 메서드를 통해 주입 받는 객체 생성
		TestBean t11 = factory.getBean("test9", TestBean.class);
		DataBean d4 = t11.getData4();
		System.out.println("t11.data1 : " + t11.getData1());
		System.out.println("t11.data2 : " + t11.getData2());
		System.out.println("t11.data3 : " + t11.getData3());
		System.out.println("d4.data100 : " + d4.getData100());
	}
}











