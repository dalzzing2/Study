<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>셀렉터</title>
<style>
	/* 태그 선택자 */
	body{
		/* 배경 색상 */
		background-color : blue;
		/* 글자색 */
		color : yellow;
	}
	P {
		background-color : green;
		color : purple;
	}
	/* id 속성으로 선택 */
	#css1{
		background-color : red;
		color : balck;
	}
	/* class 속성으로 선택 */
	/*
		하나의 태그가 여러 개의 클래스에 적용을 받는다면 style 태그 내에 작성해준 스타일 시트 클래스의 순서대로 반영된다.
		만약 외부에서 만든 css 파일 가져다 사용하고 이를 수정할 경우에는 link 태그를 먼저 작성하고 그 밑에 클래스를 다시 정의하면 된다.
	*/
	.css2{
		background-color : white;
	}
	.css3{
		background-color : fuchsia;
	}
	.css4{
		color : black;
	}
</style>
</head>
<body>
	문자열1
	<p>문자열2</p>
	<p>문자열3</p>
	<p id="css1">문자열4</p>
	<p class="css2">문자열5</p>
	<p class="css3">문자열6</p>
	<p class="css3 css2">문자열7</p>
	<p class="css2 css3">문자열8</p>
</body>
</html>