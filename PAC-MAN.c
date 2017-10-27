// CybeResdienT
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SIZE_MAP_X 30 // ºº∑Œ 20
#define SIZE_MAP_Y 30 // ∞°∑Œ 50

enum //ªˆ±Ú«‘ºˆ
{
    BLACK, /* 0 : ±Ó∏¡ */
    DARK_BLUE, /* 1 : æÓµŒøÓ ∆ƒ∂˚ */
    DARK_GREEN, /* 2 : æÓµŒøÓ √ ∑œ */
    DARK_SKY_BLUE, /* 3 : æÓµŒøÓ «œ¥√ */
    DARK_RED, /* 4 : æÓµŒøÓ ª°∞≠ */
    DARK_VIOLET, /* 5 : æÓµŒøÓ ∫∏∂Û */
    DARK_YELLOW, /* 6 : æÓµŒøÓ ≥Î∂˚ */
    GRAY, /* 7 : »∏ªˆ */
    DARK_GRAY, /* 8 : æÓµŒøÓ »∏ªˆ */
    BLUE, /* 9 : ∆ƒ∂˚ */
    GREEN, /* 10 : √ ∑œ */
    SKY_BLUE, /* 11 : «œ¥√ */
    RED, /* 12 : ª°∞≠ */
    VIOLET, /* 13 : ∫∏∂Û */
    YELLOW, /* 14 : ≥Î∂˚ */
    WHITE, /* 15 : «œæÁ */
    };//ªˆ∞•«‘ºˆµÈ
    int x=1; // «√∑π¿ÃæÓx¡¬«•
    int y=1; // «√∑π¿ÃæÓy¡¬«•

    int a=28; // ø¨µŒªˆ x¡¬«•
    int b=28; // ø¨µŒªˆ y¡¬«•

    int c=1; // ∫∏∂Ûªˆ x¡¬«•
    int d=28; // ∫∏∂Ûªˆ y¡¬«•

    int e=28; // ª°∞£ªˆ x¡¬«•
    int f=1; // ª°∞£ªˆ y¡¬«•

    int before1=5;
    int before2=5;
    int before3=5;

    int score=0;

    int try=1;

    int victory=0;

    int q=0;
    int w=0;

    int yn=2;

void removeCursor(void) // ƒøº≠∏¶ æ»∫∏¿Ã∞‘«—¥Ÿ
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int start(){ // Ω√¿€»≠∏È

    system("mode con:lines=31");//ºº∑Œ 31
    system("mode con:cols=88");// ∞°∑Œ 62


    gotoxy(30,13);
    SetColor(YELLOW);
    printf("æÓº≠øÕ ");
    SetColor(RED);
    printf("∆—∏«¿∫ √≥¿Ω¿Ã¡ˆ?");


    SetColor(SKY_BLUE);
    gotoxy(50,20);
    printf("500¿ª 50000¿∏∑Œ ø¨±›º˙");

    gotoxy(10,25);
    SetColor(RED);
    printf("æ∆π´∞≈≥™ ¥≠∑Ø∫¡");

    char key;
    key=getch();

}

int map[SIZE_MAP_X][SIZE_MAP_Y]= // ºº∑Œ30 ∞°∑Œ30 - ∏  µ•¿Ã≈Õ
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
         1,2,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,4,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,
         1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,3,3,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,3,1,1,1,1,3,1,3,3,3,3,1,3,1,1,1,1,3,1,1,1,1,3,1,
         1,3,1,3,3,3,3,3,3,3,1,3,1,1,1,3,1,1,3,1,3,3,3,3,3,3,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,3,3,3,3,3,3,1,3,1,1,3,1,1,1,3,1,3,3,3,3,3,3,3,1,3,1,
         1,3,1,1,1,1,3,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,3,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,
         1,1,1,3,1,1,1,1,1,3,1,1,1,0,1,1,0,1,1,1,3,1,3,1,1,1,3,1,1,1,
         1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,3,3,3,3,3,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,3,3,3,3,1,
         1,1,1,1,1,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,1,1,1,1,1,
         1,3,3,3,3,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,3,3,3,3,1,
         1,3,1,1,1,1,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,1,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,1,
         1,1,1,1,1,3,1,3,1,0,1,1,1,1,1,1,1,1,1,1,3,1,3,1,3,1,1,1,1,1,
         1,3,3,3,3,3,3,3,1,3,3,3,3,3,1,1,3,3,3,3,3,1,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,1,1,1,3,1,
         1,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,1,
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
         };

