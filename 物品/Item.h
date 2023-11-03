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
//�ڴ�ׯ�Ķ�
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

//�����ӵ�
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
    int speed; int dir;//1`4������������
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
    int level;//�ȼ������10
    int money, score, hightest_score;
    int kill;//��ǰ�ؿ���ɱ��
    int needKill_kill;
    bool alive;
    int Hp; int originalHp;
    int hang, lie;//λ������ �� ��
    int skill;//���� ������1~3����
    int weaponUsing;//����ʹ�õ�����
    int weaponId;//����ʹ��weapon01����02
    int weapon01;
    int weapon02;//�����ִ��ţ�1~5����������
    int weaponTemp01, weapontemp02;
    bool weaponAllow;//��ǰ�Ƿ�����ʹ������
    int speed;//ԽСԽ��
    int shootSpeed;//����
    int damage;
    bool difficultAllow; //�Ƿ��н�������ģʽ��Ȩ��
    int Cd;//������ȴ
    int limit;//Ѫ������
    int Exp; //����ֵ
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
