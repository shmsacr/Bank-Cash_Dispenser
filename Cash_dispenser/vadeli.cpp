#include "vadeli.h"

#include <utility>
#include <fstream>

Vadeli::Vadeli(double _money,double _gnmoney, double _snmoney,bool aktif, string _name, string _surname, string _tcno, string _hesapno) :
money(_money),gnmoney(_gnmoney),snmoney(_snmoney),Kayit(aktif, move(_name),move(_surname),move(_tcno),move(_hesapno)){}


double Vadeli::getMoney() {return money;}
double Vadeli::getMoney2() {return gnmoney;}

double Vadeli::getMoney1() {return snmoney;}

void Vadeli::uzunvade1() {
    double mon;
    mon = ((money*14)*365)/36500 + money;
    this->gnmoney = mon ;
}
void Vadeli::setMoney() {
    double para, mon;
    cout << "Yatirilacak parayi giriniz:";
    cin >> para;
    mon= para + money;
    this-> money = mon ;}

void Vadeli::uzunvade(int gun, int ay,int gun1, int ay1) {
    double totel;
    int guns,ays;
    guns = gun - gun1;
    ays = ay - ay1;
    totel = ((guns + ays*30)*money)*14/36500 + money ;

    this->snmoney = totel;
}

void Vadeli::kisavade() {
    double mon;
    mon = ((money*8)*365)/36500 + money;
    this ->gnmoney = mon;

}
void Vadeli::kisavade1(int gun, int ay, int gun1, int ay1) {
    double totel ;
    int guns,ays;
    guns = gun - gun1;
    ays = ay - ay1;

    totel = ((guns + ays*30)*money)*8/36500 + money;
    this ->snmoney = totel;

}
void Vadeli::cekme() {
double cek, miktar;
    cout << "Cekmek istediginiz tutari giriniz:";
    cin >> cek;
    if (getMoney() >= cek){
        miktar = money - cek ;
    this->money = miktar;
    }else cout << "Yeterli Bakiye Bulunamadi" << endl ;
}

void Vadeli::dosyaya(int dr,int gun,int ay,bool aktif) {

    string data = "data/";
    string ak1 = "musteri_bilgileri.txt";
    string ak = data  + tcno + "/musteri_bilgileri.txt" ;
    fstream dosya1;
    dosya1.open(ak , ios::out);
    dosya1 << dr << endl
           << aktif<< endl
           << gun << endl
           << ay << endl
           << name << endl
           << surname << endl
           << tcno << endl
           << hesapno << endl
           << money << endl
           << snmoney << endl
           << gnmoney;
    dosya1.close();
}


