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


#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y, int z, int w, int h, char m)
    : Shape(x, y, z, w, h, m) {
    }

void Rectangle::cizdir(char ekran[25][100]) {

    for (int i=0; i < height; ++i) { // satır için
        for (int j = 0; j< width; ++j) { // sütun için
            int drawX = x + j;
            int drawY = y + i;

            if (drawX < 100 && drawX >= 0 && drawY < 25 && drawY >= 0) { // sınırları taşmaması için kontrol
                ekran[drawY][drawX] = marker; // belirlenen karakterde bastırılıyo
            }
        }
    }
}

SekilTipi Rectangle::getTip() const{
    return DIKDORTGEN;
}