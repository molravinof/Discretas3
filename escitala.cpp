#include<iostream>
#include<string>
using namespace std;

string encripto(string &xs,int row){
	string* grupos=new string[row];
	int i=0;
    bool estado=false;//desenso
	for(string::iterator it=xs.begin();it!=xs.end();it++){
        if(estado){//true ascende
            grupos[i]+=*it;
            i--;
            if(i==-1){
                i=i+2;
                estado=false;
            }
        }
        else if(!estado){//false desiende
            grupos[i]+=*it;
            i++;
            if(i==row){
                i=i-2;
                estado=true;
            }
        }
	}
    string rpta;
    for(int j=0;j<row;j++){
        rpta+=grupos[j];
    }
    return rpta;
}

string desencripto(string &xs,int row){
    string* grupos=new string[row];
	int i=0;
	bool estado=false;//desenso
	for(string::iterator it=xs.begin();it!=xs.end();it++){
		if(estado){//true ascende
			grupos[i]+=*it;
			i--;
			if(i==-1){
				i=i+2;
				estado=false;
			}
		}
		else if(!estado){//false desiende
			grupos[i]+=*it;
			i++;
			if(i==row){
				i=i-2;
				estado=true;//ascenso
			}
		}
	}
    int k=0;
    int j=0;
    while(k<row){
        grupos[k]=xs.substr(j,grupos[k].length());
        j+=grupos[k].length();
		cout<<grupos[k]<<endl;
		++k;
    }
    i=0;//recorrer el string xs
    j=0;//recorrer los grupos
    k=0;//recorrer las letras de los grupos
	int ciclo=0;
    estado=true;//adelante
    string rpta;
    while(i<xs.length()){
        if(estado){//ida
			if(j==(row-1)){
				rpta+=grupos[j][k-ciclo];
				j--;
				k++;
				estado=false;
			}
			else{
				rpta+=grupos[j][k];
				j++;
			}
		}
        else if(!estado){//vuelta
			if(j==0){
				rpta+=grupos[j][k-ciclo];
				j++;
				estado=true;
				k++;
				ciclo++;
			}
			else{
				rpta+=grupos[j][k];
				j--;
			}
        }
		i++;
    }
    return rpta;
}

int main(){
	string m("elcieloesellimite");
    string mc=encripto(m,3);
    cout<<mc<<endl;
    string msn=desencripto(mc,3);
    cout<<msn<<endl;
	return 0;
}

