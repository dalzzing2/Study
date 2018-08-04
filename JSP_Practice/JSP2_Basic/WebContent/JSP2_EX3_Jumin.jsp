<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>주민등록 번호 검증</title>
</head>
<body>
	<%
		// 주민 번호
		int [] jumin = {7, 8, 1, 2, 1, 7, 1, 0, 
				3, 0, 5, 3, 9
		};
		// 각 자리수에 곱할 숫자
		int [] target = {2, 3, 4, 5, 6, 7, 8, 9, 
				2, 3, 4, 5
		};
		// 각 자리수를 곱한다.
		int total = 0;
		for(int i = 0 ; i < jumin.length - 1 ; i++){
			// 각 자리수를 곱하고 누적한다.
			total = total + (jumin[i] * target[i]);
		}
		// 누적한 총합을 11로 나눈 나머지를 구한다.
		int data1 = total % 11;
		// 11을 나머지로 빼준다.
		int data2 = 11 - data1;
		// 10로 나눈 나머지를 구한다.
		int data3 = data2 % 10;
		
		if(data3 == jumin[12]){
			out.write("옳바른 주민 번호 입니다<br/>");
		} else {
			out.write("옳바른 주민 번호가 아닙니다<br/>");
		}
	%>
</body>
</html>










