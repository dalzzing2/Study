<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>데이터 집어 넣기</title>
</head>
<body>
	<%
		// JDBC 드라이버 로딩
		Class.forName("oracle.jdbc.OracleDriver");
		//Class.forName("oracle.jdbc.driver.OracleDriver");
		// 접속 정보
		String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
		String db_id = "scott";
		String db_pw = "1234";
		// 접속한다.
		Connection conn 
			= DriverManager.getConnection(db_url, db_id, db_pw);
		
		// 쿼리문 작성
		StringBuffer buf = new StringBuffer();
		buf.append("insert into JDBC_TEST_TABLE ")
		   .append("(INT_DATA, STR_DATA) ")
		   .append("values (?, ?)");
		String sql = buf.toString();
		// PreparedStatement를 생성한다.
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		// ?에 값을 바인딩한다.
		pstmt.setInt(1, 100);
		pstmt.setString(2, "안녕하세요");
		// 쿼리 실행
		pstmt.execute();
		
		// ?에 값을 바인딩한다.
		pstmt.setInt(1, 200);
		pstmt.setString(2, "반갑습니다");
		// 쿼리 실행
		pstmt.execute();
		
		// 연결을 해제한다.
		conn.close();
	%>
	저장완료
</body>
</html>
















