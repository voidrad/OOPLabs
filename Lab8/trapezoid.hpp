//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_TRAPEZOID_HPP
#define LAB8_TRAPEZOID_HPP
#include "figure.hpp"

const unsigned int TRAPEZE_TYPE_ID = 3;

template<class T>
class TTrapeze : public IFigure {
private:
    std::pair<T, T> Cords;
    T GreaterBase, SmallerBase, Height;
public:
    TTrapeze() : Cords(), GreaterBase(), SmallerBase(), Height() {}
    TTrapeze(const std::pair<T, T> & xy, const T & gb, const T & sb, const T & h) : Cords(xy), GreaterBase(gb), SmallerBase(sb), Height(h) {
        if (SmallerBase > GreaterBase) {
            std::swap(SmallerBase, GreaterBase);
        }
    }

    void Print() override {
        std::cout << *this << std::endl;
    }

    void Write(FILE* out) override {
        fwrite(&TRAPEZE_TYPE_ID, sizeof(unsigned int), 1, out);
        fwrite(&Cords.first, sizeof(T), 1, out);
        fwrite(&Cords.second, sizeof(T), 1, out);
        fwrite(&SmallerBase, sizeof(T), 1, out);
        fwrite(&GreaterBase, sizeof(T), 1, out);
        fwrite(&Height, sizeof(T), 1, out);
    }

    template<class U>
    friend std::ostream & operator << (std::ostream & out, const TTrapeze<U> & trapeze) {
        T d = (trapeze.GreaterBase - trapeze.SmallerBase) / 2.0;
        out << "Trapeze {";
        out << std::pair<T, T>(trapeze.Cords.first, trapeze.Cords.second) << ", ";
        out << std::pair<T, T>(trapeze.Cords.first + d, trapeze.Cords.second + trapeze.Height) << ", ";
        out << std::pair<T, T>(trapeze.Cords.first + trapeze.SmallerBase + d, trapeze.Cords.second + trapeze.Height) << ", ";
        out << std::pair<T, T>(trapeze.Cords.first + trapeze.GreaterBase, trapeze.Cords.second);
        out << "}";
        return out;
    }
};
#endif //LAB8_TRAPEZOID_HPP
