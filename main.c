#include <stdio.h>
#include <string.h>
// Ürünü temsil eden struct
struct Urun {
    char ad[50];
    double baslangicFiyati;
};

// Açýk artýrmayý temsil eden struct
struct AcikArttirma {
    struct Urun urun;
    double guncelTeklif;
    char guncelTeklifiYapan[50];
};

// Açýk artýrmayý baþlatan fonksiyon
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

        // Teklifi verenin adýný kopyala ve null karakterle tamamla
        snprintf(arttirma->guncelTeklifiYapan, sizeof(arttirma->guncelTeklifiYapan), "%s", teklifVeren);

        printf("Yeni teklif: %.2f TL - %s tarafindan\n", teklifMiktari, teklifVeren);
    } else {
        printf("Teklif miktari, mevcut teklif olan %.2f TL'den yuksek olmalidir.\n", arttirma->guncelTeklif);
    }
}

// Açýk artýrma detaylarýný gösterme fonksiyonu
void acikArttirmaDetaylariniGoster(const struct AcikArttirma *arttirma) {
    printf("Urun: %s\n", arttirma->urun.ad);
    printf("Baslangic Fiyati: %.2f TL\n", arttirma->urun.baslangicFiyati);
    printf("Mevcut Teklif: %.2f TL - %s tarafindan\n", arttirma->guncelTeklif, arttirma->guncelTeklifiYapan);
}

  




/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    // Açýk artýrmayý baþlat
    struct AcikArttirma benimArttirma;
    acikArttirmayiBaslat(&benimArttirma, "Akilli Telefon", 500.0);

    // Açýk artýrmayý göster
    acikArttirmaDetaylariniGoster(&benimArttirma);

    // Teklif verme
    teklifVer(&benimArttirma, "1.kisi", 600.0);
    teklifVer(&benimArttirma, "2.kisi", 550.0);

    // Açýk artýrmayý güncelleme
    acikArttirmaDetaylariniGoster(&benimArttirma);



    

	return 0;
}
