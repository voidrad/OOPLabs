//
// Created by YaTeb on 10/10/2020.
//
#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
public:
    Rectangle(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }

    Rectangle(double n_x1,double n_y1,double n_x2,double n_y2){
        x1 = n_x1;
        x2 = n_x2;
        y1 = n_y1;
        y2 = n_y2;
        if (area() == 0){
            cout << "\n Vi sosdali otrezok \n";
        }
    }

    ~Rectangle(){};

    void NewCords(double n_x1,double n_y1,double n_x2,double n_y2){
        x1 = n_x1;
        x2 = n_x2;
        y1 = n_y1;
        y2 = n_y2;
        if (area() == 0){
            cout << "\n Vi zadali otrezok \n";
        }
    };

    double area(){
        return (fabs((x2-x1)*(y2 -y1)));
    };

    double perimeter(){
        return (2*(fabs(x2-x1)) + 2*(fabs(y2 - y1)));
    };

    void axis(double x, double y){
        x1 = x1+x;
        x2 = x2+x;
        y1 = y1+y;
        y2 = y2+y;
    };

    int isBiggerArea(Rectangle a){
        if (a.area() < area()){
            return 1;
        }else{
            return 0;
        }
    };

    int isBiggerPerimeter(Rectangle a){
        if(a.perimeter() < perimeter()){
            return 1;
        }else{
            return 0;
        }
    };

    Rectangle LilRect(Rectangle a){
        Rectangle *LilBro = new Rectangle;
        if((y1 > a.y2)||(a.y1 > y2)||(x1 > a.x2)||(a.x1 > x2)){
            return *LilBro;
        }else{
            LilBro->x1 = fmax(a.x1,x1);
            LilBro->x2 = fmin(a.x2,x2);
            LilBro->y1 = fmax(a.y1,y1);
            LilBro->y2 = fmin(a.y2,y2);
            return *LilBro;
        }

    };

    Rectangle BigRect(Rectangle a){
        Rectangle *BigBro = new Rectangle;
        BigBro->y2 = fmax(a.y2,y2);
        BigBro->y1 = fmin(a.y1,y1);
        BigBro->x1 = fmax(fmax(x1,x2),fmax(a.x1,a.x2));
        BigBro->x2 = fmin(fmin(x1,x2),fmin(a.x1,a.x2));
        return *BigBro;
    };

private:
    double x1,y1,x2,y2;
};

int main(){
    Rectangle First(0,0,10,10);
    Rectangle Second(0,0,20,20);
    cout << First.area() << "  hhh ";
    Rectangle Third;
    Second.axis(5,0);
    cout << First.isBiggerPerimeter(Second) << "   " << Second.isBiggerArea(First) << "  end ";
    Third = First.LilRect(Second);
    cout << Third.perimeter();
}