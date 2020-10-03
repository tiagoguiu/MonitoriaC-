#include <iostream>
#include <queue>
using namespace std;


void inserir(queue<string> &nomes){
    string nome;
    cout<<"Digite o nome a ser inserido" << endl;
    cin >>nome;
    nomes.push(nome);
}

void remover(queue<string> &nomes){

        cout<<"Removendo o primeiro" << endl;
        string nome = nomes.front();
        cout<<"Removido: " << nome << endl;
        nomes.pop();
    
}

int main(){
    
    queue<string> nomes;
    int op = 5;
    while (op!= 0)
    {
        /* code */
        cout<<"-Digite i para ler e inserir" << endl << "-Digite p para remover o primeiro" << endl << "-Digite x para encerrar o programa" << endl;
        char op2;
        cin>>op2;

        if(op2 == 'i')
            op =1;
        if(op2 == 'p')
            op = 2;
        if(op2 == 'x')
            op = 0;

        switch (op)
        {
        case 1:
            /* code */
            inserir(nomes);
            break;
        case 2:
            remover(nomes);
            break;
        case 3:
            return 0;
        
        }
    }
}