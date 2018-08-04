<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>CSS 적용하기</title>
<%-- css 정의 --%>
<style>
	<%-- class 속성에 css1 이 있는 태그에 적용--%>
	.css {
		color : red;
		font-size : 20px;
	}
</style>
<%-- 외부파일 적용 --%>
<link rel="stylesheet" href="css/CSSBasic1_1_Basic.css"/>
</head>
<body>
	<%-- 인라인 --%>
	<div style="color:red; font-size:20px;">
		안녕하세요
	</div>
	<%-- 임베디드 : head 부분의 style 태그에 있는 css 적용 --%>
	<div class="css1">
		안녕하세요
	</div>
	<%-- 외부 파일 링크 방식 여러 문서에 적용할 경우 --%>
	<div class="css2">
		안녕하세요
	</div>
</body>
</html>