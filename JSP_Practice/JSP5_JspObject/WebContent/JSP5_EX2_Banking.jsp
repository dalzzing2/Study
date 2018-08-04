<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>장기하 저금하기</title>
</head>
<body>
	<%
		/*
			장기하가 저금을 한다.
			첫날 100원을 저금.
			2일차 부터는 전날 잔고액의 3배를 저금한다.
			1일차~30일차까지의 통장 잔고액을 출력한다.
			조건 : int형 자료형만 사용한다.
			       Math클래스 사용 금지.....
		*/
	%>
	<table border="1">
		<tr>
			<td>1일차</td>
			<td align="right">100원</td>
		</tr>
<%		
		int banking1 = 100;
		int banking2 = 0;
		int banking3 = 0;
%>
<%		for(int i = 2 ; i <= 30 ; i++){ %>
<%
		// 전날 잔고액의 3배를 저금한다(4를 곱한다)
		banking1 = banking1 * 4;
		banking2 = banking2 * 4;
		banking3 = banking3 * 4;
		// Overflow 처리
		banking2 = banking2 + (banking1 / 100000000);
		banking1 = banking1 % 100000000;
		
		banking3 = banking3 + (banking2 / 100000000);
		banking2 = banking2 % 100000000;
		// 각 자리수의 문자열을 만들어준다.
		String num1 = String.format("%08d", banking1);
		String num2 = String.format("%08d", banking2);
%>
		<tr>
			<td><%=i%>일차</td>
		<%	if(banking3 == 0 && banking2 == 0){ %>			
			<td align="right"><%=banking1%>원</td>
		<%  } else if(banking3 == 0){ %>
			<td align="right"><%=banking2%><%=num1%>원</td>
		<%  } else { %>
			<td align="right"><%=banking3%><%=num2%><%=num1%>원</td>
		<%  } %>
		</tr>
<%		} %>
	</table>
</body>
</html>










