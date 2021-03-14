<html>
<head>
<script src="https://aframe.io/releases/0.9.2/aframe.min.js"></script>
<script src="/vr/scripts/main.js"></script>
<script type="text/javascript">
/*
var ws;
AFRAME.registerComponent('cursor-listener', {

  init: function () {

    var lastIndex = -1;
    var COLORS: = ['#FFFF00', '#A9A9A9', '#FF0000', '#00FF00', '#0000FF', '#800000', '#800080'];

      // Connect to Web Socket
      
    ws = new WebSocket("ws://lab.izobretarium.ru:443/");
      
    ws.onmessage = function(e) {
        // e.data contains received string.
        var id;
	var str = e.data;
	var arr =str.split(' ');
	id = arr[0]+"."+arr[1];
	color_id = arr[2];
	var array
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
      };
   }


    var lastIndex = -1;
    var COLORS = ['red', 'green', 'blue'];
    this.el.addEventListener('click', function (evt) {
      lastIndex = (lastIndex + 1) % COLORS.length;
      this.setAttribute('material', 'color', COLORS[lastIndex]);
      console.log('I was clicked at: ', evt.detail.intersection.point);
    });
  }
});
*/
</script>


</head>
<body onload="initial();">
<a-scene>

<?php
for ($i=0;$i<56;$i++)
	{
	for ($j=0;$j<56;$j++)
		{
		#echo "<a-entity id='".$i.".".$j."' geometry=\"primitive: box; depth=\"0.0001\" height=\"0.05\" width=\"0.05\"\"  material=\"color: white; \" position='".($i*0.07-1.9)." ".$j*0.07." -5'></a-entity>";
		
		echo "<a-entity on-msg id='".$i.".".$j."' geometry=\"primitive: box; depth: 0.0001; height: 0.07; width: 0.07\" material=\"color: #abc910\" position='".($i*0.07-1.9)." ".$j*0.07." -5'></a-entity>";

		#echo "<a-box id='".$i.".".$j."' depth='0.0001' height='0.05' width='0.05' position='".($i*0.07-1.9)." ".$j*0.07." -5' color='#FFFF00' on-message = 'color: #FFFF00'></a-box>";
		#echo "< a-box id='".$i.".".$j."' color = '#FFFF00' depth='0.1' height='0.1' width='0.1' position='".$i*0.2." ".$j*0.2." -10' on-message = 'color: #FFFF00'> </ a-box >";
		#echo "<td id='".$i.".".$j."' style=\"background: gray;\"></td>";
		}
	}
?>
      <a-plane height="20" width="20" position="0 0 0" rotation="-90 0 0" color="green"></a-plane>
      <a-sky color="#ECECEC"></a-sky>
</a-scene>
</body>
</html>