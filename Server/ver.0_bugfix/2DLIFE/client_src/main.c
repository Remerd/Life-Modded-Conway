#include <stdio.h>
#include "lib.c"
int main(void)
{
FILE *file;
int action,i,x,y,team;
file = fopen("buffer.txt", "w");
 for( ; ;)
  {
   print_menu();
   scanf("%d",&action);
   switch(action)
    {
     case 1:
     file = fopen("buffer.txt", "w");
	printf("Выберите команду: ");
	printf("0 - O, 1 - X, 2 - #");
	scanf("%d",&team);
	for (i=0;i<10;i++)
        	{
        	printf("Введите координату X: ");
        	scanf("%d",&x);
        	while(x>=56)
        	        {
        	        printf("Число должно быть меньше 56\nВведите координату X: ");
        	        scanf("%d",&x);
        	        }
        	printf("Введите координату Y: ");
        	scanf("%d",&y);
        	while(y>=56)
        	        {
        	        printf("Число должно быть меньше 56\nВведите координату Y: ");
        	        scanf("%d",&y);
        	        }
	       	 fprintf(file,"%d %d %d\n",y,x,team);
        	}
     fclose(file);
     break;
     case 2:
     return(0);
     break;
    }
}
}
