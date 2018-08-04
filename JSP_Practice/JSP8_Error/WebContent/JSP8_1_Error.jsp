<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 에러 페이지임을 설정한다. --%>
<%@ page isErrorPage="true" %>
<%@ page import="java.io.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>에러 페이지 입니다.</title>
</head>
<body>
	오류 발생 !!!!<br/>
	<%= exception.getClass().getName() %><br/>
	<%= exception.getMessage() %><br/>
	<%
		exception.printStackTrace();
	
		PrintWriter out2 = response.getWriter();
		exception.printStackTrace(out2);
	%>
	
</body>
</html>









