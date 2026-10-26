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


// Shape.hpp 'deki fonksiyonların gövdesini buraya yazıyorum.
#include "Shape.hpp"

Shape::Shape(int x, int y, int z, int w, int h, char m) { // kurucu fonksiyon
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = w;
    this->height = h;
    this->marker = m;
}

Shape::~Shape() {
    
}

void Shape::hareketEttir(int newX, int newY) {
    this->x = newX;
    this->y = newY;
}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}

int Shape::getZ() const {
    return z;
}

int Shape::getHeight() const {
    return height;
}

int Shape::getWidth() const {
    return width;
}

char Shape::getMarker() const {
    return marker;
}
