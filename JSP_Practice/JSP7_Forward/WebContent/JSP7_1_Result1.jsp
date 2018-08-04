<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 데이터 추출
	String data1 = request.getParameter("data1");
	String data2 = request.getParameter("data2");
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>sendRedirect로 이동된 페이지</title>
</head>
<body>
	data1 : <%=data1%><br/>
	data2 : <%=data2%><br/>
</body>
</html>







