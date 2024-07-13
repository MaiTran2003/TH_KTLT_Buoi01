#include <stdio.h>

int main() {
    int a, b, c;
    printf("Nhap so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf("%d", &b);
    printf("Nhap so nguyen c: ");
    scanf("%d", &c);

    if (a == b) {
        printf("khong chia cho 0 vì a và b bang nhau.\n");
    }
    else {
        printf("Ket qua: c / (a - b) = %.2f\n", (float)c / (a - b));
    }

    return 0;
}
