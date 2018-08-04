<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>파라미터 데이터 사용하기 예제</title>
</head>
<body>
	<a href="JSP3_2_Parameter?data1=문자열1&data2=문자열2&data3=문자열3&data3=문자열4">
		파라미터 넘기기(서블릿)
	</a>
	<br/>
	<a href="JSP3_2_Parameter.jsp?data1=문자열1&data2=문자열2&data3=문자열3&data3=문자열4">
		파라미터 넘기기(JSP)
	</a>
	<br/>
	<%-- 폼 태그 안에 입력 도구들은 파라미터로
	     value 속성의 값을 넘겨준다. 
	 --%>
	<form action="JSP3_2_Parameter" method="post">
		<input type="text" name="data1"/><br/>
		<input type="text" name="data2"/><br/>
		<input type="checkbox" name="data3"
		       value="체크박스1"/>체크박스1<br/>
		<input type="checkbox" name="data3"
		       value="체크박스2"/>체크박스2<br/>
		<button type="submit">확인</button>
	</form>
</body>
</html>











