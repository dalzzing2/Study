<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>미디어</title>
<script>
	function playVideo(){
		myVideo.play();
	}
	function pauseVideo(){
		myVideo.pause();
	}
	function stopVideo(){
		myVideo.pause();
		myVideo.currentTime = 0;
	}
	function playAudio(){
		myAudio.play();
	}
	function pauseAudio(){
		myAudio.pause();
	}
	function stopAudio(){
		myAudio.pause();
		myAudio.currentTime = 0;
	}
</script>
</head>
<body>
	<%--
		poster : 동영상이 재생 되기 전까지 보여줄 이미지
		controls : 재생 제어를 위한 컨트롤을 표시
		loop : 반복 재생
		autoplay : 자동 재생
	 --%>
	 <%--
	<video src="media/video.mp4" poster="image/thm.jpg"
	       controls loop autoplay>
		이 부분은 HTML5가 지원되지 않는 브라우저를 위한
		HTML코드를 작성하는 부분입니다
	</video>
	 --%>
	<%--
	<audio src="media/song.mp3" controls loop autoplay></audio>
	 --%>
	<video src="media/video.mp4" id="myVideo"></video><br/>
	<audio src="media/song.mp3" id="myAudio" controls></audio><br/>
	
	<button onclick="playVideo()">동영상 재생</button>
	<button onclick="pauseVideo()">동영상 일시정지</button>
	<button onclick="stopVideo()">동영상 정지</button>
	<br/>
	
	<button onclick="playAudio()">오디오 재생</button>
	<button onclick="pauseAudio()">오디오 일시정지</button>
	<button onclick="stopAudio()">오디오 정지</button>
</body>
</html>



















