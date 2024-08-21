#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
void nhapMIC_SoNguyen(int*& a, int& n)
{
	int i;
	printf("Nhap so luong phan tu: ");
	scanf_s("%d", &n);
	srand(time(0));
	// cap phåt a co 10 phän til'
	a = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		do
		{
			*(a + i) = rand() % 100;
		} while (*(a + i) % 2 != 0);
}
}
void xuatMIC_SoNguyen(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (void*)(a + i));
		// Sửa printf trên để hiển thị giá trị và địa chỉ của phần tử thứ i
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, a[i], (void*)&a[i]);
	}
}

int demSoPhanTu(int* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 5 == 0)
			dem++;
	}
	return dem;
}

int main()
{
	int n;
	int* a;
	nhapMIC_SoNguyen(a, n);
	xuatMIC_SoNguyen(a, n);
	printf("\nSo phan tu la boi cua 5 la: %d", demSoPhanTu(a, n));
	free(a);
	_getch();
}