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

#include "Triangle.hpp"

Triangle::Triangle(int x, int y, int z, int h, char m) : Shape(x, y, z, 0, h, m)
{
    this->width = (2*h) -1;
}

void Triangle::cizdir(char ekran[25][100]) {
    for (int i = 0; i < height; ++i) {
        int charCount = 2 * i + 1;
        
        int bosluk = height - 1 - i;

        for (int k = 0; k < charCount; ++k) {
            int drawX = x + bosluk + k;
            int drawY = y + i;

            if (drawX >= 0 && drawX < 100 && drawY >= 0 && drawY < 25) {
                ekran[drawY][drawX] = marker;
            }
        }
    }
}

SekilTipi Triangle::getTip() const{
    return UCGEN;
}