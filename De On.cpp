#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) {
        return 0; // Không phải số nguyên tố
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // Không phải số nguyên tố
        }
    }
    return 1; // Là số nguyên tố
}

// Hàm nhập giá trị cho mảng a
void nhapMang(float* a, int n) {
    printf("Nhap gia tri cho mang:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf_s("%f", &a[i]);
    }
}

// Hàm tạo mảng ngẫu nhiên
void taoMangNgauNhien(float* a, int n) {
    printf("Mang sau khi tao ngau nhien:\n");
    for (int i = 0; i < n; i++) {
      *(a+i) = (float)rand() / RAND_MAX * 100.0; // Giả sử giá trị từ 0 đến 100.0
        printf("%.2f ", *(a+i));
    }
    printf("\n");
}

// Hàm xuất các phần tử có phần nguyên là số nguyên tố
void xuatSoNguyenTo(float* a, int n) {
    printf("Cac phan tu co phan nguyen la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo((int)a[i])){
            printf("%.2f ", a[i]);
        }
        sqrt(*(a + i));
    }

    printf("\n");
}

// Hàm xuất các phần thập phân của mỗi phần tử
void xuatPhanThapPhan(float* a, int n) {
    printf("Cac phan thap phan cua moi phan tu:\n");
    for (int i = 0; i < n; i++) {
        float phanNguyen = floor(a[i]);
        float phanThapPhan = a[i] - phanNguyen;
        printf("%.2f ", phanThapPhan);
    }
    printf("\n");
}

void xoaPhanNguyenLe(float* a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        int phanNguyen = (int)fabs(*(a + i));
        if (phanNguyen % 2 != 0)
        {
            for (int j = i; j < n; j++)
            {
                *(a + j) = *(a + j + 1);
            }
            n--;
        }
    }
}


void xuat(float* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\n", *(a + i));
    }
}
// Hàm đếm số phần tử có phần nguyên chứa chữ số 2
int demSoPhanTuChuaChuSoHai(float* a, int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        int phanNguyen = (int)fabs(a[i]); // Lấy giá trị tuyệt đối trước khi chuyển sang số nguyên
        while (phanNguyen > 0) {

            if (phanNguyen % 10 == 2) {
                dem++;
                break; // Đã tìm thấy số 2, thoát khỏi vòng lặp
            }
            phanNguyen /= 10;
        }
    }
    return dem;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    // Kiểm tra nếu n không hợp lệ
    if (n <= 0) {
        printf("So phan tu khong hop le.\n");
        return 1;
    }

    // Cấp phát bộ nhớ cho mảng
    float* a = (float*)malloc(n * sizeof(float));

    // Kiểm tra xem cấp phát bộ nhớ có thành công không
    if (a == NULL) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }

    // Lựa chọn nhập hoặc tạo ngẫu nhiên mảng
    int luaChon;
    printf("Chon lua chon:\n");
    printf("1. Nhap mang\n");
    printf("2. Tao mang ngau nhien\n");
    printf("Lua chon cua ban: ");
    scanf_s("%d", &luaChon);

    switch (luaChon) {
    case 1:
        nhapMang(a, n);
        break;
    case 2:
        taoMangNgauNhien(a, n);
        break;
    default:
        printf("Lua chon khong hop le.\n");
        free(a); // Giải phóng bộ nhớ nếu có lỗi
        return 1;
    }

    // Xuất mảng
    printf("Mang sau khi nhap/tao:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    //printf("\n");

    //// Xuất các phần tử có phần nguyên là số nguyên tố
    //xuatSoNguyenTo(a, n);

    //// Xuất các phần thập phân của mỗi phần tử
    //xuatPhanThapPhan(a, n);

    //// Đếm số phần tử có phần nguyên chứa chữ số 2
    //int soPhanTuChuaChuSoHai = demSoPhanTuChuaChuSoHai(a, n);
    //printf("So phan tu co phan nguyen chua chu so 2: %d\n", soPhanTuChuaChuSoHai);



    printf("Xoa phan nguyen: \n");
    xoaPhanNguyenLe(a, n);
    xuat(a, n);

    // Giải phóng bộ nhớ
    free(a);

    return 0;
}
