#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class Field {
    private:
        uint8_t data[3][3];
    public:
        Field();
        ~Field();
        bool setField(size_t y, size_t x, uint8_t p);
        bool check(uint8_t p);
        void reset();
        char getRepresentation(size_t y, size_t x);
        bool isFull();
};

#endif // FIELD_H
