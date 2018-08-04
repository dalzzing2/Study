<%@ page contentType="text/json; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// ajax 통신을 위해 브라우저가 생성한 값을 추출
	String callback = request.getParameter("callback");
	//String callback = request.getParameter("key");
	System.out.println(callback);
%>
<%-- callback값을 되돌려준다. --%>
<%=callback%>(
{
	"data1" : 100,
	"data2" : 200,
	"data3" : 300
}
);