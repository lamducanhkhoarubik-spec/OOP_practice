#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long 

using namespace std;
class NguoiSoHuu{
    private:
       string tenNguoi;
       int namSinh;
       string cmnd;
       string diaChi;
    public: 
       void Nhap(){
        cout <<"Nhap ten nguoi so huu: ";
        cin.ignore();
        getline(cin,tenNguoi);
        
        cout <<"Nhap nam sinh: ";
        cin >> namSinh;
        cout <<"Nhap CMND: ";
        cin >>cmnd;
        cout <<"Nhap dia chi: ";
        getline(cin,diaChi);
       }
       void Xuat(){
        cout <<tenNguoi<<"\n"<<namSinh<<"\n"<<cmnd<<"\n"<<diaChi<<"\n";
       }
    
};
class Ngay{
    private:
       int ngay;
       int thang;
       int nam;
    public:
       void Nhap(){
        cout <<"Nhap ngay: ";
        cin >> ngay;
        cout <<"Nhap thang: ";
        cin >> thang;
        cout <<"nhap nam: ";
        cin >> nam;
       }
       void Xuat(){
        cout <<ngay<<"/"<<thang<<"/"<<nam<<"\n";
       }
       int getNam(){
         return nam;
       }
};

class DatDai{
    protected:
       string soGiay;
       NguoiSoHuu nguoi;
       int soThua;
       int dienTich;
       Ngay ngayCap;
       string diachiDat;
       int soTo;
       int giaThue;
    public:
       virtual void Nhap(){
           cout << "Nhap so giay: ";
    cin >> soGiay; 
    // Không cần ignore ở đây vì vào NguoiSoHuu::Nhap() đã có ignore đầu hàm rồi

    cout << "Nhap thong tin nguoi so huu: \n";
    nguoi.Nhap();
   cin.ignore();
    cout << "Nhap so thua: ";
    cin >> soThua;

    cout << "Nhap dien tich: ";
    cin >> dienTich;

    cout << "Nhap ngay cap: \n";
    ngayCap.Nhap(); 

    cin.ignore(); // QUAN TRỌNG: Dọn dấu Enter sau khi nhập Năm của ngày cấp
    cout << "Dia chi dat: ";
    getline(cin, diachiDat);

    cout << "Nhap so to: ";
    cin >> soTo;

    cout << "Nhap gia thue: ";
    cin >> giaThue;

       }
       virtual void Xuat(){
        cout <<"So giay: "<<soGiay<<"\n";
        nguoi.Xuat();
        cout <<"So thua: "<<soThua<<"\n"<<"Dien tich: "<<dienTich<<"\n";
        ngayCap.Xuat();
        cout <<"Dia chi dat: "<<diachiDat<<"\n"<<"So to: "<<soTo<<"\n"<<"Gia thue: "<<giaThue<<"\n";
    }
       virtual bool KiemTraNongNghiep(){
        return false;
       }
       int TinhThue(){
        return dienTich * giaThue;
       }
};
class DatNongNghiep : public DatDai{
    private:
       Ngay thoiHan;
    public:
       void Nhap(){
        DatDai::Nhap();
        cout <<"Nhap thoi han: ";
        thoiHan.Nhap();
       }
       void Xuat(){
        DatDai::Xuat();
        cout <<"Thoi han: ";
        thoiHan.Nhap();

       }
       bool KiemTraNongNghiep(){
        return true;
       }
       bool KiemTraThoiHan(){
        if (thoiHan.getNam() < 2026){
            return true;
        }
        return false;
       }
};
class DatO : public DatDai{};
class DanhSachDat{
    private:
      DatDai *arr[50];
      int size;
    public:
      void Nhap(){
        cout <<"Nhap so luong dat: ";
        cin >>size;
        for (int i = 0; i < size; ++i){
            cout <<"Nhap dat thu "<<i + 1<<"(1: Dat Nong Nghiep, 2: Dat O)\n";
            int type;
            cin >> type;
            if(type == 1){
                arr[i] = new DatNongNghiep();
            }
            else{
                arr[i] = new DatO();
            }
            arr[i]->Nhap();
        }
      }
      DatDai *TimThueNhieuNhat(){
        int max_tax = 0;
        for (int i = 0; i < size; i++){
            if (arr[max_tax]->TinhThue() < arr[i]->TinhThue()){
                max_tax = i;
            }
        }
        return arr[max_tax];
      }
      void XuatDatNongNghiepHetHan(){
        for (int i = 0; i < size; i++){
            if (arr[i]->KiemTraNongNghiep()){
                if (((DatNongNghiep*) arr[i])->KiemTraThoiHan()){
                    arr[i]->Xuat();
                }
            }
        }
      }
};


int main (int argc, char *argv[]){
   DanhSachDat item; 
 item.Nhap(); 
 DatDai* kq = item.TimThueNhieuNhat(); 
 kq->Xuat(); 
 item.XuatDatNongNghiepHetHan(); 
 return 0; 
}