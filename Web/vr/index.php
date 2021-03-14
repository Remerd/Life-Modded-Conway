
<html>
<head>
<script src="https://aframe.io/releases/0.9.2/aframe.min.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script type="text/javascript" data-limit=<?=$_GET['limit']?$_GET['limit']:1000?> data-blanks=1 >
$(function() {
	var scripts = document.getElementsByTagName("script");
	var blanks = parseInt(scripts[scripts.length - 1].getAttribute("data-blanks"), 10);
	var limit = parseInt(scripts[scripts.length - 1].getAttribute("data-limit"), 10);
	var ws = new WebSocket("ws://185.20.227.83:443/");
	var colors = {
		'0': '#ffff00',
		'1': '#FF0000',
		'2': '#00FF00',
		'3': '#0000FF',
		'4': '#800000',
		'5': '#800080',
		'9': '#A9A9A9',
	}
	var scene = document.querySelector('a-scene');

	ws.onmessage = function(e) {
		var mesg = e.data.split("=");
		for (let iter = 0; iter<mesg.length;iter++)
		{
		var str = mesg[iter];
		var arr =str.split(' ');
		var a0 =parseInt(arr[0], 10);
		var a1 =parseInt(arr[1], 10);
		var a2 =parseInt(arr[2], 10);
//		var a3 =parseInt(arr[3], 10);
		var idd =a0+'_'+a1;			
		if (a2 == 9 ) {
			$('#'+idd).remove();
		} else if (a0 < limit && a1 < limit) {
			if ($('#'+idd).length) {				
				if ($('#'+idd).attr('material').color != colors[a2]) {
					if (colors[a2]) {
						$('#'+idd)[0].setAttribute('material', {color: colors[a2], metalness: 0, roughness: 10});
					} else {
						$('#'+idd)[0].setAttribute('material', {color: colors[0], metalness: 0, roughness: 10});
					}
				}
			} else {
				var entity = document.createElement('a-entity');
				entity.setAttribute('id', idd);
				entity.setAttribute('geometry', {primitive: 'sphere', radius: 0.5});
				if (colors[a2]) {
					entity.setAttribute('material', {color: colors[a2], metalness: 0, roughness: 10});
				} else {
					entity.setAttribute('material', {color: colors[0], metalness: 0, roughness: 10});
				}
				entity.setAttribute('position', {
					x: parseInt(arr[0]*1-28.4, 10), 
					y: parseInt(2, 10),  
					z: parseInt(arr[1]*-1+25.4, 10), 
				});
				scene.appendChild(entity);
			}
		}
		}			
	}

});
</script>


</head>
<body>
	<a-scene>
		<a-entity position="0 45 0" rotation="-90 0 90">
			<a-camera rotation-reader   wasd-controls="acceleration: 200"></a-camera> 	
		</a-entity>

		<a-sky color="#ECECEC"></a-sky>
	</a-scene>
</body>
</html>

