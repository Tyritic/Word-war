
#include"Item.h"
#include"func.h"

using namespace std;

int step[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int Fire::num = 0;
int Thorn::num = 0;
int Box::num = 0;
int Buttet::num = 15;
int Wave::num = 10;
int Laser::num = 10;
int emenyButtet::num = 40;
int Medicine::num = 5;
int Hole::num = 0;
int Bin::num = 0;
int Zu::num = 0;
int Di::num = 0;
int Wang::num = 0;
int Huang::num = 0;

AbstractItem::AbstractItem() { hang = lie = 0; }

Buy::Buy() { price = 0; };

Box::Box()
{
    alive = 0;
}

Medicine::Medicine()
{
    alive = 0;
}

PassHole::PassHole() { alive = 0; }

Buttet::Buttet() { hang = lie = 20; alive = 0; speed = 50; dir = 0; }
void Buttet::move(string map[][65], Box box[])
{
    if (dir == 1) { if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1; gotoxy(2 * lie, hang + 4); SetColor(13); printf("弹"); SetColor(); return; } }
    else if (dir == 2) { if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱") { map[hang][lie] = "一";  gotoxy(2 * lie, hang + 4); printf("  "); hang += 1; gotoxy(2 * lie, hang + 4); SetColor(13); printf("弹"); SetColor(); return; } }
    else if (dir == 3) { if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1; gotoxy(2 * lie, hang + 4); SetColor(13); printf("弹"); SetColor(); return; } }
    else if (dir == 4) { if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1; gotoxy(2 * lie, hang + 4); SetColor(13); printf("弹"); SetColor();  return; } }

    if (dir == 1) { if (map[hang - 1][lie] == "墙" || map[hang - 1][lie] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    else if (dir == 2) { if (map[hang + 1][lie] == "墙" || map[hang + 1][lie] == "石") { map[hang][lie] = "一";  gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    else if (dir == 3) { if (map[hang][lie - 1] == "墙" || map[hang][lie - 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    else if (dir == 4) { if (map[hang][lie + 1] == "墙" || map[hang][lie + 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }

    if (dir == 1) {
        if (map[hang - 1][lie] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang - 1][lie] = "一"; gotoxy(2 * lie, hang - 1 + 4); printf("  ");
            for (int i = 0; i < Box::num; ++i)
            {
                if (hang - 1 == box[i].hang && lie == box[i].lie) { box[i].alive = 0; break; }
            }
            return;
        }
    }
    else if (dir == 2) {
        if (map[hang + 1][lie] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");  alive = 0; map[hang + 1][lie] = "一"; gotoxy(2 * lie, hang + 1 + 4); printf("  "); for (int i = 0; i < Box::num; ++i)
            {
                if (hang + 1 == box[i].hang && lie == box[i].lie) { box[i].alive = 0; break; }
            } return;
        }
    }
    else if (dir == 3) {
        if (map[hang][lie - 1] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang + 4); printf("  ");   for (int i = 0; i < Box::num; ++i)
            {
                if (hang == box[i].hang && lie - 1 == box[i].lie) { box[i].alive = 0; break; }
            }return;
        }
    }
    else if (dir == 4) {
        if (map[hang][lie + 1] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");  alive = 0; map[hang][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang + 4); printf("  ");   for (int i = 0; i < Box::num; ++i)
            {
                if (hang == box[i].hang && lie + 1 == box[i].lie) { box[i].alive = 0; break; }
            }return;
        }
    }
}

Wave::Wave() { hang = lie = 20; alive = 0; speed = 60; dir = 0; }
void Wave::move(string map[][65], Box box[])
{
    if (dir == 1) {
        if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
        {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");
            if (map[hang + 1][lie - 1] != "墙" && map[hang + 1][lie - 1] != "石") { map[hang + 1][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang + 1 + 4); printf("  "); }
            if (map[hang + 1][lie + 1] != "墙" && map[hang + 1][lie + 1] != "石") {
                map[hang + 1][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang + 1 + 4); printf("  ");
            }hang -= 1;
            gotoxy(2 * lie, hang + 4); SetColor(13); printf("击"); SetColor();
        }
        if (map[hang - 1][lie] == "墙" || map[hang - 1][lie] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; }
    }
    else if (dir == 2) {
        if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");
            if (map[hang - 1][lie - 1] != "墙" && map[hang - 1][lie - 1] != "石") { map[hang - 1][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang - 1 + 4); printf("  "); }
            if (map[hang - 1][lie + 1] != "墙" && map[hang - 1][lie + 1] != "石") { map[hang - 1][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang - 1 + 4); printf("  "); }hang += 1;
            gotoxy(2 * lie, hang + 4); SetColor(13); printf("击"); SetColor();
        }
        if (map[hang + 1][lie] == "墙" || map[hang + 1][lie] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; }
    }
    else if (dir == 3) {
        if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");
            if (map[hang - 1][lie + 1] != "墙" && map[hang - 1][lie + 1] != "石") { map[hang - 1][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang - 1 + 4); printf("  "); }
            if (map[hang + 1][lie + 1] != "墙" && map[hang + 1][lie + 1] != "石") { map[hang + 1][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang + 1 + 4); printf("  "); }lie -= 1;
            gotoxy(2 * lie, hang + 4); SetColor(13); printf("击"); SetColor();
        }
        if (map[hang][lie - 1] == "墙" || map[hang][lie - 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; }
    }
    else if (dir == 4) {
        if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");
            if (map[hang - 1][lie - 1] != "墙" && map[hang - 1][lie - 1] != "石") { map[hang - 1][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang - 1 + 4); printf("  "); }
            if (map[hang + 1][lie - 1] != "墙" && map[hang + 1][lie - 1] != "石") { map[hang + 1][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang + 1 + 4); printf("  "); }lie += 1;
            gotoxy(2 * lie, hang + 4); SetColor(13); printf("击"); SetColor();
        }
        if (map[hang][lie + 1] == "墙" || map[hang][lie + 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; }
    }

    //if (dir == 1) { if (map[hang - 1][lie] == "墙" || map[hang - 1][lie] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    //else if (dir == 2) { if (map[hang + 1][lie] == "墙" || map[hang + 1][lie] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    //else if (dir == 3) { if (map[hang][lie - 1] == "墙" || map[hang][lie - 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    //else if (dir == 4) { if (map[hang][lie + 1] == "墙" || map[hang][lie + 1] == "石") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return; } }
    if (dir == 1) {
        if (map[hang - 1][lie] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang - 1][lie] = "一"; gotoxy(2 * lie, hang - 1 + 4); printf("  ");
            for (int i = 0; i < Box::num; ++i)
            {
                if (hang - 1 == box[i].hang && lie == box[i].lie) { box[i].alive = 0; break; }
            }
            return;
        }
    }
    else if (dir == 2) {
        if (map[hang + 1][lie] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang + 1][lie] = "一"; gotoxy(2 * lie, hang + 1 + 4); printf("  "); for (int i = 0; i < Box::num; ++i)
            {
                if (hang + 1 == box[i].hang && lie == box[i].lie) { box[i].alive = 0; break; }
            } return;
        }
    }
    else if (dir == 3) {
        if (map[hang][lie - 1] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang][lie - 1] = "一"; gotoxy(2 * (lie - 1), hang + 4); printf("  "); for (int i = 0; i < Box::num; ++i)
            {
                if (hang == box[i].hang && lie - 1 == box[i].lie) { box[i].alive = 0; break; }
            }return;
        }
    }
    else if (dir == 4) {
        if (map[hang][lie + 1] == "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; map[hang][lie + 1] = "一"; gotoxy(2 * (lie + 1), hang + 4); printf("  "); for (int i = 0; i < Box::num; ++i)
            {
                if (hang == box[i].hang && lie + 1 == box[i].lie) { box[i].alive = 0; break; }
            }return;
        }
    }
    if (alive == 1)
    {
        if ( dir == 1)
        {
            map[hang][lie] = "击"; if (map[hang + 1][lie - 1] != "墙" && map[hang + 1][lie - 1] != "石") { map[hang + 1][lie - 1] = "冲"; gotoxy(2 * (lie - 1), hang + 1 + 4); SetColor(13); printf("冲"); SetColor(); }
            if (map[hang + 1][lie + 1] != "墙" && map[hang + 1][lie + 1] != "石") { map[hang + 1][lie + 1] = "波"; gotoxy(2 * (lie + 1), hang + 1 + 4); SetColor(13); printf("波"); SetColor(); }
        }
        if ( dir == 2)
        {
            map[hang][lie] = "击"; if (map[hang - 1][lie - 1] != "墙" && map[hang - 1][lie - 1] != "石") { map[hang - 1][lie - 1] = "冲"; gotoxy(2 * (lie - 1), hang - 1 + 4); SetColor(13); printf("冲"); SetColor(); }
            if (map[hang - 1][lie + 1] != "墙" && map[hang - 1][lie + 1] != "石") { map[hang - 1][lie + 1] = "波"; gotoxy(2 * (lie + 1), hang - 1 + 4); SetColor(13); printf("波"); SetColor(); }
        }
        if ( dir == 3)
        {
            map[hang][lie] = "击"; if (map[hang - 1][lie + 1] != "墙" && map[hang - 1][lie + 1] != "石") { map[hang - 1][lie + 1] = "冲"; gotoxy(2 * (lie + 1), hang - 1 + 4); SetColor(13); printf("冲"); SetColor(); }
            if (map[hang + 1][lie + 1] != "墙" && map[hang + 1][lie + 1] != "石") { map[hang + 1][lie + 1] = "波"; gotoxy(2 * (lie + 1), hang + 1 + 4); SetColor(13); printf("波"); SetColor(); }
        }
        if ( dir == 4)
        {
            map[hang][lie] = "击"; if (map[hang - 1][lie - 1] != "墙" && map[hang - 1][lie - 1] != "石") { map[hang - 1][lie - 1] = "冲"; gotoxy(2 * (lie - 1), hang - 1 + 4); SetColor(13); printf("冲"); SetColor(); }
            if (map[hang + 1][lie - 1] != "墙" && map[hang + 1][lie - 1] != "石") { map[hang + 1][lie - 1] = "波"; gotoxy(2 * (lie - 1), hang + 1 + 4); SetColor(13); printf("波"); SetColor(); }
        }
    }
}

Laser::Laser() { hang = lie = 20; alive = 0; dir = 0; }
void Laser::move(string map[][65], Box box[])
{
    if (dir == 1)
    {
        int i = 1;
        if (timer(400, 578)) while (true)
        {
            if (map[hang - i][lie] != "墙" && map[hang - i][lie] != "石")
            {
                if (map[hang - i][lie] == "箱")
                {
                    for (int j = 0; j < Box::num; ++j)
                    {
                        if (hang - i == box[j].hang && lie == box[j].lie) { box[j].alive = 0; break; }
                    }
                }
                map[hang - i][lie] = "光"; ++i;
            }
            else
            {
                timer(200, 574); i = 1;
                break;
            }
        }
        if (timer(200, 574))
        {
            alive = 0;
            while (true)
            {
                if (map[hang - i][lie] != "墙" && map[hang - i][lie] != "石")
                {
                    map[hang - i][lie] = "一"; gotoxy(2 * lie, hang - i + 4); printf("  "); ++i;
                }
                else { break; }
            }
        }

    }
    else if (dir == 2)
    {
        int i = 1;
        if (timer(400, 579))  while (true)
        {
            if (map[hang + i][lie] != "墙" && map[hang + i][lie] != "石")
            {
                if (map[hang + i][lie] == "箱")
                {
                    for (int j = 0; j < Box::num; ++j)
                    {
                        if (hang + i == box[j].hang && lie == box[j].lie) { box[j].alive = 0; break; }
                    }
                }
                map[hang + i][lie] = "光"; ++i;
            }
            else
            {
                timer(200, 575); i = 1;
                break;
            }
        }
        if (timer(200, 575))
        {
            alive = 0;
            while (true)
            {
                if (map[hang + i][lie] != "墙" && map[hang + i][lie] != "石")
                {
                    map[hang + i][lie] = "一"; gotoxy(2 * lie, hang + i + 4); printf("  ");  ++i;
                }
                else { break; }
            }
        }
    }
    else if (dir == 3)
    {
        int i = 1;
        if (timer(400, 580))while (true)
        {
            if (map[hang][lie - i] != "墙" && map[hang][lie - i] != "石")
            {
                if (map[hang][lie - i] == "箱")
                {
                    for (int j = 0; j < Box::num; ++j)
                    {
                        if (hang == box[j].hang && lie - i == box[j].lie) { box[j].alive = 0; break; }
                    }
                }
                map[hang][lie - i] = "光"; ++i;
            }
            else
            {
                timer(200, 576);
                break;
            }
        }
        if (timer(200, 576))
        {
            alive = 0;
            while (true)
            {
                if (map[hang][lie - i] != "墙" && map[hang][lie - i] != "石")
                {
                    map[hang][lie - i] = "一"; gotoxy(2 * (lie - i), hang + 4); printf("  ");  ++i;
                }
                else { break; }
            }
        }
    }
    else if (dir == 4)
    {
        int i = 1;
        if (timer(400, 581)) while (true)
        {
            if (map[hang][lie + i] != "墙" && map[hang][lie + i] != "石")
            {
                if (map[hang][lie + i] == "箱")
                {
                    for (int j = 0; j < Box::num; ++j)
                    {
                        if (hang == box[j].hang && lie + i == box[j].lie) { box[j].alive = 0; break; }
                    }
                }
                map[hang][lie + i] = "光"; ++i;
            }
            else
            {
                timer(200, 577);
                break;
            }
        }
        if (timer(200, 577))
        {
            alive = 0;
            while (true)
            {
                if (map[hang][lie + i] != "墙" && map[hang][lie + i] != "石")
                {
                    map[hang][lie + i] = "一";  gotoxy(2 * (lie + i), hang + 4); printf("  "); ++i;
                }
                else { break; }
            }
        }
    }
}

emenyButtet::emenyButtet() { hang = lie = 20; alive = 0; speed = 100; damage = 1; dir = 0; }
void emenyButtet:: move(string map[][65])
{
    if (dir == 1) { if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1; gotoxy(2 * lie, hang + 4); SetColor(14); printf("弹"); SetColor(); return; } }
    else if (dir == 2) { if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱") { map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1; gotoxy(2 * lie, hang + 4); SetColor(14); printf("弹"); SetColor(); return; } }
    else if (dir == 3) {
        if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1; gotoxy(2 * lie, hang + 4); SetColor(14); printf("弹"); SetColor(); return;
        }
    }
    else if (dir == 4) {
        if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱") {
            map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1; gotoxy(2 * lie, hang + 4); SetColor(14); printf("弹"); SetColor(); return;
        }
    }

    if (dir == 1 && (map[hang - 1][lie] == "墙" || map[hang - 1][lie] == "石" || map[hang - 1][lie] == "箱")) {
        map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return;
    }
    else if (dir == 2 && (map[hang + 1][lie] == "墙" || map[hang + 1][lie] == "石" || map[hang + 1][lie] == "箱")) {
        map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return;
    }
    else if (dir == 3 && (map[hang][lie - 1] == "墙" || map[hang][lie - 1] == "石" || map[hang][lie - 1] == "箱")) {
        map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return;
    }
    else if (dir == 4 && (map[hang][lie + 1] == "墙" || map[hang][lie + 1] == "石" || map[hang][lie + 1] == "箱")) {
        map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); alive = 0; return;
    }
}

