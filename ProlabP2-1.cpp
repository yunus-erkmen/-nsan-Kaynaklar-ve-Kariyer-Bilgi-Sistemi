#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
char *trim(char *);
void DosyaOku();
void filtre_yaz(FILE *dosya,char[]);
void sistem_kayit();
void ekle(struct kisiler *,struct kisiler *);
void bilgi_goruntule(struct kisiler *);
void IsBilgisiEkle(struct kisiler *,int);
void OkulBilgisiEkle(struct kisiler *,int);
void AgacYaz(struct kisiler *);
void DosyayaYaz(FILE *,struct kisiler *);
void DosyaOku();
struct kisiler *bul(struct kisiler *,char []);
void guncelle();
void bilgi_listele(struct kisiler *);
void kisi_arama();
void filtre_ekle(struct kisiler *);
void yasa_gore(struct kisiler *,int );
void filtreleri_goruntule();
void filtreleri_goruntule2();
void lisans(struct kisiler *);
void ingilizce(struct kisiler *);
void fazla_dil(struct kisiler *);
void deneyim_sure(struct kisiler *,float);
void deneyimsiz(struct kisiler *);
void ehliyete_gore(struct kisiler *,char []);
int eleman_say(struct kisiler *);
struct kisiler *kucuk_bul(struct kisiler *);
void sil(struct kisiler *);
int derinlik_bul(struct kisiler *);
void postorder(struct kisiler *);
void preorder(struct kisiler *);
void inorder(struct kisiler *);

struct filtrelenenler
{
	struct kisiler *kisi;
	struct filtrelenenler *sonraki;
};
int eleman_sayisi=0,agac_derinlik=0;

struct filtrelenenler *filtre_ilk=NULL,*filtre_son=NULL;
struct kisiler
{
	
	char ad_soyad[50];
	char adres[50];
	char telefon[15];
	char e_posta[50];
	char dogum_tarihi[15];
	char y_dil[100];
	char ehliyet[10];
	int onceki_is_sayisi;
	int mezun_okul_sayisi;
	struct is_deneyimi *is_bilgileri_ilk;
	struct is_deneyimi *is_bilgileri_son;
	struct egitim_durumu *okul_bilgileri_ilk;
	struct egitim_durumu *okul_bilgileri_son;
	
	struct kisiler *sol,*sag,*onceki;
	
};

struct is_deneyimi
{
	int num;
	char ad[50];
	char pozisyon[50];
	float sure;
	char adres[50];
	struct is_deneyimi *sonraki;
	
};


struct egitim_durumu
{
	int num;
	char okul_ad[50];
	char bolum[50];
	char baslangic_bitis[21];
	char ortalama[10];
	char tur[20];
	struct egitim_durumu *sonraki;
		
};


struct kisiler *kok=NULL;
FILE *dosya;

