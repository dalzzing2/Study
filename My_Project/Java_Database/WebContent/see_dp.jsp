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
		<hr color=green width=400>
		<h1>담당 환자 저장</h1>
		<hr color=green width=400>
		<form action="see_p.jsp" method="POST">
		담당 환자 아이디 : <input type="text" name="patientid"><br><br>
		<input type="hidden" name="doctorid" value="<%session.getAttribute("doctorid"); %>">
		<input type="hidden" name="assigndate" value="<%=new java.util.Date()%>">
		<input type="submit" value="저장"><input type="reset" value="다시작성"><br><br>
		</form><form action="doctor_info.jsp" method="POST"><input type="submit" value="돌아가기"></form>
	</center>
</body>
</html>