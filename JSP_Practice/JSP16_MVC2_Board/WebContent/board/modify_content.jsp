<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="db.*" %>
<%@ page import="bean.*" %>
<%@ include file="../member/check_login.jsp" %>
<%
	// 파라미터 데이터 추출
	String board_idx_str = request.getParameter("board_idx");
	String page_num_str = request.getParameter("page_num");
	int board_idx = Integer.parseInt(board_idx_str);
	int page_num = Integer.parseInt(page_num_str);
	
	BoardBean bean = BoardDAO.getBoardContent(board_idx);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>수정하기</title>
<script>
	function cancel(){
		location.href = "<%=path%>/board/read_content.jsp?"
				      + "board_idx=<%=board_idx%>"
				      + "&page_num=<%=page_num%>";
	}
</script>
</head>
<body>
	<form action="<%=path %>/board/modify_content_pro.jsp" method = "post">
		작성자 : <input type = "text" name ="user_name" value ="<%=bean.getUser_name()%>" readonly/><br/>
		제목 : <input type = "text" name ="board_subject" value ="<%=bean.getBoard_subject()%>"/><br/>
		내용 : <textarea name ="board_content"><%=bean.getBoard_content()%></textarea><br/>
		<input type ="hidden" name ="board_idx" value ="<%=board_idx %>"/>
		<input type ="hidden" name ="page_num" value ="<%=page_num %>"/>
		<button type ="submit">글 수정</button>
		<button type ="button" onclick ="cancel()">취소</button>
	</form>
</body>
</html>