int remap[SIZE_MAP_X][SIZE_MAP_Y]= // ºº∑Œ30 ∞°∑Œ30, ∏  µ˚∑Œ ¿˙¿Â
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
         1,2,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,4,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,
         1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,1,3,1,0,0,0,1,3,1,0,0,0,1,3,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,3,3,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,3,1,1,1,1,3,1,3,3,3,3,1,3,1,1,1,1,3,1,1,1,1,3,1,
         1,3,1,3,3,3,3,3,3,3,1,3,1,1,1,3,1,1,3,1,3,3,3,3,3,3,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,3,3,3,3,3,3,1,3,1,1,3,1,1,1,3,1,3,3,3,3,3,3,3,1,3,1,
         1,3,1,1,1,1,3,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,3,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,
         1,1,1,3,1,1,1,1,1,3,1,1,1,0,1,1,0,1,1,1,3,1,3,1,1,1,3,1,1,1,
         1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,3,3,3,3,3,3,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
         1,3,3,3,3,3,3,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,3,3,3,3,1,
         1,1,1,1,1,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,1,1,1,1,1,
         1,3,3,3,3,3,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,3,3,3,3,3,1,
         1,3,1,1,1,1,1,3,1,3,1,3,1,3,1,1,3,1,3,1,3,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,1,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,
         1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,1,
         1,1,1,1,1,3,1,3,1,3,1,1,1,1,1,1,1,1,1,1,3,1,3,1,3,1,1,1,1,1,
         1,3,3,3,3,3,3,3,1,3,3,3,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,1,
         1,3,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,
         1,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,1,
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
         };

void gotoxy(int x, int y) // ¡¬«•¿Ãµø
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

int lose() // ¡ˆ¥¬ ¡∂∞«
{
    try=try+1; // Ω√µµ»Ωºˆ ¡ı∞°

    char key;

    w=score;

    if(w>q) q=w; // √÷¥Î Ω∫ƒ⁄æÓ¿˙¿Â

    system("cls");

    SetColor(RED);
    gotoxy(37,13);
    printf("¥ŸΩ√«œ±∏ΩÕ¬ﬁ??øÏ¬ﬁ¬ﬁ¬ﬁ?");

    gotoxy(30,16);
    SetColor(YELLOW);
    printf("¥œ ¡°ºˆ§ª§ª§ª§ª§ª : %d",score);
    SetColor(YELLOW);
    gotoxy(10,25);
    SetColor(SKY_BLUE);
    printf("¬j¬j§ª«Ï±Q§ª§ª§ª§ª§ª§ª500ø¯?");


    yn=0;
    getch();
    getch();
}


int win(){ // Ω¬∏Æ ¡∂∞«
    if(score==3600){

        q=0; // √÷¥Î¡°ºˆ
        w=0; // »πµÊ«—¡°ºˆ
        victory=victory+1; // Ω¬∏Æ »Ωºˆ ¡ı∞°
        try=try+1; // Ω√µµ»Ωºˆ ¡ı∞°
        system("cls");
        gotoxy(37,13);
        printf("«Ê«Ê«Ê«Ê«Ê«Ê«Ê«Ê");

        SetColor(YELLOW);

        SetColor(SKY_BLUE);
        gotoxy(20,25);
        printf("æ∆π´≈∞≥™ ¥©∏£∏È ∏Æº¬");

        char key;
        getch();
        key=getch();
        if(1) yn=0;

    }

}

