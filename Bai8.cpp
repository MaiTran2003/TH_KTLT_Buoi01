#include <stdio.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

// a. Nhap/xuat cac phan tu cua mang
void nhapPhanSo(PhanSo* ps, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d (tu/mau): ", i + 1);
        scanf("%d/%d", &ps[i].tu, &ps[i].mau);
        while (ps[i].mau == 0) {
            printf("Mau so khong the bang 0. Nhap lai: ");
            scanf("%d/%d", &ps[i].tu, &ps[i].mau);
        }
    }
}

void xuatPhanSo(PhanSo* ps, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ps[i].tu, ps[i].mau);
    }
    printf("\n");
}

// b. Xuat cac phan so co mau > tu
void xuatPhanSoMauLonHonTu(PhanSo* ps, int n) {
    for (int i = 0; i < n; i++) {
        if (ps[i].mau > ps[i].tu) {
            printf("%d/%d ", ps[i].tu, ps[i].mau);
        }
    }
    printf("\n");
}

// c. Dem so phan so co mau va tu chan
int demPhanSoChan(PhanSo* ps, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ps[i].tu % 2 == 0 && ps[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

// d. Rut gon phan so
int ucln(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void rutGonPhanSo(PhanSo* ps, int n) {
    for (int i = 0; i < n; i++) {
        int uc = ucln(ps[i].tu, ps[i].mau);
        ps[i].tu /= uc;
        ps[i].mau /= uc;
    }
}

// e. Tinh tich cac phan so
PhanSo tichPhanSo(PhanSo* ps, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu *= ps[i].tu;
        tich.mau *= ps[i].mau;
    }
    return tich;
}

// f. Tim phan tu lon nhat
float giaTriThuc(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

PhanSo phanSoLonNhat(PhanSo* ps, int n) {
    PhanSo max = ps[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(ps[i]) > giaTriThuc(max)) {
            max = ps[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PhanSo ps[n];
    nhapPhanSo(ps, n);

    printf("Cac phan so da nhap: ");
    xuatPhanSo(ps, n);

    printf("Cac phan so co mau lon hon tu: ");
    xuatPhanSoMauLonHonTu(ps, n);

    printf("So phan so co tu va mau deu chan: %d\n", demPhanSoChan(ps, n));

    rutGonPhanSo(ps, n);
    printf("Cac phan so sau khi rut gon: ");
    xuatPhanSo(ps, n);

    PhanSo tich = tichPhanSo(ps, n);
    printf("Tich cac phan so: %d/%d\n", tich.tu, tich.mau);

    PhanSo max = phanSoLonNhat(ps, n);
    printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

    return 0;
}
