<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>현재 위치 측정</title>
<script>
	function get_location(){
		// 위치 측정을 지원할 경우에만 동작하게 한다.
		if(navigator.geolocation){
			// 현재 위치를 측정(단발성)
			navigator.geolocation.getCurrentPosition(success, error);
			// 현재 위치를 측정(지속성)
			navigator.geolocation.watchPosition(success, error);
		}
	}
	// 위치 측정에 성공했을 때 호출될 함수
	function success(position){
		result.innerHTML 
			= "위도 : " + position.coords.latitude + "<br/>";
		result.innerHTML
			+= "경도 : " + position.coords.longitude + "<br/>";
	}
	// 실패했을때
	// 네트워크 사정에 따라 실패했을 경우
	// 사용자가 위치 수집을 거부했을 경우
	function error(){
		result.innerHTML = "위치 측정 오류";
	}
</script>
</head>
<body>
	<div id="result"></div>
	<button onclick="get_location()">현재위치측정</button>
</body>
</html>







