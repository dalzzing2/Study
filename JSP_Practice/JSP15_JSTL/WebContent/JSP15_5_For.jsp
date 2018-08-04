<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c" 
           uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>For</title>
</head>
<body>
	<%-- 기본 for --%>
	<c:forEach var="i" begin="0" end="10">
		${i}&nbsp;
	</c:forEach>
	<br/>
	<c:forEach var="i" begin="0" end="10" step="2">
		${i}&nbsp;
	</c:forEach>
	<br/>
	<%-- 배열 --%>
	<%
		int [] array1 = {1, 2, 3, 4, 5};
	%>
	<c:set var="array1" value="<%=array1%>"/>
	array1[0] : ${array1[0]}<br/>
	array1[1] : ${array1[1]}<br/>
	<c:forEach var="i" begin="0" 
	                   end="<%=array1.length - 1 %>">
	     array1[${i}] : ${array1[i]}<br/>
	</c:forEach>
	<c:forEach var="i" items="${array1}" varStatus="idx">
		${idx.index} : ${i}&nbsp;
	</c:forEach>
	<br/>
	<%
		ArrayList<String> list
						= new ArrayList<String>();
		list.add("문자열1");
		list.add("문자열2");
		list.add("문자열3");
	%>
	<c:set var="list" value="<%=list%>"/>
	<c:forEach var="item" items="${list}">
		${item}&nbsp;
	</c:forEach>
	<br/>
	<%
		HashMap<String, String> map
					= new HashMap<String, String>();
		map.put("map1", "맵 문자열1");
		map.put("map2", "맵 문자열2");
		map.put("map3", "맵 문자열3");
	%>
	<c:set var="map" value="<%=map%>"/>
	${map.map1}&nbsp;
	${map.map2}&nbsp;
	${map.map3}&nbsp;
</body>
</html>










