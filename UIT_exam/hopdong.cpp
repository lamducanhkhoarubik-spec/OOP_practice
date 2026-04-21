#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define pb push_back
#define ll long long
using namespace std;
bool isLeap(int y){
	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
long countDays(int d, int m, int y){
	int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    long total = 365 * y + d;
	for (int i = 0; i < m - 1; i++){
		total += monthDay[i];
	}
	if (m > 2 && isLeap(y)){
		total++;
	}
	total += y/4 - y/100+y/400;
	return total;
}
class cNgay{
	private:
	  int ngay;
	  int thang;
	  int nam;
	public:
	  friend istream& operator>>(istream&, cNgay&);
	  int operator-(cNgay&);
};
class cHopDong{
	protected:
	  string TenDoiTac;
	  string TenPhanMem;
	  cNgay NgayHoanThanhDuKien;
	  string LinhVuc;
	  string NenTangKyThuat;
	  float CPChung;
	  float CPBandau;
	  int thoigiangiacong;
	  float luongnhansu;
	public:
	  enum LOAI{CHUNG,TRON_GOI, PHAT_TRIEN, TAI_CHO};
	  LOAI loaihopdong;
	  cHopDong() {loaihopdong = CHUNG;}
	  virtual void Nhap();
	  virtual float LoiNhuan() = 0;
};
class cHopDongTronGoi : public cHopDong{
     private:
	    float GiaTri;
		cNgay NgayHoanThanh;
     public:
	    void Nhap();
		float LoiNhuan();
};
class cHopDongPhatTrien : public cHopDong{
	private:
	   float ChiPhiNhanSu;
	public:
	   virtual void Nhap();
	   float LoiNhuan();
};
class cHopDongTaiCho : public cHopDongTronGoi{
	private:
	   float phiSinhHoat;
	public:
	cHopDongTaiCho() : phiSinhHoat(0) {loaihopdong = TAI_CHO;}
	   void Nhap();
	   float LoiNhuan();
};
class cDsHopDong{
	private:
	  vector<cHopDong*> ds;
	public:
	  void Nhap();
	  float tongLoiNhuan(cHopDong::LOAI loai = cHopDong::CHUNG);
	  string LoiNhuanCaoNhat();

};
istream &operator>>(istream &is, cNgay &d){
	is >> d.ngay >> d.thang >> d.nam;
	return is;
}
int cNgay::operator-(cNgay &a){
	return countDays(a.ngay, a.thang, a.nam) - countDays(this->ngay, this->thang, this->nam);
}
void cHopDong::Nhap(){
	cin >> TenDoiTac >> TenPhanMem >> NgayHoanThanhDuKien >> LinhVuc >> NenTangKyThuat >> CPChung >> CPBandau >> thoigiangiacong >> luongnhansu;
}
void cHopDongTronGoi::Nhap(){
	cHopDong::Nhap();
	cin >> GiaTri >>NgayHoanThanh;

}
void cHopDongPhatTrien::Nhap(){
	cHopDong::Nhap();
	cin >> ChiPhiNhanSu;
}
void cHopDongTaiCho::Nhap(){
	cHopDongTronGoi::Nhap();
	cin >> phiSinhHoat;
}
float cHopDongTronGoi::LoiNhuan(){
	float LOI_NHUAN = GiaTri - ((luongnhansu + CPChung) * thoigiangiacong) - CPBandau;
	int THOI_GIAN_TRE = NgayHoanThanh - NgayHoanThanhDuKien;
	if (THOI_GIAN_TRE >= 15
		&& THOI_GIAN_TRE < 90) {
		LOI_NHUAN += GiaTri * 0.1f;
	}
	else if (THOI_GIAN_TRE >= 90) {
		LOI_NHUAN += GiaTri * 0.3f;
	}
	return LOI_NHUAN;
	
}
float cHopDongPhatTrien::LoiNhuan(){
	float profit = (ChiPhiNhanSu - luongnhansu - CPChung)*thoigiangiacong - CPBandau;
	return profit;
}
float cHopDongTaiCho::LoiNhuan(){
	float profit = cHopDongTronGoi::LoiNhuan() - phiSinhHoat * thoigiangiacong;
	return profit;
}
void cDsHopDong::Nhap(){
	int n;
	cout <<"Nhap so luong hop dong: ";
	cin >> n;
	for (int i = 0; i < n; ++i){
		cout <<"Nhap loai hop dong (1-Tron goi, 2-Phat trien, 3-TaiCho): ";
		int type;
		cin >> type;
		cHopDong *temp;
		if (type == 1){
			temp = new cHopDongTronGoi();
		}
		else if (type == 2){
			temp = new cHopDongPhatTrien();
		}
		else{
			temp = new cHopDongTaiCho();
		}
		temp->Nhap();
		ds.pb(temp);
	}
}
float cDsHopDong::tongLoiNhuan(cHopDong::LOAI loai){
	
	if (loai == cHopDong::CHUNG){
		float sum = 0;
		for (cHopDong *HD : ds){
			sum += HD->LoiNhuan();
		}
	}
	else{
		float sum = 0;
		for (cHopDong *HD : ds){
			if (HD->loaihopdong == loai){
				sum += HD->LoiNhuan();
			}
		}
		return sum;
	}
	
}
string cDsHopDong::LoiNhuanCaoNhat(){
   float sum_trongoi = tongLoiNhuan(cHopDong::TRON_GOI);
   float sum_ptrien = tongLoiNhuan(cHopDong::PHAT_TRIEN);
   float sum_taicho = tongLoiNhuan(cHopDong::TAI_CHO);
   float max_type = max({sum_trongoi, sum_ptrien, sum_taicho});
   if (max_type == sum_trongoi) return "TRON_GOI";
   else if (max_type == sum_ptrien) return "PHAT_TRIEN";
   else return "TAI_CHO";
}
int main(int argc, char *argv[]){
	cDsHopDong GlobalTech;
	cout << "a. Nhap danh sach hop dong:" << endl;
	GlobalTech.Nhap();
	cout << "b. Tong loi nhuan: "
		<< GlobalTech.tongLoiNhuan();
	cout << "c. Loai hop dong co loi nhuan cao nhat: "
		<< GlobalTech.LoiNhuanCaoNhat();
}