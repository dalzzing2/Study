<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// jsp:include 태그로 다른 페이지를 포함할 경우
	// 파라미터 한글 처리를 해줘야 한다.
	request.setCharacterEncoding("utf-8");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<jsp:include page="JSP6_2_Sub/JSP6_2_Top.jsp">
	<jsp:param value="너네집 소개" name="title"/>
</jsp:include>
			<tr>
				<jsp:include page="JSP6_2_Sub/JSP6_2_Menu.jsp">
					<jsp:param value="3" name="menu"/>
				</jsp:include>
				<td>
					너네집 소개 입니다.
				</td>
			</tr>
			<jsp:include page="JSP6_2_Sub/JSP6_2_Footer.jsp"/>
		</table>
	</center>
</body>
</html>









