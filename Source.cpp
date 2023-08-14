#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>


const int height = 20;
int width = 30;
bool isDraw;
bool menuOver;
bool settingExit;
bool choice;
bool language;
int key = 0;
int qr = 0;
const int snakeLength = 30 * 20;
int burgerX, burgerY; //���������� ������� (��������)
bool isDrawScreen;
bool gameOver; //����� ����, ���� True
int score = 0; //������� �����
const char LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's', STOP = 'x';
char rotate = 0;
bool gameStart;
char dot = '.';

std::string ruScreen[]{ "#                 #           #",
					   "# ### #   # ### #   # # # ### #",
					   "#   # ## ## #   #  ## ##  # # #",
					   "# ### # # # ### # # # #   ### #",
					   "#   # #   # #   ##  # ##  # # #",
					   "# ### #   # ### #   # # # # # #" };

std::string enScreen[]{ "#                             #",
					   "#    #### #   # ### # # ###   #",
					   "#   #     ##  # # # ##  #     #",
					   "#    ###  # # # ### #   ###   #",
					   "#       # #  ## # # ##  #     #",
					   "#   ####  #   # # # # # ###   #" };

struct coordinates
{
	int x, y; //���������� ����
};
coordinates coord;
coordinates snake[snakeLength]{};

//struct people
//{
//	std::string name;
//};
//people* winners = new people[5];

void MenuDraw()
{
	
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		if (language)
			std::cout << ruScreen[i];
		else
			std::cout << enScreen[i];
		std::cout << std::endl;
	}

	for (int y = 0; y < height - 6; y++)
	{
		for (int x = 0; x < width; x++)
		{
			isDrawScreen = false;
			if (x == 0 || x == width - 1)
				std::cout << "#";

			if (language)
			{
				if (y == 5 && x == 7)
				{
					std::cout << "1.  ������ ����";
					width = width - 15;
				}
				if (y == 7 && x == 5)
				{
					std::cout << "2.  ������� �������";
					width = width - 19;
				}
				if (y == 9 && x == 8)
				{
					std::cout << "3.  ���������";
					width = width - 13;
				}
				if (y == 11 && x == 6)
				{
					std::cout << "4.  ����� �� ����";
					width = width - 17;
				}
			}

			if (!language)
			{
				if (y == 5 && x == 10)
				{
					std::cout << "1.  Start";
					width = width - 9;
				}
				if (y == 7 && x == 7)
				{
					std::cout << "2.  Leaderboard";
					width = width - 15;
				}
				if (y == 9 && x == 9)
				{
					std::cout << "3.  Settings";
					width = width - 12;
				}
				if (y == 11 && x == 6)
				{
					std::cout << "4.  Exit the game";
					width = width - 17;
				}
			}

			if (!isDrawScreen)
				std::cout << " ";
		}
		std::cout << std::endl;
		width = 30;
	}

	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;
}

void SettingDraw()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		if (language)
			std::cout << ruScreen[i];
		else
			std::cout << enScreen[i];
		std::cout << std::endl;
	}

	for (int y = 0; y < height - 6; ++y)
	{
		for (int x = 0; x < width; x++)
		{
			isDrawScreen = false;
			if (x == 0 || x == width - 1)
				std::cout << "#";

			if (language)
			{
				if (y == 5 && x == 11)
				{
					std::cout << "1.  ����";
					width = width - 8;
				}
				if (key == 1 && (choice == false) && y == 6 && x == 11)
				{
					std::cout << "English";
					width = width - 7;
					language = false;
				}
				else if (key == 1 && (choice == true) && y == 6 && x == 11)
				{
					std::cout << "�������";
					width = width - 7;
					language = true;
				}
				if (y == 8 && x == 7)
				{
					std::cout << "2.  ����������";
					width = width - 14;
				}
				if (y == 11 && x == 7)
				{
					std::cout << "3.  ������ ����";
					width = width - 15;
				}
			}

			if (!language)
			{
				if (y == 5 && x == 9)
				{
					std::cout << "1.  Language";
					width = width - 12;
				}
				if (key == 1 && (choice == false) && y == 6 && x == 11)
				{
					std::cout << "English";
					width = width - 7;
					language = false;
				}
				else if (key == 1 && (choice == true) && y == 6 && x == 11)
				{
					std::cout << "�������";
					width = width - 7;
					language = true;
				}
				if (y == 8 && x == 9)
				{
					std::cout << "2.  Control";
					width = width - 11;
				}
				if (y == 11 && x == 8)
				{
					std::cout << "3.  Game size";
					width = width - 13;
				}
			}

			if (!isDrawScreen)
				std::cout << " ";
		}
		std::cout << std::endl;
		width = 30;
	}

	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;
}

