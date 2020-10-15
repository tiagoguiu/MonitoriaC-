#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct ItemCompra{
    string nome;
    int quantidade;
    string marca;
    float preco;
};

void carregaRegistros(vector<ItemCompra> &X){
    ifstream arquivo;
    ItemCompra Y;
    arquivo.open("arquivos//compras.txt");
    if (arquivo.is_open()){
        while (arquivo.good()){
           arquivo >> Y.nome >> Y.quantidade >> Y.marca >> Y.preco;
            X.push_back(Y);
        }
    arquivo.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void salvaRegistros(vector<ItemCompra> &X){
    ofstream arquivo;
    ItemCompra Y;
    arquivo.open("arquivos//compras.txt", ios::app);
    cout << "Digite o nome do alimento:" << endl;
    cin >> Y.nome;
    cout << "Digite a quantidade:" << endl;
    cin >> Y.quantidade;
    cout << "Digite a marca:" << endl;
    cin >> Y.marca;
    cout << "Digite o preco:" << endl;
    cin >> Y.preco;
    X.push_back(Y);
    arquivo << Y.nome << " " << Y.quantidade << " " << Y.marca << " " << Y.preco << endl;
    arquivo.close();
    cout << "Os dados foram salvos no arquivo com sucesso!" << endl;
}

int main() {
    int w=4;
    vector<ItemCompra> X;
    carregaRegistros(X);
    int excluir;

    while (w!=0) {
        cout << "Digite 1 para imprimir sua lista na tela, 2 para adicionar um item na lista, 3 para excluir um item e 0 para sair." << endl;
        cin >> w;

        if (w==1) {
            for(int i = 0; i < X.size(); i++){
                cout << X[i].nome << " " << X[i].quantidade << " " << X[i].marca << " " << X[i].preco << endl;
            }
        }
        if (w==2) {
            salvaRegistros(X);
        }
        if (w==3) {
            cout << "Digite a posicao do item a ser excluido: " << endl;
            cin >> excluir;
            

            for (vector<ItemCompra>::iterator it; it != X.end(); it++) {
                if (excluir == 1) {
                    X.erase(it);
                }
                else
                {
                    /* code */
                    X.erase(it + excluir);
                }
                
            }
        }
    }

    return 0;
}