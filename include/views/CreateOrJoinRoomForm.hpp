#pragma once

#include "views/BaseBox.hpp"

class CreateOrJoinRoomForm: public BaseBox {
    private:
        const int FORM_BOX_HEIGHT = 12;
        const int FORM_BOX_WIDTH = 40;
        const int CREATE_CENTER_X = -12;
        const int JOIN_CENTER_X = 3;
        const int WIN_BASE_Y = 2;
        Position title;
        Position create;
        Position join;

    public:
        CreateOrJoinRoomForm();
        ~CreateOrJoinRoomForm();
        void showForm();

    protected:
        void showContents() override;
        void keyWait() override;
};