Battery::Battery() { hang = lie = 20; alive = 0; }
void Battery::shoot(Buttet buttet[])
{
    for (int i = 0; i < Buttet::num; i++)
    {
        if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 1; break; }
    }
    for (int i = 0; i < Buttet::num; i++)
    {
        if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 2; break; }
    }
    for (int i = 0; i < Buttet::num; i++)
    {
        if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 3; break; }
    }
    for (int i = 0; i < Buttet::num; i++)
    {
        if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 4; break; }
    }
}

person::person()
{
    Hp = 10; alive = 1; weaponId = 1; weaponUsing = 1; weapon01 = 1; weapon02 = 1; hang = 0; lie = 0;  weaponAllow = 0;  speed = 60; level = 1; damage = 1; shootSpeed = 800; skill = 0;
    level = 0, money = 1000, score = 0, hightest_score = 0, kill = 0; difficultAllow = 0; Cd = 0; needKill_kill = 10; limit = 10; Exp = 0; originalHp = 10;
    weaponTemp01 = weapontemp02 = 1;
}
void person::countdown()
{
    if (timer(1000, 700))
    {
        if (Cd > 0)
            Cd--;
    }
}
string person::weaponChange(int id)
{
    string name{ 0 };
    switch (id)
    {
    case 1:
        name = "雪弦";
        break;
    case 2:
        name = "润泽";
        break;
    case 3:
        name = "荧焰";
        break;
    case 4:
        name = "折镜";
        break;
    case 5:
        name = "碧芒";
        break;
    }
    return name;
}
string person::skillChange(int id)
{
    string name{ 0 };
    switch (id)
    {
    case 0:
        name = "   无技能"; break;
    case 1:
        name = "     炮台";
        break;
    case 2:
        name = "     护盾";
        break;
    case 3:
        name = " 全图冲击";
        break;
    }
    return name;
}
void person::move(string map[][65])
{
    int upHang = hang - 1; int upLie = lie - 1; int downHang = hang + 1; int downLie = lie + 1;
    if (GetAsyncKeyState('W') && map[upHang][lie] != "路" && map[upHang][lie] != "墙" && map[upHang][lie] != "石" && map[upHang][lie] != "柜" && map[upHang][lie] != "箱" && timer(speed, 1))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        hang--; gotoxy(lie * 2, hang + 4); printf("我");
    }
    if (GetAsyncKeyState('S') && map[downHang][lie] != "路" && map[downHang][lie] != "墙" && map[downHang][lie] != "石" && map[downHang][lie] != "柜" && map[downHang][lie] != "箱" && timer(speed, 2))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        hang++; gotoxy(lie * 2, hang + 4); printf("我");
    }
    if (GetAsyncKeyState('A') && map[hang][upLie] != "路" && map[hang][upLie] != "墙" && map[hang][upLie] != "石" && map[hang][upLie] != "柜" && map[hang][upLie] != "箱" && timer(speed, 3))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        lie--; gotoxy(lie * 2, hang + 4); printf("我");
    }
    if (GetAsyncKeyState('D') && map[hang][downLie] != "路" && map[hang][downLie] != "墙" && map[hang][downLie] != "石" && map[hang][downLie] != "柜" && map[hang][downLie] != "箱" && timer(speed, 4))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        lie++; gotoxy(lie * 2, hang + 4); printf("我");
    }

}
void person::shootButtet(Buttet buttet[])
{
    if (GetAsyncKeyState(VK_UP))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 1; break; }
        }
        return;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 4; break; }
        }return;
    }
}
void person::shootButtetPlus(Buttet buttet[])
{
    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
    {
        PlayZheJing();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 1; break; }
        }
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 2; break; }
        }
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 3; break; }
        }
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 4; break; }
        }
    }
}
void person::shootWave(Wave wave[])
{
    if (GetAsyncKeyState(VK_UP))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 1; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 4; break; }
        }return;
    }

}
void person::shootWavePlus(Wave wave[])
{
    for (int i = 0; i < Wave::num; i++)
    {
        if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 1; break; }
    }
    for (int i = 0; i < Wave::num; i++)
    {
        if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 2; break; }
    }
    for (int i = 0; i < Wave::num; i++)
    {
        if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 3; break; }
    }
    for (int i = 0; i < Wave::num; i++)
    {
        if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 4; break; }
    }
}
void person::shootLaser(Laser laser[])
{
    if (GetAsyncKeyState(VK_UP))
    {
        PlayBiMang();
        for (int i = 0; i < Laser::num; i++)
        {
            if (laser[i].alive == 0) { laser[i].alive = 1; laser[i].hang = hang; laser[i].lie = lie; laser[i].dir = 1; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        PlayBiMang();
        for (int i = 0; i < Laser::num; i++)
        {
            if (laser[i].alive == 0) { laser[i].alive = 1; laser[i].hang = hang; laser[i].lie = lie; laser[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        PlayBiMang();
        for (int i = 0; i < Laser::num; i++)
        {
            if (laser[i].alive == 0) { laser[i].alive = 1; laser[i].hang = hang; laser[i].lie = lie; laser[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        PlayBiMang();
        for (int i = 0; i < Laser::num; i++)
        {
            if (laser[i].alive == 0) { laser[i].alive = 1; laser[i].hang = hang; laser[i].lie = lie; laser[i].dir = 4; break; }
        }return;
    }
}
void person::placeBattery(Battery& battery, string map[][65])
{
    if (battery.alive == 0) {
        battery.hang = hang; battery.lie = lie;
        battery.alive = 1;
    }
    else { map[battery.hang][battery.lie] = "一"; gotoxy(battery.lie, battery.hang + 4); printf("  "); battery.hang = hang; battery.lie = lie; }
}
void person::shield(bool& flag)
{
    originalHp = Hp;
    Hp += 2; flag = 1;
}
void person::fullMapDamage(bool& flag)
{
    flag = 1;
}
void person::player01ShootWave(Wave wave[])
{
    if (GetAsyncKeyState('Y'))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 1; break; }
        }return;
    }
    if (GetAsyncKeyState('H'))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState('G'))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState('J'))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 4; break; }
        }return;
    }
}
void person::player02ShootWave(Wave02 wave[])
{
    if (GetAsyncKeyState(VK_NUMPAD5))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 1; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_NUMPAD2))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_NUMPAD1))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_NUMPAD3))
    {
        PlayZheJing();
        for (int i = 0; i < Wave::num; i++)
        {
            if (wave[i].alive == 0) { wave[i].alive = 1; wave[i].hang = hang; wave[i].lie = lie; wave[i].dir = 4; break; }
        }return;
    }
}
void person::player01ShootButtet(Buttet buttet[])
{
    if (GetAsyncKeyState('Y'))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 1; break; }
        }
        return;
    }
    if (GetAsyncKeyState('H'))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState('G'))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState('J'))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 4; break; }
        }return;
    }
}
void person::player02ShootButtet(Buttet02 buttet[])
{
    if (GetAsyncKeyState(VK_NUMPAD5))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 1; break; }
        }
        return;
    }
    if (GetAsyncKeyState(VK_NUMPAD2))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 2; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_NUMPAD1))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 3; break; }
        }return;
    }
    if (GetAsyncKeyState(VK_NUMPAD3))
    {
        PlayRunZe();
        for (int i = 0; i < Buttet::num; i++)
        {
            if (buttet[i].alive == 0) { buttet[i].alive = 1; buttet[i].hang = hang; buttet[i].lie = lie; buttet[i].dir = 4; break; }
        }return;
    }
}
void person::player02Move(string map[][65])
{
    int upHang = hang - 1; int upLie = lie - 1; int downHang = hang + 1; int downLie = lie + 1;
    if (GetAsyncKeyState(VK_UP) && map[upHang][lie] != "路" && map[upHang][lie] != "墙" && map[upHang][lie] != "石" && map[upHang][lie] != "柜" && map[upHang][lie] != "箱" && timer(speed, 866))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        hang--; gotoxy(lie * 2, hang + 4); printf("他");
    }
    if (GetAsyncKeyState(VK_DOWN) && map[downHang][lie] != "路" && map[downHang][lie] != "墙" && map[downHang][lie] != "石" && map[downHang][lie] != "柜" && map[downHang][lie] != "箱" && timer(speed, 867))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        hang++; gotoxy(lie * 2, hang + 4); printf("他");
    }
    if (GetAsyncKeyState(VK_LEFT) && map[hang][upLie] != "路" && map[hang][upLie] != "墙" && map[hang][upLie] != "石" && map[hang][upLie] != "柜" && map[hang][upLie] != "箱" && timer(speed, 868))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        lie--; gotoxy(lie * 2, hang + 4); printf("他");
    }
    if (GetAsyncKeyState(VK_RIGHT) && map[hang][downLie] != "路" && map[hang][downLie] != "墙" && map[hang][downLie] != "石" && map[hang][downLie] != "柜" && map[hang][downLie] != "箱" && timer(speed, 869))
    {
        map[hang][lie] = "一"; gotoxy(lie * 2, hang + 4); printf("  ");
        lie++; gotoxy(lie * 2, hang + 4); printf("他");
    }
}



