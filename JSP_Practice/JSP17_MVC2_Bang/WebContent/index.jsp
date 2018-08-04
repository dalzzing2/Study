<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>로그인</title>
</head>
<body>
	<c:url var="login_pro" 
	       value="/login_pro.bang"/>
	<form action="${login_pro}" method="post">
		이름 : <input type="text" name="user_name"/><br/>
		<button type="submit">로그인</button>
	</form>
</body>
</html>








