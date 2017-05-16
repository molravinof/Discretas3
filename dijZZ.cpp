#include<NTL/ZZ.h>
//#include<iostream>
#include<omp.h>
#include<cstdio>
using namespace std;
using namespace NTL;

typedef ZZ nat;

nat mcd(nat &a,nat &b){
    cout<<"a: "<<a<<" b: "<<b<<endl;
    if(a==b)
        return a;
    else if(a>b){
        a-=b;
        return mcd(a,b);
    }
    else if(b>a){
        b-=a;
        return mcd(a,b);
    }
}
int main(){
    printf("-------- Simply count elapsed time (CountTime) -------\n");
    const double startTime = omp_get_wtime();
    nat a,b,c;
    a=123456789;
    b=473456789;
    c=mcd(a,b);
    cout<<c<<endl;
    const double endTime = omp_get_wtime();
    printf("Duration = %lf seconds\n", (endTime - startTime));
    printf("------------------------------------------------------\n");
    return 0;
}

//g++ -g -O2 dijzzz.cpp -lgomp -o m -lntl -lgmp -lm

