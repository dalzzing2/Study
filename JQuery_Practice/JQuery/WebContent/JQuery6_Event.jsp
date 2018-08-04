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
	// t1에 onclick속성에서 호출하는 함수
	function event_t1(){
		alert('t1');
	}
	
	$(function(){
		// 태그 객체에 이벤트 발생시 호출될 함수를 넣어준다.
		// on + 사건이름
		var t2 = document.getElementById("t2");
		t2.onclick = function(){
			alert("t2");
		}
		
		// 함수를 이용한 등록
		var t3 = document.getElementById("t3");
		if(t3.addEventListener){
			t3.addEventListener("click", function(){
				alert("t3");
			});
		} else {	// IE 8.0 이하
			t3.attachEvent("onclick", function(){
				alert("t3");
			});
		}
		// ready 내에서 이벤트 설정
		$("#t5").on("click", function(){
			alert("t5");
		});
		// 단 한번만 반응할 이벤트를 설정
		$("#t6").one("click", function(){
			alert("t6");
		});
	});
	
	// ready 밖에서 이벤트 설정
	// #t4 까지 읽을때는 t4가 있는지 모르고 예약만 걸어놓음
	$(document).on("click", "#t4", function(){
		alert('t4');
	});
	
	
</script>
</head>
<body>
	<h1 id="t1" onclick="event_t1()">inline</h1>
	<h1 id="t2">onclick 멤버 사용하기</h1>
	<h1 id="t3">함수를 이용한 등록</h1>
	<h1 id="t4">jQuery 사용(ready 외부)</h1>
	<h1 id="t5">jQuery 사용(ready 내부)</h1>
	<h1 id="t6">one</h1>
</body>
</html>