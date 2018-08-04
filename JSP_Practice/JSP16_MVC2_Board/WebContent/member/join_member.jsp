<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>회원 가입</title>
</head>
<body>
	<c:url var="join_pro" value="/join_pro.samsung"/>
	<form action="${join_pro}" method="post">
		이름 : <input type="text" name="user_name"/><br/>
		아이디 : <input type="text" name="user_id"/><br/>
		비밀번호 : <input type="password" name="user_pw"/>
		<br/>
		<button type="submit">회원가입</button>
	</form>
</body>
</html>










