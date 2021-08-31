//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_FIGURE_HPP
#define LAB8_FIGURE_HPP
#include <iostream>
#include <tuple>

class IFigure {
public:
    virtual void Print() = 0;
    virtual void Write(FILE* out) = 0;
    virtual ~IFigure() {}
};

template<class T1, class T2>
std::ostream & operator << (std::ostream & out, const std::pair<T1, T2> & p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
#endif //LAB8_FIGURE_HPP
