#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>

using namespace std;
void logo()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
  rectangle(250,30,387,48);
  rectangle(275,143,398,160);
  rectangle(275,175,398,192);
}
void main()
{
  clrscr();
  char u[20],p[20];
  logo();
  gotoxy(34,3);
  cout<<"FacebookLogin";
  gotoxy(25,10);
  cout<<"Username:";
  gotoxy(25,12);
  cout<<"Password:";
  gotoxy(51,10);
  cout<<"(Press enter after entering)";
  gotoxy(51,12);
  cout<<"(8 characters only)";
  gotoxy(36,10);
  gets(u);
  gotoxy(36,12);
  for(int i=0;i<8;++i)
    {
      p[i]=getch();
      cout<<"*";
    }
  p[i]='\0';
  getch();
  gotoxy(20,20);
  cout<<"Plz wait Redirecting";
  for(int j=0;j<8;++j)
    {
      sleep(1);
      cout<<".";
    }
}
