<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSON 가져오기</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_json(){
		$.ajax({
			url : "Ajax4_JSON_Server.jsp";
			dataType : "json",
			type : "post",
			success : function(data){
				// root 배열의 개수만큼 반복한다.
				$(data).each(function(index, item){
					$("#result").append(item.user_id + "<br/>");
					$("#result").append(item.pw_id + "<br/>");
					$("#result").append(item.pw_name + "<br/>");
				});
			}
		});
	}
</script>
</head>
<body>
	<button onclick="get_json()">JSON 가져오기</button>
	<div id="result"></div>
</body>
</html>