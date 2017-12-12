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
    if(n == 1){                                         //如果圓盤只有一個，從A移到C
        gotoxy(31,8+N);
        Sleep(sec);
        printf("將第%d個圓盤從%c移到%c\n",n,A,C);

        gotoxy(20*(A-64)-n,4+locate[n][1]);             //圓盤從A柱(代號)消失
        for(i=1;i<=n;i++){
            printf(" ");
        }
        gotoxy(20*(A-64)+1,4+locate[n][1]);
        for(i=1;i<=n;i++){
            printf(" ");
        }

        k=N+1;                                          //找出C柱(代號)上最上層圓盤的位置
        for(i=1;i<=N;i++){
            if(locate[i][0] == C-64){
                if(locate[i][1]<k){
                    k = locate[i][1];
                }
            }
        }

        gotoxy(20*(C-64)-n,4+k-1);                      //將圓盤放在最上層圓盤的上一層
        for(i=1;i<=n;i++){
            printf("=");
        }
        gotoxy(20*(C-64)+1,4+k-1);
        for(i=1;i<=n;i++){
            printf("=");
        }

        locate[n][0] = C-64;                            //重新記錄圓盤位置
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
        move(locate,N,n-1,sec,A,C,B);                       //如果圓盤不只一個，將n-1個圓盤從A移到B
        gotoxy(31,8+N);                                 //再將第n個圓盤從A移到C
        Sleep(sec);

        printf("將第%d個圓盤從%c移到%c\n",n,A,C);

        gotoxy(20*(A-64)-n,4+locate[n][1]);             //圓盤從A柱(代號)消失
        for(i=1;i<=n;i++){
            printf(" ");
        }
        gotoxy(20*(A-64)+1,4+locate[n][1]);
        for(i=1;i<=n;i++){
            printf(" ");
        }

        k=N+1;                                          //找出C柱(代號)上最上層圓盤的位置
        for(i=1;i<=N;i++){
            if(locate[i][0] == C-64){
                if(locate[i][1]<k){
                    k = locate[i][1];
                }
            }
        }

        gotoxy(20*(C-64)-n,4+k-1);                      //將圓盤放在最上層圓盤的上一層
        for(i=1;i<=n;i++){
            printf("=");
        }
        gotoxy(20*(C-64)+1,4+k-1);
        for(i=1;i<=n;i++){
            printf("=");
        }

        locate[n][0] = C-64;                            //重新記錄圓盤位置
        locate[n][1] = k-1;

        D += 1;
        gotoxy(45,11+N);
        printf("    ");
        gotoxy(45,11+N);
        for(i=1;i<=(D%4);i++){
            printf(".");
        }

        move(locate,N,n-1,sec,B,A,C);                       //最將n-1個圓盤從B移到C
    }
}

int main(){
    int n,N,i,j,locate[50][2]={0},sec;
    char A='A',B='B',C='C';

    printf("請輸入[hanoi 塔]的層數 : ");
    scanf("%d",&n);
    printf("請輸入每次移動的間隔時間(ms) : ");
    scanf("%d",&sec);
    N=n;

    textbackground(LIGHTGRAY);                          //畫柱子
    for(i=1;i<4;i++){
        for(j=1;j<=n;j++){
            gotoxy(20*i,4+j);
            printf(" \n");
        }
    }

    textbackground(BLACK);
    textcolor(LIGHTGREEN);                               //寫柱子代號
    gotoxy(20,5+N);
    printf("A");
    gotoxy(40,5+N);
    printf("B");
    gotoxy(60,5+N);
    printf("C");
    gotoxy(67,1);
    printf("%c Mike Chen %c",15,15);
    textcolor(LIGHTGRAY);

    for(i=1;i<=N;i++){                                  //顯示起始狀態
        gotoxy(20-i,4+i);
        for(j=1;j<=i;j++){
            printf("=");
        }
        gotoxy(21,4+i);
        for(j=1;j<=i;j++){
            printf("=");
        }
        locate[i][0]=1;                                 //設定初始位置
        locate[i][1]=i;
    }

    textcolor(BROWN);
    gotoxy(26,7+N);
    printf("-----------------------------\n");
    gotoxy(26,8+N);
    printf("|                           |\n");
    gotoxy(26,9+N);
    printf("-----------------------------\n");
    gotoxy(26,10+N);
    printf("----                     ----\n");
    gotoxy(26,11+N);
    printf("---          (._. )       ---\n");
    gotoxy(26,12+N);
    printf("--                         --\n");
    gotoxy(26,12+N);
    printf("--                         --\n");
    textcolor(LIGHTGRAY);
    move(locate,N,n,sec,A,B,C);                             //開始移動
    gotoxy(39,11+N);
    printf("(OwO!)     \n");

    gotoxy(1,20);
    system("pause");
    return 0;
}
