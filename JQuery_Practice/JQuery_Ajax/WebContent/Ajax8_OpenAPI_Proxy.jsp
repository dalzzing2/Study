<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
<%-- jQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>
	function get_places(){
		// 현재 위치를 측정한다.
		navigator.geolocation.getCurrentPosition(success, error);	
	}
	function success(position){
		// 위도 경도를 추출
		var lat = position.coords.latitude;
		var lng = position.coords.longitude;
		// Proxy를 ajax로 요청한다.
		var param = {
				lat : lat,
				lng : lng
		}
		$.ajax({
			url : "Ajax8_OpenAPI_Sub.jsp",
			dataType : "json",
			data : param,
			type : "post",
			success : function(data){
				if(data.status == "OK"){
					// results 배열의 개수만큼 반복
					$(data.results).each(function(index, item){
						// 데이터 추출
						var lat = item.geometry.location.lat;
						var lng = item.geometry.location.lng;
						var name = item.name;
						var vicinity = item.vicinity;
						
						$("#result").append("위도 : " + lat + "<br/>");
						$("#result").append("경도 : " + lng + "<br/>");
						$("#result").append("이름 : " + name + "<br/>");
						$("#result").append("주소 : " + vicinity + "<br/>");
						$("#result").append("<br/>");

					});
				}else{
					$("#result").html("오류입니다<br/>");
				}
			}
		});
	}
	function error(e){
		alert(e);
	}
	function get_places_data(lat, lng){
		
	}
</script>
</head>
<body>
	<%--
		구글 주변 정보 사용하기
		1. http://console.developers.google.com 에 접속한다.
		2. 로그인
		3. 좌측 상단 메뉴를 클릭하고 "API 관리자"를 선택한다.
		4. 만든 프로젝트가 없다면 프로젝트를 만들어준다.
		5. API 목록에서 "Google Maps API"에 있는
		   "Google Places API Web Service"를 클릭한다.
		6. 상단 부분에 있는 "API 사용 설정"을 클릭한다.
		7. "자세히 알아보기"를 클릭한다.
		8. 다음에서 "안내"를 클릭한다.
		9. "Places API 웹 서비스 사용 예"에서 "장소 검색"을
		   클릭한다.
		   https://developers.google.com/places/web-service/search?hl=ko
           여기에서 접속할 페이지의 주소, 파라미터, 응답 결과 양식을
           파악한다.		
           
        키 발급 받기
        1. 좌측 상단 메뉴에서 "API 관리자"를 클릭한다.
        2. 좌측에서 "사용자 인증 정보"를 클릭한다.
        3. "사용자 인증 정보 추가"를 클릭한다.
        4. 메뉴에서 "API 키"를 클릭한다.
        5. "새키 만들기"에서 "브라우저 키"를 눌러준다.   
	 --%>
	 <button onclick="get_places()">주변 정보 가져오기</button>
	 <div id="result"></div>
</body>
</html>