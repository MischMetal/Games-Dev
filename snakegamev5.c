
/*
	Snake
	Ayush mishra
	project started: 21/10/14 
	project ended: 27/10/14
	ASCII:
			DIRECTIONS (getch() returns two values for special char, ref arrow.c for usage)
			up: 			72
			down:			80
			left:			75
			right:			77

			snake head:		178
			snake block:	219
			snake food:		223

			CONSTRUCTORS:
			vbar:			179			
			hbar:			196
			cross:			197
			rhtc:			191
			rhbc:			217
			lhtc:			218
			lhbc:			192
		...
	
	Project status: finished.
*/ 


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<time.h>

char move[500]; 	
char DISP[23][72];		

int Y[500], X[500];				

int length=10;

int pos_ctr;

char up=72;
char down=80;
char left=75;
char right=77;

char snakehead=178;
char snakeblock=219;
char snakefood=223;

char vbar=179;			
char hbar=196;
char cross=97;
char rhtc=191;
char rhbc=217;
char lhtc=218;
char lhbc=192;

void getfood()	
	{
		int pos, a, b, t, no=1, cnt=0;
		
		 	rerandomize:
		 		pos=rand()%1440;
		 		a=pos/72;
		 		b=pos%72;
		 for(t=0;t<length;++t)
		 		if(a==Y[t] && b==X[t])
		 			goto rerandomize;
		 if( DISP[a][b]==hbar || DISP[a][b]==vbar || DISP[a][b]==lhtc || DISP[a][b]==lhbc || DISP[a][b]==rhtc || DISP[a][b]==rhbc)
		 		goto rerandomize;
		 DISP[a][b]=snakefood;
		
	}

void builder()
	{
		int i, j, x, y, m, l;				

		for(x = 0; x < 23; ++x)
			for (y = 0; y < 72; ++y)
				DISP[x][y]=' ';
		
		for (i = 1; i < 71; ++i)
		{
			DISP[0][i]=DISP[22][i]=hbar;
		}
		
		for (j = 1; j < 22; ++j)
		{
			DISP[j][0]=DISP[j][71]=vbar;
		}
		
		for(m=0;m<length;m++)
			move[m]=left;

		DISP[0][0]=lhtc;
		DISP[0][71]=rhtc;
		DISP[22][0]=lhbc;
		DISP[22][71]=rhbc;
	
		X[0]=36;
		Y[0]=12;
	
		DISP[12][65]=snakefood;

		for(l=1;l<length;l++)
				{
					X[l]=X[0]+l;
					Y[l]=Y[0];
				}
	}

void show()
	{
		system("cls");
		
		int x, y, v;
		
		DISP[0][0]=lhtc;
		DISP[Y[0]][X[0]]=snakehead;

		for(v=1;v<length;v++)
			DISP[Y[v]][X[v]]=snakeblock;

		for(;v<100;v++)
		{
			X[v]=X[v-1];
			Y[v]=Y[v-1];
		}
		
		printf("\n  ");
		for(x = 0; x < 23; ++x)
			{
				for (y = 0; y < 72; ++y)
				{
					printf("%c",DISP[x][y]);
			 	}
			 printf("\n  ");
			} 
		printf("SCORE: %d",length-10);
	}

