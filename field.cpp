#include "field.h"

Field::Field() {
    this->reset();
}

Field::~Field() {

}

void Field::reset() {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            this->data[i][j] = 2;
        }
    }
}

bool Field::setField(size_t y, size_t x, uint8_t p) {
    if (y > 2 || x > 2 || p > 1 || this->data[y][x] != 2) {
        return false;
    }
    this->data[y][x] = p;
    return true;
}

bool Field::check(uint8_t p) {
    if (p > 1) {
        return false;
    }
    for (size_t i = 0; i < 3; i++) {
        if (this->data[0][i] == p && this->data[1][i] == p && this->data[2][i] == p) {
            return true;
        }
        if (this->data[i][0] == p && this->data[i][1] == p && this->data[i][2] == p) {
            return true;
        }
    }
    if (this->data[0][0] == p && this->data[1][1] == p && this->data[2][2] == p) {
        return true;
    }
    if (this->data[2][0] == p && this->data[1][1] == p && this->data[0][2] == p) {
        return true;
    }
    return false;
}

char Field::getRepresentation(size_t y, size_t x) {
    if (y > 2 || x > 2) {
        return '\0';
    }
    switch (this->data[y][x]) {
        case 0:
            return 'X';
        case 1:
            return 'O';
        default:
            return ' ';
    }
}

bool Field::isFull() {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (this->data[i][j] == 2) {
                return false;
            }
        }
    }
    return true;
}
