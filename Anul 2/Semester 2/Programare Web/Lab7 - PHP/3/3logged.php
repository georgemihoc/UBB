<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 3 - logged in</title>
</head>
<body>



  <?php
  session_start();
    if(!isset($_SESSION["ok"])){
      exit("Acces denied");
    }
  ?>

	<form action ="3logged.php" method="POST">
		<label for="elev">Elev:</label>
    <input type="text" name="elevInput" value="">
    <br>
    <label for="materie">Materie:</label>
    <input type="text" name="materieInput" value="">
    <br>
    <label for="nota">Nota:</label>
    <input type="number" name="notaInput" value="">
    <br>
		<input type="submit" name="add" value="Add nota">


	</form>
  <form action="3logout.php" method="POST" >
    <input type="submit" value="Logout" name="logout">
  </form>

  <?php
    if(isset($_POST['add'])){
      error_reporting(E_ERROR | E_PARSE);
      $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
      $con->set_charset("utf8");

      $formElev = addslashes(htmlentities($_POST['elevInput'], ENT_COMPAT, "UTF-8"));
      $formMaterie = addslashes(htmlentities($_POST['materieInput'], ENT_COMPAT, "UTF-8"));
      $formNota = addslashes(htmlentities($_POST['notaInput'], ENT_COMPAT, "UTF-8"));

      $stmt = $con->prepare("SELECT title FROM subjects WHERE title = ?");
  		$stmt->bind_param('s', $formMaterie);
  		$stmt->execute();
      $count = 0;
      while($stmt->fetch()){
         $count = $count + 1;
      }
      if($formNota > 0 && $formNota<=10){

        if( $count == 1){
          $stmt = $con->prepare("INSERT INTO grades (elev, materie, nota) VALUES (?,?,?)");
      		$stmt->bind_param('sss', $formElev,$formMaterie,$formNota);
      		$stmt->execute();
      		$stmt->close();
        }
        else{
          echo "Materie inexistenta";
        }
      }
      else{
        echo "Nota invalida";
      }

    }
  ?>


</body>
</html>
