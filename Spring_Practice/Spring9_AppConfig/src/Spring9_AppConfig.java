import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.DataBean;
import bean.TestBean;

public class Spring9_AppConfig {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		
		// data1 빈을 가져온다.
		DataBean d1 = factory.getBean("data1", DataBean.class);
		System.out.println("d1 : " + d1);
		// 객체를 주입하는 빈을 가져온다.
		TestBean t1 = factory.getBean("test2", TestBean.class);
		System.out.println(t1.getData_bean());
		System.out.println(t1.getData_wire());
		
		TestBean t2 = factory.getBean("test3", TestBean.class);
		System.out.println(t2.getData_bean());
		System.out.println(t2.getData_wire());
		
		((ConfigurableApplicationContext) factory).close();
	}

}










