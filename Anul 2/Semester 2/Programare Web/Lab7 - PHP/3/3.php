<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 3</title>
</head>
<body>

  <?php

    error_reporting(E_ERROR | E_PARSE);
    $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
    $con->set_charset("utf8");

    $sql = "SELECT * FROM grades";
    $result = $con->query($sql);
    echo "<b>Grades</b>";
    echo "<br>";
    while ($row = $result->fetch_assoc() ) {
      $id = $row['id'];
      $elev = $row['elev'];
      $materie = $row['materie'];
      $nota = $row['nota'];
      echo "<tr><td>$elev </td><td>$materie </td><td>$nota</td><br>";
    }
    echo "<br>";


   ?>
	<form action ="3.php" method="POST">
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
          $_SESSION["ok"] = "ok";
          header("Location: 3logged.php");
        }
    }
  ?>


</body>
</html>
