<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
	// 파라미터 추출
	String title = request.getParameter("title");
%>
<title><%=title%></title>
</head>
<body>
	<center>
		<table border="1" width="800px">
			<tr>
				<td colspan="2">
					<center>
						여기는 배너 부분입니다<br/>
						<%=title%>
					</center>
				</td>
			</tr>
			
			
			
			
			
			