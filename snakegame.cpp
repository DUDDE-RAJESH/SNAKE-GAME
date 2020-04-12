#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,score;
int  fruitx,fruity;
int tailx[100],taily[100];
int ntail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	score=0;
	fruitx=rand() % width;
	fruity=rand() % height;
	
}
void draw()
{
  system("cls");
    for(int k=0;k<width+2;k++)
    {
    cout<<"#";
    }
    cout<<endl;
  	for(int i=0;i<height;i++)
  	{
  	for(int j=0;j<width;j++)
  	{
  	if(j==0)
  	cout<<"#";
  	if(i==y && j==x)
  	 cout<<"O";
  	else if(i==fruity && j==fruitx)
  	 cout<<"F";
  	else
  	{
  	bool print=false;
  	for(int n=0;n<ntail;n++)
  	{
  		if(tailx[n]==j && taily[n]==i)
  	    {
  		cout<<"o";
  		print=true;
        }
    }
	    if(!print)
	    {
	      cout<<" ";
	    }
  	}
  	if(j==width-1)
  	cout<<"#";
    }
    cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {
  	cout<<"#";
    }
    cout<<endl;
	cout<<"score:"<<score<<endl; 
}
void input()
{
  if(_kbhit())
  {
  	switch(_getch())
  	{
  		case 'a':
  			dir=LEFT;
  			break;
  		case 'd':
  			dir=RIGHT;
  			break;
  		case 's':
  			dir=DOWN;
  			break;
  		case 'w':
  			dir=UP;
  			break;
  		case 'x':
  			gameover=true;
  			break;
	  }
	  }	
}
void logic()
{  
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x;int prev2y;
    tailx[0]=x;
   	taily[0]=y;
    for(int i=1;i<ntail;i++)
    {
    	prev2x=tailx[i];
    	prev2y=taily[i];
    	tailx[i]=prevx;
    	taily[i]=prevy;
    	prevx=prev2x;
    	prevy=prev2y;
	}
	switch(dir)
	{
		
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
		 break;
	}
	if(x>width || x<0 || y>height || y<0)
	gameover=true;	
    for(int i=0;i<ntail;i++)
    {
    	if(tailx[i]==x && taily[i]==y)
    	gameover=true;
	}
	if(x==fruitx && y==fruity)
	{
	score+=10;
    fruitx=rand()%(width);
    fruity=rand()%(height);
  	ntail++;
    }
}
int main()
{
	cout<<"SNAKE GAME"<<endl;
	sleep(1.5);
		cout<<"a-to move left"<<endl;
		cout<<"d-to move right"<<endl;
		cout<<"w-to move up "<<endl;
		cout<<"s-to move down"<<endl;
	        cout<<"use small letters for input"<<endl;
	        cout<<"don't swing the snake(forward-backward move)it terminate the game"<<endl;
		cout<<"press x-to exit"<<endl;
		sleep(2.5);
	system("clr");
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		sleep(0.7);
	}
	if(gameover)
	system("cls");
	cout<<"Game Over"<<endl;
	cout<<"score:"<<score<<endl;
	return 0;
}

