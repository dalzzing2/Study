<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>페이지 이동 실습</title>
</head>
<body>
	<%
		// 1. sendRedirect 이용하기
		// 브라우저의 주소가 이동된 주소로 변경
		// 파라미터 데이터는 주소 뒤에 붙혀줘야 한다.
		// response.sendRedirect("JSP7_1_Result1.jsp?data1=123&data2=abc");
	
		// 2. forward 메서드 이용하기
		// forward 메서드는 브라우저의 주소가 변경되지
		// 않는다.
		// 값을 전달하기 위해서는 setAttribute를 이용한다.
		// 전달할 값을 셋팅
		// request 객체가 다음 페이지로 전달되기 때문에
		// request 객체에 담으면 된다.
		//request.setAttribute("data1", "kkk");
		//request.setAttribute("data2", 333);
		// 이동한다.
		//String site = "JSP7_1_Result2.jsp";
		//RequestDispatcher dis 
		//		= request.getRequestDispatcher(site);
		//dis.forward(request, response);
		
		// forward 액션 태그를 이용한다.
		// 1. forward메서드 처럼 서버에서 코드의 흐름이
		// 이동된다. 주소 창의 주소가 변경되지 않는다.
		// 2. param 태그를 이용해 파라미터로 데이터를
		// 넘긴다.
	%>
	<jsp:forward page="JSP7_1_Result3.jsp">
		<jsp:param value="zzz" name="value1"/>
		<jsp:param value="999" name="value2"/>
	</jsp:forward>
</body>
</html>










