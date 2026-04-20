#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class NhomMau{
    protected:
      char Rh;
    public:
      void Nhap();
      virtual bool KiemTraChaMe(NhomMau*, NhomMau*) = 0;
      virtual bool KiemTraTuongThich(NhomMau*) = 0;
      char getRh();
      virtual char getMau() = 0;
};
class A : public NhomMau{
    public:
      char getMau();
      bool KiemTraChaMe(NhomMau*, NhomMau*);
      bool KiemTraTuongThich(NhomMau*);
};
class B : public NhomMau{
    public:
      char getMau();
      bool KiemTraChaMe(NhomMau*, NhomMau*);
      bool KiemTraTuongThich(NhomMau*);
};
class AB : public NhomMau{
    public:
      char getMau();
      bool KiemTraChaMe(NhomMau*, NhomMau*);
      bool KiemTraTuongThich(NhomMau*);
};
class O : public NhomMau{
    public:
      char getMau();
      bool KiemTraChaMe(NhomMau*, NhomMau*);
      bool KiemTraTuongThich(NhomMau*);
};
class DanhSach{
    protected:
      int n;
      NhomMau* ds[100];
    public:
      void Nhap();
      bool KiemTraDiTruyen();
      void TimKiemNguoiCho();

};
void NhomMau::Nhap(){
    cout <<"Nhap Rh: ";
    cin >> Rh;
}
char NhomMau::getRh(){
    return Rh;
}
char A::getMau(){
    return 'A';
}
char B::getMau(){
    return 'B';
}
char AB::getMau(){
    return 'C';
}
char O::getMau(){
    return 'O';
}
bool A::KiemTraChaMe(NhomMau *cha, NhomMau *me){
    char mauCha = cha->getMau();
    char mauMe = me->getMau();
    if (mauCha == 'A' || mauCha == 'C' || mauMe == 'A' || mauMe =='C'){
        return true;
    }
    return false;
}
bool B::KiemTraChaMe(NhomMau *cha, NhomMau *me){
    char mauCha = cha->getMau();
    char mauMe = me->getMau();
    if (mauCha == 'B' || mauCha == 'C' || mauMe == 'B' || mauMe == 'C'){
        return true;
    }
    return false;
}
bool AB::KiemTraChaMe(NhomMau *cha, NhomMau *me){
    char mauCha = cha->getMau();
    char mauMe = me->getMau();
    if ((mauCha == mauMe && mauCha != 'C') || (mauCha == 'O' || mauMe == 'O') ){
        return false;
    }
    return true;
}
bool O::KiemTraChaMe(NhomMau *cha, NhomMau *me){
    char mauCha = cha->getMau();
    char mauMe = me->getMau();
    if (mauCha == 'C' && mauMe == 'C'){
        return false;
    }
    return true;
}
bool A::KiemTraTuongThich(NhomMau *other){
   if (other->getMau() == 'A' || other->getMau() == 'O'){
    if (other->getRh() == '+' || other->getRh() == '-'){
        return true;
    }
    
   }    
   return false;
}
bool B::KiemTraTuongThich(NhomMau *other){
    if (other->getMau() == 'B' || other->getMau() == 'O'){
        if (other->getRh() == '+' || other->getRh() == '-'){
            return true;
        }
        
    }
    return false;
}
bool AB::KiemTraTuongThich(NhomMau *other){
    if (other->getRh() == '+' || other->getRh() == '-'){
        return true;
    }
    return false;
}
bool O::KiemTraTuongThich(NhomMau *other){
    if (other->getMau() == 'O'){
        if (other->getRh() =='+'||other->getRh() == '-'){
            return true;
        }
    }
    return false;
}
void DanhSach::Nhap(){
    for (int i = 0; i < n; i++){
        cout <<"Nhap nhom mau (A - A, B - B, C - AB, O-O): ";
        char type;
        cin >> type;
        if (type == 'A'){
            ds[i] = new A();
        }
        else if (type == 'B'){
            ds[i] = new B();
        }
        else if (type == 'C'){
            ds[i] = new AB();
        }
        else{
            ds[i] = new O();
        }
        ds[i]->Nhap();
    }
}
bool DanhSach::KiemTraDiTruyen(){
    int cha, me, con;
    cout <<"Nhap nhom mau lan luot (cha, me, con): ";
    cin >> cha >> me>>con;
    if (ds[con]->KiemTraChaMe(ds[cha], ds[me]) == 1){return true;}
    return false;
}
void DanhSach::TimKiemNguoiCho(){
    int X;
    cout <<"Nhap nguoi X: ";
    cin >> X;
    cout <<"Nhung nguoi co the cho mau X: ";
    for (int i = 0; i < n; i++){
        if (ds[X]->KiemTraTuongThich(ds[i])){
            cout <<"Nguoi thu "<< i<<" ";
        }
    }

    
}
int i = 0;
class K{
public:
K() {
i = 3;
}
~K() {
i=10;
}
};
int foo() {
int &p = i;
A ob;
return p;
}
int main(){
    int a = 5;
    int &p = a;
    a = 6;
    
    cout << p;
}