<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%-- request에 있는 빈 객체를 추출 --%>
<jsp:useBean id="bean" class="bean.MemberBean"
             scope="request"/>
<%
	// request에 담겨져 있는 빈 객체를 추출
	//MemberBean bean 
	//		= (MemberBean)request.getAttribute("bean");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Request Scope Java Bean</title>
</head>
<body>
<%--
	name : <%= bean.getName() %><br/>
	age : <%= bean.getAge() %><br/>
	gender : <%= bean.getGender() %><br/>
 --%>
 	name : <jsp:getProperty property="name" name="bean"/>
 	<br/>
 	age : <jsp:getProperty property="age" name="bean"/>
 	<br/>
 	gender : <jsp:getProperty property="gender" name="bean"/>
</body>
</html>














