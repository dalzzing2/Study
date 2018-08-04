<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>쿠키 삭제</title>
</head>
<body>
	<%
		// 수명이 0인 쿠키를 만들어 추가한다.
		Cookie c = new Cookie("data1", "");
		c.setMaxAge(0);
		response.addCookie(c);
	%>
</body>
</html>











