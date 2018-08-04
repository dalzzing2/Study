<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>String 객체 사용하기</title>
<script>
	window.onload = function(){
		var result = document.getElementById("result");
		
		var str1 = "better tomorrow";
		// 문자열 찾기
		// 앞에서 부터 찾기
		result.innerHTML += str1.indexOf("t") + "<br/>";
		// 앞에서 6번째 글자에서 부터 찾기
		result.innerHTML += str1.indexOf("t", 5) + "<br/>";
		// 뒤에서 부터 찾기 (결과는 찾은 글자의 앞에서 부터의 인덱스 번호)
		result.innerHTML += str1.lastIndexOf("t") + "<br/>";
		// 앞에서 6번째 글자에서 부터 뒤로 찾기
		result.innerHTML += str1.lastIndexOf("t", 5) + "<br/>";
		
		// 문자열 자르기
		// 문자열 자체가 잘라지기 보다는 잘려진 문자열을 반환
		var str2 = "JavaScript";
		// 5번째에서 8-1번째 까지
		result.innerHTML += str2.substring(5, 8) + "<br/>";
		// 5번째에서 3개
		result.innerHTML += str2.substr(5, 3) + "<br/>";
		// 구분자를 지정하여 문자열을 잘라낸다.
		var str3 = str2.split("s");
		for(var i in str3){
			result.innerHTML += str3[i] + "<br/>";
		}
	}
</script>
</head>
<body>
	<div id="result"></div>
</body>
</html>