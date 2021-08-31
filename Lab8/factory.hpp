//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_FACTORY_HPP
#define LAB8_FACTORY_HPP

#include <memory>

#include "rectangle.hpp"
#include "square.hpp"
#include "trapezoid.hpp"

template<class T, class FIGURE>
class TFactory;

template<class T>
class TFactory< T, TSquare<T> > {
public:
    static std::shared_ptr<IFigure> CreateFigure() {
        std::pair<T, T> curCords;
        T curSide;
        std::cin >> curCords.first >> curCords.second >> curSide;
        TSquare<T>* sq = new TSquare<T>(curCords, curSide);
        return std::shared_ptr<IFigure>(sq);
    }
};

template<class T>
class TFactory< T, TRectangle<T> > {
public:
    static std::shared_ptr<IFigure> CreateFigure() {
        std::pair<T, T> curCords;
        T curHeight, curWidth;
        std::cin >> curCords.first >> curCords.second >> curHeight >> curWidth;
        TRectangle<T>* rect = new TRectangle<T>(curCords, curHeight, curWidth);
        return std::shared_ptr<IFigure>(rect);
    }
};

template<class T>
class TFactory< T, TTrapeze<T> > {
public:
static std::shared_ptr<IFigure> CreateFigure() {
    std::pair<T, T> curCords;
    T curGreaterBase, curSmallerBase, curHeight;
    std::cin >> curCords.first >> curCords.second >> curGreaterBase >> curSmallerBase >> curHeight;
    TTrapeze<T>* trap = new TTrapeze<T>(curCords, curGreaterBase, curSmallerBase, curHeight);
    return std::shared_ptr<IFigure>(trap);
}
};
#endif //LAB8_FACTORY_HPP
