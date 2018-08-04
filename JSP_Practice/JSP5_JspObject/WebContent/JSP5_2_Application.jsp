<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>초기화 파라미터</title>
</head>
<body>
	<%--
		WEB-INF에 있는 web.xml에 작성한 파라미터 값은
		웹 애플리케이션 내에서 모두 가져다 사용할 수 
		있다.
		모든 페이지에서 고정된 값이 필요할 경우 사용
		<context-param>
			<description>설명문(필수x)<description>
			<param-name>이름</param-name>
			<param-value>값</param-value>
		</context-param>
	--%>
	 <%
	 	// 초기화 파라미터 값을 읽어온다.
	 	String data1 
	 			= application.getInitParameter("data1");
	 	String data2
	 			= application.getInitParameter("data2");
	 %>
	 data1 : <%=data1%><br/>
	 data2 : <%=data2%><br/>
</body>
</html>











