<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Session과 Application에 데이터 저장</title>
</head>
<body>
	<%
		// Application에 데이터 저장
		application.setAttribute("data1", 100);
		application.setAttribute("data2", "안녕하세요");
		// Session에 데이터 저장
		session.setAttribute("value1", 500);
		session.setAttribute("value2", "반갑습니다");
	%>
	<a href="JSP5_4_Result.jsp">결과 확인하기</a>
</body>
</html>









