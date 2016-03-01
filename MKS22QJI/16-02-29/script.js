var pic = document.getElementById("vimg");
var cbutton = document.getElementById("clear");
var mbutton = document.getElementById("move");

var drawC = function(x, y) {
	var c = document.createElementNS("http://www.w3.org/2000/svg", "circle");
	c.setAttribute("cx", x);
	c.setAttribute("cy", y);
	c.setAttribute("r", "25");
	c.setAttribute("fill", "red");
	c.setAttribute("stroke", "black");
	
	pic.appendChild(c);
};

var clicked = function(e) {
	console.log(e);
	if(e.toElement == pic) {
		drawC(e.offsetX, e.offsetY);
	}
	else {
		this.setAttribute("fill", "yellow");
	}
};

var clear = function() {
	while(pic.childElementCount >= 0) {
		pic.removeChild(pic.children[0]);
	}
};

var animate = function() {
	var c = document.getElementsByTagName("circle")[0];
	var x = parseInt(c.getAttribute("cx"));
	var a = function() {
		x+= 1;
		c.setAttribute("cx", x);
	};
	
	window.setInterval(animate, 500);
};

pic.addEventListener("click", clicked);
cbutton.addEventListener("click", clear);
mbutton.addEventListener("click", animate);
