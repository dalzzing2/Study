<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.net.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>쿠키 읽어오기</title>
</head>
<body>
	<%
		// 쿠키를 추출
		Cookie [] array = request.getCookies();
		// 쿠키의 개수 만큼 반복
		for(Cookie c : array){
			// 쿠키의 이름을 추출
			String name = c.getName();
			// 쿠키의 값을 추출
			String value = c.getValue();
			value = URLDecoder.decode(value, "utf-8");
			// 출력한다.
			out.write(name + " : " + value + "<br/>");
		}
		// 이름으로 쿠키 탐색
		for(Cookie c : array){
			// 쿠키의 이름을 비교
			if(c.getName().equals("data2")){
				String value = c.getValue();
				value = URLDecoder.decode(value, "utf-8");
				out.write("data2 : " + value + "<br/>");
			}
		}
	%>
</body>
</html>








