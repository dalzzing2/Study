<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_data(){
		// 데이터를 전달할 파라미터 데이터
		/*
		var param = {
				name : $("#name").val(),
				age : $("#age").val(),
				addr : $("#addr").val()
		};*/
		var param = "name=" + $("#name").val()
			+ "&age=" + $("#age").val()
			+ "&addr=" + $("#addr").val();
		
		$.ajax({
			// 접속할 페이지의 주소
			url : "Ajax1_Text_Server.jsp",
			// 응답결과 타입
			dataType : "text",
			// 통신 방식
			type : "post",
			// 파라미터 데이터
			data : param,
			// 성공했을 때 호출될 함수
			success : function(data){
				$("#result").text(data);
			}
		});
	}
</script>
</head>
<body>
	<input type="text" id="name" placeholder="이름"/><br/>
	<input type="text" id="age" placeholder="나이"/><br/>	
	<input type="text" id="addr" placeholder="주소"/><br/>
	<button onclick="get_data()">데이터 가져오기</button>
	<div id="result"></div>
</body>
</html>