<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- auto flush를 비활성화 --%>
<%@ page autoFlush="false" %>
<%-- 버퍼의 사이즈를 조절 --%>
<%@ page buffer="102400kb"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>auto flush 예제</title>
</head>
<body>
	버퍼의 크기 : <%=out.getBufferSize()%><br/>
	남은 크기 : <%=out.getRemaining()%><br/>
	auto flush : <%=out.isAutoFlush()%><br/>
	<%
		for(int i = 0 ; i < 100000 ; i++){
			out.write("1234 ");
			// flushing
			// out.flush();
		}
	%>
</body>
</html>










