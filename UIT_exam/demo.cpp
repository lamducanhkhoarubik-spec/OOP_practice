#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <Cstring>

using namespace std;


struct Date{
  int day, month, year;
};
bool isLeap(int y){
  return ((y % 4 == 0 && y % 100 != 0) || (y % 400 ==0));
}
int daysBetweenDates(string date1, string date2) {
        int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        Date d1;
        sscanf(date1.c_str(), "%d-%d-%d", &d1.year, &d1.month, &d1.day);
        Date d2;
        sscanf(date2.c_str(), "%d-%d-%d", &d2.year, &d2.month, &d2.day);
        long total1 = d1.year * 365+d1.day;
        long total2 = d2.year * 365+d2.day;
        for (int i = 0; i < d1.month - 1; i++){
            total1 += monthDay[i];
        }
        if (d1.month > 2 && isLeap(d1.year)){
          total1++;
        }
        for (int i = 0; i < d2.month - 1; i++){
            total2 += monthDay[i];
        }
        if (d2.month > 2 && isLeap(d2.year)){
          total2++;
        }
        total1 += ((d1.year-1)/4)-((d1.year-1)/100)+((d1.year-1)/400);
        total2 += ((d2.year-1)/4)-((d2.year-1)/100)+((d2.year-1)/400);
        return abs(total1 - total2);
    }
int main(int argc, char *argv[]){
    string date1 = "2020-01-15";
    string date2 = "2019-12-31";
    cout << daysBetweenDates(date1, date2);
}