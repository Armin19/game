#include<iostream.h>
#include<conio.h>
#include<dos.h>
char funckey(int &T)
{
char c=getch();
if(c==0)
{
T=1;
c=getch();
}
else
T=0;
return c;
}
void chapkon(int x,int y,char c,int color,
int light,int bgcolor,int blink)
{
int far*SCR=(int far*)0xB8000000;
int v=color+8*light+16*bgcolor+128*blink;
SCR[y*80+x]=v*256+c;
}
int main()
{
int x=40,y=13,vx=-1,vy=1;
int px=40;
clrscr();
chapkon(px,24,'_',4,1,0,0);
int isfunc;
char c=funckey(isfunc);
while(!(kbhit()&&c==27))
{
if(kbhit())
{
c=funckey(isfunc);
if(isfunc)
{
switch(c){
case 'K':
if (px>0)px-=1;
break;
case 'M':
if (px<80)px+=1;
}
{
chapkon(x,y,' ',0,1,0,0);
x=x+vx;
y=y+vy;
if(x==0||x==79)
{
vx=vx*-1;
if(y==0 || y==24)
{
vy=vy*-1;
}
chapkon(x,y,'0',3,0,0,0);
delay(300);
}
}
}
}
}
return 0;
}