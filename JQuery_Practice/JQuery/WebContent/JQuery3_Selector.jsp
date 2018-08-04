<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	$(function(){
		// 전체 선택자
		$("*").css("background", "yellow");
		// 태그 선택자 : $("태그이름");
		$("p").css("background", "blue");
		// 아이디 선택자 : $("#아이디")
		$("#test1").css("color", "white");
		// 클래스 선택자 : $(".클래스")
		$(".test2").css("background", "red");
		$(".test3").css("background", "green");
		// 클래스에 test2와 test3이 모두 있는 태그를 선택
		$(".test2.test3").css("background", "white");
		// p 태그에 class 가 test4인 태그를 선택
		$("p.test4").css("background", "purple");
		// div 태그 중에 class가 test4인 태그를 선택
		$("div.test4").css("background", "red");
		// div 태그 중에 id가 test5인 태그
		$("div#test4").css("color", "white");
		// p 태그 중에 id가 test5인 태그
		$("p#test5").css("color", "yellow");
		// 여러 셀렉터를 이용해 동시에 여러 태그를 선택할 경우 , 로 구분한다.
		$("h1, h2").css("color", "orange");
	});
</script>
</head>
<body>
	<p>문자열1</p>
	<p id = "test1">문자열2</p>
	<p class = "test2 test3">문자열3</p>
	<p class = "test2">문자열4</p>
	<p class = "test3">문자열5</p>
	<p class = "test4">문자열6</p>
	<div class = "test4" id = "test5">문자열7</div>
	<p id = "test5">문자열8</p>
	<h1>h1 글자입니다</h1>
	<h2>h2 글자입니다</h2>
</body>
</html>