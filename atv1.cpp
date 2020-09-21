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
    int cpf;
    int telefone;
};

int carregaDados(dados R[])
{
    int i =0;
    string linha;
    ifstream arquivo;
    
}

int main() 
{
    dados R [100];

}
 