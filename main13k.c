#include <stdio.h>
#include <stdlib.h>
// Dügüm yapisi tanimlanir

struct dugum {
    int veri;
    struct dugum* sonraki;
};
// Bas ve son dügümler tanimlanir.Bu dügümler kuyrugun basini ve sonunu temsil eder.
struct dugum* bas = NULL;
struct dugum* son = NULL;

// Ekleme islemi için fonksiyon tanimlanir
void ekle(int veri) {
// Yeni bir dügüm olusturulur
    struct dugum* yeniDugum = (struct dugum*)malloc(sizeof(struct dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    
// Kuyruk bossa
    if (bas == NULL) {
        bas = yeniDugum;
        son = yeniDugum;
    }
    // Kuyruk doluysa
    else {
        son->sonraki = yeniDugum;
        son = yeniDugum;
    }
}
// Silme islemi için fonksiyon tanimlanir
void sil() {
	// Kuyruk bossa fonksiyon calisir
    if (bas == NULL) {
        printf("Kuyruk bos.\n\n");
        return;
    }

    struct dugum* temp = bas;
    bas = bas->sonraki;

// Kuyrukta tek eleman varsa
    if (bas == NULL) {
        son = NULL;
    }

    free(temp);
}
// Görüntüleme islemi için fonksiyon tanimlanir
void goster() {
	
	 // Kuyruk bossa fonksiyon calisir
    if (bas == NULL) {
        printf("Kuyruk bos.\n\n");
        return;
    }

    struct dugum* temp = bas;

    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }

    printf("\n");
}

int main() {
    int secim, veri;
//secim yapilir
    while (1) {
        printf("1-Ekle\n\n 2-Sil\n\n 3-Goster\n\n 4-Cikis\n\n Secim: ");
        
        scanf_s("%d", &secim);

        switch (secim) {
        	
        case 1:
        	
            printf("Eklenecek veriyi giriniz: ");
            scanf_s("%d", &veri);
            ekle(veri);
            break;

        case 2:
        	
            sil();
            break;

        case 3:
        	
            goster();
            
            break;

        case 4:
        	
            exit(0);

        default:
        	
            printf("Gecersiz secim yaptiniz tekrar deneyiniz .\n");
            
            break;
        }
    }

    return 0;
}

