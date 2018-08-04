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
	%>메시지 코드 :
	<%
		out.println(medicalrecordid);
	%><br>
	<br>환자 아이디 :
	<%
		out.println(patientid);
	%><br>
	<br>진찰 날짜 :
	<%
		out.println(recorddate);
	%><br>
	<br>질병 이름 :
	<%
		out.println(diseasename);
	%><br>
	<br>처방전 :
	<%
		out.println(description);
	%><br>
	<br>설명서 :
	<%
		out.println(prescription);
	%><br>
	<br>서명 :
	<%
		out.println(signature);
	%><br><br>--------------------------------<br><%
	} rs.close(); st.close(); con.close();
	%>
	
	<br>
	<br>
	<form action="select_p.jsp" method="POST">
		<input type="submit" value="돌아가기">
	</form>
	<br>
	<form action="logout.jsp" method="POST">
		<input type="submit" value="로그아웃">
	</form>
	<%		
		} catch (Exception e) {
			out.println("Error");

		}
	%>
</body>
</html>