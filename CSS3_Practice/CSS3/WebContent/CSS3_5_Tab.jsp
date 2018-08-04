<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>탭</title>
<link rel="stylesheet" href="css/CSS3_5_Tab.css"/>
<script>
	window.onload = function(){
		
	}
	function tab_click(obj){
		// 페이지의 주소값을 #을 기준으로 잘라낸다.
		var addr = obj.href.split("#");
		// 모든 li 태그에 className을 비워줌
		clock.className = "";
		weather.className = "";
		calendar.className = "";
		chart.className = "";
		
		// 추출한 이름을 통해 태그객체를 추출
		var tag_obj = document.getElementById(addr[1]);
		// active 클래스를 추가
		tag_obj.className = "active";
	}
</script>
</head>
<body>
	<div class="main">
		<%-- 제목부분 --%>
		<h1 class="tab_title">
			탭 메뉴 만들기<span>Tab menu Design</span>
		</h1>
		<%-- 탭부분 --%>
		<div class="tabs">
			<%-- 탭 버튼 부분 --%>
			<div class="tab_menu">
				<ul>
					<li>
						<a href="#clock" onclick="tab_click('this')">
							<img src="tab_image/clock-icon.png"/>
							시계
						</a>
					</li>
					<li>
						<a href="#weather" onclick="tab_click('this')">
							<img src="tab_image/weather-icon.png"/>
							날씨
						</a>
					</li>
					<li>
						<a href="#calendar" onclick="tab_click('this')">
							<img src="tab_image/calendar-icon.png"/>
							달력
						</a>
					</li>
					<li>
						<a href="#chart" onclick="tab_click('this')">
							<img src="tab_image/chart_pie-icon.png"/>
							차트
						</a>
					</li>
					<li>
						<a href="#chat" onclick="tab_click('this')">
							<img src="tab_image/chat-icon.png"/>
							채팅
						</a>
					</li>
				</ul>
			</div>
			<%-- 탭 본문 부분 --%>
			<div class="tab_contents">
				<ul>
					<li id="clock">
						<img src="tab_image/clock.png" width="128" height="128"/>
						<h3>시계</h3>
						<p>시계 시계 시계 시계 시계</p>
					</li>
					<li id="weather">
						<img src="tab_image/weather.png" width="128" height="128"/>
						<h3>날씨</h3>
						<p>날씨 날씨 날씨 날씨 날씨</p>
					</li>
					<li id="calendar">
						<img src="tab_image/calendar.png" width="128" height="128"/>
						<h3>달력</h3>
						<p>달력 달력 달력 달력 달력</p>
					</li>
					<li id="chart">
						<img src="tab_image/chart_pie.png" width="128" height="128"/>
						<h3>차트</h3>
						<p>차트 차트 차트 차트 차트</p>
					</li>
					<li id="chat">
						<img src="tab_image/chat.png" width="128" height="128"/>
						<h3>채팅</h3>
						<p>채팅 채팅 채팅 채팅 채팅</p>
					</li>
				</ul>
			</div>
		</div>
	</div>
</body>
</html>