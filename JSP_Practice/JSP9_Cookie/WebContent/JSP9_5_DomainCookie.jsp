<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>도메인별로 쿠키 관리하기</title>
</head>
<body>
	<%
		// 도메인을 설정하지 않고 쿠키 저장
		// 이 페이지를 띄울 때 사용한 도메인에서만
		// 사용 가능한 쿠키
		Cookie c1 = new Cookie("test1", "abc");
		c1.setMaxAge(365 * 24 * 60 * 60);
		response.addCookie(c1);
		// 도메인을 지정하여 쿠키 저장
		Cookie c2 = new Cookie("test2", "123");
		c2.setMaxAge(365 * 24 * 60 * 60);
		c2.setDomain("www.abc.com");
		response.addCookie(c2);
		// abc.com인 도메인에서는 모두 사용할 수 있는
		// 쿠키
		Cookie c3 = new Cookie("test3", "123");
		c3.setMaxAge(365 * 24 * 60 * 60);
		c3.setDomain(".abc.com");
		response.addCookie(c3);
	%>
	쿠키 저장 완료
</body>
</html>










