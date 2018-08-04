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
	// 페이지 로딩이 완료되면 호출되는 함수 등록
	// onload는 속성에 함수를 넣어주는 것이므로
	// 제일 마지막 하나만 동작한다.
	/*
	window.onload = function(){
		var result = document.getElementById("result");
		result.innerHTML += "on load 1<br/>";
	}
	window.onload = function(){
		var result = document.getElementById("result");
		result.innerHTML += "on load 2<br/>";
	}
	window.onload = function(){
		var result = document.getElementById("result");
		result.innerHTML += "on load 3<br/>";
	}
	*/
	// jQuery의 ready를 사용하면 등록된 모든 함수가 호출된다.
	jQuery(document).ready(function(){
		$("#result").append("ready 1<br/>");
	});
	jQuery(document).ready(function(){
		$("#result").append("ready 2<br/>");
	});
	jQuery(document).ready(function(){
		$("#result").append("ready 3<br/>");
	});
	
	$(document).ready(function(){
		$("#result").append("ready 4<br/>");
	});
	
	$(function(){
		$("#result").append("ready 5<br/>");
	});
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>