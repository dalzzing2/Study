<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
	<%@page session="true"%>
	<%@ page import="java.sql.*"%>
	
	<center>
		<hr color=green width=500>
		<h1>�ǻ� ����,�޽���</h1>
		<hr color=green width=500>
		<br><br>
		<form action="logout.jsp" method="POST"><input type="submit" value="�α׾ƿ�"><br><br></form>
		<form action="department.jsp" method="POST"><input type="submit" value="�μ���������"><br><br></form>
		<form action="messagesend_d.jsp" method="POST"><input type="submit" value="�޽��� ������"><br><br></form>
		<form action="messagereceive_d.jsp" method="POST"><input type="submit" value="�޽��� �ޱ�"><br><br></form>
		<form action="see_dp.jsp" method="POST"><input type="submit" value="���ȯ������"><br><br></form>
		<form action="select_p.jsp" method="POST"><input type="submit" value="���ȯ�ں���"></form>
	</center>
</body>
</html>