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
		<h1>진찰 기록란</h1>
		<hr color=green width=400>
		<form action="medicalrecord_main.jsp" method="POST">
		진찰 이름 : <input type="text" name="medicalrecordid"><br><br>
		진찰 날짜 : <input type="text" name="recorddate"><br><br>
		담당 의사 : <input type="text" name="doctorid"><br><br>
		담당 환자 : <input type="text" name="patientid"><br><br>
		질병 이름 : <input type="text" name="diseasename"><br><br>
		환자 처방 : <input type="text" name="description"><br><br>
		환자 예약 : <input type="text" name="prescription"><br><br>
		서명 : <input type="text" name="signature"><br><br>
		<input type="submit" value="저장하기"><input type="reset" value="다시쓰기">
		</form>
	</center>
</body>
</html>