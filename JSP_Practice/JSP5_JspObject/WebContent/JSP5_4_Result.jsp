<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>session, application의 데이터 가져오기</title>
</head>
<body>
	<%
		// application에 저장된 데이터를 가져온다.

		Integer data1 
			= (Integer)application.getAttribute("data1");
		String data2
			= (String)application.getAttribute("data2");
		// session에 저장된 데이터를 가져온다.
		Integer value1 
			= (Integer)session.getAttribute("value1");
		String value2
			= (String)session.getAttribute("value2");
	%>
	
	data1 : <%=data1%><br/>
	data2 : <%=data2%><br/>
	value1 : <%=value1%><br/>
	value2 : <%=value2%><br/>	
</body>
</html>