int ghost(){// 0¿ß 1æ∆∑° 2øﬁ¬  3 ø¿∏•¬  // ø¿∏•¬ ¿ß¿Ø∑… ∫∏∂Û 1ƒ≠

    int moving;
    z:
    moving=rand();

    //ø¬πÊ«‚¿∏∑Œ ∏¯∞°∞‘«œ±‚
    if(before1==0 && moving%4==1){
        goto z;
    }
    else if(before1==1 && moving%4==0){
        goto z;
    }
    else if(before1==2 && moving%4==3){
        goto z;
    }
    else if(before1==3 && moving%4==2){
        goto z;
    }

    if(moving%4==0){ // ¿ß
        switch(map[c-1][d]){

        case    0:  map[c][d]=0;
                    gotoxy(d*2,c);
                    printf("  ");

                    c=c-1;

                    map[c][d]=4;
                    gotoxy(d*2,c);
                    SetColor(VIOLET);
                    printf("¢¡");
                    break;

        case    1:  goto z; break;

        case    2:  lose();
                    break;

        case    3:  map[c][d]=3;
                    gotoxy(d*2,c);
                    SetColor(YELLOW);
                    printf("§˝");

                    c=c-1;

                    map[c][d]=4;
                    gotoxy(d*2,c);
                    SetColor(VIOLET);
                    printf("¢¡");
                    break;

        case    4:  map[c][d]=0;
                    gotoxy(d*2,c);
                    printf("  ");

                    c=c-1;

                    map[c][d]=4;
                    gotoxy(d*2,c);
                    SetColor(VIOLET);
                    printf("¢¡");
                    break;
        }
}
    else if(moving%4==1){ //æ∆∑°
        switch(map[c+1][d]){
            case    0:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        c=c+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[c][d]=3;
                        gotoxy(d*2,c);
                        SetColor(YELLOW);
                        printf("§˝");

                        c=c+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;

            case    4:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        c=c+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;
    }

}
    else if(moving%4==2){ //øﬁ¬ 
        switch(map[c][d-1]){
            case    0:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        d=d-1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");    break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[c][d]=3;
                        gotoxy(d*2,c);
                        SetColor(YELLOW);
                        printf("§˝");

                        d=d-1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;
            case    4:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        d=d-1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;
        }
    }

    else if(moving%4==3){ // ø¿∏•¬ 
        switch(map[c][d+1]){
            case    0:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        d=d+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[c][d]=3;
                        gotoxy(d*2,c);
                        SetColor(YELLOW);
                        printf("§˝");

                        d=d+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;

            case    4:  map[c][d]=0;
                        gotoxy(d*2,c);
                        printf("  ");

                        d=d+1;

                        map[c][d]=4;
                        gotoxy(d*2,c);
                        SetColor(VIOLET);
                        printf("¢¡");
                        break;
        }
    }
    before1=moving%4;
}


int ghost2(){// 0¿ß 1æ∆∑° 2øﬁ¬  3 ø¿∏•¬  // ø¿∏•¬  æ∆∑° √ ∑œ¿Ø∑… 2ƒ≠

    int moving;
    z:
    moving=rand();

    //ø¬πÊ«‚¿∏∑Œ ∏¯∞°∞‘«œ±‚
    if(before2==0 && moving%4==1){
        goto z;
    }
    else if(before2==1 && moving%4==0){
        goto z;
    }
    else if(before2==2 && moving%4==3){
        goto z;
    }
    else if(before2==3 && moving%4==2){
        goto z;
    }

    if(moving%4==0){ // ¿ß
        switch(map[a-1][b]){

        case    0:  map[a][b]=0;
                    gotoxy(b*2,a);
                    printf("  ");

                    a=a-1;

                    map[a][b]=4;
                    gotoxy(b*2,a);
                    SetColor(GREEN);
                    printf("¢¡");
                    break;

        case    1:  goto z; break;

        case    2:  lose(); break;

        case    3:  map[a][b]=3;
                    gotoxy(b*2,a);
                    SetColor(YELLOW);
                    printf("§˝");
                    a=a-1;

                    map[a][b]=4;
                    gotoxy(b*2,a);
                    SetColor(GREEN);
                    printf("¢¡");
                    break;

        case    4:  map[a][b]=0;
                    gotoxy(b*2,a);
                    printf("  ");

                    a=a-1;

                    map[a][b]=4;
                    gotoxy(b*2,a);
                    SetColor(GREEN);
                    printf("¢¡");
                    break;


        }
}
    else if(moving%4==1){ //æ∆∑°
        switch(map[a+1][b]){
            case    0:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        a=a+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[a][b]=3;
                        gotoxy(b*2,a);
                        SetColor(YELLOW);
                        printf("§˝");

                        a=a+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

            case    4:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        a=a+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

    }
}
    else if(moving%4==2){ //øﬁ¬ 
        switch(map[a][b-1]){
            case    0:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        b=b-1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");    break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[a][b]=3;
                        gotoxy(b*2,a);
                        SetColor(YELLOW);
                        printf("§˝");

                        b=b-1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

            case    4:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        b=b-1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;
        }
    }

    else if(moving%4==3){ // ø¿∏•¬ 
        switch(map[a][b+1]){
            case    0:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        b=b+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[a][b]=3;
                        gotoxy(b*2,a);
                        SetColor(YELLOW);
                        printf("§˝");

                        b=b+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;

            case    4:  map[a][b]=0;
                        gotoxy(b*2,a);
                        printf("  ");

                        b=b+1;

                        map[a][b]=4;
                        gotoxy(b*2,a);
                        SetColor(GREEN);
                        printf("¢¡");
                        break;
        }
    }

    before2=moving%4;
}

