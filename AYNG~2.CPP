#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

char background=178;

class player
	{
	public:

	float location;
	int lives;
	int killed;
	char weapon;
	char weaponname[10];
	int score;
	int level;
	int goldm;
	char name[40];
	void gold()
	{
	goldm+=25;
	}
	player()
	{
	key=0;
	goldm=0;
	}
	int key;
	void getname()
		{
		cout<<"enter your name ";
		gets(name);
		getch();
		clrscr();
		}
	void levelup()
		{
		level++;
		}
	};
class display:public player
	{
	char rock;
	int sroomvar;
	char gun, grenade, shield;
	char vbar;
	char hbar;
	char rhbc;
	char rhtc;
	char lhbc;
	char lhtc;
	int keyvar;
	int moneyvar;
	int goldvar;
	int unlocked;
	int blasted;
	public:
	display()
		{
		 location= 0.0;
		 blasted=0;
		 lives=5;
		 weapon='-';
		 sroomvar=0;
		 gun=169;
		 grenade=248;
		 shield=232;
		 ekey=0;
		 vbar=186;
		 hbar=205;
		 rhbc=188;
		 rhtc=187;
		 lhbc=200;
		 lhtc=201;
		keyvar=goldvar=moneyvar=0;
		unlocked=0;
		rock=15;
		killed=0;
		}
	void secretdungeon()
	{
	clrscr();
	cout<<"Secret Room";
	sleep(1);
	weaponroom();
	}
	void weaponroom();

	int ekey;
	void move();
	char disp[25][75];
	void innitial();
	int moveprototype();
	void level1();
	void level2();
	void level3();
	void screenshow();
	void cavernpass();
	void cavernblock();
	};
void display::cavernpass()
	{

	   for(int i=1;i<29;i++)
		{
		int run=i;
		disp[11][69-run]=1;
		disp[11][70-run]=178;
		disp[5][69-i]=178;
		disp[6][69-i]='V';
			if(i>1)
			for(int ij=0;ij<i;ij++)
			disp[6][69-ij]=178;
		screenshow();
		delay(70);
			for(int f=11;f>6;f--)
			      for(int y=0;y<28;y++)
			      disp[f][68-y]=disp[f-1][68-y];
		}
	       disp[11][39]=1;
	}

void display::cavernblock()
{
disp[11][68]=1;
disp[11][69]=178;
char hsbar=196;
int u=5, v=70;
for(int ip=0;disp[u+ip+1][v-2]!=hbar;ip++)
	    {
	    disp[u+ip][v-2]=178;
	    disp[u+ip+1][v-2]='V';
	    delay(70);
	    screenshow();
	    }

lives--;
disp[11][68]='V';
disp[11][69]=178;
disp[11][70]=1;
screenshow();
}
void display::move()
	{
		char ar[3][75];
		for(int i=0;i<75;i++)
		{ar[0][i]=ar[2][i]=hbar;
		ar[1][i]=178;}
		ar[1][0]=1;
		for(int m=1;m<75;m++)
		{
		delay(50);
		clrscr();
		char t;
		t=ar[1][m-1];
		ar[1][m-1]=ar[1][m];
		ar[1][m]=t;
		for(int o=0;o<3;o++)
		{
		for(int p=0;p<75;p++)
		cprintf("%c",ar[o][p]);
		cout<<"\n";
		}}
	clrscr();
	}
void display::innitial()
	{
	disp[1][1]=1;
	for(int i=0;i<25;i++)
	for(int j=0;j<75;j++)
	disp[i][j]=178/*177*/;
	}
