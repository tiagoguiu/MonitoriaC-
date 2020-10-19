#include <iostream>
#include <vector>
using namespace std;

void selecao(vector<int> &V)
{
    int menor;
    for(int i = 0; i < V.size(); i++ )
    {
        menor = i;
        for(int j = i+1; j < V.size(); j++)
        {
            if(V[j] < V[menor]){menor = j;}
        }
        swap(V[i], V[menor]);
    }
}

void insercao(vector<int> &V)
{
    int i , j , escolhido;
    for(i = 1; i < V.size(); i++)
    {
        escolhido = V[i];
        for(j = i-1; (j>=0) && (V[j] > escolhido); j--)
        {
            V[j+1] = V[j];
        }
        V[j+1] = escolhido;
    }
}

int main()
{
    int i , x;
    vector<int> V;
    cout << "Digite 10 numeros para serem ordenados" << endl;
    for(i=0;i<10;i++)
    {
        cin>>x;
        V.push_back(x);
    }
    insercao(V);
    cout << "A lista ordenada e:" << endl;
    for(int z = 0; z < V.size(); z++)
    {
        cout << V[z] << endl;
    }
    return 0;
}