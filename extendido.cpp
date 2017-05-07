#include<iostream>
using namespace std;

typedef int nat;

class euclides{
protected:
    nat m_a; //numeros
    nat m_b; //para sacar los coeficientes Bezout

    nat m_x; //coef x de Bezout
    nat m_y; //coef y de Bezout
    nat m_mcd; //el Maximo comun divisor
public:
    euclides():m_a(1),m_b(1){}
    euclides(nat a,nat b):m_a(a),m_b(b){
        coef();
    }

    void coef(){
        nat x1,x2,y1,y2,c,r,tx,ty;
        x1=1;
        x2=0;
        y1=0;
        y2=1;
        if(m_a < m_b){ //ordenamos  para 
            m_a=m_a+m_b; //q m_a sea siempre mayor
            m_b=m_a-m_b; //q m_b 
            m_a=m_a-m_b;
        }
        nat t_a=m_a,t_b=m_b; //con el fin de conservar los componentes originales
        while(t_b>0){
            c=t_a/t_b; //de este modo la division no sera cero
            r=t_a-c*t_b;
            tx=x1-c*x2;
            ty=y1-c*y2;
            x1=x2;
            y1=y2;
            x2=tx;
            y2=ty;
            t_a=t_b;
            t_b=r;
        }
        m_x=x1;
        m_y=y1;
        m_mcd=t_a;
    }
    void setA(nat a){   
        this->m_a=a;
    }
    void setB(nat b){   
        this->m_b=b;
    }
    nat getA(){ return m_a;}
    nat getB(){ return m_b;}
    nat getX(){ return m_x;}
    nat getY(){ return m_y;}
    nat getMcd(){   return m_mcd;}
    friend ostream& operator<<(ostream& out, euclides &eu){
        out<<eu.getA()<<"("<<eu.getX()<<")"<<"+"<<eu.getB()<<"("<<eu.getY()<<")"<<"="<<eu.getMcd();
        return out;
    }
};


int main(){
    euclides a(52,47);
    /*cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
    cout<<a.getMcd()<<endl;*/
    cout<<a<<endl;
    return 0;
}
