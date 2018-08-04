<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ include file="../member/check_login.jsp" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>글 작성하기</title>
<script>
	function cancel_write(){
		// main.jsp로 이동한다.
		location.href="<%=path%>/board/main.jsp";
	}
</script>
</head>
<body>
	<form action="<%=path%>/board/write_board_pro.jsp"
	      method="post">
	      작성자 : <%=member_bean.getUser_name()%><br/>
	      제목 : <input type="text" name="board_subject"/>
	      <br/>
	      내용 : <textarea name="board_content"></textarea>
	      <br/>
	      <button type="submit">작성완료</button>
	      <button type="button" onclick="cancel_write()">취소</button>
	</form>
</body>
</html>











