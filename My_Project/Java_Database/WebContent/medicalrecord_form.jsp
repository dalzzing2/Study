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
		<h1>���� ��϶�</h1>
		<hr color=green width=400>
		<form action="medicalrecord_main.jsp" method="POST">
		���� �̸� : <input type="text" name="medicalrecordid"><br><br>
		���� ��¥ : <input type="text" name="recorddate"><br><br>
		��� �ǻ� : <input type="text" name="doctorid"><br><br>
		��� ȯ�� : <input type="text" name="patientid"><br><br>
		���� �̸� : <input type="text" name="diseasename"><br><br>
		ȯ�� ó�� : <input type="text" name="description"><br><br>
		ȯ�� ���� : <input type="text" name="prescription"><br><br>
		���� : <input type="text" name="signature"><br><br>
		<input type="submit" value="�����ϱ�"><input type="reset" value="�ٽþ���">
		</form>
	</center>
</body>
</html>