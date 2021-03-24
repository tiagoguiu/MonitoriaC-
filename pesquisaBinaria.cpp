#include <iostream>
#include <vector>

using namespace std;

struct Registro
{
    /* data */
    string chave;
    string nome;
};

Registro A = {"chaveA", "Antonio"};
Registro B = {"chaveB", "Beatriz"};
Registro C = {"chaveC", "Carlos"};
Registro D = {"chaveD", "Daniel"};
Registro E = {"chaveE", "Elisa"};

Registro pesquisaBinaria(vector<Registro> V, int e, int d, string chaveBusca)
{
    //DIVIDE A COLEÇÃO EM DIREITA MEIO E ESQUERDA E COMPARA 
    //O VALOR DO MEIO NO INTUITO DE NÃO PESQUISAR O VETOR INTEIRO
    
    int meio = (e+d)/2;//MEDIA ENTRE ESQUERDA E DIREITA

    if(V[meio].chave == chaveBusca)
        return meio;
    if(e >= d)
        return -1;//CONJUNTO DE APENAS UM ELEMENTO LOGO NÃO FOI ENCONTRADO
    else
        if(V[meio].chave < chaveBusca)
            return pesquisaBinaria(V, meio+1, d,chaveBusca);
        else 
            return pesquisaBinaria(V,e,meio-1,chaveBusca);
         
}

int main()
{
    system("cls");

    string chaveBusca = "chaveC";
    Registro resultado;
    vector<Registro> V;

    V.push_back(A);
    V.push_back(B);
    V.push_back(C);
    V.push_back(D);
    V.push_back(E);

    resultado = pesquisaSequencial(V, chaveBusca);
    cout<<"O resultado da pesquisa e:"<<endl<<resultado.nome;
    return 0;
}
