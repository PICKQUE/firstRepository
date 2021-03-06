// hitnumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
char ch;
int food[40][40] = {0};
int rows = 0,cols = 0;
int leavels=0, stores = 0;
bool gameOver = false;
//声明开始界面
void Start_interface()
{
	for (int i = 0; i < 15; i++)
		cout << endl;
	for (int i = 0; i < 40; i++)
		cout << ' ';
	cout << "input anykey to start the game";
	if (getchar()) {
		system("cls");
		cout  << "leavels: " << leavels << "       " << "stores: " << stores<<endl;
		cout << "_________________________________________________" << endl;
	}
}
//游戏界面
void Draw() {
	cout << "leavels: " << leavels << "       " << "stores: " << stores << endl;
	cout << "_________________________________________________" << endl;
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			if (food[i][j] == 0) {
				cout << " ";
			}
			else if (food[i][j] == 1) {
				cout << ch;
			}
		}
		cout << endl;
	}
}
void Setup() {
	srand(time(NULL));
	ch = rand() % 26 + 97;
//	rows = rand() % 40;
	cols = rand() % 40;
	food[rows][cols] = 1;
}
void Logic() {
	int temp = rows;
	food[temp][cols] = 0;
	rows++;
	food[rows][cols] = 1;
	if (_kbhit()) {
		char temp_char = _getch();
		if (temp_char == ch) {
			food[rows][cols] = 0;
			ch = rand() % 26 + 97;
			cols = rand() % 40;
			rows = 0;
		}
	}
	if (rows < 0 || rows>40) {
		gameOver = true;
	}
}

int main()
{
	Start_interface();
	Setup();
	system("cls");
	while (1) {
		Logic();
		Draw();
		system("cls");
		if (gameOver) {
			cout << "         "<<"you lose!" << endl<<"          "<<"Game Over";
			return 0;
		}
		Sleep(300);
	}
	return 0;
}