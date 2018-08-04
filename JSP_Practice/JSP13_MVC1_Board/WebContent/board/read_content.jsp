<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="db.*" %>
<%@ page import="bean.*" %>
<%@ page import="java.util.*" %>
<%-- board/read_content.jsp --%>
<%@ include file="../member/check_login.jsp" %>
<%
	// 파라미터 데이터 추출
	String board_idx_str = request.getParameter("board_idx");
	String page_num_str = request.getParameter("page_num");
	if(page_num_str == null){
		page_num_str = "1";
	}
	int page_num = Integer.parseInt(page_num_str);
	
	
	int board_idx = Integer.parseInt(board_idx_str);
	// 조회수를 증가시킨다.
	BoardDAO.update_board_show(board_idx);
	// 게시글 데이터를 가져온다.
	BoardBean bean = BoardDAO.getBoardContent(board_idx);
	// 댓글 정보를 가져온다.
	ArrayList<ReplyBean> reply_list
					= BoardDAO.getReplyList(board_idx);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>글 내용 보기</title>
</head>
<body>
	작성자 : <input type="text" value="<%=bean.getUser_name()%>" 
	                readonly/><br/>
	제목 : <input type="text" value="<%=bean.getBoard_subject()%>"
	                readonly/><br/>
	내용 : <textarea readonly><%=bean.getBoard_content()%></textarea>
	<br/>
<%-- 작성자 아이디와 로그인한 사람의 아이디가 같을
	경우에만 링크가 나오도록 한다. 
 --%>
<% 
	String id1 = bean.getUser_id();
	String id2 = member_bean.getUser_id();
	if(id1.equals(id2)){ %>
	<a href="<%=path%>/board/modify_content.jsp?board_idx=<%=board_idx%>&page_num=<%=page_num%>">수정하기</a>
	<a href="<%=path%>/board/delete_content.jsp?board_idx=<%=board_idx%>&page_num=<%=page_num%>">삭제하기</a>
<% } %>
	<a href="<%=path%>/board/main.jsp?page_num=<%=page_num%>">리스트</a>
	<br/>
	<br/>
	<br/>
	--------------------------------<br/>
<%-- 댓글의 개수만큼 반복한다. --%>
<% for(ReplyBean reply_bean : reply_list){ %>
	<%=reply_bean.getReply_content()%><br/>
	<%
		String login_id = member_bean.getUser_id();
		String reply_id = reply_bean.getUser_id();
		if(login_id.equals(reply_id)){
			String del_site = path + "/board/remove_reply.jsp"
					        + "?reply_idx=" + reply_bean.getReply_idx()
					        + "&board_idx=" + reply_bean.getBoard_idx()
					        + "&page_num=" + page_num;
	%>
	<a href="<%=del_site%>">삭제하기</a>
	<br/>
	<%  } %>
	--------------------------------<br/>
<%  }  %>
	
	<form action="<%=path%>/board/add_reply.jsp"
	      method="post">
	      <textarea name=reply_content></textarea><br/>
	      <input type="hidden" name="board_idx"
	             value="<%=board_idx%>"/>
		  <input type="hidden" name="page_num"
		         value="<%=page_num%>"/>
	      <button type="submit">댓글달기</button>
	</form>
	
</body>
</html>








