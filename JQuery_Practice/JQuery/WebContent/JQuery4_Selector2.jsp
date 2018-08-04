<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>셀렉터 2</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	$(function(){
		// 태그 내의 모든 h1 태그를 선택(자손, 하위)
		$("div h1").css("background", "yellow");
		// 태그 내의 작계 하위 h1 태그를 선택(자식)
		$("div > h1").css("color", "red");
	});
	
	function get_text(){
		// input 태그의 값은 val() 함수를 이용하면 가져올 수 있다.
		// type 속성이 text인 input 태그의 값을 가져온다.
		var str = $("input[type=text]").val();
		$("#result1").html(str + "<br/>");
	}
	function cal(){
		// 사용자가 입력한 값을 가지고 온다.
		var num1 = $("#number1").val();
		var num2 = $("#number2").val();
		// 더한다
		var num3 = num1 + num2;
		// 출력
		$("#result2").html(num3);
	}
	function get_selected(){
		// checkbox, radio의 경우 : checked
		// select 의 경우 : selected
		// name이 list인 select 태그의 option 태그 중에서
		// 선택되어 있는 태그의 값을 가지고 온다.
		var op = $("select[name=list] > option:selected");
		$("#result3").html(op.val() + "<br/>");
		
		var op2 = $("#items > option:selected");
		$("#result3").append(op.val() + "<br/>");
	}
</script>
</head>
<body>
	<div>
		<ul>
			<li><h1>항목1</h1></li>
			<li>항목2</li>
			<li>항목3</li>
		</ul>
	</div>
	
	<input type="text"/><br/>
	<input type="password"/><br/>
	<button onclick="get_text()">문자열 가져오기</button>
	<div id="result1"></div>
	
	<input type="text" id="number1" placeholder="숫자1"/><br/>
	<input type="text" id="number2" placeholder="숫자1"/><br/>
	<button onclick="cal()">더하기</button>
	<div id="result2"></div>
	
	<select name="list">
		<option value="1">항목1</option>
		<option value="2">항목2</option>
		<option value="3">항목3</option>
		<option value="4">항목4</option>
		<option value="5">항목5</option>
		<option value="6">항목6</option>
	</select>
	<button onclick="get_selected()">선택</button>
	<div id="result3"></div>
</body>
</html>