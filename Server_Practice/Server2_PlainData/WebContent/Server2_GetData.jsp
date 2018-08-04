<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.net.*" %>
<%@ page import="java.io.*" %>
<%
	// 접속할 페이지의 주소
	String site = "http://localhost:8080/"
				+ "Server2_PlainData/"
	            + "Server2_PlainData.jsp";

	//접속할 페이지를 관리할 URL 객체를 만들어준다.
	URL url = new URL(site);
	// 서버에 접속
	URLConnection conn = url.openConnection();
	// 데이터를 받아오기 위한 스트림을 추출
	InputStream is = conn.getInputStream();
	// 라인단위로 입력받기 위한 필터 스트림을 연결
	InputStreamReader isr 
				= new InputStreamReader(is, "utf-8");
	BufferedReader br = new BufferedReader(isr);
	// 데이터를 담아놓을 StringBuffer 생성
	StringBuffer buf = new StringBuffer();
	String str = null;
	// 문서의 마지막 까지 읽어온다.
	do{
		str = br.readLine();
		if(str != null){
			buf.append(str);
		}
	} while(str != null);
	// 스트림을 닫는다.
	br.close();
	// 읽어온 데이터를 문자열로 변환한다.
	String data = buf.toString();
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>문자열 데이터 받아오기</title>
</head>
<body>
	받아온 문자열 데이터 : <%= data %>
</body>
</html>






