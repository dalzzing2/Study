<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>선택자 조합</title>
<style>
	/* div1 클래스를 포함한 하위까지 모두 적용 */
	.div1{
		background-color : white;
		color : black;
	}
	/* .div1 안에있는 모든 div 태그를 선택 */
	.div1 div{
		background-color : red;
		color : yellow;
	}
	/* .div1 안에 있는 모든 .div3을 선택 */
	/* div 태그 중에 class 가 div1 인 태그 자식 중 class가 div3이고 id가 kkk인 요소 선택 */
	.div1 > div.div3#kkk{
		backgorund-color : black;
		color : white;
	}
	/* 여러 선택자를 동시에 작성해 주는 경우 */
	.div100, .div200{
		background-color : olive;
		color : purple;
	}
	/* 동적 가상 클래스 */
	.div300{
		background-color : black;
		color : white;
	}
	.div300:hover {
		background-color : white;
		color : black;
	}
	/* 언어 선택자 */
	/* html 태그에 설정된 언어에 따른다 (ISO-639 language code) */
	.div400 {
		background-color : black;
		color : white;
	}
	.div400:lang(ko) {
		background-color : black;
		color : white;
	}
</style>
</head>
<body>
	<div class="div1">
		문자열5
		<div class="div2">
			<div class="div3">
				문자열1
			</div>
			<div class="div4">
				문자열2
			</div>
		</div>
		<div class="div3">
			문자열3
		</div>
		<div class="div3" id="kkk">
			문자열4
		</div>
	</div>
	
	<div class="div100">
		문자열5
	</div>
	<div class="div200">
		문자열6
	</div>
	<div class="div300">
		문자열7
	</div>
	<div class="div400">
		문자열8
	</div>
</body>
</html>