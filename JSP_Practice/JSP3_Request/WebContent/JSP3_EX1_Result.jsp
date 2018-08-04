<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 데이터 추출
	String num1 = request.getParameter("num1");
	String num2 = request.getParameter("num2");
	String op = request.getParameter("op");
	// 숫자로 변환
	int number1 = Integer.parseInt(num1);
	int number2 = Integer.parseInt(num2);
	// 연산자에 따라 값을 계산한다.
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
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>계산기 결과 페이지</title>
</head>
<body>
	계산 결과 : <%=result%>
</body>
</html>








