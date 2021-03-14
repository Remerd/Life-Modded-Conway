#include <stdio.h>						// 3D_LIFE lite
#include <ncurses.h>
#include <unistd.h>
#define N 32
#define iterations 10000 


int sumarround(int ul, int um, int ur, int ml, int mr, int bl, int bm, int br, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
 int sum = (ul+um+ur)+(ml+mr)+(bl+bm+br) + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18;
 return sum;
}

int status(int sum, int alive_or_dead)
{ 
 if(alive_or_dead == 0) //dead 
   {
    if (sum == 4) {return 1;}
    else {return 0;}
   }
 else //alive
   {
    if ((sum == 4) || (sum == 3)) {return 1;}
    else {return 0;}
   }

}
//Uncomment before coloring and change input
int get_color(int mm, int ul, int um, int ur, int ml, int mr, int bl, int bm, int br, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int mmc,int ulc, int umc, int urc, int mlc, int mrc, int blc, int bmc, int brc, int a1c, int a2c, int a3c, int a4c, int a5c, int a6c, int a7c, int a8c, int a9c, int a10c, int a11c, int a12c, int a13c, int a14c, int a15c, int a16c, int a17c, int a18c)
{//Making magic
int i,i_max_value,max_value;
i_max_value =0;

int color[6]={0};
for (i=0;i<6;i++)
	{
	if (mmc ==i)
		{if (mm==1)
			{color[i]= color[i]+2;}}// Priority for itself 
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
	if (a1c ==i)
		{if (a1 ==1)
		{color[i]= color[i]+1;}}
	if (a2c ==i)
		{if (a2 ==1)
		{color[i]= color[i]+1;}}
	if (a3c ==i)
		{if (a3 ==1)
		{color[i]= color[i]+1;}}
	if (a4c ==i)
		{if (a4 ==1)
		{color[i]= color[i]+1;}}
	if (a5c ==i)
		{if (a5 ==1)
		{color[i]= color[i]+1;}}
	if (a6c ==i)
		{if (a6 ==1)
		{color[i]= color[i]+1;}}
	if (a7c ==i)
		{if (a7 ==1)
		{color[i]= color[i]+1;}}
	if (a8c ==i)
		{if (a8 ==1)
		{color[i]= color[i]+1;}}
	if (a9c ==i)
		{if (a9 ==1)
		{color[i]= color[i]+1;}}
	if (a10c ==i)
		{if (a10 ==1)
		{color[i]= color[i]+1;}}
	if (a11c ==i)
		{if (a11 ==1)
		{color[i]= color[i]+1;}}
	if (a12c ==i)
		{if (a12 ==1)
		{color[i]= color[i]+1;}}
	if (a13c ==i)
		{if (a13 ==1)
		{color[i]= color[i]+1;}}
	if (a14c ==i)
		{if (a14 ==1)
		{color[i]= color[i]+1;}}
	if (a15c ==i)
		{if (a15 ==1)
		{color[i]= color[i]+1;}}
	if (a16c ==i)
		{if (a16 ==1)
		{color[i]= color[i]+1;}}
	if (a17c ==i)
		{if (a17 ==1)
		{color[i]= color[i]+1;}}
	if (a18c ==i)
		{if (a18 ==1)
		{color[i]= color[i]+1;}}

	}
max_value=color[0];
for(i = 1;i<6;i++)
        {
        if(max_value<color[i])
                {
                i_max_value = i;
                max_value = color[i];
		}
        }
for (i=0;i<6;i++)
{
	if (color[mmc]==color[i] && mm==1)
	{
		i_max_value=mmc;
	}
}
return i_max_value;
}

int print_matrix(int matrix[N][N][N][2])
{
 int i,j,k,f;
 for(i=0;i<N;i++)
 {
     for(k=0;k<70;k++)
        {
         printf(" ");
        }
     for(j=0;j<N;j++)
        {
     for(f=0;f<N;f++)
	{
         if(matrix[i][j][k][0]==1)
		{
		 if(matrix[i][j][k][1]==0)
			{printf("Y");}// Yellow
		 else if(matrix[i][j][k][1]==1)
			{printf("R");}// - Red
		 else if (matrix[i][j][k][1]==2)
			{printf("G");}// - Green
		else if (matrix[i][j][k][1]==3)
			{printf("B");}// - Blue
		else if (matrix[i][j][k][1]==4)
			{printf("M");}//  ???Maroon???
		else if(matrix[i][j][k][1]==5)
			{printf("P");}// Purple
		}

         else { printf("_");}}
        }
      printf("\n");
    }
}


