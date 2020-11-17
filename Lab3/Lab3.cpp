//
// Created by YaTeb on 10/17/2020.
//
#include "vector"
#include "iostream"
using namespace std;

struct DotCoords{
    double x,y;
};

class Figure {
public:
    Figure(){
        S = getSquare();
    };


    double getSquare(){
        return height * midSum;
    }

    virtual void coordsOut(){}

    virtual DotCoords getCenter(){}

    double height,midSum,S;
};

class Degrees: public Figure {
public:
    Degrees(){
        height = rightCorner.y - leftCorner.y;
        midSum = rightCorner.x - leftCorner.x;
    };

    DotCoords getCenter(){
        DotCoords result;
        result.x =  (rightCorner.x - leftCorner.x)/2 + leftCorner.x;
        result.y = (rightCorner.y - leftCorner.y)/2 + leftCorner.y;
        return result;
    }

    void coordsOut(){
        cout <<"\nКоординаты четырех точек данной фигуры:\n A = (" <<leftCorner.x <<" " <<rightCorner.y<<") \n";
        cout <<"B = (" <<rightCorner.x <<" " <<rightCorner.y<<") \n";
        cout <<"C = (" <<rightCorner.x <<" " <<leftCorner.y<<") \n";
        cout <<"D = (" <<leftCorner.x <<" " <<leftCorner.y<<") \n";
    }

    DotCoords leftCorner,rightCorner;
};


class Square: public Degrees {
public:
    Square(DotCoords lc, DotCoords rc){
        leftCorner = lc;
        rightCorner = rc;
    }



};


class Rectangle: public Degrees {
public:
    Rectangle(DotCoords lc, DotCoords rc){
        leftCorner = lc;
        rightCorner = rc;
    }



};


class Trapezoid: public Figure {
public:
    Trapezoid(DotCoords ldc, DotCoords luc,DotCoords ruc, DotCoords rdc){

        leftDownCorner = ldc;
        leftUpCorner = luc;
        rightUpCorner = ruc;
        rightDownCorner = rdc;

        height = luc.y - ldc.y;
        midSum = (ruc.x-luc.x+rdc.x-ldc.x)/2;
    }

    DotCoords getCenter(){
        DotCoords result;
        result.y = rightDownCorner.y + height/2;
        result.x =((rightDownCorner.x/2+leftDownCorner.x/2)+(rightUpCorner.x/2+leftUpCorner.x/2))/2;
        return result;
    }

    void coordsOut(){
        cout <<"\nКоординаты четырех точек данной фигуры:\n A = (" <<leftUpCorner.x <<" " <<leftUpCorner.y<<") \n";
        cout <<"B = (" <<rightUpCorner.x <<" " <<rightUpCorner.y<<") \n";
        cout <<"C = (" <<rightDownCorner.x <<" " <<rightDownCorner.y<<") \n";
        cout <<"D = (" <<leftDownCorner.x <<" " <<leftDownCorner.y<<") \n";
    }



    DotCoords leftDownCorner,leftUpCorner,rightDownCorner,rightUpCorner;
};

int main(){


    return 0;
}