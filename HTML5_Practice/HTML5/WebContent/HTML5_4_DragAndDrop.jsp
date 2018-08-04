<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Drag And Drop</title>
<style>
	#dropbox {
		width : 300px;
		height : 300px;
		border : 1px black solid;
	}
</style>
<script>
	function dragEnter(event){
		// 이벤트 버블링 차단
		// 이벤트 버블링 : 발생된 사건에 대한 정보가
		// 브라우저로 전달되는 개념
		event.stopPropagation();
		event.preventDefault();
	}
	function dragExit(event){
		event.stopPropagation();
		event.preventDefault();
	}
	function dragOver(event){
		event.stopPropagation();
		event.preventDefault();
	}
	function drop(event){
		event.stopPropagation();
		event.preventDefault();
		// 파일을 추출
		var file = event.dataTransfer.files[0];
		// 파일 이름을 출력한다.
		file_name.innerHTML = "파일 이름 : " + file.name;
		// 파일에서 데이터를 읽어온다.
		var reader = new FileReader();
		// 파일 읽기가 완료되면 호출되는 함수 등록
		reader.onloadend = function(event){
			// 파일에서 읽어온 내용을 출력
			file_data.innerHTML = event.target.result;
			// 이미지 데이터를 img 태그에 설정한다.
			image_view.src = event.target.result;
		}
		// 읽어온다.
		 reader.readAsDataURL(file);
		// 텍스트 파일...
		// reader.readAsText(file);
	}
	window.onload = function(){
		// 이벤트 셋팅
		// 드래그해서 들어 왔을 때
		dropbox.ondragenter = dragEnter;
		// 드래그해서 들어 왔다가 나갈 때
		dropbox.ondragexit = dragExit;
		// 드래그 해서 머물러 있을 때
		dropbox.ondragover = dragOver;
		// 드랍했을때
		dropbox.ondrop = drop;
	}
</script>
</head>
<body>
	<div id="dropbox">
		여기에 이미지를 넣어주세요
	</div>
	<div id="file_name"></div>
	<div id="file_data"></div>
	<img src="" id="image_view"/>
</body>
</html>











