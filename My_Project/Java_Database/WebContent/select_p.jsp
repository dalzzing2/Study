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
				//수정 -> String name = rs.getString("name");
				String assigndate = rs.getString("assigndate");
				if (ks.next()) {

					String patientid2 = ks.getString("patientid");
					//수정 -> String name2 = ks.getString("name");
					String name = ks.getString("name");
					String ssn = ks.getString("ssn");
					String gender = ks.getString("gender");
					String height = ks.getString("height");
					String weight = ks.getString("weight");
					String bloodtype = ks.getString("bloodtype");
					if (patientid.equals(patientid2)) {//수정 -> if(name.equals(name2)){
	%>---------------------------------------------
	<br>
	<%
		
	%>담당 환자 아이디 :
	<%
		out.println(patientid);
	%><br>
	<br>방문 시간 :
	<%
		out.println(assigndate);
	%><br>
	<br>환자 이름 :
	<%
		out.println(name);
	%><br>
	<br>환자 이메일 :
	<%
		out.println(ssn);
	%><br>
	<br>환자 성별 :
	<%
		out.println(gender);
	%><br>
	<br>환자 키 :
	<%
		out.println(height);
	%><br>
	<br>환자 몸무게 :
	<%
		out.println(weight);
	%><br>
	<br>환자 혈액형 :
	<%
		out.println(bloodtype);
	
	%><br>
	<br>---------------------------------------------<%
	
		}

				}
			}%><br><form action="medicalrecord_form.jsp" method="POST"><input type="submit" value="진찰기록저장"></form><form action="medicalrecord_d_d_see.jsp" method="POST"><input type="submit" value="진찰기록보기"></form><%
				%><br><br><form action="doctor_info.jsp" method="POST"><input type="submit" value="돌아가기"></form><%
			%><br><form action="logout.jsp" method="POST"><input type="submit" value="로그아웃"></form><%	
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