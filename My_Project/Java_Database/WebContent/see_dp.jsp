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
		<h1>��� ȯ�� ����</h1>
		<hr color=green width=400>
		<form action="see_p.jsp" method="POST">
		��� ȯ�� ���̵� : <input type="text" name="patientid"><br><br>
		<input type="hidden" name="doctorid" value="<%session.getAttribute("doctorid"); %>">
		<input type="hidden" name="assigndate" value="<%=new java.util.Date()%>">
		<input type="submit" value="����"><input type="reset" value="�ٽ��ۼ�"><br><br>
		</form><form action="doctor_info.jsp" method="POST"><input type="submit" value="���ư���"></form>
	</center>
</body>
</html>