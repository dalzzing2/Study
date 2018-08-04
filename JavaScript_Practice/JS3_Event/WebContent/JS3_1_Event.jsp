<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%--
	웹 브라우저에서의 이벤트는
	http://www.w3schools.com/jsref/dom_obj_event.asp
	여기를 참조한다.
 --%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>자바 스크립트 이벤트 처리</title>
<script>
	var result;
	// window.onload : load 사건은 브라우저가 
	// html 요소를 전부다 메모리에 올려 놓으면 반응하는
	// 이벤트
	// 페이지가 보이자마자 자동으로 뭔가 처리해야 할때
	window.onload = function(){
		result = document.getElementById("result");
		result.innerHTML = "load 사건 발생<br/>";
		
		var btn1 = document.getElementById("btn1");
		result.innerHTML += btn1.onclick + "<br/>";
		// 자바 스크립트 코드로 이벤트 설정하기
		var img = document.getElementById("img");
		img.onmouseover = function(){
			// 이미지 교체
			img.src = "img/thm2.jpg";
		}
		img.onmouseout = function(){
			img.src = "img/thm.jpg";
		}
	}
	// 버튼을 누르면 호출되는 함수
	function btn_method(){
		result.innerHTML += "btn_method 호출<br/>";
	}
</script>
</head>
<body>
	<div id="result"></div>
	<%-- inline 방식으로 이벤트 처리 --%>
	<button onclick="alert('안녕하세요'); alert('반갑습니다');" id="btn1">
		버튼 클릭 이벤트
	</button>
	<br/>
	<button onclick="btn_method()">버튼 클릭 이벤트2</button>
	<br/>
	
	<img src="img/thm.jpg" id="img"/><br/>
</body>
</html>








