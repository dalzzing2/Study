<%--
	contentType : 브라우저에게 전달할 데이터의 타입
	pageEncoding : 자바 파일로 변환될 때 사용할 타입
 --%>
<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 다른 패키지의 클래스를 사용할 경우에는
     import를 해야 한다.
 --%>
<%@ page import="java.util.*" %>
<%@ page import="java.io.*" %>
<%@ page import="java.net.*, java.math.*" %>
<%-- 지시자 때문에 생긴 공백을 제거한다. --%>
<%@ page trimDirectiveWhitespaces="true" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Page 지시자 예제</title>
</head>
<body>
	<%
		Date date = new Date();
		System.out.println(date);
	%>
</body>
</html>









