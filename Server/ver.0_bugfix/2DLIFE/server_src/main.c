#include <stdio.h>
#include <unistd.h>
#define N 56
#define iterations 10000 

int sumarround(int ul, int um, int ur, int ml, int mr, int bl, int bm, int br)
{
 int sum = (ul+um+ur)+(ml+mr)+(bl+bm+br);
 return sum;
}

int status(int sum, int alive_or_dead)
{ 
 if(alive_or_dead==0) //dead 
   {
    if(sum==3) {return 1;}
    else {return 0;}
   }
 else //alive
   {
    if (sum<2) {return 0;}
    else if (sum>3) {return 0;}
    else {return 1;}
   }

}

int get_color(int mm, int ul, int um, int ur, int ml, int mr, int bl, int bm, int br, int mmc,int ulc, int umc, int urc, int mlc, int mrc, int blc, int bmc, int brc)
{
int i,i_max_value,max_value;
i_max_value =0;

int color[4]={0};
if (mm==1)
{
for (i=0;i<4;i++)
	{
	if (mmc ==i)
		{color[i]= color[i]+1;}
	if (ulc ==i)
		{if (ul ==1)
			{color[i]= color[i]+1;}}
	if (umc ==i)
		{if (um ==1)
		{color[i]= color[i]+1;}}
	if (urc ==i)
		{if (ur ==1)
		{color[i]= color[i]+1;}}
	if (mrc ==i)
		{if (mr ==1)
		{color[i]= color[i]+1;}}
	if (mlc ==i)
		{if (ml ==1)
		{color[i]= color[i]+1;}}
	if (blc ==i)
		{if (bl ==1)
		{color[i]= color[i]+1;}}
	if (bmc ==i)
		{if (bm ==1)
		{color[i]= color[i]+1;}}
	if (brc ==i)
		{if (br ==1)
		{color[i]= color[i]+1;}}
	}
max_value=color[0];
for(i = 1;i<4;i++)
        {
        if(max_value<color[i])
                {
                i_max_value = i;
                max_value = color[i];
		}
        }
return i_max_value;
}
else
{return 0;
}
}

int print_matrix(int matrix[N][N][2])
{
 int i,j,k;
 for(i=0;i<N;i++)
 {    
     for(k=0;k<70;k++)
        {
         printf(" ");
        }	 
     for(j=0;j<N;j++)
        {
         if(matrix[i][j][0]==1) 
		{
		 if(matrix[i][j][1]==0)
			{printf("O");}
		 else if(matrix[i][j][1]==1)
			{printf("Х");}
		 else if (matrix[i][j][1]==2)
			{printf("#");}
		else if (matrix[i][j][1]==3)
			{printf("U");}
		else if (matrix[i][j][1]==4)
			{printf("N");}
		else if(matrix[i][j][1]==5)
			{printf("F");}
		}
         else { printf("_");}
        }
      printf("\n");
    }
}


int main(void)
{
 int i,j,step,sum,sum_c;
 int k=0;
 int a[N][N][2], b[N][N][2];
 
 FILE *file;
 struct cellcord
 {
  int x;
  int y;
  int z;
 };
 struct cellcord newcell[10];

 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
         a[i][j][0]=0;
	 b[i][j][0]=0;
	}
    }

 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
         a[i][j][1]=0;
         b[i][j][1]=0;
        }
    }
 FILE *log;

