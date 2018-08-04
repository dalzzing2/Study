<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<style>
	.c1{
		background : black;
		color : white;
	}
</style>
<script>
	$(function(){
		$("#t1").hover(function(){
			// 들어왔을 때
			$("#t1").addClass("c1");
		}, function(){
			// 나갔을 때
			$("#t1").removeClass("c1");
		});
		
		$("#t1").click(function(){
			alert("클릭사건 발생");
		});
	});
</script>
</head>
<body>
	<h1 id="t1">hover 테스트</h1>	
</body>
</html>