<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="c" 
           uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>if문 등등</title>
</head>
<body>
	<c:set var="a" value="100"/>
	<%-- if : test속성에 true, false를 넣어준다 --%>
	<c:if test='true'>
		true입니다<br/>
	</c:if>
	<c:if test='false'>
		false입니다<br/>
	</c:if>
	<%-- 조건식 --%>
	<c:if test='${a > 10}'>
		a는 10보다 큽니다<br/>
	</c:if>
	<c:if test='${a < 200}'>
		a는 200보다 작습니다<br/>
	</c:if>
	<%-- 특정 이름의 값이나 객체가 있는지 확인 --%>
	<c:if test='${empty a}'>
		a라는 이름의 값이 없습니다<br/>
	</c:if>
	<c:if test='${empty b}'>
		b라는 이름의 값이 없습니다<br/>
	</c:if>
	<c:if test='${not empty a}'>
		a라는 이름의 값이 있습니다<br/>
	</c:if>
	<c:if test='${not empty b}'>
		b라는 이름의 값이 있습니다<br/>
	</c:if>
	<%-- 객체 비교 --%>
	<c:set var="str1" value="안녕하세요"/>
	<c:if test='${str1 == "안녕하세요"}'>
		== 비교 : str1은 안녕하세요 입니다<br/>
	</c:if>
	<c:if test='${str1 eq "안녕하세요"}'>
		eq 비교 : str1은 안녕하세요 입니다<br/>
	</c:if>
	<%-- null 여부 판단 --%>
	<%
		//null인 참조 변수 선언
		StringBuffer buf = null;
	%>
	<c:set var="str_buf" value="<%=buf%>"/>
	<c:if test='${str_buf == null}'>
		== 비교 : str_buf는 null입니다<br/>
	</c:if>
	<c:if test='${str_buf eq null}'>
		eq 비교 : str_buf는 null입니다<br/>
	</c:if>
	<%-- 여러 조건 문 --%>
	<c:choose>
		<%-- if(a == 1){ --%>
		<c:when test="${a == 1}">
			a는 1입니다<br/>
		</c:when>
		<%-- } else if(a == 2){ --%>
		<c:when test="${a == 2}">
			a는 2입니다<br/>
		</c:when>
		<%-- } else { --%>
		<c:otherwise>
			a는 1, 2가 아닙니다<br/>
		</c:otherwise>
	</c:choose>
</body>
</html>












