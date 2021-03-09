//Ariansyah
//16020071

#include<stdio.h>
#include<stdlib.h>

//menu
void showMenu(int input){
    printf("\nKalkulator Sederhana\n");
    printf("====\n");
    printf("1. Kalkulator biasa (+, -, *, /, ^)\n");
    printf("2. Kalkulator integral tentu\n");
    printf("3.Exit\n");
}
//luas trapesium untuk integral
float luas_trapesium(float a, float b, float c, float dx, float partisi1, float partisi2){
    return(((a*partisi2*partisi2 + b*partisi2 + c)+(a*partisi1*partisi1 + b*partisi1 + c))/2*dx);
}
//jumlah riemann
float integral(float a, float b, float c, float x1, float x2, float n){
    float sum, luas_partisi, partisi1, partisi2, dx;
    sum = 0;
    dx=(x2-x1)/n;
    for (float i = 0; i < n - 1; i++){
        partisi1 = x1 + i*dx;
        partisi2 = x1 + (i+1)*dx;
        luas_partisi = luas_trapesium(a, b, c, dx, partisi1, partisi2);
        sum = sum + luas_partisi;
    }
    return(sum);
}
int main(){
    int input;
    int menu;
    showMenu(input);
    scanf("%d",&menu);
	while (menu!=3){
        if (menu==1){
            //kamus
            float x, y;
            float z=0;
            char o;
            printf("\nMasukkan angka pertama: ");
            scanf("%f", &x);
            printf("\nMasukkan operator: ");
            scanf(" %c", &o);
            printf("\nMasukkan angka kedua: ");
            scanf("%f", &y);
            switch (o){
                case '+':
                    //pertambahan
                    z = x + y;
                    printf("%f + %f = %f", x, y, z);
                    break;
                case '-':
                    //pengurangan
                    z = x - y;
                    printf("%f - %f = %f", x, y, z);
                    break;
                case '*':
                    //perkalian
                    z = x * y;
                    printf("%f * %f = %f", x, y, z);
                    break;
                case '/':
                    //pembagian
                    z = x / y;
                    printf("%f / %f = %f", x, y, z);
                    break;
                case '^':
                    //perpangkatan
                    z = x;
                    for (float i = 1; i < y ; i++){
                        z = z*x;
                    }
                    printf("%f ^ %f = %f", x, y, z);
                    break;
            }
        }
        else if (menu==2){
        //kamus
            float a, b, c, x1, x2, hasil, n;
            printf("\nf(x) = Ax^2 + Bx + C");
            printf("\nMasukkan A: ");
            scanf("%f",&a);
            printf("\nMasukkan B: ");
            scanf("%f",&b);
            printf("\nMasukkan C: ");
            scanf("%f",&c);
            printf("\nMasukkan batas bawah  ");
            scanf("%f",&x1);
            printf("\nMasukkan batas atas: ");
            scanf("%f",&x2);
            printf("\nMasukkan jumlah partisi: ");
            scanf("%f",&n);
            hasil = integral(a, b, c, x1, x2, n);
            printf("\nHasil integral adalah %f ", hasil);
        }
        showMenu(input);
        scanf("%d",&menu);
    }
}

