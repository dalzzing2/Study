<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
<%@ page import="java.sql.*"%>
	<center>
		<hr color=green width=400>
		<h1>ȯ�� ���Զ�</h1>
		<hr color=green width=400>
		<form action="patient_login.jsp" method="POST">
		���̵� : <input type="text" name="patientid"><br><br>
		��й�ȣ : <input type="password" name="loginpwd"><br><br>
		�̸� : <input type="text" name="name"><br><br>
		�̸��� : <input type="text" name="ssn"><br><br>
		���� : <input type="radio" name="gender" value="man">��<input type="radio" name="gender" value="woman">��<br><br>
		������� : <input type="text" name="birth"><br><br>
		�ּ� : <input type="text" name="address"><br><br>
		��ȭ��ȣ : <input type="text" name="phoneno"><br><br>
		Ű : <input type="text" name="height"><br><br>
		������ : <input type="text" name="weight"><br><br>
		������ : <input type="radio" name="bloodtype" value="A">A<input type="radio" name="bloodtype" value="B">B
		<input type="radio" name="bloodtype" value="AB">AB<input type="radio" name="bloodtype" value="O">B<br><br>
		���Գ�¥ : <input type="text" name="visitdate"><br><br>
		PublicKey : <input type="password" name="publickey"><br><br>
		PrivateKey : <input type="password" name="privatekey"><br><br>
		<input type="submit" value="ȸ������"><input type="reset" value="�ٽ��ۼ�">
		</form>
		</center>
</body>
</html>