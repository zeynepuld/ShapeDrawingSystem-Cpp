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


// tek yönlü bağlı liste (şekilleri tutacak liste) -kaynak dosyası
// header dosyasındaki fonksiyonların gövdeleri yazılacak

#include "ShapesList.hpp"
#include <iostream>

ShapeNode::ShapeNode(Shape* veri) {
    this->veri= veri;
    this->sonraki = 0;
}

ShapeNode::~ShapeNode() {
    if(veri) delete veri;
} // /
//////////////************************ */

ShapesList::ShapesList() {
    ilk = 0;
    secili = 0;
}

ShapesList::~ShapesList() {
    ShapeNode* gecici = ilk; // ilkin adresini kaybetmemek için silme işlemi yaparken bunu geçici bi değişkene atadım, sonra bunu silinecek yapıp delete ile silicem.

    while (gecici != 0) {
        ShapeNode* silinecek = gecici;


        gecici = gecici->sonraki;

        delete silinecek;
    }
} //
//***************************** */

void ShapesList::siraliEkle(Shape* sekil) { // şekiller hareket ettirilirken önce çizilen arkada, sonra çizilen önde kalacak
    ShapeNode* yeni = new ShapeNode(sekil);

    if (ilk == 0 || sekil->getZ() < ilk->veri->getZ()) { // liste boşsa veya yeni eklenecek şeklin z değeri baştaki şeklin z değerinden küçükse yeni şekli listenin en başına ekler
        yeni->sonraki = ilk;

        ilk = yeni;
    }
    else { // araya ekleme, sona ekleme
        ShapeNode* taranan = ilk;

        while (taranan->sonraki != 0 && taranan->sonraki->veri->getZ() <= sekil->getZ()) { // bi sonraki eleman varsa mevcutsa ve sonrakinin z değeri daha küçük ya da eşitse devam et
            
            taranan = taranan->sonraki;
        }
        
        yeni->sonraki = taranan->sonraki; // düğümleri birbirine bağla
        taranan->sonraki = yeni;
    }
    if (secili == 0) secili = ilk; // eleman seçilmediyse ilk elemanı seç
}

void ShapesList::tumunuCizdir(char ekran[25][100]) { // listedeki her şekli, ekrana çizdrir
    ShapeNode* taranan = ilk;
//      /

    while (taranan != 0) {
        taranan->veri->cizdir(ekran);

        taranan = taranan->sonraki;
    }
}

void ShapesList::sonrakiSekil() {
    if (secili != 0 && secili->sonraki != 0) {
        secili = secili->sonraki;
    }
}

void ShapesList::oncekiSekil() {
    if (secili == 0 || secili == ilk)
        return;

    ShapeNode* taranan = ilk;
    while (taranan->sonraki != secili) {

        taranan = taranan->sonraki;  // listede geriye gidiliypr
    }
    secili = taranan;
}
//******************geri don !!!!!!!!!! */


Shape* ShapesList::seciliSekliGetir() {
    if (secili){
        return secili->veri;}


    return 0;
}

void ShapesList::seciliyiSil() {
    if (ilk == 0 || secili == 0)
        return; /////////////////////////*************** */

    ShapeNode* silinecek = secili;

    if (silinecek == ilk) { // baştan silinecekse
        ilk = ilk->sonraki;

        secili = ilk;
    } 
    
    else { // aradan silinecekse
        ShapeNode* onceki = ilk;

        while (onceki->sonraki != silinecek) {
            onceki = onceki->sonraki;
        }

        onceki->sonraki = silinecek->sonraki;
        
        
        if (silinecek->sonraki != 0)
            secili = silinecek->sonraki;
        else
            secili = onceki;
    }
    silinecek->sonraki = 0; //


    delete silinecek;
}

ShapeNode* ShapesList::ilkiGetir() {
    return ilk;
}
/// ///////7************
///
int ShapesList::elemanSayisi() { //

    int sayac = 0;

    ShapeNode* taranan = ilk;

    while (taranan != 0) { // kaç tane şekil varsa onu hesaplaması için
        sayac++;

        taranan = taranan->sonraki;
    }
//

    return sayac;
}