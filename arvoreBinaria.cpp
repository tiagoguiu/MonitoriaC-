//NÓ RAIZ
//SE MENOR ENTRA PRA ESQUERDA 
//SE MAIOR ENTRA PARA DIREITA

#include <iostream>

using namespace std;

struct Registro
{
    /* data */
    string chave;
    string nome;

    Registro *dir, *esq; //ponteiros para dividir a arvore e apontar para os elementos
};

Registro A = {"chaveA", "Antonio", NULL,NULL};
Registro B = {"chaveB", "Beatriz",NULL,NULL};
Registro C = {"chaveC", "Carlos",NULL,NULL};
Registro D = {"chaveD", "Daniel",NULL,NULL};
Registro E = {"chaveE", "Elisa",NULL,NULL};
Registro nulo = {"Sem correspondencia", "Sem correspondencia",NULL,NULL};

void inserirArvore(Registro &no, Registro &novo_no)
{
    //se for menor, entao insere a esquerda
    if(novo_no.chave < no.chave)
    {
        //verifica se a esquerda é nulo
        if(no.esq == NULL)
        {
            no.esq = &novo_no; // seta o novo_no á esquerda
        } else
        {
            /* code */
            //senão, continua percorrendo recursivamente
            inserirArvore(*no.esq, novo_no);
        }
        
    } else if(novo_no.chave > no.chave)//se for maior, entao insere
    {
        if(no.dir == NULL)//verifica se a direita é nulo ou seja nao tem ninguem
        {
            no.dir = &novo_no; // seta o novono á direita
        }else
        {
            /* code */
            //senão continua percorrendo recursivamente
            inserirArvore(*no.dir, novo_no);
        }
        /*
        se for igual não vai inserir. Não pode existir 2 chaves iguais 
        */
    }
}

Registro pesquisaArvoreBinaria(Registro no, string chaveBusca)
{
    if(no.chave == chaveBusca)
    {
        return no;
    } else if(chaveBusca < no.chave)
        {
            if(no.esq)
                return pesquisaArvoreBinaria(*no.esq,chaveBusca);
            else
                return nulo;
        }else
        {
            /* code */
            if(no.dir)
                return pesquisaArvoreBinaria(*no.dir, chaveBusca);
            else
                return nulo;
        }
        
}

int main()
{
    system("cls");

    string chaveBusca = "chaveB";

    //O C É A RAIZ DA ARVORE NESTE CASO
    //PODERIA TER CRIADO UM REGISTRO ARVORE = C PARA FICAR MAIS INTUITIVO
    inserirArvore(C,A);
    inserirArvore(C,B);
    inserirArvore(C,D);
    inserirArvore(C,E);

    Registro resultado = pesquisaArvoreBinaria(C,chaveBusca);
    cout<<"O resultado da pesquisa e:"<<endl<<resultado.nome;
    
    return 0;
}
