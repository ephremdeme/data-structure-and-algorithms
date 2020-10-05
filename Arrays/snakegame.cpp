/*
link the ncurses library in command line.
$clang++ snakegame.cpp -lncurses -o a.out
$./a.out
*/

#include <iostream>
#include <ncurses.h>


using namespace std;

bool isRunning = true;

const int Boundry_Width = 50;
const int Boundry_Height = Boundry_Width / 2;

const char Head = 'O';
const char Fruit = 'x';
const char Border = '#';
const char Blank = ' ';

char gameArr[Boundry_Height][Boundry_Width];
int headX, headY, fruitX, fruitY;
int score = 0;

enum movement{ Up = 0, Down, Left, Right};

movement curr_mov;

//Function declarations
void init();
void UserInput();
void DrawGame();
void GameLogic();
void EndGame();
//

void DrawGame()
{
    for(int i = 0; i < Boundry_Height; i++)
        for(int j = 0; j < Boundry_Width; j++)
            mvaddch(i, j, gameArr[i][j]);
    char _score[15] = "Score: ";
    char _s[4] = "0";
    sprintf(_s, "%d", score);
    strcat(_score, _s);
    mvaddstr(Boundry_Height + 2, 0, _score);
    wrefresh(stdscr);
}

void GameLogic()
{
    gameArr[headY][headX] = Blank;
    switch (curr_mov) {
        case Up:
            --headY;
            break;
        case Down:
            ++headY;
            break;
        case Left:
            --headX;
            break;
        case Right:
            ++headX;
            break;
        default:
            break;
    }
    
    if(headX == 0 || headX == Boundry_Width - 1 || headY == 0 || headY == Boundry_Height - 1)
    {
        isRunning = false;
    }
    else
    {
        gameArr[headY][headX] = Head;
        
        if(headY == fruitY && headX == fruitX)
        {
            score++;
            
            fruitX = rand() % (Boundry_Width - 2);
            if(fruitX == headX)
                fruitX = rand() % (Boundry_Width - 2);
            
            fruitY = rand() % (Boundry_Height - 2);
            if(fruitY == headY)
                fruitY = rand() % (Boundry_Height - 2);
            
            gameArr[fruitY][fruitX] = Fruit;
        }
    }
}

void UserInput()
{
    keypad(stdscr, true); //Can intercept special keys.
    halfdelay(1);
    
    int ch = getch();
    switch(ch)
    {
        case KEY_UP:
            curr_mov = Up;
            break;
        case KEY_DOWN:
            curr_mov = Down;
            break;
        case KEY_LEFT:
            curr_mov = Left;
            break;
        case KEY_RIGHT:
            curr_mov = Right;
            break;
        case 120: //ASCII for 'x'
            isRunning = false;
            break;
        default:
            break;
    }
}

void init()
{
    curr_mov = Left;
    
    headX = Boundry_Width / 2;
    headY = Boundry_Height / 2;
    
    fruitX = rand() % (Boundry_Width - 2);
    if(fruitX == headX)
        fruitX = rand() % (Boundry_Width - 2);
    
    fruitY = rand() % (Boundry_Height - 2);
    if(fruitY == headY)
        fruitY = rand() % (Boundry_Height - 2);
    
    for(int i = 0; i < Boundry_Height; i++)
    {
        for(int j = 0; j < Boundry_Width; j++)
        {
            gameArr[i][j] = Blank;
            if(i == 0 || i == Boundry_Height - 1 || j == 0 || j == Boundry_Width - 1)
                gameArr[i][j] = Border;
        }
    }
    
    gameArr[headY][headX] = Head;
    gameArr[fruitY][fruitX] = Fruit;
    
    initscr();
    clear();
    noecho(); //Doesn't display the cin key.
    cbreak(); //Disables terminal buffers.
}

void EndGame()
{
    endwin();
    cout << "Game Over !!!" << endl;
    cout << "Your Score: " << score << endl;
}

int main()
{
    init();
    
    while(isRunning)
    {
        DrawGame();
        UserInput();
        GameLogic();
    }
    
    EndGame();
    
    return 0;;
}
