<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>방명록</title>
</head>
<body>
	<%-- 세션에 있는 사용자 이름을 출력 --%>
	<h1>${sessionScope.user_name}님 환영합니다</h1>	
	<c:url var="add_bang" value="add.bang"/>
	<form action="${add_bang}" method="post">
		<textarea name="bang_content"></textarea><br/>
		<button type="submit">작성하기</button>		
	</form>
	-----------------------------------<br/>
	<c:forEach var="bang_bean"
				items="${requestScope.list}">
		${bang_bean.bang_content}<br/>
		작성자 : ${bang_bean.bang_name}<br/>
	------------------------------------<br/>
	</c:forEach>
</body>
</html>











