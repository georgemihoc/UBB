<?php header('Access-Control-Allow-Origin: *'); ?>

<?php


// DE TEST
$data= array
  (
  array("cluj","Bucuresti"),
  array("cluj","Brasov"),
  array("bucuresti","Timisoara"),
  array("bucuresti","Brasov"),
  array("bucuresti","Cluj"),
  array("timisoara","Cluj"),
  array("timisoara","Bucuresti"),
  array("brasov","Bucuresti")
  );

// get the q parameter from URL
$q = $_REQUEST["q"];

$hint = "";


if ($q !== "") {
  $q = strtolower($q);
  $len=strlen($q);
  foreach ($data as $item)
    if ($item[0] === $q){
      if ($hint === "") {
        $hint = $item[1];
      } else {
        $hint .= ", $item[1]";
      }
    }
}
// DE TEST
// echo $hint === "" ? "No destination" : $hint;

class MyDB extends SQLite3
{
    function __construct()
    {
        $this->open('/Users/george/Documents/UBB/Anul 2/Semester 2/Programare Web/Lab6- AJAX/ajaxDb.db');
    }
}

$db = new MyDB();
$result = "";
$stmt = $db->prepare('SELECT stop FROM Prima WHERE start=:start');
$stmt->bindValue(':start', $q , SQLITE3_TEXT);

$res = $stmt->execute();

while ($row= $res->fetchArray(1))
{
  if ($result === "") {
    $result = $row['stop'];
  } else {
    $result .= ", ";
    $result .=  $row['stop'];
  }

}

echo $result


?>
