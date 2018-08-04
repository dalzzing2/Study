<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
	<%@page import="java.sql.*"%>
	<%
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
			Connection con = DriverManager.getConnection(DB_URL,
					"md09253064", "910206");
			request.setCharacterEncoding("EUC-KR");

			String sql = "select medicalrecordid, patientid, recorddate, diseasename, description, prescription, signature from medicalrecord where doctorid=?";
			
			String doctorid = ((String) session.getAttribute("doctorid"));
			PreparedStatement st = con.prepareStatement(sql);
			
			st.setString(1, doctorid);
			ResultSet rs = st.executeQuery();
			
			while (rs.next()) {
				String medicalrecordid = rs.getString("medicalrecordid");
				String patientid = rs.getString("patientid");
				String recorddate = rs.getString("recorddate");
				String diseasename = rs.getString("diseasename");
				String description = rs.getString("description");
				String prescription = rs.getString("prescription");
				String signature = rs.getString("signature");
	%>--------------------------------<br><br><%
	%>�޽��� �ڵ� :
	<%
		out.println(medicalrecordid);
	%><br>
	<br>ȯ�� ���̵� :
	<%
		out.println(patientid);
	%><br>
	<br>���� ��¥ :
	<%
		out.println(recorddate);
	%><br>
	<br>���� �̸� :
	<%
		out.println(diseasename);
	%><br>
	<br>ó���� :
	<%
		out.println(description);
	%><br>
	<br>���� :
	<%
		out.println(prescription);
	%><br>
	<br>���� :
	<%
		out.println(signature);
	%><br><br>--------------------------------<br><%
	} rs.close(); st.close(); con.close();
	%>
	
	<br>
	<br>
	<form action="select_p.jsp" method="POST">
		<input type="submit" value="���ư���">
	</form>
	<br>
	<form action="logout.jsp" method="POST">
		<input type="submit" value="�α׾ƿ�">
	</form>
	<%		
		} catch (Exception e) {
			out.println("Error");

		}
	%>
</body>
</html>