<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
	<%@page session="true"%>
	<%@page import="java.sql.*"%>
	<%@page import="java.security.*" %>
	<%!
    public String createHash(String data) throws Exception {
         if(data == null) {
             throw new NullPointerException();
         }

        MessageDigest md = MessageDigest.getInstance("SHA-256");
         byte[] raw = md.digest(data.getBytes("EUC-KR"));
        
         StringBuffer result = new StringBuffer();
         for(int i=0; i<raw.length; i++) {
             result.append(Integer.toHexString(raw[i] & 0xff));
         }
         return result.toString();
     }
 %>
	
	<%
		try {
			request.setCharacterEncoding("EUC-KR");
			Class.forName("oracle.jdbc.driver.OracleDriver");
			String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
			Connection con = DriverManager.getConnection(DB_URL,
					"md09253064", "910206");

			String query_d = "select * from doctor where doctorid=? and loginpwd=?";
			String query_p = "select * from patients where patientid=? and loginpwd=?";
			PreparedStatement st = con.prepareStatement(query_d);
			PreparedStatement st1 = con.prepareStatement(query_p);

			String job = request.getParameter("job");
			String id = request.getParameter("id");
			String loginpwd = request.getParameter("loginpwd");
			
			loginpwd = createHash(loginpwd);
			
			st.setString(1, id);
			st.setString(2, loginpwd);
			st1.setString(1, id);
			st1.setString(2, loginpwd);
			ResultSet rs = st.executeQuery();
			ResultSet ps = st1.executeQuery();
			
			
			
			if (job.equals("doctor")) {
				if (rs.next()) {
					String doctorid = rs.getString("doctorid");
					session.setAttribute("doctorid", doctorid);
	%><script>
		location.href = "doctor_info.jsp";
	</script>
	<%
		} else {
	%><script>
		alert('아이디 또는 비밀번호가 일치하지 않습니다.');
		location.href = "loginjoin.jsp";
	</script>
	<%
		}
			} else if (job.equals("patient")) {
				if (ps.next()) {
					String patientid = ps.getString("patientid");
					session.setAttribute("patientid", patientid);
	%><script>
		location.href = "patient_info.jsp";
	</script>
	<%
		} else {
	%><script>
		alert('아이디 또는 비밀번호가 일치하지 않습니다.');
		location.href = "loginjoin.jsp";
	</script>
	<%
		}
			}
			rs.close();
			st.close();
			st1.close();
			con.close();
		} catch (Exception e) {
			out.println("Error");
		}
	%>
</body>
</html>