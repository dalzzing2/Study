<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c" 
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSTL 사용해 보기</title>
</head>
<body>
	<%
		String str1 = "안녕하세요";
	
		if(str1.equals("안녕하세요")){
	%>
			<%=str1%> 문자열<br/>
	<%			
		}
	%>
	<%-- page에 문자열을 설정한다. --%>
	<c:set var="str2" value="<%=str1%>"/>
	
	<c:if test="${str2 eq '안녕하세요'}">
		${str2} 문자열<br/>
	</c:if>
	
</body>
</html>









