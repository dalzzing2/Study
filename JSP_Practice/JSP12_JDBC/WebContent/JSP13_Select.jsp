<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>데이터 베이스에서 데이터 가져오기</title>
</head>
<body>
	<%
		Class.forName("oracle.jdbc.OracleDriver");
		String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
		String db_id = "scott";
		String db_pw = "1234";
		// 데이터 베이스 접속
		Connection conn
			= DriverManager.getConnection(db_url, db_id, db_pw);
		// 쿼리문
		String sql = "select * from JDBC_TEST_TABLE";
		// Statement 생성
		Statement stmt = conn.createStatement();
		// 쿼리 실행
		ResultSet rs = stmt.executeQuery(sql);
		// ResultSet이 로우에 접근할 수 있도록 next메서드를
		// 반드시 호출해야 한다.
		// next 메서드는 로우 접근에 성공하면 true,
		// 실패하면 false를 반환한다.
		while(rs.next()){
			// 컬럼의 이름을 통해 가지고 온다.
			// int int_data = rs.getInt("INT_DATA");
			// String str_data = rs.getString("STR_DATA");
			
			// 인덱스 번호를 통해 가지고 온다.
			int int_data = rs.getInt(1);
			String str_data = rs.getString(2);
			
			out.print("int : " + int_data + "<br/>");
			out.print("str : " + str_data + "<br/>");
		}
		// 접속 해제
		conn.close();
	%>
</body>
</html>










