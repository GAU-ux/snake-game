#include<stdio.h>
#include<conio.h>
int main(){
    char ch;
    while(1){
         if(kbhit())
           {
               ch=getch();
               printf("character = %c",ch);
               break;
           }
    printf("Hello!\n");
    };
    return 0;
}
