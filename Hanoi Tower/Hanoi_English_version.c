/*
THIS CODE IS MY OWN WORK.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "conio0.h"
#include "conio2.h"


void move(int locate[50][2],int N,int n,int sec,char A,char B,char C){
    int i,j,k,D;
    if(n == 1){                                         //Move from A to C if there is only one disk
        gotoxy(27,8+N);
        Sleep(sec);
        printf("Move %dth disk from %c to %c\n",n,A,C);

        gotoxy(20*(A-64)-n,4+locate[n][1]);             //Disk disappear from A
        for(i=1;i<=n;i++){
            printf(" ");
        }
        gotoxy(20*(A-64)+1,4+locate[n][1]);
        for(i=1;i<=n;i++){
            printf(" ");
        }

        k=N+1;                                          //Find the location of the top disk on C
        for(i=1;i<=N;i++){
            if(locate[i][0] == C-64){
                if(locate[i][1]<k){
                    k = locate[i][1];
                }
            }
        }

        gotoxy(20*(C-64)-n,4+k-1);                      //Place the disk above the top disk
        for(i=1;i<=n;i++){
            printf("=");
        }
        gotoxy(20*(C-64)+1,4+k-1);
        for(i=1;i<=n;i++){
            printf("=");
        }

        locate[n][0] = C-64;                            //Set the disk location
        locate[n][1] = k-1;

        D += 1;
        gotoxy(45,11+N);
        printf("    ");
        gotoxy(45,11+N);
        for(i=1;i<=(D%4);i++){
            printf(".");
        }


    }
    else{
        move(locate,N,n-1,sec,A,C,B);                   //If there is more than one disk, move n-1 disks from A to B
        gotoxy(27,8+N);                                 //Then move the nth disc from A to C
        Sleep(sec);

        printf("Move %dth disk from %c to %c\n",n,A,C);

        gotoxy(20*(A-64)-n,4+locate[n][1]);             //Disk disappear from A
        for(i=1;i<=n;i++){
            printf(" ");
        }
        gotoxy(20*(A-64)+1,4+locate[n][1]);
        for(i=1;i<=n;i++){
            printf(" ");
        }

        k=N+1;                                          //Find the location of the top disk on C
        for(i=1;i<=N;i++){
            if(locate[i][0] == C-64){
                if(locate[i][1]<k){
                    k = locate[i][1];
                }
            }
        }

        gotoxy(20*(C-64)-n,4+k-1);                      //Place the disk above the top disk
        for(i=1;i<=n;i++){
            printf("=");
        }
        gotoxy(20*(C-64)+1,4+k-1);
        for(i=1;i<=n;i++){
            printf("=");
        }

        locate[n][0] = C-64;                            //Set the disk location
        locate[n][1] = k-1;

        D += 1;
        gotoxy(45,11+N);
        printf("    ");
        gotoxy(45,11+N);
        for(i=1;i<=(D%4);i++){
            printf(".");
        }

        move(locate,N,n-1,sec,B,A,C);                   //Finally, move n-1 disks from B to C
    }
}

int main(){
    int n,N,i,j,locate[50][2]={0},sec;
    char A='A',B='B',C='C';

    printf("Please enter the disk amount of [hanoi tower] : ");
    scanf("%d",&n);
    printf("Please enter the interval time of each move (ms) : ");
    scanf("%d",&sec);
    N=n;

    //Draw pillar
    textbackground(LIGHTGRAY);
    for(i=1;i<4;i++){
        for(j=1;j<=n;j++){
            gotoxy(20*i,4+j);
            printf(" \n");
        }
    }

    //Write the code of pillars
    textbackground(BLACK);
    textcolor(LIGHTGREEN);
    gotoxy(20,5+N);
    printf("A");
    gotoxy(40,5+N);
    printf("B");
    gotoxy(60,5+N);
    printf("C");
    gotoxy(67,1);
    printf("%c Mike Chen %c",15,15);
    textcolor(LIGHTGRAY);

    //Show initial state
    for(i=1;i<=N;i++){
        gotoxy(20-i,4+i);
        for(j=1;j<=i;j++){
            printf("=");
        }
        gotoxy(21,4+i);
        for(j=1;j<=i;j++){
            printf("=");
        }

        //Set initial location
        locate[i][0]=1;
        locate[i][1]=i;
    }

    textcolor(BROWN);
    gotoxy(24,7+N);
    printf("--------------------------------\n");
    gotoxy(24,8+N);
    printf("|                              |\n");
    gotoxy(24,9+N);
    printf("--------------------------------\n");
    gotoxy(24,10+N);
    printf("----                        ----\n");
    gotoxy(24,11+N);
    printf("---           (._. )         ---\n");
    gotoxy(24,12+N);
    printf("--                            --\n");
    gotoxy(24,12+N);
    printf("--                            --\n");

    //Start moving
    textcolor(LIGHTGRAY);
    move(locate,N,n,sec,A,B,C);
    gotoxy(38,11+N);
    printf("(OwO!)     \n");

    gotoxy(1,20);
    system("pause");
    return 0;
}
