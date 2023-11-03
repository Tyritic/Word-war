#include"Music.h"
void PlayStartBGM()
{
	mciSendString(TEXT("open ./Start.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./Start.mp3 repeat"), 0, 0, 0);
}
void StopStartBGM()
{
	mciSendString(TEXT("stop ./Start.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./Start.mp3"), 0, 0, 0);
}
void PlayTownAndShopBGM()
{
	mciSendString(TEXT("open ./TownAndShop.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./TownAndShop.mp3 repeat"), 0, 0, 0);
}
void StopTownAndShopBGM()
{
	mciSendString(TEXT("stop ./TownAndShop.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./TownAndShop.mp3"), 0, 0, 0);
}
void PlayStageModeBGM()
{
	mciSendString(TEXT("open ./StageGame.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./StageGame.mp3 repeat"), 0, 0, 0);
}
void StopStageModeBGM()
{
	mciSendString(TEXT("stop ./StageGame.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./StageGame.mp3"), 0, 0, 0);
}
void PlayStageModeBossBGM()
{
	mciSendString(TEXT("open ./StageGameBoss.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./StageGameBoss.mp3 repeat"), 0, 0, 0);
}
void StopStageModeBossBGM()
{
	mciSendString(TEXT("stop ./StageGameBoss.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./StageGameBoss.mp3"), 0, 0, 0);
}
void PlayEndlessGameBGM()
{
	mciSendString(TEXT("open ./EndlessGame.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./EndlessGame.mp3 repeat"), 0, 0, 0);
}
void StopEndlessGameBGM()
{
	mciSendString(TEXT("stop ./EndlessGame.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./EndlessGame.mp3"), 0, 0, 0);
}
void PlayMultiplayersBGM()
{
	mciSendString(TEXT("open ./Mutiplayers.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./Mutiplayers.mp3 repeat"), 0, 0, 0);
}
void StopMultiplayersBGM()
{
	mciSendString(TEXT("stop ./Mutiplayers.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./Mutiplayers.mp3"), 0, 0, 0);
}
void PlayWinBGM()
{
	mciSendString(TEXT("open ./Win.mp3"), 0, 0, 0);
	mciSendString(TEXT("play ./Win.mp3"), 0, 0, 0);
}
void StopWinBGM()
{
	mciSendString(TEXT("stop ./Win.mp3"), 0, 0, 0);
	mciSendString(TEXT("close ./Win.mp3"), 0, 0, 0);
}

