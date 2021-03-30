#include <iostream>
#include <vector>
using namespace std;

struct Registro 
{
    string nome, endereco;
};

int main()
{
    system("cls");
    cout<< "PONTEIROS COM STRUCTS E ITERATOR"<<endl;

    Registro *p;
    //variavel feita apenas para armazenar endereco

    Registro x = {"Tiago", "Joselina nora"};
    vector<Registro> V;
    vector<Registro>::iterator it;

    for(int i = 0; i < 5; i++)
        V.push_back(x);
        //inserindo 5 vezes o mesmo registro apenas a fim de teste
    
    for(it = V.begin(); it !=V.end(); ++it)
        cout << " "<< it->nome<<endl;
        //utilizando a forma de iterator para percorrer a lista/colecao

    p = &x;
    //p recebendo o endereco de x

    p->nome = "Euler";
    //fazendo p apontar para o campo nome e alterar para euler, alterando assim o conteudo da variavel x

    cout << "X = "<< x.nome << " Referencia ou endereco: "<< &x<<endl;
    cout << "*p = "<< p->nome << " Referencia ou endereco: "<< &p<<endl;


}