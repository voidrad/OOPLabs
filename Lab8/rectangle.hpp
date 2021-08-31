//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_RECTANGLE_HPP
#define LAB8_RECTANGLE_HPP
#include "figure.hpp"

const unsigned int RECTANGLE_TYPE_ID = 2;

template<class T>
class TRectangle : public IFigure {
private:
    std::pair<T, T> Cords;
    T Height, Width;
public:
    TRectangle() : Cords(), Height(), Width() {}
    TRectangle(const std::pair<T, T> & xy, const T & h, const T & w) : Cords(xy), Height(h), Width(w) {}

    void Print() override {
        std::cout << *this << std::endl;
    }

    void Write(FILE* out) override {
        fwrite(&RECTANGLE_TYPE_ID, sizeof(unsigned int), 1, out);
        fwrite(&Cords.first, sizeof(T), 1, out);
        fwrite(&Cords.second, sizeof(T), 1, out);
        fwrite(&Height, sizeof(T), 1, out);
        fwrite(&Width, sizeof(T), 1, out);
    }

    template<class U>
    friend std::ostream & operator << (std::ostream & of, const TRectangle<U> & rect) {
        of << "Rectangle {";
        of << std::pair<U, U>(rect.Cords.first, rect.Cords.second) << ", ";
        of << std::pair<U, U>(rect.Cords.first, rect.Cords.second + rect.Height) << ", ";
        of << std::pair<U, U>(rect.Cords.first + rect.Width, rect.Cords.second + rect.Height) << ", ";
        of << std::pair<U, U>(rect.Cords.first + rect.Width, rect.Cords.second);
        of << "}";
        return of;
    }
};

#endif //LAB8_RECTANGLE_HPP
