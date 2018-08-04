import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.DataBean;
import bean.TestBean;

public class Spring8_BeanScan {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		
		DataBean data1 = factory.getBean("data1", DataBean.class);
		DataBean data2 = factory.getBean("data1", DataBean.class);
		
		TestBean test1 = factory.getBean("test1", TestBean.class);
		TestBean test2 = factory.getBean("test1", TestBean.class);
		
		System.out.println("data1 : " + data1);
		System.out.println("data2 : " + data2);
		
		System.out.println("test1 : " + test1);
		System.out.println("test2 : " + test2);
		
		((ConfigurableApplicationContext) factory).close();
	}

}