/*
  a[8][1][0]=0;  a[8][2][0]=1;  a[8][3][0]=0;  a[8][4][0]=0;  a[8][5][0]=0;  a[8][6][0]=0;  a[8][7][0]=0;  a[8][8][0]=0; a[8][9][0]=1; a[8][10][0]=0; a[8][11][0]=0;
 a[8][12][0]=0; a[8][13][0]=0; a[8][14][0]=0; a[8][15][0]=0; a[8][16][0]=0; a[8][17][0]=0; a[8][18][0]=0; a[8][19][0]=0;
  a[9][1][0]=1;  a[9][2][0]=1;  a[9][3][0]=1;  a[9][4][0]=0;  a[9][5][0]=0;  a[9][6][0]=0;  a[9][7][0]=0;  a[9][8][0]=1; a[9][9][0]=1; a[9][10][0]=1; a[9][11][0]=0;
 a[9][12][0]=0; a[9][13][0]=0; a[9][14][0]=0; a[9][15][0]=0; a[9][16][0]=0; a[9][17][0]=0; a[9][18][0]=0; a[9][19][0]=0;
 a[10][1][0]=0; a[10][2][0]=1; a[10][3][0]=0; a[10][4][0]=0; a[10][5][0]=0; a[10][6][0]=0; a[10][7][0]=0; a[10][8][0]=0;a[10][9][0]=1;a[10][10][0]=0;a[10][11][0]=0;
a[10][12][0]=0;a[10][13][0]=0;a[10][14][0]=0;a[10][15][0]=0;a[10][16][0]=0;a[10][17][0]=0;a[10][18][0]=0;a[10][19][0]=0;

a[10][10][0]=1;a[10][11][0]=1;a[10][12][0]=1;a[9][12][0]=1;a[8][11][0]=1;
a[10][20][0]=1;a[10][21][0]=1;a[10][22][0]=1;a[9][22][0]=1;a[8][21][0]=1;
a[10][30][0]=1;a[10][31][0]=1;a[10][32][0]=1;a[9][32][0]=1;a[8][31][0]=1;
a[10][40][0]=1;a[10][41][0]=1;a[10][42][0]=1;a[9][42][0]=1;a[8][41][0]=1;
a[10][50][0]=1;a[10][51][0]=1;a[10][52][0]=1;a[9][52][0]=1;a[8][51][0]=1;
*/

 //--- print initial population --
 
 printf("START -------------------------->\n");
 //printf("INITIAL a\n");
 print_matrix(a);
 
// getchar();
 //--- print next step -----------

 //printf("INITIAL b\n");
 //print_matrix(b);

 //--- CALCULATING ---------------


 for(step=0;;step++)
 {
   printf("ITERATION %d\n",step); 


 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
         if(i==0)
           {
            if(j==0)
              {
               sum = sumarround(a[N-1][N-1][0],a[N-1][0][0],a[N-1][1][0], a[0][N-1][0],a[0][1][0], a[1][N-1][0],a[1][0][0],a[1][1][0]);
               //b[i][j]=2; // b[0][0]
               //b[i][j][0]=status(sum,b[i][j][0]); // b[0][0]
		b[i][j][0]=status(sum,b[i][j][0]);
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
              }
            else if(j==N-1)            
              {
               sum = sumarround(a[N-1][N-2][0],a[N-1][N-1][0],a[N-1][0][0], a[0][N-2][0],a[0][0][0], a[1][N-2][0],a[1][N-1][0],a[1][0][0]);
               //b[i][j]=4; // b[0][N-1]
               //b[i][j][0]=status(sum,b[i][j][0]); // b[0][N-1]
		b[i][j][0]=status(sum,b[i][j][0]);
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);

              }
            else
              {
               sum = sumarround(a[N-1][j-1][0],a[N-1][j][0],a[N-1][j+1][0], a[0][j-1][0],a[0][j+1][0], a[1][j-1][0],a[1][j][0],a[1][j+1][0]);
               //b[i][j]=3; // b[0][*]
               //b[i][j][0]=status(sum,b[i][j][0]); // b[0][*]
		b[i][j][0]=status(sum,b[i][j][0]);
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);
              } 
           }
         else if(i==N-1)
           {
            if(j==0)
              {
               sum = sumarround(a[N-2][N-1][0],a[N-2][0][0],a[N-2][1][0], a[N-1][N-1][0],a[N-1][1][0], a[0][N-1][0],a[0][0][0],a[0][1][0]);
               //b[i][j]=5; // b[N-1][0]
               //b[i][j][0]=status(sum,b[i][j][0]); // b[N-1][0]
		b[i][j][0]=status(sum,b[i][j][0]);
               b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);

		}
            else if(j==N-1)
              {
               sum = sumarround(a[N-2][N-2][0],a[N-2][N-1][0],a[N-2][0][0], a[N-1][N-2][0],a[N-1][0][0], a[0][N-2][0],a[0][N-1][0],a[0][0][0]);
               //b[i][j]=7; //b[N-1][N-1]
               b[i][j][0]=status(sum,b[i][j][0]); //b[N-1][N-1]
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);

              }
            else
              {
               sum = sumarround(a[N-2][j-1][0],a[N-2][j][0],a[N-2][j+1][0], a[N-1][j-1][0],a[N-1][j+1][0], a[0][j-1][0],a[0][j][0],a[0][j+1][0]);
               //b[i][j]=6; // b[N-1][8]
               b[i][j][0]=status(sum,b[i][j][0]); // b[N-1][8]
              	b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);

		}
           }
         else
           { 
            if(j==0)
              {
               sum = sumarround(a[i-1][N-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][N-1][0],a[i][j+1][0], a[i+1][N-1][0],a[i+1][j][0],a[i+1][j+1][0]);
               //b[i][j]=8; // b[*][0] (* != 0,N-1)
               b[i][j][0]=status(sum,b[i][j][0]); // b[*][0] (* != 0,N-1)
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);
  
              }
            else if(j==N-1)
              {
               sum = sumarround(a[i-1][j-1][0],a[i-1][j][0],a[i-1][0][0], a[i][j-1][0],a[i][0][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][0][0]);
               //b[i][j]=9; // b[*][N-1] (* != 0,N-1)
               b[i][j][0]=status(sum,b[i][j][0]); // b[*][N-1] (* != 0,N-1)
      		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);

		}
            else
              {
               //sum = sumarround(a[i+1][j-1],a[i+1][j],a[i+1][j+1], a[i][j-1],a[i][j+1], a[i-1][j-1],a[i-1][j],a[i-1][j+1]);
               sum = sumarround(a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0]);
	       //b[i][j]=1;
		b[i][j][0]=status(sum,b[i][j][0]);
		b[i][j][1] = get_color(a[i][j][0],a[i-1][j-1][0],a[i-1][j][0],a[i-1][j+1][0], a[i][j-1][0],a[i][j+1][0], a[i+1][j-1][0],a[i+1][j][0],a[i+1][j+1][0],a[i][j][1],a[i-1][j-1][1],a[i-1][j][1],a[i-1][j+1][1], a[i][j-1][1],a[i][j+1][1], a[i+1][j-1][1],a[i+1][j][1],a[i+1][j+1][1]);
		//b[i][j][0]=status(sum,b[i][j][0]);
              }
           }

        }
    }

