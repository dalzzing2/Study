<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>세션 사용 예제</title>
</head>
<body>
	<%-- 세션은 브라우저 마다 하나씩 할당 --%>
	<%-- 브라우저를 종료하면 소멸된다 --%>
	<%
		session.setAttribute("data1", "세션데이터");
		session.setAttribute("data2", 100);
	%>	
	<%-- 애플리케이션은 서버에 단 하나만 존재 --%>
	<%-- 사용자 브라우저에 관계없이 서버 종료시까지 유지 --%>
	<%
		application.setAttribute("data3", "애플리케이션");
		application.setAttribute("data4", 200);
	%>
	<a href="JSP10_2_GetSession.jsp">정보확인</a>
</body>
</html>