int direction(char dir)
	{
		int v, z;

		for(v=length-1;v>0;v--)
			{
				move[v]=move[v-1];
			}

		move[0]=dir;

		switch(dir)
			{
				case 72: if(DISP[Y[0]-1][X[0]]==hbar || DISP[Y[0]-1][X[0]]==snakeblock)	//up
							return 0;
						else if(DISP[Y[0]-1][X[0]]==snakefood)
								{
									DISP[Y[0]][X[0]]=' ';
									DISP[Y[0]-1][X[0]]==' ';
									Y[0]--;
									switch(move[length-1])
										{
										case 72: Y[length]=Y[length-1]+1;
												 X[length]=X[length-1];
											break;
										case 80: Y[length]=Y[length-1]-1;
												 X[length]=X[length-1];
											break;
										case 75: Y[length]=Y[length-1];
												 X[length]=X[length-1]+1;
											break;
										case 77: Y[length]=Y[length-1];
												 X[length]=X[length-1]-1;
											break;
										default:
											break;
										}
									move[length]=move[length-1];
									getfood();
									length++;
								}
						else
						{
							DISP[Y[0]][X[0]]=' ';
							Y[0]--;
						}
					break;
				case 80:if(DISP[Y[0]+1][X[0]]==hbar || DISP[Y[0]+1][X[0]]==snakeblock)	//down
							return 0;
						else if(DISP[Y[0]+1][X[0]]==snakefood)
								{
									DISP[Y[0]][X[0]]=' ';
									DISP[Y[0]+1][X[0]]==' ';
									Y[0]++;
									switch(move[length-1])
										{
										case 72: Y[length]=Y[length-1]+1;
												 X[length]=X[length-1];
											break;
										case 80: Y[length]=Y[length-1]-1;
												 X[length]=X[length-1];
											break;
										case 75: Y[length]=Y[length-1];
												 X[length]=X[length-1]+1;
											break;
										case 77: Y[length]=Y[length-1];
												 X[length]=X[length-1]-1;
											break;
										default:
											break;
										}
									move[length]=move[length-1];	
									getfood();
									length++;
								}
						else
						{
							DISP[Y[0]][X[0]]=' ';
							Y[0]++;
						}
					break;
				case 75:if(DISP[Y[0]][X[0]-1]==vbar || DISP[Y[0]][X[0]-1]==snakeblock)	//left
							return 0;
						else if(DISP[Y[0]][X[0]-1]==snakefood)
								{
									DISP[Y[0]][X[0]]=' ';
									DISP[Y[0]][X[0]-1]==' ';
									X[0]--;
									switch(move[length-1])
										{
										case 72: Y[length]=Y[length-1]+1;
												 X[length]=X[length-1];
											break;
										case 80: Y[length]=Y[length-1]-1;
												 X[length]=X[length-1];
											break;
										case 75: Y[length]=Y[length-1];
												 X[length]=X[length-1]+1;
											break;
										case 77: Y[length]=Y[length-1];
												 X[length]=X[length-1]-1;
											break;
										default:
											break;
										}
									move[length]=move[length-1];	
									getfood();
									length++;
								}
						else
						{
							DISP[Y[0]][X[0]]=' ';
							X[0]--;
						}
					break;
				case 77:if(DISP[Y[0]][X[0]+1]==vbar || DISP[Y[0]][X[0]+1]==snakeblock)	//right
							return 0;
						else if(DISP[Y[0]][X[0]+1]==snakefood)
								{
									DISP[Y[0]][X[0]]=' ';
									DISP[Y[0]][X[0]+1]==' ';
									X[0]++;
									switch(move[length-1])
										{
										case 72: Y[length]=Y[length-1]+1;
												 X[length]=X[length-1];
											break;
										case 80: Y[length]=Y[length-1]-1;
												 X[length]=X[length-1];
											break;
										case 75: Y[length]=Y[length-1];
												 X[length]=X[length-1]+1;
											break;
										case 77: Y[length]=Y[length-1];
												 X[length]=X[length-1]-1;
											break;
										default:
											break;
										}
									move[length]=move[length-1];	
									getfood();
									length++;
								}
						else
						{
							DISP[Y[0]][X[0]]=' ';
							X[0]++;
						}
					break;									
			}
	
	for(z=1;z<length;z++)		
			{
				switch(move[z])
			{
				case 72: Y[z]--;
					break;
				case 80: Y[z]++;
					break;
				case 75: X[z]--;
					break;
				case 77: X[z]++;
					break;
				default:
					break;
			}
			}
	
	switch(move[length-1])
			{
				case 72: DISP[Y[length-1]+1][X[length-1]]=' ';
					break;
				case 80: DISP[Y[length-1]-1][X[length-1]]=' ';
					break;
				case 75: DISP[Y[length-1]][X[length-1]+1]=' ';
					break;
				case 77: DISP[Y[length-1]][X[length-1]-1]=' ';
					break;
				default:
					break;
			}

	return 1;
	}

