#include <stdio.h>

void tinhTong(float* pa, float* pb, float* ketqua) {
    *ketqua = *pa + *pb;
}

void tinhHieu(float* pa, float* pb, float* ketqua) {
    *ketqua = *pa - *pb;
}

void tinhTich(float* pa, float* pb, float* ketqua) {
    *ketqua = *pa * *pb;
}

void tinhThuong(float* pa, float* pb, float* ketqua) {
    if (*pb != 0) {
        *ketqua = *pa / *pb;
    }
    else {
        printf("Khong the chia cho 0.\n");
    }
}

int main() {
    float a, b;
    printf("Nhap so thuc a: ");
    scanf("%f", &a);
    printf("Nhap so thuc b: ");
    scanf("%f", &b);

    float* pa = &a, * pb = &b;
    float ketqua;

    tinhTong(pa, pb, &ketqua);
    printf("Tong: %.2f tai dia chi: %p\n", ketqua, (void*)&ketqua);

    tinhHieu(pa, pb, &ketqua);
    printf("Hieu: %.2f tai dia chi: %p\n", ketqua, (void*)&ketqua);

    tinhTich(pa, pb, &ketqua);
    printf("Tich: %.2f tai dia chi: %p\n", ketqua, (void*)&ketqua);

    tinhThuong(pa, pb, &ketqua);
    printf("Thuong: %.2f tai dia chi: %p\n", ketqua, (void*)&ketqua);

    return 0;
}
