<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%-- page scope로 빈 객체를 생성 --%>
<jsp:useBean id="bean" class="bean.MemberBean"/>
<jsp:setProperty name="bean" property="name" value="홍길동"/>
<jsp:setProperty name="bean" property="age" value="30"/>
<jsp:setProperty name="bean" property="gender" value="1"/>
<%
//	MemberBean bean = new MemberBean();
//	bean.setName("홍길동");
//	bean.setAge(30);
//	bean.setGender(1);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Page Scope Java Bean</title>
</head>
<body>
<%--
	name : <%= bean.getName() %><br/>
	age : <%= bean.getAge() %><br/>
 --%>
 	name : <jsp:getProperty property="name" name="bean"/>
 	<br/>
 	age : <jsp:getProperty property="age" name="bean"/>
 	<br/>
	gender : <%= bean.getGender() == 1 ? "남자" : "여자" %>
</body>
</html>







