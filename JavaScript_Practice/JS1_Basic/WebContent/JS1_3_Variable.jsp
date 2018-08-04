<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>자바 스크립트 변수</title>
<script>
	window.onload = function(){
		// id가 result인 태그를 얻어온다.
		var result = document.getElementById("result");
		var str;
		// 변수 선언
		var a;
		var b = 10;
		
		str = "a : " + a + "<br/>";
		str += "b : " + b + "<br/>";
		//str += "c : " + c + "<br/>";
		// 변수 a 가 undefined인지 확인이 필요할 경우
		if(a == undefined){
			str += "a는 undefined 입니다<br/>";
		}
		// 문자열
		var str1 = "안녕하세요";
		var str2 = '안녕하세요';
		str += "str1 : " + str1 + "<br/>";
		str += "str2 : " + str2 + "<br/>";
		// 따옴표를 가지고 있는 문자열
		var str3 = "이름은 '홍길동' 입니다";
		var str4 = '이름은 "홍길동" 입니다';
		str += "str3 : " + str3 + "<br/>";
		str += "str4 : " + str4 + "<br/>";
		// 섞어서 사용하기
		var str5 = "이름은 \"홍길동\" 나이는 '30세'";
		var str6 = '이름은 \'최길동\' 나이는 "50세"';
		
		str += "str5 : " + str5 + "<br/>";
		str += "str6 : " + str6 + "<br/>";
		// 배열
		// 길이가 0인 배열
		var array1 = [];
		// 갯수가 3개인 배열
		var array2 = [10, 20, 30];
		str += "array1 : " + array1 + "<br/>";
		str += "array2 : " + array2 + "<br/>";
		str += "array1의 개수 : " + array1.length + "<br/>";
		str += "array2의 개수 : " + array2.length + "<br/>";
		// 배열에 맴버를 추가
		array1[0] = 100;
		str += "array1의 개수 : " + array1.length + "<br/>";
		str += "array1[0] : " + array1[0] + "<br/>";
		
		array1[10] = 1000;
		str += "array1의 개수 : " + array1.length + "<br/>";
		str += "array1 : " + array1 + "<br/>";
		
		// 배열 객체가 제공하는 메서드
		// 배열의 데이터를 , 로 구분한 문자열로 추출
		var s1 = array2.toString();
		str += "s1 : " + s1 + "<br/>";
		// 구분자를 변경하여 문자열을 추출
		var s2 = array2.join("^");
		str += "s2 : " + s2 + "<br/>";
		// 배열에 요소를 추가한다.
		array2[3] = 40;
		array2[4] = 50;
		str += "array2 : " + array2 + "<br/>";
		
		array2.push(60);
		array2.push(70);
		array2.push(80, 90, 100, 110, 120, 130, 140);
		str += "array2 : " + array2 + "<br/>";
		// 정렬
		var array3 = ["홍길동", "이순신", "강감찬",
		              "을지문덕", "전우치"];
		str += "정렬전 : " + array3 + "<br/>";
		
		array3.sort();
		str += "정렬후 : " + array3 + "<br/>";
		
		array3.reverse();
		str += "뒤집기 : " + array3 + "<br/>";
	
		
		result.innerHTML = str;	
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>




