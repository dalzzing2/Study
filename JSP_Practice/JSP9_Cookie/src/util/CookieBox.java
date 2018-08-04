package util;

import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.HashMap;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/*
 * 이 클래스는 쿠키를 보다 쉽게 사용하기 위해
 * 만든 클래스 입니다.
 */
public class CookieBox {
	// 요청 정보를 담고 있는 객체
	HttpServletRequest request;
	// 응답 정보를 담고 있는 객체
	HttpServletResponse response;
	// 쿠키의 정보를 담고 있을 컬렉션
	HashMap<String, String> cookie_info;
	// 생성자
	public CookieBox(HttpServletRequest request, 
						HttpServletResponse response){
		this.request = request;
		this.response = response;
		// 쿠키 정보를 읽어와 컬렉션에 담아준다.
		cookie_info = new HashMap<String, String>();
		// 쿠키를 얻어온다.
		// import javax.servlet.http
		Cookie [] cookies = request.getCookies();
		// 쿠키의 개수만큼 반복한다.
		for(Cookie c : cookies){
			// 쿠키의 이름과 값을 추출
			String c_name = c.getName();
			String c_value = c.getValue();
			// 컬렉션에 담는다.
			cookie_info.put(c_name, c_value);
		}
	}
	// 쿠키를 설정하는 메서드
	public void setCookie(String name, String value, 
						int expire, String encoding){
		try{
			// 인코딩
			// import java.net
			value = URLEncoder.encode(value, encoding);
			// 쿠키 생성
			Cookie c = new Cookie(name, value);
			c.setMaxAge(expire);
			// 쿠키 추가
			response.addCookie(c);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	// 쿠키를 제거하는 메서드
	public void removeCookie(String name){
		// 쿠키 생성
		Cookie c = new Cookie(name, "");
		c.setMaxAge(0);
		response.addCookie(c);
	}
	// 컬렉션에 저장된 값을 반환 받는다.
	public String getCookie(String name, String encoding){
		try{
			String value = cookie_info.get(name);
			if(value != null){
				value = URLDecoder.decode(value, encoding);
			}
			return value;
		}catch(Exception e){
			e.printStackTrace();
		}
		return null;
	}
}











