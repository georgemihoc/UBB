<!DOCTYPE html>
<html>
<body>

  <?php
  session_start();
    if(!isset($_SESSION["user"])){
      exit("Acces denied");
    }
  ?>


<form action="5logged.php" method="POST" enctype="multipart/form-data">
  Select image to upload:
  <input type="file" name="fileToUpload" id="fileToUpload">
  <input type="submit" value="Upload Image" name="submit">
</form>
<form action="5logout.php" method="POST" >
  <input type="submit" value="Logout" name="logout">
</form>

<?php

    error_reporting(E_ERROR | E_PARSE);
    $con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
    $con->set_charset("utf8");


    if(isset($_POST["submit"])) {
      $target_dir = "uploads/";
      $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
      $uploadOk = 1;
      $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

      $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
      if($check !== false) {
        echo "File is an image - " . $check["mime"] . ".";
        $uploadOk = 1;
      } else {
        echo "File is not an image.";
        $uploadOk = 0;
      }



      if ($uploadOk == 0) {
        echo "Sorry, your file was not uploaded.";
      } else {
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
          $filename = addslashes(htmlentities($_FILES["fileToUpload"]["name"], ENT_COMPAT, "UTF-8"));


          $stmt = $con->prepare("INSERT INTO pictures (user, filename) VALUES (?,?)");
      		$stmt->bind_param('ss', $_SESSION["user"], $filename);
      		$stmt->execute();
      		$stmt->close();
          echo "The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.";
        } else {
          echo "Sorry, there was an error uploading your file.";
        }
      }
    }


?>

<?php

    if(isset($_GET["deleteButton"])){
      echo "CEAU";
      $filename2 = $_REQUEST["deleteButton2"];
      echo $filename2;
      $stmt = $con->prepare("DELETE FROM pictures WHERE filename=?");
      $stmt->bind_param('s', $filename2);
      $stmt->execute();
      $stmt->close();
    }

 ?>

  <?php
      $sql = "SELECT * FROM pictures ORDER BY user";
      $result = $con->query($sql);
      echo "<br>Personal pictures <br>";
      while ($row = $result->fetch_assoc()) {
        $username = $row['user'];
        $filepicture = $row['filename'];

        if($username == $_SESSION["user"]){
          echo "<img src=" . "\"" . "uploads/"  . $filepicture . "\"" . ">";
          echo "<br>";
          $buttonName = $filepicture;
          echo "<form action=" . "\"" . "5logged.php" . "\"" . " method=" . "\"" . "GET" . "\"><input type=" . "\"" . "submit" . "\"" . "name=" . "\"" . "deleteButton" . "\"" . "value=" . "\"" . "Delete" . "\"" . ">" . "<input type=" . "\" " . "hidden " . "\"" . "name=" . "\"" . "deleteButton2" . "\"" . "value=" . "\"" . $buttonName . "\"" . "readonly>" .  "</form>";
        }
      }
      $sql = "SELECT * FROM pictures ORDER BY user";
      $result = $con->query($sql);
      echo "<br>Other users: <br>";
      while ($row = $result->fetch_assoc()) {
        $username = $row['user'];
        $filepicture = $row['filename'];
        if($username != $_SESSION["user"])
          echo "<img src=" . "\"" . "uploads/"  . $filepicture .  "\"" . ">";
          echo "    ";
      }
  ?>



</body>
</html>
