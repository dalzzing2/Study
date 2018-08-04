<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>함수</title>
<script>
	
	var result;

	window.onload = function(){
		result = document.getElementById("result");
		// 함수 호출
		f1();
		f2();
		// 함수를 변수에 담는다.
		var f3 = f1;
		f3();
		// 반환값이 있는 함수를 호출
		var r1 = f4();
		result.innerHTML += "반환된 값 : " + r1 + "<br/>";
		// 함수 호출
		f5();
		f5(10);
		f5(10, 20);
		f5(10, 20, 30);
		f5(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
		
		f6();
		f6(10);
		f6(10, 20);
		f6(10, 20, 30);
		f6(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
		
		// 함수를 매개변수로 넘긴다.
		f7(f8);
		// 익명 함수 사용하기
		f7(function(a1, a2){
			var a3 = a1 * a2;
			result.innerHTML += "a3 : " + a3 + "<br/>";
		});
		
		// 내부에 함수를 가지고 있는 함수를 호출
		f9();
		// f9 내부에 만든 함수를 호출
		f10();
	}
	// 일반적인 함수 구현 방법
	function f1(){
		result.innerHTML += "f1 함수 호출<br/>";
	}
	// 익명 함수
	var f2 = function(){
		result.innerHTML += "f2 함수 호출<br/>";
	}
	// 값을 반환하는 함수
	function f4(){
		return 100;
	}
	// 매개 변수를 가지고 있는 함수
	function f5(a, b){
		result.innerHTML += "a : " + a + "<br/>";
		result.innerHTML += "b : " + b + "<br/>";
		result.innerHTML += "--------------<br/>";
	}
	// arguments 배열 사용
	function f6(){
		result.innerHTML += " 값의 개수 : " + arguments.length + "<br/>";
		for(var i = 0 ; i < arguments.length ; i++){
			result.innerHTML += arguments[i] + ",";
		}
		result.innerHTML += "<br/>";
		result.innerHTML += "-----------------------------------<br/>";
	}
	// 함수를 매개 변수로 받는다.
	function f7(a){
		// 매개 변수로 들어온 함수를 호출한다.
		a(100, 200);
	}
	// f7을 호출할 때 넘겨줄 함수
	function f8(a1, a2){
		var a3 = a1 + a2;
		result.innerHTML += "f8 : " + a3 + "<br/>"; 
	}
	// 함수안의 함수
	function f9(){
		function f10(){
			result.innerHTML += "f10함수 호출<br/>";
		}
		// 내부의 함수를 호출
		f10();
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>





