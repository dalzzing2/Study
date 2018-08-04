<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	String menu = request.getParameter("menu");
%>
    
<td height="500" width="200">
<%  if(menu.equals("1")){ %>
	[회사소개]<br/>
<%  } else { %>
	<a href="JSP6_2_Page1.jsp">회사소개</a><br/>
<%  }  %>

<%  if(menu.equals("2")){ %>
	[우리집소개]<br/>
<%  } else { %>	
	<a href="JSP6_2_Page2.jsp">우리집소개</a><br/>
<%  } %>

<%  if(menu.equals("3")){ %>
	[너네집 소개]<br/>
<%  } else { %>
	<a href="JSP6_2_Page3.jsp">너네집소개</a><br/>
<%  } %>
</td>










