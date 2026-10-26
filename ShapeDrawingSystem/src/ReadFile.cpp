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



// şekiller burada çizdirilecek
// işlemler de burda
// program kapatıldığında veriler dosyalara yüklensin kaydedilsin, tekrar açıldığında dosyadan okunsun

#include "ReadFile.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <fstream>
using namespace std;


bool ayniKelimeMi(const char* a, const char* b) {
    while (*a == *b) { // aynı kelime mi (adresleri aynı mı) kontrolü iiçin
        if (*a == 0){
            return true;
        }
        
        a++;
        b++;
    }
    return false; // kelimeler aynı değil false döndürecek
}
////*///////////// //*


void ReadFile::dosyaYaz(MainList* mainList, const char* dosyaAdi) { // dosyaya yazdırılacak kayıt tutulacak

    ofstream dosya(dosyaAdi);

    if (!dosya.is_open()) return; // dosya açılıyo mu açılmıyor mu kontrolü, açılmıyorsa hata ver program sonlandırır
///////////////////********
 /**/
    MainNode* dugumGecici = mainList->ilkiGetir();
    
    while (dugumGecici != 0) { // tasarımmmmmm kısmı - dosyaya nasıl yazdırılacak???????
        dosya << "----------------------------------------" << endl;
        dosya << "LISTE" << endl;
        
        ShapeNode* sekilGecici = dugumGecici->sekilListesi->ilkiGetir();

        while (sekilGecici != 0) {
            Shape* s = sekilGecici->veri;
            
            dosya << "----------------------------------------" << endl;
            dosya << "DATA "; // bilgisayar data yazısından sonraki verileri alacak artık onlara göre ekrana çizdirecek dosyadan getirecek
            ////////////////////////////////************** */

            SekilTipi tip = s->getTip(); /// enum olarak alıncak şeklin tipi. 0 : dikdörtgen, 1: üçgen, 2: yıldız için

            if (tip == DIKDORTGEN) { // şekillerin tipine göre (üçgen-dikdörthen-yıldız ) dosyaya yazdırılıyor
                dosya << "RECTANGLE ";
            }
            else if (tip == UCGEN) {
                dosya << "TRIANGLE ";
            }
            else if (tip == YILDIZ) {
                dosya << "STAR "; }
            // ----------------------------//
            
            dosya << s->getX() << " " // şeklin özellikleri x,y,z,w,h,m sırasıyla
                  << s->getY() << " " 
                  << s->getZ() << " "
                  << s->getWidth() << " "
                  << s->getHeight() << " "
                  << s->getMarker() << endl; dosya << endl; 
            ///////////bitti

            int h = s->getHeight(); // dosyaya şeklin resmini de çizdirioruz
            char m = s->getMarker();

// **********************************
            // burda tipi belirlenen şeklin çizimi yapılıyor. dosyada şeklin görselinin de olması için
            if (tip == DIKDORTGEN) {
                int w = s->getWidth();

                for(int i=0; i< h; i++) {           // satır kadar dönecek

                    for(int j= 0; j< w; j++) {      // sütun kadar dönecek
                        dosya << m;
                    } dosya << endl;
                } // tmam dikdörtgen çizidrildi

            }
            else if (tip == UCGEN) {
                int ortaNokta = h-1;  // burası tepe noktası olacak
                int toplamGenislik = 2*h -1; // üçgenin tabanı, en alt satır ne kadar genişlikte

                for (int i= 0; i< h; ++i) {

                    int baslangic = ortaNokta - i; // ortadan sole ve sağa birer birer açılarak üçgen şeklini aldırmaya çalıştım
                    int bitis = ortaNokta + i;

                    for (int k= 0; k < toplamGenislik; k++) { // sınır kontrolü sınırlar içindeyse şekli dosyaya yazdırır, henüz sınır a gelinmediyse boşluk yazdırır
                        if (k>= baslangic && k<= bitis) { 
                            dosya << m;
                        }
                        else if (k < baslangic) {
                            dosya << " ";
                        }
                    }dosya << endl;
                }
            }else if (tip == YILDIZ) {

                int orta = h/2;               /// yıldız çizilirken en çok karakterin olacağı orta noktayı belilrliyorum

                for (int i = 0; i < h; ++i) {
                    int uzaklik = (i <= orta) ? i: (h-1 -i);
                    
                    int solSinir = orta - uzaklik;      // yıldızın başladığı satır
                    int sagSinir = orta + uzaklik;      // yıldıızn bittiği satır
/////////************************************** */

                    for(int k= 0; k< h; k++) {
                        if( k >= solSinir && k <= sagSinir) { // sınırlar içindeyse çizilir değilse boşluk koy yine
                            dosya << m;
                        }
                        else {
                            dosya << " ";
                        }
                    }dosya << endl;
                } // yıldız da çizdiirdim yani insallah cizilmistir amin
            }
            
            dosya << endl; sekilGecici = sekilGecici->sonraki; // sonraki şekle geçiyurum
        }

        dugumGecici = dugumGecici->sonraki; // sonraki listeye geçiyorum
    }
    dosya << "----------------------------------------" << endl;


    dosya.close(); ////////////*************** dosya kapandı */
}


