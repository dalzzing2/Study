<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 데이터를 셋팅
	pageContext.setAttribute("str1", "문자열1");
	request.setAttribute("str2", "문자열2");
	session.setAttribute("str3", "문자열3");
	application.setAttribute("str4", "문자열4");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>EL 기본예제</title>
</head>
<body>
	page str1 : <%= pageContext.getAttribute("str1") %>
	<br/>
	request str2 : <%=request.getAttribute("str2") %>
	<br/>
	session str3 : <%= session.getAttribute("str3") %>
	<br/>
	application str4 : <%=application.getAttribute("str4") %>
	<br/>
	<br/>
	page str1 : ${pageScope.str1}<br/>
	request str2 : ${requestScope.str2}<br/>
	session str3 : ${sessionScope.str3}<br/>
	application str4 : ${applicationScope.str4}<br/>
	<br/>
	page str1 : ${str1}<br/>
	request str2 : ${str2}<br/>
	session str3 : ${str3}<br/>
	application str4 : ${str4}<br/>
	
	param : <%=request.getParameter("data1") %><br/>
	param : ${param.data1}<br/>
	param : ${data1}<br/>
</body>
</html>











