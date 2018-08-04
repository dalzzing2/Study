<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 오류가 났을 경우 보여줄 페이지 지정 --%>
<%@ page errorPage="JSP8_1_Error.jsp" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>오류가 발생되는 페이지</title>
</head>
<body>
	<%-- 오류 발생 --%>
	<% int a = 10 / 0; %>
</body>
</html>