main()
{
	setlocale(LC_ALL,"Turkish");
	char sec;
	system("color 1F");
	DosyaOku();

	int secenek1,secenek2;
	
	nokta:
			
		if((dosya=fopen("TumAgac.txt","w"))==NULL)
		{	
			printf("Dosya Açýlýrken Hata Olustu !!!\n");	
		}	
		
		
		
		
	AgacYaz(kok);
	fclose(dosya);
	tekrar :printf("\n\n\n\n\n\n\n");
	printf("\t\t               ANA MENU             \n");
	printf("\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
	printf("\t\tIs Basvurusu Bolumu Icin   --> <1>\n");
	printf("\t\tSirket Bolumu Icin         --> <2>\n\n\n");
	printf("\t\tCikis yapmak icin          --> <0>  ");
	printf("\n\n\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n ");
	printf(":");
	scanf("%d",&secenek1);
	system("cls");
	switch(secenek1)
	{
		
		case 1:        printf("\n\n\n\n\n");
		               printf("\t\t\t    ISCI BOLUMU              \n");
			           printf("\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
	tekrar1:		   printf("\t\tSisteme kayit icin                   --> <1>\n\t\tSistem bilgi goruntuleme icin        --> <2>  ");
	                   printf("\n\t\tSistemden cikma icin                 --> <3>\n\t\tSistemdeki bilgileri guncelleme icin --> <4>  ");
	                   printf("\n\n\n                Ana menuye donmek icin               --> <0> \n");
	                   printf("\n\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	                   
	printf(":");
	scanf("%d",&secenek2);
	switch(secenek2)
	{
		case 1:
		system("cls");
		sistem_kayit();
			
		break;
		
		case 2:
		system("cls");	
		kisi_arama();
		break;
		case 3:
			   char sil2[50];
	           printf("silinecek = ");fflush(stdin);
	           gets(sil2);
	           sil(bul(kok,sil2));
	
		break;
		case 4:
		guncelle();
		break;
		case 0: system ("cls"); goto tekrar;
		break;
		default:
        printf("Girilen sayi degeri gecersiz \n");goto tekrar1;
        break;
		
	}
	
	goto nokta;
	
		break;
		case 2:
			 int x;
			 printf("\n\n\n");
			 tekrar2: printf("\t\t             SIRKET BOLUMU            \n");
			          printf("\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			          printf("\tIkili arama agaci tüm kiþileri listeleme   --> <1>\n");
			          printf("\tIse basvuran adaylarin bilgileri listeleme --> <2>\n");
			          printf("\tArama yapacaginiz kisi (isim-soyisim ile)  --> <3>\n");
			          printf("\tEn az lisans mezunlarý listeleme           --> <4>\n");
			          printf("\tIngilizce bilen kisilerin listelenmesi     --> <5>\n");
			          printf("\tBirden fazla dil bilenlerin listelenmesi   --> <6>\n");
			          printf("\tDeneyim süresine göre basvuru listeleme    --> <7>\n");
			          printf("\tDeneyimsiz kisilerin listelenmesi          --> <8>\n");
			          printf("\tArama yapacaginiz kisi (Yas ile)           --> <9>\n");
			          printf("\tBelirli tip ehliyet listeleme              --> <10>\n");
			          printf("\n\n\tAna menuye donmek icin                     --> <0> \n");
			          printf("\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			 printf(":");         
			 scanf("%d",&x);
			 switch(x)
			 {
			 	case 0:
			 		system("cls");
			 		  goto tekrar;
			 	break;
			 	case 1:
			 		   printf("Eleman SAyisi = %d\nDerinlik = %d\n\n",eleman_say(kok),agac_derinlik);
	                   printf("--Preorder-- \n");
	                   preorder(kok);printf("\n");
					   printf("--Inorder-- \n");
	                   inorder(kok);printf("\n");
	                   printf("--Postorder-- \n");
	                   postorder(kok);
	                   
			 	break ;
			 	case 2:
			 		   bilgi_listele(kok);
			 	break ;
			 	case 3:
			 		   kisi_arama();
			 		    printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		   fflush(stdin);
			 		   	scanf("%c",&sec);
			 		  	if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Arama.txt");
			 		  		filtre_ilk=NULL;
			 		   		filtre_son=NULL;
						}
			 		   
			 		  
			 	break;
			 	
			 	case 4:
			 		
			 		   lisans(kok);
			 		   filtreleri_goruntule2();
			 		printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Lisans.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			 		   
			 	break;
			 	
			 		case 5:
			 		
			 		   ingilizce(kok);
			 		   filtreleri_goruntule2();
			 		   printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		  fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"ingilizce.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			 		  
			 		   
			 	break;
			 	case 6:
			 		     fazla_dil(kok);
			 		     filtreleri_goruntule2();
			 		    printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		  if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Cok Dil.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			    break;
			    case 7:
			    	     float sure;
			    	     printf("Minimum deneyim süresini giriniz: ");scanf("%f",&sure);
			    	     deneyim_sure(kok,sure);
			    	     filtreleri_goruntule2();
			    	    printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Minimum Deneyim.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			    	     
			    break;
			    case 8:
			    	    deneyimsiz(kok);
						filtreleri_goruntule2();
						printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Deneyimsiz.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			    break;
			 	
			 	case 9:
			 		   int yas;
			 		   printf("Yas degerini giriniz= ");scanf("%d",&yas);
			 		   yasa_gore(kok,yas);
			 		   filtreleri_goruntule2();
			 		    printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Yas.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			 		   
			 		   
			 		   
			 		   
			 	break;
			 	case 10:
			 		     char ehliyet[5];
			 		     printf("Ehliyet tipini giriniz= ");scanf("%s",&ehliyet);
			 		     ehliyete_gore(kok,ehliyet);
			 		     filtreleri_goruntule2();
			 		    printf("Filtrelenenleri Dosyaya Kaydetmek Ýstermisiniz ? (E/H)");
			 		    fflush(stdin);
			 		   scanf("%c",&sec);
			 		   if(sec=='E' || sec=='e')
			 		    {
			 		  	 	filtre_yaz(dosya,"Ehliyet.txt");
			 		  		 
						}
			 		   
			 		   filtre_ilk=NULL;
			 		   filtre_son=NULL;
			 	break;
			 	default:
                printf("Girilen sayi degeri gecersiz \n");goto tekrar2;
                break;
			 	
			 }
	    break;
	    case 0:exit(0);
	    break;
	    default:
        printf("Girilen sayi degeri gecersiz \n");goto tekrar;
        break;
	}
	
	exit(0);
}
	
void filtre_yaz(FILE *dosya,char ad[])
{
	struct filtrelenenler *gezici=filtre_ilk;
	if((dosya=(fopen(ad,"w+")))==NULL)
	{
		printf("Dosya Açýlýrken Hata oluþtu !!!");
		
	}

	else
	{
		while(gezici!=NULL)
		{
			DosyayaYaz(dosya,gezici->kisi);
			gezici=gezici->sonraki;
		}
	}
	fclose(dosya);
	printf("Basariyla Yazýldý !!!\n");
}	

void sistem_kayit()
{
	struct kisiler *eklenecek;
	eklenecek=(kisiler *) malloc(sizeof(struct kisiler));

	printf("Ad Soyad = ");
	fflush(stdin);
	gets(eklenecek->ad_soyad);
	fflush(stdin);
	printf("Adres = ");
	scanf("%s",eklenecek->adres);
	fflush(stdin);	
	printf("Telefon = ");
	scanf("%s",eklenecek->telefon);
	fflush(stdin);
	printf("E - Posta = ");
	scanf("%s",eklenecek->e_posta);
	fflush(stdin);
	printf("Dogum Tarihi = ");
	scanf("%s",eklenecek->dogum_tarihi);
	fflush(stdin);
	printf("Yabanci Dillerinizi Giriniz = ");
	scanf("%s",eklenecek->y_dil);
	fflush(stdin);
	printf("Ehliyet = ");
	scanf("%s",eklenecek->ehliyet);
	system("cls");
	
	
	
	eklenecek->is_bilgileri_ilk=NULL;
	eklenecek->okul_bilgileri_son=NULL;
	eklenecek->is_bilgileri_son=NULL;
	eklenecek->okul_bilgileri_ilk=NULL;
	
	eklenecek->sag=NULL;
	eklenecek->sol=NULL;
	eklenecek->onceki=NULL;
	
	eklenecek->onceki_is_sayisi=0;
	eklenecek->mezun_okul_sayisi=0;
	char secenek;
	
	nokta1:
	printf("Is Bilgisi Girmek Istiyormusunuz (e/h) :");
	fflush(stdin);
	scanf("%c",&secenek);
	fflush(stdin);
	system("cls");
	if(secenek=='e' ||secenek=='E')
	{
		
		IsBilgisiEkle(eklenecek,eklenecek->onceki_is_sayisi+1);
		eklenecek->onceki_is_sayisi++;
		goto nokta1;
	}
	
	nokta2:
		
	printf("Okul Bilgisi Girmek Istiyormusunuz (e/h) :");
	
	fflush(stdin);
	scanf("%c",&secenek);
	fflush(stdin);
	system("cls");
	if(secenek=='e' ||secenek=='E')
	{
		OkulBilgisiEkle(eklenecek,eklenecek->mezun_okul_sayisi+1);
		eklenecek->mezun_okul_sayisi++;
		goto nokta2;
	}
	
	

	system("cls");
	ekle(kok,eklenecek);					
	
}


void IsBilgisiEkle(struct kisiler *eklenecek,int num)
{
	struct is_deneyimi *yeni;
	yeni=(is_deneyimi *) malloc(sizeof(struct is_deneyimi));

	printf("\n");
	printf("Is Yeri Adi = ");
	fflush(stdin);
	gets(yeni->ad);
	fflush(stdin);
	printf("Is Yeri Adresi =");
	scanf("%s",yeni->adres);
	fflush(stdin);
	printf("Pozisyon = ");
	fflush(stdin);
	gets(yeni->pozisyon);
	fflush(stdin);
	printf("Calisma Suresi= ");
	scanf("%f",&yeni->sure);
	
	yeni->num=num;

	if(eklenecek->is_bilgileri_ilk==NULL)
	{
		yeni->sonraki=NULL;
		eklenecek->is_bilgileri_ilk=yeni;
		eklenecek->is_bilgileri_son=yeni;	
		
	}
	else
	{
		
		eklenecek->is_bilgileri_son->sonraki=yeni;
		yeni->sonraki=NULL;
		eklenecek->is_bilgileri_son=yeni;
	
	}
	

	system("cls");
	
}
void OkulBilgisiEkle(struct kisiler *eklenecek,int num)
{
	struct egitim_durumu *yeni;
	yeni=(egitim_durumu *) malloc(sizeof(struct egitim_durumu));
    system("cls");
	printf("\n");
	printf("Okul Adi = ");
	fflush(stdin);
	gets(yeni->okul_ad);
	fflush(stdin);
	printf("Bolumu =");
	fflush(stdin);
	gets(yeni->bolum);
	printf("Tur =");
	fflush(stdin);
	gets(yeni->tur);
	fflush(stdin);
	printf("Baþlangic ve Bitis Tarihleri = ");
	fflush(stdin);
	gets(yeni->baslangic_bitis);
	fflush(stdin);
	printf("Ortalama= ");
	scanf("%s",yeni->ortalama);
	yeni->num=num;


	if(eklenecek->okul_bilgileri_ilk==NULL)
	{

		yeni->sonraki=NULL;
		eklenecek->okul_bilgileri_ilk=yeni;
		eklenecek->okul_bilgileri_son=yeni;
	}
	else
	{
		
		eklenecek->okul_bilgileri_son->sonraki=yeni;
		yeni->sonraki=NULL;
		eklenecek->okul_bilgileri_son=yeni;
		
		
	}
	

	system("cls");
	
}



void ekle(struct kisiler *kok2,struct kisiler *eklenecek)
{
	
	if(kok2==NULL)
	{	
		kok=eklenecek;
	}	
					
	else
	{
		if(strcmp(eklenecek->ad_soyad,kok2->ad_soyad)<=0)
		{
			if(kok2->sol==NULL)
			{
				kok2->sol=eklenecek;
				eklenecek->onceki=kok2;
			}
			else
			{
				ekle(kok2->sol,eklenecek);
			}		
		}
			
		else
		{
			
			if(kok2->sag==NULL)
			{
				kok2->sag=eklenecek;
				eklenecek->onceki=kok2;	
			}
			else
			{
				ekle(kok2->sag,eklenecek);
			}				
		}		
	}
		
}

void goruntule(struct kisiler *kok2)
{
		
		printf("\n\n-------------------------Kisisel Bilgiler------------------------\n\n");
		printf("Ad Soyad = %s\n",kok2->ad_soyad);
		printf("Adres = %s\n",kok2->adres);
		printf("Telefon = %s\n",kok2->telefon);
		printf("E - Posta = %s\n",kok2->e_posta);
		printf("Dogum Tarihi = %s\n",kok2->dogum_tarihi);
		printf("Yabanci Dilleri = %s\n",kok2->y_dil);
		printf("Ehliyet = %s\n",kok2->ehliyet);
		printf("Onceki Is Sayisi= %d\n",kok2->onceki_is_sayisi);
		printf("Mezun Okul Sayisi = %d\n",kok2->mezun_okul_sayisi);
		
		struct is_deneyimi *gezici;
		gezici=kok2->is_bilgileri_ilk;
		
		printf("\n-------------------------Is bilgileri ---------------------------\n");

		
		while(gezici!=NULL)
		{
			
			printf("%d. Is Bilgileri\n",gezici->num);
			printf("Is Ad = %s\n",gezici->ad);
			printf("Is Adresi = %s\n",gezici->adres);
			printf("Pozisyon = %s\n",gezici->pozisyon);
			printf("Calisma Suresi = %.1f\n",gezici->sure);
			
			
			printf("------------------------------\n");
			
			gezici=gezici->sonraki;
			
		}
		struct egitim_durumu *gezici2;
		gezici2=kok2->okul_bilgileri_ilk;
		
					printf("-------------------------Okul Bilgileri -------------------------\n");

		while(gezici2!=NULL)
		{
			
			printf("%d. Okul Bilgileri\n",gezici2->num);
			printf("Okulun Adi = %s\n",gezici2->okul_ad);
			printf("Bolum = %s\n",gezici2->bolum);
			printf("Baslangic-Bitis Tarihleri = %s\n",gezici2->baslangic_bitis);
			printf("Ortalama = %s\n",gezici2->ortalama);
			printf("Tur = %s\n",gezici2->tur);
			printf("------------------------------\n");
			
			gezici2=gezici2->sonraki;
			
		}
		
		
		printf("\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
	
}
void goruntule_isim(struct kisiler *kok2)
{
	
		printf("Ad Soyad = %s\n",kok2->ad_soyad);
		printf("\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
	
}


void bilgi_goruntule(struct kisiler *kok2)
{
	
	if(kok2!=NULL)
	{
		
		goruntule(kok2);
		
		printf("sag = %s\n",kok2->sag);
		printf("sol = %s",kok2->sol);	
		bilgi_goruntule(kok2->sol);
		bilgi_goruntule(kok2->sag);

		
	}
		
}




void DosyayaYaz(FILE *dosya,struct kisiler *kok2)
{
	
	
	
	
			
			fprintf(dosya,"Ad Soyad            Adres               Telefon             E-Posta             Dogum Tarihi        Yabanci Dil         Ehliyet             Is Say    Okul Say\n\n");///127
			
			fprintf(dosya,"%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-10d%-10d\n\n",kok2->ad_soyad,kok2->adres,kok2->telefon,kok2->e_posta,kok2->dogum_tarihi,kok2->y_dil,kok2->ehliyet,kok2->onceki_is_sayisi,kok2->mezun_okul_sayisi);
			


			struct is_deneyimi *gezici;
			
			gezici=kok2->is_bilgileri_ilk;
			
			fprintf(dosya,"\t-------------------Is Bilgileri--------------------\n"); //20+x
			
			fprintf(dosya,"\tAd                                      Adres               Pozisyon                                Calisma Suresi\n\n");
			
			while(gezici!=NULL)
			{
				
				fprintf(dosya,"\t%-40s%-20s%-40s%-20.1f\n\n",gezici->ad,gezici->adres,gezici->pozisyon,gezici->sure);
				gezici=gezici->sonraki;
			
			}
		
			
			struct egitim_durumu *gezici2;
			gezici2=kok2->okul_bilgileri_ilk;
		
			fprintf(dosya,"\n\n\t--------------------Egitim Bilgileri--------------------\n");
			fprintf(dosya,"\tOkul Adi                                Bolum               Tur                 Tarih               Ortalama\n\n");
			while(gezici2!=NULL)
			{

				fprintf(dosya,"\t%-40s%-20s%-20s%-20s%-20s\n\n",trim(gezici2->okul_ad),trim(gezici2->bolum),trim(gezici2->tur),trim(gezici2->baslangic_bitis),gezici2->ortalama);
				
				gezici2=gezici2->sonraki;
			
			}
		fprintf(dosya,"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");//110
	
	
	
}




void DosyaOku()
{
	struct kisiler *eklenecek;
	struct is_deneyimi *is;
	struct egitim_durumu *egitim;
	
	if((dosya=fopen("TumAgac.txt","r"))==NULL)
	{
		
		printf("Onceden Kayit Bulunamadi");
		
	}
	
	
	else
	{
		while(!feof(dosya))
		{
			
			eklenecek=(kisiler *) malloc(sizeof(struct kisiler));
			eklenecek->is_bilgileri_ilk=NULL;
			eklenecek->okul_bilgileri_son=NULL;
			eklenecek->is_bilgileri_son=NULL;
			eklenecek->okul_bilgileri_ilk=NULL;
			eklenecek->sag=NULL;
			eklenecek->sol=NULL;
			fseek(dosya,sizeof(char)*158,1);
			fscanf(dosya,"\n\n");
			fgets(eklenecek->ad_soyad,21,dosya);
			fscanf(dosya,"%s %s %s %s %s %s %d %d\n\n\t",&eklenecek->adres,&eklenecek->telefon,&eklenecek->e_posta,&eklenecek->dogum_tarihi,&eklenecek->y_dil,&eklenecek->ehliyet,&eklenecek->onceki_is_sayisi,&eklenecek->mezun_okul_sayisi);
			
			fseek(dosya,sizeof(char)*51,1);
			fscanf(dosya,"\n\t");
			fseek(dosya,sizeof(char)*114,1);
			fscanf(dosya,"\n\n");
			
			for(int i=0;i<eklenecek->onceki_is_sayisi;i++)
			{
				
				is=(is_deneyimi *) malloc(sizeof(struct is_deneyimi));
				fscanf(dosya,"\t");
				fgets(is->ad,41,dosya);
				fgets(is->adres,21,dosya);
				fgets(is->pozisyon,41,dosya);
				fscanf(dosya,"%f",&is->sure);
				fscanf(dosya,"\n\n");
				is->num=i+1;
				if(i==0)
				{
					is->sonraki=NULL;
					eklenecek->is_bilgileri_ilk=is;
					eklenecek->is_bilgileri_son=is;
					
				}
			
			
				else
				{
		
					eklenecek->is_bilgileri_son->sonraki=is;
					is->sonraki=NULL;
					eklenecek->is_bilgileri_son=is;
				
				}
			
				
				
			}
			
			
			fscanf(dosya,"\n\n\t");
			fseek(dosya,sizeof(char)*56,1);
			fscanf(dosya,"\n\t");
			fseek(dosya,sizeof(char)*108,1);
			fscanf(dosya,"\n\n");
			
				for(int i=0;i<eklenecek->mezun_okul_sayisi;i++)
			{
				
				egitim=(egitim_durumu *) malloc(sizeof(struct egitim_durumu));
				fscanf(dosya,"\t");
				fgets(egitim->okul_ad,41,dosya);
				fgets(egitim->bolum,21,dosya);
				fgets(egitim->tur,21,dosya);
				fgets(egitim->baslangic_bitis,21,dosya);
				fscanf(dosya,"%s\n\n",&egitim->ortalama);
				
				egitim->num=i+1;				
			
			
				if(i==0)
				{
					egitim->sonraki=NULL;
					eklenecek->okul_bilgileri_ilk=egitim;
					eklenecek->okul_bilgileri_son=egitim;
					
				}
			
				else
				{
		
					eklenecek->okul_bilgileri_son->sonraki=egitim;
					egitim->sonraki=NULL;
					eklenecek->okul_bilgileri_son=egitim;
				
				}
			
				
			}
			
			fseek(dosya,sizeof(char)*130,1);
			
			
			fscanf(dosya,"\n");			
			
			ekle(kok,eklenecek);
			derinlik_bul(eklenecek);
			
		}
	}
	
	
	
	
	
	fclose(dosya);
	
}


void AgacYaz(struct kisiler *kok2)
{
		
		
	
			if(kok2!=NULL)
			{
				DosyayaYaz(dosya,kok2);
				AgacYaz(kok2->sol);
				AgacYaz(kok2->sag);
				
		
			}
		
		
	
		
}


struct kisiler *bul(struct kisiler *kok2,char aranan[])
{

	
     if(strcmp(trim(aranan),trim(kok2->ad_soyad))==0)
	{
		
		printf(kok2->ad_soyad);
		return kok2;
			
    }
    
    else if(strcmp(trim(aranan),trim(kok2->ad_soyad))>0)
	{ 
	
        return bul(kok2->sag,aranan);
        
    }
    
    
    else if(strcmp(trim(aranan),trim(kok2->ad_soyad))<0)
	{
        return bul(kok2->sol,aranan);
   	}
   	
   	
   
   
}

char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

        while( isspace(*frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace(*(--endp)) && endp != frontp ) {}
    }

    if( str + len - 1 != endp )
            *(endp + 1) = '\0';
    else if( frontp != str &&  endp == frontp )
            *str = '\0';

    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }


    return str;
    
}



/*
int ad_kontrol(kisiler kok2,char aranan[])
{
	
	if(strcmp(kok2->ad_soyad,aranan)==0)
	return 1;
		
	else
	return 0;
	
}
*/


void guncelle()
{
	char aranan[50];
	printf("Guncellemek Istediginiz = ");
	fflush(stdin);
	gets(aranan);
	struct kisiler *guncellenecek;
	struct is_deneyimi *is;
	struct egitim_durumu *okul;
	int x;
	
	if((guncellenecek=bul(kok,aranan))!=NULL)
	{
		printf("Kayýt bulundu.");
		goruntule(guncellenecek);
		
	}
	
	
	int secenek;
	printf("Kisisel Bilgi Guncellemek Icin >> 1\n");
	printf("Is Bilgisi Guncellemek Icin >> 2\n");
	printf("Egitim Bilgisi Guncellemek Icin >> 3\n");
	fflush(stdin);
	scanf("%d",&secenek);
	switch(secenek)
	{
	
	case 1:
		    
			
	        printf("Ad soyad guncellemek icin     >> 1\n");
			printf("Adres guncellemek icin        >> 2\n");
			printf("Telefon guncellemek icin      >> 3\n");	
			printf("E-posta guncellemek icin      >> 4\n");	
			printf("Dogum tarihi guncellemek icin >> 5\n");	
			printf("Yabanci dil guncellemek icin  >> 6\n");	
			printf("Ehliyet guncellemek icin      >> 7\n");
			scanf("%d",&x);	
			
			switch(x)
			{
				case 1:
		               printf("Ad Soyad = ");
		               fflush(stdin);
	                   gets(guncellenecek->ad_soyad);
	            break; 
	            case 2:
		               printf("Adres = ");
	                   scanf("%s",guncellenecek->adres);
	            break;
	            case 3:
		               printf("Telefon = ");
	                   scanf("%s",guncellenecek->e_posta);
	            break;
	            case 4:
		               printf("E-posta = ");
	                   scanf("%s",guncellenecek->adres);
	            break;
	            case 5:
		              printf("Dogum tarihi = ");
	                  scanf("%s",guncellenecek->dogum_tarihi);
	            break;
	            case 6:
		              printf("Yabanci Dil = ");
	                  scanf("%s",guncellenecek->y_dil);
	            break;
	            case 7:
		              printf("Ehliyet = ");
	                  scanf("%s",guncellenecek->ehliyet);
	            break; 
	            
				}	
	
	break;
	
	case 2:
			printf("Guncellenecek Is Numarasý = ");
			scanf("%d",&secenek);
		    int y;
		    is=guncellenecek->is_bilgileri_ilk;
		    while(is!=NULL)
		    {
			if(is->num==secenek)
			{
			
		    printf("Isim guncellemek icin     >> 1\n");
			printf("Pozisyon guncellemek icin >> 2\n");
			printf("Sure guncellemek icin     >> 3\n");	
			printf("Adres guncellemek icin     >> 4\n");
			scanf("%d",&y);
			switch(y)
			{
				case 1:
		               printf("Is Yeri Adi = ");
	                   fflush(stdin);
	                   gets(is->ad);
	            break;
	            case 2:
		               printf("Pozisyon = ");
	                   fflush(stdin);
	                   gets(is->pozisyon);
	            break;
	            case 3:
		                printf("Calisma Suresi= ");
	                    scanf("%f",&is->sure);
	            break;
	            case 4:
		                printf("Adres= ");
	                    scanf("%s",is->adres);
	            break;
			}
		}
			is=is->sonraki;
		}
			
	break;
	
	case 3:
		    int z;
		    printf("Guncellenecek Okul Numarasý = ");
			scanf("%d",&secenek);
			okul=guncellenecek->okul_bilgileri_ilk;
			while(okul!=NULL)
			{
				
			if(secenek=okul->num)
			{
				
			
			
		    printf("Okul adi guncellemek icin        >> 1\n");
			printf("Bolum guncellemek icin           >> 2\n");
			printf("Turu guncellemek icin            >> 3\n");	
			printf("Baslangic-bitis guncellemek icin >> 4\n");	
			printf("Ortalama guncellemek icin        >> 5\n");
			scanf("%d",&z);
			switch(z)
			{
			case 1:
		           printf("Okul Adi = ");
	               fflush(stdin);
	               gets(okul->okul_ad);
	               fflush(stdin);
	        break;
			case 2:
		           printf("Bolum = ");
	               fflush(stdin);
	               gets(okul->bolum);
	               fflush(stdin);
	        break;
			case 3:
		           printf("Turu = ");
	               fflush(stdin);
	               gets(okul->tur);
	               fflush(stdin);
	        break;
			case 4:
		           printf("Baslangic-Bitis = ");
	               scanf("%s",okul->baslangic_bitis);
	        break;
			case 5:
		           printf("Ortalama = ");
	               scanf("%s",okul->ortalama);
	        break;	
			}
		}
			okul=okul->sonraki;
		}
	break;
	
}
	
	
}





void sil(struct kisiler *silinecek)
{
	
	struct kisiler *degisecek=NULL;
	
	//////////////////////////////////////////////////////////
	if(silinecek->sag==NULL && silinecek->sol==NULL)
	{
		
		if(silinecek==kok)
		{
			kok=NULL;
		}
		else
		{
		
			silinecek->onceki->sag=NULL;
			silinecek->onceki->sol==NULL;
		}
		
	}
	//////////////////////////////////////////////////////////////
	
	
	
	else if((silinecek->sag==NULL && silinecek->sol!=NULL))
	{
		
		if(silinecek==kok)
		{
			
			kok=silinecek->sol;
			
		}
		
		else
		{
				
			if(silinecek->onceki->sag==silinecek)
			{
				silinecek->onceki->sag=silinecek->sol;

			}
			else if(silinecek->onceki->sol==silinecek)
			{
				silinecek->onceki->sol=silinecek->sol;
			}
			
		}
	}
	
	else if((silinecek->sag!=NULL && silinecek->sol==NULL))
	{
		if(silinecek==kok)
		{
			
			kok=silinecek->sag;
			
		}
		else
		{
			if(silinecek->onceki->sag==silinecek)
			{
				silinecek->onceki->sag=silinecek->sag;

			}
			else if(silinecek->onceki->sol==silinecek)
			{
				silinecek->onceki->sol=silinecek->sag;
			}
		}
		
		
	}
	
	///////////////////////////////////////////////////////////////////////////
	else if(silinecek->sag!=NULL && silinecek->sol!=NULL)
	{
		
		
		degisecek=kucuk_bul(silinecek);
		
			degisecek->onceki->sol=degisecek->sag;
			degisecek->sag=silinecek->sag;
			degisecek->sol=silinecek->sol;
		
		if(silinecek==kok)
		{
			
			degisecek->sag=degisecek->onceki->sag;
			
			
			
			
		}
		
		
		
		else
		{
			
			
		
			if(silinecek==silinecek->onceki->sol)
			{
				silinecek->onceki->sol=degisecek;
			}
		
			else if(silinecek==silinecek->onceki->sag)
			{
				silinecek->onceki->sag=degisecek;
			}
			
			degisecek->onceki=silinecek->onceki;
		}
		
	}
	printf("Basariyla Silindi !!! \n");
	
}



struct kisiler *kucuk_bul(struct kisiler *kok2)
{
	
	kok2=kok2->sag;
	
	while(kok2->sol!=NULL)
	{
		
			kok2=kok2->sol;
			
	}
	
	return kok2;
	
}








void bilgi_listele(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{

		bilgi_goruntule(kok2->sol);
		goruntule(kok2);
		bilgi_goruntule(kok2->sag);
		
		
	}
}

void kisi_arama()
{
	char aranan[50];
	printf("Arama Yapacagýnýz Kisi= ");
	fflush(stdin);
	gets(aranan);
	struct kisiler *aranacak;
	
	if((aranacak=bul(kok,aranan))!=NULL)
	{
		printf("Kayýt bulundu...\n\n");
		goruntule(aranacak);
		filtre_ekle(aranacak);
		
	}
	

}



void filtre_ekle(struct kisiler *eklenecek)
{
	
	struct filtrelenenler *yeni;
	
	yeni=(filtrelenenler *) malloc(sizeof(struct filtrelenenler));
	
	yeni->kisi=eklenecek;
	
	if(filtre_ilk==NULL)
	{
		yeni->sonraki=NULL;
		filtre_ilk=yeni;
		filtre_son=yeni;
			
	}
	
	else
	{	
		filtre_son->sonraki=yeni;
		yeni->sonraki=NULL;
		filtre_son=yeni;		
	}
	
}

void yasa_gore(struct kisiler *kok2,int yas)
{
	if(kok2!=NULL)
	{
		
		yasa_gore(kok2->sol,yas);
		if((2016-atoi(kok2->dogum_tarihi))<yas)
		{
			filtre_ekle(kok2);
		}
		
		yasa_gore(kok2->sag,yas);
		
	}	
}


void ingilizce(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{
		
		ingilizce(kok2->sol);
		if(strstr(kok2->y_dil,"Ing"))
		{
			filtre_ekle(kok2);
		}
		
		ingilizce(kok2->sag);
		
	}	
}

void deneyimsiz(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{
		
		deneyimsiz(kok2->sol);
		
		if((kok2->onceki_is_sayisi)==0)
		{
			filtre_ekle(kok2);
		}
		
		deneyimsiz(kok2->sag);
		
	}	
}

void ehliyete_gore(struct kisiler *kok2,char ehliyet[])
{
	
	if(kok2!=NULL)
	{
		
		ehliyete_gore(kok2->sol,ehliyet);
		
		if(strstr(kok2->ehliyet,ehliyet)!=NULL)
		{
			filtre_ekle(kok2);
		}
		
		ehliyete_gore(kok2->sag,ehliyet);
		
	}	
}


void fazla_dil(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{
		
		fazla_dil(kok2->sol);
		if(strstr(kok2->y_dil,","))
		{
			filtre_ekle(kok2);
		}
		
		fazla_dil(kok2->sag);
		
	}	
}

void lisans(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{
		
		lisans(kok2->sol);
		struct egitim_durumu *gezici=kok2->okul_bilgileri_ilk;
		while(gezici!=NULL)
		{
			
			if(strcmp(gezici->tur,"Lisans")==0)
			{
				filtre_ekle(kok2);
				break;
			}
			
			gezici=gezici->sonraki;
		}
	
		
		lisans(kok2->sag);
		
	}	
}

void deneyim_sure(struct kisiler *kok2,float sure)
{
	float toplam=0;
	if(kok2!=NULL)
	{
		
		deneyim_sure(kok2->sol,sure);
		struct is_deneyimi *gezici=kok2->is_bilgileri_ilk;
		while(gezici!=NULL)
		{
			
			toplam+=gezici->sure;
			
			gezici=gezici->sonraki;
		}
		if(toplam>=sure)
		{
			
			filtre_ekle(kok2);
			
		}
		
		deneyim_sure(kok2->sag,sure);
		
	}	
}


void filtreleri_goruntule()
{
		struct filtrelenenler *gezici=filtre_ilk;
		while(gezici!=NULL)
		{
			
			goruntule(gezici->kisi);
	
			gezici=gezici->sonraki;
		}
	
}

void filtreleri_goruntule2()
{
		struct filtrelenenler *gezici=filtre_ilk;
		while(gezici!=NULL)
		{
		
			goruntule_isim(gezici->kisi);
	
			gezici=gezici->sonraki;
		}
	
}


int eleman_say(struct kisiler *kok2)
{
	
		
	if(kok2!=NULL)
	{
		
		eleman_sayisi++;
		
		eleman_say(kok2->sol);	
		eleman_say(kok2->sag);
			
			
	}
	
	return eleman_sayisi;
}


int derinlik_bul(struct kisiler *kok2)
{
	 int derinlik=0;
	 
	 while(kok2!=NULL)
	 {
	 	
	 	kok2=kok2->onceki;
	 	derinlik++;
	 }
	 
	if(derinlik>agac_derinlik)
	{
		agac_derinlik=derinlik;
	}
	return derinlik;
	
}



void inorder(struct kisiler *kok2)
{
	
	if(kok2!=NULL)
	{
		
		
		inorder(kok2->sol);	
		printf("%s   Duzey = %d\n",kok2->ad_soyad,derinlik_bul(kok2)-1);
		inorder(kok2->sag);
		
	}	
	
}


void preorder(struct kisiler *kok2)
{
	
	if(kok2!=NULL)
	{
		
		printf("%s   Duzey = %d\n",kok2->ad_soyad,derinlik_bul(kok2)-1);
		inorder(kok2->sol);	
		inorder(kok2->sag);
		
	}	
}


void postorder(struct kisiler *kok2)
{
	if(kok2!=NULL)
	{
		
		inorder(kok2->sol);	
		inorder(kok2->sag);
		printf("%s   Duzey = %d\n",kok2->ad_soyad,derinlik_bul(kok2)-1);

	}
		
}




