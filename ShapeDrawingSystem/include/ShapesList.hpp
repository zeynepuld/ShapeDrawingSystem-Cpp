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



// tek yönlü bağlı liste -header dosyası
// tüm şekillerin tutulduğu bağlı liste olacak
// menüden bir liste seçildiğinde listenin içine girildiğinde seçenekleri gösterecek
// şekil ekleme, şekil çizdirme, sonraki önceki şekle geçme, şekli silme
// şekilleri listede sıraya dizecek, üzerinde işlemler yapılacak(yönetilecek yani), hafızadan temizleyecek(delete)

#ifndef SHAPESLIST_HPP
#define SHAPESLIST_HPP

#include "Shape.hpp"

class ShapeNode { // düğüm sınıfı
    public:
        Shape* veri;
        ShapeNode* sonraki;

        ShapeNode(Shape* veri);
        ~ShapeNode();
};


class ShapesList { // liste sınıfı
    private:
        ShapeNode* ilk;
        ShapeNode* secili;

    public:
        ShapesList();
        ~ShapesList();

        void siraliEkle(Shape* sekil); // şekilleri z değerine göre sıralı ekleyecek fonksiyon
        void tumunuCizdir(char ekran[25][100]); // şekilleri ekrana çizdirme fonksiyonu

        void sonrakiSekil(); // sonraki şekli seçer
        void oncekiSekil(); // önceki şekli seçer
        Shape* seciliSekliGetir(); // seçili şeklin adresini getirir

        void seciliyiSil(); // seçili şekli listeden siler

        ShapeNode* ilkiGetir();
        int elemanSayisi();
};

#endif