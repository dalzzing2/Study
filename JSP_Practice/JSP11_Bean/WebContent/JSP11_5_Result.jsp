<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%
	// 파라미터 데이터 추출
	request.setCharacterEncoding("utf-8");

//	String name = request.getParameter("name");
//	String age_str = request.getParameter("age");
//	String gender_str = request.getParameter("gender");
	
//	MemberBean bean = new MemberBean();
//	bean.setName(name);
//	bean.setAge(Integer.parseInt(age_str));
//	bean.setGender(Integer.parseInt(gender_str));
%>
<%-- 빈 객체를 생성한다. --%>
<jsp:useBean id="bean" class="bean.MemberBean"/>
<%-- 파라미터 데이터를 받는다 --%>
<%-- param : 파라미터의 이름 --%>
<%--
<jsp:setProperty property="name" name="bean" 
                 param="name"/>
<jsp:setProperty property="age" name="bean" 
                 param="age"/>
<jsp:setProperty property="gender" name="bean" 
                 param="gender"/>
 --%>
<%-- 
	파라미터의 이름(param)과 담을 곳(property)이
	같을 경우 파라미터의 개수에 관계없이 한줄로 받는다.
 --%>
<jsp:setProperty property="*" name="bean"/>
                 

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>파라미터 받기</title>
</head>
<body>
	name : <%= bean.getName() %><br/>
	age : <%= bean.getAge() %><br/>
	gender : <%= bean.getGender() %><br/>
</body>
</html>





