<!DOCTYPE HTML>
<html lang="ro">
<head>
<meta charset="UTF-8">
<title>Problema 6</title>
</head>
<body>

  <b>Admin login</b><br>
	<form action ="6.php" method="post">
		Username:<input type="text" name="username">
		<br>
		Password:<input type="password"  name="password">
		<br>

		<input type="submit" name="login" value="Login">
	</form>
  <br>
  <b>Article</b>
  <br>
  <div>The 16-inch MacBook Pro (2019) has the keyboard every Apple laptop should have. And I'm glad that Apple has brought it to the MacBook Air, as superior ergonomic comfort should not be a premium feature. There are plenty of other reasons to splurge on this laptop, including its vivid 16-inch display with narrower bezels, amazing audio system and epic battery life.

      This is also a very powerful notebook, thanks to the combination of Core i9 muscle, gobs of RAM and one of the fastest SSDs in a laptop. It's up to you to decide how much oomph you need — and how much extra you're willing to pay above the $2,399 starting price. The only strikes against the 16-inch MacBook Pro are the sheer expense and the lack of legacy ports that some pros would appreciate.

      If you're on the fence between Windows and macOS, the Dell XPS 15 is a compelling MacBook Pro alternative, as it offers comparable performance, a keyboard with even more travel and an OLED display for hundreds less. But if you are set on a Mac and demand a large canvas for work and play, the 16-inch MacBook Pro should satisfy for years to come.
  <div>

  <br>
  <b>Add a comment</b><br>
  <form action="6.php" method="post" >
  	User:<input type="text" name="user">
  	<br>
  	Text:
  	<br>
  	<textarea name="comment"></textarea>
  	<br>
  	<input type="submit" name="add" value="Add">
  </form>
  <br>
  <b>User comments</b><br><br>


  <?php

    	$con= new mysqli('127.0.0.1', 'mgir2554', 'mgir2554', 'mgir2554');
    	$con->set_charset("utf8");

    	$sql = "SELECT user,comment  FROM comments WHERE moderated = 1";
    	$result = $con->query($sql);
    	while ($row = $result->fetch_assoc()) {
      	$userDb = $row['user'];
      	$commentDb = $row['comment'];
      	print $userDb . ": " . $commentDb . "<br>";
      }


      if(isset($_POST['add'])){
          $user = addslashes(htmlentities($_POST['user'], ENT_COMPAT, "UTF-8"));
          $comment = addslashes(htmlentities($_POST['comment'], ENT_COMPAT, "UTF-8"));

          if($user != "" && $comment != ""){
              $moderated = 0;
              $stmt = $con->prepare("INSERT INTO comments (user, comment, moderated) VALUES (?,?,?)");
            	$stmt->bind_param('sss', $user ,$comment,$moderated);
            	$stmt->execute();
          }
      }
      if(isset($_POST['login'])){
          $username = addslashes(htmlentities($_POST['username'], ENT_COMPAT, "UTF-8"));
          $password = addslashes(htmlentities($_POST['password'], ENT_COMPAT, "UTF-8"));

          	$stmt = $con->prepare("SELECT username FROM users WHERE username=? AND password=?");

        			$stmt->bind_param('ss', $username, $password);
        			$stmt->execute();
        			$count = 0;
        			while($stmt->fetch()){
        				$count = $count + 1;
        			}
        			if ($count != 1) {
        	 			header("Location: 6.php");
        	 			return;
        			}
        			session_start();
        			$_SESSION['user'] = $username;
        			header("Location: 6logged.php");
      }
	?>






</body>
</html>
