/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include<iostream>
#include "functionality.h"
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace sf;
int main(){
    srand(time(0));
	 Music music;
	 music.openFromFile("audio/background.wav");
	music.setVolume(80);
		music.play();
	music.setLoop(true);
    RenderWindow window(VideoMode(370, 480), title);
    Texture obj1, obj2, obj3,obj4,obj5,obj6,obj7;
    obj1.loadFromFile("img/tiles.png");//one for tile which is moving
    obj2.loadFromFile("img/menu.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/tiles.png");
    obj5.loadFromFile("img/bomb.png");
    obj6.loadFromFile("img/frame.png");
    obj7.loadFromFile("img/menu.png");
    
	Sprite sprite(obj1), background(obj2), frame(obj3),shadow(obj4),bomb(obj5),frame1(obj6),menu(obj7);
	background.setScale(1.25,1);
	int delta_x=0, colorNum=1;
	int score=0;   int randombomb;
	int shadow1[4][2]; int bombcolor;int level=1;

	float timer=0, delay=0.3;
	float timerbomb=0;
	float delaybomb=0.2;
	float leveltimer=0;
	float time2;
	float timer3=0;
	float blockbreaker=0;
	float shrink=0;
	bool flag4=false;
	bool flagH=true;
	bool rotate=0;
    bool isbomb = 0 ;
	float blastTimer = 0 ;
	bool bombReached = 0 ;
	
     sf:: Font font1;
     if(!font1.loadFromFile("font/Roamer.ttf")){
    	std::cerr<<"error";
    }
    sf::Text fontText;
    sf::Text scoretext;
    sf::Text leveltext;
    sf::Text levelt;
    sf::Text timetext;
    sf::Text time1;
    
    time1.setFont(font1);
    timetext.setFont(font1);
    fontText.setFont(font1);
    leveltext.setFont(font1);
    scoretext.setFont(font1);
    levelt.setFont(font1);
    
    time1.setPosition(310,150);
    timetext.setPosition(245,150);
    levelt.setPosition(310,200);
    leveltext.setPosition(245,200);
    fontText.setPosition(245,250);
    scoretext.setPosition(310,250);    
    DisplayingMenu(window);
    start();    
    Clock clock;
    while (window.isOpen()){
 	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer+=time;
	timerbomb+=time;
	time2+=time;
	timer3+=time;
	blockbreaker+=time;
	shrink+=time;	
	blastTimer+= time;
	std::string str=std:: to_string(score);
	std::string str1=std:: to_string(level);
	std::string str2=std:: to_string(time2);
	///////////////////////////////////////////////
	///*** START CALLING YOUR FUNCTIONS HERE ***///
	
	EventListengin(window,delta_x,delay,shadow1);
	if(bombReached == 0)
	fallingPiece(timer, delay,colorNum);    //Example: fallingPiece() function is called here
	leftright(delta_x);
	shadow2(shadow1);
	lineclear(score);
	levelup(time2,level,delay);
	blockdown();
	if(blockbreaker > 0.9){
	if(gameover(window) == 1){
		music.stop();
		window.close();
		main();
	}
	}
	window.clear();
	if(blockbreaker>0.5){
		if(flag4==false){
		breaker(blockbreaker);
		flag4=true;	
	}
	}
	delay = 0.3 - (level*0.05);
	///*** YOUR CALLING STATEMENTS END HERE ***///
	/////////////////////////////////////////////	
	window.clear(Color::Black);
	window.draw(background);
	for (int i=0; i<M; i++){
	    for (int j=0; j<N; j++){
		if (gameGrid[i][j]==0)
		    continue;
		sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
		sprite.setPosition(j*18,i*18);
		sprite.move(28,31); //offset
		window.draw(sprite);
	    }
	} 
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
          
          
       for (int i=0; i<4; i++){
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setPosition(shadow1[i][0]*18,shadow1[i][1]*18);
            shadow.move(28,31);
            shadow.setColor((Color(255,255,255,100)));
            window.draw(shadow);
          }    
  
     bombInitilization(window,bomb,isbomb,xbomb,ybomb,timerbomb,timer3,delaybomb,bombcolor,bombReached, blastTimer); 
	 if(bombReached == 1 )
	 	bombBlast(timerbomb,timer3,isbomb, bombcolor,bombReached , blastTimer);
	fontText.setString("score" );
	leveltext.setString("Level: ");
	scoretext.setString(str );
	levelt.setString(str1);
	timetext.setString("Time: ");
	
	String t2;
		for(int i = 0 ; str2[i-2] !='.'; i++){
				t2+=str2[i];
		}
	
	time1.setString(t2);
	window.draw(time1);
	window.draw(timetext);
	window.draw(levelt);
	window.draw(scoretext);
	window.draw(fontText);
	window.draw(leveltext);
		
    // bomb falling down 
	


        window.draw(frame);
        window.display();
    }
    
    return 0;
}
