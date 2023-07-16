/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
#include"menu.h"
#include<stdlib.h>
#include<time.h>
//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay,int &colorNum){
    if (timer>delay){
       for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
        	for(int i=0;i<4;i++)
        	gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        	colorNum=rand()%7;
			// colorNum = 7;
        	while(colorNum==0){
        		colorNum=rand()%7;
        	}
            int n=rand()%7;
			
            for (int i=0;i<4;i++){


				 point_1[i][0] = BLOCKS[n][i] % 2;
                 point_1[i][1] = BLOCKS[n][i] / 2;
            }
         }
        		
     	 timer=0;
     }
}
/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

	void leftright(int &delta_x)
	{
		bool flag=true;
		if(delta_x!=0)
		{
			for(int i=0;i<4;i++)
			{
				if((point_1[i][0]+delta_x<0||point_1[i][0]+delta_x>=N)||(gameGrid[point_1[i][1]+1][point_1[i][0]+delta_x])!=0)		///condition for checking that the poits towars which bolock is being moved is empyty or not 
				{
					flag =false;			/// if space is not available then it is going to false /////////
					break;
				}	
			}
			if(flag)
			
			{
			
				for(int i=0;i<4;i++)
             {
           		point_1[i][0]+=delta_x;
           	}
				
			}
			
           	delta_x=0;		
		}
		
	
	}
	//////////////////////////////    FUNCTION	FOR 	ROTAION	///////////////////////////////////////////////////////
	void rotation(){
	 
	   	int px=point_1[1][0];
		int py=point_1[1][1];
		bool flag1=true;
		for(int i=0;i<4;i++){
			int x=point_1[i][1]-py;
			int y=point_1[i][0]-px;
			if(px-x < 0 || py-x < 0 || px-x > N || py-x > N){
				flag1 =false;
				break;
			}
		}

		if(flag1){
			for(int i=0;i<4;i++){
				int x=point_1[i][1]-py;
				int y=point_1[i][0]-px;
				point_1[i][0]=px-x;
				point_1[i][1]=py+y;
			}
			
		}
		else{
			int px=point_1[3][0];
			int py=point_1[3][1];
			for(int i=0;i<4;i++){
				int x=point_1[i][1]-py;
				int y=point_1[i][0]-px;
				point_1[i][0]=px-x;
				point_1[i][1]=py+y;
				
			}
		}
	}
	/////////////////////////////////////	FUNCTION FOR SHADOW		/////////////////////////////////////////////////////
	void shadow2(int shadow1[][2]){
		for(int i=0;i<4;i++){
      		shadow1[i][0]=point_1[i][0];
      		shadow1[i][1]=point_1[i][1];
       	}
      	
  		while(shadow1[3][1]!=M-1 ){
      		 bool flag3=true;
      		for(int i=0;i<4;i++){
      			if(gameGrid[shadow1[i][1]+1][shadow1[i][0]]!=0){
      				flag3=false;
      				break;
      			}
      	
      		}
		   if(flag3){
		  		for(int i=0;i<4;i++){
		  			shadow1[i][1]++;
		  	}
		  	}
		  if(!flag3)
		  	break;
		 }
	
	
	}
//////////////////////////////////	FUNCTION FOR LINVE CLEARING			////////////////////////////////////////
	void lineclear(int &score){
		int l=M-1;
		int j=M-1;
   		for (j;j>0;j--){
       		 int count=0;
        	for (int i=0;i<N;i++){
            	if (gameGrid[j][i])
            		count++;			//check wether the line is completed or not
          	 gameGrid[l][i]=gameGrid[j][i];
           }
        	if (count<N)
        		 l--;
      	}
    	if(l-j==1)
        	score+=10;
        else  if(l-j==2)
        	score+=30;
        else if(l-j==3)
        	score+=60;
        else if(l-j==4)
        	score+=100;
	
	}
	/////////////////////////////	FUNCTION 	FOR 	HADRDROPPING	//////////////////////////////////////////////
	void spacefun(int shadow1[][2]){
		for(int i=0;i<4;i++){
    		point_1[i][0]=shadow1[i][0];
    		point_1[i][1]=shadow1[i][1];
        }
	}