void display::level1()
	{
	innitial();

	location=1.0;

	if(moneyvar<8)
	disp[2][70]='$';

	if(sroomvar==0)
	disp[1][1]=1;
	if(sroomvar==1)
	disp[6][8]=1;
	// standard declaration
	for(int i=1;i<24;i++)
	disp[i][0]=disp[i][73]=vbar;    // vertical screen border
	for(int j=1;j<74;j++)
	disp[0][j]=disp[23][j]=hbar;    // horizontal screen border
	//screen corners
	disp[0][0]=lhtc;
	disp[0][73]=rhtc;
	disp[23][0]=lhbc;
	disp[23][73]=rhbc;
	//...
	disp[0][35]=209;

	 disp[4][0]=199;
	 for(int r=1;r<69;r++)
	 disp[4][r]=196;
	 disp[4][35]=193;
			if(unlocked<1)
			disp[2][35]=254;
	 disp[3][35]=disp[1][35]=179;

	 disp[4][10]=194;
	 disp[5][10]=disp[6][10]=disp[7][10]=disp[8][10]=disp[9][10]=179;
	 disp[10][10]=217;
	 for(int y=1;y<10;y++)
	 disp[10][y]=196;
	 disp[10][0]=199;

	disp[22][70]=202;
	disp[21][70]=206;
	disp[20][70]=203;
	disp[20][69]=201;
	disp[20][71]=187;
	disp[21][69]=204;
	disp[21][71]=185;
	disp[22][69]=200;
	disp[22][71]=188;



	 disp[4][9]=disp[4][8]=disp[4][7]=178;


	disp[5][2]=218;
	disp[6][2]=179;
	disp[7][2]=195;
	disp[8][2]=192;

	disp[5][3]=196;
	disp[6][3]=218;
	disp[7][3]=180;
	disp[8][3]=193;

	disp[5][4]=194;
	disp[6][4]=180;
	disp[7][4]=179;
	disp[8][4]=193;

	disp[5][6]=191;
	disp[6][6]=disp[7][6]=179;
	disp[8][6]=217;

	disp[5][5]=194;
	disp[6][5]=disp[7][5]=179;
	disp[8][5]=193;

	//
	disp[0][40]=209;
	disp[4][39]=disp[4][38]=disp[4][37]=disp[4][36]=178;
	disp[4][40]=195;
	disp[1][40]=disp[3][40]=179;
			if(unlocked<2)
			disp[2][40]=254;
	disp[5][40]=disp[6][40]=179;
	disp[6][40]=217;
	for(int f=14;f<40;f++)
	disp[6][f]=disp[10][f]=196;
	for(int yt=11;yt<37;yt++)
	disp[8][yt]=196;
	disp[8][10]=195;
	for(int g=5;g<10;g++)
	disp[g][40]=179;
	disp[6][40]=180;
	disp[10][40]=217;
	disp[10][14]=218;
	for(int rf=11;rf<23;rf++)
	disp[rf][14]=179;


	disp[12][11]=rock;


	disp[13][14]=180;
	for(int hu=7;hu<14;hu++)
	disp[13][hu]=196;
	disp[13][6]=218;
	disp[21][6]=disp[22][6]=179;
	if(killed==0)
	disp[20][5]=2;
	disp[23][6]=207;
	for(int ki=14;ki<20;ki++)
	disp[ki][6]=179;
	if(moneyvar==0)
	{
	disp[17][10]=disp[16][11]=disp[15][10]=disp[14][11]='$';
	disp[18][11]=disp[19][10]=disp[20][11]='$';
	}
	if(keyvar<2)
	disp[21][10]=231;
	disp[23][14]=207;
	// cavern

	for(int il=41;il<69;il++)
	disp[5][il]='V';
	for(int huy=5;huy<11;huy++)
	disp[huy][69]=179;
	disp[12][69]=193;
	disp[12][70]=disp[12][71]=disp[12][72]=196;
	disp[12][73]=182;
	for(int ho=30;ho<69;ho++)
	disp[12][ho]=196;
	disp[4][69]=191;

	//blast path

	disp[22][14]=178;
	disp[21][14]=195;
	for(int ru=0;ru<20;ru++)
		{
		disp[21][15+ru]=196;
		if(blasted==0)
		disp[22][15+ru]=176;
		}
	disp[21][35]=217;
	disp[20][35]=179;
	disp[20][38]=disp[19][38]=disp[21][38]=disp[22][38]=179;
	disp[23][38]=207;
	disp[18][35]=218;
	disp[18][38]=191;
	disp[18][36]=disp[18][37]=196;

	if(moneyvar<14 && blasted==0)
	disp[19][36]=disp[19][37]=disp[20][36]=disp[20][37]=disp[21][36]=disp[21][37]='$';

	disp[18][35]=194;
	disp[18][34]=196;
	disp[18][33]=194;
	disp[19][33]=179;
	disp[21][31]=193;
	disp[20][31]=179;
	if(killed!=15)
	disp[19][32]=2;
	for(int it=0;it<10;it++)
	disp[18][32-it]=196;
	disp[18][20]=194;
	disp[18][19]=disp[18][18]=disp[18][17]=disp[18][16]=disp[18][15]=196;
	disp[18][14]=195;
	disp[19][20]=179;
	disp[21][20]=193;
	disp[19][16]=169;

	disp[23][44]=207;
	for(int yu=1;yu<7;yu++)
	disp[23-yu][44]=179;
	disp[16][44]=176;
	disp[15][44]=disp[14][44]=disp[13][44]=179;
	disp[12][44]=194;

	//remove later after adding gun firing code:
	disp[20][16]=248;

	disp[23][53]=disp[23][63]=207;
	for(int yo=0;yo<8;yo++)
	disp[22-yo][53]=disp[22-yo][63]=disp[22-yo][68]=179;
	disp[12][68]=194;
	disp[13][68]=179;

	disp[21][65]=disp[19][67]=disp[15][66]=disp[22][66]=disp[22][67]=disp[18][66]=disp[20][65]='$';

	char lever=194;

	if(disp[22][46]!=rock)
	disp[22][46]=lever;

	if(disp[22][46]==lever)
	disp[14][53]=254;

			if(disp[22][56]!=rock)
			disp[22][56]=lever;

			if(disp[22][56]==lever)
			disp[14][63]=254;

			disp[13][63]=179;
			disp[12][63]=194;
	disp[17][47]=218;
	disp[17][48]=disp[17][49]=disp[17][50]=disp[17][51]=disp[17][52]=196;
	disp[17][53]=180;

	disp[18][47]=disp[19][47]=disp[20][47]=disp[21][47]=disp[22][47]=179;
	disp[23][47]=207;

	disp[16][50]=rock;

		disp[17][57]=218;
		disp[17][58]=disp[17][59]=disp[17][60]=disp[17][61]=disp[17][62]=196;
		disp[17][53]=180;

		disp[18][57]=disp[19][57]=disp[20][57]=disp[21][57]=disp[22][57]=179;
		disp[23][57]=207;

		disp[16][60]=rock;

	disp[13][53]=179;
	disp[12][53]=194;



	}
