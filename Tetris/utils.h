//ABdullah Aslam 22i-0784 PROJECT
/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * This header contains the global/common variables of the project.
 * You don't really need to change anything.
 * TIP: After completing your project, you can make changes for aesthetics.
 * */

//---Title: PF-Project, Fall-2022 for BS(CS)---//
const char title[] = "PF-Project, Fall-2022";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {0};

//---To Hold the Coordinates of the Piece---//
int point_1[4][4]={0}, point_2[4][4]={0};
int copy_tetris[4][4]={0};
//---Check Uncertain Conditions---//
bool anamoly(){
    for (int i=0;i<4;i++)
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>=M)
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])
            return 0;
    return 1;
}
bool anamoly_copy(){		//for shadow another condition checked
    for (int i=0;i<4;i++)
        if (copy_tetris[i][0]<0 || copy_tetris[i][0]>=N ||copy_tetris[i][1]>=M-1)
            return 0;
        else if (gameGrid[copy_tetris[i][1]+1][copy_tetris[i][0]])
            return 0;
       
    return 1;
}
void rot()
{
	if (!anamoly()) 
       {
       	int i=0;
		while (i<4)
       	{
       		point_1[i][0]=point_2[i][0];//again upadting point_1 if anamaloy becomes true;
       		point_1[i][1]=point_2[i][1];
       		++i;
       	}
       }
}
void drop()
{
	int i=10;
	while (i<10)//traverse the top row 
	{
		if (gameGrid[0][i]==1)// if it has found any single block on the top
		{
			
			exit(0);// to exit the game 
		}
		++i;
	}
}

