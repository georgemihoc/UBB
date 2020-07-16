<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 6 - logged in</title>
</head>
<body>

  <?php
  session_start();
    if(!isset($_SESSION["user"])){
      exit("Acces denied");
    }
  ?>

	<form action="6logout.php" method="post">
    	<input type="submit" value="logout" name="Logout">
  </form>
  <?php
      $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
      $con->set_charset("utf8");

      if(isset($_GET["moderateButton"])){
        $idDb = $_REQUEST["moderateButton2"];

        $stmt = $con->prepare("UPDATE comments SET moderated=1 WHERE id=?");
        $stmt->bind_param('s', $idDb);
        $stmt->execute();
      }
      if(isset($_GET["moderateButton3"])){
        $idDb = $_REQUEST["moderateButton4"];

        $stmt = $con->prepare("DELETE FROM comments WHERE id=?");
        $stmt->bind_param('s', $idDb);
        $stmt->execute();
      }
   ?>


	<?php


	$sql = "SELECT id,user,comment FROM comments WHERE moderated = 0";
  	$result = $con->query($sql);
  	while ($row = $result->fetch_assoc()) {
      $idDb = $row['id'];
    	$userDb = $row['user'];
    	$commentDb = $row['comment'];
      echo $userDb . ": " . $commentDb;
      echo "<form action=" . "\"" . "6logged.php" . "\"" . " method=" . "\"" . "GET" . "\"><input type=" . "\"" . "submit" . "\"" . "name=" . "\"" . "moderateButton" . "\"" . "value=" . "\"" . "Accept" . "\"" . ">" . "<input type=" . "\"" . "hidden" . "\"" . " name=" . "\"" . "moderateButton2" . "\"" . "value=" . "\"" . $idDb . "\"" . "readonly>" .  "</form>";
      echo "<form action=" . "\"" . "6logged.php" . "\"" . " method=" . "\"" . "GET" . "\"><input type=" . "\"" . "submit" . "\"" . "name=" . "\"" . "moderateButton3" . "\"" . "value=" . "\"" . "Remove" . "\"" . ">" . "<input type=" . "\"" . "hidden" . "\"" . " name=" . "\"" . "moderateButton4" . "\"" . "value=" . "\"" . $idDb . "\"" . "readonly>"  . "</form>";

      echo "<br>";
    }

	?>

</body>

</html>
