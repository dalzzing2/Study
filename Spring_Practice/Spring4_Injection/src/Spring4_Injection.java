import java.util.ArrayList;
import java.util.HashMap;

import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import bean.DataBean;
import bean.TestBean;

public class Spring4_Injection {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext factory
			= new FileSystemXmlApplicationContext(
					"applicationContext.xml");
		System.out.println("생성자를 통한 주입------");
		TestBean t1 = factory.getBean("test1", TestBean.class);
		System.out.println("t1.data1 : " + t1.getData1());
		System.out.println("t1.data2 : " + t1.getData2());
		System.out.println("t1.data3 : " + t1.getData3());
		
		System.out.println("세터를 통한 주입--------");
		TestBean t2 = factory.getBean("test2", TestBean.class);
		System.out.println("t2.data1 : " + t2.getData1());
		System.out.println("t2.data2 : " + t2.getData2());
		System.out.println("t2.data3 : " + t2.getData3());
		
		System.out.println("리스트 주입 -------------");
		TestBean t3 = factory.getBean("test3", TestBean.class);
		ArrayList<String> list1 = t3.getList1();
		for(String str : list1){
			System.out.println(str);
		}
		
		TestBean t4 = factory.getBean("test4", TestBean.class);
		ArrayList<DataBean> list2 = t4.getList2();
		for(DataBean bean : list2){
			System.out.println(bean);
		}
		
		System.out.println("HashMap 주입 ---------------");
		TestBean t5 = factory.getBean("test5", TestBean.class);
		HashMap<String, Object> map = t5.getMap();
		String v1 = (String)map.get("v1");
		DataBean v2 = (DataBean)map.get("v2");
		System.out.println(v1);
		System.out.println(v2);
		
		((ConfigurableApplicationContext)factory).close();
	}

}












