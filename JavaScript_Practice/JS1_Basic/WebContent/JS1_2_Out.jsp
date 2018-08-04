<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>출력하기</title>
<script>
	// 콘솔창에 출력(F12를 누르면 콘솔창이 나타난다.)
	console.log("콘솔에 출력");
	// 웹 브라우저 화면에 HTML로 출력한다.
	document.writeln("document 객체를 이용한 출력<br/>");
	window.onload = function(){
		// id가 result인 div 태그를 얻어온다.
		var result = document.getElementById("result");
		result.innerHTML = "div 태그에 html 추가하기<br/>";
		
		// 경고창
		alert("경고창 입니다");
	}
</script>
</head>
<body>
	<input type="text"/><br/>
	<div id="result"></div>
</body>
</html>






