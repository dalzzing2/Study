package db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import bean.BoardBean;
import bean.ReplyBean;

public class BoardDAO {
	
	public static synchronized int add_board(BoardBean bean)
								throws Exception {
		Connection conn = DBConnector.getConnection();
		// 쿼리문
		String sql = "insert into JDBC_BOARD_TABLE "
				   + "(BOARD_IDX, BOARD_SUBJECT, "
				   + "BOARD_CONTENT, BOARD_SHOW, "
				   + "USER_ID) values "
				   + "(JDBC_BOARD_SEQ.nextval, ?, ?, 0, ?)";
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		// ?에 값을 셋팅
		pstmt.setString(1, bean.getBoard_subject());
		pstmt.setString(2, bean.getBoard_content());
		pstmt.setString(3, bean.getUser_id());
		// 쿼리를 실행
		pstmt.execute();
		// 작성한 글의 번호를 가져온다.
		String sql2 = "select max(BOARD_IDX) "
				    + "from JDBC_BOARD_TABLE";
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery(sql2);
		rs.next();
		int max_idx = rs.getInt(1);
		
		conn.close();
		
		return max_idx;
	}
	// 글 번호를 받아서 해당 글의 데이터를 반환하는 메서드
	public static BoardBean getBoardContent(int board_idx)
									throws Exception {
		Connection conn = DBConnector.getConnection();
		// 쿼리문
		String sql = "SELECT b.USER_NAME, a.BOARD_SUBJECT, "
	               + "a.BOARD_CONTENT, "
	               + "a.BOARD_SHOW, "
	               + "a.USER_ID "
	               + "FROM JDBC_BOARD_TABLE a, "
	               + "JDBC_MEMBER_TABLE b "
	               + "WHERE a.USER_ID=b.USER_ID "
	               + "and BOARD_IDX=?";
	      
		PreparedStatement pstmt
							= conn.prepareStatement(sql);
		pstmt.setInt(1, board_idx);
		// 쿼리 실행
		ResultSet rs = pstmt.executeQuery();
		rs.next();
		// 데이터를 가져온다.
		String board_subject = rs.getString("BOARD_SUBJECT");
		String board_content = rs.getString("BOARD_CONTENT");
		int board_show = rs.getInt("BOARD_SHOW");
		String user_id = rs.getString("USER_ID");
		String user_name = rs.getString("USER_NAME");
		
//		System.out.println(board_subject);
//		System.out.println(board_content);
//		System.out.println(board_show);
//		System.out.println(user_id);
//		System.out.println(user_name);
		// 데이터를 담을 빈을 생성한다.
		BoardBean bean = new BoardBean();
		bean.setUser_id(user_id);
		bean.setBoard_idx(board_idx);
		bean.setBoard_subject(board_subject);
		bean.setBoard_content(board_content);
		bean.setBoard_show(board_show);
		bean.setUser_name(user_name);
		
		conn.close();
		
		return bean;
	}
	// 데이터 베이스의 모든 글을 가져오는 메서드
	public static ArrayList<BoardBean> getBoardAlldata(int page_num) 
							throws Exception {
		Connection conn = DBConnector.getConnection();
		
		String sql = "select * from "
				   + "(select rownum as rnum, t1.* from "
				   + "(select a.BOARD_IDX, a.BOARD_SUBJECT, "
				   + "b.USER_NAME, a.BOARD_SHOW "
				   + "from JDBC_BOARD_TABLE a, "
				   + "JDBC_MEMBER_TABLE b "
				   + "where a.USER_ID=b.USER_ID "
				   + "order by a.BOARD_IDX desc) t1) t2 "
				   + "where rnum >= ? and rnum <= ?";
		
		// 최대 값과 최소 값을 구한다.
		int con_min = 1 + ((page_num - 1) * 10);
		int con_max = 10 + ((page_num - 1) * 10);
		
		PreparedStatement pstmt = conn.prepareStatement(sql);
		pstmt.setInt(1, con_min);
		pstmt.setInt(2, con_max);
		// 쿼리 실행
		ResultSet rs = pstmt.executeQuery();
		// 데이터를 담아 놓을 ArrayList
		ArrayList<BoardBean> list = new ArrayList<BoardBean>();
		// 로우의 끝까지 반복한다.
		while(rs.next()){
			int board_idx = rs.getInt("BOARD_IDX");
			String board_subject = rs.getString("BOARD_SUBJECT");
			String user_name = rs.getString("USER_NAME");
			int board_show = rs.getInt("BOARD_SHOW");
			// 데이터를 담을 빈 객체 생성
			BoardBean bean = new BoardBean();
			bean.setBoard_idx(board_idx);
			bean.setBoard_subject(board_subject);
			bean.setUser_name(user_name);
			bean.setBoard_show(board_show);
			// 빈 객체를 ArrayList에 담는다.
			list.add(bean);
			
//			System.out.println(board_idx);
//			System.out.println(board_subject);
//			System.out.println(user_name);
//			System.out.println(board_show);
		}
		 
		
		conn.close();
		
		return list;	
	}
	// 페이지 수를 구하는 메서드
	public static int getPageCount() throws Exception{
		Connection conn = DBConnector.getConnection();
		
		// 쿼리문 
		String sql = "select count(*) from "
				   + "JDBC_BOARD_TABLE";
		
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery(sql);
		rs.next();
		// 전체 글의 개수를 가져온다.
		int cnt = rs.getInt(1);
		// 페이지 수 계산
		int page_cnt = cnt / 10;
		if(cnt % 10 > 0){
			page_cnt++;
		}
		
		conn.close();
		
		return page_cnt;
	}
	// 글을 삭제하는 메서드
	public static void delete_content(int board_idx)
									throws Exception{
		Connection conn = DBConnector.getConnection();
		
		// 쿼리문
		String sql = "delete from JDBC_BOARD_TABLE "
				   + "where board_idx=?";
		PreparedStatement pstmt 
						= conn.prepareStatement(sql);
		pstmt.setInt(1, board_idx);
		
		pstmt.execute();
		
		conn.close();
	}
	// 글을 수정하는 메서드
	public static void modify_content(BoardBean bean)
						throws Exception {
		Connection conn = DBConnector.getConnection();
		
		String sql = "update JDBC_BOARD_TABLE "
				   + "set BOARD_SUBJECT=?, "
				   + "BOARD_CONTENT=? "
				   + "where BOARD_IDX=?";
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		pstmt.setString(1, bean.getBoard_subject());
		pstmt.setString(2, bean.getBoard_content());
		pstmt.setInt(3, bean.getBoard_idx());
		
		pstmt.execute();
		
		conn.close();
	}
	
