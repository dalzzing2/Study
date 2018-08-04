<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%@ taglib prefix="c" 
           uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.util.*" %>
<%@ page import="bean.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSTL Core Set</title>
</head>
<body>
<%
	// scope
	// page : 같은 JSP에서만 사용 가능한 영역
	// request : forward할 경우 다른 JSP/Servlet에서 사용
	//           가능
	// session : 브라우저가 같을 경우 사용 가능
	// application : 서버를 종료할 때 까지 사용 가능
	// Java 코드 
	request.setAttribute("data1", "문자열1");
	pageContext.setAttribute("data2", "문자열2");
	session.setAttribute("data3", "문자열3");
	application.setAttribute("data4", "문자열4");
%>
<%-- jstl --%>
<c:set var="data5" value="문자열5" scope="request"/>
<c:set var="data6" value="문자열6" scope="page"/>
<c:set var="data7" value="문자열7" scope="session"/>
<c:set var="data8" value="문자열8" scope="application"/>
<%-- 자바코드(표현식)으로 출력 --%>
<%
String data11 = (String)request.getAttribute("data1");
String data22 = (String)pageContext.getAttribute("data2");
String data33 = (String)session.getAttribute("data3");
String data44 = (String)application.getAttribute("data4");

String data55 = (String)request.getAttribute("data5");
String data66 = (String)pageContext.getAttribute("data6");
String data77 = (String)session.getAttribute("data7");
String data88 = (String)application.getAttribute("data8");
%>
----------------------- JSP 코드<br/>
data1 : <%=data11%><br/>
data2 : <%=data22%><br/>
data3 : <%=data33%><br/>
data4 : <%=data44%><br/>
data5 : <%=data55%><br/>
data6 : <%=data66%><br/>
data7 : <%=data77%><br/>
data8 : <%=data88%><br/>
--------------------- el 출력 ---------------<br/>
data1 : ${requestScope.data1}<br/>
data2 : ${pageScope.data2}<br/>
data3 : ${sessionScope.data3}<br/>
data4 : ${applicationScope.data4}<br/>
data5 : ${data5}<br/>
data6 : ${data6}<br/>
data7 : ${data7}<br/>
data8 : ${data8}<br/>
------------------------- Bean 사용하기 <br/>
<%
	// 자바 코드를 이용해 빈 객체를 생성
	JSP15_TestBean t1 = new JSP15_TestBean();
	//t1.setInt_data(100);
	//t1.setString_data("안녕하세요");
	//t1.setDouble_data(55.55);
%>
<%-- jstl에서 자바에 선언된 변수를 통해 객체를 사용 --%>
<c:set target="<%=t1%>" property="int_data" value="200"/>
<c:set target="<%=t1%>" property="string_data"
						value="반갑습니다"/>
<c:set target="<%=t1%>" property="double_data"
						value="77.77"/>
<%= t1.getInt_data() %><br/>
<%= t1.getString_data() %><br/>
<%= t1.getDouble_data() %><br/>
<%-- JSP 액션 태그를 이용해 객체를 사용 --%>
<jsp:useBean id="t2" class="bean.JSP15_TestBean"/>
<%--
<jsp:setProperty property="int_data" name="t2"
                 value="300"/>
<jsp:setProperty property="string_data" name="t2"
				 value="감사합니다"/>
<jsp:setProperty property="double_data" name="t2"
                 value="88.88"/>
 --%>
<c:set target="${t2}" property="int_data" value="400"/>
<c:set target="${t2}" property="string_data" 
                   value="배고파요"/>
<c:set target="${t2}" property="double_data" value="99.99"/>

${t2.int_data}<br/>
${t2.string_data}<br/>
${t2.double_data}<br/>
-------------------------최종 빈 사용하기<br/>
<% JSP15_TestBean t3 = new JSP15_TestBean(); %>
<jsp:useBean id="t4" class="bean.JSP15_TestBean"/>
<%-- jstl에서 객체를 사용할 수 있도록 셋팅 --%>
<c:set var="t5" value="<%=t3%>"/>
<c:set var="t6" value="${t4}"/>
<c:set target="${t5}" property="int_data" value="1"/>
<c:set target="${t5}" property="string_data" value="가"/>
<c:set target="${t5}" property="double_data" value="1.1"/>
<c:set target="${t6}" property="int_data" value="2"/>
<c:set target="${t6}" property="string_data" value="나"/>
<c:set target="${t6}" property="double_data" value="2.2"/>
${t5.int_data}<br/>
${t5.string_data}<br/>
${t5.double_data}<br/>
${t6.int_data}<br/>
${t6.string_data}<br/>
${t6.double_data}<br/>
----------------------- HashMap<br/>
<%
	HashMap<String, String> map
				= new HashMap<String, String>();
	map.put("data1", "데이터1");
	map.put("data2", "데이터2");
	map.put("data3", "데이터3");
%>
<%-- JSTL 에서 맵을 사용하기위해 셋팅한다. --%>
<c:set var="map" value="<%=map%>"/>
data1 : ${map.data1}<br/>
data2 : ${map.data2}<br/>
data3 : ${map.data3}<br/>

</body>
</html>










