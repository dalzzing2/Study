<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.*" %>
<%@ page import="java.io.*" %>
<%@ page import="java.net.*" %>
<%@ page import="javax.xml.parsers.*" %>
<%@ page import="org.w3c.dom.*" %>
<%
	// 데이터를 담아놓을 컬렉션
	HashMap<String, Object> data_map
					= new HashMap<String, Object>();
	// 접속할 페이지의 주소
	String site = "http://localhost:8080/Server4_XML/"
			    + "Server4_XMLDataEx.jsp";
	URL url = new URL(site);
	// 접속
	URLConnection conn = url.openConnection();
	// 스트림 추출
	InputStream is = conn.getInputStream();
	// DOM 방식으로 분석을 할 수 있는 객체 생성
	DocumentBuilderFactory factory
				= DocumentBuilderFactory.newInstance();
	DocumentBuilder builder
				= factory.newDocumentBuilder();
	// 분석
	Document doc = builder.parse(is);
	// root를 가져온다.
	Element school = doc.getDocumentElement();
	// 데이터 추출
	NodeList school_name_list 
			= doc.getElementsByTagName("school_name");
	NodeList school_addr_list
			= doc.getElementsByTagName("school_addr");
	NodeList school_cnt_list
			= doc.getElementsByTagName("school_cnt");
	// 태그 객체 가져온다.
	Element school_name_tag
			= (Element)school_name_list.item(0);
	Element school_addr_tag
			= (Element)school_addr_list.item(0);
	Element school_cnt_tag
			= (Element)school_cnt_list.item(0);
	// 문자열 데이터 추출
	String school_name = school_name_tag.getTextContent();
	String school_addr = school_addr_tag.getTextContent();
	String school_cnt = school_cnt_tag.getTextContent();
	// HashMap에 담아준다
	data_map.put("school_name", school_name);
	data_map.put("school_addr", school_addr);
	data_map.put("school_cnt", school_cnt);
	// School_grade를 담을 ArrayList
	ArrayList<HashMap<String, Object>> grade_list
			= new ArrayList<HashMap<String, Object>>();
	data_map.put("school_grade_list", grade_list);
	// school_grade 태그를 추출
	NodeList school_grade_list 
			= doc.getElementsByTagName("school_grade");
	// School_grade 태그 개수만큼 반복
	for(int i = 0 ; i < school_grade_list.getLength() ; i++){
		// i 번째 태그 객체를 추출
		Element school_grade_tag
					= (Element)school_grade_list.item(i);
		// 속성 추출
		String grade = school_grade_tag.getAttribute("grade");
		String class_cnt 
				= school_grade_tag.getAttribute("class_cnt");
		// class 태그 추출
		NodeList class_list
				= school_grade_tag.getElementsByTagName("class");
		// class에서 추출한 정보를 담을 ArrayList
		ArrayList<HashMap<String, String>> class_list2
			= new ArrayList<HashMap<String, String>>();
		for(int k = 0 ; k < class_list.getLength() ; k++){
			// i 번째 class 태그 객체를 추출
			Element class_tag = (Element)class_list.item(i);
			// 데이터 추출
			NodeList class_number_list
				= class_tag.getElementsByTagName("class_number");
			NodeList class_member_cnt_list
			 = class_tag.getElementsByTagName("class_member_cnt");
			NodeList class_boss_name_list
			   = class_tag.getElementsByTagName("class_boss_name");
			NodeList class_president_list
				= class_tag.getElementsByTagName("class_president");
			
			Element class_number_tag
						= (Element) class_number_list.item(0);
			Element class_member_cnt_tag
					= (Element) class_member_cnt_list.item(0);
			Element class_boss_name_tag
					= (Element) class_boss_name_list.item(0);
			Element class_president_tag
					= (Element) class_president_list.item(0);
				
			HashMap<String, String> class_map
							= new HashMap<String, String>();
			class_map.put("class_number", 
						class_number_tag.getTextContent());
			class_map.put("class_member_cnt",
						class_member_cnt_tag.getTextContent());
			class_map.put("class_boss_name", 
						class_boss_name_tag.getTextContent());
			class_map.put("class_president", 
						class_president_tag.getTextContent());			
			
			class_list2.add(class_map);
			
		}
		
		// 데이터를 담을 해시 맵
		HashMap<String, Object> school_grade_map
						= new HashMap<String, Object>();
		school_grade_map.put("grade", grade);
		school_grade_map.put("class_cnt", class_cnt);
		school_grade_map.put("class_list", class_list2);
		
		grade_list.add(school_grade_map);
	}
	
	
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>XML DOM 분석</title>
</head>
<body>
	<%= data_map.get("school_name") %><br/>
	<%= data_map.get("school_addr") %><br/>
	<%= data_map.get("school_cnt") %><br/>
	<%
		// 리스트 추출
		ArrayList<HashMap<String, Object>> grade_list2
			= (ArrayList<HashMap<String, Object>>) 
					data_map.get("school_grade_list");
		for(HashMap<String, Object> map2 : grade_list2){
			String grade = (String)map2.get("grade");
			String class_cnt = (String)map2.get("class_cnt");
			out.print(grade + "<br/>");
			out.print(class_cnt + "<br/>");
			
			ArrayList<HashMap<String, String>> class_list3
				= (ArrayList<HashMap<String, String>>)
					map2.get("class_list");
			for(HashMap<String, String> map3 : class_list3){
				String class_number = map3.get("class_number");
				String class_member_cnt
							= map3.get("class_member_cnt");
				String class_boss_name
							= map3.get("class_boss_name");
				String class_president
							= map3.get("class_president");
				out.print(class_number + "<br/>");
				out.print(class_member_cnt + "<br/>");
				out.print(class_boss_name + "<br/>");
				out.print(class_president + "<br/>");
			}
		}
	%>
</body>
</html>








