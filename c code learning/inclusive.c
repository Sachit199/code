/*#include<stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    int  y ;
    printf("enter a no :");
    scanf("%d",&y);
    int z;
    printf ("enter a no :");
     scanf("%d",&z);
     if ((x + y + z) / 3 == 0)
     {
        printf("sum of three avg no ");
     }
     else {
        printf("not avg no");
     }

	
	return 0;
}*/
/* or this syntax can be written like this as upper one was just printing avg three no but in next code 
it give answer with it */
#include<stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    int  y ;
    printf("enter a no :");
    scanf("%d",&y);
    int z;
    printf ("enter a no :");
   scanf("%d",&z);
   int a= ((x + y + z) / 3 );
   printf("average of three no is : %d",a);
	return 0;
}