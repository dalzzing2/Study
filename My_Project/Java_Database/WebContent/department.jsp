<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<%@page import="java.sql.*"%>
	<%
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
			Connection con = DriverManager.getConnection(DB_URL,
					"md09253064", "910206");
			request.setCharacterEncoding("EUC-KR");

			String sql = "select departmentid, doctorid from doctor where doctorid=?";
			String sql1 = "select departmentid, name, building, description, repphoneno from department";
			
			String doctorid = ((String) session.getAttribute("doctorid"));
			PreparedStatement st = con.prepareStatement(sql);
			
			st.setString(1, doctorid);
			ResultSet rs = st.executeQuery();
			
			Statement stmt = con.createStatement();
			ResultSet ks = stmt.executeQuery(sql1);
			
			while (rs.next()) {
				String departmentid = rs.getString("departmentid");
				if (ks.next()) {
					String departmentid2 = ks.getString("departmentid");
					String name = ks.getString("name");
					String building = ks.getString("building");
					String description = ks.getString("description");
					String repphoneno = ks.getString("repphoneno");
					if (departmentid.equals(departmentid2)) {
	%>�μ� �ڵ� :
	<%
		out.println(departmentid);
	%><br></br>�μ� �̸� :
	<%
		out.println(name);
	%><br></br>�μ� �ǹ� :
	<%
		out.println(building);
	%><br></br>�μ� ���� :
	<%
		out.println(description);
	%><br></br>�μ� ��ȣ :
	<%
		out.println(repphoneno);
					}
				}
				ks.close();
			}

			rs.close();
			st.close();
			con.close();
			%><br><br><form action="doctor_info.jsp" method="POST"><input type="submit" value="���ư���"></form><%
			%><br><form action="logout.jsp" method="POST"><input type="submit" value="�α׾ƿ�"></form><%		
		} catch (Exception e) {
			out.println("Error");

		}
	%>
</body>
</html>