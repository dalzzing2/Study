<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="db.*" %>
<%@ page import="bean.*" %>
<%
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
%>
<%-- 로그인 확인 페이지를 포함한다. --%>
<%@ include file="../member/check_login.jsp" %>
<%-- 파라미터로 넘어오는 값을 받는다. --%>
<jsp:useBean id="board_bean" class="bean.BoardBean"/>
<jsp:setProperty property="*" name="board_bean"/>
<%
	// 작성자 아이디를 board_bean에 넣어준다.
	board_bean.setUser_id(member_bean.getUser_id());
	// 데이터 베이스에 저장
	int max_idx = BoardDAO.add_board(board_bean);
	// 작성한 글을 보기위한 페이지로 이동한다.
	String site = path + 
		"/board/read_content.jsp?board_idx=" + max_idx;
	response.sendRedirect(site);	
%>









