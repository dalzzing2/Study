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
	String patientid = ((String)session.getAttribute("patientid"));
	String messageid = request.getParameter("messageid");
	String datetime = request.getParameter("datetime");
	String doctorid = request.getParameter("doctorid");
	String type = request.getParameter("type");
	String title = request.getParameter("title");
	String content = request.getParameter("content");
	String signature = request.getParameter("signature");
	
	Class.forName("oracle.jdbc.driver.OracleDriver");
	String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
	Connection con = DriverManager.getConnection(DB_URL,
			"md09253064", "910206");
	request.setCharacterEncoding("EUC-KR");
	String sql = "insert into message(messageid, type, patientid, doctorid, datetime, title, content, signature) values(?,?,?,?,?,?,?,?)";

	PreparedStatement st = con.prepareStatement(sql);
	
	st.setString(1, messageid);
	st.setString(2, type);
	st.setString(3, patientid);
	st.setString(4, doctorid);
	st.setString(5, datetime);
	st.setString(6, title);
	st.setString(7, content);
	st.setString(8, signature);
	//out.println(""+messageid+" "+type+" "+patientid+" "+doctorid+" "+datetime+" "+title+" "+content+" "+signature);
	st.executeUpdate();
	out.println("succes?");
	
	st.close();
	con.close();
	%><script>location.href="patient_info.jsp";alert('메시지를 보냈습니다.');</script><%
}catch (Exception e) {
	out.println("Error");

}
%>
</body>
</html>