void display::level2()
	{
	location=2.0;

	disp[14][50]=disp[14][47]=178;
	disp[12][50]=disp[12][49]=disp[12][48]=disp[12][47]=205;
	disp[12][51]=187;
	disp[12][46]=201;
	disp[13][46]=204;
	disp[13][51]=185;
	disp[13][50]=disp[13][49]=disp[13][48]=disp[13][47]=205;
	disp[14][51]=disp[14][46]=186;
	disp[15][46]=200;
	disp[15][51]=188;
	disp[15][47]=disp[15][50]=205;
	disp[15][48]=disp[15][49]=202;
	disp[14][48]=201;
	disp[14][49]=187;



	disp[1][1]=1;
	// standard declaration
	for(int i=1;i<24;i++)
	disp[i][0]=disp[i][73]=vbar;    // vertical screen border
	for(int j=1;j<74;j++)
	disp[0][j]=disp[23][j]=hbar;    // horizontal screen border
	//screen corners
	disp[0][0]=lhtc;
	disp[0][73]=rhtc;
	disp[23][0]=lhbc;
	disp[23][73]=rhbc;
	//...
	}
void display::level3()
	{
	location=3.0;

	disp[14][50]=disp[14][47]=178;
	disp[12][50]=disp[12][49]=disp[12][48]=disp[12][47]=205;
	disp[12][51]=187;
	disp[12][46]=201;
	disp[13][46]=204;
	disp[13][51]=185;
	disp[13][50]=disp[13][49]=disp[13][48]=disp[13][47]=205;
	disp[14][51]=disp[14][46]=186;
	disp[15][46]=200;
	disp[15][51]=188;
	disp[15][47]=disp[15][50]=205;
	disp[15][48]=disp[15][49]=202;
	disp[14][48]=201;
	disp[14][49]=187;


	disp[1][1]=1;
	// standard declaration
	for(int i=1;i<24;i++)
	disp[i][0]=disp[i][73]=vbar;    // vertical screen border
	for(int j=1;j<74;j++)
	disp[0][j]=disp[23][j]=hbar;    // horizontal screen border
	//screen corners
	disp[0][0]=lhtc;
	disp[0][73]=rhtc;
	disp[23][0]=lhbc;
	disp[23][73]=rhbc;
	//...
	}
