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
			
			String sql = "select messageid, type, doctorid, datetime, title, content, signature from message where patientid=?";
			
			String patientid = ((String) session.getAttribute("patientid"));
			
			PreparedStatement st = con.prepareStatement(sql);
			st.setString(1, patientid);
			ResultSet rs = st.executeQuery();
			
			while(rs.next()){

				String messageid = rs.getString("messageid");
				String doctorid = rs.getString("doctorid");
				String type = rs.getString("type");
				String datetime = rs.getString("datetime");
				String title = rs.getString("title");
				String content = rs.getString("content");
				String signature = rs.getString("signature");

				if (!patientid.equals(signature)) {
	%><br>----------------------------------<%			
	%><br>�޽��� ���̵� :	<%out.println(messageid);
	%><br>���� �ǻ� ���̵� :<%	out.println(doctorid);
	%><br>���� �ð� :<%out.println(datetime);
	%><br>���� :<%out.println(type);
	%><br>���� :<%out.println(title);
	%><br>���� :<%out.println(content);
	%><br>���� :<%out.println(doctorid);
	%><br>----------------------------------<%
				}
			}
			%><br><br><form action="patient_info.jsp" method="POST"><input type="submit" value="���ư���"></form><%
			%><br><form action="logout.jsp" method="POST"><input type="submit" value="�α׾ƿ�"></form><%	
	rs.close();
	st.close();
	con.close();
		} catch (Exception e) {
			out.println("Error");

		}//out.println(" "+patientid+" "+messageid+" "+type+" "+doctorid+" "+datetime+" "+title+" "+content+" "+signature);
	%>
	
</body>
</html>