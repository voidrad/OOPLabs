//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_SQUARE_HPP
#define LAB8_SQUARE_HPP
#include "figure.hpp"

const unsigned int SQUARE_TYPE_ID = 1;

template<class T>
class TSquare : public IFigure {
private:
    std::pair<T, T> Cords;
    T Side;
public:
    TSquare() : Cords(), Side() {}
    TSquare(const std::pair<T, T> & xy, const T & l) : Cords(xy), Side(l) {}

    void Write(FILE* out) override {
        fwrite(&SQUARE_TYPE_ID, sizeof(unsigned int), 1, out);
        fwrite(&Cords.first, sizeof(T), 1, out);
        fwrite(&Cords.second, sizeof(T), 1, out);
        fwrite(&Side, sizeof(T), 1, out);
    }

    void Print() override {
        std::cout << *this << std::endl;
    }

    template<class U>
    friend std::ostream & operator << (std::ostream & of, const TSquare<U> & sq) {
        of << "Square {";
        of << std::pair<U, U>(sq.Cords.first, sq.Cords.second) << ", ";
        of << std::pair<U, U>(sq.Cords.first, sq.Cords.second + sq.Side) << ", ";
        of << std::pair<U, U>(sq.Cords.first + sq.Side, sq.Cords.second + sq.Side) << ", ";
        of << std::pair<U, U>(sq.Cords.first + sq.Side, sq.Cords.second);
        of << "}";
        return of;
    }
};
#endif //LAB8_SQUARE_HPP
