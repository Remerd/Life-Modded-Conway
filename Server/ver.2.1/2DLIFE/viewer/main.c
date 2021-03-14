#include <unistd.h>
#include <stdio.h>
#define N 56

void print_matrix(int matrix[N][N][2])
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
                        {printf("Y");}// - æ¸ëòûé
                 else if(matrix[i][j][1]==1)
                        {printf("R");}// - êðàñíûé
                 else if (matrix[i][j][1]==2)
                        {printf("G");}// - çåë¸íûé
                else if (matrix[i][j][1]==3)
                        {printf("B");}// - ãîëóáîé
                else if (matrix[i][j][1]==4)
                        {printf("M");}// Íå èñïîëüçóåòñÿ!
                else if(matrix[i][j][1]==5)
                        {printf("P");}// Íå èñïîëüçóåòñÿ!
                }
         else { printf("_");}
        }
      printf("\n");
    }
}


void main(void)
{
FILE *view;
int a[N][N][2] = {{0}};
int x, y, z;

while(1==1){
	if (view = fopen("log.txt", "r"))
	{
	while(fscanf (view, "%d%d%d", &x, &y, &z) != EOF)
	{
		if (z!=9){
			a[x][y][0]=1;
			a[x][y][1]=z;
		}
		else{
			a[x][y][0]=0;
		}
	}
	fclose(view);
//	remove("log.txt");
	}
	print_matrix(a);
	sleep(1);
}

}
