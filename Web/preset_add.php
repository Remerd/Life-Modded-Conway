<?
function ssh_connect($host, $port, $login, $password, $cmd){

    $connection = ssh2_connect($host, $port);

    if (!(ssh2_auth_password($connection, $login, $password))) {
        echo "Ошибка аутентификации \r\n" ;
    }else{
        if(!($stream = ssh2_exec($connection, $cmd))){
            echo "Не удалось выполнить команду \r\n" ;
        }else{
            stream_set_blocking($stream, true);
            $stream_out = ssh2_fetch_stream($stream, SSH2_STREAM_STDIO);
            echo stream_get_contents($stream_out);
        }
    }
}
if (isset($_POST['preset']))
	{
	$preset=$_POST['preset'];
	$cmd = "echo ";
	if ($preset == "0")
		{
		$file= file_get_contents('http://life.izobretarium.ru/pres/1kvadrat.txt');
		}
	elseif ($preset == "1")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/2chaos.txt");
		}
	elseif ($preset == "2")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/3four_colony.txt");
		}
	elseif ($preset == "3")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/4spiral_big_sharp.txt");
		}
	elseif ($preset == "4")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/5spiral_last.txt");
		}
	elseif ($preset == "5")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/6spiral_13.txt");
		}
	elseif ($preset == "6")
		{
		$file = file_get_contents("http://life.izobretarium.ru/pres/7vrash_spir.txt");
		}
	#echo $file;
	#echo "<br><br>";
	$cmd = $cmd."'$file'";
	#echo $file;
	#echo $cmd;
	$cmd =$cmd." > ./LIFE/ver.2.1/websocket/buffer.txt";
	
	#echo "<br><br>";
	ssh_connect("185.20.227.83", "22", "remerd", "123456789900", $cmd);
	#echo $cmd;
	}

?>

<head>
<meta charset="windows-1251">
<link rel="icon" href="/images/LifeLogo.png" type="/images/png">
<script type= "text/javascript">
function goToPage()
{
	document.location.href = "http://life.izobretarium.ru";
}
</script>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-131766938-2"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-131766938-2');
</script>

</head>
<body onload="goToPage()">
</body> 