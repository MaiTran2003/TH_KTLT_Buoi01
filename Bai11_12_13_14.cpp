#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Các hàm của bài 11
void xuatSoCucTieu(int a[], int n);
int xoaPhanTuTaiViTri(int a[], int n, int k);
int themPhanTuTaiViTri(int a[], int n, int k, int x);
void chuyenChanLenDau(int a[], int n);
bool kiemTraChanLeXenKe(int a[], int n);

// Các hàm của bài 12
typedef struct {
    int tu;
    int mau;
} PhanSo;

PhanSo phanSoLonNhat(PhanSo ps[], int n);
PhanSo phanSoNhoNhat(PhanSo ps[], int n);
int xoaPhanSoTaiViTri(PhanSo ps[], int n, int k);
int themPhanSoTaiViTri(PhanSo ps[], int n, int k, PhanSo x);

// Các hàm của bài 13
void chiaMang(int a[], int b[], int n, int m);

// Các hàm của bài 14
typedef struct {
    char hoTen[50];
    int ngay, thang, nam;
    char gioiTinh[10];
} NguoiLaoDong;

void tinhTuoiNghiHuu(NguoiLaoDong nd);

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Xuat cac so cuc tieu trong mang\n");
        printf("2. Xoa phan tu tai vi tri k\n");
        printf("3. Them phan tu x tai vi tri k\n");
        printf("4. Chuyen so chan len dau, so le xuong cuoi mang\n");
        printf("5. Kiem tra mang co chua chan le xen ke khong\n");
        printf("6. Tim phan so lon nhat\n");
        printf("7. Tim phan so nho nhat\n");
        printf("8. Xoa phan so tai vi tri k\n");
        printf("9. Them phan so tai vi tri k\n");
        printf("10. Chia mang a cho mang b\n");
        printf("11. Tinh tuoi nghi huu cua nguoi lao dong\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int n;
            int a[MAX];
            printf("Nhap so luong phan tu trong mang: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            xuatSoCucTieu(a, n);
            break;
        }
        case 2: {
            int n, k;
            int a[MAX];
            printf("Nhap so luong phan tu trong mang: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            n = xoaPhanTuTaiViTri(a, n, k);
            printf("Mang sau khi xoa: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        }
        case 3: {
            int n, k, x;
            int a[MAX];
            printf("Nhap so luong phan tu trong mang: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            printf("Nhap vi tri can them: ");
            scanf("%d", &k);
            printf("Nhap gia tri can them: ");
            scanf("%d", &x);
            n = themPhanTuTaiViTri(a, n, k, x);
            printf("Mang sau khi them: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        }
        case 4: {
            int n;
            int a[MAX];
            printf("Nhap so luong phan tu trong mang: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            chuyenChanLenDau(a, n);
            printf("Mang sau khi chuyen: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;
        }
        case 5: {
            int n;
            int a[MAX];
            printf("Nhap so luong phan tu trong mang: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            if (kiemTraChanLeXenKe(a, n)) {
                printf("Mang co chua chan le xen ke\n");
            }
            else {
                printf("Mang khong chua chan le xen ke\n");
            }
            break;
        }
        case 6: {
            int n;
            PhanSo ps[MAX];
            printf("Nhap so luong phan so: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap tu va mau cua phan so thu %d: ", i + 1);
                scanf("%d %d", &ps[i].tu, &ps[i].mau);
            }
            PhanSo max = phanSoLonNhat(ps, n);
            printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
            break;
        }
        case 7: {
            int n;
            PhanSo ps[MAX];
            printf("Nhap so luong phan so: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap tu va mau cua phan so thu %d: ", i + 1);
                scanf("%d %d", &ps[i].tu, &ps[i].mau);
            }
            PhanSo min = phanSoNhoNhat(ps, n);
            printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);
            break;
        }
        case 8: {
            int n, k;
            PhanSo ps[MAX];
            printf("Nhap so luong phan so: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap tu va mau cua phan so thu %d: ", i + 1);
                scanf("%d %d", &ps[i].tu, &ps[i].mau);
            }
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            n = xoaPhanSoTaiViTri(ps, n, k);
            printf("Cac phan so sau khi xoa: ");
            for (int i = 0; i < n; i++) {
                printf("%d/%d ", ps[i].tu, ps[i].mau);
            }
            printf("\n");
            break;
        }
        case 9: {
            int n, k;
            PhanSo ps[MAX];
            PhanSo x;
            printf("Nhap so luong phan so: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap tu va mau cua phan so thu %d: ", i + 1);
                scanf("%d %d", &ps[i].tu, &ps[i].mau);
            }
            printf("Nhap vi tri can them: ");
            scanf("%d", &k);
            printf("Nhap tu va mau cua phan so can them: ");
            scanf("%d %d", &x.tu, &x.mau);
            n = themPhanSoTaiViTri(ps, n, k, x);
            printf("Cac phan so sau khi them: ");
            for (int i = 0; i < n; i++) {
                printf("%d/%d ", ps[i].tu, ps[i].mau);
            }
            printf("\n");
            break;
        }
        case 10: {
            int n, m;
            int a[MAX], b[MAX];
            printf("Nhap so luong phan tu trong mang a: ");
            scanf("%d", &n);
            printf("Nhap cac phan tu cua mang a: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            printf("Nhap so luong phan tu trong mang b: ");
            scanf("%d", &m);
            printf("Nhap cac phan tu cua mang b: ");
            for (int i = 0; i < m; i++) {
                scanf("%d", &b[i]);
            }
            chiaMang(a, b, n, m);
            break;
        }
        case 11: {
            NguoiLaoDong nd;
            printf("Nhap ho ten: ");
            scanf(" %[^\n]", nd.hoTen);
            printf("Nhap ngay sinh (dd mm yyyy): ");
            scanf("%d %d %d", &nd.ngay, &nd.thang, &nd.nam);
            printf("Nhap gioi tinh (nam/nu): ");
            scanf("%s", nd.gioiTinh);
            tinhTuoiNghiHuu(nd);
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

// Bài 11a
void xuatSoCucTieu(int a[], int n) {
    printf("Cac so cuc tieu trong mang la: ");
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Bài 11b
int xoaPhanTuTaiViTri(int a[], int n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri xoa khong hop le.\n");
        return n;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    return n - 1;
}

// Bài 11c
int themPhanTuTaiViTri(int a[], int n, int k, int x) {
    if (k < 0 || k > n) {
        printf("Vi tri them khong hop le.\n");
        return n;
    }
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    return n + 1;
}

// Bài 11d
void chuyenChanLenDau(int a[], int n) {
    int chan[MAX], le[MAX];
    int c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            chan[c++] = a[i];
        }
        else {
            le[l++] = a[i];
        }
    }
    for (int i = 0; i < c; i++) {
        a[i] = chan[i];
    }
    for (int i = 0; i < l; i++) {
        a[c + i] = le[i];
    }
}

// Bài 11e
bool kiemTraChanLeXenKe(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

// Bài 12a
PhanSo phanSoLonNhat(PhanSo ps[], int n) {
    PhanSo max = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tu / ps[i].mau > (float)max.tu / max.mau) {
            max = ps[i];
        }
    }
    return max;
}

// Bài 12a
PhanSo phanSoNhoNhat(PhanSo ps[], int n) {
    PhanSo min = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tu / ps[i].mau < (float)min.tu / min.mau) {
            min = ps[i];
        }
    }
    return min;
}

// Bài 12b
int xoaPhanSoTaiViTri(PhanSo ps[], int n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri xoa khong hop le.\n");
        return n;
    }
    for (int i = k; i < n - 1; i++) {
        ps[i] = ps[i + 1];
    }
    return n - 1;
}

// Bài 12c
int themPhanSoTaiViTri(PhanSo ps[], int n, int k, PhanSo x) {
    if (k < 0 || k > n) {
        printf("Vi tri them khong hop le.\n");
        return n;
    }
    for (int i = n; i > k; i--) {
        ps[i] = ps[i - 1];
    }
    ps[k] = x;
    return n + 1;
}

// Bài 13
void chiaMang(int a[], int b[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] != 0) {
                printf("a[%d] / b[%d] = %f\n", i, j, (float)a[i] / b[j]);
            }
            else {
                printf("Khong the chia a[%d] cho b[%d] vi b[%d] = 0\n", i, j, j);
            }
        }
    }
}

// Bài 14
void tinhTuoiNghiHuu(NguoiLaoDong nd) {
    int tuoiNghiHuu;
    if (strcmp(nd.gioiTinh, "nam") == 0) {
        if (nd.nam < 1961) {
            tuoiNghiHuu = 60;
        }
        else if (nd.nam < 1963) {
            tuoiNghiHuu = 60 + (2024 - 2021) * 3;
        }
        else if (nd.nam < 1966) {
            tuoiNghiHuu = 61 + (2027 - 2024) * 3;
        }
        else {
            tuoiNghiHuu = 62;
        }
    }
    else {
        if (nd.nam < 1966) {
            tuoiNghiHuu = 55 + (2024 - 2021) * 4;
        }
        else if (nd.nam < 1968) {
            tuoiNghiHuu = 56 + (2026 - 2024) * 4;
        }
        else if (nd.nam < 1970) {
            tuoiNghiHuu = 57 + (2029 - 2026) * 4;
        }
        else {
            tuoiNghiHuu = 58;
        }
    }
    printf("Tuoi nghi huu cua nguoi lao dong %s la: %d\n", nd.hoTen, tuoiNghiHuu);
}
