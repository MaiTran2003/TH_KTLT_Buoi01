#include <stdio.h>
#include <math.h>

// a. Tim phan tu lon nhat va xuat ra phan tu lon nhat va dia chi cua no
void timPhanTuLonNhat(int *a, int n) {
    int *max = a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) > *max) {
            max = a + i;
        }
    }
    printf("Phan tu lon nhat: %d tai dia chi: %p\n", *max, (void*)max);
}

// b. Xuat dia chi cua phan tu chan lon nhat va phan tu le nho nhat
void timPhanTuChanLe(int *a, int n) {
    int *chanLonNhat = NULL;
    int *leNhoNhat = NULL;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            if (chanLonNhat == NULL || *(a + i) > *chanLonNhat) {
                chanLonNhat = a + i;
            }
        } else {
            if (leNhoNhat == NULL || *(a + i) < *leNhoNhat) {
                leNhoNhat = a + i;
            }
        }
    }
    if (chanLonNhat != NULL) {
        printf("Phan tu chan lon nhat: %d tai dia chi: %p\n", *chanLonNhat, (void*)chanLonNhat);
    } else {
        printf("Khong co phan tu chan trong mang\n");
    }
    if (leNhoNhat != NULL) {
        printf("Phan tu le nho nhat: %d tai dia chi: %p\n", *leNhoNhat, (void*)leNhoNhat);
    } else {
        printf("Khong co phan tu le trong mang\n");
    }
}

// c. Xoa phan tu co gia tri 0
int xoaPhanTu0(int *a, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (*(a + i) != 0) {
            *(a + j) = *(a + i);
            j++;
        }
    }
    return j;
}

// d. Them phan tu x vao sau phan tu dau tien
void themPhanTuSauDauTien(int *a, int *n, int x) {
    for (int i = *n; i > 1; i--) {
        *(a + i) = *(a + i - 1);
    }
    *(a + 1) = x;
    (*n)++;
}

// e. Tinh tong cac phan tu la so chinh phuong
int laSoChinhPhuong(int x) {
    int s = (int)sqrt(x);
    return (s * s == x);
}

int tongSoChinhPhuong(int *a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(*(a + i))) {
            tong += *(a + i);
        }
    }
    return tong;
}

// f. Xuat cac so cuc dai trong mang
void xuatSoCucDai(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ((i == 0 || *(a + i) > *(a + i - 1)) && (i == n - 1 || *(a + i) > *(a + i + 1))) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}

int main() {
    int a[100], n;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Phan tu lon nhat:\n");
    timPhanTuLonNhat(a, n);

    printf("Phan tu chan lon nhat va le nho nhat:\n");
    timPhanTuChanLe(a, n);

    printf("Xoa phan tu co gia tri 0:\n");
    n = xoaPhanTu0(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int x;
    printf("Nhap phan tu x de them vao sau phan tu dau tien: ");
    scanf("%d", &x);
    themPhanTuSauDauTien(a, &n, x);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Tong cac phan tu la so chinh phuong: %d\n", tongSoChinhPhuong(a, n));

    printf("Cac so cuc dai trong mang: ");
    xuatSoCucDai(a, n);

    return 0;
}
