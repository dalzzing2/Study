<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>사칙 계산기</title>
</head>
<body>
	<form action="JSP3_EX1_Result.jsp" method="post">
		<input type="number" name="num1"
		       placeholder="숫자1"/><br/>
		<input type="number" name="num2"
		       placeholder="숫자2"/><br/>
		<input type="radio" name="op" value="1" checked/>+<br/>
		<input type="radio" name="op" value="2"/>-<br/>
		<input type="radio" name="op" value="3"/>*<br/>
		<input type="radio" name="op" value="4"/>/<br/>
		<button type="submit">확인</button>
	</form>
</body>
</html>