void display::screenshow()
	{
	 clrscr();
	 char enemy=2, player=1, key=231, mudr=176, lock=254;
	 char title[45]="                        MAZE DAVE (Prototype)";
	 char subtitle[38]="                              ROOM ONE";
	 textcolor(CYAN);
	 for(int hu=0;hu<45;hu++)
	 cprintf("%c",title[hu]);
	 cout<<"\n\n";
	 textcolor(YELLOW);
	 for(int gu=0;gu<38;gu++)
	 cprintf("%c",subtitle[gu]);

	 cout<<"\n";
	 for(int r=0;r<24;r++)
		{
		 for(int h=0;h<74;h++)
			if(disp[r][h]==background)
			{if(location==1.0)
			{textcolor(GREEN);
			cprintf("%c",disp[r][h]);}
			else
			{if(r>8 && r<17 && h>20 && h<43)
			{textcolor(GREEN);
			cprintf("%c",disp[r][h]);}
			else
			{textcolor(BLACK);
			cprintf("%c",disp[r][h]);
			}
			}}
			else if(disp[r][h]=='V' || disp[r][h]==mudr)
			{textcolor(BROWN);
			cprintf("%c",disp[r][h]);
			}
			else if(disp[r][h]==lock || disp[r][h]==key)
			{textcolor(CYAN);
			cprintf("%c",disp[r][h]);
			}
			else if(disp[r][h]==rock)
			{textcolor(LIGHTGRAY);
			cprintf("%c",disp[r][h]);
			}
			else if(disp[r][h]==enemy)
			{textcolor(RED);
			cprintf("%c",disp[r][h]);
			}
			else if(disp[r][h]==player)
			{textcolor(WHITE);
			cprintf("%c",disp[r][h]);        //8-17, 20-43
			}
			else if(disp[r][h]=='$')
			{textcolor(YELLOW);
			cprintf("%c",disp[r][h]);
			}
			else if(disp[r][h]==rock)
			{textcolor(BROWN);
			cprintf("%c",disp[r][h]);
			}
			else
			{textcolor(DARKGRAY);
			cprintf("%c",disp[r][h]);
			}




		 cout<<"\n";
		}
	 textcolor(YELLOW);
	 cout<<"\n";
	 cout<<"keys: "<<ekey<<"       Money: "<<goldm<<"       Weapon: "<<weapon<<"      Lives: "<<lives;

	 char bonenemy=2;
	 char bono=1;
	 char mud=176;
	 for(int y=0;y<24;y++)
	 for(int z=0;z<74;z++)
	 if(disp[y][z]==bono && weapon=='b')
	 {if(disp[y-1][z]==mud || disp[y+1][z]==mud || disp[y][z+1]==mud || disp[y][z-1]==mud)
	 cout<<"\n\n\n                  Press 'X' to use your Bomb!";}
	 else if(disp[y][z]==bono && weapon=='g')
	 {for(int df=0;df<8;df++)
	 if(disp[y][z+df]==bonenemy || disp[y][z-df]==bonenemy)
	 cout<<"\n\n\n                  Press 'X' to use your Gun!";
	 }

	 }

