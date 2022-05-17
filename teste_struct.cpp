#include <iostream>
#include <fstream>
using namespace std;

struct Num
{
  int numeros;
};

int main()
{
  ifstream arq;

  int i = 0;
  struct Num inteiros[20];
  arq.open("teste.txt");
  if (arq.is_open())
  {
    while (arq.good())
    {
      arq >> inteiros[i].numeros;
      cout << inteiros[i].numeros << endl;
      i++;
    }
  }
  for (int j = 0; j < i; j++)
  {
    if(inteiros[j].numeros  > 0)
    {
      cout <<"SIMMMMMMMMMMM"<<endl;
    }
  }
  
  
}