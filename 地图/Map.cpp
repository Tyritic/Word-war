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
            if (map[i][j] == "һ")
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
            if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf("��"); }
            else if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf("��"); }
            else if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf("��"); }
        }
    }
}
void printMapFight(string map[][65], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Buttet buttet[], emenyButtet emenybuttet[])
{

    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
        {
            if (map[i][j] == "һ")
            {
                std::printf("%s", "  ");
                continue;
            }
            else if (map[i][j] == "��") { SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "ҩ") { SetColor(10); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(11); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") {
                SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            else if (map[i][j] == "��") {
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
            if (map[i][j] == "��") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(12); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(11); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "ҩ") { SetColor(10); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
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
            if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
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
            if (map[i][j] == "һ")
            {
                std::printf("%s", "  ");
                continue;
            }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(11); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") {
                SetColor(6); std::printf("%s", map[i][j].c_str()); SetColor(); continue;
            }
            else if (map[i][j] == "��") {
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
            if (map[i][j] == "��") { SetColor(12); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(11); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(6); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            else if (map[i][j] == "��") { SetColor(13); gotoxy(2 * j, i + 4); std::printf("%s", map[i][j].c_str()); SetColor(); continue; }
            if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
            if (map[i][j] == "��") { gotoxy(2 * j, i + 4); printf(map[i][j].c_str()); }
        A:;
        }

    }
}
void Printstate(person A, int level)
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|HP��  " << left << setw(3) << A.Hp << "/" << left << setw(6) << A.limit << right << setw(9) << "��ǰ������" << A.weaponChange(A.weaponUsing) << setw(10) << "����R�л���" << right << setw(10) << "�����ۣ�" << A.weaponChange(A.weapon01) << "," << A.weaponChange(A.weapon02) << setw(10) << "���ܣ�" << A.skillChange(A.skill);
    if (A.Cd > 0 && A.skill != 0)
    {
        cout << "�����ո��ͷţ���" << "������һ�μ����ͷŻ���"
            << setw(2) << A.Cd << "�룩" << setw(6) << "|" << endl;
    }
    else if (A.Cd <= 0 && A.skill != 0)
    {
        cout << "�����ո��ͷż��ܣ�" << "                               |" << endl;
    }
    else cout << "                                                 |" << endl;
    cout << "|�÷֣�" << left << setw(10) << A.score << "�ȼ���" << setw(21) << A.level << left << setw(7) << "��Ǯ��" << setw(14) << A.money << left << setw(10);
    if (level != 0 && level != -1)cout << "ʣ���ɱ����" << setw(3) << A.needKill_kill - A.kill << right << setw(50) << "|" << endl;
    else cout << "                                                                |" << endl;;
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
}
void PrintHp(const person& p)
{
    SetColor(4);
    for (int i = 1; i <= p.Hp; ++i)
    {
        std::printf("Ѫ��");
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
    cout << "                                  ���գ���������һ�����ϵĵر�����������֮���Ѿ��Ⱥ��ʱ��" << endl; Sleep(2000);
    cout << "                         ��������֮���Ľ�̸�У���ѧ������δ���һ�����������Ǻ�ƽ����������ķ�����" << endl; Sleep(2000);
    cout << "                 �ص���½����һ�ˣ���������֮���̸���ķ������������˶�ѧ����ʹ�����֣���������һ����ƽ���������硣" << endl; Sleep(2000);
    cout << "                           ���Ϊ��һ��Ӣ�ۣ����������������У���������ϵ�����Ҳ��Ϊ�����ø������á�" << endl; cout << endl << endl; Sleep(2000);
    cout << "                                                          ��P���ص���ׯ ";
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
        std::printf("Ѫ");
    }SetColor();
    for (int i = h[0].Hp + 1; i <= 65; ++i)
    {
        std::printf("  ");
    }
}
void printStateEndless(person& p, int level)
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|HP��  " << left << setw(3) << p.Hp << "/" << left << setw(6) << p.limit << right << setw(9) << "��ǰ������" << p.weaponChange(p.weaponUsing) << setw(10) << "����R�л���"
        << right << setw(10) << "�����ۣ�" << p.weaponChange(p.weapon01) << "," << p.weaponChange(p.weapon02) << setw(10) << "���ܣ�" << p.skillChange(p.skill);
    if (p.Cd > 0 && p.skill != 0)
    {
        cout << "�����ո��ͷţ���" << "������һ�μ����ͷŻ���"
            << setw(2) << p.Cd << "�룩" << setw(6) << "|" << endl;
    }
    else if (p.Cd <= 0 && p.skill != 0)
    {
        cout << "�����ո��ͷż��ܣ�" << "                               |" << endl;
    }
    else cout << "                                                 |" << endl;
    cout << "|�÷֣�" << left << setw(10) << p.score << "�ȼ���" << setw(21) << p.level << left << setw(7) << "��Ǯ��" << setw(14) << p.money << "��߷֣�" << setw(14) << p.hightest_score << right << setw(43) << "|" << endl;
    cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
}
void printStatemultiplayer(person A, person B, int level)
{
    cout << "                                 +----------------------------------------------------------------------------------+" << endl;
    cout << "                                 |���һ HP��  " << left << setw(3) << A.Hp << "/" << left << setw(6) << 10 << right << setw(9) << "��ǰ������" << A.weaponChange(A.weaponUsing) << setw(8) << "����E�л���"
        << right << setw(10) << "�����ۣ�" << A.weaponChange(A.weapon01) << "," << A.weaponChange(A.weapon02) << setw(16) << "|" << endl;
    cout << "                                 |��Ҷ� HP��  " << left << setw(3) << B.Hp << "/" << left << setw(6) << 10 << right << setw(9) << "��ǰ������" << B.weaponChange(B.weaponUsing) << setw(8) << "����6�л���"
        << right << setw(10) << "�����ۣ�" << B.weaponChange(B.weapon01) << "," << B.weaponChange(B.weapon02) << setw(16) << "|" << endl;
    cout << "                                 +----------------------------------------------------------------------------------+" << endl;
}
void printIntroduction()
{
    cout << "��������һ���������ֵ����磬��ǰ���ֵ���һ�����ϵĴ�ׯ��"
        << "����һֱ�ڿ��ഫһ�����ϵĴ�˵����˵����һ������������֮�������ˣ�"
        << "�����������е����֣�������������ʹ����Щ����������һ�����õ����硣"
        << "���ǣ������ǰ����½����һ�ˣ�ȥѰ���������֮����"
        << "���ݴ������˵�ָ�����������˴��������ڡ��㾪��ط��ִ���������ͨ��һ�����Ρ�"
        << "����;�У��㽫�������ָ�������ս���ϰ�������Ҫ�ܿ�Σ�յ����壬��Ҫ��а��ĵ��˽���ս����"
        << "�������ͨ������˵�ս������ȡ�µ������ͼ���";
    cout << endl; cout << endl;
    SetColor(13);
    cout << "����ģʽ��Ϸ��λ���ܣ�" << endl;
    SetColor(7);
    cout << "1.WASD�����ڿ��ƽ�ɫ�ƶ�" << endl;
    cout << "2.����������ڿ��ƽ�ɫ�����" << endl;
    cout << "3.R�����л���ɫװ��" << endl;
    cout << "4.�ո��:�ͷż���" << endl;
    SetColor(12);
    cout << "���˽��ܣ�";
    SetColor(7);
    cout << "���˵���ɫ������Ŀǰ������ֵ,����ֵ����ɫ�ӵ͵���Ϊ��";
    for (int i = 1; i <= 10; i++)
    {
        SetColor(i);
        cout << i << " ";
    }
    SetColor(7);
    cout << endl;
    cout << "1.��������ͨ��С����Ѫ����ͣ�û�й̶�Ŀ��" << endl;
    cout << "2.�䣺��ǿ��С����Ѫ����ȱ���һ������" << endl;
    cout << "3.�У�������Ѫ�����˺�����һ���������������������" << endl;
    cout << "4.����Ѫ�����˺��д����ߣ����������ܷ����ӵ����������������" << endl;
    cout << "5.�ʣ�����Boss,Ѫ�����˺��͹����д����ߣ����������ܷ����ӵ����������������" << endl;
    SetColor(14);
    cout << "�������ܣ�" << endl;
    SetColor(7);
    cout << "ѩ�ң������۾���ӯ�棬��â" << endl << "��ϸ���ܿɽ����̵�鿴" << endl;
    SetColor(1);
    cout << "���ܽ��ܣ�" << endl;
    SetColor(7);
    cout << "��̨�����ܣ�ȫͼ���"
        << endl << "��ϸ���ܿɽ����̵�鿴" << endl;
    SetColor(6);
    cout << "ģʽ���ܣ�" << endl;  SetColor();
    cout << "1.����ģʽ����ģʽ����Ϸ����Ҫģʽ�������Ҫ����һ�����ĵ��˲��ڵ��������Boss�Ի������ʤ��������Boss��ɽ������Ѵ���ģʽ��"
        << endl << "2.�޾�ģʽ�������Ҫ�����޵�����ֵ�����𾡿��ܶ�ĵ��ˣ��Ӷ���ȡ��Ǯ�ͻ�÷��������Ÿ��ߵķ�����ս���ɣ�" << endl
        << "3.��սģʽ����ģʽ��һ�ֿ���ͬʱ֧�����������û�м��ܣ�����һ��������½��ж�ս��ģʽ��" << endl;
    SetColor(10);
    cout << "��սģʽ��" << endl;
    SetColor(7);
    cout << "���1 WASD�����ڿ��ƽ�ɫ�ƶ���GHJY�����ڿ��ƽ�ɫ����� E���л���ɫװ����" << endl
        << "���2 ����������ڿ��ƽ�ɫ�ƶ���1235�����ڿ��ƽ�ɫ����� 6���л���ɫװ����" << endl;
    cout << "���һ���ƵĽ�ɫΪ���ҡ�����Ҷ����ƵĽ�ɫΪ������" << endl;
    SetColor(12);
    cout << "��ɫ���Խ��ܣ�" << endl;
    SetColor();
    cout << "ÿ��ɱһ�����˻���һ����Ǯ�������뾭��ֵ������ֵ����һ����ֵ��������ɫ�ȼ���ÿ��һ����ɫ�������ֵ�����ӣ��ȼ����Ϊ10��" << endl;
    SetColor(11);
    cout << "����˵����" << endl;  SetColor();
    cout << "1.����һ�������и��ʻ����һ����ҩ�������������Իظ�����Ѫ��" << endl;
    cout << "2.״̬���·���Ѫ�������������ֵ����bossս�е�ͼ�·�Ѫ������boss����ֵ������ģʽ�Ϸ�Ѫ��Ϊ���һ����ֵ���·�Ѫ��Ϊ��Ҷ�����ֵ" << endl;
    cout << "3.���̵깺����Ķ����۸���Ϊ0�����������ỻ����ǰ����ʹ�õ�����" << endl;
    cout << "4.�ڴ�ׯ��·���кܶ�С�ݣ��뾡����Ҫ�ȵ����ǣ��ȵ������ǻ�������QAQ" << endl;
    cout << "5.��ׯ���������������·ֱ�Ϊ ����ģʽ �޾�ģʽ ��սģʽ ,��Ҫ�ߴ���Ŷ" << endl;
    SetColor(9); cout << "                                                                                 ��P���ر���"; SetColor();
}

