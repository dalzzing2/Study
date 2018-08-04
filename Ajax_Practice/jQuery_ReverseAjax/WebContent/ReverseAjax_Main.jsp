<%@ page contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ page import="java.sql.*"%>
<%
	String url = "jdbc:oracle:thin:@localhost:1521:orcl";
	String id = "scott";
	String pw = "1234";

	Class.forName("oracle.jdbc.OracleDriver");
	Connection db_con = DriverManager.getConnection(url, id, pw);
	String sql = "select max(CHAT_IDX) from JDBC_CHAT_TABLE";
	Statement stmt = db_con.createStatement();
	ResultSet rs = stmt.executeQuery(sql);
	
	int idx = 0;
	
	if(rs.next()){
		// 가져온 데이터가 있는 경우
		idx = rs.getInt(1);
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Reverse Ajax 예제</title>
<%-- JQuery CDN --%>
<script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
<script src="http://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>
<script>

	var js_idx = <%=idx%>;
	$(function() {
		// 일정시간마다 한번씩 새로 고침 해준다.
		setInterval(get_data, 1000);
	});
	// 서버에서 데이터를 가져와서 화면에 보여주는 함수
	function get_data() {
		var param = {
				idx : js_idx
		}
		$.ajax({
			url : "ReverseAjax_Out.jsp",
			type : "post",
			dataType : "json",
			data : param,
			success : function(data) {
				$("#result").html("");
				// 데이터의 개수만큼 반복
				$(data).each(function(index, item) {
					// 가장 최근의 글이 가장 처음에 있으므로 index가 0일 때 값을 설정해준다.
					if(index == 0){
						js_idx = item.chat_idx;
					}
					$("#result").append(item.chat_user + " : ");
					$("#result").append(item.chat_content + "<br/>");
					$("#result").append("--------------------<br/>");
					$("#result").html(str + $("#result").html());
				});
			}
		});
	}
	// 글 작성 함수
	function add_content() {
		// 입력한 데이터를 이용하여 파라미터 객체를 만든다.
		var param = {
			user_id : $("#user_id").val(),
			content : $("#content").val()
		}
		$.ajax({
			url : "ReverseAjax_Add.jsp",
			type : "post",
			data : param,
			success : function(data) {
				$("#content").val("");
			}
		});
	}
</script>
</head>
<body>
	<input type="text" id="user_id" placeholder="대화명" />
	<br />
	<textarea rows="5" cols="30" id="content"></textarea>
	<br />
	<button onclick="add_content()">글작성</button>
	<div id="result"></div>
</body>
</html>