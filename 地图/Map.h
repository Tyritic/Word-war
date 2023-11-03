#pragma once
#include<iostream>
#include<string>
#include"Item.h"
#include"func.h"
#include<iomanip>
using namespace std;

void printMap(string map[][65]);
void printMapFast(string map[][65]);
void printMapFight(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Buttet buttet[], emenyButtet emenybuttet[]);
void printMapFightFast(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Buttet buttet[], emenyButtet emenybuttet[]);
void printMapMultiplayer(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[]);
void printMapMultiplayerFast(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[]);
void Printstate(person A, int level);
void PrintHp(const person& p);
void printWin();
void printHuangHp(const Huang h[]);
void printStateEndless(person& p, int level);
void printStatemultiplayer(person A, person B, int level);
void printIntroduction();

void refreshMapFight(string map[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Medicine medicine[], Battery battery, Buttet buttet[], emenyButtet emenybuttet[], Wave wave[], Laser laser[], PassHole& passHole);
void refeshMapMultiplayer(string map[][65], person& p, person& p2, Box box[], Fire fire[], Thorn thorn[], Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[]);
void refeshMapShop(string mapShop[][65], person* p, Door* door, Buy buy[]);
void refeshMap(string mapStart[][65], startHole StartHole[], person* p, Door* door);













