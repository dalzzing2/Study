<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>로그인 페이지</title>
</head>
<body>
	<c:choose>
		<c:when test="${param.login_result eq '1'}">
	<font color="red">등록되지 않은 아이디 입니다</font>
	<br/>
		</c:when>
		<c:when test="${param.login_result eq '2'}">
	<font color="red">비밀번호가 잘못되었습니다</font>
	<br/>
		</c:when>
	</c:choose>

	<c:url var="login_pro" value="/login_pro.samsung"/>
	<form action="${login_pro}" method="post">
		아이디 : <input type="text" name="user_id"/><br/>
		비밀번호 : <input type="password"
		                  name="user_pw"/><br/>
		<button type="submit">로그인</button>
	</form>
	<%-- 회원 가입 페이지의 주소를 구한다. --%>
	<c:url var="join_member" value="/join_member.samsung"/>
	<a href="${join_member}">회원 가입</a>
</body>
</html>









