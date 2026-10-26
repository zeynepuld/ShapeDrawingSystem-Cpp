// program çalıştığında bu dosyadaki işlemler başlatılacak. mainde çağırılacak olan fonksiyonlar burada.

#include "Application.hpp"
#include "ReadFile.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Star.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Application::Application() {
    this->mainList = new MainList();
    this->devamEt = true;
    this->menuBaslangicIndeksi=0;
}

// Application::~Application() {

//     if (mainList) {
//         delete mainList;
//     }
// }
Application::~Application() {
    ReadFile::dosyaYaz(mainList, "veri.txt");
    if (mainList) {
        delete mainList;
    }
}

void Application::ekraniTemizle() {
    for (int i = 0; i < 25; i++) { // her bir satır için
        for (int j = 0; j < 100; j++) { // her bir sütun için
            ekran[i][j] = ' ';
        }
    }// ///** */
}

Shape* Application::rastgeleSekilOlustur() {
    int tip = rand() %3; // oluşturulacak şekil seçilecek: 0: dikdörtgen, 1: üçgen veya 2: yıldız seçer. enum kullanıldı.
    int x = rand() %90; 
    int y = rand() %20; 
    int z = rand() %10; 
    int w = (rand() %8) +3; // genişliği ve yüksekliği 3-10 arası belirledim
    int h = (rand() %8) +3; 
    
    char semboller[] = {'*', '#', '+', 'o', '@', 'X'};
    char m = semboller[ rand() %6]; // şeklin oluşturulacağı sembol seçiliyor rastgele

    if (tip == 0) {
        return new Rectangle(x, y, z, w, h, m);
    }
    else if (tip == 1) {
        return new Triangle(x, y, z, h, m);
    }
    else
        return new Star(x, y, z, h, m);
}
///////7*****************

void Application::rastgeleListeOlustur() {
    int listeSayisi = 20; // menüde 20 tane liste tutulacak. ama konsolda 6 tanesi görünecek kalanları altına dizilecek kaydırmalı yani o yüzden scrolling mantığıyla yaptım

    for (int i= 0; i< listeSayisi; i++) {
        mainList->sonaEkle(); 
        MainNode* sonListe = mainList->ilkiGetir();
        while(sonListe->sonraki != 0){
            sonListe = sonListe->sonraki;
        }//derle kontrol//////////////////////
/////////***************************** */

        int sekilSayisi = (rand() % 6) + 2; // her bir liste içinde 2-7 arası şekil tutacak.
        for (int j= 0; j< sekilSayisi; j++) {
            sonListe->sekilListesi->siraliEkle(rastgeleSekilOlustur());
            ////////////bi daha kontrol
        }
    }
}


void Application::menuyuYazdir(ShapesList* seciliListe, const char* altMesaj) { // soldaki 20 düğümlük listeyi yazdırıyor
    system("cls"); 

    int seciliIndeks = 0; // seçilen listenin sırasını tutacak indeksini

    MainNode* gecici = mainList->ilkiGetir();
    while(gecici != 0) {
        if(gecici->sekilListesi == seciliListe) { // seçili listenin indeksini bulmaya çalışıyorum
            break;
        }
        
        gecici = gecici->sonraki;
        seciliIndeks++;
        //***************** */
    }
    
    // if (seciliIndeks < menuBaslangicIndeksi) { // menüde yukarı çıkılıyorsa
    //     menuBaslangicIndeksi = seciliIndeks;
    // }
    // else if (seciliIndeks >= menuBaslangicIndeksi + 6) { // menüde aşağı iniliyorsa
    //     menuBaslangicIndeksi = seciliIndeks - 5;
    // }
 ////////7********************/
    int sayfaKapasitesi = 6;
    menuBaslangicIndeksi = (seciliIndeks / sayfaKapasitesi) * sayfaKapasitesi;

    MainNode* deneme = mainList->ilkiGetir();
    for(int k=0; k< menuBaslangicIndeksi;k++) {
        if(deneme!= 0){
            deneme=deneme->sonraki;
        }
    }

    for (int i = 0; i < 25; i++) {
        int kalan = i % 4; // menüdeki her bir liste 4 satırdan oluşacak 0,1,2,3 buna göre tasarımını aşağıda yapıcam.
        
        if (deneme != 0) {
            if (kalan == 0) { // lsitenin ilk satırıysa
                cout << "**********";
                if (deneme->sekilListesi == seciliListe){
                    cout << " <--";
                }
                else
                    cout << "     ";
            }
            else if (kalan == 1) { // listenin ikinci satırı içinde eleman sayısını (şekil sayısını) tutacak.
                int adet = deneme->sekilListesi->elemanSayisi();
                cout << "*** " << adet << "  ***";
                if (deneme->sekilListesi == seciliListe){
                    cout << " <--";
                }
                else
                    cout << "     ";
            }
            else if (kalan == 2) { // listenin üçüncü satırının tasarımı
                cout << "**********";
                if (deneme->sekilListesi == seciliListe){
                    cout << " <--";
                }
                else
                    cout << "     ";
            }
            else if (kalan == 3) { // listeler arası bir satır boşluk bıraktım
                cout << "         ";
                deneme = deneme->sonraki; 
            }
        } else {
            cout << "         ";
        }   cout << "\t";

        for (int j = 0; j < 100; j++) {
            cout << ekran[i][j];
        }
        cout << endl; 
    }
    
    cout << endl;
    // cout << "(ws) hareket   (f) listeyi sec   (c) sil : ";
    cout << altMesaj; // alt menude secenekleri gosteren kisim
}

