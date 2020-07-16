<%@ page import ="java.sql.*" %>
<%@ page import ="javax.sql.*" %>
<%@ page import="java.sql.DriverManager"%>
<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 1 - logged</title>
  <body>
    <form action="1logged.jsp" method="POST">
    	<input type="submit" name="logoutButton" value="Logout" >
  </form>
    <%

      if(session.getAttribute("user") == null){
        response.sendRedirect("1.jsp");
      }


      String driver = "com.mysql.jdbc.Driver";
      Class.forName(driver);
      java.sql.Connection con = DriverManager.getConnection("jdbc:mysql://localhost/db?serverTimezone=UTC","root","");

      String logoutButton = request.getParameter("logoutButton");
      if(logoutButton!=null && logoutButton.equals("Logout")){
        response.sendRedirect("1.jsp");
      }

    %>


    <%

    String addButton = request.getParameter("moderateButton");
    String removeButton = request.getParameter("moderateButton3");

    if(addButton!=null && addButton.equals("Accept"))
    {
      int idComment = Integer.parseInt(request.getParameter("moderateButton2"));
      PreparedStatement ps = con.prepareStatement("UPDATE comments SET moderated=1 where id=?");
      int moderated = 0;
  		ps.setInt(1, idComment);
  		ps.execute();
    }else if(removeButton!=null && removeButton.equals("Remove")){
      int idComment = Integer.parseInt(request.getParameter("moderateButton4"));
      PreparedStatement ps = con.prepareStatement("DELETE FROM comments where id=?");
      int moderated = 0;
  		ps.setInt(1, idComment);
  		ps.execute();
    }

    %>

    <%
    %><b>Comments</b> <br><%
    Statement st= con.createStatement();
    ResultSet rs=st.executeQuery("SELECT * FROM comments WHERE moderated=0");
    while(rs.next())
    {
          %>
            <tr>
                  <td><b><%=rs.getString("user") %>: </b></td>
                  <td><%=rs.getString("comment") %></td>
            </tr>
            <form action="1logged.jsp" method="POST">
              <input type="submit" name="moderateButton" value="Accept">
              <input type="hidden" name="moderateButton2" value=<%=rs.getString("id") %> readonly>
            </form>
            <form action="1logged.jsp" method="POST">
              <input type="submit" name="moderateButton3" value="Remove">
              <input type="hidden" name="moderateButton4" value=<%=rs.getString("id") %> readonly>
            </form>
            <br>
          <%
    }

    %>



</body>
</html>
