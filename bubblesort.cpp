#include <iostream>
#include <vector>
using namespace std;
void bubblesort(vector<int> &V,int n){
    int i, j, aux;
    for (int i=0;i<n-1;i++){
        for (int j=1;j<n-i;j++){
            if (V[j]<V[j-1]){
                aux= V[j];
                V[j]=V[j-1];
                V[j-1] = aux;
            }
        }
    }
}
int main(){
    int x;  
    vector<int> V;
    for (int i=0;i<10;i++){
        cin >>x;
        V.push_back(x);
    }
    bubblesort(V,10);
    system("cls");
    for (int k=0;k<V.size();k++){
        cout<<V[k]<<endl;
    }
    return 0;
}