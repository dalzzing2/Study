import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.SubBean;

public class Spring6_InheriteWired {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		
		SubBean sub1 = factory.getBean("sub1", SubBean.class);
		System.out.println(sub1.getData1());
		System.out.println(sub1.getData2());
		System.out.println(sub1.getData3());
		
		SubBean sub2 = factory.getBean("sub2", SubBean.class);
		System.out.println(sub2.getData1());
		System.out.println(sub2.getData2());
		System.out.println(sub2.getData3());
		
		((ConfigurableApplicationContext)factory).close();
	}

}