void start()
	{
		int i, j;
		for(i=0;i<23;i++)
			for(j=0;j<72;j++)
				DISP[i][j]=' ';

		//s
		DISP[6][19]=DISP[6][20]=DISP[6][21]=DISP[6][22]=DISP[6][23]=snakeblock;
		DISP[7][19]=DISP[8][19]=snakeblock;
		DISP[9][19]=DISP[9][20]=DISP[9][21]=DISP[9][22]=DISP[9][23]=snakeblock;
		DISP[10][23]=DISP[11][23]=DISP[12][23]=snakeblock;
		DISP[13][19]=DISP[13][20]=DISP[13][21]=DISP[13][22]=DISP[13][23]=snakeblock;
		
		//n
		for(i=6;i<=13;i++)
			DISP[i][26]=DISP[i][31]=snakeblock;
		DISP[7][27]=DISP[8][28]=DISP[9][29]=DISP[10][30]=snakeblock;
		
		//a
		for(i=7;i<=13;i++)
			DISP[i][34]=DISP[i][38]=snakeblock;
		DISP[6][35]=DISP[6][36]=DISP[6][37]=snakeblock;
		DISP[9][35]=DISP[9][36]=DISP[9][37]=snakeblock;
		
		//k
		for(i=6;i<=13;i++)
			DISP[i][41]=snakeblock;
		DISP[9][42]=DISP[10][43]=DISP[8][43]=DISP[11][44]=DISP[7][44]=DISP[12][45]=DISP[6][45]=DISP[13][45]=snakeblock;
		
		//e	
		for(i=6;i<=13;i++)
			DISP[i][48]=snakeblock;
		DISP[6][49]=DISP[6][50]=DISP[6][51]=DISP[6][52]=snakeblock;
		DISP[9][49]=DISP[9][50]=DISP[9][51]=snakeblock;
		DISP[13][49]=DISP[13][50]=DISP[13][51]=DISP[13][52]=snakeblock;
		
		for(i=0;i<19;i++)
			{
				for(j=0;j<72;j++)
				printf("%c",DISP[i][j]);
				printf("\n");
			}		
	
		printf("\t\t\t Press any key to begin!\n");
	getch();
	}

int menu()
	{
		pos_ctr=0;
		char c=72; 
		
		while(c!=13)
			{
				switch(c)
					{
						case 72:if(pos_ctr>1)
									pos_ctr--;
								else
									pos_ctr=4;
							break;
						case 80:if(pos_ctr<4)
									pos_ctr++;
								else
									pos_ctr=1;
							break;
						default:
							break;
					}

				system("cls");
				printf("\n\t\t\tSNAKE-Menu");

				if(pos_ctr==1)
				printf("\n\n\n>>> NEW GAME");
			    else
				printf("\n\n\n    New Game");
				if(pos_ctr==2)
				printf("\n>>> INSTRUCTIONS");
			    else
				printf("\n    Instructions");
				if(pos_ctr==3)
				printf("\n>>> CREDITS");
			    else
				printf("\n    Credits");
				if(pos_ctr==4)
				printf("\n>>> EXIT");
			    else
				printf("\n    Exit");

			printf("\n\n\n\n\t    Use Arrow keys to navigate!");
			getch();
			c=getch();
		}
		return pos_ctr;
	}

void instructions()
	{
		system("cls");
		printf("\n\t\t\tSNAKE-Instructions");
		printf("\n\nWelcome to snake!\n\n ");
		int y;
		for(y=0;y<10;y++)
			printf("%c",snakeblock);
		printf("%c <- This is your snake.\n\n",snakehead );
		printf("The objective of the game is to eat as many food items as possible.\n");
		printf("Each food item looks like this: %c\n",snakefood);
		printf("\n\nEverytime you eat a food item, your length increases.\n");
		printf("But Beware! The game is over as soon as your snake collides with the wall\n");
		printf("or itself.\n");
		printf("\nDirect the snake using the Arrow Keys.\n");
		getch();
	}

void credits()
	{
		system("cls");
		printf("\n\t\t\tSNAKE-Credits");
		printf("\n\nThe game has been coded by Ayush Mishra\n");
		printf("\nProject Information:\n");
		printf("Started: 21-10-14\n");
		printf("Ended:   27-10-14\n");
		printf("Lines:   498\n");
		getch();
	}

int main()
	{

		start();
		int choice=0;
		while(choice!=4)
		{
			choice=menu();
			switch(choice)
			{
				case 1:builder();
					show();
					int y=1;
					char dir=left;
					while(y!=0)
						{
							char temp;
								if(kbhit())
									{	
										dir=_getch();
									}
							y=direction(dir);
							show();
						}
					getch();
					system("cls");
					printf("\n\n\tGAMEOVER. \n\tSCORE: %d", length-10);
					getch();
					break;
				case 2:instructions();
					break;
				case 3:credits();
					break;
				case 4: return 1;
				default:; 
			}
		}
		return 1;
	}


