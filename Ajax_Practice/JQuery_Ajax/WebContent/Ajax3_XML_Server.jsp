<%@ page contentType="text/xml; charset=utf-8" pageEncoding="utf-8"%>
<%@ page trimDirectiveWhitespaces="true"%>
<%@ page import="java.sql.*" %>
<?xml version="1.0" encoding="utf-8"?>
<%
	// db 접속
	String url = "jdbc:oracle:thin:@localhost:1521:orcl";
	String id = "scott";
	String pw = "1234";
	
	Class.forName("oracle.jdbc.OracleDriver");
	Connection db_con = DriverManager.getConnection(url, id, pw);
	
	String sql = "select * from JDBC_MEMBER_TABLE";
	// 쿼리 실행
	Statement stmt = db_con.createStatement();
	ResultSet rs = stmt.executeQuery(sql);
%>
<user>
<%	while(rs.next()){ %>
	<member>
		<user_id><%=rs.getString("USER_ID")%></user_id>
		<user_pw><%=rs.getString("USER_PW")%></user_pw>
		<user_name><%=rs.getString("USER_NAME")%></user_name>
	</member>
<%	} %>
<%	db_con.close(); %>
</user>