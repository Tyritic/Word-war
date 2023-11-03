
#include"Game.h"
#include"initialization.h"
using namespace std;

void moveEmeny(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], person& p)
{
    for (int i = 0; i < Bin::num; i++) { if (b[i].alive == 1) { if (timer(b[i].speed, 6 + i))b[i].move(map); } }//敌人移动
    for (int i = 0; i < Zu::num; i++) { if (z[i].alive == 1) { if (timer(z[i].speed, 56 + i)) z[i].move(map); } }
    for (int i = 0; i < Di::num; i++) { if (d[i].alive == 1) { if (timer(d[i].speed, 107 + i))d[i].move(map, p); } }
    for (int i = 0; i < Wang::num; i++) { if (w[i].alive == 1) { if (timer(w[i].speed, 158 + i))w[i].move(map, p); } }
    for (int i = 0; i < Huang::num; i++) { if (h[i].alive == 1) { if (timer(h[i].speed, 209 + i))h[i].move(map, p); } }
}
void emenyShoot(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], person& p, emenyButtet emenybuttet[],int emenyButtetSpeed)  //内置了计时器
{
    for (int i = 0; i < Bin::num; i++) { if (b[i].alive == 1) { if (timer(b[i].shootSpeed, 320 + i)) b[i].shoot(p, emenybuttet, emenyButtetSpeed); } }
    for (int i = 0; i < Zu::num; i++) { if (z[i].alive == 1) { if (timer(z[i].shootSpeed, 370 + i)) z[i].shoot(p, emenybuttet, emenyButtetSpeed); } }
    for (int i = 0; i < Di::num; i++) { if (d[i].alive == 1) { if (timer(d[i].shootSpeed, 420 + i)) d[i].shoot(p, emenybuttet, emenyButtetSpeed); } }
    for (int i = 0; i < Wang::num; i++) { if (w[i].alive == 1) { if (timer(w[i].shootSpeed, 470 + i)) w[i].shoot(p, emenybuttet, emenyButtetSpeed); } }
    for (int i = 0; i < Huang::num; i++) { if (h[i].alive == 1) { if (timer(h[i].shootSpeed, 490 + i)) h[i].shoot(p, emenybuttet, emenyButtetSpeed); } }
}
void isHitPerson(person& p, emenyButtet emenybuttet[])
{
    for (int i = 0; i < emenyButtet::num; ++i)
    {
        if (emenybuttet[i].alive == 1 && p.hang == emenybuttet[i].hang && p.lie == emenybuttet[i].lie && emenybuttet[i].alive == 1 && timer(1000, 561))
        {
            PlaySound(TEXT("受伤.wav"), NULL, SND_FILENAME | SND_ASYNC);
            p.Hp -= emenybuttet[i].damage; emenybuttet[i].alive = 0;
            SetColor(4); gotoxy(132, 16); cout << "Hp-" << emenybuttet[i].damage; timer(10, 876); SetColor();         //受伤提示
        }
    }
    if (timer(600, 876)) { gotoxy(132, 16); cout << "           "; }
}
void isHitPersonByTrap(Fire fire[], Thorn thorn[], person& p)
{
    for (int i = 0; i < Fire::num; ++i)
    {                                                                                                                                   //受伤提示
        if (fire[i].hang == p.hang && fire[i].lie == p.lie && timer(1000, 588)) {
            PlaySound(TEXT("受伤.wav"), NULL, SND_FILENAME | SND_ASYNC);
        --p.Hp; SetColor(4); gotoxy(132, 16); cout << "Hp-1"; timer(10, 876); SetColor(); }
    }
    for (int i = 0; i < Thorn::num; ++i)
    {                                                                                                                                   //受伤提示
        if (thorn[i].hang == p.hang && thorn[i].lie == p.lie && timer(1000, 589)) {
            PlaySound(TEXT("受伤.wav"), NULL, SND_FILENAME | SND_ASYNC);
        --p.Hp; SetColor(4); gotoxy(132, 16); cout << "Hp-1"; timer(10, 876); SetColor(); }
    }
    if (timer(600, 876)) { gotoxy(132, 16); cout << "           "; }
}

