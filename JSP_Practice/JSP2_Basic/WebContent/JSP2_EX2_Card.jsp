<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.*" %>
<%--
	1 ~ 10까지의 숫자를 중복되지 않게
	랜덤하게 추출한다.
--%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>추첨 하기</title>
</head>
<body>
	<%
		// 추첨할 데이터를 담아준다.
		ArrayList<Integer> data_list 
						= new ArrayList<Integer>();
		for(int i = 0 ; i < 10 ; i++){
			data_list.add(i + 1);
		}
		// 데이터를 추첨한다.
		Random random = new Random();
		for(int i = 0 ; i < 10 ; i++){
			// 추첨할 데이터의 인덱스 번호를 랜덤하게
			// 추출한다.
			int value = random.nextInt(data_list.size());
			// 인덱스 번호의 데이터를 추출
			int data = data_list.get(value);
			out.write(data + "<br/>");
			// 추첨한 데이터는 제거
			data_list.remove(value);
		}
	%>
</body>
</html>




















