<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Proxy 사용하기</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_proxy(){
		var param = {
				site : "https://github.com/"
		}
		$.ajax({
			url : "Ajax6_Proxy_Proxy.jsp",
			dataType : "html",
			data : param,
			type : "post",
			success : function(data){
				$("#result").html(data);
			}
		});
	}
</script>
</head>
<body>
	<button onclick="get_proxy()">프락시 사용하기</button>
	<div id="result"></div>
</body>
</html>