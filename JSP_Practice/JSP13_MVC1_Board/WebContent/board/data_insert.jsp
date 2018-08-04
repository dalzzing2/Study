<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="db.*" %>
<%
	Connection conn = DBConnector.getConnection();

	String sql = "insert into JDBC_BOARD_TABLE "
		   + "(BOARD_IDX, BOARD_SUBJECT, "
		   + "BOARD_CONTENT, BOARD_SHOW, "
		   + "USER_ID) values "
		   + "(JDBC_BOARD_SEQ.nextval, ?, ?, 0, ?)";
	
	PreparedStatement pstmt
						= conn.prepareStatement(sql);
	for(int i = 0 ; i < 153 ; i++){
		pstmt.setString(1, "제목입니다" + i);
		pstmt.setString(2, "내용입니다" + i);
		if(i % 2 == 0){
			pstmt.setString(3, "aaa");
		} else {
			pstmt.setString(3, "abc");
		}
		pstmt.execute();
	}

	conn.close();
%>
완료되었습니다







