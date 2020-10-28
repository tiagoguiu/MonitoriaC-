#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &V, int l, int m, int r)
{
    int i , j , k;
    int n1 = m - l + 1;
    int n2 = r - m; 

    //criando lista temporaria
    vector<int> L,R;
    
    //copiando dados para os vetores temporarios

    for(i = 0; i < n1; i++)
        L.push_back(V[l + i]);
    for(j = 0; j < n2; j++)
        R.push_back(V[m + 1 + j]);

    //Mergiando os vetores temporarios
    i = 0;//indice inicial do primeira lista
    j = 0;//indice inicial da segunda lista
    k = l;//indice inicial da lista mergeada

    while(i < n1 || j < n2)
    {
        if(j >= n2 || (i < n1 && L[i] <= R[j]))
            V[k++] = L[i++];
        else
            V[k++] = R[j++];
    }
}

void mergeSort(vector<int> &V, int l, int r)
{
    if(l < r)
        {   int m = l + (r-l)/2;
            mergeSort(V, l, m);
            mergeSort(V, m+1, r);
            merge(V,l,m,r);
        }
}

int main(){
    int i , x;
    vector<int> V;
    cout<<"Digite 10 numeros"<<endl;
    for(i=0; i<10; i++)
    {
        cin>>x;
        V.push_back(x);
    }
    mergeSort(V,0,9);
    cout<<"A lista ordenada:"<<endl;
    for(int i = 0; i < V.size(); i++)
        cout<<V[i]<<endl;
    return 0;
}