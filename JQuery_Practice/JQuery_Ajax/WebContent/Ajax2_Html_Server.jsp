<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%
	request.setCharacterEncoding("utf-8");

	String name = request.getParameter("name");
	String age = request.getParameter("age");
	String addr = request.getParameter("addr");
%>
name : <%=name%><br/>
age : <%=age%><br/>
addr : <%=addr%><br/>