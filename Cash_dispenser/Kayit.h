#include <iostream>
#include <string>

using namespace std;
#ifndef UNTITLED13_KAYIT_H
#define UNTITLED13_KAYIT_H
class Kayit{
protected:
    string  name;
    string  surname;
    string  tcno ;
    string  hesapno ;
    bool aktif;
public:


    Kayit();
    Kayit(bool, string, string, string, string);
    string getName();
    string getSurname();
    string getTcno();
    string getHesapno();

    void setKayit();




};



#endif //UNTITLED13_KAYIT_H