// 
void bombBlast(float &bombtimer,float& timer3,bool &isbomb,int&bombColor,bool &bombReached,float&blastTimer){	
		if( bombReached == 1 && blastTimer >= 1){
			if(gameGrid[ybomb][xbomb] == bombColor){	// if bomb collide to blocks and block is of red color the no   block will ramin 
				for(int i=0;i<M;i++){
					for(int j=0;j<N;j++)
						gameGrid[i][j]=0;
				}
				// ybomb=0;
				isbomb = 0;
				// xbomb=1+rand()%9;
				bombtimer=0;
				timer3=0;
			}
			else{
				{	// if bomb will  collide to block and block is any other color then red
					for(int j=0;j<N;j++)
						gameGrid[ybomb][j]=0;
				}
				isbomb = 0 ;
				bombtimer=0;	
				timer3=0;
			}
				bombReached = 0 ;
				blastTimer = 0 ;
		}
}
	//////////////////////////////		FUNCTION FOR BOMB FALLING		////////////////////////////////////////////////
	void bombfalling(float &bombtimer,float& timer3,bool &isbomb,int&bombColor,bool &bombReached,float&blastTimer){
		if(isbomb == 1){
			if(ybomb!=19 && gameGrid[ybomb ][xbomb]==0){	// if bomb did not collide to any thing then move will move down
				++ybomb;
				bombtimer = 0;
			}
			else{
			 	bombReached = 1 ;
				blastTimer = 0 ;
				
			}
		}
	}
