#include <stdio.h>
#include <string.h>

int main() {
    char hoTen[50];
    int ngay, thang, nam, gioiTinh;
    int tuoi, namHienTai = 2021, tuoiHuu;

    printf("Nhap ho ten: ");
    fgets(hoTen, 50, stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng

    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &ngay, &thang, &nam);

    printf("Nhap gioi tinh (1 cho nam, 0 cho nu): ");
    scanf("%d", &gioiTinh);

    tuoi = namHienTai - nam;
    if (tuoi < 18 || (gioiTinh == 1 && tuoi > 62) || (gioiTinh == 0 && tuoi > 60)) {
        printf("Loi ma 101: Tuoi không nam trong đo tuoi lao động.\n");
        return 101;
    }

    if (gioiTinh != 1 && gioiTinh != 0) {
        printf("Loi: errcode\n");
        return -1;
    }

    if (gioiTinh == 1) {
        tuoiHuu = 62;
    }
    else {
        tuoiHuu = 60;
    }

    printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%d. Hien tại (nam %d) %s đa %d tuoi. Thoi gian %s đuoc nghi huu la thang %02d/%d.\n",
        hoTen, gioiTinh == 1 ? "nam" : "nu", ngay, thang, nam, namHienTai, hoTen, tuoi, hoTen, thang, nam + tuoiHuu);

    return 0;
}
