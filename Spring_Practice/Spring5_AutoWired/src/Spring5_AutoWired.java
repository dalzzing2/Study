import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.TestBean;

public class Spring5_AutoWired {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		
		// 빈 객체를 추출
		TestBean t1 = factory.getBean("test1", TestBean.class);
		// 주입된 객체를 출력한다.
		System.out.println(t1.getData1());
		System.out.println(t1.getData2());
		
		((ConfigurableApplicationContext)factory).close();
		
	}

}
