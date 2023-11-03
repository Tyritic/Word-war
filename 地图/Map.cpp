#include"Item.h"
#include"Map.h"
#include"Music.h"
using namespace std;

void printMap(string map[][65])
{

    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            if (map[i][j] == "一")
            {
                std::printf("%s", "  ");
                //cout << "  ";
                continue;
            }
            std::printf("%s", map[i][j].c_str());
            //cout << map[i][j];
        }
        if (i == 35)break;
        std::printf("\n");

    }
}
void printMapFast(string map[][65])
{
    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            if (map[i][j] == "买") { gotoxy(2 * j, i + 4); printf("买"); }
            else if (map[i][j] == "门") { gotoxy(2 * j, i + 4); printf("门"); }
            else if (map[i][j] == "我") { gotoxy(2 * j, i + 4); printf("我"); }
        }
    }
}
void printMapFight(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Buttet buttet[], emenyButtet emenybuttet[])
{

    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            if (map[i][j] == "一")
            {
                std::printf("%s", "  ");
                continue;
            }
            else if (map[i][j] == "洞") { SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "药") { SetColor(10); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "冲") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "击") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "波") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "光") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "刺") { SetColor(11); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "炮") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "箱") {
                SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            else if (map[i][j] == "火") {
                SetColor(12); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            for (int k = 0; k < emenyButtet::num; ++k) { if (i == emenybuttet[k].hang && j == emenybuttet[k].lie && emenybuttet[k].alive == 1) { SetColor(14); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            for (int k = 0; k < Buttet::num; ++k) { if (i == buttet[k].hang && j == buttet[k].lie && buttet[k].alive == 1) { SetColor(13); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            for (int k = 0; k < Bin::num; ++k) { if (b[k].alive == 1 && i == b[k].hang && j == b[k].lie) { SetColor(b[k].Hp); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            for (int k = 0; k < Zu::num; ++k) {
                if (z[k].alive == 1 && i == z[k].hang && j == z[k].lie) {
                    SetColor(z[k].Hp); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Di::num; ++k)
            {
                if (d[k].alive == 1 && i == d[k].hang && j == d[k].lie) {
                    SetColor(d[k].Hp); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Wang::num; ++k) {
                if (w[k].alive == 1 && i == w[k].hang && j == w[k].lie) {
                    SetColor(w[k].Hp); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Huang::num; ++k) {
                if (h[k].alive == 1 && i == h[k].hang && j == h[k].lie) {
                    SetColor(5); "%s", std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }

            std::printf("%s", map[i][j].c_str());
        A:;
        }
        if (i == 35)break;
        std::printf("\n");
    }

}
void printMapFightFast(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Buttet buttet[], emenyButtet emenybuttet[])
{
    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            //for (int k = 0; k < emenyButtet::num; ++k) { if (i == emenybuttet[k].hang && j == emenybuttet[k].lie && emenybuttet[k].alive == 1) { SetColor(14); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            //for (int k = 0; k < Buttet::num; ++k) { if (i == buttet[k].hang && j == buttet[k].lie && buttet[k].alive == 1) { SetColor(13); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            if (map[i][j] == "洞") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "火") { SetColor(12); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "刺") { SetColor(11); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "箱") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "药") { SetColor(10); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "炮") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "冲") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "击") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "波") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "光") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            for (int k = 0; k < Bin::num; ++k) { if (b[k].alive == 1 && i == b[k].hang && j == b[k].lie) { SetColor(b[k].Hp); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            for (int k = 0; k < Zu::num; ++k) {
                if (z[k].alive == 1 && i == z[k].hang && j == z[k].lie) {
                    SetColor(z[k].Hp); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Di::num; ++k)
            {
                if (d[k].alive == 1 && i == d[k].hang && j == d[k].lie) {
                    SetColor(d[k].Hp); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Wang::num; ++k) {
                if (w[k].alive == 1 && i == w[k].hang && j == w[k].lie) {
                    SetColor(w[k].Hp); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            for (int k = 0; k < Huang::num; ++k) {
                if (h[k].alive == 1 && i == h[k].hang && j == h[k].lie) {
                    SetColor(5); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A;
                }
            }
            if (map[i][j] == "我") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
        A:;
        }

    }
}
void printMapMultiplayer(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[])
{
    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            if (map[i][j] == "一")
            {
                std::printf("%s", "  ");
                continue;
            }
            else if (map[i][j] == "冲") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "击") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "波") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "刺") { SetColor(11); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "箱") {
                SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            else if (map[i][j] == "火") {
                SetColor(12); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            std::printf("%s", map[i][j].c_str());
        A:;
        }
        if (i == 35)break;
        std::printf("\n");
    }
}
void printMapMultiplayerFast(string map[][65], person& p, person& p2, Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[])
{
    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            //for (int k = 0; k < emenyButtet::num; ++k) { if (i == emenybuttet[k].hang && j == emenybuttet[k].lie && emenybuttet[k].alive == 1) { SetColor(14); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            //for (int k = 0; k < Buttet::num; ++k) { if (i == buttet[k].hang && j == buttet[k].lie && buttet[k].alive == 1) { SetColor(13); gotoxy(2 * j, i + 4); std::printf(map[i][j].c_str()); SetColor(); goto A; } }
            if (map[i][j] == "火") { SetColor(12); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "刺") { SetColor(11); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "箱") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "冲") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "击") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "波") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            if (map[i][j] == "我") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
            if (map[i][j] == "他") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
        A:;
        }

    }
}
void Printstate(person A, int level)
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|HP：  " << left << setw(3) << A.Hp << "/" << left << setw(6) << A.limit << right << setw(9) << "当前武器：" << A.weaponChange(A.weaponUsing) << setw(10) << "（按R切换）" << right << setw(10) << "武器槽：" << A.weaponChange(A.weapon01) << "," << A.weaponChange(A.weapon02) << setw(10) << "技能：" << A.skillChange(A.skill);
    if (A.Cd > 0 && A.skill != 0)
    {
        cout << "（按空格释放）：" << "（离下一次技能释放还需"
            << setw(2) << A.Cd << "秒）" << setw(6) << "|" << endl;
    }
    else if (A.Cd <= 0 && A.skill != 0)
    {
        cout << "（按空格释放技能）" << "                               |" << endl;
    }
    else cout << "                                                 |" << endl;
    cout << "|得分：" << left << setw(10) << A.score << "等级：" << setw(21) << A.level << left << setw(7) << "金钱：" << setw(14) << A.money << left << setw(10);
    if (level != 0 && level != -1)cout << "剩余击杀数：" << setw(3) << A.needKill_kill - A.kill << right << setw(50) << "|" << endl;
    else cout << "                                                                |" << endl;;
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
}
void PrintHp(const person& p)
{
    SetColor(4);
    for (int i = 1; i <= p.Hp; ++i)
    {
        std::printf("血量");
    }SetColor();
    for (int i = p.Hp * 2 + 1; i <= 65; ++i)
    {
        std::printf("  ");
    }
    std::printf("\n");

}
void printWin()
{
    StopStageModeBossBGM();
    PlayWinBGM();
    system("cls");
    gotoxy(0, 17);
    cout << "                                  最终，你来到了一座古老的地堡，发现文字之王已经等候多时。" << endl; Sleep(2000);
    cout << "                         在与文字之王的交谈中，你学会了如何创造一个可以让人们和平共处的世界的方法。" << endl; Sleep(2000);
    cout << "                 回到大陆的另一端，你用文字之王教给你的方法，让所有人都学会了使用文字，并创造了一个和平共处的世界。" << endl; Sleep(2000);
    cout << "                           你成为了一个英雄，被人们铭记在心中，而这个古老的世界也因为你而变得更加美好。" << endl; cout << endl << endl; Sleep(2000);
    cout << "                                                          按P键回到村庄 ";
    while (1) {
        if (GetAsyncKeyState('P')) { StopWinBGM(); PlayTownAndShopBGM(); break; }
    }

}
void printHuangHp(const Huang h[])
{
    std::printf("\n");
    SetColor(5);
    for (int i = 1; i <= h[0].Hp; ++i)
    {
        std::printf("血");
    }SetColor();
    for (int i = h[0].Hp + 1; i <= 65; ++i)
    {
        std::printf("  ");
    }
}
void printStateEndless(person& p, int level)
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|HP：  " << left << setw(3) << p.Hp << "/" << left << setw(6) << p.limit << right << setw(9) << "当前武器：" << p.weaponChange(p.weaponUsing) << setw(10) << "（按R切换）"
        << right << setw(10) << "武器槽：" << p.weaponChange(p.weapon01) << "," << p.weaponChange(p.weapon02) << setw(10) << "技能：" << p.skillChange(p.skill);
    if (p.Cd > 0 && p.skill != 0)
    {
        cout << "（按空格释放）：" << "（离下一次技能释放还需"
            << setw(2) << p.Cd << "秒）" << setw(6) << "|" << endl;
    }
    else if (p.Cd <= 0 && p.skill != 0)
    {
        cout << "（按空格释放技能）" << "                               |" << endl;
    }
    else cout << "                                                 |" << endl;
    cout << "|得分：" << left << setw(10) << p.score << "等级：" << setw(21) << p.level << left << setw(7) << "金钱：" << setw(14) << p.money << "最高分：" << setw(14) << p.hightest_score << right << setw(43) << "|" << endl;
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
}
void printStatemultiplayer(person A, person B, int level)
{
    cout << "                                 +----------------------------------------------------------------------------------+" << endl;
    cout << "                                 |玩家一 HP：  " << left << setw(3) << A.Hp << "/" << left << setw(6) << 10 << right << setw(9) << "当前武器：" << A.weaponChange(A.weaponUsing) << setw(8) << "（按E切换）"
        << right << setw(10) << "武器槽：" << A.weaponChange(A.weapon01) << "," << A.weaponChange(A.weapon02) << setw(16) << "|" << endl;
    cout << "                                 |玩家二 HP：  " << left << setw(3) << B.Hp << "/" << left << setw(6) << 10 << right << setw(9) << "当前武器：" << B.weaponChange(B.weaponUsing) << setw(8) << "（按6切换）"
        << right << setw(10) << "武器槽：" << B.weaponChange(B.weapon01) << "," << B.weaponChange(B.weapon02) << setw(16) << "|" << endl;
    cout << "                                 +----------------------------------------------------------------------------------+" << endl;
}
void printIntroduction()
{
    cout << "你来到了一个充满文字的世界，眼前出现的是一个古老的村庄，"
        << "村子一直口口相传一个古老的传说：传说中有一个叫做“文字之王”的人，"
        << "他掌握了所有的文字，并可以让人们使用这些文字来创造一个美好的世界。"
        << "于是，你决定前往大陆的另一端，去寻找这个文字之王。"
        << "根据村里老人的指引，你来到了村子里的入口。你惊奇地发现村子里的入口通向一个地牢。"
        << "在旅途中，你将遇到各种各样的挑战和障碍，比如要避开危险的陷阱，还要与邪恶的敌人进行战斗。"
        << "但你可以通过与敌人的战斗来获取新的武器和技能";
    cout << endl; cout << endl;
    SetColor(13);
    cout << "单人模式游戏键位介绍：" << endl;
    SetColor(7);
    cout << "1.WASD：用于控制角色移动" << endl;
    cout << "2.方向键：用于控制角色的射击" << endl;
    cout << "3.R键：切换角色装备" << endl;
    cout << "4.空格键:释放技能" << endl;
    SetColor(12);
    cout << "敌人介绍：";
    SetColor(7);
    cout << "敌人的颜色代表它目前的生命值,生命值的颜色从低到高为：";
    for (int i = 1; i <= 10; i++)
    {
        SetColor(i);
        cout << i << " ";
    }
    SetColor(7);
    cout << endl;
    cout << "1.兵：最普通的小兵，血量最低，没有固定目标" << endl;
    cout << "2.卒：加强版小兵，血量相比兵有一定提升" << endl;
    cout << "3.敌：比卒在血量和伤害上有一定提升，会主动靠近玩家" << endl;
    cout << "4.王：血量和伤害有大幅提高，可以向四周发射子弹，会主动靠近玩家" << endl;
    cout << "5.皇：最终Boss,血量和伤害和攻速有大幅提高，可以向四周发射子弹，会主动靠近玩家" << endl;
    SetColor(14);
    cout << "武器介绍：" << endl;
    SetColor(7);
    cout << "雪弦，润泽，折镜，盈焰，碧芒" << endl << "详细介绍可进入商店查看" << endl;
    SetColor(1);
    cout << "技能介绍：" << endl;
    SetColor(7);
    cout << "炮台，护盾，全图冲击"
        << endl << "详细介绍可进入商店查看" << endl;
    SetColor(6);
    cout << "模式介绍：" << endl;  SetColor();
    cout << "1.闯关模式：该模式是游戏的主要模式，玩家需要消灭一定量的敌人并在第五关消灭Boss以获得最终胜利，消灭Boss后可解锁困难闯关模式。"
        << endl << "2.无尽模式：玩家需要在有限的生命值下消灭尽可能多的敌人，从而获取金钱和获得分数，向着更高的分数而战斗吧！" << endl
        << "3.对战模式：该模式是一种可以同时支持两名玩家在没有技能，武器一样的情况下进行对战的模式。" << endl;
    SetColor(10);
    cout << "对战模式：" << endl;
    SetColor(7);
    cout << "玩家1 WASD：用于控制角色移动。GHJY：用于控制角色的射击 E：切换角色装备。" << endl
        << "玩家2 方向键：用于控制角色移动。1235：用于控制角色的射击 6：切换角色装备。" << endl;
    cout << "玩家一控制的角色为“我”，玩家二控制的角色为“他”" << endl;
    SetColor(12);
    cout << "角色属性介绍：" << endl;
    SetColor();
    cout << "每击杀一个敌人会获得一定金钱、分数与经验值，经验值到达一定数值会提升角色等级，每升一级角色最大生命值会增加，等级最高为10级" << endl;
    SetColor(11);
    cout << "补充说明：" << endl;  SetColor();
    cout << "1.打死一个敌人有概率会掉出一个“药”，捡起它可以回复两点血量" << endl;
    cout << "2.状态栏下方的血条代表玩家生命值，在boss战中地图下方血条代表boss生命值，多人模式上方血条为玩家一生命值，下方血条为玩家二生命值" << endl;
    cout << "3.在商店购买过的东西价格会变为0，购买武器会换掉当前正在使用的武器" << endl;
    cout << "4.在村庄的路上有很多小草，请尽量不要踩到它们，踩到了它们会死掉的QAQ" << endl;
    cout << "5.村庄的三个洞从上往下分别为 闯关模式 无尽模式 对战模式 ,不要走错了哦" << endl;
    SetColor(9); cout << "                                                                                 按P返回标题"; SetColor();
}

