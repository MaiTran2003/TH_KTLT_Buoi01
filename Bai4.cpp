#include <stdio.h>
#include <stdlib.h>
void nhapM1C_SoNguyen(int*& a, int& n)
{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
	n = 10;
	a = (int*)malloc(n * sizeof(int)); // cấp phát a co 10 phần tử
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 100;
}
void xuatM1C_SoNguyen(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a + i), a + i);
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a + i);
	}
}
int main()
{
	int* a, n = 0;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);
	return 0;
}
