<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 파라미터 데이터에 한글이 있을 수 있으므로...
	request.setCharacterEncoding("utf-8");
	// 데이터를 추출
	String data1 = request.getParameter("data1");
	String data2 = request.getParameter("data2");
	String [] data3 
			= request.getParameterValues("data3");
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>파라미터 데이터 추출 예제</title>
</head>
<body>
	data1 : <%=data1%><br/>
	data2 : <%=data2%><br/>
<%  if(data3 != null){ %>
<%     for(String str : data3){ %>
	     data3 : <%=str%><br/>
<%     } %>	
<%  } %>
</body>
</html>










