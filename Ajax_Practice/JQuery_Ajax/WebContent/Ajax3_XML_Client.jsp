<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>xml 데이터 가져오기</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_xml(){
		$.ajax({
			url : "Ajax3_XML_Server.jsp",
			type : "post",
			dataType : "xml",
			success : function(data){
				// xml 데이터를 가녀오면 최상위 루트 태그 객체가 매개변수로 들어온다. dom 방식
				// member 태그 객체를 얻어온다.
				var member = $(data).find("member");
				// member 태그의 개수만큼 반복한다.
				$(member).each(function(index, item){
					// member 안에 있는 태그의 데이터를 가져온다.
					var user_id = $(item).find("user_id");
					var user_pw = $(item).find("user_pw");
					var user_name = $(item).find("user_name");
					
					var str1 = $(user_id).text();
					var str2 = $(user_pw).text();
					var str3 = $(user_name).text();
					
					$("#result").append("user_id : " + str1 + "<br/>");
					$("#result").append("user_pw : " + str2 + "<br/>");
					$("#result").append("user_name : " + str3 + "<br/>");
				});
			}
		});
	}
</script>
</head>
<body>
	<button onclick="get_xml()">xml 데이터 가져오기</button>
	<div id="result"></div>
</body>
</html>