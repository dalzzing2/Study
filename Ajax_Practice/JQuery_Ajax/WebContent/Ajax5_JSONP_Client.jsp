<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSONP 사용하기</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_jsonp(){
		$.ajax({
			// C:\Windows\System32\drivers\etc 의 host 파일
			url : "http://abc.com:8080/JQuery_Ajax/Ajax5_JSONP_Server.jsp",
			// 도메인이 다를 경우 브라우저는 ajax를 거부한다.
			// 만약 dataType에 jsonp라고 넣어주면
			// callback이라는 파라미터 이름으로 브라우저가 생성
			// 한 값을 서버로 넘겨주고 이값이 그대로 다시 돌아
			// 온다면 ajax를 허용한다.
			dataType : "jsonp",
			// 만약 서버에서 callback 값을 다른 이름으로 받는다면
			// 서버에서 사용하는 이름으로 맞춰줘야 한다.
			// jsonp : "key",
			type : "post",
			success : function(data){
				$("#result").append(data.data1 + "<br/>");
				$("#result").append(data.data2 + "<br/>");
				$("#result").append(data.data3 + "<br/>");
			}
		});
	}
</script>
</head>
<body>
	<button onclick="get_jsonp()">JSONP 가져오기</button>
	<div id="result"></div>
</body>
</html>