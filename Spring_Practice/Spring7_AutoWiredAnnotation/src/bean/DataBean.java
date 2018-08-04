package bean;

import org.springframework.beans.factory.annotation.Required;

public class DataBean {
	private String msg;

	public String getMsg() {
		return msg;
	}
	// 필수로 주입해 되는 프로퍼티
	@Required
	public void setMsg(String msg) {
		this.msg = msg;
	}
	
	
}
