<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.net.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>쿠키 수정 하기</title>
</head>
<body>
	<%
		// 동일명의 쿠키를 만들어 추가하면
		// 이전 쿠키를 덮어 씌울수 있다.
		String str = URLEncoder.encode("감사합니다", "utf-8");
	    Cookie c = new Cookie("data1", str);
	    c.setMaxAge(365 * 24 * 60 * 60);
	    response.addCookie(c);
	%>
	쿠키 수정 완료
</body>
</html>










