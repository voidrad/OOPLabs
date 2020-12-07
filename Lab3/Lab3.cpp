//
// Created by YaTeb on 10/17/2020.
//
#include "vector"
#include "iostream"
#include "Figures.hpp"
using namespace std;


int main(){
vector<Figure> Vector;

    int caseSwitch = 1;
    while(true) {
        cout << "\n______________________________" << endl;
        cout << "|                            |" << endl;
        cout << "|            Menu            |" << endl;
        cout << "|____________________________|" << endl;
        cout << "|                            |" << endl;
        cout << "|1  - Add Figure             |" << endl;
        cout << "|2  - Delete Figure          |" << endl;
        cout << "|3  - Sum of areas           |" << endl;
        cout << "|4  - Working with a figure  |" << endl;
        cout << "|0  - Stop                   |" << endl;
        cout << "|____________________________|" << endl;
        cin >> caseSwitch;
        switch (caseSwitch) {
            case 0:return 1;
            case 1:{
                cout<< "Which kind of figure would you like to add?\n 1:Square\n2:Rectangle\n3:Trapezoid\n";
                int addFig;
                cin>> addFig;
                switch (addFig) {
                    case 1:{cout<< "\nInsert coords of 2 diagonal angles";
                            Vector.push_back(*new Square());}continue;
                    case 2:{cout<< "\nInsert coords of 2 diagonal angles";
                        Vector.push_back(*new Rectangle());}
                        continue;
                    case 3:{cout<< "\nInsert coords of 4 angles";
                        Vector.push_back(*new Trapezoid());}continue;
                    default:cout<<"\nThat's not good!\n";   continue;
                }
            }
            case 2:{
                cout << "\nchoose a Figure to delete:\n";
                int Del;
                cin >> Del;
                if ((Del<0) || (Del > Vector.size())){
                    cout<< "figure not available"; continue;
                } else {
                }
            }continue;
            case 3:{
                for(int i = 0;i<= Vector.size();i++){
                    double Result = 0;
                    Result += Vector[i].getSquare();
                    cout << Result;
                }
            }continue;
            case 4:{
                cout << "\nchoose a Figure to work with:\n";
                int Wrk;
                cin >> Wrk;
                if ((Wrk<0) || (Wrk > Vector.size())){
                    cout<< "figure not available"; continue;
                } else {int Act;
                    cout << "\nWhat do you want to do with figure?\n 1:Get Center\n 2: Get her Coords\n 3: Get her Square\n";
                    cin >>  Act;
                    switch (Act) {
                        case 1:{
                            cout << "Center x is: " <<Vector[Wrk].getCenter().x << "y is " <<Vector[Wrk].getCenter().y;
                        }continue;
                        case 2:{
                           Vector[Wrk].coordsOut();
                        }continue;
                        case 3:{
                            cout<< "\n Her Square is " << Vector[Wrk].getSquare();
                        }continue;
                    }
                }
            }
            default:{
                cout<< "\nSomethings wrong, Try again\n";
            }
        }

        return 0;
    }
    return 0;
}