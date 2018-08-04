<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%@ page import="db.*" %>
<%@ include file="../member/check_login.jsp" %>
<%-- 파라미터 데이터를 받는다. --%>
<jsp:useBean id="reply_bean" class="bean.ReplyBean"/>
<jsp:setProperty property="*" name="reply_bean"/>
<%
	String page_num_str 
		= request.getParameter("page_num");
	int page_num = Integer.parseInt(page_num_str);
	// 삭제한다.
	BoardDAO.remove_reply(reply_bean.getReply_idx());
	// 페이지 이동
	String site = path + "/board/read_content.jsp"
	            + "?board_idx=" + reply_bean.getBoard_idx()
	            + "&page_num=" + page_num;
	response.sendRedirect(site);
%>








