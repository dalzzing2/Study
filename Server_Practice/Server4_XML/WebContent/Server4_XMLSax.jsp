<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.net.*" %>
<%@ page import="java.util.*" %>
<%@ page import="javax.xml.parsers.*" %>
<%@ page import="org.xml.sax.*" %>
<%@ page import="org.xml.sax.helpers.*" %>
<%@ page import="parser.*" %>
<%@ page import="bean.*" %>
<%
	//접속할 페이지의 주소
	String site = "http://localhost:8080/Server4_XML/"
			    + "Server4_XMLDataEx.jsp";
	URL url = new URL(site);
	// 데이터를 담을 빈 객체 생성
	SaxBean bean = new SaxBean();
	// 파싱 작업을 처리할 객체 생성
	XmlHandler handler = new XmlHandler(bean);
	// 파서 생성
	SAXParserFactory factory 
			= SAXParserFactory.newInstance();
	SAXParser sp = factory.newSAXParser();
	XMLReader xr = sp.getXMLReader();
	// 파싱 시작
	xr.setContentHandler(handler);
	xr.parse(new InputSource(url.openStream()));
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>SAX Parsing</title>
</head>
<body>
	school_name : <%=bean.school_name %><br/>
	school_addr : <%=bean.school_addr %><br/>
	school_cnt : <%=bean.school_cnt %><br/>
	
	<% 
		for(int i = 0 ; i < bean.attr_grade.size() ; i++){ 
			out.print("---------------------<br/>");
			out.print("grade : ");
			out.print(bean.attr_grade.get(i) + "<br/>");
			out.print("class_cnt : ");
			out.print(bean.attr_class_cnt.get(i) + "<br/>");
		} 
	
		for(int i = 0 ; i < bean.class_number.size() ; i++){
			String class_number = bean.class_number.get(i);
			String class_member_cnt
							= bean.class_member_cnt.get(i);
			String class_boss_name 
							= bean.class_boss_name.get(i);
			String class_president
							= bean.class_president.get(i);
			
			out.print("class_number : ");
			out.print(class_number + "<br/>");
			out.print("class_member_cnt : ");
			out.print(class_member_cnt + "<br/>");
			out.print("class_boss_name : ");
			out.print(class_boss_name + "<br/>");
			out.print("class_president : ");
			out.print(class_president + "<br/>");
		}
	%>
</body>
</html>















