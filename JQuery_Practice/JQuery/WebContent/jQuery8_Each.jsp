<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>배열 처리</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	$(function(){
		// 배열 
		var array1 = [10, 20, 30, 40, 50];
		// 배열 처리(index : 인덱스, item : index번째 데이터)
		$.each(array1, function(index, item){
			$("#result").append(index + " : " + item + "<br/>");
		});
		// 태그처리(index : 인덱스, item : index번째 태그 객체)
		// item을 이용해도 되지만 $(this)를 이용해된다.
		$("li").each(function(index, item){
			// item을 이용해서 jQuery 객체로 만들어 주거나
			// $(this)를 사용한다.
			var str = $(item).text();
			$("#result").append(index + " : " + str + "<br/>");
		});
	});
</script>
</head>
<body>
	<ul id="list">
		<li>항목1</li>
		<li>항목2</li>
		<li>항목3</li>
	</ul>
	<div id="result"></div>
</body>
</html>












