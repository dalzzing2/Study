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
		<h1>의사 가입란</h1>
		<hr color=green width=400>
		<form action="doctor_login.jsp" method="POST">
		아이디 : <input type="text" name="doctorid"><br><br>
		이름 : <input type="text" name="name"><br><br>
		비밀번호 : <input type="password" name="loginpwd"><br><br>
		사원번호 : <input type="radio" name="departmentid" value="1-1">외과<input type="radio" name="departmentid" value="1-2">내과<input type="radio" name="departmentid" value="1-3">소아과<br><br>
		직책 : <input type="text" name="title"><br><br>
		사무실전화번호 : <input type="text" name="officeno"><br><br>
		개인전화번호 : <input type="text" name="phoneno"><br><br>
		급여 : <input type="text" name="salary"><br><br>
		PublicKey : <input type="password" name="publickey"><br><br>
		PrivateKey : <input type="password" name="privatekey"><br><br>
		<input type="submit" value="회원가입"><input type="reset" value="다시작성"><br><br>
		</form>
	</center>
</body>
</html>