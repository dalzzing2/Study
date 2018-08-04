<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JQuery 맛보기</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function set_h1(){
		/*
		// h1 태그를 얻어온다.
		var h1 = document.getElementById("h1");
		// 첫 번째 h1의 문자열을 관리하는 객체를 추출한다.
		var str = h1[0].firstchild;
		// 문자열을 변경
		str.nodeValue = "문자열 변경";
		*/
		
		//var h1 = jQuery("hi");
		//var h1 = $("h1");
		$("h1").text("jQuery로 문자열 변경");
	}
	function get_h1(){
		/*
		// li 태그 객체를 얻어온다.
		var li = document.getElementById("li");
		// id가 result인 태그 객체를 얻어온다.
		var result = document.getElementById("result");
		// li 태그 객체 개수만큼 반복
		for(var i = 0; i < li.length; i++){
			//i 번째 li 태그의 문자열 관리 객체를 추출
			var str = li[i].firstChild;
			// 출력
			result.innerHTML += str.nodeValue + "<br/>";
		}*/
		// li 태그의 개수만큼 반복
		$("li").each(function(){
			// 문자열 추출
			// 특정 태그 때문에 함수가 호출되었을 경우 $(this)는 그 태그 객체를 의미한다
			var str = $(this).text();
			// 출력
			// id가 result인 div 태그에 html로 넣어준다.
			
			// $("#result").html(str + "<br/>");
			$("result").append(str + "<br/>");
		});
	}
</script>
</head>
<body>
	<h1>문자열입니다</h1>
	<button onclick="set_h1()">h1 문자열 변경하기</button>
	<br/>
	<ul>
		<li>데이터1</li>
		<li>데이터2</li>
		<li>데이터3</li>
	</ul>
	<button onclick="get_li()">li 문자열 출력</button>
	<div id="result"></div>
</body>
</html>