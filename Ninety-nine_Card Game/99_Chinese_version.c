#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "conio0.h"
#include "conio2.h"
#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <mmsystem.h>


void gameset(int *playeramount,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII,int *backgroundmusic){
    int i;

    system("cls");
    textcolor(DARKGRAY);
    gotoxy(50,1);printf("提示: 請將soundresource放入D槽");
    gotoxy(50,2);printf("提示: 玩家名稱不可超過8個字元");
    textcolor(LIGHTGRAY);
    gotoxy(1,1);printf("Game setting!\n");
    printf("Please enter player amount(4 >=amount>= 2): ");
    scanf("%d",&*playeramount);

    while(*playeramount<2 || *playeramount>4){
        fflush(stdin);
        printf("Wrong input!!\n");
        PlaySound( "D:\\soundresource\\fail.wav" , NULL, SND_FILENAME | SND_ASYNC);
        printf("Please enter player amount again(5>amount>1): ");
        scanf("%d",&*playeramount);
    }

    printf("Input success!\n");

    printf("Player 1 name: ");
    scanf("%s",playernameI);
    printf("Player 2 name: ");
    scanf("%s",playernameII);
    if(*playeramount >= 3){
        printf("Player 3 name: ");
        scanf("%s",playernameIII);
    }
    if(*playeramount >= 4){
        printf("Player 4 name: ");
        scanf("%s",playernameIIII);
    }

    printf("\n請選擇BGM:\n1.Adrift.wav\n2.Audioscribe.wav\n3.Awake.wav\n4.city2.wav\n5.Good Morning.wav\n6.Lensko.wav\n7.Matilda\n8.Stressed Out\n9.None\n");
    scanf("%d",&*backgroundmusic);
    while(*backgroundmusic<1 || *backgroundmusic>9){
        fflush(stdin);
        printf("Wrong input!!\n");
        PlaySound( "D:\\soundresource\\fail.wav" , NULL, SND_FILENAME | SND_ASYNC);
        printf("請重新選擇一次: ");
        scanf("%d",&*backgroundmusic);
    }
    PlaySound( "D:\\soundresource\\zero.wav" , NULL, SND_FILENAME | SND_ASYNC);

    printf("Finish!");
    Sleep(1000);
    system("cls");
}
void gamestart(){
    gotoxy(10,5);printf("    gggggggg         aaa        mmm        mmm   eeeeeeeeee");
    gotoxy(10,6);printf("   gg      gg       aa aa       mmmm      mmmm   ee");
    gotoxy(10,7);printf("  gg               aa   aa      mm mm    mm mm   eeeeeeee");
    gotoxy(10,8);printf("  gg      gggg    aaaaaaaaa     mm  mm  mm  mm   eeeeeeee");
    gotoxy(10,9);printf("   gg       gg   aa       aa    mm   mmmm   mm   ee");
    gotoxy(10,10);printf("    ggggggggg   aa         aa   mm    mm    mm   eeeeeeeeee");
    gotoxy(9,15);printf("   sssss      tttttttttt       aaa       rrrrrrr    tttttttttt");
    gotoxy(9,16);printf(" sss   sss    tttttttttt      aa aa      rr    rr   tttttttttt");
    gotoxy(9,17);printf("  ssss            tt         aa   aa     rr    rr       tt    ");
    gotoxy(9,18);printf("     ssss         tt        aaaaaaaaa    rrrrrrr        tt    ");
    gotoxy(9,19);printf(" sss   sss        tt       aa       aa   rr    rr       tt    ");
    gotoxy(9,20);printf("   sssss          tt      aa         aa  rr     rr      tt    ");

}

