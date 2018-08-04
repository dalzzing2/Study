<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>객체 사용하기</title>
<script>
	window.onload = function(){
		var result = document.getElementById("result");
		// 리터럴을 이용한 객체 생성(JSON)
		// 이 객체와 동일한 객체를 생성할 수 없다.
		var obj1 = {
			a1 : 100,
			"a2" : 10.23,
			a3 : "안녕하세요",
			a4 : true,
			a5 : [10, 20, 30],
			a6 : {
					b1 : 200,
					b2 : 300
			     },
			a7 : function(){
					result.innerHTML += "a7 호출<br/>";
			     },
			toString : function(){
							// 객체를 출력할 경우
							// toString 메서드에서 반환하는
							// 문자열을 출력한다.
							return "obj1 객체입니다<br/>";
			           }
		};
		result.innerHTML += "obj1 : " + obj1 + "<br/>";
		result.innerHTML += "obj1.a1 : " + obj1.a1 + "<br/>";
		result.innerHTML += "obj1.a2 : " + obj1.a2 + "<br/>";
		result.innerHTML += "obj1.a3 : " + obj1.a3 + "<br/>";
		result.innerHTML += "obj1.a4 : " + obj1.a4 + "<br/>";
		for(var i in obj1.a5){
			result.innerHTML += "obj1.a5[" + i + "] : "
			                 + obj1.a5[i] + "<br/>";
		}
		result.innerHTML += "obj1.a6.b1 : " 
		                 + obj1.a6.b1 + "<br/>";
		result.innerHTML += "obj1.a6.b2 : " 
						 + obj1.a6.b2 + "<br/>";
						 
		obj1.a7();
		
		result.innerHTML 
			+= "obj1['a1'] : " + obj1['a1'] + "<br/>";
		result.innerHTML
			+= "obj1['a2'] : " + obj1['a2'] + "<br/>";
			
		// 객체에 맴버 추가하기
		var obj2 = {};
		// 없는 맴버를 사용하기
		result.innerHTML += "obj2.a1 : " + obj2.a1 + "<br/>";
		// 맴버 추가
		obj2.a1 = 100;
		result.innerHTML += "obj2.a1 : " + obj2.a1 + "<br/>";
		// 메서드 추가
		obj2.a2 = function(){
			result.innerHTML += "obj2의 a2 함수 호출<br/>";
		}
		obj2.a2();
		// 생성자 함수를 이용하여 객체를 생성
		function Test(){
			// 만들어진 객체에 맴버를 추가
			this.a1 = 100;
			this.a2 = 200;
			this.a3 = function(){
				result.innerHTML 
					+= "Test로부터 만들어진 객체<br/>";
			}
		}
		// new를 이용해 객체를 생성하면 일단 비어있는
		// 객체가 생성되고 지정한 함수를 호출한다.
		var t1 = new Test();
		var t2 = new Test();
		result.innerHTML += "t1.a1 : " + t1.a1 + "<br/>";
		result.innerHTML += "t1.a2 : " + t1.a2 + "<br/>";
		result.innerHTML += "t2.a1 : " + t2.a1 + "<br/>";
		result.innerHTML += "t2.a2 : " + t2.a2 + "<br/>";
		t1.a3();
		t2.a3();
		
		t1.a1 = 2000;
		result.innerHTML += "t1.a1 : " + t1.a1 + "<br/>";
		result.innerHTML += "t2.a1 : " + t2.a1 + "<br/>";
		// Prototype을 통한 맴버 추가
		// 생성자 함수를 통해 객체가 생성이 되면
		// Prototype 영역을 사용할 수 있게 되고
		// 객체에 맴버가 없으면 Prototype 영역의 맴버를
		// 사용하게 된다.
		Test.prototype.a4 = 400;
		result.innerHTML += "t1.a4 : " + t1.a4 + "<br/>";
		result.innerHTML += "t2.a4 : " + t2.a4 + "<br/>";
		// 맴버를 추가하게 되면 더이상 Prototype의 영역의
		// 맴버를 사용하지 않는다.
		t1.a4 = 500;
		result.innerHTML += "t1.a4 : " + t1.a4 + "<br/>";
		result.innerHTML += "t2.a4 : " + t2.a4 + "<br/>";
		// 생성자 함수에 접근
		result.innerHTML += "생성자 함수 : " 
		                 + t1.constructor + "<br/>";
		// 생성자 함수를 통해 Prototype 영역에 접근
		result.innerHTML += "t1.constructor.prototype.a4 : "
		                 + t1.constructor.prototype.a4 + "<br/>";
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>









