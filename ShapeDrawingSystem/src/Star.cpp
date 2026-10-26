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

#include "Star.hpp"

Star::Star(int x, int y, int z, int h, char m) : Shape(x, y, z, h, h, m) {}

void Star::cizdir(char ekran[25][100]) {
    int orta = height / 2;

    for (int i = 0; i < height; ++i) {
        int ortadanUzaklik = (i <= orta) ? i : (height - 1 - i);
        
        int solSinir = orta - ortadanUzaklik;
        int sagSinir = orta + ortadanUzaklik;

        for (int j = solSinir; j <= sagSinir; ++j) {
            int drawX = x + j;
            int drawY = y + i;

            if (drawX >= 0 && drawX < 100 && drawY >= 0 && drawY < 25) {
                ekran[drawY][drawX] = marker;
            }
        }
    }
}

SekilTipi Star::getTip() const{
    return YILDIZ;
}