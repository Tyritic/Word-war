#pragma once

#include<iostream>
#include<string>
using namespace std;

class AbstractItem
{
public:AbstractItem();

      int hang, lie;
};

class Buy :public AbstractItem
{
public:Buy();

      int price;
};
class Fire :public AbstractItem
{
public:static int num;
};
class Thorn :public AbstractItem
{
public:static int num;
};
class Box :public AbstractItem
{
public:
    Box();
    static int num;
    bool alive;
};
class Medicine :public AbstractItem
{
public:
    Medicine();
    static int num;
    bool alive;
};
//在村庄的洞
class startHole :public AbstractItem
{
public:
};
class PassHole :public AbstractItem
{
public:
    PassHole();
    bool alive;
};
class Hole :public AbstractItem
{
public:static int num;
};
class Door :public AbstractItem
{
public:
};

//各种子弹
class Buttet
{
public:Buttet();

      void move(string map[][65], Box box[]);

      int hang, lie;
      bool alive;
      int speed; int dir; static int num;
};
class Buttet02 : public Buttet
{

};
class Wave
{
public:
    Wave();
    void move(string map[][65], Box box[]);

    int hang, lie;
    bool alive;
    int speed; int dir;//1`4代表上下左右
    static int num;
};
class Wave02 :public Wave
{

};
class Laser
{
public:
    Laser();

    void move(string map[][65], Box box[]);

    int hang, lie;
    bool alive; int dir;
    static int num;
};
class emenyButtet
{
public:emenyButtet();

      void move(string map[][65]);

      int hang, lie;
      bool alive;
      int speed;
      int damage; int dir;
      static int num;
};

class Battery
{
public:Battery();

      void shoot(Buttet buttet[]);

      int hang, lie;
      bool alive;
};

class person
{
public:
    person();
    void countdown();
    string weaponChange(int id);
    string skillChange(int id);

    void move(string map[][65]);
    void shootButtet(Buttet buttet[]);
    void shootButtetPlus(Buttet buttet[]);
    void shootWave(Wave wave[]);
    void shootWavePlus(Wave wave[]);
    void shootLaser(Laser laser[]);
    void placeBattery(Battery& battery, string map[][65]);
    void shield(bool& flag);
    void fullMapDamage(bool& flag);

    void player01ShootWave(Wave wave[]);
    void player02ShootWave(Wave02 wave[]);
    void player01ShootButtet(Buttet buttet[]);
    void player02ShootButtet(Buttet02 buttet[]);
    void player02Move(string map[][65]);
    void PlayZheJing();
    void PlayBiMang();
    void PlayRunZe();
    void PlayYingyan();
    int level;//等级，最高10
    int money, score, hightest_score;
    int kill;//当前关卡击杀数
    int needKill_kill;
    bool alive;
    int Hp; int originalHp;
    int hang, lie;//位置坐标 行 列
    int skill;//技能 用数字1~3代替
    int weaponUsing;//正在使用的武器
    int weaponId;//正在使用weapon01还是02
    int weapon01;
    int weapon02;//用数字代号（1~5）代表武器
    int weaponTemp01, weapontemp02;
    bool weaponAllow;//当前是否允许使用武器
    int speed;//越小越快
    int shootSpeed;//射速
    int damage;
    bool difficultAllow; //是否有进入困难模式的权力
    int Cd;//技能冷却
    int limit;//血量上限
    int Exp; //经验值
};
class Emeny
{
public:
    Emeny();
    void move(string map[][65]);
    void shoot(person& p, emenyButtet emenybuttet[]);

    bool alive;
    int hang, lie;
};
class Bin :public Emeny
{
public:
    Bin();
    void creat(Hole hole[]);
    void shoot(person& p, emenyButtet emenybuttet[],int emenyButtetSpeed);
    int Hp; int speed; int shootSpeed;
    static int num;
};
class Zu : public Emeny
{
public:
    Zu();
    void creat(Hole hole[]);
    void shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed);
    int Hp; int speed; int shootSpeed;
    static int num;
};
class Di :public Emeny
{
public:
    Di();
    void creat(Hole hole[]);
    void shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed);
    void move(string map[][65], person& p);

    int Hp; int speed; int shootSpeed;
    static int num;
};
class Wang : public Emeny
{
public:
    Wang();
    void creat(Hole hole[]);
    void shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed);
    void move(string map[][65], person& p);

    int Hp; int speed; int shootSpeed;
    static int num;
};
class Huang : public Emeny
{
public:
    Huang();
    void creat(Hole hole[]);
    void shoot(person& p, emenyButtet emenybuttet[], int emenyButtetSpeed);
    void move(string map[][65], person& p);
    void PlayShoot();
    int Hp; int speed; int shootSpeed;
    static int num;
};
