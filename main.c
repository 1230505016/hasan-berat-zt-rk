#include <stdio.h>
#include <string.h>
// �r�n� temsil eden struct
struct Urun {
    char ad[50];
    double baslangicFiyati;
};

// A��k art�rmay� temsil eden struct
struct AcikArttirma {
    struct Urun urun;
    double guncelTeklif;
    char guncelTeklifiYapan[50];
};

// A��k art�rmay� ba�latan fonksiyon
void acikArttirmayiBaslat(struct AcikArttirma *arttirma, const char *urunAdi, double baslangicFiyati) {
    // Urun adini kopyala ve null karakterle tamamla
    snprintf(arttirma->urun.ad, sizeof(arttirma->urun.ad), "%s", urunAdi);

    arttirma->urun.baslangicFiyati = baslangicFiyati;
    arttirma->guncelTeklif = baslangicFiyati;

    // "Henuz teklif yok" stringini kopyala ve null karakterle tamamla
    snprintf(arttirma->guncelTeklifiYapan, sizeof(arttirma->guncelTeklifiYapan), "%s", "Henuz teklif yok");
}

// Teklif verme fonksiyonu
void teklifVer(struct AcikArttirma *arttirma, const char *teklifVeren, double teklifMiktari) {
    if (teklifMiktari > arttirma->guncelTeklif) {
        arttirma->guncelTeklif = teklifMiktari;

        // Teklifi verenin ad�n� kopyala ve null karakterle tamamla
        snprintf(arttirma->guncelTeklifiYapan, sizeof(arttirma->guncelTeklifiYapan), "%s", teklifVeren);

        printf("Yeni teklif: %.2f TL - %s tarafindan\n", teklifMiktari, teklifVeren);
    } else {
        printf("Teklif miktari, mevcut teklif olan %.2f TL'den yuksek olmalidir.\n", arttirma->guncelTeklif);
    }
}

// A��k art�rma detaylar�n� g�sterme fonksiyonu
void acikArttirmaDetaylariniGoster(const struct AcikArttirma *arttirma) {
    printf("Urun: %s\n", arttirma->urun.ad);
    printf("Baslangic Fiyati: %.2f TL\n", arttirma->urun.baslangicFiyati);
    printf("Mevcut Teklif: %.2f TL - %s tarafindan\n", arttirma->guncelTeklif, arttirma->guncelTeklifiYapan);
}

  




/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    // A��k art�rmay� ba�lat
    struct AcikArttirma benimArttirma;
    acikArttirmayiBaslat(&benimArttirma, "Akilli Telefon", 500.0);

    // A��k art�rmay� g�ster
    acikArttirmaDetaylariniGoster(&benimArttirma);

    // Teklif verme
    teklifVer(&benimArttirma, "1.kisi", 600.0);
    teklifVer(&benimArttirma, "2.kisi", 550.0);

    // A��k art�rmay� g�ncelleme
    acikArttirmaDetaylariniGoster(&benimArttirma);



    

	return 0;
}
