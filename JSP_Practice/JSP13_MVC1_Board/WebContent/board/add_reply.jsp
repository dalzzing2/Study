<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="db.*" %>
<%@ page import="bean.*" %>
<%@ include file="../member/check_login.jsp" %>
<%
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
%>
<%-- 파라미터 데이터를 받는다 --%>
<jsp:useBean id="reply_bean" class="bean.ReplyBean"/>
<jsp:setProperty property="*" name="reply_bean"/>
<%
	String page_num_str 
	                = request.getParameter("page_num");
	int page_num = Integer.parseInt(page_num_str);
	
	// 세션의 사용자 아이디를 셋팅한다.
	reply_bean.setUser_id(member_bean.getUser_id());
	// 댓글 정보를 저장한다.
	BoardDAO.add_reply(reply_bean);
	// 글 보는 페이지로 이동
	
	String site = path + "/board/read_content.jsp"
	            + "?board_idx=" + reply_bean.getBoard_idx()
	            + "&page_num=" + page_num;
	response.sendRedirect(site);
%>











