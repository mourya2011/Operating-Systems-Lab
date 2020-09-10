#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int x;
    x=fork();
    if(x==0)
    {
        for(int y=1;y<=10;y++)
         printf("Child Process \n");
        exit(0);
    }
    {
        for(int y=1;y<=10;y++)
         printf("Parent Process \n");

    }
   exit(0);
}