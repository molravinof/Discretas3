#include<NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ mcd(ZZ &a,ZZ &b){
    if(b==0)
        return a;
    a%=b;
    return mcd(b,a);
}

int main(){
    ZZ a,b,c;
    a=15;
    b=4;
    c=mcd(a,b);
    cout<<c;
    return 0;
}
