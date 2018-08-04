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
<style>
	.highlight{
		background : black;
		color : white;
		trasition : all 0.2s;
	}
	
	li {
		transition : all 0.2s
	}
	
</style>
<script>
	$(function(){
		$("li").hover(function(){
			// 클래스를 추가
			$(this).addClass("highlight");
		}, function(){
			// 클래스를 제거
			$(this).removeClass("highlight");
		});
	});
</script>
</head>
<body>
	<ul id="list">
		<li>항목1</li>
		<li>항목2</li>
		<li>항목3</li>
		<li>항목4</li>
		<li>항목5</li>
		<li>항목6</li>
		<li>항목7</li>
	</ul>
</body>
</html>












