<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>기본 HTML 태그</title>
</head>
<body>
	<%-- 제목용 태그 --%>
	<h1>h1 제목</h1>
	<h2>h2 제목</h2>
	<h3>h3 제목</h3>
	<h4>h4 제목</h4>
	<h5>h5 제목</h5>
	<h6>h6 제목</h6>
	<%-- 단락 --%>
	<p>문자열 1입니다</p>
	<p>문자열 2입니다</p>
	<%-- 영역을 구분 --%>
	<div>문자열 3입니다</div>
	<div>문자열 4입니다</div>
	<%-- 링크 --%>
	<a href="http://www.w3schools.com">w3schools</a><br/>
	<%-- 이름이 abc인 창을 통해 요청한다. --%>
	<a href="http://www.w3schools.com" target="abc">
		w3schools.com
	</a>
	<br/>
	<%-- 계속해서 새로운 창을 통해 요청한다 --%>
	<a href="http://www.w3schools.com" target="_blank">
		w3schools.com
	</a>
	<br/>
	<%-- 브라우저가 처리할 수 있는 파일을 요청한다. --%>
	<a href="media/video.mp4">동영상 재생</a><br/>
	<a href="media/song.mp3">썸타기 좋은날~</a><br/>
	<%-- 브라우저가 처리할 수 없는 파일을 요청한다. --%>
	<a href="media/EditPlus.zip">압축파일</a><br/>
	<%-- 이미지 --%>
	<%-- 이미지 파일명 : html을 이용해 화면을 구성한 후에
	      이미지의 데이터를 다운로드 받기 시작한다. 
	      응답결과의 용량이 작아지기 때문에 화면을 빠르게
	      구성할 수 있도록 할 수 있지만 화면이 구성된 시점과
	      이미지가 보여지는 시점이 크게 차이가 날 수도 있다.
	      대부분의 이미지 파일
	 --%>
	<img src="media/thm.jpg"/><br/>
	<%--
		데이터 : 응답결과내에 포함되어 있기 때문에 화면 구성할때
		데이터를 이미 받아온 상태가 된다.
		응답결과의 용량이 커지기 때문에 화면을 구성하는 시간이
		오래 결릴수도 있지만 화면이 구성된 시점가 이미지가
		보여지는 시점이 차이가 없다.
		배경으로 사용하는 이미지 중 용량이 작은 이미지
		프로그래밍 코드를 통해 생성하는 이미지
	 --%>
	<img src="data:image/gif;base64,R0lGODlhEAAQAKIHAPzu7PfT0Oh5cfGtqONbUuBLQeBKP////yH5BAEAAAcALAAAAAAQABAAAANKeLrcfkAI8NowZtQFCCbUJmCYsAWFAQBGEVSjyhqmc2HBnDUdGQQkEOOGA5I0CkCKxMQUQjEnAMU0GUkuZTPgaRaWTEK0Sa5tGgkAOw=="/><br/>
	<%-- 이미지 링크 --%>
	<a href="http://multicampus.co.kr">
		<img src="media/thm.jpg"/><br/>
		멀티캠퍼스
	</a>	
	<%-- 내부링크 --%>
	<%-- 아이디가 zzz인 태그를 보여주기 위해 스크롤한다 --%>
	<a href="#zzz">zzz로 이동</a>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<br/>
	<div id="zzz">zzz입니다.</div>
</body>
</html>