int display::moveprototype()
	{
	char gun=169;
	char bomb=248;
	char shield=232;
	char enemy=2;
	char lock=254;
	char key=231;
	char a=202;
	char b1=201;
	char b2=188;
	char b3=187;
	char b4=200;
	char b5=205;
	char b6=204;
	char b7=185;
	char b8=186;
	char b9=196;
	char b10=192;
	char b11=217;
	char b12=218;
	char b13=191;
	char b14=176;
	char b15=193;
	char b16=209;
	char b17=179;
	char tree=7;
	char lever=194;
	char player=1;
	char a1=180, a2=182, a3=193, a4=194, a5=195;

	play:

	if(location==1.0)
	{

		if(disp[22][56]!=rock)
			disp[22][56]=lever;

			if(disp[22][56]==lever)
			disp[14][63]=254;
			else if(disp[14][63]!=player)
	 disp[14][63]=178;

	if(disp[22][46]!=rock)
	disp[22][46]=lever;

	if(disp[22][46]==lever)
	disp[14][53]=254;
	else if(disp[14][53]!=player)
	 disp[14][53]=178;}

	char move;
	move=getch();
	for(int u=0;u<24;u++)
	{for(int v=0;v<75;v++)
	{if(disp[u][v]==1)
	{switch(move)
	{
/*-->*/	case 'w':

	 if(disp[u-1][v]==bomb && goldm>10)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a bomb for $10? (y/n)";
	 choicee1:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='b';
			disp[u-1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=10;
			break;
		case 'n':break;
		default:goto choicee1;
		}
	 }

	 else if(disp[u-1][v]==gun && goldm>40)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a Gun for $40? (y/n)";
	 choicee2:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='g';
			disp[u-1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=40;
			break;
		case 'n':break;
		default:goto choicee2;
		}
	 }
	 else if(disp[u-1][v]==shield && goldm>30)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a shield for $30? (y/n)";
	 choicee3:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='s';
			disp[u-1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=30;
			break;
		case 'n':break;
		default:goto choicee3;
		}
	 }


	 else if(disp[u-1][v]==lock && ekey==1)
	 {
	  goldvar++;
	  ekey--;
	  disp[u-1][v]=disp[u][v];
	  disp[u][v]=178;
	  disp[u-1][v-1]=217;
	  disp[u-1][v+1]=192;
	  unlocked++;
	  goto mapshow;
		 }

	else if(disp[u-1][v]=='X')
	{location=1.0;
	goto finishing;}

	else if(disp[u-1][v]=='$')
       {moneyvar++;
       gold();
	  disp[u-1][v]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;}

	else if(disp[u-1][v]==b1 || disp[u-1][v]==b2 || disp[u-1][v]==b3 || disp[u-1][v]==b4
	|| disp[u-1][v]==b5 || disp[u-1][v]==b6 || disp[u-1][v]==b7 || disp[u-1][v]==b8
	|| disp[u-1][v]==b9 || disp[u-1][v]==b10 || disp[u-1][v]==b11 || disp[u-1][v]==b12
	 || disp[u-1][v]==b13 || disp[u-1][v]==b14 || disp[u-1][v]==tree
	  || disp[u-1][v]==b15 || disp[u-1][v]==b16 || disp[u-1][v]==b17 || disp[u-1][v]==lock
	   || disp[u-1][v]==enemy || disp[u-1][v]=='V' || disp[u-1][v]==a1 || disp[u-1][v]==a2
	    || disp[u-1][v]==a3 || disp[u-1][v]==a4 || disp[u-1][v]==a5)
		goto play;
	 else if(disp[u-1][v]==key)
	 {
	  keyvar++;
	  ekey=1;
	  disp[u-1][v]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }

	 else if(disp[u-1][v]==a)
	 goto finish;
		else
	       {{char s;
		s=disp[u-1][v];
	       disp[u-1][v]=disp[u][v];
		 disp[u][v]=s;}
	       break;}
 /*-->*/ case 's':

	 if(disp[u+1][v]==bomb && goldm>10)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a bomb for $10? (y/n)";
	 choicee4:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='b';
			disp[u+1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=10;
			break;
		case 'n':break;
		default:goto choicee4;
		}
	 }

	 else if(disp[u+1][v]==gun && goldm>40)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a Gun for $40? (y/n)";
	 choicee5:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='g';
			disp[u+1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=40;
			break;
		case 'n':break;
		default:goto choicee5;
		}
	 }
	 else if(disp[u+1][v]==shield && goldm>30)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a shield for $30? (y/n)";
	 choicee6:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='s';
			disp[u+1][v]=disp[u][v];
			disp[u][v]=178;
			goldm-=30;
			break;
		case 'n':break;
		default:goto choicee6;
		}
	 }



	else if(disp[u+1][v]==lock && ekey==1)
	 {
	  goldvar++;
	  ekey--;
	  disp[u+1][v]=disp[u][v];
	  disp[u][v]=178;
	  disp[u+1][v-1]=191;
	  disp[u+1][v+1]=218;
	  unlocked++;
	  goto mapshow;
	 }
	else if(disp[u+1][v]=='X')
	{location=1.0;
	goto finishing;}
	else if(disp[u+1][v]=='$')
	{moneyvar++;
	gold();
	disp[u+1][v]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }

	else if(disp[u+1][v]==b1 || disp[u+1][v]==b2 || disp[u+1][v]==b3 || disp[u+1][v]==b4
	|| disp[u+1][v]==b5 || disp[u+1][v]==b6 || disp[u+1][v]==b7 || disp[u+1][v]==b8
	|| disp[u+1][v]==b9 || disp[u+1][v]==b10 || disp[u+1][v]==b11 || disp[u+1][v]==b12
	 || disp[u+1][v]==b13 || disp[u+1][v]==b14 || disp[u+1][v]==tree
	  || disp[u+1][v]==b15 || disp[u+1][v]==b16 || disp[u+1][v]==b17 || disp[u+1][v]==lock
	   || disp[u+1][v]==rock || disp[u+1][v]==enemy || disp[u+1][v]=='V' || disp[u+1][v]==a1
	    || disp[u+1][v]==a2 || disp[u+1][v]==a3 || disp[u+1][v]==a4 || disp[u+1][v]==a5)
	goto play;
		 else if(disp[u+1][v]==key)
	 {
	  keyvar++;
	  ekey=1;
	  disp[u+1][v]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }
	else if(disp[u+1][v]==a)
	 goto finish;
	else
	{char w;
	w=disp[u+1][v];
	disp[u+1][v]=disp[u][v];
	disp[u][v]=w;}
	break;
