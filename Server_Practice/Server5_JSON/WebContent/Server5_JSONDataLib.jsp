<%@ page contentType="text/json; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="org.json.simple.*" %>
<%@ page import="org.json.simple.parser.*" %>
<%@ page trimDirectiveWhitespaces="true" %>
<%
Class.forName("oracle.jdbc.OracleDriver");
String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
String db_id = "scott";
String db_pw = "1234";
//데이터 베이스 접속
Connection conn
	= DriverManager.getConnection(db_url, db_id, db_pw);
// 쿼리문
String sql = "select * from jdbc_board_table";
Statement stmt = conn.createStatement();
ResultSet rs = stmt.executeQuery(sql);
// 배열 생성
JSONArray root = new JSONArray();
// 데이터의 개수만큼 반복
while(rs.next()){
	// 객체 생성
	JSONObject obj = new JSONObject();
	// 객체에 데이터를 넣어준다.
	obj.put("board_idx", rs.getInt("board_idx"));
	obj.put("board_subject", rs.getString("board_subject"));
	obj.put("board_content", rs.getString("board_content"));
	obj.put("board_show", rs.getInt("board_show"));
	obj.put("user_id", rs.getString("user_id"));
	// 배열에 추가
	root.add(obj);
}
%>
<%= root.toJSONString() %>