// }//******************************* */

void Application::calistir() {
    srand(time(0));
    system("cls");

    cout << "-------------------HOSGELDINIZ!!-----------------------" << endl; // baslangic ekrani
    cout << "Sekiller nasil olusturulsun? " << endl;
    cout << "1) Rastgele olustur" << endl;
    cout << "2) Dosyadan oku" << endl;
    cout << "-------------------------------------------------------" << endl;

    char secim;
    cin >> secim;

    if (secim == '1') rastgeleListeOlustur();
    else ReadFile::dosyaOku(mainList, "veri.txt");

    while (devamEt) {
        ekraniTemizle();
        
        ShapesList* seciliListe = mainList->seciliListeyiGetir();

        if (seciliListe != 0) {
            seciliListe->tumunuCizdir(ekran);
        }

        char secilen;
        menuyuYazdir(seciliListe, "(ws) hareket   (f) listeyi sec   (c) sil : "); cin >> secilen;

        /////////******************** */
        if (secilen == 'w') mainList->yukariGit();
        else if (secilen == 's') mainList->asagiGit();
        else if (secilen == 'c'){
            mainList->seciliyiSil();
            ReadFile::dosyaYaz(mainList, "veri.txt");
        }
        else if (secilen == 'f')
        {
            if(seciliListe!=0) { // menüdeki tüm listeler silinmişse f'e basıldığında çalışmaması için kontrol edkliyorum
                bool sekilModuAktif = true;
                while (sekilModuAktif) {
                    ekraniTemizle();
                    seciliListe->tumunuCizdir(ekran);
                        
                    menuyuYazdir(seciliListe, "(awsd) hareket   (q) onceki sekil   (e) sonraki sekil   (c) sekli sil   (g) geri don : ");

                    char sekilTusu;
                    cin >> sekilTusu;

                    if (sekilTusu == 'g') {
                        sekilModuAktif = false;
                    }
                    else if (sekilTusu == 'c') {
                        seciliListe->seciliyiSil();
                        ReadFile::dosyaYaz(mainList, "veri.txt");

                        if (seciliListe->elemanSayisi() == 0){
                            sekilModuAktif = false;
                            mainList->seciliyiSil(); // listenin içindeki tüm elemanlar (şekiller) silindiyse düğümü listeden sil. ana menüye geri dön otomatik
                            ReadFile::dosyaYaz(mainList, "veri.txt"); // değişiklikler kaydediliyor
                        }
                    }
                    else if (sekilTusu == 'q') {
                        seciliListe->oncekiSekil();
                    }
                    else if (sekilTusu == 'e') {
                        seciliListe->sonrakiSekil();
                    }

                    else { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DİKKAT sınır kotrolleri
                        Shape* s = seciliListe->seciliSekliGetir();
                        if (s != 0) {
                            int x = s->getX();
                            int y = s->getY();

                            int w = s->getWidth();
                            int h = s->getHeight();

                            if (sekilTusu == 'w') y--; // seçili şekli öteleme hareketleri burda wasd ile yukarı aşağı sağa sola
                            else if (sekilTusu == 's') y++;
                            else if (sekilTusu == 'a') x--;
                            else if (sekilTusu == 'd') x++;

                            if (x<0) x = 0; // alt ve üst sınır kontrolleri için. şekillerin şekli bozulmayacak şekilde sınırlara çarptığında hiçbir şey değişmeyecek. silinmeyecek de.
                            if(x>100 -w) x = 100 -w;
                            
                            if(y<0) y=0;
                            if (y>25 -h) y= 25 -h;
                            ////////////////7***********************

                            s->hareketEttir(x, y);

                            ReadFile::dosyaYaz(mainList, "veri.txt");
                        }
                    }
                }
            }
        }
    }
   // system("cls");

}