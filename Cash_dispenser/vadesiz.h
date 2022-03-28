#include <iostream>
#include <string>
#include "Kayit.h"
using namespace std;

#ifndef UNTITLED13_VADESIZ_H
#define UNTITLED13_VADESIZ_H
class Vadesiz : public Kayit{
private:
    double money = 0.00;
public:
    Vadesiz() = default;
    Vadesiz(double, bool, string, string, string, string);

    double getMoney() const;

    void setMoney();
    void paracekme();
    void dosyaya(bool);


};

#endif //UNTITLED13_VADESIZ_H
