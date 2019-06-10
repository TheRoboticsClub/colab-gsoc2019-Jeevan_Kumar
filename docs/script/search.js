var posts = document.getElementsByName('posts'),i;
// console.log(posts);
var tags = [];
var analized = [];
var i;
for(i=0;i<posts.length;i++){
  tags.push(posts[i].childNodes[3]);
}

// console.log(tags[0].children[0].innerHTML.length);
// console.log(window.location.search.split('?query=')[1]);
var query = window.location.search.split('?query=')[1];
// var query = 'as'
var patt = new RegExp(query,'gim');
console.log(patt);


//Started
for(k=0;k<posts.length;k++){
  var j=tags[k].children.length-2,score=0;
  var title = posts[k].childNodes[1].children[0].innerHTML;
  var meta = posts[k].childNodes[1].children[1].innerHTML;
  if(patt.test(title)){
    score+=5;
    // console.log(title+' title');
  }
  if(patt.test(meta)){
    score+=4;
    // console.log(meta+' meta');
  }
  i=0;
  var mid = search(query,i,j,k) ;
  var first,last;
  if(mid!=-1){
    // console.log(mid+' mid ');
    // console.log(tags[k].children[mid].innerHTML)
    first = range(mid,query[0].toLowerCase(),k,j)[0];
    last = range(mid,query[0].toLowerCase(),k,j)[1];
    // console.log(first+' :first ; last: '+last);
    var title;
    for(i=first;i<last;i=i+2){
      if(patt.test(tags[k].children[i].innerHTML)){
        // console.log(tags[k].children[i].innerHTML+' is the inner HTML');
        score=score+Number(tags[k].children[i+1].innerHTML);
      }
    }
  }
  console.log(score+' I am the score' + ' ; I am K :' + k);
  if(score){
    var key = new Key_value(k,score);
    analized.push(key);
  }
}
//ended


var result  = document.getElementById('content');



// console.log(typeof (analized));
// console.log(typeof (posts) );
// console.log(posts);
// console.log(analized);

if(analized.length){
  analized.sort(function compare(a,b){
    // console.log(typeof(b.score));
    return b.score - a.score;
  });
  console.log(analized.length);
  // console.log(result);
  var temp = [];
  for(i=0;i<analized.length;i++){
    temp.push(posts[analized[i].index].innerHTML);
  }
  console.log(temp.length);
  for(i=0;i<analized.length;i++){
    result.children[i].innerHTML = temp[i];
  }
// console.log(result);

    // console.log(posts[0]);
  for(i=analized.length;i<posts.length;i++){
      result.children[i].style.display='none';
  }
}

else {
  result.innerHTML = 'Sorry, no results found.'
}

// console.log(analized);



function range(mid,query_1,k){
  var x=mid,y=mid;
  while( x>=0 && tags[k].children[x].innerHTML[0]==query_1 ){
    x=x-2;
  }
  while(y<=j && tags[k].children[y].innerHTML[0]==query_1){
    y=y+2;
  }
  x=x+2,y=y;
  // console.log(tags[k].children[x].innerHTML,tags[k].children[y-2].innerHTML);
  return [x,y];
}

function search(query,i,j,k) {
  var  mid = ( (i+j) - ( (i+j)%2 ) ) /2;
  if(mid%2){
    mid=mid-1;
  }
  while(i<=j){
    // console.log( i + ' = low ;' + mid + ' = mid ;'  + j + ' = high;');
    if(tags[k].children[mid].innerHTML[0].localeCompare(query[0].toLowerCase())==0){
      // console.log(tags[k].children[mid].innerHTML + ' From search and k is : ' + k);
      return mid;
    }
    else if(tags[k].children[mid].innerHTML[0].localeCompare(query[0].toLowerCase())==1){
      j = mid-2;
    }
    else {
      i = mid+2;
    }
    mid = ( (i+j) - ( (i+j)%2 ) ) /2;
    if(mid%2){
      mid=mid-1;
    }
  }
  return -1;
}

function Key_value(index,score){
  this.index = index;
  this.score = score;
}
