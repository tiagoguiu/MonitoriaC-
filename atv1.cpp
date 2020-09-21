#include <iostream>
#include <fstream>
using namespace std;

/*
ofstream nomedavariavel; para escrita
ifstream nomedavariavel; para leitura
nomedavariavel.open("exemplo.txt",parâmetros);

parametros:
ios::in - leitura
ios::out - escrita
ios::binary - formato binario
ios::ate - posiciona ao final do arquivo (inicio do arquivo é padrao)
ios::app - modo de concatenação ao final do arquivo
ios::trunc - se o modo for escrita, apaga o arquivo, se existir, e reinicia o conteudo.

leitura:
nomedavariavel>>variavelareceberdados(le a proxima palavra ou numero até o espaço)
nomedavariavelarquivo.getline(variavelareceberdados)

escrita:
nomedavariavel<<variavelcomdadosparaescrever

posivionamento:
nomedavariavel.seekg(posicao) - posiciona para leitura
nomedavariavel.seekp(posicao) - posiciona para escrita

fechamento:
nomedavariavel.close()
*/

struct dados
{
    /* data */
    string nome;
    string cpf;
    string telefone;
};

void split(string linha, char at, string S[])
{
    int pos = 0, fim, i = 0;
    do
    {
        /* code */
        fim = linha.find(at, pos);
        if( fim == -1) // ultimo campo
            S[i] = linha.substr(pos);
        else  // primeiro ao penultimo campo
            S[i++] = linha.substr(pos, fim - pos);
        pos = fim + 1;
    } while ( fim != -1);
    
}

int carregaDados(dados R[])
{
    int i = 0;
    string linha;
    ifstream arquivo;
    arquivo.open("agenda.csv");
    if(arquivo.is_open())
    {   
        while (getline(arquivo, linha)) 
        //continua enquanto houverem dados a serem lidos pois a função getline retorna retorna bool
        {
            /* code */
            
            cout << linha << endl;
            string S[2];
            split(linha, ',' , S);
            R[i].nome = S[0];
            R[i].cpf = S[1];
            R[i].telefone = S[2];
            i++;
        }
        arquivo.close();
        return i;
        
    }else
    { 
        cout<<"Nao foi possivel abrir o arquivo"<<endl;
        return 0;
    }

}

void salvaDados( dados R[], int quant)
{
    ofstream arquivo;
    arquivo.open("agenda.csv", ios::trunc);
    for (int i = 0; i < quant; i++)
    {
        /* code */
        arquivo << R[i].nome << "," << R[i].cpf << "," << R[i].telefone << endl;
    }
    arquivo.close();
     
}

int main() 
{
    dados R [100];
    int q = carregaDados(R);
    salvaDados(R, q);
    return 0;

}
 