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
	request.setCharacterEncoding("EUC-KR");
	String medicalrecordid = request.getParameter("medicalrecordid");
	String recorddate = request.getParameter("recorddate");
	String doctorid = request.getParameter("doctorid");
	String patientid = request.getParameter("patientid");
	String diseasename = request.getParameter("diseasename");
	String description = request.getParameter("description");
	String prescription = request.getParameter("prescription");
	String signature = request.getParameter("signature");
	
	Class.forName("oracle.jdbc.driver.OracleDriver");
	String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
	Connection con = DriverManager.getConnection(DB_URL,
			"md09253064", "910206");
	request.setCharacterEncoding("EUC-KR");

	String sql = "insert into medicalrecord(medicalrecordid, patientid, doctorid, recorddate, diseasename, description, prescription, signature) values(?,?,?,?,?,?,?,?)";
	
	PreparedStatement st = con.prepareStatement(sql);
	
	st.setString(1, medicalrecordid);
	st.setString(2, patientid);
	st.setString(3, doctorid);
	st.setString(4, recorddate);
	st.setString(5, diseasename);
	st.setString(6, description);
	st.setString(7, prescription);
	st.setString(8, signature);
	
	st.executeUpdate();
	
	st.close();
	con.close();
	%><script>location.href="select_p.jsp";</script><%
}catch (Exception e) {
	out.println("Error");

}
%>
</body>
</html>