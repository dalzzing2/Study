<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>가입 완료</title>
</head>
<body>
	가입이 완료되었습니다<br/>
	<c:url var="index" value="/index.jsp"/>
	<a href="${index}">로그인하기</a>
</body>
</html>







