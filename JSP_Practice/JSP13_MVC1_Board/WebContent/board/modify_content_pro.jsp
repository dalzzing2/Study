<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%@ page import="db.*" %>
<%@ include file="../member/check_login.jsp" %>
<% request.setCharacterEncoding("utf-8"); %>
<%-- 파라미터 데이터를 받는다. --%>
<jsp:useBean id="board_bean" class="bean.BoardBean"/>
<jsp:setProperty property="*" name="board_bean"/>
<%
	String page_num_str = request.getParameter("page_num");
	int page_num = Integer.parseInt(page_num_str);
	// 데이터를 수정한다.
	BoardDAO.modify_content(board_bean);
	// read_content.jsp로 이동한다.
	String site = path 
	            + "/board/read_content.jsp?"
	            + "board_idx=" + board_bean.getBoard_idx()
	            + "&page_num=" + page_num;
	response.sendRedirect(site);
%>