void isHitEmenyByButtet(person& p, Buttet buttet[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65])
{
    for (int i = 0; i < Buttet::num; ++i)
    {
        for (int j = 0; j < Bin::num; ++j)
        {
            if ((buttet[i].alive == 1 && b[j].alive == 1) && ((buttet[i].hang == b[j].hang - 1 && buttet[i].lie == b[j].lie) || (buttet[i].hang == b[j].hang + 1 && buttet[i].lie == b[j].lie) || (buttet[i].hang == b[j].hang && buttet[i].lie == b[j].lie - 1) || (buttet[i].hang == b[j].hang && buttet[i].lie == b[j].lie + 1))) {
                b[j].Hp -= p.damage; buttet[i].alive = 0;  map[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
                if (p.weaponUsing == 2 && rand() % 8 == 1 && p.Hp < p.limit) { p.Hp += 1; }                  //回血
            }
        }
    }
    for (int i = 0; i < Buttet::num; ++i)
    {
        for (int j = 0; j < Zu::num; ++j)
        {
            if ((buttet[i].alive == 1 && z[j].alive == 1) && ((buttet[i].hang == z[j].hang - 1 && buttet[i].lie == z[j].lie) || (buttet[i].hang == z[j].hang + 1 && buttet[i].lie == z[j].lie) || (buttet[i].hang == z[j].hang && buttet[i].lie == z[j].lie - 1) || (buttet[i].hang == z[j].hang && buttet[i].lie == z[j].lie + 1)))
            {
                z[j].Hp -= p.damage; buttet[i].alive = 0; map[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
                if (p.weaponUsing == 2 && rand() % 8 == 1 && p.Hp < p.limit) { p.Hp += 1; }                 //回血
            }
        }
    }
    for (int i = 0; i < Buttet::num; ++i)
    {
        for (int j = 0; j < Di::num; ++j)
        {
            if ((buttet[i].alive == 1 && d[j].alive == 1) && ((buttet[i].hang == d[j].hang - 1 && buttet[i].lie == d[j].lie) || (buttet[i].hang == d[j].hang + 1 && buttet[i].lie == d[j].lie) || (buttet[i].hang == d[j].hang && buttet[i].lie == d[j].lie - 1) || (buttet[i].hang == d[j].hang && buttet[i].lie == d[j].lie + 1)))
            {
                d[j].Hp -= p.damage; buttet[i].alive = 0; map[buttet[i].hang][buttet[i].lie] = "一";  gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
                if (p.weaponUsing == 2 && rand() % 8 == 1 && p.Hp < p.limit) { p.Hp += 1; }                 //回血
            }
        }
    }
    for (int i = 0; i < Buttet::num; ++i)
    {
        for (int j = 0; j < Wang::num; ++j)
        {
            if ((buttet[i].alive == 1 && w[j].alive == 1) && ((buttet[i].hang == w[j].hang - 1 && buttet[i].lie == w[j].lie) || (buttet[i].hang == w[j].hang + 1 && buttet[i].lie == w[j].lie) || (buttet[i].hang == w[j].hang && buttet[i].lie == w[j].lie - 1) || (buttet[i].hang == w[j].hang && buttet[i].lie == w[j].lie + 1)))
            {
                w[j].Hp -= p.damage; buttet[i].alive = 0;  map[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
                if (p.weaponUsing == 2 && rand() % 8 == 1 && p.Hp < p.limit) { p.Hp += 1; }                 //回血
            }
        }
    }
    for (int i = 0; i < Buttet::num; ++i)
    {
        for (int j = 0; j < Bin::num; ++j)
        {
            if ((buttet[i].alive == 1 && h[j].alive == 1) && ((buttet[i].hang == h[j].hang - 1 && buttet[i].lie == h[j].lie) || (buttet[i].hang == h[j].hang + 1 && buttet[i].lie == h[j].lie) || (buttet[i].hang == h[j].hang && buttet[i].lie == h[j].lie - 1) || (buttet[i].hang == h[j].hang && buttet[i].lie == h[j].lie + 1)))
            {
                h[j].Hp -= p.damage; buttet[i].alive = 0; map[buttet[i].hang][buttet[i].lie] = "一";  gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
                if (p.weaponUsing == 2 && rand() % 8 == 1) { p.Hp += 1; }                  //回血
            }
        }
    }
}
void isHitEmenyByWave(person& p, Wave wave[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65])
{
    for (int i = 0; i < Wave::num; ++i)
    {
        for (int j = 0; j < Bin::num; ++j)
        {
            if ((wave[i].alive == 1 && b[j].alive == 1) && ((wave[i].hang == b[j].hang - 1 && wave[i].lie == b[j].lie) || (wave[i].hang == b[j].hang + 1 && wave[i].lie == b[j].lie) || (wave[i].hang == b[j].hang && wave[i].lie == b[j].lie - 1) || (wave[i].hang == b[j].hang && wave[i].lie == b[j].lie + 1) || (wave[i].hang == b[j].hang && wave[i].lie == b[j].lie + 2) || (wave[i].hang == b[j].hang && wave[i].lie == b[j].lie - 2) || (wave[i].hang == b[j].hang + 2 && wave[i].lie == b[j].lie) || (wave[i].hang == b[j].hang - 2 && wave[i].lie == b[j].lie))) {
                b[j].Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
                if (wave[i].dir == 1) {
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 2) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                }
                else if (wave[i].dir == 3) {
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 4) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        for (int j = 0; j < Zu::num; ++j)
        {
            if ((wave[i].alive == 1 && z[j].alive == 1) && ((wave[i].hang == z[j].hang - 1 && wave[i].lie == z[j].lie) || (wave[i].hang == z[j].hang + 1 && wave[i].lie == z[j].lie) || (wave[i].hang == z[j].hang && wave[i].lie == z[j].lie - 1) || (wave[i].hang == z[j].hang && wave[i].lie == z[j].lie + 1) || (wave[i].hang == z[j].hang && wave[i].lie == z[j].lie + 2) || (wave[i].hang == z[j].hang && wave[i].lie == z[j].lie - 2) || (wave[i].hang == z[j].hang + 2 && wave[i].lie == z[j].lie) || (wave[i].hang == z[j].hang - 2 && wave[i].lie == z[j].lie))) {
                z[j].Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
                if (wave[i].dir == 1) {
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 2) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                }
                else if (wave[i].dir == 3) {
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 4) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        for (int j = 0; j < Wang::num; ++j)
        {
            if ((wave[i].alive == 1 && w[j].alive == 1) && ((wave[i].hang == w[j].hang - 1 && wave[i].lie == w[j].lie) || (wave[i].hang == w[j].hang + 1 && wave[i].lie == w[j].lie) || (wave[i].hang == w[j].hang && wave[i].lie == w[j].lie - 1) || (wave[i].hang == w[j].hang && wave[i].lie == w[j].lie + 1) || (wave[i].hang == w[j].hang && wave[i].lie == w[j].lie + 2) || (wave[i].hang == w[j].hang && wave[i].lie == w[j].lie - 2) || (wave[i].hang == w[j].hang + 2 && wave[i].lie == w[j].lie) || (wave[i].hang == w[j].hang - 2 && wave[i].lie == w[j].lie))) {
                w[j].Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
                if (wave[i].dir == 1) {
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 2) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                }
                else if (wave[i].dir == 3) {
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 4) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        for (int j = 0; j < Di::num; ++j)
        {
            if ((wave[i].alive == 1 && d[j].alive == 1) && ((wave[i].hang == d[j].hang - 1 && wave[i].lie == d[j].lie) || (wave[i].hang == d[j].hang + 1 && wave[i].lie == d[j].lie) || (wave[i].hang == d[j].hang && wave[i].lie == d[j].lie - 1) || (wave[i].hang == d[j].hang && wave[i].lie == d[j].lie + 1) || (wave[i].hang == d[j].hang && wave[i].lie == d[j].lie + 2) || (wave[i].hang == d[j].hang && wave[i].lie == d[j].lie - 2) || (wave[i].hang == d[j].hang + 2 && wave[i].lie == d[j].lie) || (wave[i].hang == d[j].hang - 2 && wave[i].lie == d[j].lie))) {
                d[j].Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
                if (wave[i].dir == 1) {
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 2) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                }
                else if (wave[i].dir == 3) {
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 4) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        for (int j = 0; j < Huang::num; ++j)
        {
            if ((wave[i].alive == 1 && h[j].alive == 1) && ((wave[i].hang == h[j].hang - 1 && wave[i].lie == h[j].lie) || (wave[i].hang == h[j].hang + 1 && wave[i].lie == h[j].lie) || (wave[i].hang == h[j].hang && wave[i].lie == h[j].lie - 1) || (wave[i].hang == h[j].hang && wave[i].lie == h[j].lie + 1) || (wave[i].hang == h[j].hang && wave[i].lie == h[j].lie + 2) || (wave[i].hang == h[j].hang && wave[i].lie == h[j].lie - 2) || (wave[i].hang == h[j].hang + 2 && wave[i].lie == h[j].lie) || (wave[i].hang == h[j].hang - 2 && wave[i].lie == h[j].lie))) {
                h[j].Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
                if (wave[i].dir == 1) {
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 2) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                }
                else if (wave[i].dir == 3) {
                    if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
                else  if (wave[i].dir == 4) {
                    if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                    }
                    if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                        map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                    }
                }
            }
        }
    }

}
void isHitEmenyByLaser(person& p, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65])
{
    for (int i = 0; i < Bin::num; ++i)
    {
        if (b[i].alive == 1) {
            if ((map[b[i].hang - 1][b[i].lie] == "光" || map[b[i].hang + 1][b[i].lie] == "光" || map[b[i].hang][b[i].lie - 1] == "光" || map[b[i].hang][b[i].lie + 1] == "光") && timer(500, 583))
            {
                b[i].Hp -= p.damage;
            }
        }
    }
    for (int i = 0; i < Zu::num; ++i)
    {
        if (z[i].alive == 1) {
            if ((map[z[i].hang - 1][z[i].lie] == "光" || map[z[i].hang + 1][z[i].lie] == "光" || map[z[i].hang][z[i].lie - 1] == "光" || map[z[i].hang][z[i].lie + 1] == "光") && timer(500, 584))
            {
                z[i].Hp -= p.damage;
            }
        }
    }
    for (int i = 0; i < Di::num; ++i)
    {
        if (d[i].alive == 1) {
            if ((map[d[i].hang - 1][d[i].lie] == "光" || map[d[i].hang + 1][d[i].lie] == "光" || map[d[i].hang][d[i].lie - 1] == "光" || map[d[i].hang][d[i].lie + 1] == "光") && timer(500, 585))
            {
                d[i].Hp -= p.damage;
            }
        }
    }
    for (int i = 0; i < Wang::num; ++i)
    {
        if (w[i].alive == 1) {
            if ((map[w[i].hang - 1][w[i].lie] == "光" || map[w[i].hang + 1][w[i].lie] == "光" || map[w[i].hang][w[i].lie - 1] == "光" || map[w[i].hang][w[i].lie + 1] == "光") && timer(500, 586))
            {
                w[i].Hp -= p.damage;
            }
        }
    }
    for (int i = 0; i < Huang::num; ++i)
    {
        if (h[i].alive == 1) {
            if ((map[h[i].hang - 1][h[i].lie] == "光" || map[h[i].hang + 1][h[i].lie] == "光" || map[h[i].hang][h[i].lie - 1] == "光" || map[h[i].hang][h[i].lie + 1] == "光") && timer(500, 587))
            {
                h[i].Hp -= p.damage;
            }
        }
    }
}
void isHitEmenyByFullMapDamage(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65])
{
    
    for (int i = 0; i < Bin::num; i++) { if (b[i].alive == 1) { if (map[b[i].hang][b[i].lie] == "波" && timer(500, 600 + i)) { b[i].Hp -= 1; } } }
    for (int i = 0; i < Zu::num; i++) {
        if (z[i].alive == 1) {
            if (map[z[i].hang][z[i].lie] == "波" && timer(500, 650 + i)) { z[i].Hp -= 1; }
        }
    }
    for (int i = 0; i < Di::num; i++) {
        if (d[i].alive == 1) {
            if (map[d[i].hang][d[i].lie] == "波" && timer(500, 700 + i)) { d[i].Hp -= 1; }
        }
    }
    for (int i = 0; i < Wang::num; i++) {
        if (w[i].alive == 1) {
            if (map[w[i].hang][w[i].lie] == "波" && timer(500, 750 + i)) { w[i].Hp -= 1; }
        }
    }
    for (int i = 0; i < Huang::num; i++) {
        if (h[i].alive == 1) {
            if (map[h[i].hang][h[i].lie] == "波" && timer(500, 770 + i)) { h[i].Hp -= 1; }
        }
    }
}
void isKillEmeny(person& p, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], string map[][65], Medicine medicine[])
{
    for (int i = 0; i < Bin::num; ++i)
    {
        if (b[i].alive == 1)if (b[i].Hp <= 0) {
            b[i].alive = 0; map[b[i].hang][b[i].lie] = "一"; gotoxy(b[i].lie * 2, b[i].hang + 4); printf("  ");
            ++p.kill; ++p.score; p.money += 3; p.Exp += 1;
            if (rand() % 10 == 0) {
                for (int j = 0; j < Medicine::num; ++j) {
                    if (medicine[j].alive == 0) { medicine[j].alive = 1; medicine[j].hang = b[i].hang; medicine[j].lie = b[i].lie; break; }
                }
            }
        }
    }
    for (int i = 0; i < Zu::num; ++i)
    {
        if (z[i].alive == 1) if (z[i].Hp <= 0) {
            z[i].alive = 0; map[z[i].hang][z[i].lie] = "一"; gotoxy(z[i].lie * 2, z[i].hang + 4); printf("  "); ++p.kill; p.score += 2; p.money += 4; p.Exp += 2;
            if (rand() % 10 == 1) {
                for (int j = 0; j < Medicine::num; ++j) {
                    if (medicine[j].alive == 0) { medicine[j].alive = 1; medicine[j].hang = z[i].hang; medicine[j].lie = z[i].lie; break; }
                }
            }
        }
    }
    for (int i = 0; i < Di::num; ++i)
    {
        if (d[i].alive == 1) if (d[i].Hp <= 0) {
            d[i].alive = 0; map[d[i].hang][d[i].lie] = "一"; gotoxy(d[i].lie * 2, d[i].hang + 4); printf("  "); ++p.kill; p.score += 3; p.money += 5; p.Exp += 3;
            if (rand() % 10 == 1) {
                for (int j = 0; j < Medicine::num; ++j) {
                    if (medicine[j].alive == 0) { medicine[j].alive = 1; medicine[j].hang = d[i].hang; medicine[j].lie = d[i].lie; break; }
                }
            }
        }
    }
    for (int i = 0; i < Wang::num; ++i)
    {
        if (w[i].alive == 1) if (w[i].Hp <= 0) {
            w[i].alive = 0; map[w[i].hang][w[i].lie] = "一"; gotoxy(w[i].lie * 2, w[i].hang + 4); printf("  "); ++p.kill; p.score += 6; p.money += 10; p.Exp += 6;
            if (rand() % 5 == 1) {
                for (int j = 0; j < Medicine::num; ++j) {
                    if (medicine[j].alive == 0) { medicine[j].alive = 1; medicine[j].hang = w[i].hang; medicine[j].lie = w[i].lie; break; }
                }
            }
        }
    }
    for (int i = 0; i < Huang::num; ++i)
    {
        if (h[i].alive == 1)if (h[i].Hp <= 0) {
            h[i].alive = 0; map[h[i].hang][h[i].lie] = "一"; gotoxy(h[i].lie * 2, h[i].hang + 4); printf("  "); ++p.kill; p.score += 20; p.money += 30; p.Exp += 20;
            if (rand() % 5 == 1) {
                for (int j = 0; j < Medicine::num; ++j) {
                    if (medicine[j].alive == 0) { medicine[j].alive = 1; medicine[j].hang = h[i].hang; medicine[j].lie = h[i].lie; break; }
                }
            }
        }
    }
}
void isChangeWeapon(person& p)
{
    if (GetAsyncKeyState('R') && timer(500, 591))
    {
        if (p.weaponId == 1)
        {
            p.weaponId = 2; p.weaponUsing = p.weapon02;
        }
        else  if (p.weaponId == 2)
        {
            p.weaponId = 1; p.weaponUsing = p.weapon01;
        }
    }
}
void isPlayer01ChangeWeapon(person& p)
{
    if (GetAsyncKeyState('E') && timer(500, 788))
    {
        if (p.weaponId == 1)
        {
            p.weaponId = 2; p.weaponUsing = p.weapon02;
        }
        else  if (p.weaponId == 2)
        {
            p.weaponId = 1; p.weaponUsing = p.weapon01;
        }
    }
}
void isPlayer02ChangeWeapon(person& p)
{
    if (GetAsyncKeyState(VK_NUMPAD6) && timer(500, 788))
    {
        if (p.weaponId == 1)
        {
            p.weaponId = 2; p.weaponUsing = p.weapon02;
        }
        else  if (p.weaponId == 2)
        {
            p.weaponId = 1; p.weaponUsing = p.weapon01;
        }
    }
}
void updatePersonDamage(person& p)
{
    switch (p.weaponUsing)
    {
    case 1: p.damage = 2; p.shootSpeed = 800; break;
    case 2: p.damage = 3;  p.shootSpeed = 1100; break;
    case 3: p.damage = 2; p.shootSpeed = 900; break;
    case 4: p.damage = 2; p.shootSpeed = 1000; break;
    case 5: p.damage = 3;  p.shootSpeed = 1200; break;
    default:p.damage = 0; p.shootSpeed = 900; break;
    }
}
void levelReward(person& p)
{
    switch (p.level)
    {
    case 1:p.limit = 10; break;
    case 2: p.limit = 11; break;
    case 3: p.limit = 13; break;
    case 4: p.limit = 15; break;
    case 5:p.limit = 16; break;
    case 6: p.limit = 17; break;
    case 7: p.limit = 18; break;
    case 8: p.limit = 19; break;
    case 9:  p.limit = 20; break;
    case 10: p.limit = 21; break;
    }
}
void isLevelup(person& p)
{
    if (p.Exp >= 400) { p.level = 10; }
    else if (p.Exp >= 310) { p.level = 9; }
    else if (p.Exp >= 260) { p.level = 8; }
    else if (p.Exp >= 210) { p.level = 7; }
    else if (p.Exp >= 170) { p.level = 6; }
    else if (p.Exp >= 130) { p.level = 5; }
    else if (p.Exp >= 100) { p.level = 4; }
    else if (p.Exp >= 70) { p.level = 3; }
    else if (p.Exp >= 30) { p.level = 2; }
    else if (p.Exp >= 0) { p.level = 1; }
}
void isPickMedicine(person& p, Medicine medicine[], string map[][65])
{
    for (int i = 0; i < Medicine::num; ++i)
    {
        if (medicine[i].alive == 1 && p.hang == medicine[i].hang && medicine[i].lie == p.lie)
        {
            if (p.Hp <= p.limit - 2) { p.Hp += 2; }
            else { p.Hp = p.limit; }
            medicine[i].alive = 0; map[medicine[i].hang][medicine[i].lie] = "一"; gotoxy(medicine[i].lie * 2, medicine[i].hang + 4); printf("  "); break;
        }
    }
}
void isDie(person& p, int& level, string map[][65], startHole StartHole[], Door* door, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[],string mapStart[][65],PassHole &passhole)
{
    if (p.Hp <= 0) {
        saveGame(p, buy);
        level = 0; initMapStart(StartHole, &p, door); p.kill = 0; p.score = 0; p.Hp = p.limit;
        for (int i = 0; i < Bin::num; ++i) {
            b[i].alive = 0; mapFight[b[i].hang][b[i].lie] = "一"; gotoxy(b[i].lie * 2, b[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Zu::num; ++i) {
            z[i].alive = 0; mapFight[z[i].hang][z[i].lie] = "一"; gotoxy(z[i].lie * 2, z[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Di::num; ++i) {
            d[i].alive = 0; mapFight[d[i].hang][d[i].lie] = "一"; gotoxy(d[i].lie * 2, d[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wang::num; ++i) {
            w[i].alive = 0; mapFight[w[i].hang][w[i].lie] = "一"; gotoxy(w[i].lie * 2, w[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Huang::num; ++i) {
            h[i].alive = 0; mapFight[h[i].hang][h[i].lie] = "一"; gotoxy(h[i].lie * 2, h[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Laser::num; ++i) {
            laser[i].alive = 0; mapFight[laser[i].hang][laser[i].lie] = "一"; gotoxy(laser[i].lie * 2, laser[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < emenyButtet::num; ++i) {
            emenybuttet[i].alive = 0; mapFight[emenybuttet[i].hang][emenybuttet[i].lie] = "一"; gotoxy(emenybuttet[i].lie * 2, emenybuttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Medicine::num; ++i) {
            medicine[i].alive = 0; mapFight[medicine[i].hang][medicine[i].lie] = "一"; gotoxy(medicine[i].lie * 2, medicine[i].hang + 4); printf("  ");
        }
        battery.alive = 0; mapFight[battery.hang][battery.lie] = "一"; gotoxy(battery.lie * 2, battery.hang + 4); printf("  ");
        passhole.alive = 0; mapFight[passhole.hang][passhole.lie] = "一"; gotoxy(passhole.lie * 2, passhole.hang + 4); printf("  ");
        for (int i = 1; i < 36; ++i)
        {
            for (int j = 0; j < 65; ++j)
            {
                if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") {
                    mapFight[i][j] = "一"; gotoxy(j * 2, i + 4); printf("  ");
                }
            }
        }
        system("cls"); gotoxy(0, 0); printMap(map);
        while (true)
        {
            if (GetAsyncKeyState('P'))
            {
                StopStageModeBossBGM();
                StopStageModeBGM();
                PlayTownAndShopBGM();
            system("cls"); Printstate(p, level); printf("\n"); initMapStart(StartHole, &p, door); printMap(mapStart); break; }
        }
    }
}
void isDieInEndlessMode(person& p, int& level, string map[][65], startHole StartHole[], Door* door, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[],  string mapStart[][65])
{
    if (p.Hp <= 0) {
        saveGame(p, buy);
        level = 0; initMapStart(StartHole, &p, door); p.kill = 0;
        if (p.score > p.hightest_score) { p.hightest_score = p.score; }
        p.score = 0; p.Hp = p.limit;

        for (int i = 0; i < Bin::num; ++i) {
            b[i].alive = 0; mapFight[b[i].hang][b[i].lie] = "一"; gotoxy(b[i].lie * 2, b[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Zu::num; ++i) {
            z[i].alive = 0; mapFight[z[i].hang][z[i].lie] = "一"; gotoxy(z[i].lie * 2, z[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Di::num; ++i) {
            d[i].alive = 0; mapFight[d[i].hang][d[i].lie] = "一"; gotoxy(d[i].lie * 2, d[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wang::num; ++i) {
            w[i].alive = 0; mapFight[w[i].hang][w[i].lie] = "一"; gotoxy(w[i].lie * 2, w[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Huang::num; ++i) {
            h[i].alive = 0; mapFight[h[i].hang][h[i].lie] = "一"; gotoxy(h[i].lie * 2, h[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Laser::num; ++i) {
            laser[i].alive = 0; mapFight[laser[i].hang][laser[i].lie] = "一"; gotoxy(laser[i].lie * 2, laser[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < emenyButtet::num; ++i) {
            emenybuttet[i].alive = 0; mapFight[emenybuttet[i].hang][emenybuttet[i].lie] = "一"; gotoxy(emenybuttet[i].lie * 2, emenybuttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Medicine::num; ++i) {
            medicine[i].alive = 0; mapFight[medicine[i].hang][medicine[i].lie] = "一"; gotoxy(medicine[i].lie * 2, medicine[i].hang + 4); printf("  ");
        }
        battery.alive = 0; mapFight[battery.hang][battery.lie] = "一"; gotoxy(battery.lie * 2, battery.hang + 4); printf("  ");
        for (int i = 1; i < 36; ++i)
        {
            for (int j = 0; j < 65; ++j)
            {
                if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") {
                    mapFight[i][j] = "一"; gotoxy(j * 2, i + 4); printf("  ");
                }
            }
        }system("cls"); gotoxy(0, 0); printMap(map);
        while (true)
        {
            if (GetAsyncKeyState('P')) 
            {
                StopEndlessGameBGM();
                PlayTownAndShopBGM();
                system("cls"); Printstate(p, level); printf("\n"); initMapStart(StartHole, &p, door); printMap(mapStart); break; }
        }
    }
}
void isPlayerDie(person& p, person& p2, int& level, string mapFight[][65], startHole StartHole[], Door* door, Wave wave[], Wave02 wave02[], Buttet buttet[], Buttet02 buttet02[], string mapStart[][65])
{
    if (p.Hp <= 0)
    {
        level = 0; initMapStart(StartHole, &p, door); p.Hp = p.limit; p.weapon01 = p.weaponTemp01; p.weapon02 = p.weapontemp02; p.weaponUsing = p.weapon01; p.weaponId = 1;
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
            wave02[i].alive = 0; mapFight[wave02[i].hang][wave02[i].lie] = "一"; gotoxy(wave02[i].lie * 2, wave02[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
            buttet02[i].alive = 0; mapFight[buttet02[i].hang][buttet02[i].lie] = "一"; gotoxy(buttet02[i].lie * 2, buttet02[i].hang + 4); printf("  ");
        }
        for (int i = 1; i < 36; ++i)
        {
            for (int j = 0; j < 65; ++j)
            {
                if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") {
                    mapFight[i][j] = "一"; gotoxy(j * 2, i + 4); printf("  ");
                }
            }
        }
        mapFight[p.hang][p.lie] = "一"; gotoxy(p.lie * 2, p.hang + 4); printf("  ");
        mapFight[p2.hang][p2.lie] = "一"; gotoxy(p2.lie * 2, p2.hang + 4); printf("  ");

        system("cls");  gotoxy(0, 18); cout << "                                                玩家2获胜！" << endl << endl;;
        cout << "                                               按P返回村庄" << endl;
        while (true)
        {
            if (GetAsyncKeyState('P'))
            {
                StopMultiplayersBGM();
                PlayTownAndShopBGM();
                system("cls"); Printstate(p, level); printf("\n"); initMapStart(StartHole, &p, door); printMap(mapStart); break; }
        }
    }
    else if (p2.Hp <= 0)
    {
        level = 0; initMapStart(StartHole, &p, door); p.Hp = p.limit; p.weapon01 = p.weaponTemp01; p.weapon02 = p.weapontemp02; p.weaponUsing = p.weapon01; p.weaponId = 1;
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
            wave02[i].alive = 0; mapFight[wave02[i].hang][wave02[i].lie] = "一"; gotoxy(wave02[i].lie * 2, wave02[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
            buttet02[i].alive = 0; mapFight[buttet02[i].hang][buttet02[i].lie] = "一"; gotoxy(buttet02[i].lie * 2, buttet02[i].hang + 4); printf("  ");
        }
        for (int i = 1; i < 36; ++i)
        {
            for (int j = 0; j < 65; ++j)
            {
                if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") {
                    mapFight[i][j] = "一"; gotoxy(j * 2, i + 4); printf("  ");
                }
            }
        }
        mapFight[p.hang][p.lie] = "一"; gotoxy(p.lie * 2, p.hang + 4); printf("  ");
        mapFight[p2.hang][p2.lie] = "一"; gotoxy(p2.lie * 2, p2.hang + 4); printf("  ");

        system("cls");  gotoxy(0, 18); cout << "                                                玩家1获胜！" << endl << endl;;
        cout << "                                               按P返回村庄" << endl;
        while (true)
        {
            if (GetAsyncKeyState('P')) {
                StopMultiplayersBGM();
                PlayTownAndShopBGM(); 
                system("cls"); Printstate(p, level); printf("\n"); initMapStart(StartHole, &p, door); printMap(mapStart); break; }
        }
    }
}
void isPass(person& p, int& level, PassHole& passHole, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[])
{
    if (p.needKill_kill - p.kill <= 0) {
        Hole::num = 0;  saveGame(p, buy);
        for (int i = 0; i < Bin::num; ++i) {
            if (b[i].alive == 1) { b[i].alive = 0; mapFight[b[i].hang][b[i].lie] = "一"; gotoxy(b[i].lie * 2, b[i].hang + 4); printf("  "); }
        }
        for (int i = 0; i < Zu::num; ++i) {
            if (z[i].alive == 1) {
                z[i].alive = 0; mapFight[z[i].hang][z[i].lie] = "一"; gotoxy(z[i].lie * 2, z[i].hang + 4); printf("  ");
            }
        }
        for (int i = 0; i < Di::num; ++i) {
            if (d[i].alive == 1) {
                d[i].alive = 0; mapFight[d[i].hang][d[i].lie] = "一"; gotoxy(d[i].lie * 2, d[i].hang + 4); printf("  ");
            }
        }
        for (int i = 0; i < Wang::num; ++i) {
            if (w[i].alive == 1) {
                w[i].alive = 0; mapFight[w[i].hang][w[i].lie] = "一"; gotoxy(w[i].lie * 2, w[i].hang + 4); printf("  ");
            }
        }
        for (int i = 0; i < Huang::num; ++i) {
            if (h[i].alive == 1) {
                h[i].alive = 0; mapFight[h[i].hang][h[i].lie] = "一"; gotoxy(h[i].lie * 2, h[i].hang + 4); printf("  ");
            }
        }
        /*for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一";
        }
        for (int i = 0; i < Laser::num; ++i) {
            laser[i].alive = 0; mapFight[laser[i].hang][laser[i].lie] = "一";
        }
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一";
        }*/
        for (int i = 0; i < emenyButtet::num; ++i) if(emenybuttet[i].alive ==1) {
            emenybuttet[i].alive = 0; mapFight[emenybuttet[i].hang][emenybuttet[i].lie] = "一"; gotoxy(emenybuttet[i].lie * 2, emenybuttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Medicine::num; ++i) if (medicine[i].alive == 1) {
            medicine[i].alive = 0; mapFight[medicine[i].hang][medicine[i].lie] = "一"; gotoxy(medicine[i].lie * 2, medicine[i].hang + 4); printf("  ");
        }
        if (battery.alive == 1) { battery.alive = 0; mapFight[battery.hang][battery.lie] = "一"; gotoxy(battery.lie * 2, battery.hang + 4); printf("  "); }
        if (timer(800, 783)) {
            for (int i = 1; i < 36; ++i)
            {
                for (int j = 0; j < 65; ++j)
                {
                    if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") {
                        mapFight[i][j] = "一";  gotoxy(j * 2, i + 4); printf("  ");
                    }
                }
            }
        }
        gotoxy(133, 20); printf("通关啦！"); gotoxy(133, 21); printf("走入洞中可进入下一关");

        Bin::num = Zu::num = Di::num = Wang::num = Huang::num = 0;
        passHole.alive = 1;
        if (level == 1) { passHole.hang = 25; passHole.lie = 40; }
        else if (level == 2) { passHole.hang = 25; passHole.lie = 28; }
        else if (level == 3) { passHole.hang = 17; passHole.lie = 30; }
        else if (level == 4) { passHole.hang = 17; passHole.lie = 33; }

    }

}
void isKillHuang(person& p, int& level, PassHole& passHole, Bin b[], Zu z[], Di d[], Wang w[], Huang h[], emenyButtet emenybuttet[], Buttet buttet[], Laser laser[], Wave wave[], Battery& battery, Medicine medicine[], string mapFight[][65], Buy buy[])
{
    if (h[0].alive <= 0)
    {
        saveGame(p, buy);
        Hole::num = 0; p.kill = 0; p.difficultAllow = 1;
        for (int i = 0; i < Bin::num; ++i) {
            b[i].alive = 0; mapFight[b[i].hang][b[i].lie] = "一"; gotoxy(b[i].lie * 2, b[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Zu::num; ++i) {
            z[i].alive = 0; mapFight[z[i].hang][z[i].lie] = "一"; gotoxy(z[i].lie * 2, z[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Di::num; ++i) {
            d[i].alive = 0; mapFight[d[i].hang][d[i].lie] = "一"; gotoxy(d[i].lie * 2, d[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wang::num; ++i) {
            w[i].alive = 0; mapFight[w[i].hang][w[i].lie] = "一"; gotoxy(w[i].lie * 2, w[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Huang::num; ++i) {
            h[i].alive = 0; mapFight[h[i].hang][h[i].lie] = "一"; gotoxy(h[i].lie * 2, h[i].hang + 4); printf("  ");
        }
    
        for (int i = 0; i < emenyButtet::num; ++i) {
            emenybuttet[i].alive = 0; mapFight[emenybuttet[i].hang][emenybuttet[i].lie] = "一"; gotoxy(emenybuttet[i].lie * 2, emenybuttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Medicine::num; ++i) {
            medicine[i].alive = 0; mapFight[medicine[i].hang][medicine[i].lie] = "一"; gotoxy(medicine[i].lie * 2, medicine[i].hang + 4); printf("  ");
        }
        battery.alive = 0; mapFight[battery.hang][battery.lie] = "一"; gotoxy(battery.lie * 2, battery.hang + 4); printf("  ");
        if (timer(800, 782))
        {
            for (int i = 1; i < 36; ++i)
            {
                for (int j = 0; j < 65; ++j)
                {
                    if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光") { mapFight[i][j] = "一"; }
                }
            }
        }
        Bin::num = Zu::num = Di::num = Wang::num = Huang::num = 0;
        passHole.alive = 1;
        passHole.hang = 23; passHole.lie = 29;
    }
}
void isHitByWave(string map[][65], person& p, person& p2, Wave wave[], Wave02 wave02[])
{
    for (int i = 0; i < Wave::num; ++i)
    {
        if (wave[i].alive == 1 && ((wave[i].hang == p2.hang - 1 && wave[i].lie == p2.lie) || (wave[i].hang == p2.hang + 1 && wave[i].lie == p2.lie) || (wave[i].hang == p2.hang + 2 && wave[i].lie == p2.lie) || (wave[i].hang == p2.hang - 2 && wave[i].lie == p2.lie) || (wave[i].hang == p2.hang && wave[i].lie == p2.lie + 1) || (wave[i].hang == p2.hang && wave[i].lie == p2.lie - 1) || (wave[i].hang == p2.hang && wave[i].lie == p2.lie + 2) || (wave[i].hang == p2.hang && wave[i].lie == p2.lie - 2)))
        {
            p2.Hp -= p.damage; wave[i].alive = 0;  map[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
            if (wave[i].dir == 1) {
                if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                    map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                }
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                    map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                }
            }
            else if (wave[i].dir == 2) {
                if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                    map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                    map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                }
            }
            else if (wave[i].dir == 3) {
                if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") {
                    map[wave[i].hang - 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石") {
                    map[wave[i].hang + 1][wave[i].lie + 1] = "一"; gotoxy((wave[i].lie + 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                }
            }
            else if (wave[i].dir == 4) {
                if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") {
                    map[wave[i].hang - 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石") {
                    map[wave[i].hang + 1][wave[i].lie - 1] = "一"; gotoxy((wave[i].lie - 1) * 2, wave[i].hang + 1 + 4); printf("  ");
                }
            }
        }
        if (wave02[i].alive == 1 && ((wave02[i].hang == p.hang - 1 && wave02[i].lie == p.lie) || (wave02[i].hang == p.hang + 1 && wave02[i].lie == p.lie) || (wave02[i].hang == p.hang + 2 && wave02[i].lie == p.lie) || (wave02[i].hang == p.hang - 2 && wave02[i].lie == p.lie) || (wave02[i].hang == p.hang && wave02[i].lie == p.lie + 1) || (wave02[i].hang == p.hang && wave02[i].lie == p.lie - 1) || (wave02[i].hang == p.hang && wave02[i].lie == p.lie + 2) || (wave02[i].hang == p.hang && wave02[i].lie == p.lie - 2)))
        {
            p.Hp -= p2.damage; wave02[i].alive = 0;  map[wave02[i].hang][wave02[i].lie] = "一"; gotoxy(wave02[i].lie * 2, wave02[i].hang + 4); printf("  ");
            if (wave02[i].dir == 1) {
                if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "石") {
                    map[wave02[i].hang + 1][wave02[i].lie - 1] = "一"; gotoxy((wave02[i].lie - 1) * 2, wave02[i].hang + 1 + 4); printf("  ");
                }
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "石") {
                    map[wave02[i].hang + 1][wave02[i].lie + 1] = "一"; gotoxy((wave02[i].lie + 1) * 2, wave02[i].hang + 1 + 4); printf("  ");
                }
            }
            else  if (wave02[i].dir == 2) {
                if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "石") {
                    map[wave02[i].hang - 1][wave02[i].lie - 1] = "一"; gotoxy((wave02[i].lie - 1) * 2, wave02[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "石") {
                    map[wave02[i].hang - 1][wave02[i].lie + 1] = "一"; gotoxy((wave02[i].lie + 1) * 2, wave02[i].hang - 1 + 4); printf("  ");
                }
            }
            else if (wave02[i].dir == 3) {
                if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "石") {
                    map[wave02[i].hang - 1][wave02[i].lie + 1] = "一"; gotoxy((wave02[i].lie + 1) * 2, wave02[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "石") {
                    map[wave02[i].hang + 1][wave02[i].lie + 1] = "一"; gotoxy((wave02[i].lie + 1) * 2, wave02[i].hang + 1 + 4); printf("  ");
                }
            }
            else  if (wave02[i].dir == 4) {
                if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "石") {
                    map[wave02[i].hang - 1][wave02[i].lie - 1] = "一"; gotoxy((wave02[i].lie - 1) * 2, wave02[i].hang - 1 + 4); printf("  ");
                }
                if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "石") {
                    map[wave02[i].hang + 1][wave02[i].lie - 1] = "一"; gotoxy((wave02[i].lie - 1) * 2, wave02[i].hang + 1 + 4); printf("  ");
                }
            }
        }
    }
}
void isHitByButtet(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[])
{
    for (int i = 0; i < Buttet::num; ++i)
    {
        if ((buttet[i].alive == 1) && ((buttet[i].hang == p2.hang - 1 && buttet[i].lie == p2.lie) || (buttet[i].hang == p2.hang + 1 && buttet[i].lie == p2.lie) || (buttet[i].hang == p2.hang && buttet[i].lie == p2.lie - 1) || (buttet[i].hang == p2.hang && buttet[i].lie == p2.lie + 1)))
        {
            p2.Hp -= p.damage;
            buttet[i].alive = 0; map[buttet[i].hang][buttet[i].lie] = "一";  gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
            if (p.weaponUsing == 2 && rand() % 7 == 2 && p.Hp < 10) { p.Hp += 1; }                  //回血
        }
        if ((buttet02[i].alive == 1) && ((buttet02[i].hang == p.hang - 1 && buttet02[i].lie == p.lie) || (buttet02[i].hang == p.hang + 1 && buttet02[i].lie == p.lie) || (buttet02[i].hang == p.hang && buttet02[i].lie == p.lie - 1) || (buttet02[i].hang == p.hang && buttet02[i].lie == p.lie + 1)))
        {
            p.Hp -= p2.damage;
            buttet02[i].alive = 0; map[buttet02[i].hang][buttet02[i].lie] = "一";  gotoxy(buttet02[i].lie * 2, buttet02[i].hang + 4); printf("  ");
            if (p2.weaponUsing == 2 && rand() % 7 == 2 && p2.Hp < 10) { p2.Hp += 1; }                  //回血
        }
    }
}
void isHitByTrap(person& p, person& p2, Fire fire[], Thorn thorn[])
{
    for (int i = 0; i < Fire::num; ++i)
    {
        if (fire[i].hang == p.hang && fire[i].lie == p.lie && timer(1000, 872)) { --p.Hp; }
        if (fire[i].hang == p2.hang && fire[i].lie == p2.lie && timer(1000, 874)) { --p2.Hp; }
    }
    for (int i = 0; i < Thorn::num; ++i)
    {
        if (thorn[i].hang == p.hang && thorn[i].lie == p.lie && timer(1000, 872)) { --p.Hp; }
        if (thorn[i].hang == p2.hang && thorn[i].lie == p2.lie && timer(1000, 874)) { --p2.Hp; }
    }
}
void isChooseDifficultMode(bool difficult)
{
    GetAsyncKeyState('N'); GetAsyncKeyState('M'); system("cls");
    while (1)
    {
        gotoxy(0, 20);
        cout << "                                        选择游戏难度" << endl;
        cout << "                                        N:普通 M:困难" << endl;
        if (GetAsyncKeyState('N')) { difficult = 0; break; }
        if (GetAsyncKeyState('M')) { difficult = 1; break; }
    }
}

bool isInPassHole(person& p, int& level, PassHole& passHole, string mapFight[][65], Hole hole[], Box box[], Fire fire[], Thorn thorn[], Buttet buttet[], Laser laser[], Wave wave[])
{
    if (passHole.alive == 1 && p.hang == passHole.hang && p.lie == passHole.lie)
    {
        for (int i = 0; i < Box::num; ++i) { box[i].alive = 0; }

        passHole.alive = 0;
        p.kill = 0;
        for (int i = 0; i < Buttet::num; ++i) {
            buttet[i].alive = 0; mapFight[buttet[i].hang][buttet[i].lie] = "一"; gotoxy(buttet[i].lie * 2, buttet[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Laser::num; ++i) {
            laser[i].alive = 0; mapFight[laser[i].hang][laser[i].lie] = "一"; gotoxy(laser[i].lie * 2, laser[i].hang + 4); printf("  ");
        }
        for (int i = 0; i < Wave::num; ++i) {
            wave[i].alive = 0; mapFight[wave[i].hang][wave[i].lie] = "一"; gotoxy(wave[i].lie * 2, wave[i].hang + 4); printf("  ");
        }
        for (int i = 1; i < 36; ++i)
        {
            for (int j = 0; j < 65; ++j)
            {
                if (mapFight[i][j] == "冲" || mapFight[i][j] == "波" || mapFight[i][j] == "光" || mapFight[i][j] == "击" || mapFight[i][j] == "弹") {
                    mapFight[i][j] = "一"; gotoxy(j * 2, i + 4); printf("  ");
                }
            }
        }
        level++;
        mapFight[passHole.hang][passHole.lie] = "一"; gotoxy(passHole.lie * 2, passHole.hang + 4); printf("  ");
        return 1;
    }
    return 0;
}
int isInStartHole(person& p, startHole startHole[])
{
    if (p.hang == startHole[0].hang && p.lie == startHole[0].lie)return 1;
    if (p.hang == startHole[1].hang && p.lie == startHole[1].lie)return 2;
    if (p.hang == startHole[2].hang && p.lie == startHole[2].lie)return 3;
    return 0;
}
bool isInShop(person* p, Door* door)
{
    if (p->hang == door[0].hang && p->lie == door[0].lie)return 1;
    return 0;
}
bool isOutShop(person* p, Door* door)
{
    if (p->hang == door[1].hang && p->lie == door[1].lie)return 1;
    return 0;
}

void isBuy(person& p, Buy buy[], int& level, Door door[],string mapShop[][65])
{
    for (int i = 0; i < 8; i++)
    {
        if (p.hang == buy[i].hang && p.lie == buy[i].lie)
        {
            gotoxy(94, 23);
            std::printf("是否购买?(y:购买 n:不买）");
            while (1)
            {
                if (timer(500, 5)) { GetAsyncKeyState('Y'); GetAsyncKeyState('N'); }
                if (GetAsyncKeyState('Y'))
                {
                    if (buy[i].price <= p.money)
                    {
                        p.money -= buy[i].price; buy[i].price = 0;
                        if (i <= 4)
                        {
                            if (p.weaponId == 1) { p.weapon01 = i + 1; p.weaponUsing = i + 1; }
                            else { p.weapon02 = i + 1; p.weaponUsing = i + 1; }
                            saveGame(p, buy);
                        }
                        else
                        {
                            p.skill = i - 4; saveGame(p, buy);
                        }
                    }
                    else {
                        gotoxy(95, 24);
                        cout << "余额不足，赚够钱再来吧~"; Sleep(1000); p.hang += 2; system("cls");  Printstate(p, level); printf("\n");  printMap(mapShop); break;
                    }
                    gotoxy(95, 24);
                    cout << "购买成功!"; Sleep(1000); p.hang += 2; system("cls"); Printstate(p, level); printf("\n"); printMap(mapShop); break;
                }
                else if (GetAsyncKeyState('N'))
                {
                    p.hang += 2; system("cls"); Printstate(p, level); printf("\n"); printMap(mapShop); break;
                }
            }
        }
    }
}
void moveFullMapDamage(string map[][65], bool& flag, Bin b[], Zu z[], Di d[], Wang w[], Huang h[])
{
    static int i = 0;
    for (int j = 1; j <= 35; ++j)
    {
        if (map[j][i] != "墙" && map[j][i] != "石" && map[j][i] != "箱")
        {
            map[j][i] = "波"; gotoxy(i * 2, j + 4); SetColor(13); printf("波"); SetColor();
        }
        if (i - 1 >= 0 && map[j][i - 1] == "波")
        {
            map[j][i - 1] = "一"; gotoxy((i - 1) * 2, j + 4); printf("  ");
        }
    }
    if (i == 64) {
        //for (int k = 1; k <= 35; ++k) { if (map[k][i] == "波") { map[k][i] = "一"; } }
        //for (int u = 0; u < Bin::num; u++) { if (b[u].alive == 1) { b[u].Hp -= 1; } }           //敌人受伤
        //for (int u = 0; u < Zu::num; u++) { if (z[u].alive == 1) { z[u].Hp -= 1; } }
        //for (int u = 0; u < Di::num; u++) { if (d[u].alive == 1) { d[u].Hp -= 1; } }
        //for (int u = 0; u < Wang::num; u++) { if (w[u].alive == 1) { w[u].Hp -= 1; } }
        //for (int u = 0; u < Huang::num; u++) { if (h[u].alive == 1) { h[u].Hp -= 1; } }
        for (int j = 1; j <= 35; ++j) {
            if (i - 1 >= 0 && map[j][i] == "波")
            {
                map[j][i] = "一"; gotoxy(i * 2, j + 4); printf("  ");
            }
        }
        i = 0; flag = 0;
        return;
    }
    if (timer(50, 595))++i;
}

//过场加载动画
void playAnimation()
{
    system("cls");
    for (int i = 1; i <= 20; i++)cout << endl;
    cout << "                                                       加载中..." << endl;
    cout << endl;
    cout << "                                                 进度条" << endl;
    Sleep(500);
    gotoxy(0, 20);
    cout << "                                                       加载中..." << endl;
    cout << endl;
    cout << "                                                 进度条进度条" << endl;
    Sleep(500);
    gotoxy(0, 20);
    cout << "                                                       加载中..." << endl;
    cout << endl;
    cout << "                                                 进度条进度条进度条" << endl;
    Sleep(500); system("cls");
}
//标题加载动画
void playTitleAnimation()
{
    system("cls");
    gotoxy(0, 26);
    cout << "              这是个" << endl;
    cout << "              关于我的冒险" << endl; Sleep(1000);  system("cls");
    gotoxy(0, 27);
    cout << "                  我" << endl; Sleep(1000); system("cls");
}
void playChallengeMode(string map[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Medicine medicine[], Battery& battery, Buttet buttet[], emenyButtet emenybuttet[], Wave wave[], Laser laser[], PassHole& passHole, int& level, startHole StartHole[], Door door[], Buy buy[],bool &isPutOnShield,bool &isFullMapDamage,string mapDie[][65],string mapStart[][65])
{
    isHitEmenyByButtet(p, buttet, b, z, d, w, h, map);//子弹是否打中敌人
    isHitEmenyByWave(p, wave, b, z, d, w, h, map);
    p.move(map);                                       //我移动，内置计时器
    moveEmeny(map, b, z, d, w, h, p);                     //内置计时器,敌人移动
    for (int i = 0; i < Buttet::num; i++) { if (buttet[i].alive == 1) { if (timer(buttet[i].speed, 501 + i)) { buttet[i].move(map, box); } } } //子弹移动
    for (int i = 0; i < Wave::num; i++) { if (wave[i].alive == 1) { if (timer(wave[i].speed, 563 + i)) { wave[i].move(map, box); } } } //冲击波移动
    for (int i = 0; i < Laser::num; ++i) { if (laser[i].alive == 1) { laser[i].move(map, box); } }  //激光移动
    isHitEmenyByLaser(p, b, z, d, w, h, map);                                             // 激光是否打中敌人

    if (GetAsyncKeyState(VK_SPACE)) {                                                         //我释放技能
        if (p.skill == 1) { if (p.Cd <= 0) { p.placeBattery(battery, map); p.Cd = 30; } }
        else if (p.skill == 2) { if (p.Cd <= 0) { p.shield(isPutOnShield); p.Cd = 30; } }
        else if (p.skill == 3) { if (p.Cd <= 0) { p.fullMapDamage(isFullMapDamage); p.Cd = 20; } }
    }
    isKillEmeny(p, b, z, d, w, h, map, medicine);              //是否杀死敌人(掉落药物)

    for (int i = 0; i < emenyButtet::num; ++i) { if (emenybuttet[i].alive == 1) { if (timer(emenybuttet[i].speed, 520 + i)) { emenybuttet[i].move(map); } } } //敌人子弹移动

    isPickMedicine(p, medicine, map);
    if (isFullMapDamage == 1)moveFullMapDamage(map, isFullMapDamage, b, z, d, w, h);     //全图冲击移动，最后会有伤害
    isHitEmenyByFullMapDamage(b, z, d, w, h, map);                                    //全图冲击伤害

    if (level <= 5) { isDie(p, level, mapDie, StartHole, door, b, z, d, w, h, emenybuttet, buttet, laser, wave, battery, medicine, map, buy,mapStart,passHole); }  //是否死亡
    else if (level == 6) { isDieInEndlessMode(p, level, mapDie, StartHole, door, b, z, d, w, h, emenybuttet, buttet, laser, wave, battery, medicine, map, buy, mapStart); }
    if (level <= 4) { isPass(p, level, passHole, b, z, d, w, h, emenybuttet, buttet, laser, wave, battery, medicine, map, buy); }        //是否过关
    else if (level == 5) { isKillHuang(p, level, passHole, b, z, d, w, h, emenybuttet, buttet, laser, wave, battery, medicine, map, buy); }
}
void playMultiplayerMode(person& p, person& p2, string map[][65], Box box[], Fire fire[], Thorn thorn[], Wave wave[], Wave02 wave02[], Buttet buttet[], Buttet02 buttet02[], int& level, startHole StartHole[], Door door[],string mapMultiplayer[][65], string mapStart[][65])
{
    p.move(map);
    p2.player02Move(map);
    if (p.weaponUsing == 3) { if (timer(p.shootSpeed, 784)) { p.player01ShootWave(wave); } }
    else if (p.weaponUsing == 2) { if (timer(p.shootSpeed, 786)) { p.player01ShootButtet(buttet); } }
    if (p2.weaponUsing == 3) { if (timer(p2.shootSpeed, 785)) { p2.player02ShootWave(wave02); } }
    else if (p2.weaponUsing == 2) { if (timer(p2.shootSpeed, 787)) { p2.player02ShootButtet(buttet02); } }

    isPlayer01ChangeWeapon(p);
    isPlayer02ChangeWeapon(p2);
    updatePersonDamage(p);
    updatePersonDamage(p2);

    isHitByWave(mapMultiplayer, p, p2, wave, wave02);
    isHitByButtet(mapMultiplayer, p, p2, buttet, buttet02); //是否被击中
    isHitByTrap(p, p2, fire, thorn);

    for (int i = 0; i < Buttet::num; i++) { if (buttet[i].alive == 1) { if (timer(buttet[i].speed, 791 + i)) { buttet[i].move(map, box); } } } //子弹移动
    for (int i = 0; i < Wave::num; i++) { if (wave[i].alive == 1) { if (timer(wave[i].speed, 810 + i)) { wave[i].move(map, box); } } } //冲击波移动
    for (int i = 0; i < Buttet::num; i++) { if (buttet02[i].alive == 1) { if (timer(buttet02[i].speed, 830 + i)) { buttet02[i].move(map, box); } } } //子弹移动
    for (int i = 0; i < Wave::num; i++) { if (wave02[i].alive == 1) { if (timer(wave02[i].speed, 846 + i)) { wave02[i].move(map, box); } } } //冲击波移动

    isPlayerDie(p, p2, level, mapMultiplayer, StartHole, door, wave, wave02, buttet, buttet02,mapStart);
}

void loadGame(person& p, Buy buy[])
{
    ifstream data;
    data.open("Data.txt", ios::in);
    if (data.good())
    {
        while (data >> p.hightest_score >> p.Exp >> p.money >> p.weapon01 >> p.weapon02 >> p.skill >> p.difficultAllow >> buy[0].price >> buy[1].price >> buy[2].price >> buy[3].price >> buy[4].price >> buy[5].price >> buy[6].price >> buy[7].price);
    }
    data.close();
}
void saveGame(person& p, Buy buy[])
{
    ofstream data;
    data.open("Data.txt", ios::out);
    data << p.hightest_score << ' ' << p.Exp << ' ' << p.money << ' ' << p.weapon01 << ' ' << p.weapon02 << ' ' << p.skill << ' ' << p.difficultAllow << ' ' << buy[0].price << ' ' << buy[1].price << ' ' << buy[2].price << ' ' << buy[3].price << ' ' << buy[4].price << ' ' << buy[5].price << ' ' << buy[6].price << ' ' << buy[7].price;
    data.close();
}

void PlayHuangDie()
{
   
}




