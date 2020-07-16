<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 1</title>
</head>
<body>

  <?php
     session_start();
     // echo $_SESSION['pageNr'];
  ?>

	<form action ="1.php" method="POST">
		<select name="nrElements">
      <option value="blank"></option>
			<option <?php if ($_POST["nrElements"] == 1) { ?>selected="true" <?php }; ?> value="1">1</option>
			<option <?php if ($_POST["nrElements"] == 2) { ?>selected="true" <?php }; ?> value="2">2</option>
			<option <?php if ($_POST["nrElements"] == 3) { ?>selected="true" <?php }; ?> value="3">3</option>
			<option <?php if ($_POST["nrElements"] == 4) { ?>selected="true" <?php }; ?> value="4">4</option>
		</select>

		<input type="submit" value="Afiseaza produse">
    <input type="submit" name="buttonType" value="Previous">
    <input type="submit" name="buttonType" value="Next">

	</form>

  <br>

  <?php
  error_reporting(E_ERROR | E_PARSE);
  $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
  $con->set_charset("utf8");

  $var = $_POST["nrElements"];
  $buttonType = $_POST["buttonType"];

  $sql = "SELECT * FROM notebooks";
  $result = $con->query($sql);
  $sql2 = "SELECT COUNT(*) FROM notebooks";
  $nrInregistrari_query = $con->query($sql2);
  $nrInregistrari = $nrInregistrari_query -> fetch_array();
  $ok = 0;
  if($buttonType == ""){
    $number = 0;
    $_SESSION["pageNr"] = 1;
    $ok = 1;
  }
  elseif ($buttonType == "Next") {
      if($_SESSION["pageNr"] <= floor($nrInregistrari[0] / $var)+1){
        $_SESSION["pageNr"] = $_SESSION["pageNr"] + 1;
        $number = 0;
        $number = ($number + $var) * ($_SESSION["pageNr"] - 1);
        $ok = 1;
      }

  }
  elseif ($buttonType == "Previous") {
      if($_SESSION["pageNr"] > 1){
        $_SESSION["pageNr"] = $_SESSION["pageNr"] - 1;
        $number = 0;
        $number = ($_SESSION["pageNr"] - 1) * $var;
        $ok = 1;

      }
  }
  $index = 0;
  while ($row = $result->fetch_assoc() ) {
    if($ok ==1){
       $id = $row['id'];
       $producator = $row['producator'];
       $procesor = $row['procesor'];
       if(floor($number / $var) + 1 == $_SESSION['pageNr'] && $number == $index || ($buttonType == "" && $number < $var && $number > 0)){
         echo "<tr><td>$id </td><td>$producator </td><td>$procesor</td><br>";
         $number = $number + 1;
       }
       $index = $index + 1;
     }

  }


  ?>

</body>
</html>
