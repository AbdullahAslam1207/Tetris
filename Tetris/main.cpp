//ABdullah Aslam 22i-0784 PROJECT
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
#include <SFML/Audio.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include<string>
#include<iostream>
using namespace std;
using namespace sf;
int main(){ 
    float a;
    int b;
    bool pause_game;
    bool q=false;
    srand(time(0));
    
    Texture menu;
    menu.loadFromFile("img/index1.png");
    Sprite menu1(menu);
    menu1.setPosition(0,0);
    menu1.scale(1,1.5);
    RenderWindow window1(VideoMode(340,320), "MENU");
    Music music;
    music.openFromFile("img/Tetris-Theme-Tetris-Soundtrack.wav");
    music.setVolume(100);	
    music.play();
 
    while (window1.isOpen())//menu window 
    {
    	Event f;// event created
    	while (window1.pollEvent(f))
    	{
    		if (f.type == Event::Closed)                   //If cross/close is clicked/pressed
			window1.close();
    		if (f.type==Event::KeyPressed)
    		{
    			if (f.key.code==Keyboard::Num1)//game started
    			{  
    				window1.close();
    				srand(time(0));
    				Texture level;
    				level.loadFromFile("img/level.jpeg");
    				Sprite level1(level);
    				RenderWindow window3(VideoMode(340,320), "LEVELS");
    				while (window3.isOpen())
    				{
    					Event h;
    					while (window3.pollEvent(h))
    					{
    						if (h.type==Event::KeyPressed)
    						{
    						if (h.key.code==Keyboard::Num1)//level 1
    							{a=0.7;
    							b=4;
    							window3.close();}
    						else if (h.key.code==Keyboard::Num2)//level 2
    							{a=0.3;
    							b=7;
    							window3.close();}
    						}
    					}
    					window3.draw(level1);
    					window3.display(); 
    				}
    							
    		    srand(time(0));
		    RenderWindow window(VideoMode(320, 480), title);
		    Texture obj1, obj2, obj3, obj4,obj5;
		    
		    
		    
			obj1.loadFromFile("img/tiles.png");
			obj2.loadFromFile("img/background.png");
			obj3.loadFromFile("img/frame.png");
			obj4.loadFromFile("img/tiles.png");
			obj5.loadFromFile("img/tile.jpeg");
		    
		    Sprite sprite(obj1), background(obj2), frame(obj3), copy(obj4),shrink(obj5);
		    int delta_x=0, colorNum=1;
		    float timer=0, delay=a;
		    bool rotate=0; int score=0; int lines=0;
		    Font Calibri;//font declared
		    Calibri.loadFromFile("img/Calibri.ttf");
		    Text text;
		    text.setFont(Calibri);
		    Clock clock;
		    
		    while (window.isOpen())
		    { 
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer+=time;

			//---Event Listening Part---//
			Event e;
			while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
			    if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
				window.close();                            //Opened window disposes
			    if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
				if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
				   { rotate = true; 
				   rotation_tetris(rotate);
				     }                     //Rotation gets on
				else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
				    {delta_x = -1; 
				    move_leftside(delta_x);}                         //Change in X-Axis - Negative
				else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
				   { delta_x = 1; 
				    move_rightside(delta_x);
				    }                          //Change in X-Axis - Positive
			    } 
			} 
			if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
			    delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
			 if (Keyboard::isKeyPressed(Keyboard::P))
			{ 
				
    
				    Texture menu2;
				    menu2.loadFromFile("img/index2.png");
				    Sprite menu3(menu2);
				    menu3.setPosition(0,0);
				    menu3.scale(1,1.5);
				    RenderWindow window4(VideoMode(340,320), "MENU");
				    while (window4.isOpen())
				    {
				    	Event z;
				    	while (window1.pollEvent(z))
				    	{
				    		if (z.type == Event::Closed)                   //If cross/close is clicked/pressed
							window1.close();
				    		if (z.type==Event::KeyPressed)
				    		{
				    			pause_game=false;
						}
						
					}
					if (!pause_game) 
					{
						if (Keyboard::isKeyPressed(Keyboard::Num5))
						{
							window4.close();
						}
						if (Keyboard::isKeyPressed(Keyboard::Num1))
						{
							window4.close();
							window.close();
							
							
						}
						if (Keyboard::isKeyPressed(Keyboard::Num3))
						{
							RenderWindow window2(VideoMode(400, 200), "HELP PAGE");
			    		Texture help;
			    		help.loadFromFile("img/index3.png");
			    		Sprite help1(help);
							while (window2.isOpen())
				    			{ 
				    				Event g;
				    				while (window2.pollEvent(g))
				    				{
					    		if (g.type == Event::Closed)                   //If cross/close is clicked/pressed
								window2.close();
					    		if (g.type==Event::KeyPressed)
					    		{
					    			if (g.key.code==Keyboard::Num0)
					    			{ 
					    				window2.close();
					    			}
					    			
					    		}
					    		window2.draw(help1);
					    		window2.display();
				    		}
				    }
				    }
							
					}
					window4.draw(menu3);
					window4.display();
					
				    }

					
		    	}
		    	if (Keyboard::isKeyPressed(Keyboard::Space))
		    	{
				 q=true;	
			}
			
			///////////////////////////////////////////////
			///*** START CALLING YOUR FUNCTIONS HERE ***///
			fallingPiece(timer, delay,colorNum,a,b); //Example: fallingPiece() function is called here
			destroy_row(score);
			
			gameover_bye();
			shadow_incoming();
			hard_drop(q);
			//bomber(colorNum);
			///*** YOUR CALLING STATEMENTS END HERE ***///
			//////////////////////////////////////////////


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
			for (int i=0; i<M; i++){ //shadow
			for (int j=0; j<N; j++){
				if (gameGrid[i][j]==0)
				    continue;
				copy.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
				copy.setPosition(j*18,i*18);
				copy.move(28,31); //offset
				window.draw(copy);
			    }
			}
			for (int i=0; i<4; i++){ //shadow
			    copy.setTextureRect(IntRect(9*18,0,18,18));
			    copy.setPosition(copy_tetris[i][0]*18,copy_tetris[i][1]*18);
			    copy.move(28,31);
			    window.draw(copy);
			  }
			for (int i=0; i<4; i++){
			    sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
			    sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
			    sprite.move(28,31);
			    window.draw(sprite);
			  }
			string scores=to_string(score);//to display on screen
			Text Score(scores,Calibri);
			Score.setCharacterSize(20);
			Score.setFillColor(Color::Red);
			Score.setPosition(265,130);
			Text text1;
			text1.setFont(Calibri);
			text1.setString("SCORE");
			text1.setCharacterSize(27);
			text1.setFillColor(Color::Red);
			text1.setPosition(240,100);
			Text text2;
			
			Clock clock;
			
			Time time1 = clock.getElapsedTime();

			float seconds = time1.asSeconds(); //calculate time
			
			
			text2.setFont(Calibri);
			text2.setString("TIMER");
			text2.setCharacterSize(27);
			text2.setFillColor(Color::Red);
			text2.setPosition(240,160);
			
			string second=to_string(seconds);
			Text timee(second,Calibri);
			timee.setCharacterSize(20);
			timee.setFillColor(Color::Red);
			timee.setPosition(265,180);
			int h=score;// to shrink window 
			if (h==10)
			{
				
				
			
				for (int i=0; i<4; i++)
				{
			    		shrink.setTextureRect(IntRect(colorNum*18,0,18,18));
			    		for (int j=0;j<M;j++)
			    		{
			    			for (int k=0;k<N;k++)
			    			{
			    				if (j=0)
			    				{
			    					shrink.setPosition(j,k);
			    					window.draw(shrink);
			    				}	
			    				else if (j=M-1)
			    				{
			    					shrink.setPosition(j,k);
			    					window.draw(shrink);
			    				}
			    			}
			    		}
			    	}
			    		
			  	
			  }
			  h=0;
			//---The Final on Which Everything is Drawn Over is Loaded---//
			window.draw(frame);
			window.draw(Score);
			window.draw(text1);
			window.draw(text2);
			window.draw(timee);
			//---The Window that now Contains the Frame is Displayed---//
			window.display();
			
		    }
		  				
		    }
		    	else if(f.key.code==Keyboard::Num2)
		    	{
		    		
		    	}
		    	else if(f.key.code==Keyboard::Num3)//help page opened 
		    	{
		    		RenderWindow window2(VideoMode(400, 200), "HELP PAGE");
		    		Texture help;
		    		help.loadFromFile("img/index3.png");
		    		Sprite help1(help);
		    		 
		    		 while (window2.isOpen())
				    { 
				    	Event g;
				    	while (window2.pollEvent(g))
				    	{
				    		if (g.type == Event::Closed)                   //If cross/close is clicked/pressed
							window2.close();
				    		if (g.type==Event::KeyPressed)
				    		{
				    			if (g.key.code==Keyboard::Num0)
				    			{ 
				    				window2.close();
				    			}
				    			
				    		}
				    		window2.draw(help1);
				    		window2.display();
				    	}
				    }
			}
			else if(f.key.code==Keyboard::Num4)//exit 
			{
				                  
				window1.close();
			}
			
			
		    		}//closing the if key pressed
		    		 window1.clear(Color::Black);
				 window1.draw(menu1);
				 window1.display();
			} 
		    } 
    
    return 0;
}
