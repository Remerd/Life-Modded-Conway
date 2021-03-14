<html>
<head>
<meta charset="windows-1251">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.2.0/css/bootstrap.min.css">
<link rel="icon" href="/images/LifeLogo.png" type="/images/png">
<noscript><div><img src="https://mc.yandex.ru/watch/56274931" style="position:absolute; left:-9999px;" alt="" /></div></noscript>
<!-- /Yandex.Metrika counter -->
<style>
body{background-color: #FFFAFA;}
table td{padding: .35rem .35rem; border: solid white .1001rem;}
</style>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-131766938-2"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-131766938-2');
</script>


<script type="text/javascript">

    var ws;

     function init() {
	
      // Connect to Web Socket
      ws = new WebSocket("ws://185.20.227.83:443/");
/*
      // Set event handlers.
      ws.onopen = function() {
      };*/
      
        ws.onmessage = function(e) {
        // e.data contains received string.
        var id;
	var mesg = e.data.split("=");
	console.log("Recived bytes:"+ e.data.length+ " messaged cells = " + mesg.length);
	for (let i = 0; i<mesg.length;i++)
	{
	var str = mesg[i];
	var arr =str.split(' ');
	id = arr[0]+"."+arr[1];
	color_id = arr[2];
	if (color_id == 0)
		{
		document.getElementById(id).style.backgroundColor = "#FFFF00";
	        	}
	else if(color_id == 9)
		{
		document.getElementById(id).style.backgroundColor = "#A9A9A9";// Мёртвая клетка
		}
        else if(color_id == 1)
		{
		document.getElementById(id).style.backgroundColor = "#FF0000";
		}
        else if(color_id == 2)
		{
		document.getElementById(id).style.backgroundColor = "#00FF00";
		}
        else if(color_id == 3)
		{
		document.getElementById(id).style.backgroundColor = "#0000FF";
		}
        else if(color_id == 4)
		{
		document.getElementById(id).style.backgroundColor = "#800000";
		}
        else if(color_id == 5)
		{
		document.getElementById(id).style.backgroundColor = "#800080";
		}
	}
      };
      


    }


</script>
</head>
<body onload="init();">
<center>
<br>
<table>
<?php
for ($i=0;$i<56;$i++)
	{
	echo "<tr>";
	for ($j=0;$j<56;$j++)
		{
		echo "<td id='".$i.".".$j."' style=\"background: #A9A9A9;\"></td>";
		}
	echo "</tr>";
	}
?>	
</table>
<input type="button" value="Добавить клетки" onclick="window.open('/form.php');">
<input type="button" value="Пресозданные популяции" onclick="window.open('/preset.html');">
<input type="button" value="Перезагрузить" onClick="window.location.reload()">
<input type="button" value="Информация" onclick="window.open('http://life.remerd.ru');">
<input type="button" value="VR" onclick="window.open('http://life.izobretarium.ru/vr');">
</center><p align="right" style="position: relative; right: 10px; top: 3%">При наличии неполадок просьба писать на почту: remerd@remerd.ru<br>Если не обновляется картинка попробуйте перезагрузить страницу. Если не помогло - проблеммы с вашим интернетом.</p>
</body>
</html>
