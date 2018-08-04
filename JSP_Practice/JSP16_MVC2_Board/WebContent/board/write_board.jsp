<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>글 작성하기</title>
<c:url var="main_pro" value="/main_pro.samsung"/>
<script>
	function cancel_write(){
		// main.jsp로 이동한다.
		location.href="${main_pro}";
	}
</script>
</head>
<body>
	<c:url var="write_board_pro"
	       value="/write_board_pro.samsung"/>
	<form action="${write_board_pro}" method="post">
	      작성자 : ${member_bean.user_name}<br/>
	      제목 : <input type="text" name="board_subject"/>
	      <br/>
	      내용 : <textarea name="board_content"></textarea>
	      <br/>
	      <button type="submit">작성완료</button>
	      <button type="button" onclick="cancel_write()">취소</button>
	</form>
</body>
</html>











