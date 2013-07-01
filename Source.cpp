#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int taban, toplam, elde = 0;
char birinciSayi[20], ikinciSayi[20];
int sonuc[25];
int sonucIndex = 0;

void tabanToplamasi(int, int);
int diziBoyutu(char[]);

void main(){
	printf("Taban numarasini giriniz: ");
	scanf("%d", &taban);
	printf("1. sayiyi giriniz:        ");
	scanf("%s", birinciSayi);
	printf("2. sayiyi giriniz:        ");
	scanf("%s", ikinciSayi);
	printf("\n(%s)%d + (%s)%d = (", birinciSayi, taban, ikinciSayi, taban);
	tabanToplamasi(diziBoyutu(birinciSayi) - 1, diziBoyutu(ikinciSayi) - 1);
	int i;
	for (i=sonucIndex-1;i >= 0;i--)
		if (sonuc[i] >= 10)
			printf("%c", sonuc[i] + 55);
		else
			printf("%d", sonuc[i]);
	printf(")%d\n\n", taban);
	system("PAUSE");
}
void tabanToplamasi(int birinciIndex, int ikinciIndex){
	if (birinciIndex >= 0 || ikinciIndex >= 0){
		char xc = birinciIndex < 0 ? '0' : birinciSayi[birinciIndex];
		char yc = ikinciIndex < 0 ? '0' : ikinciSayi[ikinciIndex];
		int x = isalpha(xc) ? xc - 55 : atoi(&xc);
		int y = isalpha(yc) ? yc - 55 : atoi(&yc);
		toplam = (x + y + elde) % taban;
		elde = (x + y + elde) / taban;
		sonuc[sonucIndex++] = toplam;
		tabanToplamasi(--birinciIndex, --ikinciIndex);
	}
	else if (elde > 0){
		sonuc[sonucIndex++] = elde;
	}
}
int diziBoyutu(char dizi[]){
	int i = 0;
	for(;dizi[i] != '\0';i++);
	return i;
}