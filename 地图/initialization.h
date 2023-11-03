#pragma once

#include<iostream>
#include<string>
#include"Item.h"
using namespace std;

void initMapStart(startHole StartHole[], person* p, Door* door); 
void initMap01(string map01[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed);
void initMap02(string map02[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed);
void initMap03(string map03[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed);
void initMap04(string map04[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed);
void initMap05(string map05[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed);
void initMapEndless(string mapEndless[][65], Hole hole[], person & p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], int emenyButtetSpeed);
void initmultiplayer(string mapMultiplayer[][65], person& p, person& p2, Box box[], Thorn thorn[]);
void initEmeny(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], int emenyButtetSpeed);
void initEnhancedEmeny(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], int emenyButtetSpeed);
void initMapShop(person* p, Door* door, Buy buy[]);




















