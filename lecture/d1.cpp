#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdexcept>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;


class MyMatrix{
    private:
      int nRow, nCol;
      double **pD;
    public:
      MyMatrix() : nRow(0), nCol(0), pD(nullptr){}
      MyMatrix(int nR, int nC):nRow(nR),nCol(nC){
        if (nR <= 0 || nC <= 0){
            pD = nullptr;
            return;
        }
        pD = new double*[nR];
        pD[0] = new double[nR * nC];
        for (double **p = pD + 1, **pE = pD + nR; p < pE; ++p){
            *p = *(p - 1) + nC;
        }
      }
      ~MyMatrix(){
        if (pD){
            delete[] pD[0];
            delete[] pD;
        }
      }
      double& at(int r, int c){
        if (r >= nRow || r < 0 || c >= nCol || c < 0) throw std::out_of_range("loi");
        return *(*(pD + r) + c);
      }
      MyMatrix operator+(const MyMatrix &M){
        if (this->nCol != M.nCol || this->nRow != M.nRow){
            throw -1;
        }
        MyMatrix res(nRow, nCol);
        double *pRes = *res.pD;
        double *pA = *pD;
        double *pB = *M.pD;
        double **pEnd = pD + (nRow*nCol);
        while (pRes < *pEnd){
          *pRes++ = *pA++ + *pB++;

        }
        return res;
      }
      MyMatrix operator*(MyMatrix &M){
        if (nRow != M.nCol) throw invalid_argument("Invalid dimension!");
        MyMatrix res(nRow, M.nCol);
        for (int i = 0; i < nRow; ++i){
          for (int j = 0; j < M.nCol; ++j){
            double sum = 0;
            double *pRowA = *(pD + i);
            double *pColB = *(M.pD) + j;
            for (int k = 0; k < nCol; ++k){
              sum += (*pRowA) * (*pColB);
              pColB += M.nCol;
            }
            res.at(i,j) = sum;
          }
        }
        return res;
      }
      void print(){
        for (int i = 0; i < nRow; ++i){
            for (int j = 0; j < nCol; ++j){
                cout << at(i,j)<<" ";
            }
            cout <<"\n";
        }
      }
};   
void reverse(int *arr, int size){
  if (size <= 1) return;
  int *left = arr;
  int *right = arr + size - 1;
  while (left < right){
    int temp = *left;
    *left = *right;
    *right = temp;
    left++;
    right--;
  }

}
//Ép kiểu tới chết
class MatrixPro{
  private: 
    int rows, cols;
    int *data;
  public:
    MatrixPro(int r, int c):rows(r),cols(c){
      data = new int[r*c];
    }
    ~MatrixPro(){
      delete[] data;
    }
    void set(int r, int c, int val){
      *(data + (r * cols + c)) = val;
    }
    void print(){
      for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
          cout << *(data + (i*cols+j)) << " ";
        }
        cout << endl;
      }
    }
    MatrixPro operator+(const MatrixPro &M){
      if (this->rows != M.rows || this->cols != M.cols) throw -1;
      MatrixPro res(rows, cols);
      int *pRes = M.data;
      int *pA = this->data;
      int *pB = M.data;
      int *pEnd = this->data + (rows*cols);
      while (pRes < pEnd){
        *pRes++ = *pA++ + *pB++;
      }
      return res;
    }
};
string longestDuplicate(string s){
  map<char, int> freq;
  string res = "";
  int max_num = 0;
  for (int i = 0; i < s.length(); ++i){
    freq[s[i]]++;
    max_num = max(max_num, freq[s[i]]);
  }
  for (int i = 0; i < s.length();++i){
    if (freq[s[i]] == max_num){
      res += s[i];
    }
  }
  return s;
  
}
int countSetBits(int n){
  int count = 0;
  while (n > 0){
    n &= (n-1);
    count++;
  }
  return count;
}


template <class T> 
class Array2D {
private:
	int r;
	int c;
	T** arr;

public:
    Array2D(int r, int c){
       this->r = r;
       this->c = c;
       this->p = new T*[r];
       for (int i = 0; i < r; i++){
           this->p[i] = new T[c];
       }
    }
    Array2D(int r, int c, T init){
        this->r = r;
       this->c = c;
       this->p = new T*[r];
       for (int i = 0; i < r; i++){
           this->p[i] = new T[c];
       }
       for (int i = 0 ; i < r; i++){
           for (int j = 0; j < c; j++){
               this->p[i][j] = init;
           }
       }
    }
    ~Array2D(){
        if (this->p != nullptr){
        for (int i = 0; i < r; i++){
            delete[] this->p[i];
        }
        delete[] this->p;
        this->p = nullptr;
        }
    }
    
    

    int getR() {return this->r;}
    int getC() {return this->c;}
    
    void disp() {
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Array2D operator*(const Array2D &M){
      if (this->r != M.r){return nullptr;}
      Array2D res(this->r, M.c);
      for (int i = 0; i < this->r; ++i){
        for (int j = 0; j < M.c; ++j){
          int sum = 0;
          T *tRowA = *(arr + i);
          T *tColB = *(M.arr + j);
          for (int k = 0; k < c; ++k){
            sum += (*tRowA) * (*tColB);
            tColB += M.c;
          }
          res->arr[i][j] = sum;
        }
      }
      return res;
    }
   
};

class Coordinate{
  private:
    float x;
    float y;
  public:
    Coordinate(float x, float y) : x(x), y(y){};
    void setX(float x){this->x = x;}
    void setY(float y) {this->y = y;}
    float getX(){return this->x;}
    float getY(){return this->y;}
    float distanceTo(Coordinate &other){
       return abs(this->x - other.x) + abs(this->y - other.y);
    }
};
int main() {
   float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1,2);
    Coordinate b(0,1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);
    return 0;
}