void refreshMapFight(string map[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Medicine medicine[], Battery battery, Buttet buttet[], emenyButtet emenybuttet[], Wave wave[], Laser laser[], PassHole& passHole)
{
    if (passHole.alive == 1)map[passHole.hang][passHole.lie] = "洞";
    if (battery.alive == 1)map[battery.hang][battery.lie] = "炮";
    //for (int i = 0; i < Hole::num; ++i) { map[hole[i].hang][hole[i].lie] = "洞"; }
    for (int i = 0; i < Box::num; ++i) { if (box[i].alive == 1)map[box[i].hang][box[i].lie] = "箱"; }
    for (int i = 0; i < Fire::num; ++i) { if(map[fire[i].hang][fire[i].lie]!="冲"&& map[fire[i].hang][fire[i].lie] != "击"&& map[fire[i].hang][fire[i].lie] != "波"&& map[fire[i].hang][fire[i].lie] != "光" && map[fire[i].hang][fire[i].lie] != "弹")map[fire[i].hang][fire[i].lie] = "火"; }
    for (int i = 0; i < Thorn::num; ++i) { if (map[thorn[i].hang][thorn[i].lie] != "冲" && map[thorn[i].hang][thorn[i].lie] != "击" && map[thorn[i].hang][thorn[i].lie] != "波" && map[thorn[i].hang][thorn[i].lie] != "光" && map[thorn[i].hang][thorn[i].lie] != "弹")map[thorn[i].hang][thorn[i].lie] = "刺"; }
    for (int i = 0; i < Medicine::num; ++i) { if (medicine[i].alive == 1)map[medicine[i].hang][medicine[i].lie] = "药"; }
    for (int i = 0; i < Bin::num; ++i) { if (b[i].alive == 1)map[b[i].hang][b[i].lie] = "兵"; }
    for (int i = 0; i < Zu::num; ++i) { if (z[i].alive == 1)map[z[i].hang][z[i].lie] = "卒"; }
    for (int i = 0; i < Di::num; ++i) { if (d[i].alive == 1)map[d[i].hang][d[i].lie] = "敌"; }
    for (int i = 0; i < Wang::num; ++i) { if (w[i].alive == 1)map[w[i].hang][w[i].lie] = "王"; }
    for (int i = 0; i < Huang::num; ++i) { if (h[i].alive == 1)map[h[i].hang][h[i].lie] = "皇"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet[i].alive == 1)map[buttet[i].hang][buttet[i].lie] = "弹"; }
    for (int i = 0; i < emenyButtet::num; ++i) { if (emenybuttet[i].alive == 1)map[emenybuttet[i].hang][emenybuttet[i].lie] = "弹"; }

    map[p.hang][p.lie] = "我";

}
void refeshMapMultiplayer(string map[][65], person& p, person& p2, Box box[], Fire fire[], Thorn thorn[], Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[])
{
    for (int i = 0; i < Box::num; ++i) { if (box[i].alive == 1)map[box[i].hang][box[i].lie] = "箱"; }
    for (int i = 0; i < Fire::num; ++i) { map[fire[i].hang][fire[i].lie] = "火"; }
    for (int i = 0; i < Thorn::num; ++i) { map[thorn[i].hang][thorn[i].lie] = "刺"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet[i].alive == 1)map[buttet[i].hang][buttet[i].lie] = "弹"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet02[i].alive == 1)map[buttet02[i].hang][buttet02[i].lie] = "弹"; }

    for (int i = 0; i < Wave::num; ++i)
    {
        if (wave[i].alive == 1)
        {
            if (wave[i].dir == 1)
            {
                map[wave[i].hang][wave[i].lie] = "击"; if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石")map[wave[i].hang + 1][wave[i].lie - 1] = "冲";
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石")map[wave[i].hang + 1][wave[i].lie + 1] = "波";
            }
            if (wave[i].dir == 2)
            {
                map[wave[i].hang][wave[i].lie] = "击"; if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石")map[wave[i].hang - 1][wave[i].lie - 1] = "冲";
                if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石")map[wave[i].hang - 1][wave[i].lie + 1] = "波";
            }
            if (wave[i].dir == 3)
            {
                map[wave[i].hang][wave[i].lie] = "击"; if (map[wave[i].hang - 1][wave[i].lie + 1] != "墙" && map[wave[i].hang - 1][wave[i].lie + 1] != "石") map[wave[i].hang - 1][wave[i].lie + 1] = "冲";
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "墙" && map[wave[i].hang + 1][wave[i].lie + 1] != "石")map[wave[i].hang + 1][wave[i].lie + 1] = "波";
            }
            if (wave[i].dir == 4)
            {
                map[wave[i].hang][wave[i].lie] = "击"; if (map[wave[i].hang - 1][wave[i].lie - 1] != "墙" && map[wave[i].hang - 1][wave[i].lie - 1] != "石") map[wave[i].hang - 1][wave[i].lie - 1] = "冲";
                if (map[wave[i].hang + 1][wave[i].lie - 1] != "墙" && map[wave[i].hang + 1][wave[i].lie - 1] != "石")map[wave[i].hang + 1][wave[i].lie - 1] = "波";
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        if (wave02[i].alive == 1)
        {
            if (wave02[i].dir == 1)
            {
                map[wave02[i].hang][wave02[i].lie] = "击"; if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "石")map[wave02[i].hang + 1][wave02[i].lie - 1] = "冲";
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "石")map[wave02[i].hang + 1][wave02[i].lie + 1] = "波";
            }
            if (wave02[i].dir == 2)
            {
                map[wave02[i].hang][wave02[i].lie] = "击"; if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "石")map[wave02[i].hang - 1][wave02[i].lie - 1] = "冲";
                if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "石")map[wave02[i].hang - 1][wave02[i].lie + 1] = "波";
            }
            if (wave02[i].dir == 3)
            {
                map[wave02[i].hang][wave02[i].lie] = "击"; if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "石") map[wave02[i].hang - 1][wave02[i].lie + 1] = "冲";
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "石")map[wave02[i].hang + 1][wave02[i].lie + 1] = "波";
            }
            if (wave02[i].dir == 4)
            {
                map[wave02[i].hang][wave02[i].lie] = "击"; if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "石") map[wave02[i].hang - 1][wave02[i].lie - 1] = "冲";
                if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "墙" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "石")map[wave02[i].hang + 1][wave02[i].lie - 1] = "波";
            }
        }
    }
    map[p.hang][p.lie] = "我";
    map[p2.hang][p2.lie] = "他";
}
void refeshMapShop(string mapShop[][65], person* p, Door* door, Buy buy[])
{
    for (int i = 0; i < 8; i++) { mapShop[buy[i].hang][buy[i].lie] = "买"; }
    mapShop[p->hang][p->lie] = "我";
    mapShop[door[1].hang][door[1].lie] = "门";
}
void refeshMap(string mapStart[][65], startHole StartHole[], person* p, Door* door)
{
    mapStart[p->hang][p->lie] = "我";
    mapStart[door[0].hang][door[0].lie] = "门";
    for (int i = 0; i < 3; i++)
    {
        mapStart[StartHole[i].hang][StartHole[i].lie] = "洞";
    }
}