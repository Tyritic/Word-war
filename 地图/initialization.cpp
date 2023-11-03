#include"initialization.h"
#include"func.h"

using namespace std;

void initMapStart(startHole StartHole[], person* p, Door* door)
{
    StartHole[0].hang = 21; StartHole[0].lie = 49;
    StartHole[1].hang = 24; StartHole[1].lie = 49;
    StartHole[2].hang = 27; StartHole[2].lie = 49;
    p->hang = 23, p->lie = 9;
    door[0].hang = 13; door[0].lie = 26;
}
void initMap01(string map01[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[],bool difficult,int emenyButtetSpeed)
{
    clearKeyCache();
    Bin::num = 10; Zu::num = 10; Di::num = 5; Wang::num = Huang::num = 0;
    Box::num = 4; Fire::num = 59; Thorn::num = 45; Hole::num = 9;
    p.hang = 20; p.lie = 29;
    p.needKill_kill = 1;

    if (difficult == 0) { initEmeny(b, z, d, w, h, emenyButtetSpeed); }
    else if (difficult == 1) { initEnhancedEmeny(b, z, d, w, h, emenyButtetSpeed); p.needKill_kill += 5; Bin::num += 5; Zu::num += 5; Di::num += 2; }

    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;
    for (int i = 0; i < 4; i++) { box[i].hang = 11 + i; box[i].lie = 43; box[i].alive = 1; }//箱子初始化
    //洞初始化
    hole[0].hang = 5; hole[0].lie = 11; hole[1].hang = 4; hole[1].lie = 29; hole[3].hang = 22; hole[3].lie = 11; hole[4].hang = 9; hole[4].lie = 50; hole[2].hang = 29; hole[2].lie = 37;
    hole[5].hang = 11; hole[5].lie = 10; hole[6].hang = 11; hole[6].lie = 32; hole[7].hang = 24; hole[7].lie = 56; hole[8].hang = 32; hole[8].lie = 14;
    for (int i = 0; i < 6; i++) { fire[i].hang = 9 + i; fire[i].lie = 17; }//火的初始化
    for (int i = 0; i < 12; i++) { fire[6 + i].hang = 17 + i; fire[6 + i].lie = 6; }
    for (int i = 0; i < 10; i++) { fire[18 + i].hang = 19 + i; fire[18 + i].lie = 49; }//27
    for (int i = 0; i < 5; i++) { fire[28 + i].hang = 30 + i; fire[28 + i].lie = 33; }//32
    fire[33].hang = fire[34].hang = 34; fire[33].lie = 34; fire[34].lie = 35;
    fire[35].hang = fire[36].hang = 32; fire[35].lie = 58; fire[36].lie = 59;
    fire[37].hang = fire[38].hang = 16; fire[37].lie = 26; fire[38].lie = 32;
    fire[39].hang = fire[40].hang = fire[41].hang = fire[42].hang = 17; fire[39].lie = 24; fire[40].lie = 28; fire[41].lie = 30; fire[42].lie = 34;
    fire[43].hang = fire[44].hang = fire[45].hang = 18; fire[43].lie = 22; fire[44].lie = 29; fire[45].lie = 36;
    fire[46].hang = fire[47].hang = 19; fire[46].lie = 21; fire[47].lie = 37;
    fire[48].hang = fire[49].hang = 20; fire[48].lie = 22; fire[49].lie = 36;
    fire[50].hang = fire[51].hang = 21; fire[50].lie = 23; fire[51].lie = 35;
    fire[52].hang = fire[53].hang = 22; fire[52].lie = 24; fire[53].lie = 34;
    fire[54].hang = fire[55].hang = 23; fire[54].lie = 25; fire[55].lie = 33;
    fire[56].hang = fire[57].hang = 24; fire[56].lie = 27; fire[57].lie = 31;
    fire[58].hang = 25; fire[58].lie = 29;
    //刺初始化
    for (int i = 0; i < 11; i++) { thorn[i].hang = 14; thorn[i].lie = i + 6; }
    for (int i = 0; i < 12; i++) { thorn[i + 11].hang = 3; thorn[i + 11].lie = i + 43; }
    for (int i = 0; i < 11; i++) { thorn[i + 23].hang = 28; thorn[i + 23].lie = i + 7; }
    for (int i = 0; i < 11; i++) { thorn[i + 34].hang = 17 + i; thorn[i + 34].lie = 17; }

}
void initMap02(string map02[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed)
{
    clearKeyCache();
    p.hang = 19; p.lie = 28;
    p.needKill_kill = 1;

    Bin::num = 4; Zu::num = 4; Di::num = 3; Wang::num = Huang::num = 0;
    Box::num = 27; Fire::num = 13; Thorn::num = 15; Hole::num = 6;

    if (difficult == 0) { initEmeny(b, z, d, w, h, emenyButtetSpeed); }
    else if (difficult == 1) { initEnhancedEmeny(b, z, d, w, h, emenyButtetSpeed); p.needKill_kill += 5; Bin::num += 2; Zu::num += 2; Di::num += 1; }

    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;
    hole[0].hang = hole[1].hang = 22; hole[0].lie = 12; hole[1].lie = 44;
    hole[2].hang = hole[3].hang = 30; hole[2].lie = 23; hole[3].lie = 33;
    hole[4].hang = hole[5].hang = 10; hole[4].lie = 23; hole[5].lie = 33;

    box[0].hang = box[1].hang = 19; box[0].lie = 15; box[1].lie = 41;
    for (int i = 0; i < 4; i++) { box[i + 2].hang = 21 + i; box[i + 2].lie = 18; }
    for (int i = 0; i < 4; i++) { box[i + 6].hang = 21 + i; box[i + 6].lie = 38; }
    box[10].hang = box[11].hang = 23; box[10].lie = 23; box[11].lie = 33;
    box[12].hang = box[13].hang = 24; box[12].lie = 24; box[13].lie = 32;
    for (int i = 0; i < 3; i++) { box[14 + i].hang = i + 28; box[14 + i].lie = 28; }
    box[17].hang = box[18].hang = 32; box[17].lie = 21; box[18].lie = 35;
    box[19].hang = box[20].hang = 26; box[19].lie = 15; box[20].lie = 41;
    box[21].hang = box[22].hang = 27; box[21].lie = 15; box[22].lie = 41;
    box[23].hang = box[24].hang = 13; box[23].lie = 23; box[24].lie = 33;
    box[25].hang = box[26].hang = 14; box[25].lie = 22; box[26].lie = 34;

    thorn[0].hang = thorn[1].hang = 19; thorn[0].lie = 14; thorn[1].lie = 16;
    thorn[2].hang = thorn[3].hang = 26; thorn[2].lie = 41; thorn[3].lie = 43;
    thorn[4].hang = thorn[5].hang = 28; thorn[4].lie = 14; thorn[5].lie = 16;
    thorn[6].lie = thorn[7].lie = 28; thorn[6].hang = 31; thorn[7].hang = 32;
    for (int i = 0; i < 4; i++) { thorn[i + 8].hang = 19 + i; thorn[i + 8].lie = 37 - i; }
    for (int i = 0; i < 3; i++) { thorn[i + 12].hang = 25 + i; thorn[i + 12].lie = 25 + i; }

    fire[0].hang = fire[1].hang = 19; fire[0].lie = 40; fire[1].lie = 42;
    fire[2].hang = fire[3].hang = 26; fire[2].lie = 14; fire[3].lie = 16;
    fire[4].hang = fire[5].hang = 28; fire[4].lie = 41; fire[5].lie = 43;
    for (int i = 0; i < 4; i++) { fire[i + 6].hang = 19 + i; fire[i + 6].lie = 19 + i; }
    for (int i = 0; i < 3; i++) { fire[i + 10].hang = 25 + i; fire[i + 10].lie = 31 - i; }

}
void initMap03(string map03[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed)
{
    clearKeyCache();
    Bin::num = 10;
    Zu::num = 10;
    Di::num = 10;
    Wang::num = 2; Huang::num = 0;
    Box::num = 17;
    Fire::num = 34;
    Thorn::num = 41;
    Hole::num = 5;
    p.hang = 3; p.lie = 3;    p.needKill_kill = 1;
    if (difficult == 0) { initEmeny(b, z, d, w, h, emenyButtetSpeed); }
    else if (difficult == 1) { initEnhancedEmeny(b, z, d, w, h, emenyButtetSpeed); p.needKill_kill += 5; Bin::num += 5; Zu::num += 5; Wang::num += 1; Di::num += 2; }

    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;
    hole[0].hang = 5; hole[0].lie = 20;
    hole[1].hang = 5; hole[1].lie = 40;
    hole[2].hang = 17; hole[2].lie = 5;
    hole[3].hang = 31; hole[3].lie = 16;
    hole[4].hang = 31;
    hole[4].lie = 54;

    box[0].hang = 2; box[0].lie = 13;
    box[1].hang = box[0].hang; box[1].lie = 28;
    box[2].hang = 4; box[2].lie = box[0].lie;
    box[3].hang = 5; box[3].lie = 5;
    box[4].hang = 5; box[4].lie = box[2].lie;
    box[5].hang = 6; box[5].lie = box[3].lie;
    box[6].hang = 7; box[6].lie = 32;
    box[7].hang = 7; box[7].lie = box[6].lie + 1;
    box[8].hang = 10; box[8].lie = 46;
    box[9].hang = 13; box[9].lie = 31;
    box[10].hang = 13; box[10].lie = box[9].lie + 1;
    box[11].hang = 23; box[11].lie = 36;
    box[12].hang = 27; box[12].lie = 6;
    box[13].hang = box[12].hang; box[13].lie = box[12].lie + 1;
    box[14].hang = 31; box[14].lie = 45;
    box[15].hang = 32; box[15].lie = box[14].lie;
    box[16].hang = 33; box[16].lie = box[15].lie;

    fire[0].hang = 4; fire[0].lie = 49;
    fire[1].hang = 5; fire[1].lie = 56;
    fire[2].hang = 7; fire[2].lie = 31;
    fire[3].hang = 7; fire[3].lie = 36;
    fire[4].hang = 7; fire[4].lie = 37;
    fire[5].hang = 8; fire[5].lie = fire[0].lie;
    fire[6].hang = 10; fire[6].lie = 5;
    fire[7].hang = 10; fire[7].lie = 38;
    fire[8].hang = 10; fire[8].lie = 39;
    fire[9].hang = 13; fire[9].lie = 33;
    fire[10].hang = 14; fire[10].lie = 55;
    fire[11].hang = 14; fire[11].lie = 56;
    fire[12].hang = 15; fire[12].lie = 47;
    fire[13].hang = 17; fire[13].lie = 19;
    fire[14].hang = 18; fire[14].lie = 19;
    fire[15].hang = 18; fire[15].lie = 47;
    fire[16].hang = 19; fire[16].lie = 19;
    fire[17].hang = 19; fire[17].lie = 24;
    fire[18].hang = 22; fire[18].lie = 1;
    fire[19].hang = 23; fire[19].lie = hole[4].lie;
    fire[20].hang = 24; fire[20].lie = 22;
    fire[21].hang = 24; fire[21].lie = 36;
    fire[22].hang = 26; fire[22].lie = hole[4].lie;
    fire[23].hang = 27; fire[23].lie = 23;
    fire[24].hang = 27; fire[24].lie = 24;
    fire[25].hang = 28; fire[25].lie = 23;
    fire[26].hang = 28; fire[26].lie = 24;
    fire[27].hang = 28; fire[27].lie = 55;
    fire[28].hang = 29; fire[28].lie = 10;
    fire[29].hang = 29; fire[29].lie = fire[21].lie;
    fire[30].hang = 29; fire[30].lie = box[16].lie;
    fire[31].hang = 30; fire[31].lie = 10;
    fire[32].hang = 30; fire[32].lie = fire[26].lie;
    fire[33].hang = 31; fire[33].lie = fire[29].lie;

    thorn[0].hang = 3; thorn[0].lie = 13;
    thorn[1].hang = 4; thorn[1].lie = fire[1].lie;
    thorn[2].hang = 5; thorn[2].lie = fire[0].lie;
    thorn[3].hang = 6; thorn[3].lie = thorn[2].lie;
    thorn[4].hang = 7; thorn[4].lie = box[3].lie;
    thorn[5].hang = 7; thorn[5].lie = box[1].lie + 2;
    thorn[6].hang = 7; thorn[6].lie = 38;
    thorn[7].hang = 9; thorn[7].lie = 5;
    thorn[8].hang = 10; thorn[8].lie = 36;
    thorn[9].hang = 10; thorn[9].lie = 37;
    thorn[10].hang = 10; thorn[10].lie = 40;
    thorn[11].hang = 10; thorn[11].lie = 47;
    thorn[12].hang = 10; thorn[12].lie = 49;
    thorn[13].hang = 12; thorn[13].lie = 55;
    thorn[14].hang = 13; thorn[14].lie = 34;
    thorn[15].hang = 13; thorn[15].lie = 55;
    thorn[16].hang = 16; thorn[16].lie = 47;
    thorn[17].hang = 18; thorn[17].lie = 13;
    thorn[18].hang = 19; thorn[18].lie = 13;
    thorn[19].hang = 19; thorn[19].lie = 26;
    thorn[20].hang = 19; thorn[20].lie = 27;
    thorn[21].hang = 20; thorn[21].lie = 13;
    thorn[22].hang = 21; thorn[22].lie = 13;
    thorn[23].hang = 21; thorn[23].lie = 19;
    thorn[24].hang = 22; thorn[24].lie = 2;
    thorn[25].hang = 22; thorn[25].lie = 3;
    thorn[26].hang = 22; thorn[26].lie = 54;
    thorn[27].hang = 25; thorn[27].lie = 36;
    thorn[28].hang = 27; thorn[28].lie = 25;
    thorn[29].hang = 27; thorn[29].lie = 26;
    thorn[30].hang = 27; thorn[30].lie = 54;
    thorn[31].hang = 28; thorn[31].lie = 25;
    thorn[32].hang = 28; thorn[32].lie = 26;
    thorn[33].hang = 28; thorn[33].lie = 36;
    thorn[34].hang = 28; thorn[34].lie = fire[27].lie + 1;
    thorn[35].hang = 28; thorn[35].lie = fire[27].lie + 2;
    thorn[36].hang = 30; thorn[36].lie = fire[29].lie;
    thorn[37].hang = 30; thorn[37].lie = fire[30].lie;
    thorn[38].hang = 31; thorn[38].lie = fire[31].lie;
    thorn[39].hang = 32; thorn[39].lie = thorn[38].lie;
    thorn[40].hang = 23; thorn[40].lie = 38;
}
void initMap04(string map04[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed)
{
    clearKeyCache();
    Bin::num = 10;
    Zu::num = 10;
    Di::num = 10;
    Wang::num = 2; Huang::num = 0;
    Box::num = 45;
    Fire::num = 40;
    Thorn::num = 53;
    Hole::num = 6;
    p.hang = 17; p.lie = 34;    p.needKill_kill = 1;
    if (difficult == 0) { initEmeny(b, z, d, w, h, emenyButtetSpeed); }
    else if (difficult == 1) { initEnhancedEmeny(b, z, d, w, h, emenyButtetSpeed); p.needKill_kill += 5; Bin::num += 5; Zu::num += 5; Wang::num += 1; Di::num += 2; }

    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;
    hole[0].hang = 5; hole[0].lie = 11;
    hole[1].hang = 5; hole[1].lie = 50;
    hole[2].hang = 17; hole[2].lie = 13;
    hole[3].hang = 17; hole[3].lie = 47;
    hole[4].hang = 31; hole[4].lie = 11;
    hole[5].hang = 31; hole[5].lie = 50;

    box[0].hang = 7; box[0].lie = 15;
    box[1].hang = 8; box[1].lie = 14;
    box[2].hang = 13; box[2].lie = 10;
    box[3].hang = 13; box[3].lie = 44;
    box[4].hang = 14; box[4].lie = 10;
    box[5].hang = 14; box[5].lie = 44;
    box[6].hang = 15; box[6].lie = 10;
    box[7].hang = 15; box[7].lie = 44;
    box[8].hang = 16; box[8].lie = 10;
    box[9].hang = 16; box[9].lie = 30;
    box[10].hang = 16; box[10].lie = 44;
    box[11].hang = 17; box[11].lie = 10;
    box[12].hang = 17; box[12].lie = 23;
    box[13].hang = 17; box[13].lie = 30;
    box[14].hang = 17; box[14].lie = 38;
    box[15].hang = 17; box[15].lie = 44;
    box[16].hang = 18; box[16].lie = 17;
    box[17].hang = 18; box[17].lie = 23;
    box[18].hang = 18; box[18].lie = 30;
    box[19].hang = 18; box[19].lie = 44;
    box[20].hang = 18; box[20].lie = 50;
    box[21].hang = 19; box[21].lie = 17;
    box[22].hang = 19; box[22].lie = 23;
    box[23].hang = 19; box[23].lie = 30;
    box[24].hang = 19; box[24].lie = 44;
    box[25].hang = 19; box[25].lie = 50;
    box[26].hang = 20; box[26].lie = 17;
    box[27].hang = 20; box[27].lie = 30;
    box[28].hang = 20; box[28].lie = 44;
    box[29].hang = 20; box[29].lie = 50;

    fire[0].hang = 7; fire[0].lie = 22;
    fire[1].hang = 8; fire[1].lie = 21;
    fire[2].hang = 9; fire[2].lie = 20;
    fire[3].hang = 10; fire[3].lie = 19;
    fire[4].hang = 11; fire[4].lie = 18;
    fire[5].hang = 12; fire[5].lie = 25;
    fire[6].hang = 12; fire[6].lie = 27;
    fire[7].hang = 13; fire[7].lie = 24;
    fire[8].hang = 13; fire[8].lie = 28;
    fire[9].hang = 13; fire[9].lie = 50;
    fire[10].hang = 14; fire[10].lie = 23;
    fire[11].hang = 14; fire[11].lie = 29;
    fire[12].hang = 14; fire[12].lie = 50;
    fire[13].hang = 15; fire[13].lie = 26;
    fire[14].hang = 15; fire[14].lie = 30;
    fire[15].hang = 15; fire[15].lie = 38;
    fire[16].hang = 15; fire[16].lie = 50;
    fire[17].hang = 16; fire[17].lie = 38;
    fire[18].hang = 16; fire[18].lie = 50;
    fire[19].hang = 17; fire[19].lie = 50;
    fire[20].hang = 20; fire[20].lie = 38;
    fire[21].hang = 21; fire[21].lie = 38;
    fire[22].hang = 22; fire[22].lie = 23;
    fire[23].hang = 23; fire[23].lie = 24;
    fire[24].hang = 24; fire[24].lie = 11;
    fire[25].hang = 24; fire[25].lie = 25;
    fire[26].hang = 25; fire[26].lie = 12;
    fire[27].hang = 25; fire[27].lie = 43;
    fire[28].hang = 26; fire[28].lie = 13;
    fire[29].hang = 26; fire[29].lie = 42;
    fire[30].hang = 27; fire[30].lie = 14;
    fire[31].hang = 27; fire[31].lie = 41;
    fire[32].hang = 28; fire[32].lie = 15;
    fire[33].hang = 28; fire[33].lie = 40;
    fire[34].hang = 29; fire[34].lie = 16;
    fire[35].hang = 29; fire[35].lie = 39;
    fire[36].hang = 30; fire[36].lie = 17;
    fire[37].hang = 31; fire[37].lie = 18;
    fire[38].hang = 32; fire[38].lie = 19;
    fire[39].hang = 33; fire[39].lie = 20;

    thorn[0].hang = 7; thorn[0].lie = 39;
    thorn[1].hang = 8; thorn[1].lie = 40;
    thorn[2].hang = 9; thorn[2].lie = 41;
    thorn[3].hang = 10; thorn[3].lie = 42;
    thorn[4].hang = 11; thorn[4].lie = 43;
    thorn[5].hang = 12; thorn[5].lie = 36;
    thorn[6].hang = 13; thorn[6].lie = 37;
    thorn[7].hang = 14; thorn[7].lie = 38;
    thorn[8].hang = 15; thorn[8].lie = 23;
    thorn[9].hang = 16; thorn[9].lie = 23;
    thorn[10].hang = 20; thorn[10].lie = 23;
    thorn[11].hang = 21; thorn[11].lie = 23;
    thorn[12].hang = 21; thorn[12].lie = 30;
    thorn[13].hang = 22; thorn[13].lie = 34;
    thorn[14].hang = 22; thorn[14].lie = 38;
    thorn[15].hang = 23; thorn[15].lie = 37;
    thorn[16].hang = 24; thorn[16].lie = 36;
    thorn[17].hang = 25; thorn[17].lie = 18;
    thorn[18].hang = 26; thorn[18].lie = 19;
    thorn[19].hang = 27; thorn[19].lie = 20;
    thorn[20].hang = 28; thorn[20].lie = 21;
    thorn[21].hang = 31; thorn[21].lie = 25;
    thorn[22].hang = 31; thorn[22].lie = 26;
    thorn[23].hang = 31; thorn[23].lie = 27;
    thorn[24].hang = 31; thorn[24].lie = 28;
    thorn[25].hang = 31; thorn[25].lie = 29;
    thorn[26].hang = 31; thorn[26].lie = 30;
    thorn[27].hang = 31; thorn[27].lie = 31;
    thorn[28].hang = 31; thorn[28].lie = 32;
    thorn[29].hang = 31; thorn[29].lie = 33;
    thorn[30].hang = 31; thorn[30].lie = 34;
    thorn[31].hang = 31; thorn[31].lie = 35;
    thorn[32].hang = 31; thorn[32].lie = 36;
    thorn[33].hang = 33; thorn[33].lie = 21;
    thorn[34].hang = 33; thorn[34].lie = 22;
    thorn[35].hang = 33; thorn[35].lie = 23;
    thorn[36].hang = 33; thorn[36].lie = 24;
    thorn[37].hang = 33; thorn[37].lie = 25;
    thorn[38].hang = 33; thorn[38].lie = 26;
    thorn[39].hang = 33; thorn[39].lie = 27;
    thorn[40].hang = 33; thorn[40].lie = 28;
    thorn[41].hang = 33; thorn[41].lie = 29;
    thorn[42].hang = 33; thorn[42].lie = 30;
    thorn[43].hang = 33; thorn[43].lie = 31;
    thorn[44].hang = 33; thorn[44].lie = 32;
    thorn[45].hang = 33; thorn[45].lie = 33;
    thorn[46].hang = 33; thorn[46].lie = 34;
    thorn[47].hang = 33; thorn[47].lie = 35;
    thorn[48].hang = 33; thorn[48].lie = 36;
    thorn[49].hang = 33; thorn[49].lie = 37;
    thorn[50].hang = 33; thorn[50].lie = 38;
    thorn[51].hang = 33; thorn[51].lie = 39;
    thorn[52].hang = 33; thorn[52].lie = 40;
}
void initMap05(string map05[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], bool difficult, int emenyButtetSpeed)
{
    clearKeyCache();
    Bin::num = 5;
    Zu::num = 5;
    Di::num = 5;
    Wang::num = 2; Huang::num = 1; h[0].alive = 1;
    Box::num = 14;
    Fire::num = 24;
    Thorn::num = 20;
    Hole::num = 2;
    p.hang = 20; p.lie = 37;    p.needKill_kill = 999;
    if (difficult == 0) { initEmeny(b, z, d, w, h, emenyButtetSpeed); }
    else if (difficult == 1) { initEnhancedEmeny(b, z, d, w, h, emenyButtetSpeed); p.needKill_kill += 5; Bin::num += 5; Zu::num += 5; Wang::num += 1; Di::num += 2; }

    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;
    hole[0].hang = 7; hole[0].lie = 29;
    hole[1].hang = 23; hole[1].lie = 29;

    box[0].hang = 12; box[0].lie = 19;
    box[1].hang = 12; box[1].lie = 39;
    box[2].hang = 13; box[2].lie = 18;
    box[3].hang = 13; box[3].lie = 29;
    box[4].hang = 13; box[4].lie = 40;
    box[5].hang = 14; box[5].lie = 29;
    box[6].hang = 14; box[6].lie = 41;
    box[7].hang = 15; box[7].lie = 29;
    box[8].hang = 20; box[8].lie = 17;
    box[9].hang = 20; box[9].lie = 41;
    box[10].hang = 21; box[10].lie = 18;
    box[11].hang = 21; box[11].lie = 40;
    box[12].hang = 22; box[12].lie = 19;
    box[13].hang = 22; box[13].lie = 39;

    fire[0].hang = 9; fire[0].lie = 36;
    fire[1].hang = 10; fire[1].lie = 13;
    fire[2].hang = 10; fire[2].lie = 37;
    fire[3].hang = 10; fire[3].lie = 44;
    fire[4].hang = 11; fire[4].lie = 12;
    fire[5].hang = 11; fire[5].lie = 13;
    fire[6].hang = 11; fire[6].lie = 14;
    fire[7].hang = 11; fire[7].lie = 38;
    fire[8].hang = 12; fire[8].lie = 13;
    fire[9].hang = 12; fire[9].lie = 44;
    fire[10].hang = 14; fire[10].lie = 17;
    fire[11].hang = 15; fire[11].lie = 16;
    fire[12].hang = 16; fire[12].lie = 15;
    fire[13].hang = 16; fire[13].lie = 29;
    fire[14].hang = 17; fire[14].lie = 29;
    fire[15].hang = 18; fire[15].lie = 15;
    fire[16].hang = 18; fire[16].lie = 29;
    fire[17].hang = 19; fire[17].lie = 16;
    fire[18].hang = 23; fire[18].lie = 20;
    fire[19].hang = 23; fire[19].lie = 43;
    fire[20].hang = 23; fire[20].lie = 44;
    fire[21].hang = 23; fire[21].lie = 45;
    fire[22].hang = 24; fire[22].lie = 21;
    fire[23].hang = 25; fire[23].lie = 22;

    thorn[0].hang = 9; thorn[0].lie = 22;
    thorn[1].hang = 10; thorn[1].lie = 21;
    thorn[2].hang = 11; thorn[2].lie = 20;
    thorn[3].hang = 11; thorn[3].lie = 43;
    thorn[4].hang = 11; thorn[4].lie = 44;
    thorn[5].hang = 11; thorn[5].lie = 45;
    thorn[6].hang = 15; thorn[6].lie = 42;
    thorn[7].hang = 16; thorn[7].lie = 43;
    thorn[8].hang = 18; thorn[8].lie = 43;
    thorn[9].hang = 19; thorn[9].lie = 42;
    thorn[10].hang = 22; thorn[10].lie = 14;
    thorn[11].hang = 22; thorn[11].lie = 44;
    thorn[12].hang = 23; thorn[12].lie = 13;
    thorn[13].hang = 23; thorn[13].lie = 14;
    thorn[14].hang = 23; thorn[14].lie = 15;
    thorn[15].hang = 23; thorn[15].lie = 38;
    thorn[16].hang = 24; thorn[16].lie = 14;
    thorn[17].hang = 24; thorn[17].lie = 37;
    thorn[18].hang = 24; thorn[18].lie = 44;
    thorn[19].hang = 25; thorn[19].lie = 36;
}
void initMapEndless(string mapEndless[][65], Hole hole[], person& p, Box box[], Fire fire[], Thorn thorn[], Bin b[], Zu z[], Di d[], Wang w[], Huang h[], int emenyButtetSpeed)
{
    clearKeyCache();
    Box::num = 16;
    Thorn::num = 26;
    Fire::num = 26;
    Hole::num = 8;
    p.hang = 17; p.lie = 31;
    Bin::num = Zu::num = 5; Di::num = 3; Huang::num = 0; Wang::num = 2;
    initEmeny(b, z, d, w, h, emenyButtetSpeed);

    hole[0].hang = 5; hole[0].lie = 31;
    hole[1].hang = 7; hole[1].lie = 15;
    hole[2].hang = 7; hole[2].lie = 47;
    hole[3].hang = 17; hole[3].lie = 10;
    hole[4].hang = 17; hole[4].lie = 51;
    hole[5].hang = 28; hole[5].lie = 15;
    hole[6].hang = 28; hole[6].lie = 47;
    hole[7].hang = 30; hole[7].lie = 31;

    box[0].hang = 12; box[0].lie = 25;
    box[1].hang = 12; box[1].lie = 26;
    box[2].hang = 12; box[2].lie = 36;
    box[3].hang = 12; box[3].lie = 37;
    box[4].hang = 13; box[4].lie = 25;
    box[5].hang = 13; box[5].lie = 26;
    box[6].hang = 13; box[6].lie = 36;
    box[7].hang = 13; box[7].lie = 37;
    box[8].hang = 21; box[8].lie = 25;
    box[9].hang = 21; box[9].lie = 26;
    box[10].hang = 21; box[10].lie = 36;
    box[11].hang = 21; box[11].lie = 37;
    box[12].hang = 22; box[12].lie = 25;
    box[13].hang = 22; box[13].lie = 26;
    box[14].hang = 22; box[14].lie = 36;
    box[15].hang = 22; box[15].lie = 37;

    thorn[0].hang = 8; thorn[0].lie = 17;
    thorn[1].hang = 8; thorn[1].lie = 18;
    thorn[2].hang = 8; thorn[2].lie = 19;
    thorn[3].hang = 8; thorn[3].lie = 20;
    thorn[4].hang = 8; thorn[4].lie = 21;
    thorn[5].hang = 8; thorn[5].lie = 22;
    thorn[6].hang = 8; thorn[6].lie = 23;
    thorn[7].hang = 8; thorn[7].lie = 24;
    thorn[8].hang = 9; thorn[8].lie = 17;
    thorn[9].hang = 10; thorn[9].lie = 17;
    thorn[10].hang = 11; thorn[10].lie = 17;
    thorn[11].hang = 12; thorn[11].lie = 17;
    thorn[12].hang = 13; thorn[12].lie = 17;
    thorn[13].hang = 22; thorn[13].lie = 45;
    thorn[14].hang = 23; thorn[14].lie = 45;
    thorn[15].hang = 24; thorn[15].lie = 45;
    thorn[16].hang = 25; thorn[16].lie = 45;
    thorn[17].hang = 26; thorn[17].lie = 45;
    thorn[18].hang = 27; thorn[18].lie = 38;
    thorn[19].hang = 27; thorn[19].lie = 39;
    thorn[20].hang = 27; thorn[20].lie = 40;
    thorn[21].hang = 27; thorn[21].lie = 41;
    thorn[22].hang = 27; thorn[22].lie = 42;
    thorn[23].hang = 27; thorn[23].lie = 43;
    thorn[24].hang = 27; thorn[24].lie = 44;
    thorn[25].hang = 27; thorn[25].lie = 45;

    fire[0].hang = 8; fire[0].lie = 38;
    fire[1].hang = 8; fire[1].lie = 39;
    fire[2].hang = 8; fire[2].lie = 40;
    fire[3].hang = 8; fire[3].lie = 41;
    fire[4].hang = 8; fire[4].lie = 42;
    fire[5].hang = 8; fire[5].lie = 43;
    fire[6].hang = 8; fire[6].lie = 44;
    fire[7].hang = 8; fire[7].lie = 45;
    fire[8].hang = 9; fire[8].lie = 45;
    fire[9].hang = 10; fire[9].lie = 45;
    fire[10].hang = 11; fire[10].lie = 45;
    fire[11].hang = 12; fire[11].lie = 45;
    fire[12].hang = 13; fire[12].lie = 45;
    fire[13].hang = 22; fire[13].lie = 17;
    fire[14].hang = 23; fire[14].lie = 17;
    fire[15].hang = 24; fire[15].lie = 17;
    fire[16].hang = 25; fire[16].lie = 17;
    fire[17].hang = 26; fire[17].lie = 17;
    fire[18].hang = 27; fire[18].lie = 17;
    fire[19].hang = 27; fire[19].lie = 18;
    fire[20].hang = 27; fire[20].lie = 19;
    fire[21].hang = 27; fire[21].lie = 20;
    fire[22].hang = 27; fire[22].lie = 21;
    fire[23].hang = 27; fire[23].lie = 22;
    fire[24].hang = 27; fire[24].lie = 23;
    fire[25].hang = 27; fire[25].lie = 24;
}
void initmultiplayer(string mapMultiplayer[][65], person& p, person& p2, Box box[], Thorn thorn[])
{
    clearKeyCache();
    Box::num = 32;
    Thorn::num = 10; Fire::num = 0;
    for (int i = 0; i < Box::num; ++i)box[i].alive = 1;

    p.hang = 20; p.lie = 10; p.weaponTemp01 = p.weapon01; p.weapontemp02 = p.weapon02;
    p2.hang = 20; p2.lie = 54;

    p.weaponUsing = 3; p.weaponId = 1; p.weapon01 = 3; p.weapon02 = 2; p.Hp = p2.Hp = 10;
    p2.weaponUsing = 3; p2.weaponId = 1; p2.weapon01 = 3; p2.weapon02 = 2;

    box[0].hang = 9; box[0].lie = 30;
    box[1].hang = 9; box[1].lie = 31;
    box[2].hang = 9; box[2].lie = 32;
    box[3].hang = 10; box[3].lie = 30;
    box[4].hang = 10; box[4].lie = 31;
    box[5].hang = 10; box[5].lie = 32;
    box[6].hang = 11; box[6].lie = 30;
    box[7].hang = 11; box[7].lie = 31;
    box[8].hang = 11; box[8].lie = 32;
    box[9].hang = 15; box[9].lie = 29;
    box[10].hang = 15; box[10].lie = 30;
    box[11].hang = 15; box[11].lie = 32;
    box[12].hang = 15; box[12].lie = 33;
    box[13].hang = 16; box[13].lie = 28;
    box[14].hang = 16; box[14].lie = 34;
    box[15].hang = 17; box[15].lie = 27;
    box[16].hang = 17; box[16].lie = 45;
    box[17].hang = 18; box[17].lie = 28;
    box[18].hang = 18; box[18].lie = 34;
    box[19].hang = 19; box[19].lie = 29;
    box[20].hang = 19; box[20].lie = 30;
    box[21].hang = 19; box[21].lie = 32;
    box[22].hang = 19; box[22].lie = 33;
    box[23].hang = 23; box[23].lie = 30;
    box[24].hang = 23; box[24].lie = 31;
    box[25].hang = 23; box[25].lie = 32;
    box[26].hang = 24; box[26].lie = 30;
    box[27].hang = 24; box[27].lie = 31;
    box[28].hang = 24; box[28].lie = 32;
    box[29].hang = 25; box[29].lie = 30;
    box[30].hang = 25; box[30].lie = 31;
    box[31].hang = 25; box[31].lie = 32;

    thorn[0].hang = 15; thorn[0].lie = 17;
    thorn[1].hang = 15; thorn[1].lie = 45;
    thorn[2].hang = 16; thorn[2].lie = 16;
    thorn[3].hang = 16; thorn[3].lie = 46;
    thorn[4].hang = 17; thorn[4].lie = 15;
    thorn[5].hang = 17; thorn[5].lie = 47;
    thorn[6].hang = 18; thorn[6].lie = 16;
    thorn[7].hang = 18; thorn[7].lie = 46;
    thorn[8].hang = 19; thorn[8].lie = 17;
    thorn[9].hang = 19; thorn[9].lie = 45;

    for (int i = 1; i <= 35; ++i)
    {
        for (int j = 0; j < 65; ++j)
       {
            if (mapMultiplayer[i][j] == "我" || mapMultiplayer[i][j] == "他") { mapMultiplayer[i][j] = "一"; }
        }
    }
}
void initEmeny(Bin b[], Zu z[], Di d[], Wang w[], Huang h[],int emenyButtetSpeed)
{
    for (int i = 0; i < Bin::num; i++) { b[i].Hp = 2; b[i].shootSpeed = 3000; }
    for (int i = 0; i < Zu::num; i++) { z[i].Hp = 4; z[i].shootSpeed = 2000; }
    for (int i = 0; i < Di::num; i++) { d[i].Hp = 6; d[i].shootSpeed = 1600; }
    for (int i = 0; i < Wang::num; i++) { w[i].Hp = 10; w[i].shootSpeed = 1500; }
    for (int i = 0; i < Huang::num; i++) { h[i].Hp = 40; h[i].shootSpeed = 1500; }
    emenyButtetSpeed = 120;
}
void initEnhancedEmeny(Bin b[], Zu z[], Di d[], Wang w[], Huang h[], int emenyButtetSpeed)
{
    emenyButtetSpeed = 90;
    for (int i = 0; i < Bin::num; i++) { b[i].Hp = 3; b[i].shootSpeed = 2600; }
    for (int i = 0; i < Zu::num; i++) { z[i].Hp = 5; z[i].shootSpeed = 1700; }
    for (int i = 0; i < Di::num; i++) { d[i].Hp = 7; d[i].shootSpeed = 1300; }
    for (int i = 0; i < Wang::num; i++) { w[i].Hp = 12; w[i].shootSpeed = 1200; }
    for (int i = 0; i < Huang::num; i++) { h[i].Hp = 50; h[i].shootSpeed = 1200; }
}
void initMapShop(person* p, Door* door, Buy buy[])
{
    p->hang = 19; p->lie = 23;
    door[1].hang = 22; door[1].lie = 23;
    buy[0].hang = buy[1].hang = buy[2].hang = buy[3].hang = buy[4].hang = buy[5].hang = buy[6].hang = buy[7].hang = 7;
    buy[0].lie = 8; buy[1].lie = 13; buy[2].lie = 18; buy[3].lie = 23; buy[4].lie = 27; buy[5].lie = 33, buy[6].lie = 38; buy[7].lie = 43;

}











