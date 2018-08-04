<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ page import="java.io.*"%>
<%@ page import="java.net.*"%>
<%@ page trimDirectiveWhitespaces="true"%>
<%
	// 위도와 경도를 파라미터로 받는다.
	// request.getCharacterEncoding("utf-8");
	String lat = request.getParameter("lat");
	String lng = request.getParameter("lng");
	
	// 접속할 페이지의 주소
	String site = "https://maps.googleapis.com/maps/api/place/"
	            + "nearbysearch/json"
				+ "?key=AIzaSyDisX-tFSyi5BfytmEm3X3J5h-aOq7E6CM"
				+ "&location=" + lat + "," + lng
				+ "&radius=1000"
				+ "&sensor=false"
				+ "&language=ko"
				+ "&types=food";
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