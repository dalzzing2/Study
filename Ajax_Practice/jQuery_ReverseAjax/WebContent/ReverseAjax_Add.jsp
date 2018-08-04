<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ page import="java.sql.*"%>
<%
	// 파라미터 한글처리
	request.setCharacterEncoding("utf-8");
	// 파라미터 추출
	String user_id = request.getParameter("user_id");
	String content = request.getParameter("content");
	// 디비 접속
	String url = "jdbc:oracle:thin:@localhost:1521:orcl";
	String id = "scott";
	String pw = "1234";
	
	Class.forName("oracle.jdbc.OracleDriver");
	
	Connection db_con = DriverManager.getConnection(url, id, pw);
	
	String sql = "insert into JDBC_CHAT_TABLE values ("
			+ "JDBC_CHAT_SEQ.nextval, ?, ?)";
	
	PreparedStatement pstmt = db_con.prepareStatement(sql);
	
	pstmt.setString(1, user_id);
	pstmt.setString(2, content);
	
	pstmt.execute();
	
	db_con.close();
%>
<%=user_id%>