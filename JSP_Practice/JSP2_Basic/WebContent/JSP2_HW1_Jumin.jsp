<%@ page contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>  
<html>
<head>
<meta charset="UTF-8">
<title>과제_주민등록 번호 생성기</title>
</head>
<body>
<%
		/*
				과제 : 생년월일과 성별을 입력받아 가능한 주민번호 생성하기
		*/
		int[] jumin = { 9, 1, 0, 2, 0, 6, 1, 0, 0, 0, 0, 0, 0 };
		int[] target = { 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5 };

		for (int a8 = 0; a8 <= 9; a8++) { //7
			for (int a9 = 0; a9 <= 9; a9++) { //8
				for (int a10 = 0; a10 <= 9; a10++) { //9
					for (int a11 = 0; a11 <= 9; a11++) { //10
						for (int a12 = 0; a12 <= 9; a12++) { //11
							for (int a13 = 0; a13 <= 9; a13++) { //12
								// 각 자리수를 곱한다.
								int total = 0;
								for (int i = 0; i < jumin.length - 1; i++) {
									// 각 자리수를 곱하고 누적한다.
									total = total + (jumin[i] * target[i]);
								}
								// 누적한 총합을 11로 나눈 나머지를 구한다.
								int data1 = total % 11;
								// 11을 나머지로 빼준다.
								int data2 = 11 - data1;
								// 10 로 나눈 나머지를 구한다.
								int date3 = data2 % 10;

								if (date3 == jumin[12]) {
									for (int j = 0; j < 13; j++) {
	%>
	<%=jumin[j]%>
	<%
		}
									out.write("<br/>");
								} else {
									//out.write("올바른 주민 번호가 아닙니다.<br/>");
								}

								jumin[12]++;
							}
							jumin[11]++;
							jumin[12] = 0;
						}
						jumin[10]++;
						jumin[11] = 0;
						jumin[12] = 0;
					}
					jumin[9]++;
					jumin[10] = 0;
					jumin[11] = 0;
					jumin[12] = 0;
				}
				jumin[8]++;
				jumin[9] = 0;
				jumin[10] = 0;
				jumin[11] = 0;
				jumin[12] = 0;
			}
			jumin[7]++;
			jumin[8] = 0;
			jumin[9] = 0;
			jumin[10] = 0;
			jumin[11] = 0;
			jumin[12] = 0;
		}
	%>
</body>
</html>