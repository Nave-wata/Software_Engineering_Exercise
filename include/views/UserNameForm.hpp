#pragma once

#include "views/InputForm.hpp"

class UserNameForm: public InputForm {
    public:
        UserNameForm(const char*, const char*);
        ~UserNameForm();
};