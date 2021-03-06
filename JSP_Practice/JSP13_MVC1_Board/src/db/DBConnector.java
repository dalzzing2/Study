package db;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnector {
	private static final String driver_name
		= "oracle.jdbc.OracleDriver";
	private static final String db_url
		= "jdbc:oracle:thin:@localhost:1521:orcl";
	private static final String db_id
		= "scott";
	private static final String db_pw
		= "1234";
	
	// 데이터 베이스 접속하는 메서드
	// import java.sql
	public static Connection getConnection() throws Exception{
		// JDBC 드라이버 로딩
		Class.forName(driver_name);
		// 데이터 접속
		Connection conn 
			= DriverManager.getConnection(db_url, db_id, db_pw);
		// 반환한다.
		return conn;
	}
	
}




