int main(void)
{
 int i,j,step,sum,sum_c;
 int k=0;
 int a[N][N][N][2], b[N][N][N][2];
 
 FILE *file;

 int x;
 int y;
 int z;
 int c;

 int col_sum[6];

/*						//Uncomment before making graphics!!!
 remove("color_0.txt");
 remove("color_1.txt");
 remove("color_2.txt");
 remove("color_3.txt");
 remove("color_4.txt");
 remove("color_5.txt");*/

 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
	for (k=0;k<N;k++)
		{
     	 	a[i][j][k][0]=0;
	 	b[i][j][k][0]=0;
		}
	}
    }

 for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
        {
	for (k=0;k<N;k++)
		{
        	 a[i][j][k][1]=0;
        	 b[i][j][k][1]=0;
		}
        }
    }


 FILE *log;
 /*FILE *color_0;	//Uncomment before making graphics!!!
 FILE *color_1;
 FILE *color_2;
 FILE *color_3;
 FILE *color_4;
 FILE *color_5;*/


 //--- initial population --
 
 printf("START -------------------------->\n");

 print_matrix(a);
 
 //--- print next step -----------
 //--- CALCULATING ---------------


 for(step=0;;step++)
 {
   printf("ITERATION %d\n",step); 


 for(i=1;i<N-1;i++)
{
     for(j=1;j<N-1;j++)
    {
	    for (k=1;k<N-1;k++)
       	{
	    	sum = sumarround(a[i][j][k-1][0], a[i][j][k+1][0], a[i][j+1][k-1][0], a[i][j+1][k][0], a[i][j+1][k+1][0], a[i][j-1][k-1][0], a[i][j-1][k][0], a[i][j-1][k+1][0], a[i-1][j][k-1][0], a[i-1][j][k][0], a[i-1][j][k+1][0], a[i-1][j-1][k-1][0], a[i-1][j-1][k][0], a[i-1][j-1][k+1][0], a[i-1][j+1][k-1][0], a[i-1][j+1][k][0], a[i-1][j+1][k+1][0], a[i+1][j][k-1][0], a[i+1][j][k][0], a[i+1][j][k+1][0], a[i+1][j-1][k-1][0], a[i+1][j-1][k][0], a[i+1][j-1][k+1][0], a[i+1][j+1][k-1][0], a[i+1][j+1][k][0], a[i+1][j+1][k+1][0]);
		b[i][j][k][0]=status(sum,b[i][j][k][0]);

		b[i][j][k][1] = get_color(a[i][j][k][0], a[i][j][k-1][0], a[i][j][k+1][0], a[i][j+1][k-1][0], a[i][j+1][k][0], a[i][j+1][k+1][0], a[i][j-1][k-1][0], a[i][j-1][k][0], a[i][j-1][k+1][0], a[i-1][j][k-1][0], a[i-1][j][k][0], a[i-1][j][k+1][0], a[i-1][j-1][k-1][0], a[i-1][j-1][k][0], a[i-1][j-1][k+1][0], a[i-1][j+1][k-1][0], a[i-1][j+1][k][0], a[i-1][j+1][k+1][0], a[i+1][j][k-1][0], a[i+1][j][k][0], a[i+1][j][k+1][0], a[i+1][j-1][k-1][0], a[i+1][j-1][k][0], a[i+1][j-1][k+1][0], a[i+1][j+1][k-1][0], a[i+1][j+1][k][0], a[i+1][j+1][k+1][0], a[i][j][k][1], a[i][j][k-1][1], a[i][j][k+1][1], a[i][j+1][k-1][1], a[i][j+1][k][1], a[i][j+1][k+1][1], a[i][j-1][k-1][1], a[i][j-1][k][1], a[i][j-1][k+1][1], a[i-1][j][k-1][1], a[i-1][j][k][1], a[i-1][j][k+1][1], a[i-1][j-1][k-1][1], a[i-1][j-1][k][1], a[i-1][j-1][k+1][1], a[i-1][j+1][k-1][1], a[i-1][j+1][k][1], a[i-1][j+1][k+1][1], a[i+1][j][k-1][1], a[i+1][j][k][1], a[i+1][j][k+1][1], a[i+1][j-1][k-1][1], a[i+1][j-1][k][1], a[i+1][j-1][k+1][1], a[i+1][j+1][k-1][1], a[i+1][j+1][k][1], a[i+1][j+1][k+1][1]);
        }
    }
}




//--- print next step -----------

 
 // Reading new cells
 if(file = fopen("buffer.txt", "r"))
{
 while(fscanf (file, "%d%d%d%d", &y, &x, &z, &c) != EOF)
      {
       b[x][y][z][0]=1;
       b[x][y][z][1]=c;
      }
 fclose(file);
 remove("buffer.txt");
}
 



 //Log ALL!!! Previous version
/*
remove("log.txt");
 log = fopen("log.txt", "w");
 for (i=0;i<N;i++)
        {
        for (j=0;j<N;j++)
                {
		if (b[i][j][0]==1)
			{
        		 fprintf(log,"%d %d %d\n",i,j,b[i][j][1]);
			}
		else
			{
			fprintf(log,"%d %d 9\n",i,j);
			}
		}
        }
 fclose(log);*/


remove("log.txt");// Log cells for browser
 log = fopen("log.txt", "w");
 for (i=0;i<N;i++)
        {
        for (j=0;j<N;j++)
            {
	    for (k=0;k<N;k++)
            	{
		if ((b[i][j][k][0] != a[i][j][k][0]) || (b[i][j][k][1] != a[i][j][k][1]) || (step % 10 == 0) || (b[i][j][k][0] == 1))
        	    	{
				if (b[i][j][k][0]==1)
					{
        				 fprintf(log,"%d %d %d %d\n",i,j,k,b[i][j][k][1]);
					}
				else
					{
					fprintf(log,"%d %d %d 9\n",i,j,k);
					}
				}
			}
		}
        }
 fclose(log);



/*	// For making graphics. Logging rather colors
for (i=0;i<6;i++)
        {
         col_sum[i] = 0;
        }

 for(i=0;i<N;i++) 
    {
     for(j=0;j<N;j++)
        {
	if (b[i][j][0]==1)
		{
		col_sum[b[i][j][1]] = col_sum[b[i][j][1]] + 1;
		}
        }
    }


color_0 = fopen("color_0.txt", "a+");

fprintf(color_0,"%d ",step);
fprintf(color_0,"%d ", col_sum[0]);
fprintf(color_0,"\n");

fclose(color_0);

color_1 = fopen("color_1.txt", "a+");

fprintf(color_1,"%d ",step);
fprintf(color_1,"%d ", col_sum[1]);
fprintf(color_1,"\n");

fclose(color_1);

color_2 = fopen("color_2.txt", "a+");

fprintf(color_2,"%d ",step);
fprintf(color_2,"%d ", col_sum[2]);
fprintf(color_2,"\n");

fclose(color_2);

color_3 = fopen("color_3.txt", "a+");

fprintf(color_3,"%d ",step);
fprintf(color_3,"%d ", col_sum[3]);
fprintf(color_3,"\n");

fclose(color_3);

color_4 = fopen("color_4.txt", "a+");

fprintf(color_4,"%d ",step);
fprintf(color_4,"%d ", col_sum[4]);
fprintf(color_4,"\n");

fclose(color_4);

color_5 = fopen("color_5.txt", "a+");

fprintf(color_5,"%d ",step);
fprintf(color_5,"%d ", col_sum[5]);
fprintf(color_5,"\n");

fclose(color_5);
*/


//--- writing b to a -----------

 //printf("START WRITEING b TO a\n");
 for(i=0;i<N;i++)			 // From b to a saving
    {
     for(j=0;j<N;j++)
        {
	for (k=0;k<N;k++)
		{
        	 a[i][j][k][0]=b[i][j][k][0];
		 a[i][j][k][1]=b[i][j][k][1];
		}
        }
    }
// printf("END WRITEING b TO a\n");

//--- printing a -----------

 //printf("FINAL a\n");

// print_matrix(a);
 
 //getchar();
 
  sleep(2);
  }
  return(0);
}



