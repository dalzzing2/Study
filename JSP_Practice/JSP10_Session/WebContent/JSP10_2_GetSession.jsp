<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>세션 데이터 확인</title>
</head>
<body>
	<%-- 세션에 데이터를 가져온다. --%>
	<%
		String data1 = (String)session.getAttribute("data1");
		Integer data2 = (Integer)session.getAttribute("data2");
	%>
	data1 : <%= data1 %><br/>
	data2 : <%= data2 %><br/>
	<%-- 애플리케이션에서 데이터를 가지고 온다. --%>
	<%
		String data3 
			= (String)application.getAttribute("data3");
		Integer data4
			= (Integer)application.getAttribute("data4");
	%>
	data3 : <%= data3 %><br/>
	data4 : <%= data4 %><br/>
</body>
</html>










