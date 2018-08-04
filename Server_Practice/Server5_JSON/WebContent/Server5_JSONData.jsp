<%@ page contentType="text/json; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%
Class.forName("oracle.jdbc.OracleDriver");
String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
String db_id = "scott";
String db_pw = "1234";
//데이터 베이스 접속
Connection conn
	= DriverManager.getConnection(db_url, db_id, db_pw);
// 쿼리문
String sql = "select * from jdbc_board_table";
Statement stmt = conn.createStatement();
ResultSet rs = stmt.executeQuery(sql);
%>
<%--
	정수 : 100
	불리언 : true / false
	실수 : 55.55
	문자열 : "안녕하세요"
	객체 : { }
	배열 : [ ]
 --%>
 [
 <% boolean chk = rs.next(); %>
 <% while(chk){ %>
  {
  	"board_idx" : <%= rs.getInt("board_idx") %>,
  	"board_subject" : "<%=rs.getString("board_subject")%>",
  	"board_content" : "<%=rs.getString("board_content")%>",
  	"board_show" : <%=rs.getInt("board_show")%>,
  	"user_id" : "<%=rs.getString("user_id")%>"
  }
  <% 
  	// 다음 것을 접근한다.
  	chk = rs.next();
   	// 다음 것이 있다면 , 를 찍어준다
  	if(chk == true){
  		out.print(",");
  	}
  %>
 <% } %>
 ]
 
 
 
 
 
 
 
 
 
 
 
 
 
