<%@ page contentType="text/json; charset=utf-8" pageEncoding="utf-8"%>
<%@ page trimDirectiveWhitespaces="true" %>
<%@ page import="java.sql.*" %>
<%@ page import="org.json.simple.*" %>
<%@ page import="org.json.simple.parser.*" %>
<%
	//db 접속
	String url = "jdbc:oracle:thin:@localhost:1521:orcl";
	String id = "scott";
	String pw = "1234";
	
	Class.forName("oracle.jdbc.OracleDriver");
	Connection db_con = DriverManager.getConnection(url, id, pw);
	
	String sql = "select * from JDBC_MEMBER_TABLE";
	// 쿼리 실행
	Statement stmt = db_con.createStatement();
	ResultSet rs = stmt.executeQuery(sql);
	
	// JSON 배열 생성
	JSONArray root = new JSONArray();
	// 데이터 개수만큼 반복
	while(rs.next()){
		// JSON 객체를 생성
		JSONObject member = new JSONObject();
		// 데이터를 담는다
		member.put("user_id", rs.getString("USER_ID"));
		member.put("user_pw", rs.getString("USER_PW"));
		member.put("user_name", rs.getString("USER_NAME"));
		// JSON 배열에 담는다.
		root.add(member);
	}
	db_con.close();
%>
<%=root.toJSONString() %>