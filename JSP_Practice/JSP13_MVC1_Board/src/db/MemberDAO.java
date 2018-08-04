package db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import bean.MemberBean;

public class MemberDAO {
	
	// 회원 정보를 데이터베이스 저장
	public static void add_user(MemberBean bean) throws Exception{
		// 데이터 베이스 접속
		// import java.sql
		Connection conn = DBConnector.getConnection();
		// 쿼리문 작성
		String sql = "insert into JDBC_MEMBER_TABLE "
				   + "(USER_ID, USER_NAME, USER_PW) "
				   + "values (?, ?, ?)";
		// PreparedStatement
		PreparedStatement pstmt 
						= conn.prepareStatement(sql);
		// ?에 값을 바인딩
		pstmt.setString(1, bean.getUser_id());
		pstmt.setString(2, bean.getUser_name());
		pstmt.setString(3, bean.getUser_pw());
		// 쿼리 실행
		pstmt.execute();
		
		// 데이터 베이스 접속 해제
		conn.close();
	}
	// 로그인 여부를 확인
	public static String check_login(MemberBean bean)
									throws Exception {
		Connection conn = DBConnector.getConnection();
		// 쿼리문
		String sql = "select user_pw from JDBC_MEMBER_TABLE "
				   + "where USER_ID=?";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		// ?에 바인딩한다.
		pstmt.setString(1, bean.getUser_id());
		// 쿼리 실행
		ResultSet rs = pstmt.executeQuery();
		// 가져온 데이터가 있는지 확인
		// 가져온 데이터가 없으면 아이디가 없는 아이디
		boolean flag = rs.next();
		// 만약에 없다면
		if(flag == false){
			conn.close();
			return "1";
		} else {
			// 비밀번호를 추출
			String pw = rs.getString("user_pw");
			// 비밀번호를 비교
			if(pw.equals(bean.getUser_pw()) == false){
				conn.close();
				return "2";
			} else {
				conn.close();
				return "3";
			}
		}
	}
	// 아이디를 받아 정보를 반환하는 메서드
	public static MemberBean getUserInfo(String user_id)
									throws Exception {
		Connection conn = DBConnector.getConnection();
		// 쿼리문
		String sql = "select * from JDBC_MEMBER_TABLE "
				   + "where USER_ID=?";
		PreparedStatement pstmt 
							= conn.prepareStatement(sql);
		// ?에 값을 바인딩한다.
		pstmt.setString(1, user_id);
		// 쿼리 실행
		ResultSet rs = pstmt.executeQuery();
		// 데이터를 가져온다.
		rs.next();
		String user_id2 = rs.getString("user_id");
		String user_pw = rs.getString("user_pw");
		String user_name = rs.getString("user_name");
		// 데이터를 담을 빈 객체 생성
		MemberBean bean = new MemberBean();
		bean.setUser_id(user_id2);
		bean.setUser_pw(user_pw);
		bean.setUser_name(user_name);
		
		conn.close();
		
		return bean;
	}
}





















