#include<iostream>
#include<windows.h>
using namespace std;

#include"myconsole.h"
const int columns=79;
void DrawLevel(char LevelArray[][columns], int rows);
void Obstacles(char DrawLevel[][columns], int rows);
void MovePacman(char StageArray[][columns],char Lives[], int rows, int &score, int &life);
void UpMove(char StageArray[][columns],char Lives[], int &pacman_x, int pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj);
void DownMove(char StageArray[][columns],char Lives[], int &pacman_x, int pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj);
void RightMove(char StageArray[][columns],char Lives[], int pacman_x, int &pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj);
void LeftMove(char StageArray[][columns],char Lives[], int pacman_x, int &pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj);
void GhostRunToPacman(char StageArray[][columns],char Lives[], int &pacman_x, int &pacman_y, int &life, int &ii, int &jj);
void GhostRunFromPacman(char StageArray[][columns],char Lives[], int &pacman_x, int &pacman_y, int &score, int &life, int &ii, int &jj);
void PrintScoreLives(char Lives[], int score, int life);
void StartPage(char LevelArray[][columns], int rows);
void LastPage(int score, int life);
char Menu();

int main()
{
	const int rows=40;
	const int lives=4;
	char Array[rows][columns]={};
	char Lives[lives]={3,3,3,3};
	
	int score=0, life=4;
	StartPage(Array, rows);
	
	DrawLevel(Array,rows);

	MovePacman(Array, Lives, rows, score, life);
	
	LastPage(score, life);
	
	return 0;
}
	
