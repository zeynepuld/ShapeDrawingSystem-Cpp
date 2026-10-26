/*
*   DOSYA ADI : B241210029
*   IC ICE BAGLI LISTELER ANLATIM ODEVI
*   SAKARYA UNIVERSITESI BILGISAYAR MUHENDISLIGI 2. SINIF KAYHAN HOCA 1-C GRUBU
*   1.ODEV
*   Bitiş Tarihi : 23.11.2025
*   ADI : ZEYNEP ULUDAĞ
*   NUMARA : B241210029
*   MAIL : ZEYNEP.ULUDAG2@OGR.SAKARYA.EDU.TR
*/



// iki yönlü bağlı liste - header dosyası
// şekil listesini tutan liste 
// menüdeki listeleri tutan liste olacak
// konsolun solundaki menü kısmı


#ifndef MAINLIST_HPP
#define MAINLIST_HPP

#include "ShapesList.hpp"

class MainNode {
    public:
        ShapesList* sekilListesi;
        MainNode* sonraki;
        MainNode* onceki;

        MainNode();
        ~MainNode();
};

class MainList {
    private:
        MainNode* ilk;
        MainNode* secili;

    public:
        MainList();
        ~MainList();

        void asagiGit(); // menüde aşağıdaki listeyi seçer
        void yukariGit(); // menüde yuakrıdaki listeyi seçer
        void sonaEkle(); // listeye yeni bi eleman ekleme fonksiyonu
        void seciliyiSil(); // menüdeki seçili listeyi hafızadan siler
        // void menuyuYazdir(int baslangicY);
        ShapesList* seciliListeyiGetir(); // f tuşuna basıldığında seçili listenin içine girer
        MainNode* ilkiGetir();
};

#endif