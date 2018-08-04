<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>상속</title>
<script>
	window.onload = function(){
		var result = document.getElementById("result");
		
		// 생성자 함수
		function Super(){
			this.a1 = 100;
			this.a2 = 200;
			this.a3 = function(){
				result.innerHTML += "Super.a3 메서드<br/>";
			}
		}
		function Sub(){
			this.a4 = 300;
			this.a5 = 400;
			this.a6 = function(){
				result.innerHTML += "Sub.a6 메서드<br/>";
			}
		}
		// Sub에 Super를 상속
		Sub.prototype = new Super();
		// 생성자 함수를 다시 설정해준다.
		Sub.prototype.constructor = Sub;
		// 객체를 생성
		var s1 = new Sub();
		result.innerHTML += "s1.a1 : " + s1.a1 + "<br/>";
		result.innerHTML += "s1.a2 : " + s1.a2 + "<br/>";
		result.innerHTML += "s1.a4 : " + s1.a4 + "<br/>";
		result.innerHTML += "s1.a5 : " + s1.a5 + "<br/>";
		s1.a3();
		s1.a6();	
		
		result.innerHTML += s1.constructor;
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>








