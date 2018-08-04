<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>jQuery 효과</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function show_effect(){
		// 보였다 안보였다.
		// $("#img1").toggle();
		// 애니메이션 동작시간 설정
		// $("#img1").toggle(1000);
		// 콜백 함수
		/*
		$("#img1").toggle(1000, function(){
			alert("애니메이션 종료");
		});
		*/
		// $("#img1").slideToggle();
		// $("#img1").slideToggle(1000);
		// $("#img1").fadeToggle();
		// $("#img1").fadeToggle(1000);
		
		//$("#img1").hide();
		//$("#img1").hide(1000);
		//$("#img1").delay(1000).hide(1000);
		//$("#img1").slideUp(1000);
		$("#img1").fadeOut(1000);
	}
	function init_effect(){
		//$("#img1").show();
		//$("#img1").show(1000);
		//$("#img1").delay(1000).show(1000);
		//$("#img1").slideDown(1000);
		$("#img1").fadeIn(1000);
	}
</script>
</head>
<body>
	<button onclick="show_effect()">효과 적용</button>
	<button onclick="init_effect()">효과 초기화</button>
	<br/>
	<img src="image/thm.jpg" id="img1" width="120"
	     height="150"/><br/>
</body>
</html>










