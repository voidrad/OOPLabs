//
// Created by YaTeb on 12/27/2020.
//

#ifndef LAB6_SQUARE_HPP
#define LAB6_SQUARE_HPP
#include <iostream>
#include <type_traits>


template <class T>
class Square {
public:
    using value_type = T;
    using vertex = std::pair<T, T>;

    vertex a, b;
    double area() const {
        return (b.first - a.first) * (b.second - a.second);
    }


    Square() : a(), b() {}
    Square(vertex v1, vertex v2) {
        if ( v2.first- v1.first != v2.second - v1.second) {
            throw std::logic_error("Invalid vertexes for square");
        }

        if (v1.second < v2.second) {
            if (v1.first < v2.first) { a(v1); b(v2); }
            else {
                a(std::make_pair(v2.first, v1.second));
                b(std::make_pair(v1.first, v2.second));
            }
        } else {
            if (v1.first > v2.first) { a(v2); b(v1); }
            else {
                a(std::make_pair(v1.first, v2.second));
                b(std::make_pair(v2.first, v1.second));
            }
        }
    }
    ~Square() = default;
};


template <class T>
std::ostream& operator<<(std::ostream& os, const Square<T>& rec) {
    std::cout << "(" << rec.a.first << ", " << rec.a.second << ")" << " "
              << "(" << rec.a.first << ", " << rec.b.second << ")" << " "
              << "(" << rec.b.first << ", " << rec.b.second << ")" << " "
              << "(" << rec.b.first << ", " << rec.a.second << ")";
    return os;
}


template<class T>
std::istream& operator>>(std::istream& is, Square<T>& rec) {
    std::pair<T, T> v1, v2;
    std::cin >> v1.first >> v1.second >> v2.first >> v2.second;

    if ( v2.first- v1.first != v2.second - v1.second)  {
        throw std::logic_error("Invalid vertexes for square");
    }

    if (v1.second < v2.second) {
        if (v1.first < v2.first) {
            rec.a = v1;
            rec.b = v2;
        } else {
            rec.a = std::make_pair(v2.first, v1.second);
            rec.b = std::make_pair(v1.first, v2.second);
        }
    } else {
        if (v1.first > v2.first) {
            rec.a = v2;
            rec.b = v1;
        } else {
            rec.a = std::make_pair(v1.first, v2.second);
            rec.b = std::make_pair(v2.first, v1.second);
        }
    }
    return is;
}

#endif //LAB6_SQUARE_HPP
