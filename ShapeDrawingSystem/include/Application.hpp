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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "MainList.hpp"
#include "Shape.hpp"

class Application {
    private:
        MainList* mainList;
        char ekran[25][100];
        Shape* rastgeleSekilOlustur();
        void rastgeleListeOlustur();
        int menuBaslangicIndeksi;
        bool devamEt;
        void ekraniTemizle();
        void menuyuYazdir(ShapesList* seciliListe, const char* altMesaj);

    public:
        Application();
        ~Application();
        void calistir();
};

#endif