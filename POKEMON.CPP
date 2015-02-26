//*******************************************//
//                                           //
//               POKEMON BETA(c)             //
//                                           //
//                   by                      //
//                  Ayush                    //
//                                           //
//*******************************************//
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char ember='>';
char tackle='/';
char scratch=254;
char bullet=248;
char harden='|';
char water=205;
int hp=25;
int fightvar=0;
void loading1();
void loading2();
void oak();
void animation();
void display();
void gym();
void fight();
void fight1();
void fight3();
void fight2();
int quit();
void main()
{
clrscr();
animation();
loading1();
oak();
display();

}
void display()
{
int gui;
clrscr();
char tree=6;

char disp[24][75];
for(int k=0;k<24;k++)
{ for(int j=0;j<75;j++)
{
 disp[k][j]=177;
}
}
for(int p=0;p<24;p++)
{
disp[p][0]=186;           /* for screen bounddispy*/
disp[p][74]=186;
}
for(int j=0;j<75;j++)
{disp[0][j]=disp[23][j]=205;}   /* for display bounddispy */
disp[1][1]=1;
disp[0][0]=201;
disp[23][74]=188;
disp[0][74]=187;
disp[23][0]=200;
/*first gym*/
disp[4][50]=disp[4][47]=' ';
disp[2][50]=disp[2][49]=disp[2][48]=disp[2][47]=205;
disp[2][51]=187;
disp[2][46]=201;
disp[3][46]=204;
disp[3][51]=185;
disp[3][50]=disp[3][49]=disp[3][48]=disp[3][47]=205;
disp[4][51]=disp[4][46]=186;
disp[5][46]=200;
disp[5][51]=188;
disp[5][47]=disp[5][50]=205;
disp[5][48]=disp[5][49]=202;
disp[4][48]=201;
disp[4][49]=187;
/* second gym */
disp[17][20]=disp[17][17]=' ';
disp[15][20]=disp[15][19]=disp[15][18]=disp[15][17]=205;
disp[15][21]=187;/* top rh corner*/
disp[15][16]=201;
disp[16][16]=204;
disp[16][21]=185;
disp[16][20]=disp[16][19]=disp[16][18]=disp[16][17]=205;
disp[17][21]=disp[17][16]=186;
disp[18][16]=200;
disp[18][21]=188;
disp[18][17]=disp[18][20]=205;
disp[18][18]=disp[18][19]=202;
disp[17][18]=201;
disp[17][19]=187;
// gym 3 [-13][-5]
disp[4][15]=disp[4][12]=' ';
disp[2][15]=disp[2][14]=disp[2][13]=disp[2][12]=205;
disp[2][16]=187;/* top rh corner*/
disp[2][11]=201;
disp[3][11]=204;
disp[3][16]=185;
disp[3][15]=disp[3][14]=disp[3][13]=disp[3][12]=205;
disp[4][16]=disp[4][11]=186;
disp[5][11]=200;
disp[5][16]=188;
disp[5][12]=disp[5][15]=205;
disp[5][13]=disp[5][14]=202;
disp[4][13]=201;
disp[4][14]=187;
// gym 4 [][+15]
disp[4][65]=disp[4][62]=' ';
disp[2][65]=disp[2][64]=disp[2][63]=disp[2][62]=205;
disp[2][66]=187;
disp[2][61]=201;
disp[3][61]=204;
disp[3][66]=185;
disp[3][65]=disp[3][64]=disp[3][63]=disp[3][62]=205;
disp[4][66]=disp[4][61]=186;
disp[5][61]=200;
disp[5][66]=188;
disp[5][62]=disp[5][65]=205;
disp[5][63]=disp[5][64]=202;
disp[4][63]=201;
disp[4][64]=187;
// tree(=7)
for(int gop=1;gop<17;gop++)
{if(gop!=13)
disp[gop][72]=disp[gop][71]=tree;
if(gop%2==0)
disp[gop][71]=tree;
if(gop%2==1 && gop!=13)
disp[gop][70]=tree;
 }
for(int gopu=1;gopu<19;gopu++)
if(gopu!=13)
disp[gopu][73]=tree;
for(int yoj=1;yoj<31;yoj++)
disp[21][yoj]=tree;
for(int guy=1;guy<74;guy++)
disp[22][guy]=tree;
for(int fro=1;fro<9;fro++)
disp[20][fro]=tree;
disp[19][1]=disp[19][3]=disp[19][5]=disp[19][7]=tree;

// bridge
disp[12][30]=192;
disp[12][36]=217;
disp[14][30]=218;
disp[14][36]=191;
disp[12][31]=disp[12][32]=disp[12][33]=disp[12][34]=disp[12][35]=196;
disp[14][31]=disp[14][32]=disp[14][33]=disp[14][34]=disp[14][35]=196;
// river
for(int i=1;i<12;i++)
{for(int j=31;j<36;j++)
disp[i][j]=176;}
for(int v=15;v<22;v++)
{for(int q=31;q<36;q++)
disp[v][q]=176;}
for(int w=19;w<22;w++)
{for(int e=36;e<74;e++)
disp[w][e]=176;}
disp[13][74]=177;
char grass=177;
//health
char health=3;
disp[18][55]=health;

//display loop

char diy=176;
mapshow:
clrscr();
for(int s=1;s<24;s++)
{ for(int j=0;j<75;j++)
{
 if(disp[s][j]==diy)
 {textcolor(LIGHTBLUE);
 cprintf("%c",disp[s][j]);}
 else if(disp[s][j]==1)
 {textcolor(WHITE);
 cprintf("%c",disp[s][j]);}
else if(s==13 && j>=1 && j<=74)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==9 && s>12 && s<21)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==13 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==14 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}

else if(j==10 && s>13 && s<20)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(s==20 && j>=10 && j<=19)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==49 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==48 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==64 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}
else if(j==63 && s>5 && s<13)
{textcolor(BROWN);
cprintf("%c",disp[s][j]);}


