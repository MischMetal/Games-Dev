#include<GRAPHICS.H>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

int initmouse();
void showmouseptr();
void hidemouseptr();
void getmousepos(int*,int*,int*);

union REGS i, o;

int u, v, COD, temp, score;

void draw(int x, int y, int code, int time)
{
	circle(x,y,25);

	setcolor(getmaxcolor());

	u=639;
	v=479;

	switch(code){
	case 0:
	setfillstyle(SOLID_FILL,RED);
	circle(u/4,v/4,10);
	break;
	case 1:setfillstyle(SOLID_FILL,RED);
	circle((2*u)/4,v/4,10);
	break;
	case 2:setfillstyle(SOLID_FILL,RED);
	circle((3*u)/4,v/4,10);
	break;
	case 3:setfillstyle(SOLID_FILL,RED);
	circle(u/4,(2*v)/4,10);
	break;
	case 4:setfillstyle(SOLID_FILL,RED);
	circle(u/4,(3*v)/4,10);
	break;
	case 5:setfillstyle(SOLID_FILL,RED);
	circle((2*u)/4,(2*v)/4,10);
	break;
	case 6:setfillstyle(SOLID_FILL,RED);
	circle((3*u)/4,(2*v)/4,10);
	break;
	case 7:setfillstyle(SOLID_FILL,RED);
	circle((2*u)/4,(3*v)/4,10);
	break;
	case 8:setfillstyle(SOLID_FILL,RED);
	circle((3*u)/4,(3*v)/4,10);
	break;
	default:break;
	}
	setfillstyle(SOLID_FILL,getmaxcolor());
	rectangle(215,445,425,465);
	rectangle(220,450,time,460);
}

main()
{
   int gd = DETECT, gm, status, button, x, y, tempx, tempy;
   char array[50], c;
   int T=220;

   randomize();

   initgraph(&gd,&gm,"C:\\TC\\BGI");
   settextstyle(DEFAULT_FONT,0,2);

   cleardevice();
   printf("\n\n\n\n\t\tTAKE YOUR MOUSE POINTER TO THE CIRCLES");
   printf("\n\t\t\tBEFORE TIME'S UP!");
   getch();
   cleardevice




   () ;

   status = initmouse();

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();

      getmousepos(&button,&x,&y);

      renew:

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	    cleardevice();
	    draw(x,y,COD,T);
	    if(score>=1)
	    T++;
	    if(T>=420){
		gotoxy(getmaxx()/2,getmaxy()/2);
		printf("GAME OVER!  SCORE: %d\nPress 'x' to exit",score);
		getch();
		exit(0);}

	switch(COD)
	{
	 case 0:if( x<170  &&  x>150  && y<130  && y>110  )
		       {T=220;
		       temp=COD;
			fu1:
			COD=rand()%9;
			if(COD==temp)
				goto fu1;
			else
				score++;}
		break;
	 case 1:if( x<330  &&  x>310  && y<130  && y>110  )
		       {	temp=COD;
			T=220;
			fu2:
			COD=rand()%9;
			if(COD==temp)
				goto fu2;
			else
				score++;}
		break;
	 case 2:if( x<490  &&  x>470  && y<130  && y>110  )
		       {	temp=COD;
			T=220;
			fu3:
			COD=rand()%9;
			if(COD==temp)
				goto fu3;
			else
				score++;}
		break;
	 case 3:if( x<170  &&  x>150  && y<250  && y>230  )
		      {T=220;
		      temp=COD;
			fu4:
			COD=rand()%9;
			if(COD==temp)
				goto fu4;
			else
				score++;}
		break;
	 case 4:if( x<170  &&  x>150  && y<370  && y>350  )
			{temp=COD;
			T=220;
			fu5:
			COD=rand()%9;
			if(COD==temp)
				goto fu5;
			else
				score++;}
		break;
	 case 5:if( x<330  &&  x>310  && y<250  && y>230  )
			{temp=COD;
			T=220;
			fu6:
			COD=rand()%9;
			if(COD==temp)
				goto fu6;
			else
				score++;}
		break;
	 case 6:if( x<490  &&  x>470  && y<250  && y>230  )
			{temp=COD;
			T=220;
			fu7:
			COD=rand()%9;
			if(COD==temp)
				goto fu7;
			else
				score++;}
		break;
	 case 7:if( x<330  &&  x>310  && y<370  && y>350  )
			{temp=COD;
			T=220;
			fu8:
			COD=rand()%9;
			if(COD==temp)
				goto fu8;
			else
				score++;}
		break;
	 case 8:if( x<490  &&  x>470  && y<370  && y>350  )
			{temp=COD;
			T=220;
			fu:
			COD=rand()%9;
			if(COD==temp)
				goto fu;
			else
				score++;}
		break;
	 default:
		break;

	}
      }
      c=getch();
      if(c=='x')
	exit(0);
      else
	goto renew;
   }

   getch();
   return 0;
}

int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}
