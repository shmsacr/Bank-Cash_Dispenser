#include "cari.h"
#include <fstream>
Cari::Cari(double _money,double _borc, bool _aktif, string name_, string surname_, string tcno_, string hesapno_) :
    money(_money),borc(_borc), Kayit(_aktif, move(name_), move(surname_),move(tcno_),move(hesapno_)){}


double Cari::getMoney() const {return money; }
double Cari::getBorc() const{return borc;}

void Cari::parayatirma()  {
    double alacak;
    double _money;
    cout <<"1- Banka hesabina para yatirma"<< endl
         <<"2- Borc hesabina para yatirma" << endl; int a; cin >> a;
    if(a == 1){
        cout << "Yatirilacak para:";
         cin >> alacak;
    _money = alacak + money ;
    this->money = _money;
}
    if (a == 2){
        cout << "Yatirilacak para:";
    cin >> alacak;
    _money = borc + alacak;
    this->borc = _money;
    }
}

void Cari::paracekme() {
    double cekilecek;
    double _money;
    cout << "1- Banka Hesabi"<<endl
         << "2- Borclu hesap"<< endl ;int a; cin >> a;
    if (a == 1){
        cout <<"Cekilecek Miktari giriniz:"<< endl;
    cin >> cekilecek;
        if (money >= cekilecek){
    _money = money - cekilecek;
    this ->money = _money;} else cout <<"Yeterli bakiye bulunamadi!!" << endl ;
    }
    if( a == 2){
        cout <<"Cekilecek Miktari giriniz:"<< endl;
        cin >> cekilecek;
        _money =borc - cekilecek;
        this -> borc = _money;
    }

}
void Cari::dosyaya(bool aktif) {
    string data = "data/";
    string ak1 = "musteri_bilgileri.txt";
    string ak = data  + tcno +  "/musteri_bilgileri.txt" ;
    fstream dosya2;
    dosya2.open(ak , ios::out);
    dosya2 << "3"<< endl
           << aktif << endl
           << name << endl
           << surname << endl
           << hesapno << endl
           << tcno << endl
           << money << endl
           << borc ;
    dosya2.close();

}