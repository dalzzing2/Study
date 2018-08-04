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
		<h1>환자 가입란</h1>
		<hr color=green width=400>
		<form action="patient_login.jsp" method="POST">
		아이디 : <input type="text" name="patientid"><br><br>
		비밀번호 : <input type="password" name="loginpwd"><br><br>
		이름 : <input type="text" name="name"><br><br>
		이메일 : <input type="text" name="ssn"><br><br>
		성별 : <input type="radio" name="gender" value="man">남<input type="radio" name="gender" value="woman">여<br><br>
		생년월일 : <input type="text" name="birth"><br><br>
		주소 : <input type="text" name="address"><br><br>
		전화번호 : <input type="text" name="phoneno"><br><br>
		키 : <input type="text" name="height"><br><br>
		몸무게 : <input type="text" name="weight"><br><br>
		혈액형 : <input type="radio" name="bloodtype" value="A">A<input type="radio" name="bloodtype" value="B">B
		<input type="radio" name="bloodtype" value="AB">AB<input type="radio" name="bloodtype" value="O">B<br><br>
		가입날짜 : <input type="text" name="visitdate"><br><br>
		PublicKey : <input type="password" name="publickey"><br><br>
		PrivateKey : <input type="password" name="privatekey"><br><br>
		<input type="submit" value="회원가입"><input type="reset" value="다시작성">
		</form>
		</center>
</body>
</html>