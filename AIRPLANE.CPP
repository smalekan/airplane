#include <graphics.h>
#include <conio.h>
#include <math.h>
#define reg5 0.12

int point[8][3];
int LINE[12][2];
int  main_point[8][3];
int X=0,Y=0,Z=0,ZOO = 2;
int x= 300,y= 200;


char funky(int &f) {
	char c=getch();
	if(c==0) {
		f=1;
		c=getch();
	}
	else
		f=0;
	return(c);
}



void Move(int h)
{
	setcolor(0);
	for (int I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
	if(h==0)
		y-=1;
	else if(h==1)
		x+=1;
	else if(h==2)
		x-=1;
	else if(h==3)
		y+=1;
	setcolor(7);
	for (I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y+ point[LINE[I][1]][1]);
}

void init(void)
{
	point[0][0] = -10; point[0][1] =-10;point[0][2] = -10;
	point[1][0] = -10;point[1][1] = -10;point[1][2] = 10;
	point[2][0] = 10;point[2][1] = -10; point[2][2] = -10;
	point[3][0] = -10; point[3][1] = 10; point[3][2] =-10;
	point[4][0] = 10; point[4][1] = 10; point[4][2] = -10;
	point[5][0] = -10; point[5][1] = 10; point[5][2] =10;
	point[6][0] = 10; point[6][1] = -10; point[6][2] = 10;
	point[7][0] = 10; point[7][1] = 10; point[7][2] = 10;
	for(int i=0;i<8;i++)
		for(int j=0;j<3;j++)
		   main_point[i][j]=point[i][j];

	LINE[0][0] = 0; LINE[0][1] = 3;
	LINE[1][0] = 0; LINE[1][1] = 1;
	LINE[2][0] = 0; LINE[2][1] = 2;
	LINE[3][0] = 1; LINE[3][1] = 5;
	LINE[4][0] = 1; LINE[4][1] = 6;
	LINE[5][0] = 2; LINE[5][1] = 4;
	LINE[6][0] = 2; LINE[6][1] = 6;
	LINE[7][0] = 3; LINE[7][1] = 5;
	LINE[8][0] = 3; LINE[8][1] = 4;
	LINE[9][0] = 4; LINE[9][1] = 7;
	LINE[10][0] = 5; LINE[10][1] = 7;
	LINE[11][0] = 6; LINE[11][1] = 7;
}
void ROT(void)
{
	setcolor(0);
	for (int I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
	for (I = 0;I<8;I++)
	{
		int X_ROT,Y_ROT,Z_ROT;
		point[I][1] = main_point[I][1]*cos(X*reg5) - main_point[I][2]*sin(X*reg5);
		point[I][2] = main_point[I][1]*sin(X*reg5) + main_point[I][2]*cos(X*reg5);
		Y_ROT = point[I][1];
		Z_ROT = point[I][2];

		point[I][0] = main_point[I][0]*cos(Y*reg5) + Z_ROT*sin(Y*reg5);
		point[I][2] = -main_point[I][0]*sin(Y*reg5) + Z_ROT*cos(Y*reg5);
		X_ROT = point[I][0];
		Z_ROT = point[I][2];

		point[I][0] = X_ROT*cos(Z*reg5) - Y_ROT*sin(Z*reg5);
		point[I][1] = X_ROT*sin(Z*reg5) + Y_ROT*cos(Z*reg5);

	}
	setcolor(7);
	for (I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);

}

void ZOOM()
{
	setcolor(0);
	for (int I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
	for (I = 0 ;I<8;I++)
		for (int J = 0;J<3;J++)
			point[I][J] = point[I][J]*ZOO;
	setcolor(7);
	for (I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
}


void main(void)
{
	int GDRIVER = DETECT,GMODE;
	int EOP = 0,f;
	initgraph(&GDRIVER,&GMODE,"");
	init();
       while(!EOP)
	{
	ROT();
	 ZOOM();

		char c= funky(f);
		if (c== 27)
			EOP = 1;

		 else if ( c== 'z')
		 {
		// ROT();
		  Z++;
		  }
		else if (c== 'Z')
		{
	       //	ROT();
		 Z--;
		 }

		else if (c== 'y')
		{
	       //	ROT();
		Y++;
		}
		else if (c== 'Y')
		{
	      //	ROT();
		 Y--;
		 }
		else if (c== 'x')
		{
	      //	ROT();
		X++;
		}
		else if (c== 'X')
		{
	       //	ROT();
		 X--;
		 }
		else if (c== '+')
		{ZOO++;
	       //	ZOOM();
		}
		else if (c == '-')
		{ZOO--;
	       //	 ZOOM();
		}
		else if (c == 72) Move(0); //bala
		else if (c == 77) Move(1);          //rast
		else if (c == 75) Move(2);           //chap
		else if (c == 80) Move(3);         //pain
   }
	closegraph();
}