#pragma once

#include "views/InputForm.hpp"

class CreateRoomForm: public InputForm {
    public:
        CreateRoomForm(const char*, const char*);
        ~CreateRoomForm();
};