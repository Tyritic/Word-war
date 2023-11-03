#pragma once

#include<iostream>
#include<string>
#include"resource.h"
#include"Item.h"
#include"func.h"
#include"Map.h"
#include"Music.h"

using namespace std;

void moveEmeny(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], person& p);
void emenyShoot(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], person& p, emenyButtet emenybuttet[], int emenyButtetSpeed);
void isHitPerson(person& p, emenyButtet emenybuttet[]);
void isHitPersonByTrap(Fire fire[], Thorn thorn[], person& p);

void isHitEmenyByButtet(person& p, Buttet buttet[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65]);
void isHitEmenyByWave(person& p, Wave wave[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65]);
void isHitEmenyByLaser(person& p, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65]);
void isHitEmenyByFullMapDamage(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65]);
void isKillEmeny(person& p, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65], Medicine medicine[]);
void isChangeWeapon(person& p);
void isPlayer01ChangeWeapon(person& p);
void isPlayer02ChangeWeapon(person& p);
void updatePersonDamage(person& p);
void levelReward(person& p);
void isLevelup(person& p);
void isPickMedicine(person& p, Medicine medicine[], string map[][65]);
void isDie(person& p, int& level, string map[][65], startHole StartHole[], Door* door, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[], string mapStart[][65],PassHole &passhole);
void isDieInEndlessMode(person& p, int& level, string map[][65], startHole StartHole[], Door* door, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[], string mapStart[][65]);
void isPlayerDie(person& p, person& p2, int& level, string mapFight[][65], startHole StartHole[], Door* door, Wave wave[], Wave02 wave02[], Buttet buttet[], Buttet02 buttet02[], string mapStart[][65]);
void isPass(person& p, int& level, PassHole& passHole, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[]);
void isKillHuang(person& p, int& level, PassHole& passHole, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[]);
void isHitByWave(string map[][65], person& p, person& p2, Wave wave[], Wave02 wave02[]);
void isHitByButtet(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[]);
void isHitByTrap(person& p, person& p2, Fire fire[], Thorn thorn[]);
void isChooseDifficultMode(bool difficult);

bool isInPassHole(person& p, int& level, PassHole& passHole, string mapFight[][65], Hole hole[], Box box[], Fire fire[], Thorn thorn[], Buttet buttet[], Laser laser[], Wave wave[]);
int isInStartHole(person& p, startHole startHole[]);
bool isInShop(person* p, Door* door);
bool isOutShop(person* p, Door* door);

void isBuy(person& p, Buy buy[], int& level, Door door[], string mapShop[][65]);
void moveFullMapDamage(string map[][65], bool& flag, Bin b[], Zu z[], Di d[], Wang w[], Huang h[]);
//过场加载动画
void playAnimation();
//标题加载动画
void playTitleAnimation();
void playChallengeMode(string map[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Medicine medicine[], Battery& battery, Buttet buttet[], emenyButtet emenybuttet[], Wave wave[], Laser laser[], PassHole& passHole, int& level, startHole StartHole[], Door door[], Buy buy[],bool &isPutOnShield, bool &isFullMapDamage, string mapDie[][65], string mapStart[][65]);
void playMultiplayerMode(person& p, person& p2, string map[][65], Box box[], Fire fire[], Thorn thorn[], Wave wave[], Wave02 wave02[], Buttet buttet[], Buttet02 buttet02[], int& level, startHole StartHole[], Door door[],string mapMultiplayer[][65],string mapStart[][65]);
void loadGame(person& p, Buy buy[]);
void saveGame(person& p, Buy buy[]);
void PlayHuangDie();
