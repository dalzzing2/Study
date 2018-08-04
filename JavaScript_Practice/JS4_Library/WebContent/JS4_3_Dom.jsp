<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Dom</title>
<script>
	function get_input(){
		var result = document.getElementById("result");
		// 태그 이름을 통해서 가져온다.
		// 배열로 나온다.
		var inputs = document.getElementsByTagName("input");
		// name 속성을 통해서 가져온다.
		// 배열로 나온다.
		var input2 = document.getElementsByName("input2");
		// id 속성을 통해서 가져온다.(중요)
		// 단 하나만 나온다.
		var input1 = document.getElementById("input1");
		// 값을 가져와서 출력
		result.innerHTML += input1.value + "<br/>";
		result.innerHTML += input2[0].value + "<br/>";
		result.innerHTML += inputs[0].value + "<br/>";
		result.innerHTML += inputs[1].value + "<br/>";
		// form 태그 안에는 태그의 경우에는 다음과 같이
		// 접근하는게 가능하다.
		// document.form태그의 name속성.input태그의 name속성
		result.innerHTML += document.form1.input2.value + "<br/>";
	}
	function add_element(){
		/*
		result.innerHTML += "<a href='http://w3schools.com'>"
		                 + "w3schools.com"
		                 + "</a><br/>";
		*/
		// a 태그의 객체를 생성
		var anchor = document.createElement("a");
		// 속성을 설정
		anchor.href = "http://w3schools.com";
		// 태그 사이에 들어가는 문자열 노드 객체를 생성
		var str = document.createTextNode("w3schools.com");
		// 문자열 노드 객체를 a 태그 객체 하위에 포함시킨다.
		anchor.appendChild(str);
		// a 태그를 div 태그에 추가
		result.appendChild(anchor);
		// br 태그 생성
		var br = document.createElement("br");
		result.appendChild(br);
		
	}
</script>
</head>
<body>
	<div id="result"></div>
	<form name="form1">
		<input type="text" id="input1"/><br/>
		<input type="text" name="input2"/><br/>
	</form>
	<button onclick="get_input()">값 가져오기</button>
	<button onclick="add_element()">HTML 요소 추가</button>
</body>
</html>














