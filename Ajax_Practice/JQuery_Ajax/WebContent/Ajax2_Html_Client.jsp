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
		// 파리미터 데이터
		var param = {
				name : $("#name").val(),
				age : $("#age").val(),
				addr : $("#addr").val()
		};
		$.ajax({
			url : "Ajax2_Html_Server.jsp",
			type : "post",
			dataType : "html",
			data : param,
			success : function(data){
				$("#result").html(data);
			}
		});
	}
</script>
</head>
<body>
	<input type="text" id="name" placeholder="name"/><br/>
	<input type="text" id="age" placeholder="age"/><br/>
	<input type="text" id="addr" placeholder="addr"/><br/>
	<button onclick="get_data()">데이터 가져오기</button>
	<div id="result"></div>
</body>
</html>