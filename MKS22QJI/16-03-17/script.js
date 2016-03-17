var info = [50, 150, 250];
var svg = d3.select"svg");

svg.selectAll("circle")
    .data(info)
    .enter().append("circle"); // creates objects

var circles = d3.selectAll("circle");

circles.append("circle")
    .attr("r", "45")
    .attr("cx", function(d) { return d; });
    .attr("cy", "250")
