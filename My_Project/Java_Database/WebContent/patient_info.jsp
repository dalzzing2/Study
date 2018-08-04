<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
	<%@ page import="java.sql.*"%>
	<center>
		<hr color=green width=500>
		<h1>환자 정보,메시지</h1>
		<hr color=green width=500><br><br>
		<form action="logout.jsp" method="POST"><input type="submit" value="로그아웃"></form><br><br>
		<form action="messagereceive_p.jsp" method="POST"><input type="submit" value="메시지받기"></form><br><br>
		<form action="messagesend_p.jsp" method="POST"><input type="submit" value="메시지보내기"></form><br><br>	
		<form action="medicalrecord_p_see.jsp" method="POST"><input type="submit" value="진찰기록보기"></form>
	</center>
</body>
</html>