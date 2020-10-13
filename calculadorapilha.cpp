#include <iostream>
#include <stack>
using namespace std;

/* CALCULADORA POLONESA REVERSA POSFIXADA*/

int fatorial(int n) 
{
    int i, fatn = 1;
    for(i=1; i<=n;i++)
        fatn = fatn * i;
    return fatn;

}

int main()
{
    stack<int> operandos;
    string lido;
    do
    {
        /* code */
        cin >> lido;
        if(lido == "FIM")
            break;
        else if (lido == "+")
        {
            int op1 = operandos.top();
            operandos.pop();
            int op2 = operandos.top();
            operandos.pop();
            operandos.push(op1 + op2);
        } else if (lido == "-")
        {
            int op1 = operandos.top();
            operandos.pop();
            int op2 = operandos.top();
            operandos.pop();
            operandos.push(op1 - op2);

        } else if ( lido == "/")
        {
            int op1 = operandos.top();
            operandos.pop();
            int op2 = operandos.top();
            operandos.pop();
            operandos.push(op1 / op2);

        }else if (lido == "!")
        {
            int op1 = operandos.top();
            operandos.pop();
            //fatorial
            int op2 = fatorial(op1);
            operandos.push(op2);

        }else
        {
            /* code */
            operandos.push(atoi(lido.c_str()));
        }
        
    } while (lido != "FIM");
    
    cout << operandos.top();
    return 0;
}