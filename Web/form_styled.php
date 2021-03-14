<?php
if (isset($_POST['bgstring']))
   {
    $bg=$_POST['bgstring'];
    if ($bg == 0)
       {
        $bgstring="FFFF00";
	$bg = 0;
       }
    elseif($bg == 1)
	{
	$bgstring="FF0000";
	$bg=1;
	}
    elseif($bg == 2)
	{
	$bgstring="00FF00";
	$bg=2;
	}
    elseif($bg == 3)
	{
	$bgstring="0000FF";
	$bg=3;
	}
    elseif($bg == 4)
	{
	$bgstring="800000";
	$bg=4;
	}
    elseif($bg == 5)
	{
	$bgstring="800080";
	$bg=5;
	}
    }
else
       {
	$bg=0;
        $bgstring="FFFF00";
       }
?>
<!DOCTYPE html>
<html>
<head>
<link rel="icon" href="/images/LifeLogo.png" type="/images/png">
  <meta charset="windows-1251">
  <title>ADD CELLS</title>


  <link rel="stylesheet" media="screen and (max-width:1000px)" href="/css/style_1000px.css" />
  <link rel="stylesheet" media="screen and (min-width:1001px)" href="/css/style_pc.css" />
  <style>
	input[type='checkbox']:checked + label {
	  
 	  <?php
	  echo "border: 1px solid #".$bgstring.";";
          echo "background: #".$bgstring.";";
          ?>
	}
  </style>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-131766938-2"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-131766938-2');
</script>

</head>

<body>

		

<form method="post" action="add1.php">
<div style="display: block; width:4010px; height: 22px;">
<input type="button" value="???? ???? ???" onclick="window.open('/form.php');">
<input type="submit" value="???? ??? ??????" style="font-weight:bold;">
????????
</div>
<?php
echo "<div style=\"background: #".$bgstring."; padding: 0px; width: 100px; height: 22px; border: 1px solid; display: block; position: relative; top: -24px; right: -519px; \">";
echo "</div>";
?>

            <main>
                <section>
                	<ul>

			<?php
			for($i=0;$i<56;$i++)
				{
				for ($j=0;$j<56;$j++)
					{
					echo "<li>";
					echo "<input type='checkbox' id='".$i.".".$j."' name='matrix[]' value='".$j.",".$i."'>";
					echo "<label for='".$i.".".$j."' >&nbsp</label>";
					echo "</li>";

					}
				}
			?>
                    </ul> 
                </section>
            </main>
<?php
echo "<input type = 'text' name='color_id' value='".$bg."' size ='20' hidden>";
?>

</form>

    
</body>
</html>
