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
	String doctorid = request.getParameter("doctorid");
	String name = request.getParameter("name");
	String loginpwd = request.getParameter("loginpwd");
	String departmentid = request.getParameter("departmentid");
	String title = request.getParameter("title");
	String officeno = request.getParameter("officeno");
	String phoneno = request.getParameter("phoneno");
	String salary = request.getParameter("salary");
	String publickey = request.getParameter("publickey");
	String privatekey = request.getParameter("privatekey");
	
	loginpwd=createHash(loginpwd);
	
	try {
		Class.forName("oracle.jdbc.driver.OracleDriver");
		String DB_URL = "jdbc:oracle:thin:@165.132.214.251:1521:XE";
		Connection con = DriverManager.getConnection(DB_URL,
				"md09253064", "910206");
		String sql = "insert into doctor(doctorid, name, departmentid, title, officeno, phoneno, salary, publickey, privatekey, loginpwd) values(?,?,?,?,?,?,?,?,?,?)";
		PreparedStatement ps = con.prepareStatement(sql);

		ps.setString(1, doctorid);
		ps.setString(2, name);
		ps.setString(3, departmentid);
		ps.setString(4, title);
		ps.setString(5, officeno);
		ps.setString(6, phoneno);
		ps.setString(7, salary);
		ps.setString(8, publickey);
		ps.setString(9, privatekey);
		ps.setString(10, loginpwd);
		
		
		
		//out.println(""+doctorid+", "+name+", "+departmentid+", "+title+", "+officeno+", "+phoneno+", "+salary+", "+publickey+", "+privatekey+", "+loginpwd+", ");
		
		ps.executeUpdate();
		out.println("\na");
		ps.close();
		con.close();
		%><script>location.href="loginjoin.jsp";alert('회원가입에 성공하셨습니다.');</script><%
	} catch (Exception e) {
		out.println("Error");

	}
%>
</body>
</html>