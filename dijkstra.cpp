#include<NTL/ZZ.h>
//#include<iostream>
//#include<omp.h>
//#include<cstdio>
using namespace std;
using namespace NTL;

typedef ZZ nat;

nat mcd(nat &a,nat &b){
    //cout<<"a: "<<a<<" b: "<<b<<endl;
    if(a==0 || b==0)
        return a+b;
    else if(a>b){
        a%=b;
        return mcd(a,b);
    }
    else if(b>a){
        b%=a;
        return mcd(a,b);
    }
}
int main(){
   // printf("-------- Simply count elapsed time (CountTime) -------\n");
   // const double startTime = omp_get_wtime();
    nat a,b,c;
    a=1844674407370955161;
    b=8388607;
    int k,q;
    k=NumBits(a);
    q=NumBits(b);
    c=mcd(a,b);
    cout<<"mcd: "<<c<<endl;
    cout<<k<<"\n"<<q<<endl;
    cout<<sizeof(a)<<endl;
   // const double endTime = omp_get_wtime();
   // printf("Duration = %lf seconds\n", (endTime - startTime));
   // printf("------------------------------------------------------\n");
    return 0;
}

//g++ -g -O2 dijzzz.cpp -lgomp -o m -lntl -lgmp -lm
