<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// HTMLBasic2_Result.jsp
	// 파라미터 한글 처리
	request.setCharacterEncoding("utf-8");
	// 파라미터 추출
	String a1 = request.getParameter("a1");
	String a2 = request.getParameter("a2");
	String a3 = request.getParameter("a3");
	String [] a4 = request.getParameterValues("a4");
	String a5 = request.getParameter("a5");
	String a6 = request.getParameter("a6");
	String a7 = request.getParameter("a7");
	String a8 = request.getParameter("a8");
	String a9 = request.getParameter("a9");
	String a10 = request.getParameter("a10");
	String a11 = request.getParameter("a11");
	String a12 = request.getParameter("a12");
	String a13 = request.getParameter("a13");
	String a14 = request.getParameter("a14");
	String a15 = request.getParameter("a15");
	String a16 = request.getParameter("a16");
	String a17 = request.getParameter("a17");
	String a18 = request.getParameter("a18");
	String a19 = request.getParameter("a19");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>데이터 받기</title>
</head>
<body>
	a1 : <%=a1%><br/>
	a2 : <%=a2%><br/>
	a3 : <%=a3%><br/>
<%  if(a4 != null){ %>
<%  for(String str : a4){ %>
	a4 : <%=str%><br/>
<%  } %>
<%  } %>
	a5 : <%=a5%><br/>
	a6 : <%=a6%><br/>
	a7 : <%=a7%><br/>
	a8 : <%=a8%><br/>
	a9 : <%=a9%><br/>
	a10 : <%=a10%><br/>
	a11 : <%=a11%><br/>
	a12 : <%=a12%><br/>
	a13 : <%=a13%><br/>
	a14 : <%=a14%><br/>
	a15 : <%=a15%><br/>
	a16 : <%=a16%><br/>
	a17 : <%=a17%><br/>
	a18 : <%=a18%><br/>
	a19 : <%=a19%><br/>
</body>
</html>












