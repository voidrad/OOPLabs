//
// Created by YaTeb on 11/26/2020.
//

#ifndef LAB3_FIGURES_HPP
#define LAB3_FIGURES_HPP

using namespace std;
struct DotCoords{
    double x,y;
};

class Figure {
public:
    Figure(){};


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
    Square(){
        cout << "input coords of first angle, x and then y:\n";
        cin >> leftCorner.x >> leftCorner.y;
        cout << "input coords of second angle, x and then y:\n";
        cin >> rightCorner.x >> rightCorner.y;
    }
};


class Rectangle: public Degrees {
public:
    Rectangle(){
        cout << "input coords of first angle, x and then y:\n";
        cin >> leftCorner.x >> leftCorner.y;
        cout << "input coords of second angle, x and then y:\n";
        cin >> rightCorner.x >> rightCorner.y;
    }
};


class Trapezoid: public Figure {
public:
    Trapezoid(){
        cout << "input coords of Left Down angle, x and then y:\n";
        cin >> leftDownCorner.x >> leftDownCorner.y;
        cout << "input coords of Left Up angle, x and then y:\n";
        cin >>  leftUpCorner.x >>  leftUpCorner.y;
        cout << "input coords of Right Up angle, x and then y:\n";
        cin >> rightUpCorner.x >> rightUpCorner.y;
        cout << "input coords of RIght Down angle, x and then y:\n";
        cin >>  rightDownCorner.x >>  rightDownCorner.y;

        height = leftUpCorner.y - leftDownCorner.y;
        midSum = (rightUpCorner.x-leftUpCorner.x+ rightDownCorner.x-leftDownCorner.x)/2;
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




#endif //LAB3_FIGURES_HPP
