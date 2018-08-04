<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%
	// 자바 빈 객체를 생성한다.
	MemberBean bean = new MemberBean();
	// 빈 객체에 값을 담는다.
	bean.setName("홍길동");
	bean.setAge(30);
	bean.setGender(1);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>빈 객체 기본 사용하기</title>
</head>
<body>
	name : <%= bean.getName() %><br/>
	age : <%= bean.getAge() %><br/>
	gender : <%= bean.getGender() == 1 ? "남자" : "여자" %>
</body>
</html>










