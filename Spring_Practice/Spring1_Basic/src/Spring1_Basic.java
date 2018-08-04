import org.springframework.beans.factory.xml.XmlBeanFactory;
import org.springframework.core.io.FileSystemResource;

import bean.MessageBean;
import bean.MessageBeanEn;
import bean.MessageBeanKo;

public class Spring1_Basic {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// MessageBeanKo를 사용한다.
		// MessageBeanKo bean = new MessageBeanKo();
		// MessageBeanEn 클래스를 사용하는 것으로 변경한다.
		//MessageBeanEn bean = new MessageBeanEn();
		// 인터페이스형 참조 변수를 사용한다.
		//MessageBean bean
					// = new MessageBeanKo();
		//			= new MessageBeanEn();
		// applicationContext.xml을 로딩
		FileSystemResource res
			= new FileSystemResource("applicationContext.xml");
		XmlBeanFactory factory = new XmlBeanFactory(res);
		// 빈 객체를 가져온다.
		MessageBean bean 
				// = (MessageBean)factory.getBean("msg");
				= factory.getBean("msg", MessageBean.class);
		// sayHello 메서드를 호출한다.
		// sayHello 메서드는 인터페이스에 선언된 메서드를
		// 오버라이딩한 메서드이다.
		bean.sayHello();
		
		
	}

}









