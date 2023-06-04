/**
 * @file NextPuyoField.hpp
 * 
 * @brief NextPuyoFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include "views/BaseBox.hpp"
#include "views/DynamicField.hpp"
#include "views/Puyo.hpp"

class NextPuyoField: BaseBox, DynamicField {
    private:
        /** @brief フィールドの行数 */
        const int FIELD_BOX_HEIGHT = 4;

        /** @brief フィールドの列数 */
        const int FIELD_BOX_WIDTH = 3;

        /** @brief フィールドを縦方向に移動させる */
        const int FIELD_MOVE_Y = -3;

        /** @brief フィールドを横方向に移動させる */
        const int FIELD_MOVE_X = 7;

        /** @brief 1つめの次のぷよを表示した際にボックス内に収まる様にする */
        const int PUYO1_CENTER_Y = 1;

        /** @brief 2つめの次のぷよを表示した際にボックス内に収まる様にする */
        const int PUYO2_CENTER_Y = 2;

        /** @brief ぷよを表示した際にボックスの中央となるようにする */
        const int PUYO_CENTER_X = 1;

        /** @brief 次のぷよセット */
        Puyo puyos[2];

    public:
        NextPuyoField(const int y, const int x);
        ~NextPuyoField();
        void showField() override;
        void updateField() override;
        void updateField(const PuyoState puyo1, const PuyoState puyo2);

    protected:
        /** @brief 使用しない */
        void showContents() override {};

        /** @brief 使用しない */
        void keyWait() override {};

    private:
        void createPuyoSet(const PuyoState puyo1, const PuyoState puyo2);
};
