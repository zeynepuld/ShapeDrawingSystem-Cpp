# Şekil Çizdirme

Üniversitede Veri Yapıları dersi kapsamında geliştirdiğim C++ konsol uygulaması. Projede iç içe bağlı listeler kullanarak şekilleri oluşturma, görüntüleme ve düzenleme işlemleri üzerinde çalıştım.

## Proje Hakkında

Programda ana menü için çift yönlü bağlı liste, şekilleri tutmak için ise tek yönlü bağlı liste kullandım. Üçgen, dikdörtgen ve yıldız şekillerini ortak bir temel sınıftan türeterek farklı şekilleri aynı liste içerisinde yönetmeye çalıştım.

Şekiller, konsolda 25x100 boyutunda bir karakter matrisi üzerinde çiziliyor. Ayrıca listeler arasında gezinme, şekilleri hareket ettirme ve silme gibi işlemler yapılabiliyor.

## Özellikler

- Çift yönlü bağlı liste ile ana menüyü yönetme
- Tek yönlü bağlı listede şekilleri tutma
- Üçgen, dikdörtgen ve yıldız şekilleri oluşturma ve çizme
- Şekilleri seçme, hareket ettirme ve silme
- Konsol ekranında şekilleri koordinatlarına göre çizme
- Ekran sınırlarını kontrol ederek şekilleri taşırma olmadan hareket ettirme
- Uzun listelerde sayfalama kullanma
- Verileri `veri.txt` dosyasına otomatik kaydetme ve dosyadan yükleme

## Kullanılan Teknolojiler ve Konular

- C++
- Nesne yönelimli programlama
- Sınıflar, kalıtım ve polimorfizm
- Çift yönlü ve tek yönlü bağlı listeler
- Dinamik bellek yönetimi
- Dosya okuma ve yazma
- Karakter matrisi ile konsolda çizim

## Proje Dosyaları

- `MainList.hpp / MainList.cpp`: Ana menüyü tutan çift yönlü bağlı liste
- `ShapesList.hpp / ShapesList.cpp`: Şekilleri tutan tek yönlü bağlı liste
- `Application.hpp / Application.cpp`: Programın genel işleyişini ve kullanıcı etkileşimini yöneten sınıf
- `main`: Uygulamanın başlatıldığı bölüm

## Projenin Amacı

Bu projede bağlı listelerin çalışma mantığını, nesne yönelimli programlamayı ve dosya işlemlerini uygulamalı olarak öğrenmeye çalıştım. Aynı zamanda şekillerin konsol üzerinde çizilmesi ve kullanıcı işlemlerine göre güncellenmesi üzerinde çalıştım.
