#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include<conio.h>

using namespace std;
bool game;
const int breadth = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection initialDir;
int tailY[50], tailX[50];
int taila;
unsigned seed = time(0);
int goodie = 0;

void settings();
void visuals();
void logic();
void input();

int main()
{
	settings();
	while (!game)
	{
		visuals();
		logic();
		input();
		Sleep(100);
	}
	return 0;
}

void settings()
{
	int a = UP;
	game = false;
	initialDir = STOP;
	srand(seed);
	x = breadth / 2;
	y = height / 2;

	fruitX = rand() % breadth;
	fruitY = rand() % height;
	score = 0;

}

void visuals()
{
	system("cls");
	char a;
	for (int a = 0; a < breadth; a++)
	{
		cout << "#";
	}
	cout << "\n";

	for (int a = 0; a < height; a++)
	{
		for (int aa = 0; aa < breadth; aa++)
		{
			if (aa == 0 || aa == breadth - 1)
			{
				cout << "#";
			}
			else if (a == y && aa == x)
			{
				cout << "0";
			}
			else if (aa == fruitX && a == fruitY)
			{
				cout <</*aaa*/"*";
			}
			else
			{
				bool printTaila = false;

				for (int count = 0; count < taila; count++)
				{
					if (tailX[count] == aa && tailY[count] == a)
					{
						cout << "o";
						printTaila = true;
					}
				}
				if(!printTaila)
				cout << " ";
			}
		}
		cout << "\n";
	}

	for (int a = 0; a < breadth; a++)
	{
		cout << "#";
	}

	cout << endl << "Score: " << score << endl;
}

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[00] = x;
	tailY[goodie] = y;

	for (int index = 1; index < taila; index++)
	{
		prev2X = tailX[index];
		prev2Y = tailY[index];
		tailX[index] = prevX;
		tailY[index] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch (initialDir)
	{
	case LEFT:x--;
		break;

	case RIGHT:x++;
		break;

	case UP: y--;
		break;

	case DOWN: y++;
		break;
	}
	
	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % breadth;
		fruitY = rand() % height;
		taila++;
	}

	if (x >= breadth)
	{
		x = 0;
	}
	if (x < 0)
	{
		x = breadth - 1;
	}

	if (y >= height)
	{
		y = 0;
	}
	if (y < 0)
	{
		y = height - 1;
	}
	for (int index = 0; index < taila; index++)
	{
		if (tailY[index] == y && tailX[index] == x)
		{
			game = true;
		}
	}
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a': initialDir = LEFT;
				break;

		case 'd': initialDir = RIGHT;
			break;

		case 'w': initialDir = UP;
			break;

		case 's': initialDir = DOWN;
			break;

		case 'X': game = true;
			break;

		}
	}
}

