<%@ page contentType="text/plain; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
	// 파라미터 데이터를 받는다.
	String name = request.getParameter("name");
	String age = request.getParameter("age");
	String addr = request.getParameter("addr");
%>
이름 : <%=name%>, 나이 : <%=age%>, 주소 : <%=addr%>
