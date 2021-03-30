#include <iostream>
using namespace std;

int main()
{
    system("cls");

    cout<< "PONTEIROS"<<endl;
    
    int *p;
    int a = 5;
    cout<<"a = "<<a<< " Referencia ou endereco: "<<&a<<endl;
    //mostra o que esta contido em a e seu endereco na memoria virtual
    p = &a;

    cout<< "p = "<< p << " Referencia ou endereco: "<< &p<<endl;
    /*p esta armazenando o endereco de A porem p tem um endereco diferente
    pois ocupa um local diferente na memoria*/

    cout<< "*p = "<< *p << " Referencia ou endereco: "<< &p<<endl;
    /*Agora *p esta apontando para o valor contido em a ou seja 5*/

    int *z;
    int b[4] = {6,8,2,3};

    cout<< "b = "<< b[0] << " Referencia ou endereco: "<< &b<<endl;
    //valor de b na posicao 0 e seu endereco
    
    z = b;
    //aqui z esta recebendo o endereco de b 
    
    cout<< "*z = "<< *z << " Referencia ou endereco: "<< &z<<endl;
    //fazendo z apontar para b, mostra a primeira posicao do vetor b e o endereco de z \\ ao remover * de z, é exibido o endereco de b por z=b

    for (int i = 0; i < 4; i++)
        cout<< "*z = "<< *(z+i) << " Referencia ou endereco: "<< &z<<endl;
    //E possivel tambem incrementar o ponteiro para faze-lo percorrer o vetor

}