	// 조회수를 증가시키는 메서드
	public static void update_board_show(int board_idx)
								throws Exception {
		Connection conn = DBConnector.getConnection();
		
		String sql = "update jdbc_board_table "
				   + "set board_show=( "
				   + "(select board_show "
				   + "from jdbc_board_table "
				   + "where board_idx=?)+1) "
				   + "where board_idx=?";
		PreparedStatement pstmt = 
							conn.prepareStatement(sql);
		pstmt.setInt(1, board_idx);
		pstmt.setInt(2, board_idx);
		
		pstmt.execute();
		
		conn.close();
	}
	// 댓글 추가하는 메서드
	public static void add_reply(ReplyBean bean)
									throws Exception{
		Connection conn = DBConnector.getConnection();
		
		String sql = "insert into JDBC_REPLY_TABLE "
				   + "(REPLY_IDX, REPLY_CONTENT, "
				   + "USER_ID, BOARD_IDX) values "
				   + "(JDBC_REPLY_SEQ.nextval, ?, ?, ?)";
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		pstmt.setString(1, bean.getReply_content());
		pstmt.setString(2, bean.getUser_id());
		pstmt.setInt(3, bean.getBoard_idx());
		
		pstmt.execute();
		
		conn.close();
	}
	// 댓글 리스트를 가져오는 메서드
	public static ArrayList<ReplyBean> 
					getReplyList(int board_idx)
								throws Exception{
		Connection conn = DBConnector.getConnection();
		
		String sql = "select * from JDBC_REPLY_TABLE "
				   + "where BOARD_IDX=? "
				   + "order by REPLY_IDX";
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		pstmt.setInt(1, board_idx);
		
		ResultSet rs = pstmt.executeQuery();
		// ArrayList 생성
		ArrayList<ReplyBean> list
						= new ArrayList<ReplyBean>();
		// 로우의 끝까지 반복한다.
		while(rs.next()){
			// 데이터를 추출한다
			int reply_idx = rs.getInt("REPLY_IDX");
			String reply_content = rs.getString("REPLY_CONTENT");
			String user_id = rs.getString("USER_ID");
			int board_idx2 = rs.getInt("BOARD_IDX");
			// 빈 객체 담는다.
			ReplyBean bean = new ReplyBean();
			bean.setReply_idx(reply_idx);
			bean.setReply_content(reply_content);
			bean.setUser_id(user_id);
			bean.setBoard_idx(board_idx2);
			// 리스트에 담는다.
			list.add(bean);
		}
		
		conn.close();
		
		return list;
	}
	// 댓글을 삭제하는 메서드
	public static void remove_reply(int reply_idx)
									throws Exception {
		Connection conn = DBConnector.getConnection();
		
		String sql = "delete from JDBC_REPLY_TABLE "
				   + "where REPLY_IDX=?";
		
		PreparedStatement pstmt
						= conn.prepareStatement(sql);
		pstmt.setInt(1, reply_idx);
		
		pstmt.execute();
		
		conn.close();
	}
}