void bombInitilization(RenderWindow&window,Sprite&bomb,bool &isbomb,int&xbomb,int&ybomb,float&timerbomb,float&timer3,float&delaybomb,int&bombcolor,bool&bombReached,float&blastTimer){
	
	if(isbomb ==1){
		bomb.setPosition(xbomb*18,ybomb*18);
		window.draw(bomb); 	
		float x = 0.2;	
		// bomb.move(0 , x);
		  if(!bombReached)
		if(timerbomb > delaybomb){
				 bombfalling(timerbomb,timer3,isbomb,bombcolor,bombReached,blastTimer);
		}
	
	}
	// when  > 15 then new bomb will come in 
	
	if(timer3  > 10 && isbomb == 0){
		int x1 = rand() % 500;
		if(( x1) != 100){
			return ;
		}
		xbomb = 1+rand()%9;
		ybomb = 0;
		bomb.setPosition(xbomb*18,ybomb*18);
		// bomb.move(28,31);		
		bomb.setScale(0.13,0.13);
		int x= 1+rand()% 7; // producing radnow color of bomb
		if(x == 1){
			bomb.setColor(Color::Red);	
		}
		else if(x == 2){
			bomb.setColor(Color::Green);	
		}
		else if(x == 3){
			bomb.setColor(Color(255,80,203,255));	// pink
		}
		else if(x == 4){
			bomb.setColor(Color((255,165,0)));// orange	
		}
		else if(x == 5){
			bomb.setColor(Color(135, 236, 150));	// sky blue	
		}
		else if(x == 6){
			bomb.setColor(Color::Blue);// dark blue	
		}
		else if(x == 7){
			bomb.setColor(Color::Yellow);	// yellow
		}
		
		bombcolor = x;
		isbomb = 1;
			
	}    

}			
	////////////////////////////////	FUNCTION 	FOR 	LEVEL	UP /////////////////////////////////////////////
	void levelup(float&leveltimer,int &level,float &delay){
		if(leveltimer>=60){
			level++;
			leveltimer=0;
			delay-=0.05;
		}
	}
	///////////////////////////////			FUNCTION FOR BLOCK MAKING AT START 	///////////////////////////
	void start(){
	
		for(int i=0;i<M;i++){
		    	for(int j=0;j<N;j++){
    			int random =1+rand()%7;
    			gameGrid[i][j]=random;
    		
    			}
    		}
	
	
	}
	////////////////////////	BLOCK BREAKING AT START 	/////////////////////////////////////	
	void breaker(float &blockbreaker){
		
		if(blockbreaker>0.2){
			
			for(int i=0;i<M;i++){
	    		for(int j=0;j<N;j++){
	    				gameGrid[i][j] = 0;
	    			}
	    			
	   	 	}	
	   		 
			
		}	
	}
	///////////////////	FUNCTION FOR GAME OVER	///////////////////////////////////////////////
	bool gameover(RenderWindow&window){
		Menu m;
		// LOGIC: IF ANY UPPER 5 ROWS OF ANY COLUMN != 0 THEN GAME OVER
		for(int i = 0 ; i < N ; i++){
				bool flag = true;
			for(int j = 4  ; j >= 0 ;j--){
				if(gameGrid[j][i] == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				if(m.GameOver(window) == 1)
				return 1; 
			

			}
		}
		return 0;
	
	}
	
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////

void DisplayingMenu(RenderWindow & window){
	Menu m;
	  while (window.isOpen()){
		
            m.display_menu(window);
             Event e;
            while (window.pollEvent(e)){
                if (e.type == Event::Closed) {// If cross/close is clicked/pressed
                    window.close();   
                }
              
            }
            float x = Mouse::getPosition(window).x;
            float y = Mouse::getPosition(window).y;
            if ( (x > 150 && x < 232 && y > 56 && y < 110) ){
               
                if(Mouse::isButtonPressed(Mouse::Left)){
                    break;
            }
            }
            else if(x >= 55 && x <= 220 && y > 140 && y < 174 ){
                if(Mouse::isButtonPressed(Mouse::Left))
                m.displaye_help(window);
            }
            else if(x >= 196 && x <= 593 && y > 397 && y < 465 ){
             
            }

            else if(x >= 276 && x<= 430 && y > 516 && y < 593 ){
            
            }
           
         

        }
       
}


void EventListengin(RenderWindow&window,int& delta_x,float&delay,int shadow1[][2]){
	
	//---Event Listening Part---//
	Event e;
	while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
		if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
		window.close();                            //Opened window disposes
		if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
		
		if (e.key.code == Keyboard::Up) {           //Check if the other key pressed is UP key
		 rotation();
		   }		
				                  //Rotation gets on
		 else if (e.key.code == Keyboard::Left) {    //Check if the other key pressed is LEFT key
		  delta_x = -1;                          //Change in X-Axis - Negative
		}
		
		 else if (e.key.code == Keyboard::Right) {   //Check if the other key pressed is RIGHT key
		 delta_x = 1;                           //Change in X-Axis - Positive
		}
		else if(e.key.code == Keyboard::Space) {
			spacefun(shadow1);
		}
		 else if(e.key.code == Keyboard::P) {
			
		}
	 }
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Down))  { //Just another way to detect key presses without event listener
			
			delay=0.05;       

		}                             //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
		
}


//   THIS IS FOR THE MOMETN IF BOMBS DESTROY THE BLOCKS DOWN TO SOME BLOCSK THE BLOCK WILL AUTOMATICALLY FILL DOWN
void blockdown(){
	for(int  i = 0 ;  i < M ; i++){
		for(int j = 0 ; j < N; j++ ){
			if(gameGrid[i][j] != 0 ){
					int k = j;
					bool flag = true;
				while(gameGrid[i][k] != 0 && k < N){
					if( gameGrid[i+1][k] != 0 ){
						flag = false;
						
					}
						k++;
				}
				if(!flag){
					j += k;
				}
				if(flag){
					for(int x = j ; x < k  ; x++){
						if(i < 19){
							gameGrid[i+1][x] = gameGrid[i][x];
							gameGrid[i][x] = 0;
						}
					}
				}
			}			
		}
	}	
}