<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<jsp:useBean id="bean1" class="bean.MemberBean"
			scope="session"/>
<jsp:useBean id="bean2" class="bean.MemberBean"
            scope="application"/>
<%
//	MemberBean bean1 
//			= (MemberBean)session.getAttribute("bean1");
//	MemberBean bean2
//		= (MemberBean)application.getAttribute("bean2");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>결과 페이지</title>
</head>
<body>
	Session : <br/>
	name : <%= bean1.getName() %><br/>
	age : <%= bean1.getAge() %><br/>
	gender : <%= bean1.getGender() %><br/>
	<br/>
	Application : <br/>
	name : <%= bean2.getName() %><br/>
	age : <%= bean2.getAge() %><br/>
	gender : <%= bean2.getGender() %><br/>	
</body>
</html>







