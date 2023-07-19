/**
 * @file PlayBoard.cpp
 * 
 * @brief PlayBoardクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "PlayBoard.hpp"
#include "utils/Sleep.hpp"

/**
 * @brief PlayBoardクラスのコンストラクタ
 * 
 * @param y フィールドを表示する中央のy座標
 * @param x フィールドを表示する中央のx座標
 * @param settings ファイルから読み込んだ設定
 * @param single 1人プレイかどうか
 */
PlayBoard::PlayBoard(const int y, const int x, const Settings settings, const bool single)
    : chain_controller(y, x)
    , next_puyo_controller(y, x)
    , play_field_controller(y, x, settings.gravity)
    , score_controller(y, x, settings.all_clear_magnification)
    , settings(settings)
    , single(single)
    , next_puyos({PuyoState::NONE, PuyoState::NONE})
    , score(0) {}

/**
 * @brief プレイ画面を表示・管理する
 */
void PlayBoard::show() {
    chain_controller.show();
    next_puyo_controller.show();
    play_field_controller.show();
    score_controller.show();

    this->next_puyos = next_puyo_controller.create();

    std::array<PuyoState, 2> puyos = next_puyo_controller.update();
    play_field_controller.create(puyos);

    int c = '\0';
    bool isAllClear = false;
    timeout(0);

    while (true) {
        c = getch();
        play_field_controller.gravity();

        if (c == this->settings.key_left_rotate) {
            play_field_controller.rotation(LEFT_ROTATE);
        }
        else if (c == this->settings.key_right_rotate) {
            play_field_controller.rotation(RIGHT_ROTATE);
        }
        else if (c == this->settings.key_up) {
            play_field_controller.move(UP);
        }
        else if (c == this->settings.key_down) {
            play_field_controller.move(DOWN);
        }
        else if (c == this->settings.key_left) {
            play_field_controller.move(LEFT);
        }
        else if (c == this->settings.key_right) {
            play_field_controller.move(RIGHT);
        }
        else if (single && c == this->settings.key_pause) {
            timeout(-1);
            getch();
            timeout(0);
        } else if (c == this->settings.key_quit) {
            std::exit(0);
        }

        if (play_field_controller.isNext()) {
            int chain = 0;

            if (play_field_controller.isGameOver()) {
                return;
            }

            Sleep::milliSleep(100);

            play_field_controller.dropPuyos();

            Sleep::milliSleep(100);

            while (true) {
                std::vector<std::vector<puyoInfo>> deleted_puyos = play_field_controller.deletePuyos();

                if (deleted_puyos.size() == 0) break;

                chain++;
                this->score = score_controller.update(deleted_puyos, chain, isAllClear);

                Sleep::milliSleep(100);

                play_field_controller.dropPuyos();

                Sleep::milliSleep(100);
            }

            if (chain > 0) {
                isAllClear = play_field_controller.isAllClear();
            }

            std::array<PuyoState, 2> puyos = next_puyo_controller.update();
            play_field_controller.create(puyos);
            chain_controller.update(chain);
        }
    }
}
