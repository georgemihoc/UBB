<%@ page import ="java.sql.*" %>
<%@ page import ="javax.sql.*" %>
<%@ page import="java.sql.DriverManager"%>

<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 1</title>
  <body>
    <b>Admin login</b><br>

    <form action="1.jsp" method="post">

    Username :<input type="text" name="username" />
    <br>
    Password :<input type="password" name="password" />
    <br>
    <input type="submit" name="login" value="Login"/>

    </form>

    <%
    String driver = "com.mysql.jdbc.Driver";
    Class.forName(driver);
    java.sql.Connection con = DriverManager.getConnection("jdbc:mysql://localhost/db?serverTimezone=UTC","root","");

    String loginButton = request.getParameter("login");
    if(loginButton!=null && loginButton.equals("Login")){

      String username=request.getParameter("username");
      String password=request.getParameter("password");
      if(!username.equals("") && !password.equals("")){
        Statement st= con.createStatement();
        ResultSet rs=st.executeQuery("SELECT * FROM users");
        while(rs.next())
        {

          if(rs.getString("username").equals(username) && rs.getString("password").equals(password)){
            session.setAttribute("user","ok");
            response.sendRedirect("1logged.jsp");
          }
        }
        %>
          Invalid credentials
        <%
      }

    }

    %>

     <br><br>
    <b>Article</b>
  <br>
  <div>The 16-inch MacBook Pro (2019) has the keyboard every Apple laptop should have. And I'm glad that Apple has brought it to the MacBook Air, as superior ergonomic comfort should not be a premium feature. There are plenty of other reasons to splurge on this laptop, including its vivid 16-inch display with narrower bezels, amazing audio system and epic battery life.

      This is also a very powerful notebook, thanks to the combination of Core i9 muscle, gobs of RAM and one of the fastest SSDs in a laptop. It's up to you to decide how much oomph you need — and how much extra you're willing to pay above the $2,399 starting price. The only strikes against the 16-inch MacBook Pro are the sheer expense and the lack of legacy ports that some pros would appreciate.

      If you're on the fence between Windows and macOS, the Dell XPS 15 is a compelling MacBook Pro alternative, as it offers comparable performance, a keyboard with even more travel and an OLED display for hundreds less. But if you are set on a Mac and demand a large canvas for work and play, the 16-inch MacBook Pro should satisfy for years to come.
  <div>

  <br>



<br>
<b>Add a comment</b><br>
<form action="1.jsp" method="post" >

	User:<input type="text" name="user">
	<br>
	Comment:
	<br>
	<textarea name="comment"></textarea>
	<br>
	<input type="submit" name="addComment" value="Add">


</form>
<br>
<b>User comments</b><br><br>


<%
    Statement st= con.createStatement();
    ResultSet rs=st.executeQuery("SELECT * FROM comments WHERE moderated=1");
    while(rs.next())
    {
          %>
            <tr>
                  <td><b><%=rs.getString("user") %>: </b></td>
                  <td><%=rs.getString("comment") %></td>
            </tr>
            <br>
          <%
    }
%>

<%
String addButton = request.getParameter("addComment");
if(addButton!=null && addButton.equals("Add"))
{
	String user = request.getParameter("user");
	String comment = request.getParameter("comment");
	if(!user.equals("") && !comment.equals("")) {
		PreparedStatement ps = con.prepareStatement("INSERT INTO comments (user,comment,moderated) VALUES (?,?,?)");
    int moderated = 0;
    ps.setString(1, user);
		ps.setString(2, comment);
		ps.setInt(3, moderated);
		ps.execute();
	}
}
%>



</body>
</html>
