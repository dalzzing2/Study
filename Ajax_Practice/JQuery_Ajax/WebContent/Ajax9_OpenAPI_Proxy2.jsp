<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>네이버 OPEN API 사용하기</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_naver_data(){
		var param = {
			target : $("#target > option:selected").val(),
			query : $("#query").val()
		};
		$.ajax({
			url : "Ajax9_OpenAPI_Sub2.jsp",
			dataType : "xml",
			type : "post",
			data : param,
			success : function(data){
				// item 태그를 추출
				var item = $(data).find("item");
				$("#result").html("");
				// item의 개수만큼 반복
				$(item).each(function(index, item){
					// title과 link 태그 객체를 추출
					var title = $(item).find("title");
					var link = $(item).find("link");
					// 문자열 데이터 추출
					var str1 = $(title).text();
					var str2 = $(link).text();
					
					$("#result").append("<h3>" + str1 + "</h3>");
					$("#result").append("<a href='" + str2 + "' target='_blank'>자세히 보기</a><br/>");
				});
			}
		});
	}
</script>
</head>
<body>
	카테고리 : 
	<select id="target">
		<option value="blog">블로그</option>
		<option value="news">뉴스</option>
		<option value="book">책</option>
		<option value="encyc">백과사전</option>
		<option value="movie">영화</option>
		<option value="cafearticle">카페글</option>
		<option value="kin">지식인</option>
	</select>
	<br/>
	검색어 : <input type="text" id="query" placeholder="검색어"/>
	<br/>
	<button onclick="get_naver_data()">검색</button>
	<div id="result"></div>
</body>
</html>