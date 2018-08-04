<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>타이머</title>
<script>
	function startTimer(){
		var result = document.getElementById("result");
		// 3초후에 지정된 함수가 한번 호출된다.
		setTimeout(function(){
			result.innerHTML += "타이머 동작<br/>";
		}, 3000);
	}
	
	// 인터벌을 제어하기 위해 변수를 선언
	var inter;
	function startInterval(){
		var result = document.getElementById("result");
		// 100ms 마다 한번씩 지정된 함수가 호출된다.
		inter = setInterval(function(){
			result.innerHTML += "인터벌 가동 중_"
		}, 100);
	}
	function stopInterval(){
		clearInterval(inter);
	}
	
</script>
</head>
<body>
	<button onclick="startTimer()">타이머 가동</button>
	<button onclick="startInterval()">인터벌 가동</button>
	<button onclick="stopInterval()">인터벌 정지</button>
	<div id="result"></div>
</body>
</html>








