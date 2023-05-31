#pragma once

#include "views/BaseBox.hpp"
#include <vector>

typedef struct {
    char* room_name;
    char* ip_address;
} RoomInfo;

enum colors {
    BG_WHITE = 1
};

class JoinRoomForm: public BaseBox {
    private:
        const int FORM_BOX_HEIGHT = 12;
        const int FORM_BOX_WIDTH = 40;
        const int FIELD_BOX_HEIGHT = 6;
        const int FIELD_BOX_WIDTH = 30;
        const int FIELD_SPACE_Y = 1;
        const int FIELD_SPACE_X = 2;
        const int TITLE_CENTER_X = 4;
        const int FIELD_CENTER_X = 2;
        const int RELOAD_SPACE_Y = 5;
        const int RELOAD_CENTER_X = -3;
        const int WIN_BASE_Y = 2;
        const int WIN_BASE_X = 2;
        std::vector<RoomInfo> room_infos;
        WINDOW *box_win;
        WINDOW *field_win;
        Position title;
        Position field;
        Position reload;

    public:
        JoinRoomForm();
        ~JoinRoomForm();
        void showForm();

    protected:
        void showContents();
        void keyWait();

    private:
        inline void cursorInit(Position&, int&);
        inline void changeCursorReload(const int);
        inline void selectFieldRoom(std::vector<RoomInfo>&);
        inline void updateField(const int, const std::vector<RoomInfo>);
};