#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdexcept>
using namespace std;


class Nguoi{
    public:
      enum LOAI{NGUOI,SV,CN};
      LOAI pl;
    protected:
      char *hoTen;
      int NamSinh;
    public:
      Nguoi(const char *ht, int ns):NamSinh(ns),pl(NGUOI){
        hoTen = strdup(ht);

      }
      virtual ~Nguoi(){
        if (hoTen) delete[] hoTen;
      }
      virtual void Xuat() const{
        cout<<"HoTen: "<<hoTen<<" nam sinh: "<<NamSinh;
      }
};
class SinhVien : public Nguoi{
    protected:
       char *maSo;
    public:
       SinhVien(const char *n, const char *ms, int ns):Nguoi(n,ns){
        maSo = strdup(ms);
        pl = SV;
       }
       ~SinhVien(){
        if (maSo) delete[] maSo;
       }
       void Xuat() const override{
          printf("Sinh Vien: %s, Ma So: %s",hoTen, maSo);
       }
};
class CongNhan : public Nguoi{
    protected:
      double mucLuong;
    public:
      CongNhan(const char *n, double ml, int ns):Nguoi(n,ns){
        mucLuong = ml;
        pl = CN;
      }
      void Xuat() const override{
        cout <<"Cong nha, ten: "<<hoTen<<" muc luong: "<<mucLuong;
      }

};
void Xuatds(int n, Nguoi *an[]){
    for (int i = 0; i < n; i++){
        switch (an[i]->pl)
        {
        case Nguoi::SV:
            ((SinhVien*)an[i])->Xuat();
            break;
        case Nguoi::CN:
            ((CongNhan*)an[i])->Xuat();
            break;
        default:
            an[i]->Xuat();
            break;
        }
        cout <<"\n";
    }
};
class FileHandler{
    public:
      FileHandler(){
        cout <<"[1] Constructor: Mo file thanh cong!\n";

      }
      ~FileHandler(){
        cout <<"[2] Destructor: Dong file thanh cong!\n";
      }
      
};
void processData(){
    FileHandler fh;
    cout <<"[3] Dang doc du lieu .....\n";
    throw runtime_error("!!!LOI\n");
    cout <<"---Ket thuc---\n";
}

class SoPhuc{
  private:
    float *thuc;
    float *ao;
  public:
    SoPhuc(){
      thuc = new float(1.0);
      ao = new float(1.0);
    }
    SoPhuc(float r, float i){
      thuc = new float(r);
      ao = new float(i);
    }
   
    SoPhuc operator+(const SoPhuc &com){
      return SoPhuc(*(this->thuc) + *(com.thuc), *(this->ao) + *(com.ao));
    }
    SoPhuc operator+=(const SoPhuc &com){
      *(this->thuc) += *(com.thuc);
      *(this->ao) += *(com.ao);
      return *this;
    }
    SoPhuc operator*(const SoPhuc &com){
      SoPhuc kq;
      *(kq.thuc) = (*(this->thuc))*(*(com.thuc)) - (*(this->ao))*(*(com.ao));
      *(kq.ao) = (*(this->thuc))*(*(com.thuc)) + (*(this->ao)) * (*(com.ao));
      return kq;
    }
    SoPhuc operator+(const float temp){
      return SoPhuc(*(this->thuc) + temp, *(this->ao));
    }
    friend ostream& operator<<(ostream &os, const SoPhuc &temp){
      os <<*(temp.thuc)<<" + "<<*(temp.ao)<<"i";
      return os;
    }
    ~SoPhuc(){
      delete thuc;
      delete ao;
    }


  
};

class MayIn{
  public:
     void inKetQua(SoPhuc sp){
      cout << "Ketqua: "<<sp<<"\n";
     }
}
int main(int argc, char *argv[]){
    MayIn()
}