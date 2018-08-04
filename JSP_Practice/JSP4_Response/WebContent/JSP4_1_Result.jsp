<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 한글 처리
 	request.setCharacterEncoding("utf-8");
	// 파라미터 데이터 추출
	String data1 = request.getParameter("data1");
	String data2 = request.getParameter("data2");
	String data3 = request.getParameter("data3");
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
	data1 : <%=data1%><br/>
	data2 : <%=data2%><br/>
	data3 : <%=data3%><br/>
	JSP4_1_Result.jsp 입니다.
</body>
</html>