void bgm(int backgroundmusic){
    switch(backgroundmusic){
    case 1:
        PlaySound( "D:\\soundresource\\Adrift.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 2:
        PlaySound( "D:\\soundresource\\Audioscribe.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 3:
        PlaySound( "D:\\soundresource\\Awake.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 4:
        PlaySound( "D:\\soundresource\\city2.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 5:
        PlaySound( "D:\\soundresource\\Good Morning.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 6:
        PlaySound( "D:\\soundresource\\Lensko.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 7:
        PlaySound( "D:\\soundresource\\Matilda.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 8:
        PlaySound( "D:\\soundresource\\Stressed Out.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
        break;
    case 9:
        break;
    }
    Sleep(2000);
}

void playerturn(int playcount,int playeramount,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII){
    char ca;
    system("cls");
    gotoxy(6,5);printf("ppppppp   ll            aaa       yy      yy  eeeeeeeeee  rrrrrrr  ");
    gotoxy(6,6);printf("pp    pp  ll           aa aa       yy    yy   ee          rr    rr ");
    gotoxy(6,7);printf("pp    pp  ll          aa   aa       yy  yy    eeeeeeee    rr    rr ");
    gotoxy(6,8);printf("ppppppp   ll         aaaaaaaaa        yy      eeeeeeee    rrrrrrr  ");
    gotoxy(6,9);printf("pp        ll   ll   aa       aa       yy      ee          rr    rr ");
    gotoxy(6,10);printf("pp        lllllll  aa         aa      yy      eeeeeeeeee  rr     rr");
    gotoxy(39,13);printf(" _________________________");
    gotoxy(39,14);printf("|                         |");
    gotoxy(39,15);printf("|                         |");
    gotoxy(39,16);printf("|                         |");
    gotoxy(39,17);printf("|                         |");
    gotoxy(39,18);printf("|                         |");
    gotoxy(39,19);printf(" -------------------------");
    switch(playcount%playeramount){
    case 0:
        gotoxy(25,13);printf("  111");
        gotoxy(25,14);printf(" 1111");
        gotoxy(25,15);printf("   11");
        gotoxy(25,16);printf("   11");
        gotoxy(25,17);printf("   11");
        gotoxy(25,18);printf("11111111");
        gotoxy(43,14);printf("playername :");
        textcolor(LIGHTGREEN);
        gotoxy(56,14);printf("%s",playernameI);
        break;
    case 1:
        gotoxy(25,13);printf("  222");
        gotoxy(25,14);printf("22   22");
        gotoxy(25,15);printf("     22");
        gotoxy(25,16);printf("    22");
        gotoxy(25,17);printf("  22");
        gotoxy(25,18);printf("22222222");
        gotoxy(43,14);printf("playername :");
        textcolor(LIGHTGREEN);
        gotoxy(56,14);printf("%s",playernameII);
        break;
    case 2:
        gotoxy(25,13);printf(" 3333");
        gotoxy(25,14);printf("33   33");
        gotoxy(25,15);printf("    33");
        gotoxy(25,16);printf("    33");
        gotoxy(25,17);printf("33   33");
        gotoxy(25,18);printf("  333");
        gotoxy(43,14);printf("playername :");
        textcolor(LIGHTGREEN);
        gotoxy(56,14);printf("%s",playernameIII);
        break;
    case 3:
        gotoxy(25,13);printf("    444");
        gotoxy(25,14);printf("   4444");
        gotoxy(25,15);printf("  44 44");
        gotoxy(25,16);printf(" 44  44");
        gotoxy(25,17);printf("444444444");
        gotoxy(25,18);printf("     44");
        gotoxy(43,14);printf("playername :");
        textcolor(LIGHTGREEN);
        gotoxy(56,14);printf("%s",playernameIIII);
        break;
    }
    textcolor(LIGHTGRAY);
    gotoxy(12,21);printf("tttttttttt  uu     uu  rrrrrrr    nnn    nn");
    gotoxy(12,22);printf("tttttttttt  uu     uu  rr    rr   nnnn   nn");
    gotoxy(12,23);printf("    tt      uu     uu  rr    rr   nn nn  nn");
    gotoxy(12,24);printf("    tt      uu     uu  rrrrrrr    nn  nn nn");
    gotoxy(12,25);printf("    tt       uu   uu   rr    rr   nn   nnnn");
    gotoxy(12,26);printf("    tt        uuuuu    rr     rr  nn    nnn");
    ca = 0;
    gotoxy(43,16);printf("請按ENTER鍵換下個玩家");
    gotoxy(52,18);
    while(ca != '\r'){
        if(kbhit()){
            ca = getch();
        }
    }
    system("cls");
}

void showpointII(int num,int x,int y){
    switch(num){
    case 0:
        gotoxy(x,y+0);printf("   0000   ");
        gotoxy(x,y+1);printf(" 00000000 ");
        gotoxy(x,y+2);printf("000    000");
        gotoxy(x,y+3);printf("00      00");
        gotoxy(x,y+4);printf("00      00");
        gotoxy(x,y+5);printf("00      00");
        gotoxy(x,y+6);printf("00      00");
        gotoxy(x,y+7);printf("000    000");
        gotoxy(x,y+8);printf(" 00000000 ");
        gotoxy(x,y+9);printf("   0000   ");
        break;
    case 1:
        gotoxy(x,y+0);printf("  11111   ");
        gotoxy(x,y+1);printf(" 111111   ");
        gotoxy(x,y+2);printf("111 111   ");
        gotoxy(x,y+3);printf("    111   ");
        gotoxy(x,y+4);printf("    111   ");
        gotoxy(x,y+5);printf("    111   ");
        gotoxy(x,y+6);printf("    111   ");
        gotoxy(x,y+7);printf("    111   ");
        gotoxy(x,y+8);printf("1111111111");
        gotoxy(x,y+9);printf("1111111111");
        break;
    case 2:
        gotoxy(x,y+0);printf("  22222   ");
        gotoxy(x,y+1);printf("222222222 ");
        gotoxy(x,y+2);printf("22     222");
        gotoxy(x,y+3);printf("2      222");
        gotoxy(x,y+4);printf("      222 ");
        gotoxy(x,y+5);printf("     222  ");
        gotoxy(x,y+6);printf("    222   ");
        gotoxy(x,y+7);printf("   222   2");
        gotoxy(x,y+8);printf(" 2222   22");
        gotoxy(x,y+9);printf("2222222222");
        break;
    case 3:
        gotoxy(x,y+0);printf("  33333   ");
        gotoxy(x,y+1);printf("333333333 ");
        gotoxy(x,y+2);printf("33     333");
        gotoxy(x,y+3);printf("      333 ");
        gotoxy(x,y+4);printf("    3333  ");
        gotoxy(x,y+5);printf("     333  ");
        gotoxy(x,y+6);printf("      333 ");
        gotoxy(x,y+7);printf("33    3333");
        gotoxy(x,y+8);printf("333333333 ");
        gotoxy(x,y+9);printf("  33333   ");
        break;
    case 4:
        gotoxy(x,y+0);printf("      444 ");
        gotoxy(x,y+1);printf("    44444 ");
        gotoxy(x,y+2);printf("   444444 ");
        gotoxy(x,y+3);printf("  444 444 ");
        gotoxy(x,y+4);printf(" 444  444 ");
        gotoxy(x,y+5);printf("444   444 ");
        gotoxy(x,y+6);printf("4444444444");
        gotoxy(x,y+7);printf("4444444444");
        gotoxy(x,y+8);printf("      444 ");
        gotoxy(x,y+9);printf("      444 ");
        break;
    case 5:
        gotoxy(x,y+0);printf("5555555555");
        gotoxy(x,y+1);printf("555555555 ");
        gotoxy(x,y+2);printf("555       ");
        gotoxy(x,y+3);printf("555555    ");
        gotoxy(x,y+4);printf("55555555  ");
        gotoxy(x,y+5);printf("     5555 ");
        gotoxy(x,y+6);printf("       555");
        gotoxy(x,y+7);printf("55    5555");
        gotoxy(x,y+8);printf("555555555 ");
        gotoxy(x,y+9);printf("  55555   ");
        break;
    case 6:
        gotoxy(x,y+0);printf("   6666   ");
        gotoxy(x,y+1);printf(" 66666666 ");
        gotoxy(x,y+2);printf("666    666");
        gotoxy(x,y+3);printf("66        ");
        gotoxy(x,y+4);printf("66 6666   ");
        gotoxy(x,y+5);printf("666666666 ");
        gotoxy(x,y+6);printf("66     666");
        gotoxy(x,y+7);printf("666    666");
        gotoxy(x,y+8);printf(" 66666666 ");
        gotoxy(x,y+9);printf("   6666   ");
        break;
    case 7:
        gotoxy(x,y+0);printf("7777777777");
        gotoxy(x,y+1);printf("7777777777");
        gotoxy(x,y+2);printf("      777 ");
        gotoxy(x,y+3);printf("     777  ");
        gotoxy(x,y+4);printf("    777   ");
        gotoxy(x,y+5);printf("   777    ");
        gotoxy(x,y+6);printf("   777    ");
        gotoxy(x,y+7);printf("   777    ");
        gotoxy(x,y+8);printf("   777    ");
        gotoxy(x,y+9);printf("   777    ");
        break;
    case 8:
        gotoxy(x,y+0);printf("  888888  ");
        gotoxy(x,y+1);printf(" 88888888 ");
        gotoxy(x,y+2);printf("888    888");
        gotoxy(x,y+3);printf("888    888");
        gotoxy(x,y+4);printf(" 88888888 ");
        gotoxy(x,y+5);printf(" 88888888 ");
        gotoxy(x,y+6);printf("888    888");
        gotoxy(x,y+7);printf("888    888");
        gotoxy(x,y+8);printf(" 88888888 ");
        gotoxy(x,y+9);printf("  888888  ");
        break;
    case 9:
        gotoxy(x,y+0);printf("   9999   ");
        gotoxy(x,y+1);printf(" 99999999 ");
        gotoxy(x,y+2);printf("999   9999");
        gotoxy(x,y+3);printf("99     999");
        gotoxy(x,y+4);printf("999   9999");
        gotoxy(x,y+5);printf(" 999999999");
        gotoxy(x,y+6);printf("       999");
        gotoxy(x,y+7);printf("99     999");
        gotoxy(x,y+8);printf(" 99999999 ");
        gotoxy(x,y+9);printf("  99999   ");
        break;
    }
}

void showpointI(int point){
    int i;

    for(i=0;i<10;i++){
        gotoxy(24,5+i);printf("                                  ");
    }

    if(point/100 == 1){
        textcolor(WHITE);
        showpointII(1,24,5);
        showpointII(point/10-10,36,5);
        showpointII(point-10*(point/10),48,5);
        textcolor(LIGHTGRAY);
    }
    else if(point/100 == 0 && point/10 != 0){
        if(point == 99){
            textcolor(LIGHTRED);
            showpointII(point/10,29,5);
            showpointII(point-10*(point/10),43,5);
            textcolor(LIGHTGRAY);
        }
        else if(point >= 95 && point <= 98){
            textcolor(LIGHTMAGENTA);
            showpointII(point/10,29,5);
            showpointII(point-10*(point/10),43,5);
            textcolor(LIGHTGRAY);
        }
        else{
            showpointII(point/10,29,5);
            showpointII(point-10*(point/10),43,5);
        }
    }
    else{
        showpointII(point,36,5);
    }
}

void showname(int player,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII){

    textcolor(LIGHTGREEN);
    switch(player){
    case 0:
        printf("<%s>",playernameI);
        break;
    case 1:
        printf("<%s>",playernameII);
        break;
    case 2:
        printf("<%s>",playernameIII);
        break;
    case 3:
        printf("<%s>",playernameIIII);
        break;
    }
    textcolor(LIGHTGRAY);
}

void showplayer(int playcount,int count,int playeramount,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII,int inv,int choose[2]){
    int player,i;

    gotoxy(23,17);printf(" __________________________________ ");
    gotoxy(23,18);printf("|                                  |");
    gotoxy(23,19);printf(" ---------------------------------- ");

    gotoxy(28,33);printf(" ________________________ ");
    gotoxy(28,34);printf("|                        |");
    gotoxy(28,35);printf(" ------------------------ ");

    player = playcount%playeramount;
    gotoxy(7,20);
    showname(player,playernameI,playernameII,playernameIII,playernameIIII);

    textcolor(DARKGRAY);
    for(i=0;i<5;i++){
    gotoxy(5+12*(i+1),20);printf("%d.",i+1);
    }
    textcolor(LIGHTGRAY);

    if(count != 1){
        gotoxy(59,5);printf("上個玩家");
        if(choose[0] != 0){
            player = choose[0]-1;
            showname(player,playernameI,playernameII,playernameIII,playernameIIII);
        }
        else{
            if(inv == 0){
                player = (playcount-1)%playeramount;
                showname(player,playernameI,playernameII,playernameIII,playernameIIII);
            }
            else{
                player = (playcount+1)%playeramount;
                showname(player,playernameI,playernameII,playernameIII,playernameIIII);
            }
        }
        printf("出:");
    }
}

void showround(int count){
    textcolor(LIGHTGRAY);
    gotoxy(6,2);printf("第");
    if(count >= 480){
    textcolor(LIGHTRED);
    printf("%d",count);
    textcolor(LIGHTGRAY);
    printf("回合   ");
    textcolor(LIGHTRED);
    gotoxy(1,3);printf("注意!第500回合將會結束");
    textcolor(LIGHTGRAY);
    }
    else{
    textcolor(WHITE);
    printf("%d",count);
    textcolor(LIGHTGRAY);
    printf("回合   ");
    }
}

void showinv(int inv){

    if(inv == 0){
        gotoxy(6,4);printf("       ");
    }
    else{
        textcolor(YELLOW);
        gotoxy(6,4);printf("迴轉中~");
        textcolor(LIGHTGRAY);
    }

}

void showchoose_change(int playcount,int playeramount,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII,int choose[2],int change[3][3]){
    int player,i;

    if(choose[0] != 0){
        textcolor(YELLOW);
        gotoxy(6,6);printf("你被");
        player = choose[0]-1;
        showname(player,playernameI,playernameII,playernameIII,playernameIIII);
        textcolor(YELLOW);
        printf("指定了!");
        textcolor(LIGHTGRAY);
        choose[0] = 0;
    }

    for(i=0;i<3;i++){
        if(change[i][1] != 0){
            if(change[i][2] == playcount%playeramount+1){
                textcolor(YELLOW);
                gotoxy(6,8);printf("你被");
                player = change[i][1]-1;
                showname(player,playernameI,playernameII,playernameIII,playernameIIII);
                textcolor(YELLOW);
                printf("換牌了!");
                textcolor(LIGHTGRAY);
                change[i][1] = 0;
            }
        }
    }
}

void showpoker(int playcount,int count,int playeramount,int playerpoker[4][6],int show){
    int i,j,x,y;

    if(count == 1){
        j = 5;
    }
    else{
        j = 6;
    }

    if(show == 60){
        i = 0;
    }
    else{
        i = show;
        j = show+1;
    }

    for(i;i<j;i++){
        if(i == 5){
            x=4;y=-15;
        }
        else{
            x=i;y=0;
        }
        switch(playerpoker[playcount%playeramount][i]/4){
        case 15:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|         |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|         |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("|         |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("  ");
            break;
        case 0:
            if(playerpoker[playcount%playeramount][i]%4 == 0){
                textcolor(LIGHTCYAN);
            }
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|         |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|    *    |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("|         |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("1");
            break;
        case 1:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|    *    |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|         |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("|    *    |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("2");
            break;
        case 2:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|    *    |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|    *    |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("|    *    |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("3");
            break;
        case 3:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("| *     * |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|         |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("| *     * |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("4");
            break;
        case 4:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("| *     * |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("|    *    |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("| *     * |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("5");
            break;
        case 5:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("| *     * |");
            gotoxy(12*(x+1),24+y);printf("|         |");
            gotoxy(12*(x+1),25+y);printf("| *     * |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("| *     * |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("6");
            break;
        case 6:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("| *     * |");
            gotoxy(12*(x+1),24+y);printf("|    *    |");
            gotoxy(12*(x+1),25+y);printf("| *     * |");
            gotoxy(12*(x+1),26+y);printf("|         |");
            gotoxy(12*(x+1),27+y);printf("| *     * |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("7");
            break;
        case 7:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("| *     * |");
            gotoxy(12*(x+1),24+y);printf("|    *    |");
            gotoxy(12*(x+1),25+y);printf("| *     * |");
            gotoxy(12*(x+1),26+y);printf("|    *    |");
            gotoxy(12*(x+1),27+y);printf("| *     * |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("8");
            break;
        case 8:
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("| *     * |");
            gotoxy(12*(x+1),23+y);printf("|         |");
            gotoxy(12*(x+1),24+y);printf("| *     * |");
            gotoxy(12*(x+1),25+y);printf("|    *    |");
            gotoxy(12*(x+1),26+y);printf("| *     * |");
            gotoxy(12*(x+1),27+y);printf("|         |");
            gotoxy(12*(x+1),28+y);printf("| *     * |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            gotoxy(5+12*(x+1),30+y);printf("9");
            break;
        case 9:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("| *     * |");
            gotoxy(12*(x+1),23+y);printf("|    *    |");
            gotoxy(12*(x+1),24+y);printf("| *     * |");
            gotoxy(12*(x+1),25+y);printf("|         |");
            gotoxy(12*(x+1),26+y);printf("| *     * |");
            gotoxy(12*(x+1),27+y);printf("|    *    |");
            gotoxy(12*(x+1),28+y);printf("| *     * |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("10");
            break;
        case 10:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|  JJJJJJ |");
            gotoxy(12*(x+1),24+y);printf("|     J   |");
            gotoxy(12*(x+1),25+y);printf("|     J   |");
            gotoxy(12*(x+1),26+y);printf("|  J  J   |");
            gotoxy(12*(x+1),27+y);printf("|   JJJ   |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("J ");
            break;
        case 11:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|  QQQQ   |");
            gotoxy(12*(x+1),24+y);printf("| Q    Q  |");
            gotoxy(12*(x+1),25+y);printf("| Q    Q  |");
            gotoxy(12*(x+1),26+y);printf("| Q    Q  |");
            gotoxy(12*(x+1),27+y);printf("|  QQQQ Q |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("Q ");
            break;
        case 12:
            textcolor(LIGHTCYAN);
            gotoxy(12*(x+1),21+y);printf(" _________ ");
            gotoxy(12*(x+1),22+y);printf("|         |");
            gotoxy(12*(x+1),23+y);printf("|  K  K   |");
            gotoxy(12*(x+1),24+y);printf("|  K K    |");
            gotoxy(12*(x+1),25+y);printf("|  KK     |");
            gotoxy(12*(x+1),26+y);printf("|  K K    |");
            gotoxy(12*(x+1),27+y);printf("|  K  K   |");
            gotoxy(12*(x+1),28+y);printf("|         |");
            gotoxy(12*(x+1),29+y);printf(" --------- ");
            textcolor(LIGHTGRAY);
            gotoxy(5+12*(x+1),30+y);printf("K ");
            break;
        }
        switch(playerpoker[playcount%playeramount][i]%4){
        case 0:
            if(playerpoker[playcount%playeramount][i] == 60){
                gotoxy(3+12*(x+1),31+y);printf("<   > ");
            }
            else{
                gotoxy(3+12*(x+1),31+y);printf("<黑桃>");
            }
            break;
        case 1:
            gotoxy(3+12*(x+1),31+y);printf("<愛心>");
            break;
        case 2:
            gotoxy(3+12*(x+1),31+y);printf("<方塊>");
            break;
        case 3:
            gotoxy(3+12*(x+1),31+y);printf("<梅花>");
            break;
        }
    }
}

void getpoker(int playcount,int count,int playeramount,int playerpoker[4][6],int poker[52],int *pokerleft){   //抽卡
    int k=0,randnum;
    char ca;

    while(k<5){
        if(playerpoker[playcount%playeramount][k] == 60){
            ca = 0;
            gotoxy(30,18);printf("抽卡時間~ 請按ENTER鍵");
            gotoxy(40,34);
            while(ca != '\r'){
                if(kbhit()){
                    ca = getch();
                }
            }
            randnum = rand()%(*pokerleft);
            playerpoker[playcount%playeramount][k] = poker[randnum];
            poker[randnum] = poker[*pokerleft-1];
            poker[*pokerleft-1] = 60;
            *pokerleft -= 1;

            gotoxy(24,18);printf("                                  ");
            gotoxy(35,18);printf("抽卡成功!!! :D ");
            showpoker(playcount,count,playeramount,playerpoker,k);
            Sleep(500);
            gotoxy(24,18);printf("                                  ");
        }
        k += 1;
    }
}

void move(int *runy,int *ca, int min, int max){

    *ca = getch();
    switch(*ca){
    case 72:        //上
        if(*runy > min){
            gotoxy(4,*runy);printf(" ");
            *runy -= 1;
            gotoxy(4,*runy);printf("*");
        }
    break;
    case 80:         //下
        if(*runy < max){
            gotoxy(4,*runy);printf(" ");
            *runy += 1;
            gotoxy(4,*runy);printf("*");
        }
    break;
    }
}

void gamemenu(int *backgroundmusic,int *exit){
    int ca, runy, exit2;

    do{
        ca = 0;
        runy = 3;
        exit2 = 0;

        system("cls");
        textcolor(DARKGRAY);
        gotoxy(42,1);printf("提示: 請使用上下鍵移動游標，Enter選擇\n");
        textcolor(LIGHTGRAY);
        gotoxy(1,1);printf("Game menu:");
        gotoxy(6,3);printf("Change BGM");
        gotoxy(6,4);printf("Give up");
        textcolor(DARKGRAY);
        gotoxy(6,5);printf("Exit");

        textcolor(LIGHTGREEN);
        gotoxy(4,runy);printf("*");
        do{
            if(kbhit()){
                ca = getch();
                if(ca == 224){
                    move(&runy,&ca,3,5);
                }
                else if(ca == '\r'){
                    textcolor(LIGHTGRAY);
                    gotoxy(4,runy);printf(" ");
                    gotoxy(6,3);printf("                      ");
                    gotoxy(6,4);printf("       ");
                    gotoxy(6,5);printf("    ");
                    switch(runy){
                    case 3:
                        ca = 0;
                        gotoxy(4,2);printf("請選擇BGM:");
                        gotoxy(6,3);printf("Adrift.wav");
                        gotoxy(6,4);printf("Audioscribe.wav");
                        gotoxy(6,5);printf("Awake.wav");
                        gotoxy(6,6);printf("city2.wav");
                        gotoxy(6,7);printf("Good Morning.wav");
                        gotoxy(6,8);printf("Lensko.wav");
                        gotoxy(6,9);printf("Matilda.wav");
                        gotoxy(6,10);printf("Stressed Out.wav");
                        gotoxy(6,11);printf("None");
                        textcolor(DARKGRAY);
                        gotoxy(6,12);printf("Return");
                        textcolor(LIGHTGREEN);

                        gotoxy(4,runy);printf("*");
                        do{
                            if(kbhit()){
                                ca = getch();
                                if(ca == 224){
                                    move(&runy,&ca,3,12);
                                }
                            }
                        }while(ca != '\r');

                        if(runy > 2 && runy < 12){
                            PlaySound(NULL,NULL,SND_PURGE);
                        }
                        switch(runy){
                        case 3:
                            PlaySound( "D:\\soundresource\\Adrift.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 4:
                            PlaySound( "D:\\soundresource\\Audioscribe.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 5:
                            PlaySound( "D:\\soundresource\\Awake.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 6:
                            PlaySound( "D:\\soundresource\\city2.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 7:
                            PlaySound( "D:\\soundresource\\Good Morning.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 8:
                            PlaySound( "D:\\soundresource\\Lensko.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 9:
                            PlaySound( "D:\\soundresource\\Matilda.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 10:
                            PlaySound( "D:\\soundresource\\Stressed Out.wav" , NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                            exit2 = 1;
                            break;
                        case 11:
                            exit2 = 1;
                            break;
                        case 12:
                            exit2 = 2;
                            break;
                        }
                        break;
                    case 4:
                        ca = 0;
                        gotoxy(4,2);printf("Are you sure?");
                        gotoxy(6,3);printf("YES");
                        gotoxy(6,4);printf("NO");
                        textcolor(DARKGRAY);
                        gotoxy(6,5);printf("Return");
                        textcolor(LIGHTGREEN);

                        runy = 3;
                        gotoxy(4,runy);printf("*");
                        do{
                            if(kbhit()){
                                ca = getch();
                                if(ca == 224){
                                    move(&runy,&ca,3,5);
                                }
                            }
                        }while(ca != '\r');
                        switch(runy){
                        case 3:
                            *exit = 1;
                            exit2 = 1;
                            break;
                        case 4:
                            exit2 = 1;
                            break;
                        case 5:
                            exit2 = 2;
                            break;
                        }
                        break;
                    case 5:
                        exit2 = 1;
                        break;
                    }
                }
            }
        }while(exit2 == 0);
    }while(exit2 == 2);
    system("cls");
    textcolor(LIGHTGRAY);
}

void changepoker(int *playcount,int playeramount,int playerpoker[4][6],int change){
    int i,k;
    for(i=0;i<5;i++){
        k = playerpoker[*playcount%playeramount][i];
        playerpoker[*playcount%playeramount][i] = playerpoker[change-1][i];
        playerpoker[change-1][i] = k;
    }
}

void pokerchoose(int *playcount,int *count,int playeramount,char *playernameI,char *playernameII,char *playernameIII,char *playernameIIII,int playerpoker[4][6],int poker[52],int *pokerleft,int *point,int *inv,int choose[2],int change[3][3],int *backgroundmusic,int *exit){
    int secretchooseII,chooseII=0,i,j,k;
    char chooseI[10]={0},secretchooseI[10]={0},chooseIII=0,ca,secretI[10]="mikebest",secretII[10]="give_card",secretIII[10]="set_round";

    for(i=0;i<5;i++){
    //gotoxy(1,39+i);printf("playerpoker[0][%d]= %d  playerpoker[1][%d]= %d  playerpoker[2][%d]= %d    ",i,playerpoker[0][i],i,playerpoker[1][i],i,playerpoker[2][i]); //***********************
    }

    fflush(stdin);
    do{
        if(*exit != 1){
            textcolor(DARKGRAY);
            gotoxy(51,2);printf("提示: 輸入 9 可進入遊戲選單");
            textcolor(LIGHTGRAY);
            gotoxy(26,18);printf("請問要出什麼牌呢? 左~右編號1~5");
            gotoxy(40,34);scanf("%s",chooseI);
            while(chooseI[0]!=49 && chooseI[0]!=50 && chooseI[0]!=51 && chooseI[0]!=52 && chooseI[0]!=53 && chooseI[0]!=57 && strcmp(chooseI,secretI) != 0){
                fflush(stdin);
                gotoxy(24,18);printf("                                  ");
                gotoxy(34,18);printf("Wrong input!!");
                Sleep(1000);
                gotoxy(24,18);printf("                                  ");
                gotoxy(26,18);printf("請重新輸入一次 左~右編號1~5");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%s",chooseI);
            }
            if(strcmp(chooseI,secretI) == 0){
                for(i=0;i<10;i++){
                    secretchooseI[i] = 0;
                }
                textcolor(LIGHTRED);
                gotoxy(35,16);printf("::最高權限::");
                gotoxy(24,18);printf("                                  ");
                gotoxy(32,18);printf("Please input command");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%s",secretchooseI);
                if(strcmp(secretchooseI,secretII) == 0){
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(32,18);printf("Please select card");
                    gotoxy(29,34);printf("                        ");
                    gotoxy(40,34);scanf("%d",&secretchooseII);
                    k = 60;
                    for(i=0;i<*pokerleft;i++){
                        if(poker[i]/4 == secretchooseII-1){
                            k = i;
                        }
                    }
                    if(k == 60){
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(36,18);printf("No card!!");
                        Sleep(1500);
                    }
                    else{
                        j = playerpoker[*playcount%playeramount][0];
                        playerpoker[*playcount%playeramount][0] = poker[k];
                        poker[k] = j;
                        textcolor(LIGHTGRAY);
                        showpoker(*playcount,*count,playeramount,playerpoker,0);
                        textcolor(LIGHTRED);
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(36,18);printf("Success!");
                        Sleep(1500);
                    }
                }
                else if(strcmp(secretchooseI,secretIII) == 0){
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(32,18);printf("Please input number");
                    gotoxy(29,34);printf("                        ");
                    gotoxy(40,34);scanf("%d",&secretchooseII);
                    *count = secretchooseII;
                    showround(*count);
                    textcolor(LIGHTRED);
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(36,18);printf("Success!");
                    Sleep(1500);
                }
                gotoxy(35,16);printf("             ");
                gotoxy(29,34);printf("                        ");
                textcolor(LIGHTGRAY);
            }
            else if(chooseI[0] == 57){
                gamemenu(backgroundmusic,exit);
                showpointI(*point);
                showplayer(*playcount,*count,playeramount,playernameI,playernameII,playernameIII,playernameIIII,*inv,choose);
                showround(*count);
                showinv(*inv);
                showchoose_change(*playcount,playeramount,playernameI,playernameII,playernameIII,playernameIIII,choose,change);
                showpoker(*playcount,*count,playeramount,playerpoker,60);
            }
        }
        else if(*exit == 1){
            chooseI[0] = 49;
        }
    }while(strcmp(chooseI,secretI) == 0 || chooseI[0] == 57);

    if(*exit != 1){
        gotoxy(24,18);printf("                                  ");
        gotoxy(35,18);printf("選取成功!!!");
        //Sleep(1000);
        gotoxy(24,18);printf("                                  ");


        switch(playerpoker[*playcount%playeramount][chooseI[0]-49]/4){
        case 0:
            if(playerpoker[*playcount%playeramount][chooseI[0]-49]%4 == 0){
                *point = 0;
                gotoxy(39,18);printf("歸零!");
            }
            else{
                *point += 1;
            }
            break;
        case 1:
            *point += 2;
            break;
        case 2:
            *point += 3;
            break;
        case 3:
            gotoxy(39,18);printf("迴轉!");
            if(*inv == 0){
                *inv =1;
            }
            else{
                *inv =0;
            }
            break;
        case 4:
            fflush(stdin);
            gotoxy(27,18);printf("請問你要指定誰? 玩家1~%d",playeramount);
            gotoxy(29,34);printf("                        ");
            gotoxy(40,34);scanf("%d",&chooseII);
            while(chooseII<1 || chooseII>playeramount){
                fflush(stdin);
                gotoxy(24,18);printf("                                  ");
                gotoxy(34,18);printf("Wrong input!!");
                Sleep(1000);
                gotoxy(24,18);printf("                                  ");
                gotoxy(27,18);printf("請重新輸入一次 玩家1~%d",playeramount);
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%d",&chooseII);
            }
            choose[0] = *playcount%playeramount+1;
            choose[1] = chooseII;
            break;
        case 5:
            *point += 6;
            break;
        case 6:
            fflush(stdin);
            gotoxy(27,18);printf("請問你要 <1> +7 <2>換牌?");
            gotoxy(29,34);printf("                        ");
            gotoxy(40,34);scanf("%d",&chooseII);
            while(chooseII != 1 && chooseII != 2){
                fflush(stdin);
                gotoxy(24,18);printf("                                  ");
                gotoxy(34,18);printf("Wrong input!!");
                Sleep(1000);
                gotoxy(24,18);printf("                                  ");
                gotoxy(26,18);printf("請重新輸入一次 <1> +7 <2>換牌");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%d",&chooseII);
            }
            if(chooseII == 1){
                *point += 7;
            }
            else{
                gotoxy(24,18);printf("                                  ");
                gotoxy(26,18);printf("請問你要跟誰換牌? 玩家1~%d",playeramount);
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%d",&chooseII);

                while(chooseII<1 || chooseII>playeramount || chooseII == *playcount%playeramount+1){
                    fflush(stdin);
                    if(chooseII == *playcount%playeramount+1){
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(34,18);printf("不能跟自己換牌喔~");
                    }
                    else{
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(34,18);printf("Wrong input!!");
                    }
                    Sleep(1000);
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(27,18);printf("請重新輸入一次 玩家1~%d",playeramount);
                    gotoxy(29,34);printf("                        ");
                    gotoxy(40,34);scanf("%d",&chooseII);
                }
                if(change[0][0] == 0){
                    change[0][0] = 1;
                    change[0][1] = *playcount%playeramount+1;
                    change[0][2] = chooseII;

                }
                else if(change[1][0] == 0){
                    change[1][0] = 1;
                    change[1][1] = *playcount%playeramount+1;
                    change[1][2] = chooseII;
                }
                else if(change[2][0] == 0){
                    change[2][0] = 1;
                    change[2][1] = *playcount%playeramount+1;
                    change[2][2] = chooseII;
                }
            }
            break;
        case 7:
            *point += 8;
            break;
        case 8:
            *point += 9;
            break;
        case 9:
            fflush(stdin);
            gotoxy(30,18);printf("請問要 +-10? 請輸入 + or -");
            gotoxy(29,34);printf("                        ");
            gotoxy(40,34);scanf("%c",&chooseIII);
            while(chooseIII != 43 && chooseIII != 45){
                fflush(stdin);
                gotoxy(24,18);printf("                                  ");
                gotoxy(34,18);printf("Wrong input!!");
                Sleep(1000);
                gotoxy(24,18);printf("                                  ");
                gotoxy(27,18);printf("請重新輸入一次 + or -");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%c",&chooseIII);
            }

            if(*point < 10){
                while(chooseIII != 43){
                    fflush(stdin);
                    if(chooseIII == 45){
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(35,18);printf("無法 -10 !!");
                    }
                    else{
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(35,18);printf("Wrong input!!");
                    }
                    Sleep(1000);
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(30,18);printf("請重新輸入一次 + or -");
                    gotoxy(29,34);printf("                        ");
                    gotoxy(40,34);scanf("%c",&chooseIII);
                }
            }

            if(chooseIII == 43){
                *point += 10;
            }
            else{
                *point -= 10;
            }
            break;
        case 10:
            gotoxy(39,18);printf("PASS!");
            break;
        case 11:
            fflush(stdin);
            gotoxy(27,18);printf("請問要 +-20? 請輸入 + or -");
            gotoxy(29,34);printf("                        ");
            gotoxy(40,34);scanf("%c",&chooseIII);
            while(chooseIII != 43 && chooseIII != 45){
                fflush(stdin);
                gotoxy(24,18);printf("                                  ");
                gotoxy(34,18);printf("Wrong input!!");
                Sleep(1000);
                gotoxy(24,18);printf("                                  ");
                gotoxy(30,18);printf("請重新輸入一次 + or -");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);scanf("%c",&chooseIII);
            }

            if(*point < 20){
                while(chooseIII != 43){
                    fflush(stdin);
                    if(chooseIII == 45){
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(35,18);printf("無法 -20 !!");
                    }
                    else{
                        gotoxy(24,18);printf("                                  ");
                        gotoxy(35,18);printf("Wrong input!!");
                    }
                    Sleep(1000);
                    gotoxy(24,18);printf("                                  ");
                    gotoxy(30,18);printf("請重新輸入一次 + or -");
                    gotoxy(29,34);printf("                        ");
                    gotoxy(40,34);scanf("%c",&chooseIII);
                }
            }

            if(chooseIII == 43){
                *point += 20;
            }
            else{
                *point -= 20;
            }
            break;
        case 12:
            *point = 99;
            break;
        }
        poker[*pokerleft] = playerpoker[*playcount%playeramount][chooseI[0]-49];
        if(choose[0] != 0){
            playerpoker[choose[1]-1][5] = playerpoker[*playcount%playeramount][chooseI[0]-49];
        }
        else{
            if(*inv == 0){
                playerpoker[(*playcount+1)%playeramount][5] = playerpoker[*playcount%playeramount][chooseI[0]-49];
            }
            else{
                playerpoker[(*playcount-1)%playeramount][5] = playerpoker[*playcount%playeramount][chooseI[0]-49];
            }
        }

        playerpoker[*playcount%playeramount][chooseI[0]-49] = 60;
        *pokerleft += 1;

        for(i=0;i<3;i++){
            if(change[i][0] != 0){
                changepoker(playcount,playeramount,playerpoker,change[i][2]);
                showpoker(*playcount,*count,playeramount,playerpoker,60);
                ca = 0;
                gotoxy(24,18);printf("                                  ");
                gotoxy(30,18);printf("換牌成功! 請按ENTER鍵繼續");
                gotoxy(29,34);printf("                        ");
                gotoxy(40,34);
                while(ca != '\r'){
                    if(kbhit()){
                        ca = getch();
                    }
                }
                change[i][0] = 0;
            }
        }

        Sleep(500);
        gotoxy(24,18);printf("                                  ");
        gotoxy(29,34);printf("                        ");
        showpoker(*playcount,*count,playeramount,playerpoker,chooseI[0]-49);
    }
}

void caculate_playcount(int *playcount,int playeramount,int inv,int choose[2]){
    if(choose[0] != 0){
        if(inv == 0){
            if(choose[1] > (*playcount%playeramount+1)){
                *playcount += choose[1]-(*playcount%playeramount+1)-1;
            }
            else if(choose[1] < (*playcount%playeramount+1)){
                *playcount -= (*playcount%playeramount+1)-choose[1]+1;
            }
            else{
                *playcount -= 1;
            }
        }
        else{
            if(choose[1] > (*playcount%playeramount+1)){
                *playcount += choose[1]-(*playcount%playeramount+1)+1;
            }
            else if(choose[1] < (*playcount%playeramount+1)){
                *playcount -= (*playcount%playeramount+1)-choose[1]-1;
            }
            else{
                *playcount += 1;
            }
        }
    }
}


void gameover(int playcount,int playeramount,int *exit){
    int input,i;
    PlaySound(NULL,NULL,SND_PURGE);
    PlaySound( "D:\\soundresource\\explosion2.wav" , NULL, SND_FILENAME | SND_ASYNC);
    textcolor(LIGHTRED);
    for(i=1;i<22;i++){
        gotoxy(10+2*(i%2),2);printf("    gggggggg         aaa        mmm        mmm   eeeeeeeeee       ");
        gotoxy(10+2*(i%2),3);printf("   gg      gg       aa aa       mmmm      mmmm   ee               ");
        gotoxy(10+2*(i%2),4);printf("  gg               aa   aa      mm mm    mm mm   eeeeeeee         ");
        gotoxy(10+2*(i%2),5);printf("  gg      gggg    aaaaaaaaa     mm  mm  mm  mm   eeeeeeee         ");
        gotoxy(10+2*(i%2),6);printf("   gg       gg   aa       aa    mm   mmmm   mm   ee               ");
        gotoxy(10+2*(i%2),7);printf("    ggggggggg   aa         aa   mm    mm    mm   eeeeeeeeee       ");
        gotoxy(10+2*(i%2),8);printf("              >:D           >:D           >:D                     ");
        gotoxy(9+2*(i%2),9);printf("       oooooooo    vv         vv   eeeeeeeeee    rrrrrrr          ");
        gotoxy(9+2*(i%2),10);printf("     ooo      ooo   vv       vv    ee            rr    rr         ");
        gotoxy(9+2*(i%2),11);printf("     oo        oo    vv     vv     eeeeeeee      rr    rr         ");
        gotoxy(9+2*(i%2),12);printf("     oo        oo     vv   vv      eeeeeeee      rrrrrrr          ");
        gotoxy(9+2*(i%2),13);printf("     ooo      ooo      vv vv       ee            rr    rr         ");
        gotoxy(9+2*(i%2),14);printf("       oooooooo         vvv        eeeeeeeeee    rr     rr        ");
        gotoxy(63,15);printf("         ");
        gotoxy(63,16);printf("         ");
        Sleep(80);
    }
    textcolor(LIGHTGRAY);
    gotoxy(23,16);printf(" __________________________________ ");
    gotoxy(23,17);printf("|                                  |");
    gotoxy(23,18);printf("|                                  |");
    gotoxy(23,19);printf(" ---------------------------------- ");
    gotoxy(32,17);printf("玩家%d輸了!! :D",playcount%playeramount+1);
    gotoxy(30,18);printf("請問要重玩嗎? <1>是 <2>否 :");
    gotoxy(29,34);printf("                        ");
    gotoxy(40,34);scanf("%d",&input);
    while(input != 1 && input != 2){
        fflush(stdin);
        gotoxy(24,18);printf("                                  ");
        gotoxy(34,18);printf("Wrong input!!");
        PlaySound( "D:\\soundresource\\fail.wav" , NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000);
        gotoxy(24,18);printf("                                  ");
        gotoxy(26,18);printf("請重新輸入一次  <1>是 <2>否");
        gotoxy(29,34);printf("                        ");
        gotoxy(40,34);scanf("%d",&input);
    }
    *exit = input-1;
}
/*
playcount 計數器，每輪完一個玩家計數器就+1。   poker[52] 52張牌，裡面一開始是編號0~51，0=黑桃1 1=愛心1 2=方塊1 3=梅花1 4=黑桃2 5=愛心2 6=方塊2 7=梅花2 ......
pokerleft 儲存poker[52]裡剩下的張數          playerpoker[4][6] 儲存4個玩家5張牌(第6張牌為記錄玩家出什麼牌)，若沒牌則=60
playeramount 玩家人數                       inv 是否迴轉，inv=0 則 playcount += 1，inv=1 則 playcount -= 1
point 目前點數，>99則爆掉                    exit 每輪完一個玩家,檢查point是否>99，若是則exit=1，跳出第一個while，再詢問是否重新，若是則exit=0
count 計數器，每輪完一個玩家計數器就+1。
*/
int main(){
    int playcount,count, poker[52],pokerleft, playerpoker[4][6], playeramount, inv, point, exit, i, j, choose[2],change[3][3], backgroundmusic;
    char playernameI[10], playernameII[10], playernameIII[10], playernameIIII[10];
    srand(time(NULL));

    do{
        playcount=3000;count=1;pokerleft=52;inv=0;point=0;exit=0;choose[0]=0;

        for(i=0;i<3;i++){
            for(j=0;j<2;j++){
                change[i][j] = 0;
            }
        }

        for(i=0;i<52;i++){
            poker[i]=i;
        }

        for(i=0;i<4;i++){
            for(j=0;j<6;j++){
               playerpoker[i][j]=60;
            }
        }

        gameset(&playeramount,playernameI,playernameII,playernameIII,playernameIIII,&backgroundmusic);                  //遊戲設定
        gamestart();                                                                                                        //顯示遊戲開始字樣
        bgm(backgroundmusic);                                                                                               //撥放音樂

        do{
            playerturn(playcount,playeramount,playernameI,playernameII,playernameIII,playernameIIII);                       //顯示換哪個玩家
            showpointI(point);                                                                                              //顯示點數
            showplayer(playcount,count,playeramount,playernameI,playernameII,playernameIII,playernameIIII,inv,choose);      //顯示玩家名字&上一個玩家名字&撲克牌編號&訊息框&輸入框
            showround(count);
            showinv(inv);                                                                                                   //顯示有無迴轉
            showchoose_change(playcount,playeramount,playernameI,playernameII,playernameIII,playernameIIII,choose,change);  //顯示有無指定
            showpoker(playcount,count,playeramount,playerpoker,60);                                                         //顯示玩家撲克牌
            getpoker(playcount,count,playeramount,playerpoker,poker,&pokerleft);                                            //抽卡(包括顯示撲克牌)
            pokerchoose(&playcount,&count,playeramount,playernameI,playernameII,playernameIII,playernameIIII,playerpoker,poker,&pokerleft,&point,&inv,choose,change,&backgroundmusic,&exit);//用卡(包括顯示撲克牌)
            if(exit == 0){
                showinv(inv);                                                                                                   //顯示有無迴轉
                showpointI(point);
                if(point > 99 || count >= 500){
                    exit = 1;
                }
                else{
                    getpoker(playcount,count,playeramount,playerpoker,poker,&pokerleft);
                    Sleep(800);
                    count++;
                    caculate_playcount(&playcount,playeramount,inv,choose);
                    if(inv == 0){
                        playcount++;
                    }
                    else{
                        playcount--;
                    }
                }
            }
        }while(exit!=1);
        Sleep(1000);
        gameover(playcount,playeramount,&exit);
    }while(exit!=1);
    gotoxy(1,40);
    system("pause");
    return 0;
}

/*
1111111111001111111111001111111111
     111111111100001111111111
            1111111111
    0000   (長10  寬10)
  00000000
 000    000
 00      00
 00      00
 00      00
 00      00
 000    000
  00000000
    0000

   11111
  111111
 111 111
     111
     111
     111
     111
     111
 1111111111
 1111111111

   22222
 222222222
 22     222
 2      222
       222
      222
     222
    222   2
  2222   22
 2222222222

   33333
 333333333
 33     333
       333
     3333
      333
       333
 33    3333
 333333333
   33333

       444
     44444
    444444
   444 444
  444  444
 444   444
 4444444444
 4444444444
       444
       444

 5555555555
 555555555
 555
 555555
 55555555
      5555
        555
 55    5555
 555555555
   55555

    6666
  66666666
 666    666
 66
 66 6666
 666666666
 66     666
 666    666
  66666666
    6666

 7777777777
 7777777777
       777
      777
     777
     777
    777
    777
    777
    777

   888888
  88888888
 888    888
 888    888
  88888888
  88888888
 888    888
 888    888
  88888888
   888888

    9999
  99999999
 999   9999
 99     999
 999   9999
  999999999
        999
 99     999
  99999999
   99999

(長9  寬11)
___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________ ___________
|         | |         | |         | |         | |         | |         | |         | |         | | *     * | | *     * | |         | |         | |         |
|         | |    *    | |    *    | | *     * | | *     * | | *     * | | *     * | | *     * | |         | |    *    | |  JJJJJJ | |  QQQQ   | |  K  K   |
|         | |         | |         | |         | |         | |         | |    *    | |    *    | | *     * | | *     * | |     J   | | Q    Q  | |  K K    |
|    *    | |         | |    *    | |         | |    *    | | *     * | | *     * | | *     * | |    *    | |         | |     J   | | Q    Q  | |  KK     |
|         | |         | |         | |         | |         | |         | |         | |    *    | | *     * | | *     * | |  J  J   | | Q    Q  | |  K K    |
|         | |    *    | |    *    | | *     * | | *     * | | *     * | | *     * | | *     * | |         | |    *    | |   JJJ   | |  QQQQ Q | |  K  K   |
|         | |         | |         | |         | |         | |         | |         | |         | | *     * | | *     * | |         | |         | |         |
----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- ----------- -----------

介面:
 12345678911234567892123456789312345678941234567895123456789612345678971234567898
1
2     第?回合
3
4
5                          0000        0000        0000    上個玩家<PLAYER NAME>出:
6                        00000000    00000000    00000000            _________
7                       000    000  000    000  000    000          |         |
8                       00      00  00      00  00      00          |         |
9                       00      00  00      00  00      00          |         |
1                       00      00  00      00  00      00          |         |
1                       00      00  00      00  00      00          |         |
2                       000    000  000    000  000    000          |         |
3                        00000000    00000000    00000000           |         |
4                          0000        0000        0000              _________
5
6
7                       __________________________________
8                      |**********************************|   訊息框
9                       ----------------------------------
2       <PLAYER NAME>:
1            _________   _________   _________   _________   _________
2           |         | |         | |         | |         | |         |
3           |         | |         | |         | |         | |         |
4           |         | |         | |         | |         | |         |
5           |         | |         | |         | |         | |         |
6           |         | |         | |         | |         | |         |
7           |         | |         | |         | |         | |         |
8           |         | |         | |         | |         | |         |
9            _________   _________   _________   _________   _________
3                3           3           3           3           3       17 29 41 53 65
1              <**>        <**>        <**>        <**>        <**>     16 26 36 46 56
2
3                            ________________________
4                           |************************|   輸入框
5                            ------------------------
6
7
8
9
4

*/
