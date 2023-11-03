#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cmath>
#include<random>
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y);
bool timer(long long ms, int id);
void hideCursor();
void SetColor(int fore = 7, int back = 0);
void full_screen();
void clearKeyCache();



