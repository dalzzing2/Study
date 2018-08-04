<%@ page contentType="text/json; charset=utf-8" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="org.json.simple.*" %>
<%@ page import="org.json.simple.parser.*" %>
<%
	// 파라미터 데이터 추출
	String idx_str = request.getParameter("idx");
	int idx = Integer.parseInt(idx_str);
	
	String url = "jdbc:oracle:thin:@localhost:1521:orcl";
	String id = "scott";
	String pw = "1234";
	
	Class.forName("oracle.jdbc.OracleDriver");
	Connection db_con = DriverManager.getConnection(url, id, pw);
	
	String sql = "select * from JDBC_CHAT_TABLE "
			+ "where CHAt_IDX > ? "
			+ "order by CHAT_IDX desc";
	
	PreparedStatement pstmt = db_con.prepareStatement(sql);
	pstmt.setInt(1, idx);
	
	ResultSet rs = pstmt.executeQuery();
	
	// JSON 배열 생성
	JSONArray root = new JSONArray();
	// 데이터의 갯수만큼 반복
	while(rs.next()){
		JSONObject obj = new JSONObject();
		// 데이터 셋팅
		obj.put("chat_idx", rs.getInt("CHAT_IDX"));
		obj.put("chat_user", rs.getString("CHAT_USER"));
		obj.put("chat_content", rs.getString("CHAT_CONTENT"));
		
		root.add(obj);
	}
	db_con.close();
%>
<%=root.toJSONString()%>