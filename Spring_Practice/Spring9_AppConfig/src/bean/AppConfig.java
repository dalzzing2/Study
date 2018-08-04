package bean;

import org.springframework.beans.factory.annotation.Autowire;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {
	// 빈 등록
	@Bean
	public DataBean data1(){
		return new DataBean();
	}
	// 주입
	@Bean
	public TestBean test2(){
		TestBean test = new TestBean();
		// 데이터를 주입
		test.setData_bean(new DataBean());
		test.setData_wire(new DataBean());
		
		return test;
	}
	// 자동 주입
	// 객체 주입될 클래스에 정의되어 있는 프로퍼티의 이름과
	// 동일하게 메서드를 만들어 줘야 한다.
	@Bean
	public DataBean data_bean(){
		return new DataBean();
	}
	//@Bean
	public DataBean data_wire(){
		return new DataBean();
	}
	// 자동주입하는 빈을 설정
	@Bean(autowire = Autowire.BY_NAME)
	public TestBean test3(){
		return new TestBean();
	}
}













