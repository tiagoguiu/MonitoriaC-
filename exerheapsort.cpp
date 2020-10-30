#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &V, int tam, int i)
{
    int menor = i;
    int esquerda = 2*i + 1;
    int direita = 2*i +2;

    if(esquerda < tam && V[esquerda] < V[menor])
        menor = esquerda;
    
    if(direita < tam && V[direita] < V[menor])
        menor = direita;
    
    if(menor != i)
    {
        swap(V[i],V[menor]);
        heapify(V,tam,menor);
    }
}

void heapSort(vector<int> &V)
{
    for(int i = V.size() / 2-1; i >= 0; i--)
    {
        heapify(V, V.size() ,i);
    }
        
    
    for(int i = V.size() -1; i >= 0; i--)
    {
        swap(V[0],V[i]);
        heapify(V, i, 0);
    }
}

int main()
{
    int i, x;
    vector<int> V;
    cout<<"Digite 10 numeros:"<<endl;
    for(i = 0; i < 10; i++)
    {
        cin>>x;
        V.push_back(x);
    }
    heapSort(V);
    cout<<"A lista ordenada e:"<<endl;
    for(int i = 0; i < V.size(); i++)
    {
        cout<<V[i]<<endl;
    }
    return 0; 
}