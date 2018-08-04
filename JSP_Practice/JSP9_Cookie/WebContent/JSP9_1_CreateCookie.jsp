<%@page import="java.net.URLEncoder"%>
<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>쿠키 저장하기</title>
</head>
<body>
	<%
		// 쿠키는 유니코드를 저장할 수 없으므로
		// 한글 저장시에는 인코딩을 해줘야 한다.
		String str1 = URLEncoder.encode("안녕하세요", "utf-8");
		String str2 = URLEncoder.encode("반갑습니다", "utf-8");
		// 쿠키 객체 생성
		Cookie c1 = new Cookie("data1", str1);
		Cookie c2 = new Cookie("data2", str2);
		// 수명을 지정한다(초단위, 1년)
		c1.setMaxAge(365 * 24 * 60 * 60);
		c2.setMaxAge(365 * 24 * 60 * 60);
		// 쿠키를 응답결과에 추가한다.
		response.addCookie(c1);
		response.addCookie(c2);
	%>
	쿠키 저장 완료
</body>
</html>










