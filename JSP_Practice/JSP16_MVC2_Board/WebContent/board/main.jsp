<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="bean.*" %>
<%@ page import="db.*" %>
<%@ page import="java.util.*" %>
<%-- 로그인 체크를 하는 jsp를 포함한다. --%>
<%@ include file="../member/check_login.jsp" %>
<%
	String page_num_str = request.getParameter("page_num");
	if(page_num_str == null){
		page_num_str = "1";
	}
	// 페이지 번호를 구한다.
	int page_num = Integer.parseInt(page_num_str);
	// 전체 페이지의 개수를 얻어온다.
	int page_cnt = BoardDAO.getPageCount();
	// 페이지 번호가 잘못 들어 왔을 경우에 대한 처리
	if(page_num < 1){
		page_num = 1;
	} else if(page_num > page_cnt){
		page_num = page_cnt;
	}
	
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>메인 페이지</title>
</head>
<body>
	<h1>
		${member_bean.user_name}님 환영합니다~~~
	</h1>
	<table border="1" width="800" style="text-align:center">
		<tr>
			<td width="10%">글 번호</td>
			<td>글 제목</td>
			<td width="20%">작성자</td>
			<td width="10%">조회수</td>
		</tr>
<%-- ArrayList의 객체 개수 만큼 반복 --%>
<c:forEach var="board_bean" items="${list}">
<c:url var="read_content" 
       value="/read_content.samsung">
   <c:param name="board_idx" 
            value="${board_bean.board_idx }"/>
   <c:param name="page_num"
            value="${page_num}"/>
</c:url>
		<tr>
			<td>${board_bean.board_idx}</td>
			<td>
				<a href="${read_content}">
					${board_bean.board_subject}
				</a>
			</td>
			<td>${board_bean.user_name}</td>
			<td>${board_bean.board_show}</td>
		</tr>
</c:forEach>	
	</table>
<c:forEach var="i" begin="1" end="${page_cnt}">
	<c:choose>
		<c:when test="${i == page_num}">
			[${i}]&nbsp;
		</c:when>
		<c:otherwise>
			<c:url var="main_pro" 
			       value="/main_pro.samsung">
			    <c:param name="page_num" value="${i}"/>
			</c:url>
			<a href="${main_pro}">${i}</a>&nbsp;
		</c:otherwise>
	</c:choose>
</c:forEach>
	<br/>
	<c:url var="write_board" 
	       value="/write_board.samsung"/>
	<a href="${write_board}">글쓰기</a>
</body>
</html>










