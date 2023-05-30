#pragma once

#include "views/BaseBox.hpp"

class SelectPlayerForm: public BaseBox {
    private:
        const int FORM_BOX_HEIGHT = 12;
        const int FORM_BOX_WIDTH = 40;
        const int NUMBERS_CENTER_X = 3;
        const int SUBMIT_CENTER_X = 3;
        const int WIN_BASE_Y = 2;
        Position title;
        Position play1;
        Position play2;
        Position play3;
        Position play4;

    public:
        SelectPlayerForm();
        ~SelectPlayerForm();
        void showForm();

    protected:
        void showContents();
        void keyWait();
};