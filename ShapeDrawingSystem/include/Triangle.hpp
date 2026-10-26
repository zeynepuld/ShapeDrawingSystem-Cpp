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


#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle: public Shape { // Shapeten kalıtım alcak
    public:
        Triangle(int x, int y, int z, int h, char m); // üçgen olduğundan genişliği olmayacak o yüzden yükseklik yeterli
        void cizdir(char ekran[25][100]) override;

        SekilTipi getTip() const override;
    };

#endif