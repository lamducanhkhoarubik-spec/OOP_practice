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
    cout <<foo();
}