for (i=0;i<N;i++)
	{
	for (j=0;j<N;j++)
		{
		if (b[i][j][0]==0)
			{b[i][j][1]=0;}
		}
	}

//printf("END CALCULATING\n");

//--- print next step -----------

 //printf("NEXT STEP\n");
 //print_matrix(b);
 

 if(file = fopen("buffer.txt", "r"))
{
 while(fscanf (file, "%d%d%d", &(newcell[k].y), &(newcell[k].x), &(newcell[k].z)) != EOF)
      {
       //printf("a[%d][%d]=1;", newcell[k].x, newcell[k].y);
       b[newcell[k].x][newcell[k].y][0]=1;
       b[newcell[k].x][newcell[k].y][1]=newcell[k].z;
       k++;
      }
 k=0;
 fclose(file);
 remove("buffer.txt");
}
/*
for (i=0;i<N;i++)
{
	for (j=0;j<N;j++)
	{
		if (b[i][j][1]>4)
		{
			b[i][j][1]=0;
		}
	}
}
*/
 remove("log.txt");
 log = fopen("log.txt", "w");
 for (i=0;i<N;i++)
        {
        for (j=0;j<N;j++)
                {
		if (b[i][j][0]==1)
			{
	                fprintf(log,"%d %d %d\n",j,i,b[i][j][1]);
                	}
		}
        }
 fclose(log);
 

//--- writing b to a -----------

 //printf("START WRITEING b TO a\n");
 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
         a[i][j][0]=b[i][j][0];
	 a[i][j][1]=b[i][j][1];
        }
    }
// printf("END WRITEING b TO a\n");

//--- printing a -----------

 //printf("FINAL a\n");
 print_matrix(a);
// getchar();

 sleep(3);
 }
 return(0);
}



