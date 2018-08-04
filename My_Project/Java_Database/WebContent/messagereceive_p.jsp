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
	%><br>메시지 아이디 :	<%out.println(messageid);
	%><br>보낸 의사 아이디 :<%	out.println(doctorid);
	%><br>보낸 시간 :<%out.println(datetime);
	%><br>유형 :<%out.println(type);
	%><br>제목 :<%out.println(title);
	%><br>내용 :<%out.println(content);
	%><br>서명 :<%out.println(doctorid);
	%><br>----------------------------------<%
				}
			}
			%><br><br><form action="patient_info.jsp" method="POST"><input type="submit" value="돌아가기"></form><%
			%><br><form action="logout.jsp" method="POST"><input type="submit" value="로그아웃"></form><%	
	rs.close();
	st.close();
	con.close();
		} catch (Exception e) {
			out.println("Error");

		}//out.println(" "+patientid+" "+messageid+" "+type+" "+doctorid+" "+datetime+" "+title+" "+content+" "+signature);
	%>
	
</body>
</html>