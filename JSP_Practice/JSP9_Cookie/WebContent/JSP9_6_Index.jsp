<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 사용자 이름 값을 추출
	String user_name 
			= (String)request.getAttribute("user_name");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>index</title>
</head>
<body>
	<%= user_name %>님 환영합니다.<br/>
	<a href="JSP9_6_CookieLogout">로그아웃</a>
</body>
</html>












