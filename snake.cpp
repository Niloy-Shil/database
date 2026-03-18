#include <bits/c++config.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sys/poll.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <termios.h>
#include <vector>

using namespace  std;

//------------linux input setting----------
struct termios orig_termios;
void disableRawMode()
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH,&orig_termios );
}
void enableRawMode()
{
  tcgetattr(STDIN_FILENO,&orig_termios);
  atexit(disableRawMode);// to take back terminal like default
  struct termios raw=orig_termios;
  raw.c_lflag &=~(ICANON | ECHO);// for disable waiting for enter and to not show what i enter
  tcsetattr(STDIN_FILENO,TCSAFLUSH , &raw);
}

//---------------end--------------
bool kbhit()
{
  struct pollfd fds;
  fds.fd = STDIN_FILENO;
  fds.events = POLLIN;
  return poll(&fds,1,100)==1;
}
//-----------------All the Variables-----------------
bool Bon=false;
size_t life =5;
bool gameO;
const int height =20;
const int width =height*2;
int a,b,fruita,fruitb,score=0;
pair<int,int>bonus;
int sideS=1;
enum Dire{ STOP=0,LEFT,RIGHT,UP,DOWN};
Dire dir;
vector<pair<int,int>> snake,preSnake;


//---------------------------------------------
void randomNum()
{
fruita = rand() % width;
fruitb = rand() % height;
}
void randomBonus()
{
bonus={rand()%width,rand()%height};
}

//------------------------SetUp-----------------------------
void Setup()
{
gameO=false;  
dir = STOP;
a = width/2;
b = height/2;
snake.push_back({a,b});
randomNum();
randomBonus();
score =0;
}
//---------------------Draw-----------------------------
void Draw()
{
  bool print = true;
    system("clear");
  for(int i=0;i<width;i++)//top of box
    cout<<"#";
  cout<<"\n";
  
for (int i=0;i<height;i++)
{
  for(int j=0;j<=width;j++)
  {
    if(j == 0 || j==(width -1))
      {cout<<"#" ; print =false;}
  
    else  if(i== fruitb && j==fruita) 
      {cout<<"F" ; print =false;}
    else if(Bon == true && i== bonus.second && j==bonus.first)
    {
      cout<<"*";print =false;
    }
    else print = true;
    
      for (int k=0;k<snake.size();k++)
      {
        pair<int,int> nE = {j,i};
       if(snake[k]==nE)
          {
          k==0?cout <<"O" : cout <<"o";
          print = false;
        break;
        }
     }
     if(print)
     cout<<" ";
      
  }

cout<<"\n";
}

   for(int i=0;i<width;i++)// bottom of box 
    cout<<"#";

  cout<<"\n"; 
}

//---------------------------------Input-----------------------
void Input()
{
  Dire d = dir;
  int e=1;
  if(kbhit())
  {
      switch (getchar()) 
  {
  case 'a': d==RIGHT ? dir=RIGHT : dir = LEFT; break;
    
case 'd': d==LEFT ?  dir = LEFT : dir = RIGHT; break;
    
case 'w': d==DOWN ? dir = DOWN : dir = UP; break;
    
case 's': d==UP ? dir= UP : dir = DOWN; break;
  
case 'q': gameO=true; break;
  
    }
  }
}
//---------------------Logic------------------
  void Logic()
{
    pair<int,int> n={a,b}; 
 switch (dir) 
  {
case  LEFT: 
    a--; 
    if(a<0) {a=(width-1); life-=1; }  break;
    
case RIGHT: a++; 
   if(a >= width-1) { a=0 ; life-=1;} break;
    
case UP: b--; 
    if(b<0){ b = height-1; life-=1;} break;
case DOWN: b++; 
   if(b >= height ){b =0 ; life-=1;}  break;
defalut:  break;
    }
    if(a==bonus.first && b==bonus.second)
    {
      score+=20;
      sideS+=1;
      Bon =false;
      randomBonus();
    }
    if(a==fruita && b== fruitb)
    {
      score+=1;
      sideS+=1;
      snake.push_back(n);
      randomNum();
    }
    if(sideS%6==0)  
      Bon = true;
    else
     Bon =false;
    
    preSnake = snake;
    snake[0]={a,b};
    if(snake.size()>1)
      for(int i=0;i<snake.size()-1;i++)//working-------
         snake[i+1]=preSnake[i];
    for(int i=1;i<snake.size();i++)
    {
      if(snake[0]==snake[i])
      life=0;
    }
  if(life ==0) gameO = true;
    
}

//----------------------------Main-------------------------
int main()
{
  enableRawMode();
  Setup();
  while(!gameO)
  {
    Draw();
    Input();
    Logic();
    cout<<"\tscore:"<<score<<"\t life:"<<life<<"\n";
  }
if(life==0) cout<<"\t\tgame over\n";
 }
