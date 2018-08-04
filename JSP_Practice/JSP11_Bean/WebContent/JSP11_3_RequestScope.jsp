<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%-- scope가 request인 자바 빈 객체 생성 --%>
<jsp:useBean id="bean" class="bean.MemberBean"
             scope="request"/>
<jsp:setProperty 
		name="bean" property="name" value="최길동"/>
<jsp:setProperty
		name="bean" property="age" value="20"/>
<jsp:setProperty
		name="bean" property="gender" value="2"/>
<%-- 다음 페이지로 포워딩 한다. --%>
<jsp:forward page="JSP11_3_Result.jsp"/>
<%
	// 빈객체 생성 및 데이터 셋팅
//	MemberBean bean = new MemberBean();
//	bean.setName("최길동");
//	bean.setAge(20);
//	bean.setGender(2);
	// request에 빈 객체를 담는다.
//	request.setAttribute("bean", bean);
	// 다음 페이지로 포워딩 한다.
//	String site = "JSP11_3_Result.jsp";
//	RequestDispatcher dis 
//				= request.getRequestDispatcher(site);
//	dis.forward(request, response);
%>