void person::PlayZheJing()
{
    PlaySound(TEXT("折镜.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void person::PlayBiMang()
{
    PlaySound(TEXT("碧芒.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void person::PlayRunZe()
{
    PlaySound(TEXT("润泽.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void person::PlayYingyan()
{
    PlaySound(TEXT("萤焰.mp3"), NULL, SND_FILENAME | SND_ASYNC);
}


Emeny::Emeny()
{
    alive = 0;
    hang = lie = 20;
}
void Emeny::move(string map[][65])
{
    int k = rand() % 4;
    if (map[hang + step[k][0]][lie + step[k][1]] != "墙" && map[hang + step[k][0]][lie + step[k][1]] != "石" && map[hang + step[k][0]][lie + step[k][1]] != "箱")
    {
        map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  ");  hang += step[k][0]; lie += step[k][1];
    }
}
void Emeny::shoot(person& p, emenyButtet emenybuttet[])
{
    int k = rand() % 3 + 1;
    if (p.hang <= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie;
                if (k > 1) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie;
                if (k > 1) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie;
                if (k > 1) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie;
                if (k > 1) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }


}

Bin::Bin()
{
    Hp = 2; speed = 1000; shootSpeed = 3000;
}
void Bin::creat(Hole hole[])
{
    alive = 1; Hp = 2; int k = 0;
    if (Hole::num > 0)  k = rand() % Hole::num;
    hang = hole[k].hang; lie = hole[k].lie;
}
void Bin::shoot(person& p, emenyButtet emenybuttet[],int emenyButtetSpeed)
{
    int k = rand() % 4 + 1;
    if (p.hang <= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }


}

Zu::Zu() {
    Hp = 4; speed = 950; shootSpeed = 2000;
}
void Zu::creat(Hole hole[])
{
    alive = 1; Hp = 4;
    int k = 0;
    if (Hole::num > 0)  k = rand() % Hole::num;
    hang = hole[k].hang; lie = hole[k].lie;
}
void Zu::shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed)
{
    int k = rand() % 4 + 1;
    if (p.hang <= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed - 10;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1;  emenybuttet[i].speed = emenyButtetSpeed - 10;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1; emenybuttet[i].speed = emenyButtetSpeed - 10;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 1;  emenybuttet[i].speed = emenyButtetSpeed - 10;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
}

Di::Di() {
    Hp = 6; speed = 900;  shootSpeed = 1600;
}
void Di::creat(Hole hole[])
{
    alive = 1; Hp = 6;
    int k = 0;
    if (Hole::num > 0)  k = rand() % Hole::num;
    hang = hole[k].hang; lie = hole[k].lie;
}
void Di::shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed)
{
    int k = rand() % 4 + 1;
    if (p.hang <= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 20;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 20;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 1;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 20;
                if (k > 2) emenybuttet[i].dir = 3;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 20;
                if (k > 2) emenybuttet[i].dir = 4;
                else  emenybuttet[i].dir = 2;
                return;
            }
        }
    }
}
void Di::move(string map[][65], person& p)
{
    if (p.hang <= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
}

Wang::Wang() {
    Hp = 10; speed = 700; shootSpeed = 1500;
}
void Wang::creat(Hole hole[])
{
    alive = 1; Hp = 10;
    int k = 0;
    if (Hole::num > 0)  k = rand() % Hole::num;
    hang = hole[k].hang; lie = hole[k].lie;
}
void Wang::shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed)
{
    for (int j = 1; j <= 4; ++j) {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 30;
                emenybuttet[i].dir = j;
                break;
            }
        }
    }
}
void Wang::move(string map[][65], person& p)
{
    if (p.hang <= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
}

Huang::Huang() {
    Hp = 40; speed = 650; shootSpeed = 1500;
}
void Huang::PlayShoot()
{
  
}
void Huang::creat(Hole hole[])
{
    alive = 1; Hp = 40;
    int k = 0;
    if (Hole::num > 0)  k = rand() % Hole::num;
    hang = hole[k].hang; lie = hole[k].lie;
}
void Huang::shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed)
{
    PlayShoot();
    for (int j = 1; j <= 4; ++j) {
        for (int i = 0; i < emenyButtet::num; ++i)
        {
            if (emenybuttet[i].alive == 0)
            {
                emenybuttet[i].alive = 1; emenybuttet[i].hang = hang; emenybuttet[i].lie = lie; emenybuttet[i].damage = 2; emenybuttet[i].speed = emenyButtetSpeed - 40;
                emenybuttet[i].dir = j;
                break;
            }
        }
    }
}
void Huang::move(string map[][65], person& p)
{
    if (p.hang <= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang <= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang - 1][lie] != "墙" && map[hang - 1][lie] != "石" && map[hang - 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang -= 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie <= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie - 1] != "墙" && map[hang][lie - 1] != "石" && map[hang][lie - 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie -= 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
    else if (p.hang >= hang && p.lie >= lie)
    {
        if (rand() % 2 == 1)
        {
            if (map[hang][lie + 1] != "墙" && map[hang][lie + 1] != "石" && map[hang][lie + 1] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); lie += 1;
            }
        }
        else
        {
            if (map[hang + 1][lie] != "墙" && map[hang + 1][lie] != "石" && map[hang + 1][lie] != "箱")
            {
                map[hang][lie] = "一"; gotoxy(2 * lie, hang + 4); printf("  "); hang += 1;
            }
        }
    }
}



