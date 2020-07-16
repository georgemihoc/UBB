<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 5</title>
</head>
<body>


	<form action ="5.php" method="POST">
		<label for="user">User:</label>
    <input type="text" name="userInput" value="">
    <br>
    <label for="password">Password:</label>
    <input type="password" name="passwordInput" value="">
    <br>
		<input type="submit" name="login" value="Login">


	</form>

  <?php
    if(isset($_POST['login'])){
      error_reporting(E_ERROR | E_PARSE);
      $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
      $con->set_charset("utf8");

      $formUser = addslashes(htmlentities($_POST['userInput'], ENT_COMPAT, "UTF-8"));
      $formPassword = addslashes(htmlentities($_POST['passwordInput'], ENT_COMPAT, "UTF-8"));


      $stmt = $con->prepare("SELECT username FROM users WHERE username = ? and password = ?");

       $stmt->bind_param('ss', $formUser,$formPassword);
       $stmt->execute();

       $stmt->bind_result($ignored);
  		 $count = 0;
    	 while($stmt->fetch()){
    			$count = $count + 1;
    	 }
       if ($count != 1) {
           echo "Invalid credentials";
        }
        else{
          session_start();
          $_SESSION["user"] = $formUser;
          header("Location: 5logged.php");
        }
    }
  ?>


</body>
</html>