int ghost3(){// 0¿ß 1æ∆∑° 2øﬁ¬  3 ø¿∏•¬  // øﬁ¬  æ∆∑° ª°∞£ªˆ¿Ø∑… 3ƒ≠

    int moving;
    z:
    moving=rand();

    //ø¬πÊ«‚¿∏∑Œ ∏¯∞°∞‘«œ±‚
    if(before3==0 && moving%4==1){
        goto z;
    }
    else if(before3==1 && moving%4==0){
        goto z;
    }
    else if(before3==2 && moving%4==3){
        goto z;
    }
    else if(before3==3 && moving%4==2){
        goto z;
    }

    if(moving%4==0){ // ¿ß
        switch(map[e-1][f]){

        case    0:  map[e][f]=0;
                    gotoxy(f*2,e);
                    printf("  ");

                    e=e-1;

                    map[e][f]=4;
                    gotoxy(f*2,e);
                    SetColor(RED);
                    printf("¢¡");
                    break;

        case    1:  goto z; break;

        case    2:  lose(); break;

        case    3:  map[e][f]=3;
                    gotoxy(f*2,e);
                    SetColor(YELLOW);
                    printf("§˝");
                    e=e-1;

                    map[e][f]=4;
                    gotoxy(f*2,e);
                    SetColor(RED);
                    printf("¢¡");
                    break;

        case    4:  map[e][f]=0;
                    gotoxy(f*2,e);
                    printf("  ");

                    e=e-1;

                    map[e][f]=4;
                    gotoxy(f*2,e);
                    SetColor(RED);
                    printf("¢¡");
                    break;


        }
}
    else if(moving%4==1){ //æ∆∑°
        switch(map[e+1][f]){
            case    0:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        e=e+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[e][f]=3;
                        gotoxy(f*2,e);
                        SetColor(YELLOW);
                        printf("§˝");

                        e=e+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

            case    4:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        e=e+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

    }
}
    else if(moving%4==2){ //øﬁ¬ 
        switch(map[e][f-1]){
            case    0:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        f=f-1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");    break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[e][f]=3;
                        gotoxy(f*2,e);
                        SetColor(YELLOW);
                        printf("§˝");

                        f=f-1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

            case    4:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        f=f-1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;
        }
    }

    else if(moving%4==3){ // ø¿∏•¬ 
        switch(map[e][f+1]){
            case    0:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        f=f+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

            case    1:  goto z; break;

            case    2:  lose(); break;

            case    3:  map[e][f]=3;
                        gotoxy(f*2,e);
                        SetColor(YELLOW);
                        printf("§˝");

                        f=f+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;

            case    4:  map[e][f]=0;
                        gotoxy(f*2,e);
                        printf("  ");

                        f=f+1;

                        map[e][f]=4;
                        gotoxy(f*2,e);
                        SetColor(RED);
                        printf("¢¡");
                        break;
        }
    }

    before3=moving%4;
}

int playmove() // «√∑π¿ÃæÓ øÚ¡˜¿Ã±‚
{

    char key;
    key=getch();

        if(key==27)
            exit(0);

        if (key==-32){
            key=getch();

            if(key==UP && map[x-1][y]!=1){
                switch(map[x-1][y]){
                case    3:  score=score+10; break;
                case    4:  lose(); break;
                }
            map[x][y]=0;
            gotoxy(y*2,x); // gotoxy¥¬ (∞°∑Œ,ºº∑Œ)
            printf("  ");

            x=x-1;

            map[x][y]=2;
            gotoxy(y*2,x);
            SetColor(YELLOW);
            printf("°„");
        }

        else if(key==DOWN && map[x+1][y]!=1){
                switch(map[x+1][y]){
                case    3:  score=score+10; break;
                case    4:  lose(); break;
                }
            map[x][y]=0;
            gotoxy(y*2,x);
            printf("  ");

            x=x+1;

            map[x][y]=2;
            gotoxy(y*2,x);
            SetColor(YELLOW);
            printf("°Â");
        }

        else if(key==LEFT && map[x][y-1]!=1){
                switch(map[x][y-1]){
                case    3:  score=score+10; break;
                case    4:  lose(); break;
                }
            map[x][y]=0;
            gotoxy(y*2,x);
            printf("  ");

            y=y-1;

            map[x][y]=2;
            gotoxy(y*2,x);
            SetColor(YELLOW);
            printf("¢∏");
            }

        else if(key==RIGHT && map[x][y+1]!=1){
                switch(map[x][y+1]){
                case    3:  score=score+10; break;
                case    4:  lose();  break;

                }
            map[x][y]=0;
            gotoxy(y*2,x);
            printf("  ");

            y=y+1;

            map[x][y]=2;
            gotoxy(y*2,x);
            SetColor(YELLOW);
            printf("¢∫");
            }
        }
}


