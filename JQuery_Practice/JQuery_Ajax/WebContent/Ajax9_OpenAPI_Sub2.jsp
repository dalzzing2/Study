<%@ page contentType="text/xml; charset=utf-8" pageEncoding="utf-8"%>
<%@ page trimDirectiveWhitespaces="true"%>
<%@ page import="java.io.*"%>
<%@ page import="java.net.*"%>
<%
	request.setCharacterEncoding("utf-8");
	String target = request.getParameter("target");
	String query = request.getParameter("query");
	query = URLEncoder.encode(query, "utf-8");
	// 접속할 페이지의 주소
	// String site = "http://openapi.naver.com/search"
	String site = "http://softcampus.co.kr:8080/"
		+ "edu/ajax_proxy.jsp"
		+ "?key=06cf3d9264af5a400979c6b6fe786fdd"
		+ "&target=" + target
		+ "&query=" + query;
	URL url = new URL(site);
	// 접속
	URLConnection conn = url.openConnection();
	// 스트림 추출
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