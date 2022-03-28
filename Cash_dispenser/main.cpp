#include <chrono>
#include <iostream>
#include <string>
#include "Kayit.h"
using namespace std;
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "vadeli.h"
#include "vadesiz.h"
#include "cari.h"
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
struct stat info;


bool DirectoryExists(const string& path ){
    string rootDir = "data/";
    rootDir += path;
    if( _access( rootDir.c_str(), 0 ) == 0 ){

        struct stat status;
        stat( rootDir.c_str(), &status );

        return (status.st_mode & S_IFDIR) != 0;
    }
    return false;
}
string time(){
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

    return ctime(&timenow);
}



int hane(const string& tcn){
    int a;
    string data = "data/";
    string ak1 = "musteri_bilgileri.txt";
    string ak = data + tcn + "/";
    fstream dosya1;
    dosya1.open(ak + ak1, ios::in);
    dosya1 >> a;
    dosya1.close();
    return a;

}

void goruntule(string& isim1,  string& soyisim1,  string& tc,  string& hesapnu,  double para){
    cout << "Hesap Sahi:" << isim1 << soyisim1 << endl
         << "TC Kimlik No:" << tc << endl
         << "Hesap Numarasi:"<< hesapnu << endl
         << "Bakiye:"<< para ;
}


void islemler(int num) {
    Kayit yeniKayit;
    Vadeli vade;
    Vadesiz kayitvadesiz;
    Cari kayitcari;
    switch (num) {
        case 1: {
            cout << "---Hesap Olusturma islemi---" << endl << endl
                 << "**Olusturacaginiz Hesabi seciniz**" << endl
                 << "1- Vadeli Hesap Olusturma" << endl
                 << "2- Vadesiz Hesap Olusturma" << endl
                 << "3- Cari Hesap Olusturma" << endl;
            int _num;
            cin >> _num;
            switch (_num) {
                case 1: {
                    int num1;

                    cout << "--Hesap Turunu secini---" << endl
                         << "1- Uzun Vadeli" << endl
                         << "2- Kisa Vadeli" << endl
                         << "3- Cikis ";
                    cin >> num1;

                    if (num1 == 1) {
                        vade.setKayit();
//                        string data = "data/";
                        string ak = "data/" + vade.getTcno() + "/";
//                        string ak1 = "musteri_bilgileri.txt";
                        const char *a = ak.c_str();
                        mkdir(a);

                        vade.dosyaya(0,0,0,1);


                    }
                    else if (num1 == 2) {
                        vade.setKayit();

                        string ak = "data/"+ vade.getTcno() + "/";
                        const char *a = ak.c_str();
                        mkdir(a);

                        vade.dosyaya(1,0,0,1);

                    }
                    else if (num1 == 3) { break; }
                    else cout << "Boyle Bir secenek bulunmadi";

                    break;
                }

                case 2: {
                    kayitvadesiz.setKayit();
//                    string data = "data/";
//                    string ak1 = "musteri_bilgileri.txt";
                    string ak = "data/" + kayitvadesiz.getTcno() + "/";
                    const char *a = ak.c_str();
                    mkdir(a);
                    fstream dosya1;
                    dosya1.open(ak + kayitvadesiz.getHesapno()+".txt",ios::out);
                    dosya1.close();
                     kayitvadesiz.dosyaya(1);

                    break;
                }

                case 3: {
                    kayitcari.setKayit();
//                    string data = "data/";
//                    string ak1 = "musteri_bilgileri.txt";
                    string ak = "data/" + kayitcari.getTcno() + "/";
                    const char *a = ak.c_str();
                    mkdir(a);

                    kayitcari.dosyaya(1);

                    break;

                }
            }
            break;
        }
        case 2: {
            char *tcn = new char[11];

            cout << "--HESAP GORUNTULEME" << endl
                 << "Lutfen TC Kimlik Numaranizi giriniz:";
            cin >> tcn;
            if (DirectoryExists(tcn)) {
                int a;
                string st = tcn;
                  a = hane(st);
                    fstream dosya1;
                    string ak = "data/" + st + "/musteri_bilgileri.txt" ;
                if (a == 0) {
                    dosya1.open(ak, ios::in);

                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vaislem(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);

                        int gun1, ay1;
                        cout << "islem gunu:";
                        cin >> gun1;
                        cout << "islem ayi:";
                        cin >> ay1;

                        vaislem.uzunvade1();
                        vaislem.uzunvade(gun1, ay1, gun, ay);

                        goruntule(isim,soyisim,tc,hesap,money);
                        cout << "Faiz Sonu para miktari:" << vaislem.getMoney2() << endl
                             << "Guncel Faiz miktari:" << vaislem.getMoney1() << endl;


                    }else cout << "Hesabiniz aktif degil!!" << endl;

                }

                if (a == 1) {
                    dosya1.open(ak , ios::in);

                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vaislem(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);


                        int gun1, ay1;
                        cout << "islem gunu:";
                        cin >> gun1;
                        cout << "islem ayi:";
                        cin >> ay1;
                        vaislem.kisavade();
                        vaislem.kisavade1(gun1, ay1, gun, ay);

                        goruntule(isim,soyisim,tc,hesap,money);
                         cout  << "Faiz Sonu para miktari:" << vaislem.getMoney2() << endl
                               << "Guncel Faiz miktari:" << vaislem.getMoney1() << endl;


                    } else cout << "Hesabiniz aktif degil";}
                    if (a == 2) {
                        dosya1.open(ak, ios::in);

                        int hesapdurumu;
                        bool aktif;
                        string isim;
                        string soyisim;
                        string hesap;
                        string tc;
                        double money;
                        dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >>hesap >> tc >> money;

                        dosya1.close();
                        if (aktif == 1) {
                            cout <<"Hesap Bakiyesi:" << money << endl;
                            string oku;
                            goruntule(isim,soyisim,tc,hesap,money);
                            dosya1.open(ak  + hesap + ".txt", ios::in);
                                while(getline(dosya1,oku)){
                                    cout << oku << endl;}
                            dosya1.close();
                        }
                        else cout << "Hesabiniz aktif degil";
                    }
                    if (a == 3) {
                        dosya1.open(ak , ios::in);

                        int hesapdurumu;
                        bool aktif;
                        string isim;
                        string soyisim;
                        string hesap;
                        string tc;
                        double money,borc;
                        dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >>hesap >> tc >> money >> borc;

                        dosya1.close();
                        if (aktif == 1) {
                            goruntule(isim,soyisim,tc,hesap,money);
                            Cari hg(money,borc,aktif,isim,soyisim,tc,hesap);
                            cout <<"Borc durumu:" << hg.getBorc();


                        }
                    }



                } else cout << "Boyle bir hesap yok!!!" << endl;

                break;
            }


        case 3: {
            char *tcn = new char[11];
            cout << "--PARA YATiRMA--" << endl
                 << "Lutfen TC Kimlik Numaranizi giriniz:";
            cin >> tcn;
            if (DirectoryExists(tcn)) {
                int a;
                string st = tcn;
                a = hane(st);
                fstream dosya1;
                string ak = "data/" + st + "/musteri_bilgileri.txt" ;


                if (a == 0) {
                    dosya1.open(ak, ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vaislem(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                        int gun1, ay1;
                        cout << "islem gunu:";
                        cin >> gun1;
                        cout << "islem ayi:";
                        cin >> ay1;
                        vaislem.setMoney();
                        vaislem.dosyaya(0, gun1, ay1, 1);


                    } else cout << "Hesabiniz Aktif Degil!!!!!";
                }
                if (a == 1) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vadef(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                        int gun1, ay1;
                        cout << "islem gunu:";
                        cin >> gun1;
                        cout << "islem ayi:";
                        cin >> ay1;
                        vadef.setMoney();
                        vadef.dosyaya(1, gun1, ay1, 1);
                    } else cout << "Hesabiniz aktif degil";
                }
                if (a == 2) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadesiz vadeh(money, aktif, isim, soyisim, tc, hesap);
                        vadeh.setMoney();
                        vadeh.dosyaya(1);
                        dosya1.open(ak + "/" + vadeh.getHesapno() + ".txt", ios::in | ios::out | ios::ate);
                        dosya1 << time() + "Tarihinde para yatirildi" << endl;
                        dosya1.close();

                    } else cout << "Hesabiniz Aktif Degil!!!!!";
                }
                if (a == 3) {

                    dosya1.open(ak , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, borc;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money >> borc;
                    dosya1.close();

                    if (aktif == 1) {
                        Cari cari(money, borc, aktif, isim, soyisim, tc, hesap);
                        cari.parayatirma();
                        cari.dosyaya(1);
                    } else cout << "Hesabiniz Aktif Degil!!!!!" << endl ;


                }

            } else cout << "Boyle bir kullanici bulunamadi!!!";
            break;
        }

        case 4: {
            char *tcn = new char[11];
            cout << "--PARA CEKME ISLEMI--" << endl
                 << "Lutfen TC Kimlik Numaranizi giriniz:";
            cin >> tcn;
            string st = tcn;
            if (DirectoryExists(tcn)) {
                int a;
                string st = tcn;
                a = hane(st);
                fstream dosya1;
                string ak = "data/" + st + "/musteri_bilgileri.txt" ;

                dosya1 >> a;
                dosya1.close();
                if (a == 0) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vadef(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                        vadef.cekme();
                        vadef.dosyaya(0,gun,ay,1);
                    }}
                if (a == 1) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadeli vadef(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                        vadef.cekme();
                        vadef.dosyaya(1,gun,ay,1);
                    }
                }
                if (a == 2) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money;
                    dosya1.close();
                    if (aktif == 1) {
                        Vadesiz vadeh(money, aktif, isim, soyisim, tc, hesap);
                        vadeh.paracekme();
                        vadeh.dosyaya(1);
                        dosya1.open(ak + "/" + vadeh.getHesapno() + ".txt", ios::in | ios::out | ios::ate);
                        dosya1 << time() + "Tarihinde para Cekildi" << endl;
                        dosya1.close();
                    } else cout << "Hesabiniz Aktif Degil!!!!!";}
                if (a == 3) {
                    dosya1.open(ak  , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, borc;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money >> borc;
                    dosya1.close();
                    if (aktif == 1) {
                        Cari cari(money, borc, aktif, isim, soyisim, tc, hesap);
                        cari.paracekme();
                        cari.dosyaya(1);
                    } else cout << "Hesabiniz Aktif Degil!!!!!";
//

                }
            } else cout << "Boyle bir kullanici bulunamadi!!!"<< endl;
            break;
        }
        case 5:{

            char *tcn = new char[11];
            cout << "HESAP KiTLEME"<< endl
                 << "Lutfen TC Kimlik Numaranizi giriniz:";
            cin >> tcn;

            if (DirectoryExists(tcn)) {
                int a;
                string st = tcn;
                a = hane(st);
                fstream dosya1;
                string ak = "data/" + st + "/musteri_bilgileri.txt" ;
                if (a == 0) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    cout << "1- Hesap Kitle" << endl
                         << "2- Hesap acma" << endl;
                    int b;
                    cin >> b;
                    if (b == 1)
                        aktif = false;
                    if (b == 2)
                        aktif = true;
                    Vadeli akt(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                    akt.dosyaya(hesapdurumu, gun, ay,aktif);
                }
                if (a == 1) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu, gun, ay;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, snmoney, gnmoney;
                    dosya1 >> hesapdurumu >> aktif >> gun >> ay >> isim >> soyisim >> tc >> hesap >> money >> snmoney
                           >> gnmoney;
                    dosya1.close();
                    cout << "1- Hesap Kitle" << endl
                         << "2- Hesap acma" << endl;
                    int b;
                    cin >> b;
                    if (b == 1)
                        aktif = false;
                    if (b == 2)
                        aktif = true;
                    Vadeli akt(money, gnmoney, snmoney, aktif, isim, soyisim, tc, hesap);
                    akt.dosyaya(hesapdurumu, gun, ay,aktif);
                }
                if (a == 2) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money;
                    dosya1.close();

                    cout << "1- Hesap Kitle" << endl
                         << "2- Hesap acma" << endl;
                    int b;
                    cin >> b;
                    if (b == 1){
                        aktif = false;
                        dosya1.open(ak  + hesap + ".txt", ios::in | ios::out | ios::ate);
                        dosya1 << time() + "Tarihinde Hesap kitlendi," << endl;
                        dosya1.close();}
                    if (b == 2){
                        aktif = true;
                        dosya1.open(ak +hesap + ".txt", ios::in | ios::out | ios::ate);
                        dosya1 << time() + "Tarihinde Hesap acildi." << endl;
                        dosya1.close();}
                    Vadesiz akt(money,aktif,isim,soyisim,tc,hesap);
                    akt.dosyaya(aktif);

                }
                if (a == 3) {
                    dosya1.open(ak , ios::in);
                    int hesapdurumu;
                    bool aktif;
                    string isim;
                    string soyisim;
                    string hesap;
                    string tc;
                    double money, borc;
                    dosya1 >> hesapdurumu >> aktif >> isim >> soyisim >> hesap >> tc >> money >> borc;
                    dosya1.close();
                    cout << "1- Hesap Kitle" << endl
                         << "2- Hesap acma" << endl;
                    int b;
                    cin >> b;
                    if (b == 1)
                        aktif = false;
                    if (b == 2)
                        aktif = true;
                    Cari ktr(money, borc, aktif, isim, soyisim, tc, hesap);
                    ktr.dosyaya(aktif);

                }

        }else cout <<"Boyle bir hesap yok!!"<< endl;
            break;
        }
    }

}

int main() {

    srand(time(NULL));
int num;
    do {
        cout << "******BANKA MENUSU******"<<endl
             <<"1- Banka Kayit islemleri."<<endl
             <<"2- Hesap Goruntuleme"<<endl
             <<"3- Para yatirma islemi"<<endl
             <<"4- Para Cekme islemi"<<endl
             <<"5- Hesap Kitleme islemi"<<endl
             <<"6- Exit"<<endl
             <<"----Yapacagini islemi seciniz---"<<endl; cin >> num;


        while(num<1 || num >6){
            cout << "Lutfen yapacaginiz islemin numarasin dogru giriniz (1-6):";
            cin >> num;
            break;
        }

        islemler(num);
    }while(num!=6);


    return 0;
}

