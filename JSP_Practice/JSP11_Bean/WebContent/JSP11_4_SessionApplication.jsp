<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<jsp:useBean id="bean1" class="bean.MemberBean"
             scope="session"/>
<jsp:useBean id="bean2" class="bean.MemberBean"
             scope="application"/>

<jsp:setProperty property="name" name="bean1" 
                 value="김길동"/>
<jsp:setProperty property="age" name="bean1"
                 value="10"/>
<jsp:setProperty property="gender" name="bean1"
                 value="1"/>
                 
<jsp:setProperty property="name" name="bean2"
                 value="박길동"/>
<jsp:setProperty property="age" name="bean2"
                 value="50"/>
<jsp:setProperty property="gender" name="bean2"
                 value="2"/>                 
<%
//	MemberBean bean1 = new MemberBean();
//	MemberBean bean2 = new MemberBean();
	
//	bean1.setName("김길동");
//	bean1.setAge(10);
//	bean1.setGender(1);
	
//	bean2.setName("박길동");
//	bean2.setAge(50);
//	bean2.setGender(2);
	// 세션과 애플리케이션에 객체를 담는다.
//	session.setAttribute("bean1", bean1);
//	application.setAttribute("bean2", bean2);
	
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Session, Application Scope Java Bean</title>
</head>
<body>
	<a href="JSP11_4_Result.jsp">결과 보기</a>
</body>
</html>






