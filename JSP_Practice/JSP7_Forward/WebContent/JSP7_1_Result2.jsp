<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>forward 메서드로 이동한 페이지</title>
</head>
<body>
	<%
		// 데이터를 추출한다.
		String data1 = (String)request.getAttribute("data1");
		int data2 = (Integer)request.getAttribute("data2");
	%>
	data1 : <%=data1%><br/>
	data2 : <%=data2%><br/>
</body>
</html>











