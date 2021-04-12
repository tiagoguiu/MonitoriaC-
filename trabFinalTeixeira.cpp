#include <iostream>
#include <vector>
using namespace std;


struct Cliente
{
    /* data */
    int cpf;
    string nome;
    struct Projeto *projeto;
};
struct Projeto
{
    /* data */
    string dataIn;
    string dataFim;
    string nome;f
};
void inserir(vector<Cliente>v)
{
    for(int i = 0; i<v.size();i++)
    {
        cout<< "Digite seu nome" << endl;
        cin >> v[i].projeto->nome;
//EXEMPLO FEITO PARA ALUNO QUE DESEJA LINKAR AS STRUCTS PARA ACESSAR OS CAMPOS DE UMA A PARTIR DE OUTRA
    }  
}

int main()
{
    /* code */

    vector<Cliente> v;
    return 0;
}
