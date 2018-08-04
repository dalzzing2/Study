<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="db.*" %>
<%
	// 파라미터 데이터 추출
	String board_idx_str = request.getParameter("board_idx");
	String page_num_str = request.getParameter("page_num");
	int board_idx = Integer.parseInt(board_idx_str);
	int page_num = Integer.parseInt(page_num_str);
	// 글을 삭제한다.
	BoardDAO.delete_content(board_idx);
	// main.jsp로 이동한다.
	String path = request.getContextPath(); 
	String site = path + "/board/main.jsp?page_num="
			    + page_num;
	response.sendRedirect(site);
%>