void MenuSelector()
{
	if (_kbhit())
	{
		switch (_getche())
		{
		case '1':
			gameStart = true;
			break;
		case '2':

			break;
		case '3':
			settingExit = true;
			break;
		case '4':
			menuOver = true;
			break;
		}

	}
}

void SettingsSelectorPlus()
{
	if (_kbhit())
	{
		switch (_getche())
		{
		case 'w':
			choice = false;
			break;
		case 's':
			choice = true;
			break;
		}
	}
}
//������, ��� ������� � �����, ���� ����� ����������. ���� ����� ������, �� �������� �������� ����� � ����. � ��� ����� �� �������
void SettingsSelector()
{
	if (_kbhit())
	{
		switch (_getche())
		{
		case '1':
			key = 1;
			break;
		case '2':
			key = 2;
			break;
		case '3':
			key = 3;
			break;
		case '4':
			settingExit = false;
			break;
		}
	}
}

//������ ���� �
//void Leaderboard()
//{
//	system("cls");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	std::string path = "Winners.txt";
//	std::ifstream fin;
//	fin.open(path);
//	for (int i = 0; i < 5; i++)
//	{
//		fin >> winners[i].name;
//	}
//	for (int i = 0; i <= width; i++)
//		std::cout << "#";
//	std::cout << std::endl;
//
//	for (int i = 0; i < 6; i++)
//	{
//		if (language)
//			std::cout << ruScreen[i];
//		else
//			std::cout << enScreen[i];
//		std::cout << std::endl;
//	}
//
//	for (int y = 0; y < height - 6; y++)
//	{
//		for (int x = 0; x < width; x++)
//		{
//			isDrawScreen = false;
//			if (x == 0 || x == width - 1)
//				std::cout << "#";
//
//			for (int p = 0; p < height - 6; p++)
//			{
//				if (y == 5 && x == 2)
//				{
//					std::cout << winners->name;
//				}
//				if (y == 7 && x == 2)
//				{
//					std::cout << winners->name;
//				}
//			}
//			if (!isDrawScreen)
//				std::cout << " ";
//		}
//		std::cout << std::endl;
//		width = 30;
//	}
//
//	for (int i = 0; i <= width; i++)
//		std::cout << "#";
//	std::cout << std::endl;
//}

void theEnd()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		if (language)
			std::cout << ruScreen[i];
		else
			std::cout << enScreen[i];
		std::cout << std::endl;
	}

	for (int y = 0; y < height - 6; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == 0 || x == width - 1)
				std::cout << "#";
			{
				
				if (y == 6 && x == 11)
				{
					std::cout << "����� ����";
					width = width - 10;
				}
			}
			if (!isDrawScreen)
				std::cout << " ";
		}
		std::cout << std::endl;
		width = 30;
	}

	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;
}
//gameplay

void Setup()
{
	gameOver = false;
	coord.x = width / 2;
	coord.y = height / 2;
	burgerX = rand() % width;
	burgerY = rand() % height;
	score = 0;

	//!����� ���� (���������� ���� ��������� '-1', ����� ����� �� ��� ����� �������
	for (int i = 0; i < snakeLength; i++)
	{
		snake[i].x = -1;
		snake[i].y = -1;
	}
}

