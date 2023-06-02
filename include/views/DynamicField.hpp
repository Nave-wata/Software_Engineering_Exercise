#pragma once

class DynamicField {
    protected:
        const int FIELD_CENTER_Y;
        const int FIELD_CENTER_X;

    public:
        DynamicField(const int, const int);
        virtual ~DynamicField();
        virtual void showField()=0;
        virtual void updateField()=0;
};