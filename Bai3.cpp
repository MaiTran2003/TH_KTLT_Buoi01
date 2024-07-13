#include <stdio.h>

int main() {
    // Khai báo hai số thực a và b
    float a, b;

    // Nhập giá trị cho a và b
    printf("Nhập số thực a: ");
    scanf("%f", &a);
    printf("Nhập số thực b: ");
    scanf("%f", &b);

    // Tạo hai con trỏ pa và pb trỏ đến a và b
    float* pa = &a;
    float* pb = &b;

    // Xuất giá trị của các con trỏ pa và pb
    printf("Giá trị mà con trỏ pa trỏ đến: %.2f\n", *pa);
    printf("Giá trị mà con trỏ pb trỏ đến: %.2f\n", *pb);

    return 0;
}
