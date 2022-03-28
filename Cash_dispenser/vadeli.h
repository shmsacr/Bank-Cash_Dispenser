#include <utility>
#include "Kayit.h"
#ifndef UNTITLED13_VADELI_H
#define UNTITLED13_VADELI_H
class Vadeli: public Kayit{
private:
    double gnmoney = 0.00;
    double snmoney = 0.00;
    double money = 0.00;

public:
    Vadeli()= default;
    Vadeli(double, double, double, bool, string, string, string, string);

    double getMoney();
    double getMoney1();
    double getMoney2();

    void setMoney();
    void uzunvade(int, int, int, int);
    void uzunvade1();
    void kisavade();
    void kisavade1(int, int, int, int);
    void cekme();
    void dosyaya(int, int, int,bool);





};
#endif //UNTITLED13_VADELI_H
