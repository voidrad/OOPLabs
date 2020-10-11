//
// Created by YaTeb on 10/10/2020.
//
#include <iostream>
#include <string>
using namespace std;

struct Time {
    int sec,min,hour;
};

class TimePoint {
public:
    TimePoint()= default;;
    TimePoint(int hour_m,int min_m, int sec_m){
        if ((sec_m > 59)||(min_m > 59)||(hour_m >23)|| (sec_m < 0)||(min_m < 0)||(hour_m < 0)){
            cout <<"Vi vveli nepravilnoe vremya";
            return;
        }else {
            time.sec = sec_m;
            time.min = min_m;
            time.hour = hour_m;
        }
    };
    ~TimePoint()= default;;

    TimePoint operator=(const Time &solo){
        TimePoint Result;
        Result.time.hour = solo.hour;
        Result.time.min = solo.min;
        Result.time.sec = solo.sec;
        return Result;
    }

    void SeeTime(){
        cout<< "  " << time.hour << "  " << time.min << "  " << time.sec << "  \n";
    }

    void SumSec(int a){
        a = (a+ time.sec+ time.min*60 +time.hour*3600)%86400;
        time.hour = a/3600;
        time.min =(a - time.hour*3600)/60;
        time.sec = a - time.hour*3600 - time.min*60;

    };

    void MinSec(int a){
        a = (time.sec+ time.min*60 +time.hour*3600 - a)%86400;
        if (a < 0){
            a+=86400;
        }
        time.hour = a / 3600;
        time.min = (a - time.hour * 3600) / 60;
        time.sec = a - time.hour * 3600 - time.min * 60;

    };

    int ToSeconds(){
        return (time.sec+ time.min*60 +time.hour*3600);
    };

    void FromSeconds(int a){
        if (a <0){
            cout<< "Vremya ne mojet bit otrecatelnim";
            return;
        }
        a%=86400;
        time.hour = a/3600;
        time.min =(a - time.hour*3600)/60;
        time.sec = a - time.hour*3600 - time.min*60;
    };

    int ToMinutes(){
        if (time.sec > 29){
            return (time.hour*60 + time.min +1);
        }else{
            return (time.hour*60 + time.min);
        }
    };

    void FromMinutes(int a){
        if (a <0){
            cout<< "Vremya ne mojet bit otrecatelnim";
            return;
        }
        a%=1440;
        time.hour = (a/60);
        time.min = a - time.hour*60;
        time.sec = 0;
        time.hour = time.hour%24;
    };
    Time time{0,0,0};
};

TimePoint operator+(const TimePoint &left, const TimePoint &right ){
    TimePoint Result{ 0,0,0};
    int a;
    a = (left.time.hour*3600+left.time.min*60+left.time.sec + right.time.hour*3600 +right.time.min*60 + right.time.sec)%86400;
    Result.time.hour = a/3600;
    Result.time.min =(a - Result.time.hour*3600)/60;
    Result.time.sec = a - Result.time.hour*3600 - Result.time.min*60;
    return Result;
}

TimePoint operator-(const TimePoint &left, const TimePoint &right ){
    TimePoint Result{ 0,0,0};
    int a;
    a = (left.time.hour*3600+left.time.min*60+left.time.sec - right.time.hour*3600 -right.time.min*60 - right.time.sec)%86400;
    if (a <= 0){
        a+=86400;
    }
    Result.time.hour = a / 3600;
    Result.time.min = (a - Result.time.hour * 3600) / 60;
    Result.time.sec = a - Result.time.hour * 3600 - Result.time.min * 60;
    return Result;

}

bool operator<(const TimePoint &left, const TimePoint &right ){
    if(left.time.hour != right.time.hour){
        return left.time.hour < right.time.hour;
    }else if (left.time.min != right.time.min){
        return left.time.min < right.time.min;
    } else{
        return left.time.sec < right.time.sec;
    }
}

bool operator>(const TimePoint &left, const TimePoint &right ){
    if(left.time.hour != right.time.hour){
        return left.time.hour > right.time.hour;
    }else if (left.time.min != right.time.min){
        return left.time.min > right.time.min;
    } else{
        return left.time.sec > right.time.sec;
    }
}

bool operator==(const TimePoint &left, const TimePoint &right ){
    return (left.time.hour == right.time.hour) && (left.time.min == right.time.min) && (left.time.sec == right.time.sec);
}


TimePoint operator""_time(const char *str, size_t n){
    int result[3];

    string s(str);
    s+= ':';
    short count = 0; int last = 0;
    for (int i = 0; i <= n; ++i) {
        if(s[i] == ':' && count < 3){
            result[count] = stoi(s.substr(last, i - last + 1));
            last = i + 1;
            ++count;
        }
    }
    return TimePoint(result[0],result[1],result[2]);
}


int main(){
    TimePoint First (14,59, 36);
    TimePoint Second (17,59, 36);
    TimePoint Third;
    First.SeeTime();
    First.SumSec(87);
    First.SeeTime();
    First.MinSec(1400);
    First.SeeTime();
    cout << First.ToSeconds() << "   " <<First.ToMinutes() << "  \n";
    Second.SeeTime();
    Third = First + Second;
    Third.SeeTime();
    Third.FromSeconds(43200);
    Third.SeeTime();
    Third.MinSec(64741);
    Third.SeeTime();
    Third.MinSec(43200);
    Third.MinSec(43200);
    Third.SeeTime();
    First = Third;
    Third.SumSec(14000);
    First.SeeTime();
    Third.SeeTime();
    First.FromMinutes(13000);
    First.SeeTime();
    cout << (First > Third) << " " << (First == Third) << "  " << (First < Third);
}