<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>애니메이션</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<style>
	#img1{
		position : relative;
	}
</style>
<script>
	function set_animate(){
		// 애니메이션 데이터 객체 생성
		var ani1 = {
			width : 240,		// 가로 길이
			height : 300		// 세로 길이
		}
		var ani2 = {
			left : 200,			// 좌측에서 떨어진 거리
			top : 200			// 위에서 떨어진 거리
		}
		var ani3 = {
			opacity : 0			// 투명도(1 ~ 0)
		}
		var ani4 = {
			width : 240,
			height : 300,
			left : 200,
			top : 200,
			opacity : 0
		}
		// $("#img1").animate(ani1);
		// $("#img1").animate(ani1, 5000);
		// $("#img1").animate(ani1, "fast");
		// $("#img1").animate(ani1, "slow");
		// $("#img1").animate(ani2, "slow");
		// $("#img1").animate(ani3, "slow");
		// $("#img1").animate(ani4, "slow");
		$("#img1").animate(ani1, "slow")
		          .animate(ani2, "slow")
		          .animate(ani3, "slow", function(){
		        	  alert("애니메이션 종료");
		          });
	}
</script>
</head>
<body>
	<button onclick="set_animate()">
		애니메이션 설정
	</button>
	<br/>
	<img src="image/thm.jpg" id="img1"
	     width="120" height="150"/><br/>
</body>
</html>