void Drawing()
{
	system("cls");

	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			isDraw = false;
			if (x == 0 || x == width - 1)
				std::cout << "#";
			if (y == coord.y && x == coord.x - 1)
			{
				std::cout << "O";
				isDraw = true;
			}
			else if (y == burgerY && x == burgerX - 1)
			{
				std::cout << "B";
				isDraw = true;
			}
			else
			{
				for (int s = 0; s < snakeLength; s++)
				{
					if (snake[s + 1].x == -1)
						break;
					if (snake[s].x == x + 1 && snake[s].y == y)
					{
						isDraw = true;
						std::cout << "o";
					}
				}
			}
			if (!isDraw)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i <= width; i++)
		std::cout << "#";
	std::cout << std::endl;

	std::cout << "����: " << score << " �����";
}

void HeadRotator()
{
	//���������� � ������� WASD
	if (_kbhit()) //���������� ��������� ��������, ���� ���� ������ �������
	{
		switch (_getch()) //��� ��������� ������� �������
		{
		case 'a':
			if (rotate != RIGHT)
				rotate = LEFT;
			break;
		case 'd':
			if (rotate != LEFT)
				rotate = RIGHT;
			break;
		case 'w':
			if (rotate != DOWN)
				rotate = UP;
			break;
		case 's':
			if (rotate != UP)
				rotate = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

	/*���������� � ������� ���������
	if (_kbhit()) //���������� ��������� ��������, ���� ���� ������ �������
	{
		switch (_getch()) //��� ��������� ������� �������
		{
		case 75:
			if (rotate != RIGHT)
				rotate = LEFT;
			break;
		case 77:
			if (rotate != LEFT)
				rotate = RIGHT;
			break;
		case 72:
			if (rotate != DOWN)
				rotate = UP;
			break;
		case 80:
			if (rotate != UP)
				rotate = DOWN;
			break;
		}
	}*/
}

void Logic()
{

	/*if (coord.x == width - 1)
		coord.x = 0;
	else if (coord.x < 0)
		coord.x = width - 1;

	if (coord.y >= height)
		coord.y = 1;
	else if (coord.y < 0)
		coord.y = height - 1;*/


	if (coord.x == burgerX && coord.y == burgerY) //���������� �������������� ������, ����� ��� "������"
	{
		
		score += 10; // ��������� ����� ����� ������" ������

		//!����� ���� (������ ���������)
		
		burgerX = rand() % (width - 2) + 1;
		burgerY = rand() % (height - 2) + 1;

		//�� ��������
		/*if (coord.x == burgerX && coord.y == burgerY || snake->x == burgerX && snake->y == burgerY)
		{
			burgerX = rand() % (width - 2) + 1;
			burgerY = rand() % (height - 2) + 1;
		}*/
	}

	if (score > 0)
	{
		

		for (int i = score / 10; i > 0; i--)
		{
			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;
		}
		snake[0].x = coord.x;
		snake[0].y = coord.y;
	}

	switch (rotate)
	{
	case LEFT:
		coord.x--;
		break;
	case RIGHT:
		coord.x++;
		break;
	case UP:
		coord.y--;
		break;
	case DOWN:
		coord.y++;
		break;
	}

	for (int i = 1; i < score / 10; i++)
	{
		if (coord.x == snake[i].x && coord.y == snake[i].y)
		{
			gameOver = true;
		}
	}
	if(coord.x == width)
		coord.x = 0;
	else if (coord.x < 1)
		coord.x = width - 1;

	if (coord.y >= height)
		coord.y = 0;
	else if (coord.y < 0)
		coord.y = height - 1;
	/*if (coord.x > width - 1 || coord.x < 3 || coord.y > height - 2 || coord.y < 1)
		gameOver = true;*/

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	while (!menuOver)
	{
		Sleep(400);
		if (!settingExit && !gameStart)
		{
			MenuSelector();
			MenuDraw();
		}
		else if (settingExit)
		{
			SettingsSelector();
			SettingsSelectorPlus();
			SettingDraw();
		}
		else if (gameStart)
		{
			if (!gameOver)
			{
				Setup();
				while (!gameOver)
				{
					Sleep(50);
					HeadRotator(); //��������� �� ����� �������
					Logic(); //������� ������
					Drawing(); //���������
				}
			}
			else
			{
				theEnd();

			}
		}
	}
}