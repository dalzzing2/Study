<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>캡슐화</title>
<script>
	window.onload = function(){
		var result = document.getElementById("result");
		// 생성자 함수
		function Test(){
			this.a1 = 100;
			this.a2 = 200;
			// 외부에서 접근하지 못하는 변수
			var a3 = 300;
			var a4 = 400;
			// setter, getter
			this.setA3 = function(_a3){
				a3 = _a3;
			}
			this.getA3 = function(){
				return a3;
			}
			this.setA4 = function(_a4){
				a4 = _a4;
			}
			this.getA4 = function(){
				return a4;
			}
		}
		
		var t1 = new Test();
		result.innerHTML = "t1.a1 : " + t1.a1 + "<br/>";
		result.innerHTML += "t1.a2 : " + t1.a2 + "<br/>";
		// var를 통해 선언한 변에는 접근이 불가능
		result.innerHTML += "t1.a3 : " + t1.a3 + "<br/>";
		result.innerHTML += "t1.a4 : " + t1.a4 + "<br/>";
		// 제공되는 set과 get을 이용하여 맴버에 접근한다.
		t1.setA3(5000);
		t1.setA4(6000);
		
		result.innerHTML += "t1.a3 : " + t1.getA3() + "<br/>";
		result.innerHTML += "t1.a4 : " + t1.getA4() + "<br/>";
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>







