#pragma once
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")
void PlayStartBGM();
void StopStartBGM();
void PlayTownAndShopBGM();
void StopTownAndShopBGM();
void PlayStageModeBGM();
void StopStageModeBGM();
void PlayStageModeBossBGM();
void StopStageModeBossBGM();
void PlayEndlessGameBGM();
void StopEndlessGameBGM();
void PlayMultiplayersBGM();
void StopMultiplayersBGM();
void PlayWinBGM();
void StopWinBGM();