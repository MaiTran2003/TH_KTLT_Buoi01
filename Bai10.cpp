#include <stdio.h>
#include <ctype.h>
#include <string.h>

// a. Xuat gia tri tung ky tu cua chuoi thong qua con tro
void xuatKyTu(char* st) {
    while (*st != '\0') {
        printf("%c", *st);
        st++;
    }
    printf("\n");
}

// b. Chuyen cac ky tu cua chuoi ve dang chu hoa
void chuyenChuHoa(char* st) {
    while (*st != '\0') {
        *st = toupper(*st);
        st++;
    }
}

// c. Chuyen cac ky tu dau moi tu cua chuoi ve dang chu hoa
void chuyenKyTuDauChuHoa(char* st) {
    int dauTu = 1;
    while (*st != '\0') {
        if (dauTu && isalpha(*st)) {
            *st = toupper(*st);
            dauTu = 0;
        }
        else if (isspace(*st)) {
            dauTu = 1;
        }
        st++;
    }
}

int main() {
    char st[100];

    printf("Nhap chuoi: ");
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = '\0';  // Loai bo ky tu xuong dong

    printf("Xuat tung ky tu cua chuoi: ");
    xuatKyTu(st);

    chuyenChuHoa(st);
    printf("Chuoi sau khi chuyen ve chu hoa: %s\n", st);

    chuyenKyTuDauChuHoa(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s\n", st);

    return 0;
}
