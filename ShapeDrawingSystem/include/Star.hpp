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



#ifndef STAR_HPP
#define STAR_HPP

#include "Shape.hpp"

class Star : public Shape {
    public:
        Star(int x, int y, int z, int h, char m);
        void cizdir(char ekran[25][100]) override;

        SekilTipi getTip() const override;
};

#endif