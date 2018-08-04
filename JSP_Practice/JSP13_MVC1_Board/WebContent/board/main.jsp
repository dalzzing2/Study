<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
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
	// 현재 페이지의 글 데이터를 가져온다.
	ArrayList<BoardBean> list = BoardDAO.getBoardAlldata(page_num);
	
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>메인 페이지</title>
</head>
<body>
	<h1>
		<jsp:getProperty property="user_name" 
			name="member_bean"/>님 환영합니다~~~
	</h1>
	<table border="1" width="800" style="text-align:center">
		<tr>
			<td width="10%">글 번호</td>
			<td>글 제목</td>
			<td width="20%">작성자</td>
			<td width="10%">조회수</td>
		</tr>
<%-- ArrayList의 객체 개수 만큼 반복 --%>
<%	for(int i = 0 ; i < list.size() ; i++){ %>
<%-- i 번째 bean 객체 추출 --%>
<%		BoardBean board_bean = list.get(i); %>		
		<tr>
			<td><%=board_bean.getBoard_idx()%></td>
			<td>
				<a href="<%=path%>/board/read_content.jsp?board_idx=<%=board_bean.getBoard_idx()%>&page_num=<%=page_num%>">
					<%=board_bean.getBoard_subject()%>
				</a>
			</td>
			<td><%=board_bean.getUser_name()%></td>
			<td><%=board_bean.getBoard_show()%></td>
		</tr>
<%  }  %>		
	</table>
<% for(int i = 0 ; i < page_cnt ; i++){ %>
<%	if(i + 1 == page_num){	%>
		[<%=i+1%>]&nbsp;
<%	} else {  %>
		<a href="<%=path%>/board/main.jsp?page_num=<%= i + 1%>"><%= i + 1 %></a>&nbsp;
<%  } %>	
<% } %>
	<br/>
	<a href="<%=path%>/board/write_board.jsp">글쓰기</a>
</body>
</html>










