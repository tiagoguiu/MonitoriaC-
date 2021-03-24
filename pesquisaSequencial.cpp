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

Registro pesquisaSequencial(vector<Registro> V, string chaveBusca)
{
    for(int i=0; i<V.size();i++)
        if (V[i].chave == chaveBusca)
        {
            /* code */
            return V[i];
        }
            /* code */
            cout<<"Nao foi possivel achar o registro";
         
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
