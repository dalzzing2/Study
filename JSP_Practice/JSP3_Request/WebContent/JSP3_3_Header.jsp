<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>User-Agent 값을 추출</title>
</head>
<body>
	User-Agent : <%=request.getHeader("user-agent")%>
</body>
</html>