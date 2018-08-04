<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	$(function(){
		// index는 0 부터 시작한다.
		// 홀수 번째 인덱스 선택
		$("tr:odd").css("background", "yellow");
		// 짝수 번째 인덱스 선택
		$("tr:even").css("background", "red");
		// 첫 번째 선택
		$("tr:first").css("color", "yellow");
		// 마지막 선택
		$("tr:last").css("color", "red");
		// 인덱스 선택
		$("tr:eq(2)").css("color", "white");
		// nth-child, 인덱스 1부터 시작
		$("tr:nth-child(1)").css("color", "purple");
		// 수열 사용하기(n에는 0부터 대입)
		$("tr:nth-child(2n+1)").css("font-style", "italic");
	});
</script>
</head>
<body>
	<table border="1">
		<tr>
			<td>항목1</td>
			<td>항목2</td>
			<td>항목3</td>
		</tr>
		<tr>
			<td>항목1</td>
			<td>항목2</td>
			<td>항목3</td>
		</tr>
		<tr>
			<td>항목1</td>
			<td>항목2</td>
			<td>항목3</td>
		</tr>
		<tr>
			<td>항목1</td>
			<td>항목2</td>
			<td>항목3</td>
		</tr>
	</table>
</body>
</html>










