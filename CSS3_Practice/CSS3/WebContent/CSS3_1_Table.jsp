<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Table 태그를 이용한 화면 구성</title>
<style>
	table {
		width : 1024px;
	}
	tr{
		height : 150px;
	}
	td{
		/* 문자열을 가운데 표시한다 */
		text-align : center;
		font-size : 50px;
		font-weight : bold; 
		border : 1px solid black;
	}
	.menu{
		width : 30%;
	}
</style>
</head>
<body>
	<center>
		<table>
			<tr>
				<td colspan="2">title</td>
			</tr>
			<tr>
				<td colspan="2">banner</td>
			</tr>
			<tr>
				<td class="menu" rowspan="3">menu</td>
				<td>article1</td>
			</tr>
			<tr>
				<td>article2</td>
			</tr>
			<tr>
				<td>article3</td>
			</tr>
			<tr>
				<td colspan="2">footer</td>
			</tr>
		</table>
	</center>
</body>
</html>














