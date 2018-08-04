package db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import bean.BangBean;

public class BangDAO {
	// 방명록 데이터를 데이터 베이스에 저장한다.
	public static void add_bang(BangBean bean)
							throws Exception {
		// import java.sql
		Connection db = DBConnector.getConnection();
		// 쿼리문 작성
		String sql = "insert into JDBC_BANG_TABLE "
				   + "(BANG_IDX, BANG_NAME, "
				   + "BANG_CONTENT) values "
				   + "(JDBC_BANG_SEQ.nextval, ?, ?)";
		PreparedStatement pstmt
							= db.prepareStatement(sql);
		pstmt.setString(1, bean.getBang_name());
		pstmt.setString(2, bean.getBang_content());
		
		pstmt.execute();
		
		db.close();
	}
	// 모든 데이터를 가져온다.
	public static ArrayList<BangBean> get_bang()
									throws Exception {
		Connection conn = DBConnector.getConnection();
		
		String sql = "select * from JDBC_BANG_TABLE "
				   + "order by BANG_IDX desc";
		// 쿼리 실행
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery(sql);
		// 데이터를 추출
		ArrayList<BangBean> list
						= new ArrayList<BangBean>();
		while(rs.next()){
			int bang_idx = rs.getInt("BANG_IDX");
			String bang_name = rs.getString("BANG_NAME");
			String bang_content
						= rs.getString("BANG_CONTENT");
			
			BangBean bean = new BangBean();
			bean.setBang_idx(bang_idx);
			bean.setBang_content(bang_content);
			bean.setBang_name(bang_name);
			
			list.add(bean);
		}
		
		conn.close();
		
		return list;
	}
}









