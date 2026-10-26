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

#ifndef READFILE_HPP
#define READFILE_HPP

#include "MainList.hpp"

class ReadFile {
    public:
        static void dosyaOku(MainList* mainList, const char* dosyaAdi);
        static void dosyaYaz(MainList* mainList, const char* dosyaAdi);
};


//************************ */

#endif