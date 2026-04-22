#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdexcept>
#include <cmath>
#include <algorithm>
using namespace std;
struct ComplexVal{
private:
    double real, img;
public:
    ComplexVal(double r, double i):real(r),img(i){};
};
class MyMatrix{
    
    private:
      int nRow, nCol;
      double **pD;
    public:
      MyMatrix(){};

      MyMatrix(int nR, int nC){
        this->nRow = nR;
        this->nCol = nC;
      }
        double& at(int r, int c);
        double det();
      
      ~MyMatrix(){
        for (int i = 0; i < nRow; i++){
            delete[] pD[i];
        }
        delete[] pd;
        pD = nullptr;
      }
};
MyMatrix::MyMatrix():nRow(0),nCol(0),pD(nullptr){};
MyMatrix::MyMatrix(int nR, int nC), nRow(nR), nCol(nC),pD(nullptr){
    pD = new double*[nR]; 

    // 2. Cấp phát MỘT KHỐI DUY NHẤT cho toàn bộ dữ liệu (nR * nC phần tử)
    // Gán địa chỉ đầu tiên của khối này cho hàng đầu tiên (pD[0])
    pD[0] = new double[nR * nC]; 

    // 3. Vòng lặp "phân lô bán nền":
    // Chia khối dữ liệu lớn thành từng đoạn, mỗi đoạn dài nC phần tử
    for (double **p = pD + 1, **pE = pD + nR; p != pE; ++p) {
        *p = *(p - 1) + nC; 
    }
}
MyMatrix::~MyMatrix(){
    if (!pD) return nullptr;
    delete[] *pD;
    delete[] pD;
}
MyMatrix MyMatrix::operator+(MyMatri &M){
    if (nRow != M.nRow || nCol != M.nCol) throw -1;
    MyMatrix res(nRow, nCol); 
    for (double *p = res.pD, *pA = *pD, *pC = *M.pD, *pE = p + nRow*nCol; p != pE){
        *p++ = *pA++ + *pC++;
    }
    return p;
}
MyMatrix MyMatrix::operator*(MyMatrix &M){
    if (nCol != M.nRow) throw -1;
    MyMatrix res(nRow, nCol);

    double *pDestStart = *res.pD;

}
int main(int argc, char *argv[]){
    string s1 = "hello world";
    string s2 = "hello world";
    cout << (s1 == s2) << endl;
    cout << (s1.c_str() == s2.c_str()) << endl;
}