else if(disp[s][j]==tree)
{textcolor(GREEN);
cprintf("%c",disp[s][j]);}
else if(disp[s][j]==health)
{textcolor(RED);
cprintf("%c",disp[s][j]);}
else if(disp[s][j]==grass)
{textcolor(LIGHTGREEN);
cprintf("%c",disp[s][j]);}
else
{textcolor(LIGHTGRAY);
cprintf("%c",disp[s][j]);}
}
cout<<"\n";
}
cout<<"         Use w-a-s-d keys to navigate (w-up, a-left, s-down, d-right)";
cout<<"\n                          to exit, press 'l'.";
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
play:
char move;
move=getch();
for(int u=0;u<24;u++)
{for(int v=0;v<75;v++)
{if(disp[u][v]==1)
{switch(move)
{
case 'w':
if(disp[u-1][v]==health)
hp=25;
if(disp[u-1][v]==b1 || disp[u-1][v]==b2 || disp[u-1][v]==b3 || disp[u-1][v]==b4
|| disp[u-1][v]==b5 || disp[u-1][v]==b6 || disp[u-1][v]==b7 || disp[u-1][v]==b8
|| disp[u-1][v]==b9 || disp[u-1][v]==b10 || disp[u-1][v]==b11 || disp[u-1][v]==b12
 || disp[u-1][v]==b13 || disp[u-1][v]==b14 || disp[u-1][v]==tree)
	goto play;
else if(disp[u-1][v]==a)
{gym();
goto mapshow;}
	else
       {{char s;
	s=disp[u-1][v];
       disp[u-1][v]=disp[u][v];
       disp[u][v]=s;}
       break;}
case 's':
if(disp[u+1][v]==health)
hp=25;
if(disp[u+1][v]==b1 || disp[u+1][v]==b2 || disp[u+1][v]==b3 || disp[u+1][v]==b4
|| disp[u+1][v]==b5 || disp[u+1][v]==b6 || disp[u+1][v]==b7 || disp[u+1][v]==b8
|| disp[u+1][v]==b9 || disp[u+1][v]==b10 || disp[u+1][v]==b11 || disp[u+1][v]==b12
 || disp[u+1][v]==b13 || disp[u+1][v]==b14 || disp[u+1][v]==tree)
goto play;
else if(disp[u+1][v]==a)
{gym();
goto mapshow;}
else
{char w;
w=disp[u+1][v];
disp[u+1][v]=disp[u][v];
disp[u][v]=w;}
break;
case 'a':
if(disp[u][v-1]==health)
hp=25;
if(disp[u][v-1]==b1 || disp[u][v-1]==b2 || disp[u][v-1]==b3 || disp[u][v-1]==b4
|| disp[u][v-1]==b5 || disp[u][v-1]==b6 || disp[u][v-1]==b7 || disp[u][v-1]==b8
|| disp[u][v-1]==b9 || disp[u][v-1]==b10 || disp[u][v-1]==b11 || disp[u][v-1]==b12
 || disp[u][v-1]==b13 || disp[u][v-1]==b14 || disp[u][v-1]==tree)
goto play;
else if(disp[u][v-1]==a)
{gym();
goto mapshow;}
else
{char a;
a=disp[u][v-1];
disp[u][v-1]=disp[u][v];
disp[u][v]=a;}
break;
case 'd':
if(disp[u][v+1]==health)
hp=25;
if(disp[u][v+1]==b1 || disp[u][v+1]==b2 || disp[u][v+1]==b3 || disp[u][v+1]==b4
|| disp[u][v+1]==b5 || disp[u][v+1]==b6 || disp[u][v+1]==b7 || disp[u][v+1]==b8
|| disp[u][v+1]==b9 || disp[u][v+1]==b10 || disp[u][v+1]==b11 || disp[u][v+1]==b12
 || disp[u][v+1]==b13 || disp[u][v+1]==b14 || disp[u][v+1]==tree)
goto play;
else if(disp[u][v+1]==a)
{gym();
goto mapshow;}
else
{char d;
d=disp[u][v+1];
disp[u][v+1]=disp[u][v];
disp[u][v]=d;
break;}
case 'l':
gui=quit();
if(gui==1)
goto finish;
break;
default: goto play;
 }
goto mapshow;}
else continue;
}
}
finish:
clrscr();
}
void gym()
{
input:
clrscr();
cout<<"\n\n\n\n\n\n"<<"             would you like to challenge this gym leader?";
cout<<"\n"<<"                  1.Yes             2.No";
cout<<"\n                your choice: ";
char x;
cin>>x;
if(x=='1' || x=='2')
{switch(x)
{
case '1':
if(hp<=4)
{cout<<"\n                   Your pokemon is too weak to fight!!";
goto dumko;}
else
fight();
       break;
case '2':break;
}}
else
goto input;
dumko:
getch();

}
void fight1()
{
clrscr();
// pokemon display
char fi[20][70];
for(int i=0;i<20;i++)
{for(int j=0;j<70;j++)
fi[i][j]=176;}
char he[70];
for(int o=0;o<70;o++)
he[o]=' ';
for(int g=0;g<70;g++)
fi[19][g]=205;
//charmander innitialization
fi[2][7]=218;
fi[3][7]=fi[4][7]=fi[5][7]=fi[8][6]=fi[7][6]=fi[10][5]=179;
fi[6][7]=217;
fi[6][6]=218;
fi[9][5]=218;
fi[9][6]=180;
fi[11][5]=217;
fi[11][4]=196;
fi[11][3]=192;
fi[10][3]=fi[9][3]=fi[8][3]=fi[7][3]=179;
fi[11][2]=fi[10][2]=fi[9][2]=fi[8][2]=fi[7][2]=179;
fi[12][2]=192;
fi[12][3]=196;
fi[12][5]=191;
fi[13][5]=192;
fi[13][6]=fi[14][6]=179;
fi[15][6]=192;
fi[15][7]=fi[15][8]=196;
fi[15][9]=217;
fi[14][9]=191;
fi[14][8]=192;
fi[13][8]=218;
fi[13][9]=fi[13][10]=196;
fi[13][11]=191;
fi[14][11]=179;
fi[15][11]=192;
fi[15][12]=fi[15][13]=196;
fi[15][14]=217;
fi[14][14]=191;
fi[14][13]=192;
fi[13][13]=218;
fi[13][14]=196;
fi[13][15]=217;
fi[12][15]=179;
fi[8][15]=191;
fi[8][14]=192;
fi[11][15]=fi[10][15]=fi[9][15]=179;
fi[7][14]=179;
fi[6][14]=218;
fi[6][15]=217;
fi[5][15]=194;
fi[5][14]=196;
fi[5][16]=217;
fi[4][16]=191;
fi[4][15]=193;
fi[3][15]=179;
fi[2][15]=191;
fi[2][14]=fi[2][13]=fi[2][12]=fi[2][11]=fi[2][10]=fi[2][9]=fi[2][8]=196;
fi[10][6]=179;
fi[11][6]=192;
fi[11][7]=196;
fi[11][8]=217;
fi[10][8]=fi[9][8]=fi[8][8]=179;
fi[4][14]=233;
fi[15][6]=192;
fi[12][4]=196;
fi[17][5]='C';
fi[17][6]='h';
fi[17][7]='a';
fi[17][8]='r';
fi[17][9]='m';
fi[17][10]='a';
fi[17][11]='n';
fi[17][12]='d';
fi[17][13]='e';
fi[17][14]='r';
// squirtel innitialization
fi[2][50]=218;
fi[2][51]=fi[2][52]=fi[2][53]=fi[2][54]=fi[2][55]=fi[2][56]=fi[2][57]=196;
fi[2][58]=191;
fi[3][50]=fi[4][50]=fi[3][58]=fi[4][58]=179;
fi[5][58]=179;
fi[5][50]=192;
fi[5][51]=194;
fi[6][51]=192;
fi[6][52]=fi[6][53]=fi[6][54]=fi[6][55]=fi[6][56]=fi[6][57]=196;
fi[6][58]=197;
fi[7][58]=fi[8][58]=fi[9][58]=fi[10][58]=fi[11][58]=fi[12][58]=fi[14][58]=179;
fi[13][58]=197;
fi[13][57]=196;
fi[13][56]=218;
fi[14][56]=179;
fi[15][56]=217;
fi[15][55]=196;
fi[15][54]=218;
fi[16][54]=192;
fi[16][55]=fi[16][56]=196;
fi[16][57]=196;
fi[16][58]=217;
fi[15][58]=179;
fi[6][59]=fi[6][60]=fi[6][61]=196;
fi[6][62]=191;
fi[7][62]=192;
fi[7][63]=191;
fi[8][63]=fi[9][63]=fi[10][63]=fi[11][63]=179;
fi[12][63]=217;
fi[12][62]=218;
fi[13][62]=217;
fi[13][61]=fi[13][60]=fi[13][59]=196;
fi[14][56]=180;
fi[14][55]=fi[14][54]=fi[14][53]=196;
fi[14][52]=192;
fi[13][52]=fi[12][52]=fi[11][52]=fi[10][52]=179;
fi[6][52]=194;
fi[7][52]=193;
fi[9][52]=194;
fi[7][51]=fi[9][51]=196;
fi[7][50]=218;
fi[9][50]=192;
fi[8][50]=179;
fi[7][53]=191;
fi[9][53]=217;
fi[8][53]=179;
fi[4][53]=233;
fi[17][52]='S';
fi[17][53]='q';
fi[17][54]='u';
fi[17][55]='i';
fi[17][56]='r';
fi[17][57]='t';
fi[17][58]='e';
fi[17][59]='l';
//....

int ho=25;
int yu1=0, yu2=0, yu3=0;
int ghu=0;
int hai1=0, hai2=0, hai3=0;
int playc=0;
int ft=0, fy=0, rt=0, yh=0, gu=0, gy=0, yolo=0;
// health bars
//healthbar:
char bac=176;
char bar=219;
show:
for(int gn=0;gn<70;gn++)
he[gn]=' ';
for(int ki=0;ki<hp;ki++)
he[ki]=219;
for(int hl=0;hl<ho;hl++)
he[hl+45]=219;
clrscr();
for(int go=0;go<70;go++)
{
if(go<=30 && he[go]==bar && hp>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go<=30 && he[go]==bar && hp<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else
cout<<he[go];
}
textcolor(LIGHTGRAY);
cout<<"\n   Your Pokemon's Health                       Enemy Pokemon's Health";
cout<<"\n";
for(int m=0;m<20;m++)
{for(int n=0;n<70;n++)
{
// for squirtel
if(m>=3 && m<=15 && n>=51 && n<=57 && fi[m][n]==bac)
{textcolor(CYAN);
cprintf("%c",fi[m][n]);
}
else if(m>=7 && m<=13 && n>57 && n<=62 && fi[m][n]==bac)
{textcolor(BLUE);
cprintf("%c",fi[m][n]);
}
// for charmander
else if(n>=7 && n<=14 && m>=3 && m<=15 && fi[m][n]==bac)
{textcolor(LIGHTRED);
cprintf("%c",fi[m][n]);}
// charmander attack
else if(fi[m][n]=='>')
{textcolor(YELLOW);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==tackle)
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==scratch)
{textcolor(RED);
cprintf("%c",fi[m][n]);}
// squirtel attack
else if(fi[m][n]==water)
{textcolor(WHITE);
cprintf("%c",fi[m][n]);}
// for landscape
else if(m>=16 && fi[m][n]==bac)
{textcolor(GREEN);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==bac)
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}

else
{textcolor(LIGHTGRAY);
cprintf("%c",fi[m][n]);}
}
cout<<"\n";}
textcolor(LIGHTGRAY);
if(playc%2==0)
{
if(ghu==1)
goto to1;
if(ghu==2)
goto to2;
if(ghu==3)
goto to3;
//MENU
cout<<"\n what would you like to attack with?"      ;
cout<<"\n 1.Ember         2.Scratch        3.Tackle";
cout<<"\n (or press 5 to leave battle.)";
cout<<"\n Your Choice>>>> ";
char attack;
cin>>attack;
switch(attack)
{case '1':
for(yu1=18;yu1<50;yu1++)
{
ghu=1;
fi[5][yu1]='>';
goto show;
to1:
delay(50);}
for(hai1=18;hai1<50;hai1++)
fi[5][hai1]=176;
ghu=0;
ft=random(4);
if(ft==0)
{cout<<"the attack failed!";
delay(700);}
else
{cout<<"it was super effective!";
delay(700);
ho-=7;}
break;
case '2':
for(yu2=18;yu2<50;yu2++)
{
ghu=2;
fi[8][yu2]=254;
goto show;
to2:
delay(50);}
for(hai2=18;hai2<50;hai2++)
fi[8][hai2]=176;
ghu=0;
yh=random(3);
if(yh==0)
{cout<<"the attack was dodged!!";
delay(700);}
else
{cout<<"the attack was effective!";
ho-=5;
delay(700);}
break;
case '3':
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][yu3]='/';
goto show;
to3:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][hai3]=176;
ghu=0;
gu=random(2);
if(gu==0)
{ho-=3;
cout<<"it was super effective!";
delay(700);
}
else
{cout<<"the attack failed!";
delay(700);}
break;
case '5':goto hindu;
default: goto show;
}
}
if(playc%2==1)
{
if(ghu==3)
goto to6;
if(ghu==2)
goto to5;
if(ghu==1)
goto to4;
randomize();
sleep(1);
yolo=random(3);
switch(yolo)
{
case 0:cout<<"squirtel used hydropump!!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=1;
fi[8][66-yu3]=205;
goto show;
to4:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=176;
ghu=0;
delay(100);
gy=random(3);
if(gy==0)
{cout<<"but it failed!";}
else
hp-=9;
break;
case 1:cout<<"squirtel used water jet!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=2;
fi[5][66-yu3]=178;
goto show;
to5:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[5][66-hai3]=176;
ghu=0;
fy=random(2);
if(fy==0)
cout<<"but it failed!";
else
hp-=5;
break;
case 2:cout<<"squirtel used tackle!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][66-yu3]='/';
goto show;
to6:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=176;
ghu=0;
rt=random(5);
if(rt==1)
cout<<"but it failed!";
else
hp-=3;
}
sleep(1);
}
playc++;
if(hp>0 && ho<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU WIN!";
sleep(1);
goto hindu;
}
else if(ho>0 && hp<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU LOSE!";
sleep(1);
goto hindu;
}
else
goto show;
hindu:
getch();
}
void animation()
{
clrscr();
textcolor(YELLOW);
cout<<"\n\n\n\n\n\n\n\n\n\n                      ";
char RT[27];
strcpy(RT,"AM Productions Present.....") ;
for(int bo=0;bo<27;bo++)
{cprintf("%c",RT[bo]);
delay(50);}
sleep(2);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n                          ";
char SG[20];
strcpy(SG,"Created by Nintendo");
for(int i=0;i<20;i++)
{cout<<SG[i];
delay(50);
}
cout<<"\n                     ";
char FG[30];
strcpy(FG,"(c) Developed by Ayush Mishra");
for(int io=0;io<30;io++)
{cout<<FG[io];
delay(100);
}
sleep(2);
clrscr();
char PK[20][70];
for(int ii=0;ii<20;ii++)
{for(int j=0;j<70;j++)
{PK[ii][j]=250;}}
// P
PK[1][10]=201;
PK[2][10]=PK[3][10]=PK[5][10]=PK[6][10]=PK[7][10]=186;
PK[4][10]=204;
PK[1][11]=PK[1][12]=205;
PK[1][13]=187;
PK[2][13]=PK[3][13]=186;
PK[4][13]=188;
PK[4][12]=PK[4][11]=205;
// O
PK[1][15]=201;
PK[2][15]=PK[3][15]=PK[4][15]=PK[5][15]=PK[6][15]=PK[2][17]=PK[3][17]=PK[4][17]=PK[5][17]=PK[6][17]=186;
PK[1][16]=PK[7][16]=205;
PK[7][15]=200;
PK[7][17]=188;
PK[1][17]=187;
//K
PK[1][19]=PK[2][19]=PK[3][19]=PK[5][19]=PK[6][19]=PK[7][19]=186;
PK[4][19]=204;
PK[4][20]=202;
PK[3][20]=201;
PK[3][21]=188;
PK[2][21]=PK[1][21]=186;
PK[4][21]=187;
PK[5][21]=200;
PK[5][22]=187;
PK[6][22]=PK[7][22]=186;
//E
PK[1][24]=201;
PK[2][24]=PK[3][24]=PK[5][24]=PK[6][24]=186;
PK[4][24]=204;
PK[7][24]=200;
PK[1][25]=PK[1][26]=PK[4][25]=PK[4][26]=PK[7][25]=PK[7][26]=205;
//M
PK[2][28]=PK[3][28]=PK[4][28]=PK[5][28]=PK[6][28]=PK[7][28]=PK[3][30]=PK[4][30]=186;
PK[2][32]=PK[3][32]=PK[4][32]=PK[5][32]=PK[6][32]=PK[7][32]=186;
PK[1][28]=201;
PK[1][29]=187;
PK[2][29]=200;
PK[2][30]=203;
PK[2][31]=188;
PK[1][31]=201;
PK[1][32]=187;
//O
PK[1][34]=201;
PK[2][34]=PK[3][34]=PK[4][34]=PK[5][34]=PK[6][34]=PK[2][36]=PK[3][36]=PK[4][36]=PK[5][36]=PK[6][36]=186;
PK[1][35]=PK[7][35]=205;
PK[7][34]=200;
PK[7][36]=188;
PK[1][36]=187;
//N
PK[2][38]=PK[3][38]=PK[4][38]=PK[5][38]=PK[6][38]=PK[7][38]=186;
PK[1][42]=PK[2][42]=PK[3][42]=PK[4][42]=PK[5][42]=PK[6][42]=186;
PK[3][40]=PK[4][40]=PK[5][40]=186;
PK[1][38]=201;
PK[1][39]=187;
PK[2][39]=200;
PK[2][40]=187;
PK[6][40]=200;
PK[6][41]=187;
PK[7][41]=200;
PK[7][42]=188;
//B
PK[10][36]=201;
PK[10][37]=PK[13][37]=PK[16][37]=PK[16][38]=205;
PK[11][36]=PK[12][36]=PK[13][36]=PK[14][36]=PK[15][36]=PK[11][38]=PK[12][38]=PK[14][39]=PK[15][39]=186;
PK[13][36]=204;
PK[16][36]=204;
PK[10][38]=187;
PK[13][38]=202;
PK[13][39]=187;
PK[16][39]=188;
PK[17][36]=PK[18][36]=186;
PK[19][36]=188;
//E
PK[10][41]=201;
PK[11][41]=PK[12][41]=PK[14][41]=PK[15][41]=186;
PK[13][41]=204;
PK[16][41]=200;
PK[10][42]=PK[10][43]=PK[13][42]=PK[13][43]=PK[16][42]=PK[16][43]=205;
//T
PK[10][45]=PK[10][46]=PK[10][48]=PK[10][49]=205;
PK[10][47]=203;
PK[11][47]=PK[12][47]=PK[13][47]=PK[14][47]=PK[15][47]=PK[16][47]=186;
//A
PK[10][51]=201;
PK[11][51]=PK[12][51]=PK[14][51]=PK[15][51]=PK[16][51]=186;
PK[11][53]=PK[12][53]=PK[14][53]=PK[15][53]=PK[16][53]=186;
PK[10][53]=187;
PK[10][52]=PK[13][52]=205;
PK[13][51]=204;
PK[13][53]=185;
char du=250;
for(int k=0;k<20;k++)
{for(int j=0;j<70;j++)
{if(PK[k][j]==du)
{textcolor(CYAN);
cprintf("%c",PK[k][j]);
}
else
{textcolor(BLUE);
cprintf("%c",PK[k][j]);
}}
cout<<"\n";}
textcolor(LIGHTGRAY);
cprintf("                     Press any key to begin.");
getch();
/*int gd = DETECT, gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
int x=getmaxx();
int y=getmaxy();
int go=500;
for(int id=0;id<go;id+=100)
{circle(x/2,y/2,i);
delay(1000);}
getch();
closegraph();
getch();  */
}
void fight2()
{
clrscr();
// pokemon display
char fi[20][70];
for(int i=0;i<20;i++)
{for(int j=0;j<70;j++)
fi[i][j]=176;}
char he[70];
for(int o=0;o<70;o++)
he[o]=' ';
for(int g=0;g<70;g++)
fi[19][g]=205;
//charmander innitialization
fi[2][7]=218;
fi[3][7]=fi[4][7]=fi[5][7]=fi[8][6]=fi[7][6]=fi[10][5]=179;
fi[6][7]=217;
fi[6][6]=218;
fi[9][5]=218;
fi[9][6]=180;
fi[11][5]=217;
fi[11][4]=196;
fi[11][3]=192;
fi[10][3]=fi[9][3]=fi[8][3]=fi[7][3]=179;
fi[11][2]=fi[10][2]=fi[9][2]=fi[8][2]=fi[7][2]=179;
fi[12][2]=192;
fi[12][3]=196;
fi[12][5]=191;
fi[13][5]=192;
fi[13][6]=fi[14][6]=179;
fi[15][6]=192;
fi[15][7]=fi[15][8]=196;
fi[15][9]=217;
fi[14][9]=191;
fi[14][8]=192;
fi[13][8]=218;
fi[13][9]=fi[13][10]=196;
fi[13][11]=191;
fi[14][11]=179;
fi[15][11]=192;
fi[15][12]=fi[15][13]=196;
fi[15][14]=217;
fi[14][14]=191;
fi[14][13]=192;
fi[13][13]=218;
fi[13][14]=196;
fi[13][15]=217;
fi[12][15]=179;
fi[8][15]=191;
fi[8][14]=192;
fi[11][15]=fi[10][15]=fi[9][15]=179;
fi[7][14]=179;
fi[6][14]=218;
fi[6][15]=217;
fi[5][15]=194;
fi[5][14]=196;
fi[5][16]=217;
fi[4][16]=191;
fi[4][15]=193;
fi[3][15]=179;
fi[2][15]=191;
fi[2][14]=fi[2][13]=fi[2][12]=fi[2][11]=fi[2][10]=fi[2][9]=fi[2][8]=196;
fi[10][6]=179;
fi[11][6]=192;
fi[11][7]=196;
fi[11][8]=217;
fi[10][8]=fi[9][8]=fi[8][8]=179;
fi[4][14]=233;
fi[15][6]=192;
fi[12][4]=196;
fi[17][5]='C';
fi[17][6]='h';
fi[17][7]='a';
fi[17][8]='r';
fi[17][9]='m';
fi[17][10]='a';
fi[17][11]='n';
fi[17][12]='d';
fi[17][13]='e';
fi[17][14]='r';
// Bulbasaur innitialization
fi[2][51]=218;
fi[2][52]=fi[2][53]=fi[2][54]=fi[2][55]=fi[2][56]=fi[2][57]=196;
fi[2][58]=191;
fi[3][51]=fi[3][58]=fi[4][58]=179;
fi[4][50]=218;
fi[4][51]=217;
fi[5][58]=179;
fi[5][50]=192;
fi[5][51]=194;
fi[6][51]=192;
fi[6][52]=fi[6][53]=fi[6][54]=fi[6][55]=fi[6][56]=fi[6][57]=196;
fi[6][58]=197;
fi[7][58]=fi[8][58]=fi[9][58]=fi[10][58]=fi[11][58]=fi[12][58]=fi[14][58]=179;
fi[13][58]=197;
fi[13][57]=196;
fi[13][56]=218;
fi[14][56]=179;
fi[15][56]=217;
fi[15][55]=196;
fi[15][54]=218;
fi[16][54]=192;
fi[16][55]=fi[16][56]=196;
fi[16][57]=196;
fi[16][58]=217;
fi[15][58]=179;

fi[6][59]=217;
fi[5][59]=218;
fi[5][60]=fi[5][61]=fi[5][62]=196;
fi[5][63]=191;
fi[6][63]=179;
fi[7][63]=192;
fi[7][64]=191;
fi[8][64]=fi[11][64]=179;
fi[9][64]=192;
fi[10][64]=218;
fi[9][65]=217;
fi[10][65]=191;
fi[12][64]=217;
fi[12][63]=218;
fi[13][63]=179;
fi[14][63]=217;
fi[14][62]=fi[14][61]=fi[14][60]=196;
fi[14][59]=192;
fi[13][59]=191;

fi[14][56]=180;
fi[14][55]=fi[14][54]=fi[14][53]=196;
fi[14][52]=192;
fi[13][52]=fi[12][52]=fi[11][52]=fi[10][52]=179;
fi[6][52]=194;
fi[7][52]=193;
fi[9][52]=194;
fi[7][51]=fi[9][51]=196;
fi[7][50]=218;
fi[9][50]=192;
fi[8][50]=179;
fi[7][53]=191;
fi[9][53]=217;
fi[8][53]=179;
fi[4][53]=233;


fi[17][52]='B';
fi[17][53]='u';
fi[17][54]='l';
fi[17][55]='b';
fi[17][56]='a';
fi[17][57]='s';
fi[17][58]='a';
fi[17][59]='u';
fi[17][60]='r';
//....
char block=254;

int ho=25;
int yu1=0, yu2=0, yu3=0;
int ghu=0;
int hai1=0, hai2=0, hai3=0;
int playc=0;
int ft=0, fy=0, rt=0, yh=0, gu=0, gy=0, yolo=0;
// health bars
//healthbar:
char bac=176;
char bar=219;
show:
for(int gn=0;gn<70;gn++)
he[gn]=' ';
for(int ki=0;ki<hp;ki++)
he[ki]=219;
for(int hl=0;hl<ho;hl++)
he[hl+45]=219;
clrscr();
for(int go=0;go<70;go++)
{
if(go<=30 && he[go]==bar && hp>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go<=30 && he[go]==bar && hp<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else
cout<<he[go];
}
textcolor(LIGHTGRAY);

cout<<"\n   Your Pokemon's Health                       Enemy Pokemon's Health";
cout<<"\n";
for(int m=0;m<20;m++)
{for(int n=0;n<70;n++)
{
// for Bulbasaur
if(m>=3 && m<=14 && n>=52 && n<=57 && fi[m][n]==bac)
{textcolor(LIGHTGREEN);
cprintf("%c",fi[m][n]);
}
else if(m>=6 && m<=13 && n>58 && n<=63 && fi[m][n]==bac)
{textcolor(GREEN);
cprintf("%c",fi[m][n]);
}

// for charmander
else if(n>=7 && n<=14 && m>=3 && m<=15 && fi[m][n]==bac)
{textcolor(LIGHTRED);
cprintf("%c",fi[m][n]);}
// charmander attack
else if(fi[m][n]=='>')
{textcolor(YELLOW);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==block)
{textcolor(RED);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]=='/')
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}
// Bulbasaur attack
else if(fi[m][n]==bullet)
{textcolor(GREEN);
cprintf("%c",fi[m][n]);}
// for landscape
else if(m>=16 && fi[m][n]==bac)
{textcolor(GREEN);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==bac)
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}

else
{textcolor(LIGHTGRAY);
cprintf("%c",fi[m][n]);}
}
cout<<"\n";}
if(playc%2==0)
{
if(ghu==1)
goto to1;
if(ghu==2)
goto to2;
if(ghu==3)
goto to3;
//MENU
cout<<"\n what would you like to attack with?"      ;
cout<<"\n 1.Ember         2.Scratch        3.Tackle";
cout<<"\n (or press 5 to leave battle.)";
cout<<"\n Your Choice>>>> ";
char attack;
cin>>attack;
switch(attack)
{case '1':
for(yu1=18;yu1<50;yu1++)
{
ghu=1;
fi[5][yu1]='>';
goto show;
to1:
delay(50);}
for(hai1=18;hai1<50;hai1++)
fi[5][hai1]=bac;
ghu=0;
ft=random(4);
if(ft==0)
{cout<<"the attack failed!";
delay(700);}
else
{cout<<"it was super effective!";
delay(700);
ho-=7;}
break;
case '2':
for(yu2=18;yu2<50;yu2++)
{
ghu=2;
fi[8][yu2]=254;
goto show;
to2:
delay(50);}
for(hai2=18;hai2<50;hai2++)
fi[8][hai2]=bac;
ghu=0;
yh=random(3);
if(yh==0)
{cout<<"the attack was dodged!!";
delay(700);}
else
{cout<<"the attack was effective!";
ho-=5;
delay(700);}
break;
case '3':
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][yu3]='/';
goto show;
to3:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][hai3]=bac;
ghu=0;
gu=random(2);
if(gu==0)
{ho-=3;
cout<<"it was super effective!";
delay(700);
}
else
{cout<<"the attack failed!";
delay(700);}
break;
case '5':goto hindu;
default: goto show;
}
}
if(playc%2==1)
{
if(ghu==3)
goto to6;
if(ghu==2)
goto to5;
if(ghu==1)
goto to4;
randomize();
sleep(1);
yolo=random(3);
switch(yolo)
{
case 0:cout<<"Bulbasaur used Bulletseed!!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=1;
fi[8][66-yu3]=248;
goto show;
to4:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=bac;
ghu=0;
delay(100);
gy=random(5);
if(gy==0)
{cout<<"but it failed!";}
else
hp-=9;
break;
case 1:cout<<"Bulbasaur used power whip!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=2;
fi[8][66-yu3]=196;
goto show;
to5:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=bac;
ghu=0;
fy=random(3);
if(fy==0)
cout<<"but it failed!";
else
hp-=5;
break;
case 2:cout<<"Bulbasaur used tackle!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][66-yu3]='/';
goto show;
to6:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=bac;
ghu=0;
rt=random(7);
if(rt==1)
cout<<"but it failed!";
else
hp-=3;
}
sleep(1);
}
playc++;
if(hp>0 && ho<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU WIN!";
sleep(1);
goto hindu;
}
else if(ho>0 && hp<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU LOSE!";
sleep(1);
goto hindu;
}
else
goto show;
hindu:
getch();
}
void fight()
{
if(fightvar>=3)
fightvar=0;
switch(fightvar)
{case 0:
loading2();
fight1();
break;
case 1:
loading2();
fight3();
break;
case 2:
loading2();
fight2();
break;
}
fightvar++;
}
void fight3()
{
clrscr();
// pokemon display
char fi[20][70];
for(int i=0;i<20;i++)
{for(int j=0;j<70;j++)
fi[i][j]=176;}
char he[70];
for(int o=0;o<70;o++)
he[o]=' ';
for(int g=0;g<70;g++)
fi[19][g]=205;
//charmander innitialization
fi[2][7]=218;
fi[3][7]=fi[4][7]=fi[5][7]=fi[8][6]=fi[7][6]=fi[10][5]=179;
fi[6][7]=217;
fi[6][6]=218;
fi[9][5]=218;
fi[9][6]=180;
fi[11][5]=217;
fi[11][4]=196;
fi[11][3]=192;
fi[10][3]=fi[9][3]=fi[8][3]=fi[7][3]=179;
fi[11][2]=fi[10][2]=fi[9][2]=fi[8][2]=fi[7][2]=179;
fi[12][2]=192;
fi[12][3]=196;
fi[12][5]=191;
fi[13][5]=192;
fi[13][6]=fi[14][6]=179;
fi[15][6]=192;
fi[15][7]=fi[15][8]=196;
fi[15][9]=217;
fi[14][9]=191;
fi[14][8]=192;
fi[13][8]=218;
fi[13][9]=fi[13][10]=196;
fi[13][11]=191;
fi[14][11]=179;
fi[15][11]=192;
fi[15][12]=fi[15][13]=196;
fi[15][14]=217;
fi[14][14]=191;
fi[14][13]=192;
fi[13][13]=218;
fi[13][14]=196;
fi[13][15]=217;
fi[12][15]=179;
fi[8][15]=191;
fi[8][14]=192;
fi[11][15]=fi[10][15]=fi[9][15]=179;
fi[7][14]=179;
fi[6][14]=218;
fi[6][15]=217;
fi[5][15]=194;
fi[5][14]=196;
fi[5][16]=217;
fi[4][16]=191;
fi[4][15]=193;
fi[3][15]=179;
fi[2][15]=191;
fi[2][14]=fi[2][13]=fi[2][12]=fi[2][11]=fi[2][10]=fi[2][9]=fi[2][8]=196;
fi[10][6]=179;
fi[11][6]=192;
fi[11][7]=196;
fi[11][8]=217;
fi[10][8]=fi[9][8]=fi[8][8]=179;
fi[4][14]=233;
fi[15][6]=192;
fi[12][4]=196;
fi[17][5]='C';
fi[17][6]='h';
fi[17][7]='a';
fi[17][8]='r';
fi[17][9]='m';
fi[17][10]='a';
fi[17][11]='n';
fi[17][12]='d';
fi[17][13]='e';
fi[17][14]='r';
// Metapod innitialization

fi[5][50]=218;
fi[6][50]=192;
fi[6][51]=191;
fi[5][51]=196;
fi[5][52]=191;
fi[6][52]=192;
fi[7][51]=179;
fi[8][51]=192;
fi[8][52]=191;
fi[9][52]=179;
fi[10][52]=217;
fi[11][52]=191;
fi[12][52]=195;
fi[13][52]=217;
fi[13][51]=218;
fi[10][51]=218;
fi[11][51]=192;
fi[9][53]=233;
fi[14][51]=217;
fi[14][50]=196;
fi[14][49]=218;
fi[15][49]=192;
fi[15][50]=fi[15][51]=196;
fi[15][52]=217;
fi[14][52]=218;
fi[14][53]=196;
fi[14][54]=217;
fi[13][54]=218;
fi[13][55]=196;
fi[13][56]=217;
fi[12][56]=fi[11][56]=fi[10][56]=fi[9][56]=fi[8][56]=179;
fi[7][56]=191;
fi[7][55]=196;
fi[7][54]=192;
fi[6][54]=191;
fi[6][53]=196;

fi[17][52]='M';
fi[17][53]='e';
fi[17][54]='t';
fi[17][55]='a';
fi[17][56]='p';
fi[17][57]='o';
fi[17][58]='d';

//....
char bar=219;
char bac=176;

int ho=25;
int yu1=0, yu2=0, yu3=0;
int ghu=0;
int hai1=0, hai2=0, hai3=0;
int playc=0;
int ft=0, fy=0, rt=0, yh=0, gu=0, gy=0, yolo=0;
// health bars
//healthbar:
show:
for(int gn=0;gn<70;gn++)
he[gn]=' ';
for(int ki=0;ki<hp;ki++)
he[ki]=219;
for(int hl=0;hl<ho;hl++)
he[hl+45]=219;
clrscr();
for(int go=0;go<70;go++)

{
if(go<=30 && he[go]==bar && hp>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho>10)
{textcolor(YELLOW);
cprintf("%c",he[go]);}
else if(go<=30 && he[go]==bar && hp<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else if(go>=30 && he[go]==bar && ho<=10)
{textcolor(RED);
cprintf("%c",he[go]);}
else
cout<<he[go];
}
textcolor(LIGHTGRAY);


cout<<"\n   Your Pokemon's Health                       Enemy Pokemon's Health";
cout<<"\n";
for(int m=0;m<20;m++)
{for(int n=0;n<70;n++)
{
// for metapod
if(m>=7 && m<=13 && n>=52 && n<=55 && fi[m][n]==bac)
{textcolor(LIGHTGREEN);
cprintf("%c",fi[m][n]);}
// for charmander
else  if(n>=7 && n<=14 && m>=3 && m<=15 && fi[m][n]==bac)
{textcolor(LIGHTRED);
cprintf("%c",fi[m][n]);}
// charmander attack
else if(fi[m][n]=='>')
{textcolor(YELLOW);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==tackle)
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==scratch)
{textcolor(RED);
cprintf("%c",fi[m][n]);}
// metapod attack
else if(fi[m][n]==harden)
{textcolor(LIGHTGREEN);
cprintf("%c",fi[m][n]);}
// for landscape
else if(m>=16 && fi[m][n]==bac)
{textcolor(GREEN);
cprintf("%c",fi[m][n]);}
else if(fi[m][n]==bac)
{textcolor(LIGHTBLUE);
cprintf("%c",fi[m][n]);}

else
{textcolor(LIGHTGRAY);
cprintf("%c",fi[m][n]);}
}
cout<<"\n";}
textcolor(LIGHTGRAY);
if(playc%2==0)
{
if(ghu==1)
goto to1;
if(ghu==2)
goto to2;
if(ghu==3)
goto to3;
//MENU
cout<<"\n what would you like to attack with?"      ;
cout<<"\n 1.Ember         2.Scratch        3.Tackle";
cout<<"\n (or press 5 to leave battle.)";
cout<<"\n Your Choice>>>> ";
char attack;
cin>>attack;
switch(attack)
{case '1':
for(yu1=18;yu1<50;yu1++)
{
ghu=1;
fi[5][yu1]='>';
goto show;
to1:
delay(50);}
for(hai1=18;hai1<50;hai1++)
fi[5][hai1]=176;
ghu=0;
ft=random(4);
if(ft==0)
{cout<<"the attack failed!";
delay(700);}
else
{cout<<"it was super effective!";
delay(700);
ho-=7;}
break;
case '2':
for(yu2=18;yu2<50;yu2++)
{
ghu=2;
fi[8][yu2]=254;
goto show;
to2:
delay(50);}
for(hai2=18;hai2<50;hai2++)
fi[8][hai2]=176;
ghu=0;
yh=random(3);
if(yh==0)
{cout<<"the attack was dodged!!";
delay(700);}
else
{cout<<"the attack was effective!";
ho-=5;
delay(700);}
break;
case '3':
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][yu3]='/';
goto show;
to3:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][hai3]=176;
ghu=0;
gu=random(2);
if(gu==0)
{ho-=3;
cout<<"it was super effective!";
delay(700);
}
else
{cout<<"the attack failed!";
delay(700);}
break;
case '5':goto hindu;
default: goto show;
}
}
if(playc%2==1)
{
if(ghu==3)
goto to6;
if(ghu==2)
goto to5;
if(ghu==1)
goto to4;
randomize();
sleep(1);
yolo=random(3);
switch(yolo)
{
case 0:cout<<"Metapod used stringshot!!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=1;
fi[8][66-yu3]=196;
fi[5][66-yu3]=196;
fi[11][66-yu3]=196;
goto show;
to4:
delay(50);}
for(hai3=18;hai3<50;hai3++)
{fi[8][66-hai3]=176;
fi[11][66-hai3]=176;
fi[5][66-hai3]=176;}
ghu=0;
delay(100);
gy=random(5);
if(gy==0)
{cout<<"but it failed!";}
else
hp-=3;
break;
case 1:cout<<"Metapod used harden!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=2;
fi[8][66-yu3]='|';
fi[9][66-yu3]='|';
fi[10][66-yu3]='|';
goto show;
to5:
delay(50);}
for(hai3=18;hai3<50;hai3++)
{fi[8][66-hai3]=176;
fi[9][66-hai3]=176 ;
fi[10][66-hai3]=176;}
ghu=0;
fy=random(3);
if(fy==0)
cout<<"but it failed!";
else
hp-=2;
break;
case 2:cout<<"Metapod used tackle!";
delay(700);
for(yu3=18;yu3<50;yu3++)
{
ghu=3;
fi[8][66-yu3]='/';
goto show;
to6:
delay(50);}
for(hai3=18;hai3<50;hai3++)
fi[8][66-hai3]=176;
ghu=0;
rt=random(7);
if(rt==1)
cout<<"but it failed!";
else
hp-=1;
}
sleep(1);
}
playc++;
if(hp>0 && ho<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU WIN!";
sleep(1);
goto hindu;
}
else if(ho>0 && hp<=0)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                            YOU LOSE!";
sleep(1);
goto hindu;
}
else
goto show;
hindu:
getch();
}
void loading1()
{
clrscr();
textcolor(YELLOW);
for(int i=0;i<3;i++)
{clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             ";
cprintf("Loading");
delay(200);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             ";
cprintf("Loading.");
delay(200);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             ";
cprintf("Loading..");
delay(200);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             ";
cprintf("Loading...");
delay(200);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n                             ";
cprintf("Loading....");
delay(200);
}
clrscr();
textcolor(LIGHTGREEN);
cout<<"\n\n\n\n\n\n\n\n\n\n\n                                ";
cprintf("Loaded!");
sleep(1);
textcolor(LIGHTGRAY);
cout<<"x";
clrscr();
}
void loading2()
{clrscr();
int var, move;
int left=0;
int right=73;
char ar[25][74];
for(int i=0;i<25;i++)
for(int j=0;j<74;j++)
ar[i][j]=' ';
showme:
clrscr();
for(int go=0;go<25;go++)
{for(int come=0;come<74;come++)
{
if(ar[go][come]=='<')
{textcolor(RED);
cprintf("%c",ar[go][come]);}
else
{textcolor(WHITE);
cprintf("%c",ar[go][come]);}
}
cout<<"\n";
}
delay(20);
if(var==1)
goto repeat;
else if(var==2)
goto finisha;
repeat:

for(move=0;move<25;move++)
{if(move%2==0)
ar[move][left]='>';
if(move%2==1)
ar[move][right]='<';}
left++;
right--;
if(right!=0)
{var=1;
goto showme;}
else
{var=2;
goto showme;}

finisha:
textcolor(LIGHTGRAY);
cprintf("b");
clrscr();
}
void oak()
{
clrscr();
char hair=176;
char eyes=248;
char coat=219;
char ar[10][10];
for(int i=0;i<10;i++)
for(int j=0;j<10;j++)
ar[i][j]=' ';
// innitialization of oak
ar[1][2]=ar[1][3]=ar[1][4]=ar[1][5]=ar[1][6]=ar[1][7]=ar[1][8]=176;
ar[2][2]=ar[3][2]=ar[4][2]=ar[5][2]=ar[6][2]=ar[2][8]=ar[3][8]=ar[4][8]=ar[5][8]=ar[6][8]=179;
ar[6][4]=ar[6][5]=ar[6][7]=196;
ar[6][2]=192;
ar[6][8]=217;
ar[3][4]=ar[3][7]=196;
ar[4][5]=ar[4][6]=179;
ar[4][4]=ar[4][7]=248;
ar[6][3]=ar[6][6]=194;
ar[5][3]=ar[5][4]=196;
ar[7][3]=ar[7][6]=ar[8][3]=ar[8][6]=ar[9][3]=ar[9][6]=219;
ar[8][2]=ar[8][1]=ar[8][7]=ar[8][8]=ar[8][9]=219;
ar[9][2]=ar[9][1]=ar[9][7]=ar[9][8]=ar[9][9]=219;
ar[7][4]=ar[7][5]=196;
ar[8][5]=17;
ar[8][4]=16;
//Oak diaplay
for(int y=0;y<10;y++)
{cout<<"                               ";
for(int x=0;x<10;x++)
{
if(ar[y][x]==hair)
{textcolor(BROWN);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==eyes)
{textcolor(LIGHTBLUE);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==coat)
{textcolor(WHITE);
cprintf("%c",ar[y][x]);}
else
{textcolor(LIGHTGRAY);
cprintf("%c",ar[y][x]);}
}
cout<<"\n";
}

//....
textcolor(WHITE);
char SG1[9];
strcpy(SG1,"Hi there!");
for(int i1=0;i1<9;i1++)
{cprintf("%c",SG1[i1]);
delay(50);
}
delay(500);
cout<<"\n";
char SG2[18];
strcpy(SG2,"I'm Professor Oak.");
for(int i2=0;i2<18;i2++)
{cprintf("%c",SG2[i2]);
delay(50);
}
delay(500);
cout<<"\n";
char SG3[34];
strcpy(SG3,"To start with, what is your name?");
for(int i3=0;i3<34;i3++)
{cprintf("%c",SG3[i3]);
delay(50);
}
cout<<"\n";
delay(500);

char name[50];
cin.getline(name,50);

for(i3=0;name[i3]!='\0';i3++)
{cprintf("%c",name[i3]);
delay(50);}
char SG4[33];
strcpy(SG4,"! Welcome to the world of pokemon!");
for(int i4=0;i4<33;i4++)
{cprintf("%c",SG4[i4]);
delay(50);
}
cout<<"\n";
delay(500);

char SG5[116];
strcpy(SG5,"Along with your pokemon, you shall battle other gym leaders, until you become  the ultimate pokemon trainer!!");
for(i3=0;i3<111;i3++)
{cprintf("%c",SG5[i3]);
delay(50);
}
cout<<"\n";
delay(500);
clrscr();
//Oak diaplay
for(y=0;y<10;y++)
{cout<<"                               ";
for(int x=0;x<10;x++)
{
if(ar[y][x]==hair)
{textcolor(BROWN);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==eyes)
{textcolor(LIGHTBLUE);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==coat)
{textcolor(WHITE);
cprintf("%c",ar[y][x]);}
else
{textcolor(LIGHTGRAY);
cprintf("%c",ar[y][x]);}
}
cout<<"\n";
}

cout<<"\n";
char SG6[82];
strcpy(SG6,"But first of all, let me familiarise you with some things you may come across...");
for(i3=0;i3<82;i3++)
{cprintf("%c",SG6[i3]);
delay(50);
}
cout<<"\n";
delay(500);
getch();
char SG7[31];
strcpy(SG7,"Your pokemon will be charmander");
for(i3=0;i3<31;i3++)
{cprintf("%c",SG7[i3]);
delay(50);
}
cout<<"\n";
delay(500);

char SG8[76];
strcpy(SG8,"It is a fire type pokemon, and has three attacks: Ember, Scratch and Tackle");
for(i3=0;i3<76;i3++)
{cprintf("%c",SG8[i3]);
delay(50);
}
cout<<"\n";
delay(500);


char SG9[63];
strcpy(SG9,"These may or may not be effective depending on various factors.");
for(i3=0;i3<63;i3++)
{cprintf("%c",SG9[i3]);
delay(50);
}
cout<<"\n";
delay(500);
getch();


char SG10[162];
strcpy(SG10,"The main motive of this is to defeat other pokemons.You can fight a gym leader  by visiting him at his gym in the map (which can be navigated using the WASD keys)");
for(i3=0;i3<162;i3++)
{cprintf("%c",SG10[i3]);
delay(50);
}
cout<<"\n";
delay(500);
getch();

char SG11[113];
strcpy(SG11,"You defeat a pokemon whenever its health drops to 0. Similarly, if the same happens to you, you lose the battle.");
for(i3=0;i3<113;i3++)
{cprintf("%c",SG11[i3]);
delay(50);
}
cout<<"\n";
delay(500);
getch();


clrscr();
//Oak display
for(y=0;y<10;y++)
{cout<<"                               ";
for(int x=0;x<10;x++)
{
if(ar[y][x]==hair)
{textcolor(BROWN);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==eyes)
{textcolor(LIGHTBLUE);
cprintf("%c",ar[y][x]);}
else if(ar[y][x]==coat)
{textcolor(WHITE);
cprintf("%c",ar[y][x]);}
else
{textcolor(LIGHTGRAY);
cprintf("%c",ar[y][x]);}
}
cout<<"\n";
}
cout<<"\n";
char SG12[120];
strcpy(SG12,"Remember: your health is NOT restored to full after each battle.However, you can do so by walking up to the heart symbol on the map.");
for(i3=0;i3<120;i3++)
{cprintf("%c",SG12[i3]);
delay(50);
}
cout<<"\n";
delay(500);
getch();
cout<<"\n                                 SO BEST OF LUCK!";
sleep(1);
loading2();

}
int quit()
{
choice:
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                 Are you sure you want to leave the game?(Y/N)" ;
cout<<"\n                     ( All Progress will be lost )";
cout<<"\n\n\n                         Your Choice:";
char answer;
cin>>answer;
if(answer=='y')
return(1);
else if(answer=='n')
return(0);
else
goto choice;
}