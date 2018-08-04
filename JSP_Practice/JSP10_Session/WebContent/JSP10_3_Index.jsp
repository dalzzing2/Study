<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 세선으로 부터 정보를 추출
	String user_name 
			= (String)session.getAttribute("user_name");
	// 세션에 저장된 데이터가 없다면 첫 페이지로 강제이동
	if(user_name == null){
		response.sendRedirect("JSP10_3_Login.jsp");
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>로그인 완료</title>
</head>
<body>
	<%= user_name %>님 환영합니다.
</body>
</html>







