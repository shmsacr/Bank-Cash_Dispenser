#include "vadesiz.h"
#include <fstream>
#include <ctime>
#include <chrono>

Vadesiz::Vadesiz(double _money, bool aktif, string name_, string surname_, string tcno_, string hesapno_) :money(_money), Kayit(aktif, move(name_), move(surname_),move(tcno_),move(hesapno_)){}


double Vadesiz::getMoney() const { return money;}

void Vadesiz::setMoney() {
    double ekle;
    double money1;
    cout << "YATiRiLACAK TuTAR:";
    cin >> ekle;
    money1 = ekle + money;
    this->money = money1;
}


void Vadesiz::paracekme(){
    double cekilecek;
    double _money;
    cout << "Cekmek Istediginiz Tutari giriniz:";
    cin >> cekilecek;
    if (getMoney() >=cekilecek ){
        _money = money - cekilecek;
        this ->money = _money;
    } else cout << "Yeterli bakiye bulunamadi!!";

}

void Vadesiz::dosyaya(bool aktif) {
    string data = "data/";
    string ak1 = "musteri_bilgileri.txt";
    string ak = data  + tcno + "/musteri_bilgileri.txt" ;
    fstream dosya1;
    dosya1.open(ak , ios::out);
    dosya1 << "2" << endl
           << aktif << endl
           << name << endl
           << surname << endl
           << hesapno << endl
           << tcno<< endl
           << money;
    dosya1.close();
}