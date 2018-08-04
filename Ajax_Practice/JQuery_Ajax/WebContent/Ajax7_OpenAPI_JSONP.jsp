<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Open API - JSONP</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_jsonp(){
		var site = "http://api.openweathermap.org/data/2.5/weather";
		var param = {
			q : "seoul",
			appid : "2de143494c0b295cca9337e1e96b00e0"
		}
		$.ajax({
			url : site,
			dataType : "jsonp",
			data : param,
			success : function(data){
				var lat = data.coord.lat;
				var lng = data.coord.lon;
				$("#result").html("위도 : " + lat + "<br/>");
				$("#result").append("경도 : " + lng + "<br/>");
				var country = data.sys.country;
				var sunrise = data.sys.sunrise;
				var sunset = data.sys.sunset;
				$("#result").append("도시 : " + country + "<br/>");
				$("#result").append("해뜨는 시간 : " + sunrise + "<br/>");
				$("#result").append("해지는 시간 : " + sunset + "<br/>");
				var speed = data.wind.speed;
				var deg = data.wind.deg;
				$("#result").append("풍속 : " + speed + "<br/>");
				$("#result").append("풍향 : " + deg + "<br/>");
			}
		});
	}
	
</script>
</head>
<body>
	<button onclick="get_jsonp()">날씨 데이터 가져오기</button>
	<div id="result"></div>
</body>
</html>











