<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>업로드 테스트</title>
</head>
<body>
	<form action="Server6_Cos.jsp" method="post" enctype="multipart/form-data">
		<input type="text" name="data1"/><br/>
		<input type="file" name="data2"/><br/>
		<button type="submit">업로드</button>		
	</form>
</body>
</html>