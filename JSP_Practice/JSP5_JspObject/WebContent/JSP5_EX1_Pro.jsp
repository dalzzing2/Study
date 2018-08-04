<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
//파라미터 데이터 추출
	String num1 = request.getParameter("num1");
	String num2 = request.getParameter("num2");
	String op = request.getParameter("op");
	// 숫자로 변환
	int number1 = Integer.parseInt(num1);
	int number2 = Integer.parseInt(num2);
	// 연산작업
	int result = 0;
	if(op.equals("1")){
		result = number1 + number2;
	} else if(op.equals("2")){
		result = number1 - number2;
	} else if(op.equals("3")){
		result = number1 * number2;
	} else if(op.equals("4")){
		result = number1 / number2;
	}
	// 결과를 세션에 담는다.
	session.setAttribute("result", result);
	// JSP로 이동한다.
	String site = "JSP5_EX1_Result.jsp";
	RequestDispatcher dis 
			= request.getRequestDispatcher(site);
	dis.forward(request, response);
%>
