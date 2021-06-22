#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=20,height=20,gameOver;
int x,y,fruitX,fruitY,score,flag;
int tailX[100],tailY[100];
int CountTail=0;

void setup(){

gameOver=0;
x=width/2;
y=height/2;

label1:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label1;
    label2:
        fruitY=rand()%20;
    if(fruitY==0)
        goto label2;
    score=0;
}

void draw(){
int i,j,k;
system("cls");
for(i=0;i<width;i++){
    for(j=0;j<height;j++){
        if(i==0||i==height-1||j==0||j==width-1)
            printf("*");
        else{
            if(i==x && j==y)
                printf("0");
            else if(i==fruitX && j==fruitY)
                printf("+");
            else{
                int ch=0;
                for(k=0 ; k<CountTail ; k++)  // i and j are in pair
                  {
                      if(i==tailX[k] && j == tailY[k]){
                        printf("o");
                        ch=1;
                      }
                  }
                  if(ch==0)
                    printf(" ");
            }
        }
    }
    printf("\n");
 }
}

void input()
{
    if(kbhit())
        {
        switch(getch())
        {

    case 75:  //
    case 'a':
         flag=1;
         break;

    case 'd':
    case 77:
         flag=2;
         break;

    case 'w':
    case 72:
         flag=3;
         break;

    case 's':
    case 80:
         flag=4;
         break;

    case 'x':
        gameOver =1;
        break;
        }
    }
}

void MakeLogic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;

    for(i=1 ; i<CountTail ; i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(flag){
case 1:
    y--;
    break;
case 2:
     y++;
     break;
case 3:
    x--;
    break;
case 4:
    x++;
    break;
default:
    break;
    }

    if(x<0||x>width||y<0||y>height)
    gameOver=1;
    for(i=0; i<CountTail ; i++)
    {
        if(x==tailX[i] && y == tailY[i])
            gameOver=1;
    }

    if(x==fruitX && y==fruitY)
    {
        label3:
            fruitX=rand()%20;
            if(fruitX==0)
                goto label3;
        label4:
               fruitY=rand()%20;
               if(fruitY==0)
                goto label4;
        score+=10;
        CountTail++;
    }
}

int main(){

/*int width,height;
printf("Enter the width and height of box : \n");
scanf("%d %d",&width,&height);
printf("\n");
*/


x=width/2;
y=height/2;
int m,n;
char c;
label5:

     setup();
     while(!gameOver)
     {
         draw();
         input();
         MakeLogic();
         for(m=0 ; m<1000; m++){
            for(n=0 ; n< 10000 ; n++){}}

        for(m=0 ; m<1000; m++){
            for(n=0 ; n< 10000 ; n++){}}
     }


     printf("\nSCORE = %d",score);
     printf("\n");
     fflush(stdin);
     printf("\n Press Y to continue again  :");
     scanf("%c",&c);
     if(c=='y' || c=='Y')
        goto label5;
     return 0;
}
