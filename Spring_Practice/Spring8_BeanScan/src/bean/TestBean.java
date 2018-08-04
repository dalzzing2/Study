package bean;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component("test1")
@Scope("prototype")
public class TestBean {

}
