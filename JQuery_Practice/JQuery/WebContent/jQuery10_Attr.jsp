<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>속성 제어하기</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<style>
	.change{
		width : 240px;
		height : 300px;
	}
</style>
<script>
	function set_size(){
		/*
		var test = document.getElementById("test");
		test.width = 240;
		test.height = 300;
		*/
		$("#test").attr("width", 240);
		$("#test").attr("height", 300);
	}
	function get_size(){
		var w = $("#test").attr("width");
		var h = $("#test").attr("height");
		var i = $("#test").attr("id");
		var s = $("#test").attr("src");
		
		$("#result").html("width : " + w + "<br/>");
		$("#result").append("height : " + h + "<br/>");
		$("#result").append("id : " + i + "<br/>");
		$("#result").append("pw : " + s + "<br/>");
	}
	function set_css(){
		$("#test").toggleClass("change");
	}
</script>
</head>
<body>
	<img src="image/thm.jpg" id="test" 
	     width="120" height="150"/>
	<br/>
	<button onclick="set_size()">크기 변경</button>
	<button onclick="get_size()">크기 출력</button>
	<button onclick="set_css()">CSS 적용</button>
	<div id="result"></div>
</body>
</html>