import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.TestBean1;
import bean.TestBean2;

public class Spring3_Instance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 스프링 4.0 부터는 ApplicationContext 객체를 
		// 사용한다.
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		// singleton 객체 추출
		TestBean1 t1 = factory.getBean("test1", TestBean1.class);
		TestBean1 t2 = factory.getBean("test1", TestBean1.class);
		System.out.println("t1 : " + t1);
		System.out.println("t2 : " + t2);
		
		TestBean1 t3 = factory.getBean("test2", TestBean1.class);
		TestBean1 t4 = factory.getBean("test2", TestBean1.class);
		System.out.println("t3 : " + t3);
		System.out.println("t4 : " + t4);
		// prototype
		TestBean1 t5 = factory.getBean("test3", TestBean1.class);
		TestBean1 t6 = factory.getBean("test3", TestBean1.class);
		System.out.println("t5 : " + t5);
		System.out.println("t6 : " + t6);
		
		//TestBean2 test100 = TestBean2.newInstance();
		
		TestBean2 t7 = factory.getBean("test4", TestBean2.class);
		System.out.println("t7 : " + t7);
		
		
		// factory를 닫아준다.
		((ConfigurableApplicationContext)factory).close();
		
	}
}












