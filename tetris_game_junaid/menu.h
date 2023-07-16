
#include <SFML/Graphics.hpp>
using namespace sf;
#include<iostream>
using namespace std;
// #include"game.h"
// const char title[] = "OOP-Project, Spring-2023";
class Menu{
public:
Sprite sprite;
Texture tex;
sf::Font font1;
sf::Text text1;
sf::Text text2;
sf::Text text3;
sf::Text text4;
sf::Text text5;
sf::Text text6;
sf::Text text7;
sf::Text text8;
Menu();
void display_menu( RenderWindow& window);
void displaye_help(RenderWindow& window);
bool GameOver(RenderWindow& window);
};

Menu::Menu(){   
    // tex.loadFromFile("img/background.png");
     tex.loadFromFile("img/menu.png");
    sprite.setTexture(tex);
     sprite.setScale(.4, .7);
    //  sprite.setScale(1.2,1);  
    font1.loadFromFile("font/Roamer.ttf");    
    text1.setFont(font1);
    text2.setFont(font1);
    text3.setFont(font1);
    text4.setFont(font1);
    text5.setFont(font1);
    text6.setFont(font1);
    text7.setFont(font1);
    text8.setFont(font1);

    text1.setCharacterSize(30);
    text1.setStyle(sf::Text::Regular);
}
void Menu::display_menu( RenderWindow &window){
//    sprite.setScale(3.2, 1);
  
                
    window.draw(sprite);
   
    text1.setString("START");
    text2.setString("HELP");
    text3.setString("HIGH SCORE");
    text4.setString("EXIT");

    text1.setPosition(160,60);
    text2.setPosition(160,130);
    text3.setPosition(130,200);
    text4.setPosition(160,270);
    text1.setScale(1.3,1.5);
    text2.setScale(1.3,1.5);
    text3.setScale(1.3,1.5);
    text4.setScale(1.3,1.5);
 
     Event e;   
    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed) {// If cross/close is clicked/pressed
            window.close(); 
            
        }
        }
             
           
    float x = Mouse::getPosition(window).x;
    float y = Mouse::getPosition(window).y;
 
    if ((x > 150 && x < 232 && y > 56 && y < 110) ){
        sf::RectangleShape rectangle(sf::Vector2f(50, 30));
        rectangle.setPosition(150,65);
        rectangle.setSize(sf::Vector2f(100, 50));
        rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
    }
    else if(x >= 55 && x <= 220 && y > 140 && y < 174 ){
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setPosition(150,135);;
        rectangle.setSize(sf::Vector2f(80, 50));
        // rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
        if(Mouse::isButtonPressed(Mouse::Left))
            displaye_help(window);
    }
    else if(x >= 120 && x <= 225 && y > 183 && y < 252 ){
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setPosition(120,205);;
        rectangle.setSize(sf::Vector2f(150, 50));
        // rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
    }
    else if(x >= 150 && x<= 215 && y > 275 && y < 318 ){
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setSize(sf::Vector2f(80, 50));
        rectangle.setPosition(140,275);;
        // rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
         if(Mouse::isButtonPressed(Mouse::Left))
                window.close();

    }
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.display();

}
void Menu::displaye_help(RenderWindow& window){
    text1.setString("LEFT ARROW TO MOVE LEFT.");
    text2.setString("RIGHT ARROW TO MOVE RIGHT.");
    text3.setString("UP ARROW TO ROTATE.");
    text4.setString("SPACE FOR HADR DR0P.");
    text5.setString("FILL THE LINE TO SCORE.");
    text6.setString("BACK");
// sprite.setScale(3.2, 1);
    text1.setPosition(50,50);
    text2.setPosition(50,100);
    text3.setPosition(50,150);
    text4.setPosition(50,200);
    text5.setPosition(50,250);
    text6.setPosition(50,350);
       Clock clock;
       float timer;
    while (window.isOpen())
    {
          window.clear();
         window.draw(sprite);
           float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer+=time;
        Event e;   
    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed) {// If cross/close is clicked/pressed
            window.close(); 
    }  }   
  
     float x = Mouse::getPosition(window).x;
    float y = Mouse::getPosition(window).y;


    if(x >= 43 && x <= 105 && y > 348 && y< 390){
        
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setPosition(40,350);
        rectangle.setSize(sf::Vector2f(80, 50));
        // rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
        if(Mouse::isButtonPressed(Mouse::Left)){
            window.clear();
            return ;
        }
    }
    
  
    text1.setScale(1,1);
    text2.setScale(1,1);
    text3.setScale(1,1);
    text4.setScale(1,1);
    text5.setScale(1,1);
    text6.setScale(1,1);
    text7.setScale(1,1);   
    if(timer >= 0.1)
    window.draw(text1);
    if(timer >= 0.3)
    window.draw(text2);
     if(timer >= 0.5)
    window.draw(text4);
    if(timer >= 0.7)
    window.draw(text3);
   
    if(timer >= 0.9)
    window.draw(text5);
    if(timer >= 1.1)
    window.draw(text6);
    window.display();
    }
    
}
bool Menu::GameOver(RenderWindow& window){
    while (window.isOpen()){
        window.clear();
        window.draw(sprite);
        // sprite.setScale(3.2, 1);
    text1.setFont(font1);
    text2.setFont(font1);
    text3.setFont(font1);
    text4.setFont(font1);
    text5.setFont(font1);
    text6.setFont(font1);
    text7.setFont(font1);
    text8.setFont(font1);   
    text1.setString("RESTART");
    text2.setString("Exit");
    text3.setString("GAMEOVER");
       
     text1.setPosition(160,60);
    text2.setPosition(160,130);
    text3.setPosition(130,200);
    text4.setPosition(160,270);
    text1.setScale(1.3,1.5);
    text2.setScale(1.3,1.5);
    text3.setScale(1.3,1.5);
    text4.setScale(1.3,1.5);
        text1.Bold;
        text2.Bold;
        text3.Bold;
        text1.Bold;
        text1.getOutlineThickness();
        window.draw(text3);
        window.draw(text1);
        window.draw(text2);
             Event e;   
     float x = Mouse::getPosition(window).x;
    float y = Mouse::getPosition(window).y;
    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed) {// If cross/close is clicked/pressed
            window.close(); 
            
        }
    }

     if ((x > 150 && x < 232 && y > 56 && y < 110) ){
        sf::RectangleShape rectangle(sf::Vector2f(50, 30));
        rectangle.setPosition(150,65);
        rectangle.setSize(sf::Vector2f(115, 50));
        rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
         if(Mouse::isButtonPressed(Mouse::Left)){
            window.clear();
            return 1;
        }
    }     
     else if(x >= 55 && x <= 220 && y > 140 && y < 174 ){
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setPosition(150,135);;
        rectangle.setSize(sf::Vector2f(80, 50));
        // rectangle.setFillColor(sf::Color(242, 242, 242));
          rectangle.setFillColor(sf::Color(255,255,255,100));
        window.draw(rectangle);
      
             if(Mouse::isButtonPressed(Mouse::Left))
                window.close();
              
    }

         window.display();   
    }
    return 0;
}