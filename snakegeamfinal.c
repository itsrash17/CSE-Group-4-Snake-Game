#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define HEIGHT 20
#define WIDTH 40
int snktailX[100], snktailY[100];


int snktaillen;


int gameover, key, score;


int x, y, frtx, frty;

void setup() {

    gameover = 0;


    x = WIDTH / 2;
    y = HEIGHT / 2;

    frtx = rand() % WIDTH;
    frty = rand() % HEIGHT;
    while (frtx == 0)
        frtx = rand() % WIDTH;

    while (frty == 0)
        frty = rand() % HEIGHT;


    score = 0;
}


void draw() {
    system("cls");


    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {


            if (j == 0 || j == WIDTH)
                printf("|");


            if (i == y && j == x)
                printf("O");


            else if (i == frty && j == frtx)
                printf("*");


            else {
                int prtail = 0;
                for (int k = 0; k < snktaillen; k++) {
                    if (snktailX[k] == j
                        && snktailY[k] == i) {
                        printf("o");
                        prtail = 1;
                    }
                }
                if (!prtail)
                    printf(" ");
            }
        }
      printf("\n");

    }


    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
     printf("\n");


    printf("score = %d", score);
    printf("\n");
    printf("Press W, A, S, D for movement.\n");
    printf("Press X to quit the game.");
}


void input() {
    if (kbhit()) {
        switch (tolower(getch())) {
        case 'a':
            if(key!=2)
            key = 1;
            break;
        case 'd':
            if(key!=1)
            key = 2;
            break;
        case 'w':
            if(key!=4)
            key = 3;
            break;
        case 's':
            if(key!=3)
            key = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}


void logic() {


    int prevX = snktailX[0];
    int prevY = snktailY[0];
    int prev2X, prev2Y;
    snktailX[0] = x;
    snktailY[0] = y;
    for (int i = 1; i < snktaillen; i++) {
        prev2X = snktailX[i];
        prev2Y = snktailY[i];
        snktailX[i] = prevX;
        snktailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }


    switch (key) {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }


    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameover = 1;


    for (int i = 0; i < snktaillen; i++) {
        if (snktailX[i] == x && snktailY[i] == y)
            gameover = 1;
    }


    if (x == frtx && y == frty) {
        frtx = rand() % WIDTH;
        frty = rand() % HEIGHT;
        while (frtx == 0)
            frtx = rand() % WIDTH;

        while (frty == 0)
            frty = rand() % HEIGHT;
        score += 10;
         snktaillen++;
    }
}



void main() {


    setup();


    while (!gameover) {

        draw();
        input();
        logic();
        Sleep(40);
    }
}
