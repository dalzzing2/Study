<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.io.*" %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>물리적인 파일의 경로 얻어오기</title>
</head>
<body>
	<%
		// 읽어올 파일
		String file = "/data/data.txt";
		// 물리적인 경로를 얻어온다.
		String path = application.getRealPath(file);
	%>
	파일 위치 : <%=path%><br/>
	<%
		// 파일과 연결되어 있는 스트림을 추출
		// FileInputStream fis = new FileInputStream(path);
		InputStream fis 
				= application.getResourceAsStream(file);
		InputStreamReader isr = new InputStreamReader(fis, "utf-8");
		BufferedReader br = new BufferedReader(isr);
		String str = null;
		StringBuffer buf = new StringBuffer();
		// 라인단위로 읽어온다.
		do{
			str = br.readLine();
			if(str != null){
				buf.append(str + "<br/>");
			}
		} while(str != null);
		// 읽어온 데이터를 String으로 추출한다.
		String data = buf.toString();
		br.close();
	%>
	<%= data %>
</body>
</html>











