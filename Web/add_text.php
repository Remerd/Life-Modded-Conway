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

$cmd="echo '";
if (isset($_POST['text']))
	{
	$str = str_replace("\r\n", "\n", $_POST['text']);
	$cmd = $cmd."".$str." ' > ./LIFE/ver.2.1/websocket/buffer.txt";
	ssh_connect("185.20.227.83", "22", "remerd", "123456789900", $cmd);
	}
?>
<head>
<link rel="icon" href="/images/LifeLogo.png" type="/images/png">
<script type= "text/javascript">
function goToPage()
{
	document.location.href = "http://life.izobretarium.ru";
}
</script>
</head>
<body onload="goToPage()">
</body>
