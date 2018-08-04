<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor="yellow">
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
	request.setCharacterEncoding("EUC-KR");
	String patientid = request.getParameter("patientid");
	String loginpwd = request.getParameter("loginpwd");
	String name = request.getParameter("name");
	String ssn = request.getParameter("ssn");
	String gender = request.getParameter("gender");
	String birth = request.getParameter("birth");
	String address = request.getParameter("address");
	String phoneno = request.getParameter("phoneno");
	String height = request.getParameter("height");
	String weight = request.getParameter("weight");
	String bloodtype = request.getParameter("bloodtype");
	String firstvisitdate = request.getParameter("firstvisitdate");
	String publickey = request.getParameter("publickey");
	String privatekey = request.getParameter("privatekey");
	
	loginpwd=createHash(loginpwd);
	
	try {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
		Connection con = DriverManager.getConnection(DB_URL,
				"md09253064", "910206");
		String sql = "Insert into patients values(?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
		PreparedStatement ps = con.prepareStatement(sql);

		ps.setString(1, patientid);	
		ps.setString(2, name);
		ps.setString(3, ssn);
		ps.setString(4, gender);
		ps.setString(5, birth);
		ps.setString(6, address);
		ps.setString(7, phoneno);
		ps.setString(8, height);
		ps.setString(9, weight);
		ps.setString(10, bloodtype);
		ps.setString(11, firstvisitdate);
		ps.setString(12, publickey);
		ps.setString(13, privatekey);
		ps.setString(14, loginpwd);
		//out.println(""+patientid+", "+name+", "+ssn+", "+gender+", "+birth+", "+address+", "+phoneno+", "+height+", "+weight+", "+bloodtype+", "+firstvisitdate+", "+publickey+", "+privatekey+", "+loginpwd);
		ps.executeUpdate();
		
		ps.close();
		con.close();
		
		%><script>location.href="loginjoin.jsp";alert('회원가입에 성공하셨습니다.');</script><%
	} catch (Exception e) {
		out.println("Error");
	}
%>
</body>
</html>