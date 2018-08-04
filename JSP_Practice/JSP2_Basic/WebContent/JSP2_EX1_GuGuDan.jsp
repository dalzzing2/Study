<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>구구단 출력</title>
</head>
<body>
<%
	for(int i = 0 ; i < 9 ; i++){
		int a = 1 + i;
		int b = 2 + (i * 2);
%>
	2 X <%=a%> = <%=b%><br/>
<%		
	}
%>
</body>
</html>









