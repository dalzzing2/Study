<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>WebStorage</title>
<script>
	function save_data(){
		// 저장
		window.localStorage.a1 = save_local.value;
		window.sessionStorage.a2 = save_session.value;
		
	}
	function load_data(){
		result.innerHTML 
			= "local : " + window.localStorage.a1 + "<br/>"
			+ "session : " + window.sessionStorage.a2 + "<br/>";
	}
</script>
</head>
<body>
	로컬 : <input type="text" id="save_local"/><br/>
	세션 : <input type="text" id="save_session"/><br/>
	<button onclick="save_data()">저장</button>
	<button onclick="load_data()">읽어오기</button>
	<div id="result"></div>
</body>
</html>