/*-->*/	case 'a':

	 if(u==11 && v==69)
	 {
	 if(weapon=='s')
	 cavernpass();
	 else
	 cavernblock();
	 }
	 /*else*/ if(disp[u][v-1]==bomb && goldm>10)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a bomb for $10? (y/n)";
	 choicee7:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='b';
			disp[u][v-1]=disp[u][v];
			disp[u][v]=178;
			goldm-=10;
			break;
		case 'n':break;
		default:goto choicee7;
		}
	 }

	 else if(disp[u][v-1]==gun && goldm>40)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a Gun for $40? (y/n)";
	 choicee8:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='g';
			disp[u][v-1]=disp[u][v];
			disp[u][v]=178;
			goldm-=40;
			break;
		case 'n':break;
		default:goto choicee8;
		}
	 }
	 else if(disp[u][v-1]==shield && goldm>30)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a shield for $30? (y/n)";
	 choicee9:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='s';
			disp[u][v-1]=disp[u][v];
			disp[u][v]=178;
			goldm-=30;
			break;
		case 'n':break;
		default:goto choicee9;
		}
	 }

	else if(disp[u][v-1]==rock && disp[u+1][v-2]==background)
	    {
	    disp[u][v-1]=disp[u][v];
	    disp[u][v]=178;
	    for(int ip=0;disp[u+ip+1][v-2]!=hbar;ip++)
	    {
	    disp[u+ip][v-2]=178;
	    disp[u+ip+1][v-2]=rock;
	    delay(50);
	    screenshow();
	    }
	    killed++;
	    }
	    else if(disp[u][v-1]==rock && disp[u][v-2]!=vbar)
	    {disp[u][v-2]=disp[u][v-1];
	    disp[u][v-1]=disp[u][v];
	    disp[u][v]=178;
	    goto mapshow;
	    }
	    else if(disp[u][v-1]==lock && ekey==1)
	 {
	  goldvar++;
	  ekey--;
	  disp[u][v-1]=disp[u][v];
	  disp[u][v]=178;
	  disp[u-1][v-1]=217;
	  disp[u+1][v-1]=191;
	  unlocked++;
	  goto mapshow;
	 }
	else if(u>=5 && u<=8 && v==7)
	{
	location=1.1;
	secretdungeon();
	}
	else if(disp[u][v-1]=='X')
	{location=1.0;
	goto finishing;}

	else if(disp[u][v-1]=='$')
	{moneyvar++;
	gold();
	disp[u][v-1]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }

	else if(disp[u][v-1]==b1 || disp[u][v-1]==b2 || disp[u][v-1]==b3 || disp[u][v-1]==b4
	|| disp[u][v-1]==b5 || disp[u][v-1]==b6 || disp[u][v-1]==b7 || disp[u][v-1]==b8
	|| disp[u][v-1]==b9 || disp[u][v-1]==b10 || disp[u][v-1]==b11 || disp[u][v-1]==b12
	 || disp[u][v-1]==b13 || disp[u][v-1]==b14 || disp[u][v-1]==tree
	  || disp[u][v-1]==b15 || disp[u][v-1]==b16 || disp[u][v-1]==b17 || disp[u][v-1]==lock
	   || disp[u][v-1]==rock || disp[u][v-1]==enemy || disp[u][v-1]=='V' || disp[u][v-1]==a1
	    || disp[u][v-1]==a2 || disp[u][v-1]==a3 || disp[u][v-1]==a4 || disp[u][v-1]==a5)
	goto play;
		 else if(disp[u][v-1]==key)
	 {
	  keyvar++;
	  ekey=1;
	  disp[u][v-1]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }
	else if(disp[u][v-1]==a)
	 goto finish;
	else
	{char a;
	a=disp[u][v-1];
	disp[u][v-1]=disp[u][v];
	disp[u][v]=a;}
	break;