void LastPage(int score, int life)
{
	int i=0,j=0;
	ClearScreen();
	PlaceCursor(20,24);
	cout<<"T H A N K Y O U   FOR   P L A Y I N G";
	i=24;
	for(j=20; j<60; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	
	if(score>79)
	{
		PlaceCursor(25,29);
		cout<<"Y O U   W O N  T H E  G A M E";
		i=29;
		for(j=25; j<50; j++)
		{
			SetColorAtPoint(j, i, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
	}
	
	PlaceCursor(25,31);
	cout<<"Y O U R    S C O R E:  "<<score;
	PlaceCursor(25,33);
	cout<<"Y O U R    L I V E S:  "<<life;  
	
}

void StartPage(char LevelArray[][columns], int rows)
{
	ClearScreen();
	int i=0, j=0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<79; j++)
		{
			LevelArray[i][j]=179;
		}
	}
	
	for(i=37; i<41; i++)
	{
		for(j=0; j<79; j++)
		{
			LevelArray[i][j]=179;
		}	
	}
	
	for(j=0; j<3; j++)
	{
		for(i=0; i<rows; i++)
		{
			LevelArray[i][j]=179;
		}
	}
	
	for(i=0; i<rows; i++)//square
	{
		for(j=75; j<79; j++)
		{
			LevelArray[i][j]=179;
		}
	}
	
	j=20;
	for(i=5; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	j=23;
	for(i=5; i<8; i++)//square
	{
		LevelArray[i][j]=186;
	}
		
	i=5;
	for(j=20; j<24; j++)
	{
		LevelArray[i][j]=186;
	}
	i=7;
	for(j=21; j<24; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=25;
	for(i=5; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=5;
	for(j=25; j<29; j++)
	{
		LevelArray[i][j]=186;
	}
	j=28;
	for(i=6; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=7;
	for(j=26; j<28; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=30;
	for(i=6; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	
	i=5;
	for(j=30; j<35; j++)
	{
		LevelArray[i][j]=186;
	}
	
	i=9;
	for(j=31; j<35; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=32;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=32; j<36; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=35;
	for(i=12; i<15; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=36; j<38; j++)
	{
		LevelArray[i][j]=186;
	}
	j=38;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	//A
	j=40;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=40; j<44; j++)
	{
		LevelArray[i][j]=186;
	}
	j=44;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=14;
	for(j=40; j<44; j++)
	{
		LevelArray[i][j]=186;
	}
	
	//N
	j=46;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	LevelArray[12][46]=186;
	LevelArray[13][47]=186;
	LevelArray[14][48]=186;
	j=49;
	for(i=12; i<16; i++)
	{
		SetColorAtPoint(i, j, FOREGROUND_RED | FOREGROUND_INTENSITY);
		LevelArray[i][j]=186;
	}
	LevelArray[38][24]=' ';
	LevelArray[38][51]=' ';
	

	PlaceCursor(0,0);
	
	for(int u=0; u<rows; u++)
	{
		for(int h=0; h<columns; h++)
		{	
			cout<<LevelArray[u][h];
		}
		cout<<endl;
	}
	
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{	
			SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
	}
	PlaceCursor(52,15);
	cout<<'\1'<<" "<<'\1'<<" "<<'\1';
	for(i=5; i<16; i++)
	{
		for(j=10; j<70; j++)
		{
			SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
	}
	
	int checkkey=-1;
	
	PlaceCursor(29,37);
	cout<<"GAME DEVELOPED BY:\n";
	
	PlaceCursor(25,38);
	cout<<"I B R A H I M  Z A H O O R";
	i=38;
	for(j=24; j<53; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	PlaceCursor(31,20);
	cout<<"S T A R T     M E N U";
	i=20;
	for(j=31; j<54; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	
	while(1)
	{
		checkkey=Menu();

		if(checkkey=='B' || checkkey=='b')
		{
			PlaceCursor(29,29);
			cout<<"GAME  INSTRUCTIONS\n";
			i=29;
			for(j=29; j<49; j++)
			{
				SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			PlaceCursor(29,31);
			cout<<"PACMAN MOVEMENT\n";
			PlaceCursor(29,32);
			cout<<"For Up   UP KEY";
			PlaceCursor(29,33);
			cout<<"For Down  DOWN KEY";
			PlaceCursor(29,34);
			cout<<"For Right  RIGHT KEY";
			PlaceCursor(29,35);
			cout<<"For Left  LEFT KEY";
			Sleep(4000);
			PlaceCursor(29,29);
			cout<<"                   ";
			PlaceCursor(29,31);  
			cout<<"               ";
			PlaceCursor(29,32);  
			cout<<"               ";
			PlaceCursor(29,33);     
			cout<<"                  ";
			PlaceCursor(29,34);       
			cout<<"                    ";
			PlaceCursor(29,35);     
			cout<<"                  ";
		}
	
		else if(checkkey=='C' || checkkey=='c')
		{
			PlaceCursor(29,29);
			cout<<"GAME  RULES\n";
			i=29;
			for(j=29; j<49; j++)
			{
				SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			PlaceCursor(5,31);
			cout<<"PACMAN HAVE 4 LIVES\n";
			PlaceCursor(5,32);
			cout<<"EAT MORE & MORE POINTS TO HAVE MAXIMUM SCORE";
			PlaceCursor(5,33);
			cout<<"WHEN YOU EAT BLUE POINT PACMAN CAN EAT GHOST WITH THE 10 EXTRA POINTS";
			PlaceCursor(5,34);
			cout<<"WHEN PACMAN EATS BLUE POINT IT CAN EAT THE GHOSTS IN SPECIFIC TIME";
			
			Sleep(8000);
			
			PlaceCursor(29,29);
			cout<<"             ";
			
			PlaceCursor(5,31);          
			cout<<"                   ";
			PlaceCursor(5,32);                                    
			cout<<"                                            ";
			PlaceCursor(5,33);                                                            
			cout<<"                                                                     ";
			PlaceCursor(5,34);                                                       
			cout<<"                                                                  ";
		}
		else if(checkkey=='A' || checkkey=='a')
		{
			break;
		}
	}
}

char Menu()
{
	char checkkey=0;
	PlaceCursor(29,22);
	cout<<"PRESS A  TO START GAME....";
	PlaceCursor(29,24);
	cout<<"PRESS B TO SEE INSTRUCTIONS";
	PlaceCursor(29,26);
	cout<<"PRESS C TO SEE GAME RULES";
	
	checkkey=CheckKeyPressed(30000);
		
	return checkkey;
}

void MovePacman(char StageArray[][columns],char Lives[], int rows, int &score, int &life)
{
	int pacman_x=30, pacman_y=21, ghost1_x=3, ghost1_y=37,ghost2_x=34,ghost2_y=3;
	int movement=0, time=0;
	PrintScoreLives(Lives, score, life);
	
	PlaceCursor(pacman_y, pacman_x);
	cout<<'\1';
	SetColorAtPoint(pacman_y, pacman_x,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	
	while(score<81)
	{
		movement=CheckKeyPressed(20000);
		
		if(movement==40)
		{
			DownMove( StageArray, Lives, pacman_x, pacman_y, score, life, time, ghost1_x, ghost1_y, ghost2_x, ghost2_y);
		}
		
		if(movement==38)
		{
			UpMove( StageArray, Lives, pacman_x, pacman_y, score, life, time, ghost1_x, ghost1_y, ghost2_x, ghost2_y);
		}
		
		if(movement==39)
		{
			RightMove( StageArray, Lives, pacman_x, pacman_y, score, life, time, ghost1_x, ghost1_y, ghost2_x, ghost2_y);
		}
			
		if(movement==37)
		{
			LeftMove( StageArray, Lives, pacman_x, pacman_y, score, life, time, ghost1_x, ghost1_y, ghost2_x, ghost2_y);
		}
	}
}

void DownMove(char StageArray[][columns], char Lives[],int &pacman_x, int pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj)
{
	bool answer=true;
	while(answer==true && CheckKeyPressed1()==0 && life>0)
	{
		if(time==0)
		{
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, ii, jj);
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, iii, jjj);
		}
		else if (time>0)
		{
			SetColorAtPoint(15,24, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			SetColorAtPoint(26,22, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, ii, jj);
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, iii, jjj);
			time=time-1;
		}
		
		if(StageArray[pacman_x+1][pacman_y]!=0)
		{
			StageArray[pacman_x][pacman_y]=' ';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			
			pacman_x++;
			
			if(StageArray[pacman_x][pacman_y]=='.')
			{
				score=score+1;
			}
			else if(StageArray[pacman_x][pacman_y]=='o')
			{
				score=score+1;
				time=60;
			}
			
			StageArray[pacman_x][pacman_y]='\1';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			PlaceCursor(pacman_y,pacman_x);
			SetColorAtPoint(pacman_y, pacman_x,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else
		{
			answer=false;
			PlaceCursor(pacman_y,pacman_x);
		}
		PrintScoreLives(Lives, score, life);

		
		
	}
}

void UpMove(char StageArray[][columns],char Lives[], int &pacman_x, int pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj)
{
	bool answer=true;

	while(answer==true && CheckKeyPressed1()==0  && life>0)
	{
		
		if(time==0)
		{
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, ii, jj);
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, iii, jjj);
		}
		else if (time>0)
		{
			SetColorAtPoint(15,24, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			SetColorAtPoint(26,22, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, ii, jj);
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, iii, jjj);
			time=time-1;
		}
		
		if(StageArray[pacman_x-1][pacman_y]!=0)
		{
			StageArray[pacman_x][pacman_y]=' ';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			
			pacman_x--;
			
			if(StageArray[pacman_x][pacman_y]=='.')
			{
				score=score+1;
			}
			else if(StageArray[pacman_x][pacman_y]=='o')
			{
				score=score+1;
				time=60;
			}
			StageArray[pacman_x][pacman_y]='\1';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			PlaceCursor(pacman_y,pacman_x);
			SetColorAtPoint(pacman_y, pacman_x, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else
		{
			answer=false;
			PlaceCursor(pacman_y,pacman_x);
		}
		PrintScoreLives(Lives, score, life);
		
		
	}
}

void RightMove(char StageArray[][columns],char Lives[], int pacman_x, int &pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj)
{
	bool answer=true;				
	while(answer==true && CheckKeyPressed1()==0  && life>0)
	{
		if(time==0)
		{
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, ii, jj);
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, iii, jjj);
		}
		else if (time>0)
		{
			SetColorAtPoint(15,24, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			SetColorAtPoint(26,22, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, ii, jj);
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, iii, jjj);
			time=time-1;
		}
		
		if(StageArray[pacman_x][pacman_y+1]!=0)
		{
			StageArray[pacman_x][pacman_y]=' ';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			
			pacman_y++;
			
			if(StageArray[pacman_x][pacman_y]=='.')
			{
				score=score+1;
			}
			else if(StageArray[pacman_x][pacman_y]=='o')
			{
				score=score+1;
				time=60;
			}
			StageArray[pacman_x][pacman_y]='\1';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			PlaceCursor(pacman_y,pacman_x);
			SetColorAtPoint(pacman_y, pacman_x, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);		
		}
		else
		{
			answer=false;
			PlaceCursor(pacman_y,pacman_x);
		}
		PrintScoreLives(Lives, score, life);
		
		
		
	}
}

void LeftMove(char StageArray[][columns],char Lives[], int pacman_x, int &pacman_y, int &score, int &life, int &time, int &ii, int &jj, int &iii, int &jjj)
{
	bool answer=true;
	
	while(answer==true && CheckKeyPressed1()==0  && life>0)
	{
		if(time==0)
		{
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, ii, jj);
			GhostRunToPacman(StageArray, Lives, pacman_x, pacman_y, life, iii, jjj);
		}
		else if (time>0)
		{
			SetColorAtPoint(15,24, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			SetColorAtPoint(26,22, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, ii, jj);
			GhostRunFromPacman(StageArray, Lives, pacman_x, pacman_y, score, life, iii, jjj);
			time=time-1;
		}
		
		if(StageArray[pacman_x][pacman_y-1]!=0)
		{
			StageArray[pacman_x][pacman_y]=' ';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			
			pacman_y--;
			
			if(StageArray[pacman_x][pacman_y]=='.')
			{
				score=score+1;
			}
			else if(StageArray[pacman_x][pacman_y]=='o')
			{
				score=score+1;
				time=60;
			}
			
			StageArray[pacman_x][pacman_y]='\1';
			PlaceCursor(pacman_y,pacman_x);
			cout<<StageArray[pacman_x][pacman_y];
			PlaceCursor(pacman_y,pacman_x);
			SetColorAtPoint(pacman_y, pacman_x, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else
		{
			answer=false;
			PlaceCursor(pacman_y,pacman_x);
		}
		PrintScoreLives(Lives, score, life);
		
	}
}

void PrintScoreLives(char Lives[], int score, int life)
{
	int i=0, j=0;
	PlaceCursor(53,20);
	cout<<"S C O R E  "<<score;
	i=20;
	for(j=53; j<72; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	
	PlaceCursor(53,22);
	cout<<"L I V E S  ";
	i=22;
	for(j=53; j<63; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	
	for(int v=0; v<4; v++)
	{
		cout<<Lives[v];	
	}
	i=22;
	for(j=63; j<73; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	
	
	PlaceCursor(50,26);
	cout<<"C H A R A C T E R S";
	i=26;
	for(j=50; j<72; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	PlaceCursor(53,28);
	cout<<"P A C M A N  "<<'\1';
	i=28;
	for(j=53; j<73; j++)
	{
	SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	PlaceCursor(53,29);
	cout<<"G H O S T    "<<'\2';
	i=29;
	for(j=53; j<73; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	PlaceCursor(53,30);
	cout<<"P O I N T    "<<'.';
	PlaceCursor(53,31);
	cout<<"POWER POINT  "<<'o';
	i=31;
	for(j=53; j<73; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	
}

void DrawLevel(char LevelArray[][columns], int rows)
{
	ClearScreen();
	int i=0, j=0;
	for(j=0; j<79; j++)
	{
		for(i=0; i<rows; i++)
		{	
			LevelArray[i][j]=0;
		}
	}
	for(j=0; j<44; j=j+3)
	{
		for(i=0; i<rows; i=i+3)
		{	
			LevelArray[i][j]='.';
		}
	}
	//power points
	LevelArray[3][3]='o';
	LevelArray[3][39]='o';
	LevelArray[36][3]='o';
	LevelArray[36][39]='o';
	for(i=0; i<2; i++)
	{
		for(j=0; j<79; j++)
		{
			LevelArray[i][j]=178;
		}
	}
	
	for(i=rows-1; i>rows-3; i--)
	{
		for(j=0; j<79; j++)
		{
			LevelArray[i][j]=178;
		}	
	}
	
	for(j=0; j<2; j++)
	{
		for(i=0; i<rows; i++)
		{
			LevelArray[i][j]=178;
		}
	}
	
	for(i=0; i<rows; i++)//square
	{
		for(j=42; j<46; j++)
		{
			LevelArray[i][j]=178;
		}
	}
	
	for(i=0; i<rows; i++)//square
	{
		for(j=75; j<79; j++)
		{
			LevelArray[i][j]=178;
		}
	}
	
	//the following code writes PAC MAN on the left of screen
	j=48;
	for(i=5; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	j=51;
	for(i=5; i<8; i++)//square
	{
		LevelArray[i][j]=186;
	}
		
	i=5;
	for(j=48; j<52; j++)
	{
		LevelArray[i][j]=186;
	}
	i=7;
	for(j=49; j<52; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=53;
	for(i=5; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=5;
	for(j=53; j<57; j++)
	{
		LevelArray[i][j]=186;
	}
	j=56;
	for(i=6; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=7;
	for(j=54; j<56; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=58;
	for(i=6; i<10; i++)//square
	{
		LevelArray[i][j]=186;
	}
	
	i=5;
	for(j=58; j<62; j++)
	{
		LevelArray[i][j]=186;
	}
	
	i=9;
	for(j=59; j<62; j++)
	{
		LevelArray[i][j]=186;
	}
	j=55;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=55; j<59; j++)
	{
		LevelArray[i][j]=186;
	}
	
	j=58;
	for(i=12; i<15; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=59; j<61; j++)
	{
		LevelArray[i][j]=186;
	}
	j=61;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	//A
	j=63;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=12;
	for(j=63; j<67; j++)
	{
		LevelArray[i][j]=186;
	}
	j=67;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	i=14;
	for(j=63; j<67; j++)
	{
		LevelArray[i][j]=186;
	}
	
	//N
	j=69;
	for(i=12; i<16; i++)//square
	{
		LevelArray[i][j]=186;
	}
	
	LevelArray[25][15]='\2';
	LevelArray[20][26]='\2';
	
	LevelArray[12][70]=186;
	LevelArray[13][71]=186;
	LevelArray[14][72]=186;
	j=73;
	for(i=12; i<16; i++)
	{
		LevelArray[i][j]=186;
	}
	
	Obstacles(LevelArray,rows);
	LevelArray[24][15]='\2';
	LevelArray[22][26]='\2';
	
	ClearScreen();
	PlaceCursor(0,0);
	for(int u=0; u<rows; u++)
	{
		for(int h=0; h<columns; h++)
		{	
			cout<<LevelArray[u][h];
			SetColorAtPoint(h,u,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout<<endl;
	}
	for(i=5; i<16; i++)
	{
		for(j=47; j<74; j++)
		{
			SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
	}
	SetColorAtPoint(15,24, FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetColorAtPoint(26,22, FOREGROUND_RED | FOREGROUND_INTENSITY);
	
	SetColorAtPoint(3,3, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(39,3, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(3,36, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(39,36, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	PlaceCursor(47,34);
	cout<<"GAME DEVELOPED BY:\n";
	i=34;
	for(j=47; j<72; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	PlaceCursor(47,36);
	cout<<"\t\tIBRAHIM ZAHOOR";
	i=36;
	for(j=47; j<73; j++)
	{
		SetColorAtPoint(j, i, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	PlaceCursor(16,27);
	cout<<"L E V E L  1";
	i=27;
	for(j=16; j<28; j++)
	{
		SetColorAtPoint(j,i, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
}

void GhostRunToPacman(char StageArray[][columns],char Lives[], int &pacman_x, int &pacman_y, int &life, int &ghost1_x, int &ghost1_y)
{
	SetColorAtPoint(3,3, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(39,3, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(3,36, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetColorAtPoint(39,36, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	if(ghost1_x==pacman_x)
		{
			if(ghost1_y==pacman_y)
			{
				life--;
				Lives[life]=0;
				StageArray[pacman_x][pacman_y]=' ';
				PlaceCursor(pacman_y,pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
				pacman_x=30, pacman_y=21;
				StageArray[pacman_x][pacman_y]='\1';
				PlaceCursor(pacman_y, pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
				SetColorAtPoint(pacman_y, pacman_x, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				Sleep(400);
				StageArray[pacman_x][pacman_y]=' ';
				PlaceCursor(pacman_y, pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
				
			}
			else if (ghost1_y<pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if (StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if (StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
			}
			
			else if (ghost1_y>pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
				else if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
			}
		}
		
		else if (ghost1_y==pacman_y)
		{
			if(ghost1_x==pacman_x)
			{
				life--;
				Lives[life]=0;
				StageArray[pacman_x][pacman_y]=' ';
				PlaceCursor(pacman_y,pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
				pacman_x=30, pacman_y=21;
				StageArray[pacman_x][pacman_y]='\1';
				PlaceCursor(pacman_y, pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
				SetColorAtPoint(pacman_y, pacman_x, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				Sleep(400);
				StageArray[pacman_x][pacman_y]=' ';
				PlaceCursor(pacman_y, pacman_x);
				cout<<StageArray[pacman_x][pacman_y];
			}
			else if (ghost1_x<pacman_x)
			{
				if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
			else if (ghost1_x>pacman_x)
			{
				if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
		}
		
		else if (ghost1_x>pacman_x)
		{
			if(ghost1_y==pacman_y)
			{
				if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
			
			else if(ghost1_y>pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
				else if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
			}
			
			else if(ghost1_y<pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if (StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if (StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
			}
		}
		
		
		else if (ghost1_x<pacman_x)
		{
			if(ghost1_y==pacman_y)
			{
				if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
			
			else if(ghost1_y>pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
				else if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
			}
			
			else if(ghost1_y<pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if (StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if (StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
			}
		}
		
		else if (ghost1_y>pacman_y)
		{
			if(ghost1_x==pacman_x)
			{
				if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
				else if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
			}
			
			else if(ghost1_x>pacman_x)
			{
				if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
			
			else if(ghost1_x<pacman_x)
			{
				if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
		}
		
		else if (ghost1_x<pacman_x)
		{
			if(ghost1_y==pacman_y)
			{
				if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
			}
			
			else if(ghost1_y>pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y-1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y--;
				}
				else if(StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
				else if(StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
			}
			
			else if(ghost1_y<pacman_y)
			{
				if(StageArray[ghost1_x][ghost1_y+1]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_y++;
				}
				else if (StageArray[ghost1_x+1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x++;
				}
				else if (StageArray[ghost1_x-1][ghost1_y]!=0)
				{
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<'\2';
					SetColorAtPoint(ghost1_y, ghost1_x, FOREGROUND_RED | FOREGROUND_INTENSITY);
					Sleep(100);
					PlaceCursor(ghost1_y,ghost1_x);
					cout<<StageArray[ghost1_x][ghost1_y];
					ghost1_x--;
				}
			}
		}
}

void GhostRunFromPacman(char StageArray[][columns],char Lives[], int &pacman_x, int &pacman_y, int &score, int &life, int &ghost2_x, int &ghost2_y)
{
		if(ghost2_x==pacman_x)
		{
			if(ghost2_y==pacman_y)
			{
				score=score+10;
				ghost2_x=18, ghost2_y=20;
				PlaceCursor(ghost2_y, ghost2_x);
				cout<<'\2';

			}
			else if (ghost2_y<pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				else if (StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				else if (StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
			}
			
			else if (ghost2_y>pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				else if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				else if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
			}
		}
		
		else if (ghost2_y==pacman_y)
		{
			if(ghost2_x==pacman_x)
			{
				score=score+10;
				ghost2_x=18, ghost2_y=23;
				PlaceCursor(ghost2_y, ghost2_x);
				cout<<'\2';
				SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if (ghost2_x<pacman_x)
			{
				if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
			}
			else if (ghost2_x>pacman_x)
			{
				if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
			}
		}
		
		else if (ghost2_x>pacman_x)
		{
			if(ghost2_y==pacman_y)
			{
				if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
			}
			
			else if(ghost2_y>pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				else if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					Sleep(80);
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				else if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
			}
			
			else if(ghost2_y<pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					Sleep(80);
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				else if (StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				else if (StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				
			}
		}
		
		
		else if (ghost2_x<pacman_x)
		{
			if(ghost2_y==pacman_y)
			{
				if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
			}
			
			else if(ghost2_y>pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				
				else if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				else if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
			}
			
			else if(ghost2_y<pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				
				else if (StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}else if (StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
			}
		}
		
		else if (ghost2_y>pacman_y)
		{
			if(ghost2_x==pacman_x)
			{
				if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				
				else if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}else if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
			}
			
			else if(ghost2_x>pacman_x)
			{
				if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
			}
			
			else if(ghost2_x<pacman_x)
			{
				if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					Sleep(80);
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
			}
		}
		
		
		else if (ghost2_x<pacman_x)
		{
			if(ghost2_y==pacman_y)
			{
				if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
				
				else if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}else if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
			}
			
			else if(ghost2_y>pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y+1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y++;
				}
				
				else if(StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
				else if(StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}
			}
			
			else if(ghost2_y<pacman_y)
			{
				if(StageArray[ghost2_x][ghost2_y-1]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_y--;
				}
				
				else if (StageArray[ghost2_x-1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x--;
				}else if (StageArray[ghost2_x+1][ghost2_y]!=0)
				{
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<'\2';
					SetColorAtPoint(ghost2_y, ghost2_x, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					Sleep(80);
					PlaceCursor(ghost2_y,ghost2_x);
					cout<<StageArray[ghost2_x][ghost2_y];
					ghost2_x++;
				}
			}
			
		}
}

void Obstacles(char DrawObstacles[][columns], int rows)
{
	int i=0, j=0;
	for(i=5; i<17; i++)//square
	{
		for(j=5; j<16; j++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(i=5; i<17; i++)//square
	{
		for(j=27; j<38; j++)
		{
			DrawObstacles[i][j]=178;
		}	
	}
	
	for(j=20; j<22; j++) //plus
	{
		for(i=5; i<17; i++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(j=5; j<7; j++) //plus
	{
		for(i=20; i<29; i++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(j=11; j<13; j++) //plus
	{
		for(i=20; i<29; i++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	i=20;
	for(j=13; j<18; j++)
	{
		DrawObstacles[i][j]=178;
	}
	
	for(i=26; i<29; i++)
	{
		for(j=13; j<30; j++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(j=30; j<32; j++) //plus
	{
		for(i=20; i<29; i++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	i=20;
	for(j=25; j<30; j++)
	{
		DrawObstacles[i][j]=178;
	}
	
	for(j=36; j<38; j++) //plus
	{
		for(i=20; i<29; i++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(i=32; i<35; i++)
	{
		for(j=5; j<38; j++)
		{
			DrawObstacles[i][j]=178;
		}
	}
	
	for(i=21; i<26; i++)
	{
		for(j=13; j<30; j++) //inside box
		{
			DrawObstacles[i][j]=' ';
		}
	}
	
	// it creates spaces between the dots
	int y=3, x2=5, x1=0;
	for(x1=4; x1<36; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	y=39, x2=5;
	for(x1=4; x1<36; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	y=18, x2=5;
	for(x1=4; x1<18; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	y=24, x2=5;
	for(x1=4; x1<18; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	y=9, x2=20;
	for(x1=19; x1<31; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	y=33, x2=20;
	for(x1=19; x1<31; x1=x1+3)
	{
		DrawObstacles[x1][y]=' ';
		DrawObstacles[x2][y]=' ';
		x2=x2+3;
	}
	int q=3, r2=5, r1=0;
	for(r1=4; r1<38; r1=r1+3)
	{
		DrawObstacles[q][r1]=' ';
		DrawObstacles[q][r2]=' ';
		r2=r2+3;
	}
	q=18, r2=5;
	for(r1=4; r1<38; r1=r1+3)
	{
		DrawObstacles[q][r1]=' ';
		DrawObstacles[q][r2]=' ';
		r2=r2+3;
	}
	q=30, r2=5;
	for(r1=4; r1<38; r1=r1+3)
	{
		DrawObstacles[q][r1]=' ';
		DrawObstacles[q][r2]=' ';
		r2=r2+3;
	}
	q=36, r2=5;
	for(r1=4; r1<38; r1=r1+3)
	{
		DrawObstacles[q][r1]=' ';
		DrawObstacles[q][r2]=' ';
		r2=r2+3;
	}
}
