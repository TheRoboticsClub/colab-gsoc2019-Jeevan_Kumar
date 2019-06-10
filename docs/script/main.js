console.log('1');
var count =0;




const press = document.getElementById('drop-down');
const drop = document.getElementById('side-content');
var change = function (){
  console.log(count);
  if(count%2==0){
    drop.style.display = 'block';
    count++;
  }
  else {
    drop.style.display = 'none';
    count++;
  }
}

var sidenav = document.getElementById('side-content');
var about = document.getElementById('about-me');
var yourElement = document.querySelector("#about-me");
var myElement = document.querySelector("#side-content");
var position = getPosition(myElement);


var count1=0,temp=0;

function getPosition(el) {
  var height = window.innerHeight;;
  var rect = myElement.getBoundingClientRect();
  var rect1 = yourElement.getBoundingClientRect();
  // console.log(height);
  // console.log(rect1.bottom+':rect1.bottom about-me and rect1.left:'+rect1.left);
  // console.log(rect1.top+':rect1.top about-me and rect1.right:'+rect1.right);
  // console.log(rect.bottom+':rect.bottom side nav and rect.left:'+rect.left);
  // console.log(rect.top+':rect.top side nav and rect.right:'+rect.right);
  if(rect.bottom<=height && count1==0){
    sidenav.className='after';
    console.log("I have been executed");
    count1=1;
  }
  else if(rect1.bottom>=rect.top && count1==1){
    sidenav.className='before';
    console.log('Hurray it works fine');
    count1=0;
  }
}

// deal with the page getting resized or scrolled
window.addEventListener("scroll", updatePosition, false);
window.addEventListener("resize", updatePosition, false);

function updatePosition() {
  position = getPosition(myElement);
}
