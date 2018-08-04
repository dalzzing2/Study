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
	request.setCharacterEncoding("EUC-KR");
	
	String doctorid = ((String) session.getAttribute("doctorid"));
	//수정 -> String name = request.getParameter("name");
	String patientid = request.getParameter("patientid");
	String assigndate = request.getParameter("assigndate");

	try {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
		Connection con = DriverManager.getConnection(DB_URL,
				"md09253064", "910206");
		String sql = "insert into assign values(?,?,?)";
		PreparedStatement ps = con.prepareStatement(sql);

		ps.setString(1, doctorid);
		ps.setString(2, patientid);
		//수정 ps.setString(2, name);
		ps.setString(3, assigndate);
		
		ps.executeUpdate();

		ps.close();
		con.close();
		%><script>location.href="doctor_info.jsp";alert('담당환자를 등록하셨습니다.');</script><%
	} catch (Exception e) {
		%><script>location.href="doctor_info.jsp";alert('환자의 아이디가 없습니다.');</script><%
	}
%>	
</body>
</html>