    ws = new WebSocket("ws://lab.izobretarium.ru:443/");
      
    ws.onmessage = function(e) {
        // e.data contains received string.
        var id;
	var str = e.data;
	var arr =str.split(' ');
	id = arr[0]+"."+arr[1];
	
	color_id = arr[2];
	if (color_id == 0)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#FFFF00');
	        }
	else if(color_id == 9)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#A9A9A9');// Мёртвая клетка
		}
        else if(color_id == 1)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#FF0000');
		}
        else if(color_id == 2)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#00FF00');
		}
        else if(color_id == 3)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#0000FF');
		}
        else if(color_id == 4)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#800000');
		}
        else if(color_id == 5)
		{
		document.getElementById(id).el.setAttribute( 'color' ,  '#800080');
		}
