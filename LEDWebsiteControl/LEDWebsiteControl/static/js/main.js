var slider = document.getElementById("myRange"); 
var output = document.getElementById("sliderValue");
var colorBtn  = document.getElementById("colorC"); 


colorBtn.addEventListener("click", function() { 
	$.post("/ChangeColor", {data: "c"}); }) 


slider.oninput = function()
{
  $.post("/postmethod", { javascript_data: this.value }); 
}