/*-->*/	case 'd':
	if(disp[u][v+1]==bomb && goldm>10)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a bomb for $10? (y/n)";
	 choicee:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='b';
			disp[u][v+1]=disp[u][v];
			disp[u][v]=178;
			goldm-=10;
			break;
		case 'n':break;
		default:goto choicee;
		}
	 }

	 else if(disp[u][v+1]==gun && goldm>40)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a Gun for $40? (y/n)";
	 choiceet:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='g';
			disp[u][v+1]=disp[u][v];
			disp[u][v]=178;
			goldm-=40;
			break;
		case 'n':break;
		default:goto choiceet;
		}
	 }
	 else if(disp[u][v+1]==shield && goldm>30)
	 {
	 char choice;
	 cout<<"\nWould you like to buy a shield for $30? (y/n)";
	 choiceey:
	 cin>>choice;
	 switch(choice)
		{
		case 'y':weapon='s';
			disp[u][v+1]=disp[u][v];
			disp[u][v]=178;
			goldm-=30;
			break;
		case 'n':break;
		default:goto choiceey;
		}
	 }


	else if(disp[u][v+1]==rock && disp[u][v+2]!=b17)
	    {disp[u][v+2]=disp[u][v+1];
	    disp[u][v+1]=disp[u][v];
	    disp[u][v]=178;
	    goto mapshow;
	    }
	else if(disp[u][v+1]==lock && ekey==1)
	 {
	  ekey=0;
	  disp[u][v+1]=disp[u][v];
	  disp[u][v]=178;
	  disp[u-1][v+1]=192;
	  disp[u+1][v+1]=218;
	  unlocked++;
	  goto mapshow;
	 }

	else if(disp[u][v+1]=='X')
	{location=1.0;
	goto finishing;}

	else if(disp[u][v+1]=='$')
	{moneyvar++;
	gold();
	disp[u][v+1]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }

	else if(disp[u][v+1]==b1 || disp[u][v+1]==b2 || disp[u][v+1]==b3 || disp[u][v+1]==b4
	|| disp[u][v+1]==b5 || disp[u][v+1]==b6 || disp[u][v+1]==b7 || disp[u][v+1]==b8
	|| disp[u][v+1]==b9 || disp[u][v+1]==b10 || disp[u][v+1]==b11 || disp[u][v+1]==b12
	 || disp[u][v+1]==b13 || disp[u][v+1]==b14 || disp[u][v+1]==tree
	  || disp[u][v+1]==b15 || disp[u][v+1]==b16 || disp[u][v+1]==b17 || disp[u][v+1]==lock
	   || disp[u][v+1]==rock || disp[u][v+1]==enemy || disp[u][v+1]=='V' || disp[u][v+1]==a1
	    || disp[u][v+1]==a2  || disp[u][v+1]==a3 || disp[u][v+1]==a4 || disp[u][v+1]==a5)
	goto play;
		 else if(disp[u][v+1]==key)
	 {
	  keyvar++;
	  ekey=1;
	  disp[u][v+1]=disp[u][v];
	  disp[u][v]=178;
	  goto mapshow;
	 }
	else if(disp[u][v+1]==a)
	 goto finish;
	else
	{char d;
	d=disp[u][v+1];
	disp[u][v+1]=disp[u][v];
	disp[u][v]=d;
	break;}

	case 'x':
		 char enemy=2;
		 char mud=176;
		 if(disp[u-1][v]==mud || disp[u+1][v]==mud || disp[u][v+1]==mud || disp[u][v-1]==mud)
		 {if(weapon=='b')
		 {
		 for(int i=0;disp[u][v+1+i]==mud;i++)
		 {
		 disp[u][v+i+1]=178;
		 delay(65);
		 screenshow();
		 }
		 blasted++;
		 }}
		 else if(weapon=='g')
		 {
		 for(int yolo=0;yolo<8;yolo++)
			if(disp[u][v+yolo]==enemy)
			{for(int bulpos=1;disp[u][v+bulpos]==background;bulpos++)
			{disp[u][v+bulpos]='.';
			if(bulpos>1)
			disp[u][v+bulpos-1]=178;
			delay(55);
			screenshow();
			}
			disp[u][v+bulpos]=disp[u][v+bulpos-1]=178;
			delay(55);
			screenshow();
			if(location==1.0 && disp[19][32]!=enemy)
			killed=15;
			}
		 }

		 else
		 goto play;
		 break;

	default: goto play;
	 }
	goto mapshow;}
	else continue;
	}
	}
	mapshow:
	screenshow();
	goto play;
	finish:
	return(1);
	finishing:
	return(0);
	}
