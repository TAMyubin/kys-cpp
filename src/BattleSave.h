#pragma once
#include <vector>
#include "Types.h"

enum
{
    BATTLE_ROLE_COUNT = 4096,                       //ս���������
    BATTLEMAP_SAVE_LAYER_COUNT = 2,                        //�����ļ��洢��ͼ���ݲ���
    BATTLEMAP_LAYER_COUNT = 8,                     //ս����Ҫ��ͼ����
    BATTLEMAP_COORD_COUNT = 64,                        //ս���������
    BATTLE_ENEMY_COUNT = 20,
};

struct BattleInfo
{
    SAVE_INT ID;
    char Name[10];
    SAVE_INT BattleFieldID, Exp, Music;
    SAVE_INT TeamMate[TEAMMATE_COUNT], AutoTeamMate[TEAMMATE_COUNT], TeamMateX[TEAMMATE_COUNT], TeamMateY[TEAMMATE_COUNT];
    SAVE_INT Enemy[BATTLE_ENEMY_COUNT], EnemyX[BATTLE_ENEMY_COUNT], EnemyY[BATTLE_ENEMY_COUNT];
};

//���������ս��ǰ����
struct BattleFieldData2
{
    SAVE_INT data[BATTLEMAP_SAVE_LAYER_COUNT][BATTLEMAP_COORD_COUNT*BATTLEMAP_COORD_COUNT];
};

//�����������ʼ����¼��û�����
class BattleSave
{
private:
    std::vector<BattleInfo> battle_infos_;
    std::vector<BattleFieldData2> battle_field_data2_;
    static BattleSave battle_data_;
public:
    BattleSave();
    ~BattleSave();

    static BattleSave* getInstance() { return &battle_data_; }
    BattleInfo* getBattleInfo(int i) { if (i < 0 || i >= battle_infos_.size()) { return nullptr; } return &battle_infos_[i]; }
    void copyLayerData(int battle_field_id, int layer, SAVE_INT* out);

};
