<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Margin, Padding, Border</title>
<style>
	.main{
		/* 외곽선 : 굵기, 색상, 종류 */
		border : 1px black solid;
	}
	.sub1{
		/* 외곽선 : 굵기, 색상, 종류 */
		border : 1px black solid;
		/* 외부의 여백 : 상하좌우 모두 20 */
		margin : 20px;
	}
	.sub2{
		/* 외곽선 : 굵기, 색상, 종류 */
		border : 1px black dotted;
		margin-top : 20px;
		margin-left : 10px;
		margin-right : 30px;
		margin-bottom : 50px;
	}
	.sub3{
		/* 외곽선 : 굵기, 색상, 종류 */
		border : 1px black dashed;
		/*상하, 좌우 */
		/*margin : 25px 50px;*/
		/*상, 좌우, 하 */
		/*margin : 25px 50px 75px;*/
		/*상, 우, 하, 좌 */
		margin : 25px 50px 75px 100px;
	}
</style>
</head>
<body>
	<div class="main">
		<div class="sub1">
			<h3>sub1 영역</h3>
		</div>
		<div class="sub2">
			<h3>sub2 영역</h3>
		</div>
		<div class="sub3">
			<h3>sub3 영역</h3>
		</div>
	</div>
</body>
</html>