#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Biblioteca
{
    /* data */
    string titulo;
    string autor;
    string quantidade;
};


void split(string linha, char at, string S[]){
	int pos = 0, fim, i=0;
	do {
		fim=linha.find(at, pos);
		if (fim == -1) // Ultimo campo
			S[i] = linha.substr(pos);
		else // Primeiro ao penúltimo campo
			S[i++] = linha.substr(pos,  fim - pos);
		pos = fim+1;
	} while (fim != -1);
}


void carrega(vector<Biblioteca> &R){ //R PASSADO POR REFERENCIA PARA SER ALTERADO DENTRO DESTE ESCOPO
	string linha;
	ifstream arquivo;
    Biblioteca T;
	arquivo.open("biblioteca.csv");
	if (arquivo.is_open()){
		while (getline (arquivo,linha)){
		  cout << linha << '\n';
		  string S[100];
		  split(linha, ';', S);
		  T.titulo = S[0];
		  T.autor = S[1];
		  T.quantidade = S[2];
		  R.push_back(T);
		}
		arquivo.close();
		
	} else {
		cout << "Nao foi possivel abrir o arquivo";
		
	}
}

void salva(vector<Biblioteca> R){
	ofstream arquivo;
	arquivo.open("biblioteca.csv", ios::trunc );
	for(int i = 0; i <R.size(); i++){
		arquivo << R[i].titulo << ";" << R[i].autor << ";" << R[i].quantidade << endl;
	}
	arquivo.close();
}

void insere(vector<Biblioteca> &R)
{
    Biblioteca T;
    ofstream arquivo;
    arquivo.open("biblioteca.csv", ios::app);
    cout << "Digite o titulo: " << endl;
    cin >> T.titulo;
    cout << "Digite o : autor: " << endl;
    cin >> T.autor;
    cout << "Digite a quantidade: " << endl;
    cin >> T.quantidade;
    arquivo << T.titulo << ";" << T.autor << ";" << T.quantidade << endl;
    R.push_back(T);
    arquivo.close();
}

void remove(vector<Biblioteca> &R)
{
    for (int i = 0; i < R.size(); i++)
    {
        /* code */
        cout << "imprimindo lista para ver se o primeiro elemento foi excluido" << endl << R[i].autor << endl << R[i].titulo << endl << R[i].quantidade << endl;
    }
    
    vector<Biblioteca>::iterator it;
    it=R.begin();
    R.erase(it+1); // teria que passar o iterator
    //cout << "O primeiro da lista foi apagado" << endl;

    for (int i = 0; i < R.size(); i++)
    {
        /* code */
        cout << "Confira se foi excluido" << endl << R[i].autor << endl << R[i].titulo << endl << R[i].quantidade << endl;
    }
}


int main()
{
    vector<Biblioteca> R;
    carrega(R);
    salva(R);
    int op =0;
    while (op == 0)
    {
        /* code */
        insere(R);
        cout << "Para inserir mais tecle 0, para sair tecle 1, para remover tecle 2: " << endl;
        cin>>op;
        if (op == 2)
        {
            /* code */
            remove(R);
            carrega(R); // a remoção não funcionou testar de outra forma
        }
        
    }
    
        
    
}