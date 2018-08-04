<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	String value1 = request.getParameter("value1");
	String value2 = request.getParameter("value2");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>forward 액션 태그를 이용하여 이동</title>
</head>
<body>
	value1 : <%=value1%><br/>
	value2 : <%=value2%><br/>
</body>
</html>








