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
		<h1>ȸ������,�α���</h1>
		<hr color=green width=500>
			<form action="login.jsp" method="POST">
			���� : <input type="radio" name="job" value="doctor">�ǻ�
			<input type="radio" name="job" value="patient">ȯ��<br><br>
			���̵� : <input type="text" name="id"><br><br>
			��й�ȣ : <input type="password" name="loginpwd"><br>
			<br><input type="submit" value="�α���"><br><br>
			</form>
			<form action="doctor_join.jsp" method="POST"><input type="submit" value="�ǻ�ȸ������"><br><br>
			</form>
			<form action="patient_join.jsp" method="POST"><input type="submit" value="ȯ��ȸ������"><br><br>
			</form>
	</center>
</body>
</html>