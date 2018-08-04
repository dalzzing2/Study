<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
 		   uri="http://java.sun.com/jsp/jstl/core" %>
<%-- board/read_content.jsp --%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>글 내용 보기</title>
</head>
<body>
	작성자 : <input type="text" value="${bean.user_name}" 
	                readonly/><br/>
	제목 : <input type="text" value="${bean.board_subject}"
	                readonly/><br/>
	내용 : <textarea readonly>${bean.board_content}</textarea>
	<br/>
<%-- 작성자 아이디와 로그인한 사람의 아이디가 같을
	경우에만 링크가 나오도록 한다. 
 --%>
<c:if test="${bean.user_id eq member_bean.user_id}">
	<c:url var="modify_content"
	       value="/modify_content_pro.samsung">
	   <c:param name="board_idx" value="${bean.board_idx}"/>
	   <c:param name="page_num" value="${page_num}"/>
	</c:url>
	<c:url var="delete_content"
	       value="/delete_content_pro.samsung">
	   <c:param name="board_idx" value="${bean.board_idx}"/>
	   <c:param name="page_num" value="${page_num}"/>
	</c:url>
	<a href="${modify_content}">수정하기</a>
	<a href="${delete_content}">삭제하기</a>
</c:if>
	<c:url var="main_pro"
		   value="/main_pro.samsung">
		<c:param name="page_num" value="${page_num}"/>
	</c:url>
	<a href="${main_pro}">리스트</a>
	<br/>
	<br/>
	<br/>
	--------------------------------<br/>
<%-- 댓글의 개수만큼 반복한다. --%>
<c:forEach var="reply_bean" items="${reply_list}">
	${reply_bean.reply_content}<br/>
	<c:if 
	  test="${member_bean.user_id eq reply_bean.user_id}">
	  <c:url var="remove_reply"
	         value="/remove_reply.samsung">
	     <c:param name="reply_idx" 
	              value="${reply_bean.reply_idx}"/>
		 <c:param name="board_idx"
		          value="${reply_bean.board_idx}"/>
		 <c:param name="page_num"
		          value="${page_num}"/>
	  </c:url>
	  <a href="${del_site}">삭제하기</a>
	<br/>
	</c:if>
	--------------------------------<br/>
</c:forEach>
	<c:url var="add_reply" value="/add_reply.samsung"/>
	<form action="${add_reply}" method="post">
	      <textarea name=reply_content></textarea><br/>
	      <input type="hidden" name="board_idx"
	             value="${bean.board_idx}"/>
		  <input type="hidden" name="page_num"
		         value="${page_num}"/>
	      <button type="submit">댓글달기</button>
	</form>
	
</body>
</html>








