#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct sv
{
    char mssv[10];
    char name[50];
    float mon1;
	float mon2;
	float mon3;
	float TB;
	string note;
};

void nhap_1_sv_ko_ma(sv &s) {
    cout << "Nhap ho ten: ";
    cin.getline(s.name, 50);
    cout << "\nNhap mon 1: ";
    cin >> s.mon1;
	cout << "\nNhap mon 2: ";
    cin >> s.mon2;
	cout << "\nNhap mon 3: ";
    cin >> s.mon3;
    s.TB = (s.mon1 + s.mon2 + s.mon3)/3;
	if(s.TB < 5)
	{
		s.note = "KHONG DAT!";
	}
	else 
	{
		s.note = "DAT!";
	}
    cin.ignore();
}

int tim_kiem_mssv(sv a[], int n, char mssvtam[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].mssv, mssvtam) == 0) {
            return i;
        }
    }
    return -1;
}

void nhap_1_sv_co_ma(sv a[], int n, sv &s) {
    char mssvtam[10];
    int k;
    do {
        cout << "\nNhap mssv: ";
        cin.getline(mssvtam, 50);
        k = tim_kiem_mssv(a, n, mssvtam);
        if(k != -1) {
            cout << "\nMSSV bi trung! vui long nhap lai: " << endl;
        }
    } while(k != -1);
    strcpy(s.mssv, mssvtam);
    nhap_1_sv_ko_ma(s);
}

void nhap_ds_sv(sv a[], int n) {
    for(int i = 0; i < n; i++) {
        nhap_1_sv_co_ma(a, n, a[i]);
    }
}

void tieu_de() 
{
    cout << endl << setw(10) << left << "MSSV" << setw(10) << left << "NAME" << setw(10) << left << "MON 1" << setw(10) << left << "MON 2" << setw(10) << left << "MON 3" << setw(10) << left
        << "DIEM TB" << setw(10) << left << "GHI CHU" << endl;
}

void xuat_1_sv(sv s) {
    cout << endl << setw(10) << left << s.mssv << setw(10) << left << s.name << setw(10) << left << s.mon1 << setw(10) << left << s.mon2 << setw(10) << left << s.mon3 << setw(10) << left
        << s.TB << setw(10) << left << s.note;
}

void xuat_ds_sv(sv a[], int n) {
	tieu_de();
    for(int i = 0; i < n; i++) {
        xuat_1_sv(a[i]);
    }
    cout << endl;
}

void tim_kiem_sv_theo_ma(sv a[], int n) {
    char ma_tk[10];
    cout << "Nhap ma can tim kiem: " << endl;
    cin.getline(ma_tk, 50);
    int pos = tim_kiem_mssv(a, n, ma_tk);
    if(pos == -1) {
        cout << "Ko co sinh vien nay!" << endl;
    }
    else {
        cout << "Sinh vien can tim la: " << endl;
        xuat_1_sv(a[pos]);
    }
}

void hoan_vi(sv &x, sv &y)
{
    sv temp = x; x = y; y = temp;
}

void sap_xep_tang_dan(sv a[], int n) 
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++) 
        {
            if(a[i].TB > a[j].TB)
            {
                hoan_vi(a[i], a[j]);
            }
        }
    }
}

int main() {
    sv a[10];
    int n = 3;
    nhap_ds_sv(a, n);
    cout << "\nDANH SACH SINH VIEN VUA NHAP: " << endl;
    xuat_ds_sv(a, n);
    sap_xep_tang_dan(a, n);
	cout << "\nDANH SACH SINH VIEN SAP XEP DIEM TB TANG DAN: " << endl;
	xuat_ds_sv(a, n);
    cout << endl;
    system("pause");
    return 0;
}