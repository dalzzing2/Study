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
		<h1>회원가입,로그인</h1>
		<hr color=green width=500>
			<form action="login.jsp" method="POST">
			직업 : <input type="radio" name="job" value="doctor">의사
			<input type="radio" name="job" value="patient">환자<br><br>
			아이디 : <input type="text" name="id"><br><br>
			비밀번호 : <input type="password" name="loginpwd"><br>
			<br><input type="submit" value="로그인"><br><br>
			</form>
			<form action="doctor_join.jsp" method="POST"><input type="submit" value="의사회원가입"><br><br>
			</form>
			<form action="patient_join.jsp" method="POST"><input type="submit" value="환자회원가입"><br><br>
			</form>
	</center>
</body>
</html>