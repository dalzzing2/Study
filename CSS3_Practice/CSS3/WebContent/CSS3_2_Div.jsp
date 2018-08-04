<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Div 태그를 이용한 화면 구성</title>
<style>
	/* main */
	.main {
		/* 가로길이 */
		width : 1024px;
		/* 가운데 정렬 */
		margin : auto;
	}
	div {
		font-size : 50px;
		text-align : center;
		align : center;
		height : 150px;
	}
	.title, .banner, .menu, .article1,
	.article2, .article3, .footer {
		border : 1px black solid;
		position : relative;
	}
	.menu{
		height : 900px;
		width : 300px;
	}
	.article1, .article2, .article3 {
		height : 298px;
		width : 721px;
		left : 300px;
		top : -903px;
	}
	.footer {
		top : -903px;
	}
	<%--
	/* 좌표 설정의 예 */
	.banner {
		/* 원래 위치를 기준(브라우저가 정해준 값을 승계) */
		/*
		position : relative;
		*/
		/* 브라우저 좌측 상단 기준(브라우저가 정해준 값을 제거) */
		position : absolute;
		/* 가로 좌표 */
		left : 100px;
		/* 세로 좌표 */
		top : 100px;
	}
	--%>
	/*
		max-width : 최대 크기(~ 이하인 경우)
		min-width : 최소 크기(~ 이상인 경우)
		
		스마트폰
		@media all (min-width:320px) and (max-width:767px)
		
		태블릿 pc
		@media all (min-width:768px) and (max-width:1024px)
				
		pc
		@media all (min-width:1025px)
	*/	
	@media all and (max-width:1024px){
		.main {
			width : 800px;
		}
		.menu {
			width : 797px;
			height : 150px;
		}
		.article1, .article2, .article3{
			width : 797px;
			height : 150px;
			left : 0px;
			top : 0px;
		}
		.footer{
			top: 0px;
		}
	}

	
</style>
</head>
<body>
	<div class="main">
		<div class="title">
			<p>title</p>
		</div>
		<div class="banner">
			<p>banner</p>
		</div>
		<div class="menu">
			<p>menu</p>
		</div>
		<div class="article1">
			<p>article1</p>
		</div>
		<div class="article2">
			<p>article2</p>
		</div>
		<div class="article3">
			<p>article3</p>
		</div>
		<div class="footer">
			<p>footer</p>
		</div>
	</div>
</body>
</html>