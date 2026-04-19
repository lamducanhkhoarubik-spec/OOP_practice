#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long 

using namespace std;


class Nguoi{
  private:
     int maKhach;
     string ten;
     string SDT;
  public:
     void Nhap();
     void Xuat();
     int getMaKhach();
};
class Ngay{
  private:
    int ngay;
    int thang;
    int nam;
  public:
    void Nhap();
    void Xuat();
};
class SanPham{
  protected:
     long gia;
     string maSo;
     string tieuDe;
  public:
     void Nhap();
     void Xuat();
     long getGia();
};
class TranhAnh : public SanPham{
  protected:
     int cao;
     int rong;
     string hoaSi;
  public:
     void Nhap();
     void Xuat();
};
class CD : public SanPham{
  protected:
     string caSi;
     string donVi;
  public:
     void Nhap();
     void Xuat();
};
class HoaDon{
  protected:
     string maDon;
     Nguoi khach;
     Ngay ngayCap;
     int n;
     SanPham *hd[100];
     long tongGia;
  public:
     void Nhap();
     void Xuat();
     long getTongGia();
     Nguoi getKhach();
}
class CuaHang{
  protected: 
    int size;
    HoaDon ds[100];
  public:
    void Nhap();
    void Xuat();
    long ThuNhap();
    void TimKiemMax();
};
void Nguoi::Nhap(){
    cout <<"Nhap ma khach hang: ";
    cin >>maKhach;
    cout <<"Nhap ho ten: ";
    cin >> ten;
    cout <<"Nhap SDT: ";
    cin >>SDT;
}
void Nguoi::Xuat(){
  cout <<"Ma khach hang: "<<maKhach<<"\n";
  cout <<"Ho ten: "<<ten<<"\n";
  cout <<"SDT: "<<SDT<<"\n";
}
int Nguoi::getMaKhach(){
  return this->maKhach;
}
void Ngay::Nhap(){
  cout<<"Nhap ngay: ";
  cin >> ngay;
  cout <<"Nhap thang: ";
  cin >> thang;
  cout <<"Nhap nam: ";
  cin >> nam;
}
void Ngay::Xuat(){
  cout <<ngay<<"/"<<thang<<"/"<<nam;
}
void SanPham::Nhap(){
  cout <<"Nhap ma so: ";
  cin >> maSo;
  cout <<"Nhap tieu de: ";
  cin >> tieuDe;
  cout <<"Nhap gia: ";
  cin >> gia;
}
void SanPham::Xuat(){
  cout << "Ma so: "<<maSo<<"\n";
  cout << "Tieu de: "<<tieuDe<<"\n";
  cout << "Gia: "<<gia<<"\n";
}
long SanPham::getGia(){
  return gia;
}
void TranhAnh::Nhap(){
  SanPham::Nhap();
  cout <<"Cao: ";
  cin>> cao;
  cout <<"rong: ";
  cin >> rong;
  cout <<"HoaSi: ";
  cin>> hoaSi;
}
void TrangAnh::Xuat(){
  cout << "Chieu cao: "<<cao<<"\n";
  cout << "Chieu rong: "<<rong<<"\n";
  cout << "Hoa Si: "<<hoaSi<<"\n";
}
void CD::Nhap(){
  SanPham::Nhap();
  cout <<"Nhap thong tin CD: \n";
  cout <<"Nhap ten ca si: ";
  cin >> caSi;
  cout <<"Nhap ten don vi: ";
  cin >> donVi;
}
void CD::Xuat(){
  cout << "Ca si: "<<caSi<<"\n";
  cout << "Don vi: "<<donVi<<"\n";
}
void HoaDon::Nhap(){
  cout <<"Nhap hoa don: \n";
  cout <<"Nhap ma don hang: ";
  cin >> maDon;
  cout <<"Nhap thong tin khach hang: ";
  khach.Nhap();
  cout <<"Nhap ngay cap: ";
  ngayCap.Nhap();
  cout <<"Nhap so san pham: ";
  cin >> n;
  cout <<"Nhap san pham: ";
  for (int i = 0; i < n; i++){
    cout <<"Nhap san pham thu "<<i+1<<"\n";
    int loai;
    cout <<"Nhap loai san pham: (0: Tranh Anh, 1: CD)";
    cin >> loai;
    if (loai == 0){
      hd[i] = new TranhAnh();
    }
    else{
      hd[i] = new CD();
    }
    hd[i]->Nhap();
  }
 
}
long getTongGia(){
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += hd[i]->getGia();
  }
  return sum;
}
void HoaDon::Xuat(){
  cout << "-----HOA DON-----\n";
  cout <<"Ma hoa đon: "<<maDon;
  cout <<"Thong tin khach hang: ";
  khach.Xuat();
  
  cout <<"Ngay Cap: ";
  ngay.Xuat();
  for (int i = 0; i < n; i++){
    cout << "San pham thu "<< i+1<<"\n";
    hd[i]->Xuat();
  }
  cout <<"Tong gia tien: "<<getTongGia();
}
Nguoi HoaDon::getKhach(){
  return khach;
}
void CuaHang::Nhap(){
  cout <<"Nhap so hoa don: ";
  cin >> size;
  for (int i = 0; i < size; i++){
    cout << "Hoa don thu "<<i+1<<": ";
    ds[i].Nhap();
  }

}
void CuaHang::Xuat(){
   for (int i =0; i < size; i++){
    cout <<"Hoa don thu "<<i+1<<"\n";
    ds[i].Xuat();
   }
}
long CuaHang::ThuNhap(){
  int sum = 0;
  for (int i = 0; i < size; i++){
    sum += ds[i].getTongGia();

  }
  return sum;
}
void TimKiemMax(){
  int max_tong = ds[0].getTongGia();
  int curr;
  for(int i = 0; i < size; i++){
    if (max_tong < ds[i].getTongGia()){
      max_tong = ds[i].getTongGia();
      curr = i;
    }
  }
  cout <<"Khach hang mua nhieu nhat o cua hang la: \n";
  ds[curr].Xuat();
}
int main(int argc, char *argv[]){


}