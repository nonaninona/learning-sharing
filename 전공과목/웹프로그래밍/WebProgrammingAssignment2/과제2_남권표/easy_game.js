window.onload=function(){
	canvas = document.getElementById('game_screen');
	context = canvas.getContext('2d');
	draw_init();
	var start=document.getElementById("start");
	var reset=document.getElementById("reset");
	var back_to_menu=document.getElementById("back_to_menu").value;
	document.addEventListener("keydown", keyDownHandler, false);
	document.addEventListener("keyup", keyUpHandler, false);
	function keyDownHandler(e) {
    	if(e.keyCode == 39) {
     	   rightPressed = true;
   		}
    	else if(e.keyCode == 37) {
        	leftPressed = true;
    	}
	}	

	function keyUpHandler(e) {
   		if(e.keyCode == 39) {
        	rightPressed = false;
    	}
    	else if(e.keyCode == 37) {
        	leftPressed = false;
    	}
	}
	start.onclick = init;
	reset.onclick = retry;
	document.getElementById("option").onclick=check_option;
	document.getElementById("score").value=score;
	document.getElementById("max_score").value=max_score;
}
var ball_color="red";
var score=0;
var max_score=0;
var rightPressed=false;
var leftPressed=false;
var context; /* 컨텍스트 객체*/
var velocity; /* 사용자가 입력한 공의 초기속도 */
var canvas;
var ball_vx=1;
var ball_vy=1;
var ball_x = 50; /* 공의 현재 x방향 위치 */
var ball_y = 200; /* 공의 현재 y방향 위치 */
var ballRadius = 10; /* 공의 반지름 */
var score = 0; /* 점수 */
var timer; /* 타이머 객체 변수 */
var bar_x=139;/*bar의 x좌표 위치*/
var bar_y=388;/*bar의 y좌표 위치*/
var bar_width=100;/*bar의 너비*/
var bar_height=10;/*bar의 높이*/
var block_width;/*block 한개당 너비*/
var block_height;/*block 한개당 높이*/
var block_col=5;/*행 하나에 있는 열 개수*/
var block_row=5;
var opt=0;

var princess=new Image();
var timer;
princess.src="princess.png";

function draw_init(){
	blocks = [];
	for(var i=0; i<block_row; i++) {
  	  	blocks[i] = [];
  	  	for(var j=0; j<block_col; j++) {
     	   blocks[i][j] = { x: 0, y: 0, status: 1 };
  	 	}
	}
	context.clearRect(0, 0, canvas.width, canvas.height);
	rightPressed=false;
	leftPressed=false;
	if(ball_vx<0){
		ball_vx=-ball_vx;
	}
	if(ball_vy<0){
		ball_vy=-ball_vy;
	}
	
	score=0;
	document.getElementById("score").value=score;
	ball_x = 100;
	ball_y = 200;
	bar_x=139;
	bar_y=388;
	drawBall();
	drawBar();
	makeBlock();
	draw_img();
}
function drawBall() {
	context.beginPath();
	context.arc(ball_x, ball_y, ballRadius, 0, 2.0 * Math.PI, true);
	context.fillStyle = ball_color;
	context.fill();
}
function drawBar(){
	context.beginPath();
	context.rect(bar_x, bar_y, bar_width, bar_height);
	context.fillStyle="black"
	context.fill();
}
function makeBlock(){
	block_color=["red", "yellow", "green", "blue", "purple"];
	block_width=canvas.width/block_col;
	block_height=12;

	for(var i=0; i<block_row; i++) {
        for(var j=0; j<block_col; j++) {
        	if(blocks[i][j].status==1){
            	var block_x = block_width*j;
            	var block_y = block_height*i+32;
        	    blocks[i][j].x = block_x;
    	        blocks[i][j].y = block_y;
 	           	context.beginPath();
        	    context.rect(block_x, block_y, block_width, block_height);
    	        context.fillStyle = block_color[i];
 	           	context.fill();
 	       }
        }
    }
}
function draw_img(){
	context.drawImage(princess, 267, 0);
}

function draw_start(){
	if(rightPressed&&bar_x+bar_width<=canvas.width-1) {
    	bar_x += 1;
	}
	else if(leftPressed&&bar_x>=1) {
    	bar_x -= 1;
	}
	cal_v_Ball();
	cal_location_Ball();
	context.clearRect(0, 0, canvas.width, canvas.height); /* 화면을 지운다. */
	drawBall();
	drawBar();
	makeBlock();
	draw_img();
}

function init(){
	clearInterval(timer);
	draw_init();
	timer=setInterval(draw_start, 5);
}

