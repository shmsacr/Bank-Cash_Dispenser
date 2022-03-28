#include <istream>
#include <string>
#include "Kayit.h"
#ifndef UNTITLED13_CARI_H
#define UNTITLED13_CARI_H
class Cari : public Kayit{
private:
    double money = 0.00;
    double borc = 0.00;
public:
    Cari() = default;

    Cari(double,double , bool, string, string , string, string);
    double getBorc()const;
    double getMoney() const;
    void parayatirma();
    void paracekme();
    void dosyaya(bool );

};
#endif //UNTITLED13_CARI_H