int ekey=0;
void display::weaponroom()
	{
	innitial();
	sroomvar=1;
	disp[15][35]=gun;
	disp[15][30]=grenade;
	disp[15][25]=shield;

		disp[9][41]=1;
		disp[10][30]='X';
	// standard declaration
	if(keyvar==0)
		disp[15][40]=231;

	for(int i=8;i<18;i++)
	disp[i][20]=disp[i][43]=vbar;    // vertical screen border
	for(int j=20;j<44;j++)
	disp[8][j]=disp[17][j]=hbar;    // horizontal screen border
	//screen corners
	disp[8][20]=lhtc;
	disp[8][43]=rhtc;
	disp[17][20]=lhbc;
	disp[17][43]=rhbc;

	screenshow();
	}
void instruction()
{
char locks=254, keys=231, guns=169, bomb=248, shield=232;
clrscr();
cout<<"                             MAZE DAVE (prototype)";
cout<<"\n\n navigate the map with the WASD keys.";
cout<<"\nAIM: to reach the cross at the bottom right corner of the screen";
cout<<"\n open locks ("<<locks<<") with keys ("<<keys<<") that are placed in different parts of the map";
cout<<"\n WEAPONS";
cout<<"\n Gun ("<<guns<<") : use it to shoot the enemy when in range";
cout<<"\n Shield ("<<shield<<") : it has to be used to go through certain parts of the map";
cout<<"\n Bomb ("<<bomb<<") : use it to blast through certain parts of the map whenever possible";
cout<<"          do so even if an alternative route presents itself. it might be essential later on.";
getch();
clrscr();
}
void main()
	{
	clrscr();
	instruction();
	display x1;
	player a;
	ekey=0;
	x1.innitial();
	//a.getname();
	//x1.move();
	level1:
	x1.level1();
	int check=x1.moveprototype();
	if(check==0)
	goto level1;
	//x1.move();
	//x1.level2();
	//x1.moveprototype();
	//x1.move();
	//x1.level3();
	//x1.moveprototype();
	//x1.move();
	}