function cal_location_Ball(){
	ball_x=ball_x+ball_vx;
	ball_y=ball_y+ball_vy;
}
function cal_v_Ball(){
	if((ball_y>32+block_height*5+ballRadius)&&(ball_y<canvas.height-bar_height-ballRadius)){
		if((ball_x<=0+ballRadius)||(ball_x>=canvas.width-ballRadius)){
			ball_vx = -ball_vx;
			ball_vy = ball_vy;
		}//왼쪽이나 오른쪽 벽에 부딪힘.
		else{
			ball_vx = ball_vx;
			ball_vy = ball_vy;
		}//부딪히지 않음.
	}//block이나 bar에 부딪힐 확율이 없음
	else if(ball_y==canvas.height-bar_height-ballRadius){
		if(ball_x>=bar_x&&ball_x<=bar_x+bar_width){
			ball_vx=ball_vx;
			ball_vy=-ball_vy;
		}//bar과 부딪힐 경우
		else{
			ball_vx = ball_vx;
			ball_vy = ball_vy;
		}//부딪히지 않는 경우
		if(ball_x<=ballRadius||ball_x>=canvas.width-ballRadius){
			ball_vx = -ball_vx;
			ball_vy = ball_vy;
		}
	}
	else if(ball_y>canvas.height-bar_height-ballRadius&&ball_y<canvas.height-bar_height){
		if((ball_y-bar_y)*(ball_y-bar_y)+(ball_x-bar_x)*(ball_x-bar_x)<=ballRadius*ballRadius){
			if(ball_vx>0){
				ball_vx = -ball_vx;
				ball_vy = -ball_vy;
			}
			else{
				ball_vx = ball_vx;
				ball_vy = -ball_vy;
			}
		}
		else if((ball_y-bar_y)*(ball_y-bar_y)+(ball_x-(bar_x+bar_width))*(ball_x-(bar_x+bar_width))<=ballRadius*ballRadius){
			if(ball_vx<0){
				ball_vx = -ball_vx;
				ball_vy = -ball_vy;
			}
			else{
				ball_vx = ball_vx;
				ball_vy = -ball_vy;
			}
		}
		if(ball_x>=bar_x&&ball_x<=bar_x+bar_width){
			ball_vx=ball_vx;
			ball_vy=-ball_vy;
		}//bar과 부딪힐 경우
		else{
			ball_vx = ball_vx;
			ball_vy = ball_vy;
		}
		if(ball_x<=ballRadius||ball_x>=canvas.width-ballRadius){
			ball_vx = -ball_vx;
			ball_vy = ball_vy;
		}
	}
	else if(ball_y>=canvas.height-bar_height&&ball_y<canvas.height-ballRadius){
		if(ball_x>=bar_x-ballRadius&&ball_x<=bar_x+bar_width+ballRadius){
			ball_vx=ball_vx;
			ball_vy=-ball_vy;
		}//bar과 부딪힐 경우
		if(ball_x>=bar_x&&ball_x<=bar_x+bar_width){
			ball_vx=ball_vx;
			ball_vy=-ball_vy;
		}//bar과 부딪힐 경우
		else{
			ball_vx = ball_vx;
			ball_vy = ball_vy;
		}//부딪히지 않는 경우
	}//bar와 부딪힐 가능성이 생김.
	else if(ball_y==0+ballRadius){
		if((ball_x==0+ballRadius)||(ball_x==canvas.width-ballRadius)){
			ball_vx = -ball_vx;
			ball_vy = -ball_vy;
		}//왼쪽이나 오른쪽 벽에 부딪힘.
		else{
			ball_vx = ball_vx;
			ball_vy=-ball_vy;
		}
	}
	else if(ball_y<=32+block_height*5+ballRadius && ball_y>=0+ballRadius && ((ball_x==0+ballRadius) || (ball_x==canvas.width-ballRadius))){
		ball_vx = -ball_vx;
		ball_vy = ball_vy;
	}	
	else if(ball_y<=32+block_height*5+ballRadius){
		for(var i=0; i<block_row; i++) {
        	for(var j=0; j<block_col; j++) {
        		var b = blocks[i][j];
        		if(b.status==1){
          			if(ball_x > b.x-ballRadius && ball_x < b.x+block_width+ballRadius && ball_y > b.y-ballRadius && ball_y < b.y+block_height+ballRadius) {
                    	ball_vx=ball_vx;
						ball_vy=-ball_vy;
                   	 	b.status = 0;
                   	 	document.getElementById("score").value=++score;
                	}
 	       		}
        	}
    	}
	}
	var clear=gameClear();
	if(clear){
		window.open("normal_game.html","_self");
	}
	if(ball_y>=canvas.height-ballRadius){
		gameOver();
	}//canvas의 하단면에 부딪힘.=>게임이 끝남.
}
function gameOver(){
	clearInterval(timer);
	alert('Game Over...\n점수: '+ document.getElementById("score").value);
	if(max_score<score){
		max_score=score;
		document.getElementById("max_score").value=max_score;
	}
}
function gameClear(){
	for(var i=0; i<block_row; i++) {
       	for(var j=0; j<block_col; j++) {
       		var b = blocks[i][j];
       		if(b.status==1){
       			return false;
       		}
 	   	}    
    }
    clearInterval(timer);
    alert('Game Clear! We Save Princess!\n점수: '+ document.getElementById("score").value);
    max_score=score;
    document.getElementById("max_score").value=max_score;
    return true;
}
function retry(){
	clearInterval(timer);
	alert('Reset this game\n점수: '+ document.getElementById("score").value);
	if(max_score<score){
		max_score=score;
		document.getElementById("max_score").value=max_score;
	}
	draw_init();
}
function check_option(){
	alert("메뉴창을 눌러 게임이 초기화됩니다.")
	opt=prompt("바꾸려는 항복을 숫자로 선택해 주세요.(1. 공 색상 2. 공 속도 3. 공 크기)", "0");
	if(opt==0){
		alert("잘못된 입력입니다.");
	}
	else if(opt==1){
		ball_color=prompt("바꾸려는 색상을 입력해주세요.(영어로 정확히 입력하세요.)", "red");
	}
	else if(opt==2){
		var v=prompt("원하시는 속도를 입력해주세요.(양수만 가능)", "1");
		ball_vx=parseInt(v);
		ball_vy=parseInt(v);
	}
	else if(opt==3){
		var r=prompt("반지름을 입력해주세요.(양수만 가능)", "10");
		ballRadius=parseInt(r);
	}
	else{
		alert("잘못된 입력입니다.");
	}
	retry();
}