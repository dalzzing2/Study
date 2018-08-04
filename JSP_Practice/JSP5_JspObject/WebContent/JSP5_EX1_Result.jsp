<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>계산기 결과 페이지(세션)</title>
</head>
<body>
	<%
		// 세션으로 부터 데이터를 추출한다.
		int result 
			= (Integer)session.getAttribute("result");
	%>
	결과 : <%=result%>
</body>
</html>