void refreshMapFight(string map[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], Medicine medicine[], Battery battery, Buttet buttet[], emenyButtet emenybuttet[], Wave wave[], Laser laser[], PassHole& passHole)
{
    if (passHole.alive == 1)map[passHole.hang][passHole.lie] = "��";
    if (battery.alive == 1)map[battery.hang][battery.lie] = "��";
    //for (int i = 0; i < Hole::num; ++i) { map[hole[i].hang][hole[i].lie] = "��"; }
    for (int i = 0; i < Box::num; ++i) { if (box[i].alive == 1)map[box[i].hang][box[i].lie] = "��"; }
    for (int i = 0; i < Fire::num; ++i) { if(map[fire[i].hang][fire[i].lie]!="��"&& map[fire[i].hang][fire[i].lie] != "��"&& map[fire[i].hang][fire[i].lie] != "��"&& map[fire[i].hang][fire[i].lie] != "��" && map[fire[i].hang][fire[i].lie] != "��")map[fire[i].hang][fire[i].lie] = "��"; }
    for (int i = 0; i < Thorn::num; ++i) { if (map[thorn[i].hang][thorn[i].lie] != "��" && map[thorn[i].hang][thorn[i].lie] != "��" && map[thorn[i].hang][thorn[i].lie] != "��" && map[thorn[i].hang][thorn[i].lie] != "��" && map[thorn[i].hang][thorn[i].lie] != "��")map[thorn[i].hang][thorn[i].lie] = "��"; }
    for (int i = 0; i < Medicine::num; ++i) { if (medicine[i].alive == 1)map[medicine[i].hang][medicine[i].lie] = "ҩ"; }
    for (int i = 0; i < Bin::num; ++i) { if (b[i].alive == 1)map[b[i].hang][b[i].lie] = "��"; }
    for (int i = 0; i < Zu::num; ++i) { if (z[i].alive == 1)map[z[i].hang][z[i].lie] = "��"; }
    for (int i = 0; i < Di::num; ++i) { if (d[i].alive == 1)map[d[i].hang][d[i].lie] = "��"; }
    for (int i = 0; i < Wang::num; ++i) { if (w[i].alive == 1)map[w[i].hang][w[i].lie] = "��"; }
    for (int i = 0; i < Huang::num; ++i) { if (h[i].alive == 1)map[h[i].hang][h[i].lie] = "��"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet[i].alive == 1)map[buttet[i].hang][buttet[i].lie] = "��"; }
    for (int i = 0; i < emenyButtet::num; ++i) { if (emenybuttet[i].alive == 1)map[emenybuttet[i].hang][emenybuttet[i].lie] = "��"; }

    map[p.hang][p.lie] = "��";

}
void refeshMapMultiplayer(string map[][65], person& p, person& p2, Box box[], Fire fire[], Thorn thorn[], Buttet buttet[], Buttet02 buttet02[], Wave wave[], Wave02 wave02[])
{
    for (int i = 0; i < Box::num; ++i) { if (box[i].alive == 1)map[box[i].hang][box[i].lie] = "��"; }
    for (int i = 0; i < Fire::num; ++i) { map[fire[i].hang][fire[i].lie] = "��"; }
    for (int i = 0; i < Thorn::num; ++i) { map[thorn[i].hang][thorn[i].lie] = "��"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet[i].alive == 1)map[buttet[i].hang][buttet[i].lie] = "��"; }
    for (int i = 0; i < Buttet::num; ++i) { if (buttet02[i].alive == 1)map[buttet02[i].hang][buttet02[i].lie] = "��"; }

    for (int i = 0; i < Wave::num; ++i)
    {
        if (wave[i].alive == 1)
        {
            if (wave[i].dir == 1)
            {
                map[wave[i].hang][wave[i].lie] = "��"; if (map[wave[i].hang + 1][wave[i].lie - 1] != "ǽ" && map[wave[i].hang + 1][wave[i].lie - 1] != "ʯ")map[wave[i].hang + 1][wave[i].lie - 1] = "��";
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "ǽ" && map[wave[i].hang + 1][wave[i].lie + 1] != "ʯ")map[wave[i].hang + 1][wave[i].lie + 1] = "��";
            }
            if (wave[i].dir == 2)
            {
                map[wave[i].hang][wave[i].lie] = "��"; if (map[wave[i].hang - 1][wave[i].lie - 1] != "ǽ" && map[wave[i].hang - 1][wave[i].lie - 1] != "ʯ")map[wave[i].hang - 1][wave[i].lie - 1] = "��";
                if (map[wave[i].hang - 1][wave[i].lie + 1] != "ǽ" && map[wave[i].hang - 1][wave[i].lie + 1] != "ʯ")map[wave[i].hang - 1][wave[i].lie + 1] = "��";
            }
            if (wave[i].dir == 3)
            {
                map[wave[i].hang][wave[i].lie] = "��"; if (map[wave[i].hang - 1][wave[i].lie + 1] != "ǽ" && map[wave[i].hang - 1][wave[i].lie + 1] != "ʯ") map[wave[i].hang - 1][wave[i].lie + 1] = "��";
                if (map[wave[i].hang + 1][wave[i].lie + 1] != "ǽ" && map[wave[i].hang + 1][wave[i].lie + 1] != "ʯ")map[wave[i].hang + 1][wave[i].lie + 1] = "��";
            }
            if (wave[i].dir == 4)
            {
                map[wave[i].hang][wave[i].lie] = "��"; if (map[wave[i].hang - 1][wave[i].lie - 1] != "ǽ" && map[wave[i].hang - 1][wave[i].lie - 1] != "ʯ") map[wave[i].hang - 1][wave[i].lie - 1] = "��";
                if (map[wave[i].hang + 1][wave[i].lie - 1] != "ǽ" && map[wave[i].hang + 1][wave[i].lie - 1] != "ʯ")map[wave[i].hang + 1][wave[i].lie - 1] = "��";
            }
        }
    }
    for (int i = 0; i < Wave::num; ++i)
    {
        if (wave02[i].alive == 1)
        {
            if (wave02[i].dir == 1)
            {
                map[wave02[i].hang][wave02[i].lie] = "��"; if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "ǽ" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "ʯ")map[wave02[i].hang + 1][wave02[i].lie - 1] = "��";
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "ǽ" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "ʯ")map[wave02[i].hang + 1][wave02[i].lie + 1] = "��";
            }
            if (wave02[i].dir == 2)
            {
                map[wave02[i].hang][wave02[i].lie] = "��"; if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "ǽ" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "ʯ")map[wave02[i].hang - 1][wave02[i].lie - 1] = "��";
                if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "ǽ" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "ʯ")map[wave02[i].hang - 1][wave02[i].lie + 1] = "��";
            }
            if (wave02[i].dir == 3)
            {
                map[wave02[i].hang][wave02[i].lie] = "��"; if (map[wave02[i].hang - 1][wave02[i].lie + 1] != "ǽ" && map[wave02[i].hang - 1][wave02[i].lie + 1] != "ʯ") map[wave02[i].hang - 1][wave02[i].lie + 1] = "��";
                if (map[wave02[i].hang + 1][wave02[i].lie + 1] != "ǽ" && map[wave02[i].hang + 1][wave02[i].lie + 1] != "ʯ")map[wave02[i].hang + 1][wave02[i].lie + 1] = "��";
            }
            if (wave02[i].dir == 4)
            {
                map[wave02[i].hang][wave02[i].lie] = "��"; if (map[wave02[i].hang - 1][wave02[i].lie - 1] != "ǽ" && map[wave02[i].hang - 1][wave02[i].lie - 1] != "ʯ") map[wave02[i].hang - 1][wave02[i].lie - 1] = "��";
                if (map[wave02[i].hang + 1][wave02[i].lie - 1] != "ǽ" && map[wave02[i].hang + 1][wave02[i].lie - 1] != "ʯ")map[wave02[i].hang + 1][wave02[i].lie - 1] = "��";
            }
        }
    }
    map[p.hang][p.lie] = "��";
    map[p2.hang][p2.lie] = "��";
}
void refeshMapShop(string mapShop[][65], person* p, Door* door, Buy buy[])
{
    for (int i = 0; i < 8; i++) { mapShop[buy[i].hang][buy[i].lie] = "��"; }
    mapShop[p->hang][p->lie] = "��";
    mapShop[door[1].hang][door[1].lie] = "��";
}
void refeshMap(string mapStart[][65], startHole StartHole[], person* p, Door* door)
{
    mapStart[p->hang][p->lie] = "��";
    mapStart[door[0].hang][door[0].lie] = "��";
    for (int i = 0; i < 3; i++)
    {
        mapStart[StartHole[i].hang][StartHole[i].lie] = "��";
    }
}