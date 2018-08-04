<%@ page contentType="text/plain; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="java.util.*" %>
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
<%-- csv 데이터를 구성 --%>
<% 
	StringBuffer buf2 = new StringBuffer();

	for(HashMap<String, String> map : list){
		String user_id = map.get("user_id");
		String user_pw = map.get("user_pw");
		String user_name = map.get("user_name");
		
		buf2.append(user_id.trim());
		buf2.append(",");
		buf2.append(user_pw.trim());
		buf2.append(",");
		buf2.append(user_name.trim());
		buf2.append(",");
	}
%>
<%= buf2.toString() %>










