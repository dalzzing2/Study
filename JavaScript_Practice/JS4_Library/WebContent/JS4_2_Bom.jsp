<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>BOM(Browser Object Model)</title>
<script>
	window.onload = function(){
		var result = document.getElementById("result");
		// 현재 사이트의 주소
		// 브라우저의 주소창
		result.innerHTML = location.href + "<br/>";
		// user agent
		result.innerHTML += navigator.userAgent + "<br/>";
		// 브라우저의 종류
		if(navigator.userAgent.indexOf("Safari") > -1){
			if(navigator.userAgent.indexOf("Chrome") > -1){
				result.innerHTML += "크롬<br/>";
			} else {
				result.innerHTML += "사파리<br/>";
			}
		} else if(navigator.userAgent.indexOf("FireFox") > -1){
			result.innerHTML += "파이어폭스<br/>";
		} else if(navigator.userAgent.indexOf("Opera") > -1){
			result.innerHTML += "오페라 구버전<br/>";
		} else if(navigator.userAgent.indexOf("OPR") > -1){
			result.innerHTML += "오페라 최신버전<br/>";
		} else if(navigator.userAgent.indexOf("MSIE") > -1){
			// MSIE 만 있다면 6 ~ 7
			// MSIE와 Trident가 같이 있다면 8 ~ 10
			// Trident만 있다면 11
			result.innerHTML += "인터넷 익스플로러 6 ~ 10<br/>";
		} else if(navigator.userAgent.indexOf("Trident") > -1){
			result.innerHTML += "인터넷 익스플로러 8 ~ 11<br/>";
		}
		// 디바이스의 종류
		if(navigator.userAgent.indexOf("Mobile") > -1){
			result.innerHTML += "스마트폰<br/>";
		} else if(navigator.userAgent.indexOf("Tablet") > -1){
			result.innerHTML += "태블릿<br/>";
		} else {
			result.innerHTML += "PC<br/>";
		}
		// OS의 종류
		// PC : Linux, Windows NT, Macintosh
		// 모바일 : Android, Webos, iPhone, iPad,
		// Blackberry, Windows Phone.....
		if(navigator.userAgent.indexOf("Windows NT") > -1){
			result.innerHTML += "윈도우<br/>";
		} else if(navigator.userAgent.indexOf("Linux") > -1){
			if(navigator.userAgent.indexOf("Android") > -1){
				result.innerHTML += "안드로이드<br/>";
			} else {
				result.innerHTML += "리눅스<br/>";
			}
		} else if(navigator.userAgent.indexOf("iPhone") > -1){
			result.innerHTML += "아이폰<br/>";
		} else if(navigator.userAgent.indexOf("Macintosh") > -1){
			result.innerHTML += "매킨토시<br/>";
		}
		
	}
	function set_href(){
		// w3schools.com으로 이동
		// history에 남는다.(이전으로 이동 가능)
		location.href= "http://www.w3schools.com";
	}
	function set_replace(){
		// w3schools.com으로 이동
		// history에 남지 않는다(이전으로 이동 불가능)	
		location.replace("http://www.w3schools.com");
	}
</script>
</head>
<body>
	<div id="result"></div>
	<button onclick="set_href()">페이지 이동</button>
	<button onclick="set_replace()">페이지 이동</button>
</body>
</html>








