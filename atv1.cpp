#include <iostream>
#include <fstream>
using namespace std;

struct  Dados{
	string nome;
	string cpf;
	string telefone;
} ;

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

int carregaDados(Dados R[]){
	int i = 0;
	string linha;
	ifstream arquivo;
	arquivo.open("agenda.csv");
	if (arquivo.is_open()){
		while (getline (arquivo,linha)){
		  cout << linha << '\n';
		  string S[5];
		  split(linha, ';', S);
		  R[i].nome = S[0];
		  R[i].telefone = S[1];
		  R[i].cpf = S[2];
		  i++;
		}
		arquivo.close();
		return i;
	} else {
		cout << "Nao foi possivel abrir o arquivo";
		return 0;
	}
}

void salvaDados(Dados R[], int quant){
	ofstream arquivo;
	arquivo.open("agenda.csv", ios::trunc );
	for(int i = 0; i < quant; i++){
		arquivo << R[i].nome << ";" << R[i].telefone << ";" << R[i].cpf << endl;
	}
	arquivo.close();
}

int main() {
	Dados R[100];
	int q = carregaDados(R);
	salvaDados(R, q);
	return 0;
}

