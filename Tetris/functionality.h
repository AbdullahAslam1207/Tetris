//ABdullah Aslam 22i-0784 PROJECT
/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
#include<iostream>
using namespace std;
void fallingPiece(float& timer, float& delay,int& colorNum,float& a,int& b){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
            for (int i=0;i<4;i++)
            
            	gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;//block occupies the color
            	colorNum=1+rand()%b;
               
            
            	int n=rand()%b;
                for (int i=0;i<4;i++){
                    point_1[i][0] = PIECES[n][i] % 2;
                    point_1[i][1] = PIECES[n][i] / 2;
                }
                
            
        }
        timer=0; delay=a;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
int move_rightside(int& delta_x)
{
		 
        if (delta_x==0)
		{
			return 0;
		}
		else
		{
			int i=0;
			while (i<4)
			{
				point_2[i][0]=point_1[i][0];//storing the coordinates
				point_2[i][1]=point_1[i][1];
				point_1[i][0]+=1;//incrementing the coordinates
				point_1[i][1]+=1;
				++i;
			}
			if (!anamoly())
			{
				int i=0;
				while (i<4)
				{
					point_1[i][0]=point_2[i][0];//again upadating point_1
					point_1[i][1]=point_2[i][1];	
					++i;	
				}
			}
		}
	
}
int move_leftside(int& delta_x)
{
	
	if (delta_x==0)
	{
		return 0;
	}
	else
	{
		
		int i=0;
			while (i<4)
			{
				point_2[i][0]=point_1[i][0];//storing the coordinates
				point_2[i][1]=point_1[i][1];
				point_1[i][0]-=1;//incrementing the coordinates
				point_1[i][1]-=1;
				++i;
			}
			if (!anamoly())
			{
				int i=0;
				while (i<4)
				{
					point_1[i][0]=point_2[i][0];//again upadating point_1
					point_1[i][1]=point_2[i][1];
					++i;		
				}
			}
            	
       	 	
	}
	
}
void rotation_tetris(bool& rotate)
{
	if (rotate) //rotate true or not 
      {
        
        
        int i=0;
	while (i<4)
        {
        	int a=point_1[i][0]-point_1[1][0];//storing the coordinate and subtarcting with center point
        	int b=point_1[i][1]-point_1[1][1];
        	point_1[i][0]=point_1[1][0]-b;//rotation 
        	point_1[i][1]=point_1[1][1]+a;
        	++i;
        }
      } 
      rot();
	
     
       
} 
void destroy_row(int& score )
{
	
	int lines=0;
	int a=M-1;
	for (int i=M-1;i>0;i--) 
    	{
        	int c=0;
        	for (int j=0;j<N;j++)
        	{
            		if (gameGrid[i][j]!=0)//to check whether rows filled or not 
            		{ 
            			c+=1;
            		}
            	}
            	if (c==N)// to check whether the line is completly filled or not.
            	{
            		lines+=1;
            		for (int k=i;k>0;k--)
            		{
            			for (int g=0;g<N;g++)
            			{
            				gameGrid[k][g]=gameGrid[k-1][g];//upper rows takking pos of lower empty rows
            			}
            		}
            	}
            	
    	} 
    	
    	(lines==1)?score+=10:(lines==2)?score+=30:(lines==3)?score+=60:(lines==4)?score+=100:score=score;
    	lines=0;
    	
}

void shadow_incoming()
{

	for (int i=0;i<4;i++)
	{
		copy_tetris[i][0]=point_1[i][0];//copy gets coordinates of point_1
		copy_tetris[i][1]=point_1[i][1];
	}
	while (anamoly_copy()) 
	{
		int i=0;
		while (i<4)
		{
		copy_tetris[i][1]+=1;//shadow coming down.
		++i;
		}
	}
	
	
	
}
void hard_drop (bool& q)
{
	if (q)
	{
	for (int i=0;i<4;i++)
	{
		point_1[i][0]=copy_tetris[i][0];//if q gets true then delay becomes 0...instantly point_1 occupeies shadow 
		point_1[i][1]=copy_tetris[i][1]; 
	}
	q=false;//necessary otherwise point_1 occupies shadow everytime without space bar 
	}
	
}
void gameover_bye()
{
	drop(); 
}			

	
			
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
