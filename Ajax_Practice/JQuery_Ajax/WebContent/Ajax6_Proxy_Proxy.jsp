<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ page import="java.io.*"%>
<%@ page import="java.net.*"%>
<%
	// 파라미터로 접속할 페이지의 주소를 받는다.
	String site = request.getParameter("site");
	// URL 객체 생성
	URL url = new URL(site);
	// 접속
	URLConnection conn = url.openConnection();
	// 스트림을 추출한다.
	InputStream is = conn.getInputStream();
	InputStreamReader isr = new InputStreamReader(is, "utf-8");
	BufferedReader br = new BufferedReader(isr);
	// 읽어온다.
	String str = "";
	StringBuffer buf = new StringBuffer();
	do{
		str = br.readLine();
		if(str != null){
			buf.append(str);
		}
	}while(str != null);
%>
<%=buf.toString()%>