void ReadFile::dosyaOku(MainList* mainList, const char* dosyaAdi) { // dosyadan okuma- kullanıcı 2yi seçerse şekileri (kaydedilmişti)dosyadna okuyor.

    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) return;
///////////////*************** */

    char kelime[50];  // kelimeler dizisi ama geçici oalcak, kelimelerin tek tek okunup diziye atanmasını sağlayacağım.

    while (dosya >> kelime) {

        if (ayniKelimeMi(kelime, "LISTE")) { // liste kelimesini gördüğünde yeni bi düğüm ekliyor menüye.
            mainList->sonaEkle();
        }

        else if (ayniKelimeMi(kelime, "DATA")) { // data kelimesini gördüğünde sonrasında gelen özelliklerle okuyaral şeklin resmini çizdirecek
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ÖNEMLİ Bİ DAHA BAK
            char tipDizi[20]; // elemanları RECTANGLE, STAR, TRIANGLE olan dizi
            dosya >> tipDizi; 

            int x, y, z, w, h;
            char m;
            dosya >> x >> y >> z >> w >> h >> m; // şeklin özelliklerini de sırasyyla dosyaya yazıdıryor

            //!!!!!!!!!!!!!!!!!!!!!!!!1******dön
            Shape* yeniSekil = 0; // gelecek şekli tutması için boş bi pointer, şimdi çizilecek şekil buraya atanacak

///////////////7 şimdi şekil tipi neyse bellekte yeni bi şekil nesnesi oluşturuyor ona gore
            if (ayniKelimeMi(tipDizi, "RECTANGLE")) {
                yeniSekil = new Rectangle(x, y, z, w, h, m);
            }
            else if (ayniKelimeMi(tipDizi, "TRIANGLE")) {
                yeniSekil = new Triangle(x, y, z, h, m);
            }
            else if (ayniKelimeMi(tipDizi, "STAR")) {
                yeniSekil = new Star(x, y, z, h, m);
            }
///////////////7*

            if (yeniSekil != 0) { // şekil doğru bi şekilde çizdiirldiyse menü listesinin en son düğümüne eklemem lazım

                MainNode* sonDugum = mainList->ilkiGetir();
                if (sonDugum != 0) {

                    while (sonDugum->sonraki != 0) {
                        sonDugum = sonDugum->sonraki;
                    }
//////******************************************** */

                    sonDugum->sekilListesi->siraliEkle(yeniSekil); // yeni oluşuturulan şekil, şekil listesine de eklendi sıralı bi şekilde
                }
            }
        }
        
    }

    dosya.close(); ////////////// KAPAT //////////*********************** */
}