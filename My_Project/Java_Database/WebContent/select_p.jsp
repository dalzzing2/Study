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

			String sql = "select patientid, assigndate from assign where doctorid=?";
			//String sql = "select name, assigndate from assign where doctorid=?";
			String sql1 = "select patientid, name, ssn, gender, height, weight, bloodtype from patients";

			String doctorid = ((String) session.getAttribute("doctorid"));
			PreparedStatement st = con.prepareStatement(sql);

			st.setString(1, doctorid);
			ResultSet rs = st.executeQuery();

			Statement stmt = con.createStatement();
			ResultSet ks = stmt.executeQuery(sql1);
			while (rs.next()) {
				String patientid = rs.getString("patientid");
				//���� -> String name = rs.getString("name");
				String assigndate = rs.getString("assigndate");
				if (ks.next()) {

					String patientid2 = ks.getString("patientid");
					//���� -> String name2 = ks.getString("name");
					String name = ks.getString("name");
					String ssn = ks.getString("ssn");
					String gender = ks.getString("gender");
					String height = ks.getString("height");
					String weight = ks.getString("weight");
					String bloodtype = ks.getString("bloodtype");
					if (patientid.equals(patientid2)) {//���� -> if(name.equals(name2)){
	%>---------------------------------------------
	<br>
	<%
		
	%>��� ȯ�� ���̵� :
	<%
		out.println(patientid);
	%><br>
	<br>�湮 �ð� :
	<%
		out.println(assigndate);
	%><br>
	<br>ȯ�� �̸� :
	<%
		out.println(name);
	%><br>
	<br>ȯ�� �̸��� :
	<%
		out.println(ssn);
	%><br>
	<br>ȯ�� ���� :
	<%
		out.println(gender);
	%><br>
	<br>ȯ�� Ű :
	<%
		out.println(height);
	%><br>
	<br>ȯ�� ������ :
	<%
		out.println(weight);
	%><br>
	<br>ȯ�� ������ :
	<%
		out.println(bloodtype);
	
	%><br>
	<br>---------------------------------------------<%
	
		}

				}
			}%><br><form action="medicalrecord_form.jsp" method="POST"><input type="submit" value="�����������"></form><form action="medicalrecord_d_d_see.jsp" method="POST"><input type="submit" value="������Ϻ���"></form><%
				%><br><br><form action="doctor_info.jsp" method="POST"><input type="submit" value="���ư���"></form><%
			%><br><form action="logout.jsp" method="POST"><input type="submit" value="�α׾ƿ�"></form><%	
			stmt.close();
			ks.close();
			rs.close();
			st.close();
			con.close();
		} catch (Exception e) {
			out.println("Error");
		}
	%>
</body>
</html>