<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c"
 		   uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSTL로 파라미터 사용하기</title>
</head>
<body>
	<%
		String path = request.getContextPath();
		String site = path + "/test.jsp";
	%>
	<%= site %><br/>
	<c:url var="test_path" value="/test.jsp"/>
	${test_path}<br/>
	<%-- 접속할 페이지의 주소를 구한다. --%>
	<c:url var="result_jsp" value="JSP15_3_Result.jsp"/>
	<form action="${result_jsp}" method="post">
		<input type="text" name="p1"/><br/>
		<input type="text" name="p2"/><br/>
		<button type="submit">확인</button>
	</form>
	<%-- get 방식의 주소 생성 --%>
	<c:url var="result_jsp2" value="JSP15_3_Result.jsp">
		<c:param name="p1" value="감사합니다"/>
		<c:param name="p2" value="방가방가"/>
	</c:url>
	${result_jsp2}<br/>
	<a href="${result_jsp2}">Get 테스트</a>
</body>
</html>











