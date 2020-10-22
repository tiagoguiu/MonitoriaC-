#include <iostream>
#include <vector>
using namespace std;

int particao (vector<int> &V, int inicio, int fim)
{
    int meio = (inicio + fim)/2;
    //procura a mediana entre inicio meio e fim
    int a = V[inicio];
    int b = V[meio];
    int c = V[fim];
    int medianaIndice;
    //indice da mediana
    if(a < b){
        //sequencia de if else para verificar qual é a mediana
        if(b < c){
            //a < b && b < c
            medianaIndice = meio;
        }else{
            /* code */
            if(a < c){
                //a < c && c <= b
                medianaIndice = fim;
            }else{
                /* code */
                //c <= a && a < b
                medianaIndice = inicio;
            }
            
        }
        
    }else{
        if(c < b){
            //c < b && a < b
            medianaIndice = meio;
        }else{
            if(c < a){
                // b < = c && c < a
                medianaIndice = fim;
            }else{
                //b < a && a < = c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o quicksort de cormen
    swap(V[medianaIndice],V[fim]);

    // Algoritimo de partição de cormen
    //o pivo é o elemento final
    int pivo = V[fim];

    int i = inicio -1;
    /* Este laço irá varrer os vetores da esquerda para direita procurando os elemento
    que são menores ou iguais ao pivo
    esses elementos sao colocados na particao esquerda */
    
    for (int j = inicio; j <= fim-1; j++)
    {
        /* code */
        if(V[j] <= pivo){
            i = i+1;
            swap(V[i],V[j]);
        }
    }
    swap(V[i+1],V[fim]);//coloca o pivo na posição de ordenação
    return (i+1);//retorna a prosição do pivo
    
}

void quickSort(vector<int> &V, int inicio, int fim)
{
    //com mediana de 3
    if(inicio < fim)
    {
        //quando inicio = fim a particao e unitaria 
        int corte  = particao(V,inicio, fim); //realiza a partição
        quickSort(V, inicio , corte-1); //ordena a partição esquerda
        quickSort(V, corte+1 ,fim); //ordena a partição direita
    }
}
int main()
{
    int i,x;
    vector<int> V;
    cout<< "Digite 10 numeros para serem ordenados" <<endl;
    for(i= 0; i<10; i++)
    {
        cin >>x;
        V.push_back(x);
    }
    quickSort(V,0,9);
    cout << "A lista ordenada" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << V[i] << endl;
    }
    return 0;
}