import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.DataBean;
import bean.TestBean;

public class Spring7_AutoWiredAnnotation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		
		DataBean obj1 = factory.getBean("data1", DataBean.class);
		System.out.println(obj1.getMsg());
		
		TestBean test1 = factory.getBean("test1", TestBean.class);
		System.out.println(test1.getData1());
		System.out.println(test1.getData2().getMsg());
		System.out.println(test1.getData3());
		
		
		((ConfigurableApplicationContext) factory).close();
	}

}









