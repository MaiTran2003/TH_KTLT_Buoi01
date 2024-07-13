#include <stdio.h>
#include <ctime>
int tinhTuoi(int namSinh)
{
	//cần khai báo thư viện #include <ctime> để dùng được time_t và tm
	time_t now = time_t(0);
	tm* ltm = localtime(&now);
	int namHH = 1900 + ltm->tm_year;
	try
	{
		if (namSinh <= 0 || namSinh > namHH)
			throw 101; //mã lỗi 101
		else
			if (namSinh < 1920)
				throw 102; //mã lỗi 102
			else
				return namHH - namSinh;
	}
	catch (int errCode)
	{
		if (errCode == 101)
			printf("nam sinh khong hop le\n");
		else
			printf("nam sinh <1920 \n");
		return -1;
	}
}