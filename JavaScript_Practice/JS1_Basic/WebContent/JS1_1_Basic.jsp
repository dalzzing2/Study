<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>자바 스크립트 작성 방법</title>
<%-- 
	임베디드 방식
	jsp 파일에 직접 자바 스크립트 코드를 작성하는 방식 
--%>
<script>
	console.log("임베디드 방식");
</script>
<%-- 외부 파일 추가 --%>
<%-- src 속성에 파일을 지정하게 되면 지정된 파일의
	내용이 script 태그 사이에 덮어 씌어진다.
	이전의 코드는 모두 사라진다.
 --%>
<script src="js/JS1_1_Basic.js">
	console.log("이 부분이 실행될까요?");
</script>
</head>
<body>
	<%-- 인라인 방식 --%>
	<button onclick="console.log('인라인 방식');">
		인라인 방식
	</button>
</body>
</html>














