#include<stdio.h>
int main()
{
    int side;
    printf("Enter the side of the square : ");
    scanf("%d",&side);
    printf("\n\n");

int i,j;
    for(i=1;i<side;i++){
        for(j=1;j<side;j++){

             if(i==1||j==1||j==side-1||i==side-1)
                 printf("#");
            else
                 printf(" ");
        }
        printf("\n");
    }
}
