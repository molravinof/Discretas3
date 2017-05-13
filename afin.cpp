#include<iostream>
#include<string>
using namespace std;

typedef int t_nat;

class bezout{
protected:
    t_nat m_a; //numeros
    t_nat m_b; //para sacar los coeficientes Bezout

    t_nat m_x; //coef x de Bezout
    t_nat m_y; //coef y de Bezout
    t_nat m_mcd; //el Maximo comun divisor
public:
    bezout():m_a(1),m_b(1){}
    bezout(bezout &o):m_a(o.getA()),m_b(o.getB()),m_x(o.getX()),m_y(o.getY()),m_mcd(o.getMcd()){}
    bezout(t_nat a,t_nat b):m_a(a),m_b(b){
        this->coef();
    }
    void coef(){
        t_nat x1,x2,y1,y2,c,r,tx,ty;
        x1=1;
        x2=0;
        y1=0;
        y2=1;
        if(m_a < m_b){ //ordenamos  para 
            m_a=m_a+m_b; //q m_a sea siempre mayor
            m_b=m_a-m_b; //q m_b 
            m_a=m_a-m_b;
        }
        t_nat t_a=m_a,t_b=m_b; //con el fin de conservar los componentes originales
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
    void setA(t_nat a){   
        this->m_a=a;
    }
    void setB(t_nat b){   
        this->m_b=b;
    }
    t_nat getA(){ return m_a;}
    t_nat getB(){ return m_b;}
    t_nat getX(){ return m_x;}
    t_nat getY(){ return m_y;}
    t_nat getMcd(){   return m_mcd;}
    friend ostream& operator<<(ostream& out, bezout &eu){
        out<<eu.getA()<<"("<<eu.getX()<<")"<<"+"<<eu.getB()<<"("<<eu.getY()<<")"<<"="<<eu.getMcd();
        return out;
    }
};

class cripto{
protected:
	string m_user; //tipo de usuario 
	string m_msn; // mensaje
	t_nat m_bi;  //desplazamiento
	t_nat m_ai; //
	t_nat m_m; //longitud del alfabeto 27
	bezout m_test;
public:
	string minuscula="abcdefghijklmnopqrstuvwxyz"; //alfabeto usado
	cripto():m_user(""),m_msn(""),m_ai(0),m_bi(0){}
	cripto(string usuario,string mensaje,t_nat a, t_nat b):m_user(usuario),m_msn(mensaje),m_ai(a),m_bi(b){
		m_m=minuscula.length();
        bezout temp(m_ai,m_m);
        m_test=temp;
        if(m_user=="emisor"){// si el usuario es el emisor 
			if(m_test.getMcd()==1)
				this->afin(); //encripta el mensaje
			else
				cout<<"a no es co-primo de 27";
		}
		else if(m_user=="receptor"){ //con este usuario
			if(m_test.getMcd()==1)
				this->desafin(); //descencripta el mensaje
			else
				cout<<"a no es coprimo de 27";
		}
		else
				;	
	}
	int getA(){ return this->m_ai;}
	int getB(){ return this->m_bi;}
	int getM(){ return this->m_m;}
	string getMsn(){   return this->m_msn;}
	string getUser(){	return this->m_user;}
	
	void setB(t_nat nk){    this->m_bi=nk;}
	void setMsn(string msn){    this->m_msn=msn;}
	
	/*funcion encriptadora */
	void afin(){
		string xs; //string donde se almacenara el mensaje encriptado
		string ys=this->getMsn(); //el mensaje lo copeo a "ys" para ser recorrido para encriptar 
		for(string::iterator it=ys.begin();it!=ys.end();it++){
			if(!(minuscula.find(*it)==string::npos)){ //si esta en las minusculas
				t_nat pos=minuscula.find(*it); //con find ubico su posicion
				//cout<<pos<<endl;
				pos=(m_ai*pos+m_bi)%m_m; //f(x)=(a*x+b)(mod m)
				*it=minuscula[pos];
				xs+=*it;
			}
			else{ //letras diferentes al alfabeto
				xs+=*it;
			}
		}
		this->setMsn(xs);
	}
	
	void desafin(){
		string xs;
		string ys=this->getMsn();
		//bezout m_test(m_ai,m_m);
		for(string::iterator it=ys.begin();it!=ys.end();it++){
			if(!(minuscula.find(*it)==string::npos)){ //si esta en las minusculas
				t_nat pos=minuscula.find(*it);
				//cout<<pos<<endl;
				pos=(pos-m_bi)*(m_test.getY()); //f'(x)=(f(x)-b)*inv(a,m)(mod m)
				while(pos<0){
					pos+=m_m;
				}
				pos%=m_m;
				*it=minuscula[pos];
				xs+=*it;
			}
			else{
				xs+=*it;
			}
		}
		this->setMsn(xs);
	}
};

int main(){
    bezout a(11,27);
    /*cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
    cout<<a.getMcd()<<endl;*/
    cout<<a<<endl;
	
	cripto e1("emisor","hola",11,3);
	cout<<"mensaje enviado: "<<e1.getMsn()<<endl;
	string mensaje=e1.getMsn();
	
	cripto r1("receptor",mensaje,11,3);
	cout<<"mensaje recibido: "<<r1.getMsn();
    return 0;
}

