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



#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp"

class Rectangle: public Shape {
    public:
        Rectangle(int x, int y, int z, int w, int h, char m);
        void cizdir(char ekran[25][100]) override; // dikdörtgen, üçgen, yıldız bunlar aynı şekilde çizdirilmeyeceği için virtual override kullanılacak

        SekilTipi getTip() const override;
};


#endif