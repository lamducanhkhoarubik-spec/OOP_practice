(*(com.thuc)) - (*(this->ao))*(*(com.ao));
      *(kq.ao) = (*(this->thuc))*(*(com.thuc)) + (*(this->ao)) * (*(com.ao));
      return kq;
    }
    SoPhuc operator+(const float temp){
      return SoPhuc(*(this->thuc) + temp, *(this->ao));
    }
    friend ostream operator<<(ostream &os, const SoPhuc &temp){
      os <<*(temp.thuc)<<" + "<<*(temp.ao)<<"i";
      return os;
    }
    ~SoPhuc(){
      delete thuc;
      delete ao;
    }


  
};
int main(int argc, char *argv[]){
    SoPhuc a;
    SoPhuc b(2.5,7.1);
    a += b;
    SoPhuc d = a*b;
    SoPhuc c = a+b+5;
    cout << b;
}