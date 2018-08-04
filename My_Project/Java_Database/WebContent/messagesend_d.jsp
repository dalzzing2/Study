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
		<h1>메시지보내기</h1>
		<hr color=green width=500>
		<form action="messagemid_dp.jsp" method="POST">
		메시지 아이디 : <input type="text" name="messageid"><br><br>
		환자 아이디 : <input type="text" name="patientid"><br><br>
		유형 : <input type="radio" name="type" value="진찰">진찰
		<input type="radio" name="type" value="예약">예약<br><br>
		제목 : <input type="text" name="title"><br><br>
		<input type="hidden" name="signature" value="<%session.getAttribute("doctorid");%>">
		내용 : <textarea name="content" cols=50 rows=10></textarea><br>
		<input type="hidden" name="doctorid" value="<%session.getAttribute("doctorid"); %>">
		<input type="hidden" name="datetime" value="<%=new java.util.Date()%>">
		<input type="submit" value="보내기"><input type="reset" value="다시작성"></form>
		<form action="doctor_info.jsp" method="POST"><input type="submit" value="돌아가기">
		
		</form>
	</center>
</body>
</html>