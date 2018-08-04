<%@ page contentType="text/xml; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page trimDirectiveWhitespaces="true" %>
<%-- 주석 테스트 --%>
<?xml version="1.0" encoding="utf-8"?>
<%
Class.forName("oracle.jdbc.OracleDriver");
String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
String db_id = "scott";
String db_pw = "1234";
//데이터 베이스 접속
Connection conn
	= DriverManager.getConnection(db_url, db_id, db_pw);

String sql = "select * from JDBC_MEMBER_TABLE";
// 쿼리 실행
Statement stmt = conn.createStatement();
ResultSet rs = stmt.executeQuery(sql);
// 데이터를 담아 놓을 컬렉션 생성
ArrayList<HashMap<String, String>> list
	= new ArrayList<HashMap<String, String>>();

// 데이터를 추출해서 담아준다.
while(rs.next()){
	// 데이터를 추출한다.
	String user_id = rs.getString("user_id");
	String user_name = rs.getString("user_name");
	String user_pw = rs.getString("user_pw");
	// 데이터를 담는다.
	HashMap<String, String> map
					= new HashMap<String, String>();
	map.put("user_id", user_id);
	map.put("user_name", user_name);
	map.put("user_pw", user_pw);
	
	list.add(map);
}

conn.close();
%>
<% try{ %>
<root>
	<status>OK</status>
<% for(HashMap<String, String> map : list){ %>
	<user_info>
		<user_id><%= map.get("user_id") %></user_id>
		<user_pw><%= map.get("user_pw") %></user_pw>
		<user_name><%= map.get("user_name")%></user_name>
	</user_info>
<% } %>
</root>
<% } catch(Exception e){ %>
<root>
	<status>FAIL</status>
</root>
<% } %>