int scoredraw(){ // ∞‘¿”»≠∏È ø¿∏•¬  ¿Œ≈Õ∆‰¿ÃΩ∫ // ¡ˆø¸æÓ
/*
    gotoxy(62,3);
    SetColor(VIOLET);
    printf("¢¡ 1ƒ≠");

    gotoxy(62,5);
    SetColor(GREEN);
    printf("¢¡ 2ƒ≠");

    gotoxy(62,7);
    SetColor(RED);
    printf("¢¡ 3ƒ≠");



    gotoxy(62,10);
    SetColor(YELLOW);
    printf("%d / 3600",score);

    gotoxy(62,13);
    SetColor(WHITE);
    printf("High Score: %d",q);

    gotoxy(62,14);
    printf("Clear °Ê High Score reset");

    gotoxy(62,16);
    SetColor(SKY_BLUE);
    printf("Victory",victory);
    SetColor(YELLOW);
    printf(" / ");
    SetColor(RED);
    printf("Try ");
    SetColor(YELLOW);
    printf(": ");
    SetColor(SKY_BLUE);
    printf("%d ",victory);
    SetColor(YELLOW);
    printf("/ ");
    SetColor(RED);
    printf("%d",try);
*/
}

int mapdraw() // ∏ ±◊∏Æ±‚
{
    int i,j;
    for(i=0;i<30;i++)
     {
         for(j=0;j<30;j++)
         {
            switch(map[i][j]){
                case    0:  printf("  ");   break;
                case    1:  SetColor(BLUE);    printf("°·");    break;
                case    2:  SetColor(YELLOW);   printf("°‹");    break;
                case    3:  SetColor(YELLOW);    printf("§˝");    break;
                case    4:  SetColor(WHITE);  printf("¢¡");    break;
                case    5:  printf("\n");   break;
            }
         }
         printf("\n");
     }

/*
    SetColor(YELLOW);

     gotoxy(62,19);
     printf("ESC : ¡æ∑·");
     gotoxy(62,21);
     printf("°Ë :¿ß");
     gotoxy(62,23);
     printf("°È :æ∆∑°");
     gotoxy(62,25);
     printf("°Á :øﬁ¬ ");
     gotoxy(62,27);
     printf("°Ê :ø¿∏•¬ ");
     */
}

int startoption(){
    x=1; // «√∑π¿ÃæÓx¡¬«•
    y=1; // «√∑π¿ÃæÓy¡¬«•

    a=28; // ∞ÌΩ∫∆Æ2 x¡¬«•
    b=28; // ∞ÌΩ∫∆Æ2 y¡¬«•

    c=1;
    d=28;

    e=28;
    f=1;
    before1=5;
    before2=5;
    before3=5;
    yn=2;

    int m,n; // ∏  ∏Æº¬
    for(m=0;m<30;m++){
        for(n=0;n<30;n++){
            map[m][n]=remap[m][n];

        }
    }
    score=0;

}

int main()
{
    restart:
    start();

    removeCursor();
    while(1)
    {
        re:
        startoption();
        system("cls");
        mapdraw();
        while(1)
        {
            scoredraw();


            playmove();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            ghost();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            ghost2();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            ghost3();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            Sleep(20);

            ghost2();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            ghost3();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            Sleep(20);

            ghost3();
            if(yn==1)   goto re;
            else if(yn==0)  goto restart;

            win();
            if(yn==0)   goto restart;
        }
    }

    return 0;
}
