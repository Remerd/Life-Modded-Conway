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

#$cmd = "echo '".$_POST['x0']." ".$_POST['y0']." ".$_POST['color_id']."\n".$_POST['x1']." ".$_POST['y1']." ".$_POST['color_id']."\n".$_POST['x2']." ".$_POST['y2']." ".$_POST['color_id']."\n".$_POST['x3']." ".$_POST['y3']." ".$_POST['color_id']."\n".$_POST['x4']." ".$_POST['y4']." ".$_POST['color_id']."\n".$_POST['x5']." ".$_POST['y5']." ".$_POST['color_id']."\n".$_POST['x6']." ".$_POST['y6']." ".$_POST['color_id']."\n".$_POST['x7']." ".$_POST['y7']." ".$_POST['color_id']."\n".$_POST['x8']." ".$_POST['y8']." ".$_POST['color_id']."\n".$_POST['x9']." ".$_POST['y9']." ".$_POST['color_id']." ' > ./Life/ver.1/tornado/static/buffer.txt";
#ssh_connect("151.248.113.144", "443", "belov", "123456789900", $cmd);
$cmd="echo '";
if (isset($_POST['matrix']))
	{
	$matrix_size = sizeof($_POST['matrix']);
	#echo "=".sizeof($_POST['matrix'])."</br>";
     	
        for($i=0;$i<$matrix_size -1;$i++)
           {
            #echo $_POST['matrix'][$i]."</br>";
	    $str = str_replace(",", " ", $_POST['matrix'][$i]);
	    #echo "".$str." ".$_POST['color_id']." "."</br>";
            $cmd = $cmd."".$str." ".$_POST['color_id']."\n";
            }

	$str = str_replace(",", " ", $_POST['matrix'][$matrix_size - 1]);
	$cmd = $cmd."".$str." ".$_POST['color_id']." ' > ./LIFE/ver.2.1/websocket/buffer.txt";

	#echo "Строка для записи:".$cmd;
	ssh_connect("185.20.227.83", "22", "remerd", "123456789900", $cmd);
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
