<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>캔버스</title>
<script>
	// 그림을 그리기 위한 도구
	var ctx;
	// 이미지 객체를 담을 참조 변수..
	var img;
	
	window.onload = function(){
		var canvas = document.getElementById("myCanvas");
		// 그림을 그리기위한 객체를 추출
		ctx = canvas.getContext("2d");
		// 좌표 이동
		ctx.moveTo(0, 0);
		// 선을 그린다.
		ctx.lineTo(100, 100); // 0,0 ~ 100,100
		ctx.lineTo(200, 0); //100,100 ~ 200,0
		ctx.stroke();
		// 원 그리기
		ctx.moveTo(150, 100);
		// 중심점x, 중심점y, 반지름, 시작각도, 종료각도
		// 각도 : 3시 방향이 0, Math.PI : 180도
		ctx.arc(100, 100, 50, 0 * Math.PI, 2.0 * Math.PI);
		ctx.stroke();
		// 이미지 객체
		img = new Image();
		// 이미지를 지정한다.
		img.src = "image/thm.jpg";
		// 사용하고자 하는 이미지가 모두 완료되면
		// 그림을 그리는 함수를 호출된다.
		// 게임 개발 시 사용하고자 하는 모든 이미지의 로딩이
		// 완료되면 함수를 호출하고 게임의 필요한 코드를
		// 동작시키도록 구현한다.
		img.onload = image_load_end;
		
	}
	
	function image_load_end(){
		ctx.drawImage(img, 10, 10);
	}
</script>
</head>
<body>
	<canvas id="myCanvas" width="300" height="200">
		HTML5가 지원되지 않는 브라우저를 위한 HTML 코드
	</canvas>
</body>
</html>







