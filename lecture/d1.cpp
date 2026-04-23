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
int main() {
   
    return 0;
}