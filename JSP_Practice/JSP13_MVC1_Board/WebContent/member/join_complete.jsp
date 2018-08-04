<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="db.*" %>
<%@ page import="bean.*" %>
<%
	String path = request.getContextPath();
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
%>
<%-- 자바 빈 객체 생성 --%>
<jsp:useBean id="member_bean" class="bean.MemberBean"/>
<%-- 파라미터 데이터를 받는다 --%>
<jsp:setProperty property="*" name="member_bean"/>
<%
	// 데이터 베이스에 회원 정보를 저장한다.
	MemberDAO.add_user(member_bean);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>가입 완료</title>
</head>
<body>
	가입이 완료되었습니다<br/>
	<a href="<%=path%>/JSP13_Index.jsp">로그인하기</a>
</body>
</html>







