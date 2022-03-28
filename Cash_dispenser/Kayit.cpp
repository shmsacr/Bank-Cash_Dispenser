
#include <string>
#include "vadeli.h"
#include <fstream>
using namespace std;
#include "Kayit.h"
Kayit::Kayit(bool aktif, string newname , string newsurname, string newtcno, string newhesapno) : aktif(aktif), name(std::move(newname)),surname(std::move(newsurname)),tcno(std::move(newtcno)),hesapno(std::move(newhesapno)){}

Kayit::Kayit() = default;

string Kayit::getName() {return name;}
string Kayit:: getSurname(){return surname;}
string Kayit::getTcno(){return tcno;}
string Kayit::getHesapno(){return hesapno;}

void Kayit::setKayit( ){
    string newname, newsurname,newtcno, newhesapno;
    cout << "Adiniz: ";
    cin >> newname ;
    cout << "Soyadiniz: ";
    cin >> newsurname;
    cout << "Tc nonuz: ";
    cin >> newtcno;
    newhesapno = to_string(rand()% 9000 + 1000) + to_string(rand()% 9000 + 1000) + to_string(rand()% 9000 + 1000) + to_string(rand()% 9000 + 1000);

    this->name = newname;
    this->surname = newsurname;
    this->tcno = newtcno;
    this->hesapno = newhesapno;
}








