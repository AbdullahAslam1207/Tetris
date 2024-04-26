//ABdullah Aslam 22i-0784 PROJECT
/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * Shape of each piece is represented by rows in the array.
 * TIP: Name the array what is already been coded to avoid any unwanted errors.
 */
 int PIECES[7][4]={     
 			 {1,3,5,7},/*this is for I the position gets stored and when n=rand()%7 runs suppose 0 appears and then 
 			 when it runs in the for loop i<4 here it takes (0 as n and 0 as i then the block present in the array gets stored in the point array this process is repeated continuoesly untill and unless we get fixed shapes the next rows represnt the other shapes and same logic is applied*/		
			 {3,5,7,6},//J
			 {2,3,5,7},//L
			
			 {2,3,4,5},//O
			 {3,5,4,6},//S
			 {2,4,5,7},//Z
			 {3,5,4,7}//T due to mod and divison used the shapes are represented in this manner
			 
                  };
int BOMB[1][4]={0,0,0,0};

