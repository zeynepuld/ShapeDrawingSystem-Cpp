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



// iki yönlü bağlı liste - kaynak dosyası
// soldaki menüyü yöneten listenin kaynak kodları

#include "MainList.hpp"
#include <iostream>
using namespace std;

MainNode::MainNode() {
    this->sekilListesi = new ShapesList();
    this->sonraki = 0;
    this->onceki = 0;
}

MainNode::~MainNode() {
    if(sekilListesi) {
        delete sekilListesi;
    }
}

// /        ///

MainList::MainList() {
    ilk = 0;
    secili = 0;
}

MainList::~MainList() {
    MainNode* gecici = ilk; // yine ilkin adresini kaybetmemek için geçici değişken atanıyorü sonra silinecek bu

    while (gecici != 0) {
        MainNode* silinecek = gecici;
        gecici = gecici->sonraki;

        delete silinecek;
    }
}//********************************* */son mola ver

void MainList::sonaEkle() { // menüye yeni bir liste ekleme fonksiyonu
    MainNode* yeni = new MainNode();

    if (ilk == 0) {
        ilk = yeni;
        secili = yeni;
    }
    else {
        MainNode* taranan = ilk;

        while (taranan->sonraki != 0) { // en sondaki elemanı arar bulur ve yeni elemanı ondan sonrsya ekler
            taranan = taranan->sonraki;
        }
        
        taranan->sonraki = yeni;
        yeni->onceki = taranan; // iki yönlü bağlı liste, önceki ve sonraki düğümleri birbrine bağlamak içni
    }
}
////////////////////////////

void MainList::yukariGit() { // menüde yukarı gezer, önceki listeye gelir yani
    if (secili != 0 && secili->onceki != 0) {
        secili = secili->onceki;
    }
}
void MainList::asagiGit() { // menüde aşağı gider, sonraki listeyi seçer
    if (secili != 0 && secili->sonraki != 0) {
        secili = secili->sonraki;
    }
}
/////////////////////

void MainList::seciliyiSil() {
    // şöyle ki 1- listede tek eleman varsa tüm listeyi silecek hafızadan
    // 2- listenin başındaki siliniyosa öncekini null yapacak, sonrakini de ilkine bağlayacak
    // 3- listenin sonundaki siliniyosa sonrakini null yapacak, öncekine bağlayacak
    /// 4- aradan eleman siliniyosa da öncekini sonrakine, sonrakini öncekine bağlayacak.
    ////////////////////////////////////////

    if (ilk == 0 || secili == 0) return;
///////////////// //************************** */

    MainNode* silinecek = secili;

    if (silinecek == ilk && silinecek->sonraki == 0) {
        ilk = 0;
        secili = 0;
    }
    else if (silinecek == ilk) {
        ilk = ilk->sonraki;
        ilk->onceki = 0;
        secili = ilk;
    }
    else if (silinecek->sonraki == 0) {
        silinecek->onceki->sonraki = 0;
        secili = silinecek->onceki;
    }
    else {
        silinecek->onceki->sonraki = silinecek->sonraki; //
        silinecek->sonraki->onceki = silinecek->onceki;
        secili = silinecek->sonraki;
    }

    silinecek->sonraki = 0;
    silinecek->onceki = 0;
    ////////////////
    delete silinecek;
}//***** onemli!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

ShapesList* MainList::seciliListeyiGetir() {
    if (secili) {
        return secili->sekilListesi; // listenin içine girer
    }

    return 0;
}

// ****************************************
// void MainList::menuyuYazdir(int baslangicY) {
//     /// / //

//     MainNode* taranan = ilk;
//     int index = 1;

//     while (taranan != 0) {

//         if (taranan == secili) cout << "-> ";
//         else
//             cout << "   ";
//         ////*
//         cout << index << ". Liste (" 
//             << taranan->sekilListesi->elemanSayisi() << " Sekil)" << endl;
// //************//

//         taranan = taranan->sonraki;
//         index++;
//     }
// }

MainNode* MainList::ilkiGetir() { 
    return ilk; // listenin başının kaybolaaması için ilkin adresi !!!***************
}