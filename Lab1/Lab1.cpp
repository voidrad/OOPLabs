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
        return (a.area() < area());
    };

    int isBiggerPerimeter(Rectangle a){
        return (a.perimeter() < perimeter());
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
        BigBro->x1 = fmin(fmin(x1,x2),fmin(a.x1,a.x2));
        BigBro->x2 = fmax(fmax(x1,x2),fmax(a.x1,a.x2));
        return *BigBro;
    };
    double x1,y1,x2,y2;


};

int main(){
double a,b,c,d;
cout << "vvedite koordinati pervoi figuri\n";
cin >> a >>b >> c >>d;
Rectangle First(a,b,c,d);
cout << "vvedite koordinati vtoroi figuri\n";
cin >> a >>b >> c >>d;
Rectangle Second(a,b,c,d);
 cout << "area of first rectangle " << First.area() << "\n";
 cout << "Perimeter of second rectangle " << Second.perimeter() <<"\n";
 Rectangle Third;
 Third = First.LilRect(Second);
 cout <<"Koordinati ih peresechenia "<< Third.x1 << " " << Third.y1 << " " << Third.x2 << " " << Third.y2 << " \n";
 Third = First.BigRect(Second);
 cout <<"Koordinati ih obiedinenia "<< Third.x1 << " " << Third.y1 << " " << Third.x2 << " " << Third.y2 << " \n";
 cout <<" Bolshe li area pervogo chem y vtorogo "<< First.isBiggerArea(Second) << " \n";
 cout <<" Bolshe li perimeter pervogo chem y vtorogo "<< First.isBiggerPerimeter(Second)<< "\n";
 cout << " Peremestim 1 Rectangle po osyam \n";
 cin >> a >>b ;
 First.axis(a,b);
 cout << "\nNovie coordinati: \n"<< First.x1 << " " << First.y1 << " " << First.x2 << " " << First.y2 << " \n";
}