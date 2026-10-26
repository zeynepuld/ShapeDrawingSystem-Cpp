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


// şekilleri tutan ebeveyn class

#ifndef SHAPE_HPP
#define SHAPE_HPP

enum SekilTipi {
    DIKDORTGEN,
    UCGEN,
    YILDIZ
};

class Shape {
    protected: // değişkenlere mainden veya listlerden doğrudan erişilemeyecek. ama bu classtan türeyen çocuk classlardan erişilebilmesi için(star,triangle,rectangle) protected yapıldı.
        int x,y; // şeklin x y koordinatları, kaçıncı satırda başladığı x, kaçıncı sütunda başladığı y
        int z; // z değeri yazılma önceliği
        int width, height;
        char marker;

    public:
        Shape(int x, int y, int z, int w, int h, char m);
        virtual ~Shape();

        virtual void cizdir(char ekran[25][100]) = 0; // sanal çizim fonksiyonu. parametre olarak ekran boyutlarını içeren matris veriliyor
        virtual SekilTipi getTip() const= 0; // şeklin dikdörtgen mi üçgen mi yıldız mı olduğunu getiren fonksiyonu
        // -------------------------

        int getX() const;
        int getY() const;
        int getZ() const;

        int getWidth() const;
        int getHeight() const;
        char getMarker() const;

        void hareketEttir(int newX, int newY);
        
};


#endif