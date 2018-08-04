<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>파라미터를 이용한 useBean</title>
</head>
<body>
	<form action="JSP11_5_Result.jsp" method="post">
		name : <input type="text" name="name"/><br/>
		age : <input type="number" name="age"/><br/>
		gender : <input type="radio" name="gender"
		                value="1"/>남자
		         <input type="radio" name="gender"
		                value="2"/>여자<br/>
		<button type="submit">확인</button>
	</form>
</body>
</html>


