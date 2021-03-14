//alert(c[0]);

AFRAME.registerComponent ( 'on-msg' , {

schema: { 
      color: {default: '#808080'}},


init: function () { var data = this. data; var entityEl = this .el; var id = entityEl.getAttribute ( 'id' );  // <a-box> var defaultColor = entityEl.getAttribute ( 'material' ) .color;

 	
 
	var ids = id.split('.');
	ids[0] = parseInt(ids[0], 10)
	ids[1] = parseInt(ids[1], 10)
	
	el_compare.push((ids[0]*56+ids[1])+" "+entityEl);	
	
	}

});

function initial(){

el_compare = new Array(3136);

c = new Array(3136);
for (let i = 0; i < 3136; i++){
	c[i] = 9
}


ws = new WebSocket("ws://lab.izobretarium.ru:443/")

ws.onmessage = function(e) {
	
	var str = e.data;
	var arr =str.split(' ');

	var a = parseInt(arr[0], 10)*56 + parseInt(arr[1], 10)

	c[a] = arr[2];
	for (let i = 0; i< 3136; i++){
		s = el_compare[i].split(" ")
		if (a == s[0]){
			entityEl = s[1];
		}
	}
	
	if (color_id == 0)
		{
		entityEl.setAttribute('material', 'color' ,  '#FFFF00');
	        }
	else if(color_id == 9)
		{
		entityEl.setAttribute('material', 'color' ,  '#A9A9A9');
		}
        else if(color_id == 1)
		{
		entityEl.setAttribute('material', 'color' ,  '#FF0000');
		}
        else if(color_id == 2)
		{
		entityEl.setAttribute('material', 'color' ,  '#00FF00');
		}
        else if(color_id == 3)
		{
		entityEl.setAttribute('material', 'color' ,  '#0000FF');
		}
        else if(color_id == 4)
		{
		entityEl.setAttribute('material', 'color' ,  '#800000');
		}
        else if(color_id == 5)
		{
		entityEl.setAttribute('material', 'color' ,  '#800080');
		}
	};
}