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
		<h1>�ǻ� ���Զ�</h1>
		<hr color=green width=400>
		<form action="doctor_login.jsp" method="POST">
		���̵� : <input type="text" name="doctorid"><br><br>
		�̸� : <input type="text" name="name"><br><br>
		��й�ȣ : <input type="password" name="loginpwd"><br><br>
		�����ȣ : <input type="radio" name="departmentid" value="1-1">�ܰ�<input type="radio" name="departmentid" value="1-2">����<input type="radio" name="departmentid" value="1-3">�Ҿư�<br><br>
		��å : <input type="text" name="title"><br><br>
		�繫����ȭ��ȣ : <input type="text" name="officeno"><br><br>
		������ȭ��ȣ : <input type="text" name="phoneno"><br><br>
		�޿� : <input type="text" name="salary"><br><br>
		PublicKey : <input type="password" name="publickey"><br><br>
		PrivateKey : <input type="password" name="privatekey"><br><br>
		<input type="submit" value="ȸ������"><input type="reset" value="�ٽ��ۼ�"><br><br>
		</form>
	</center>
</body>
</html>