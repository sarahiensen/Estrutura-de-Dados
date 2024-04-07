#include <iostream>

using namespace std;

const int TAM = 10; //tamanho max da lista é 10
int lista[TAM]; //Declara uma lista de inteiros com tamanho TAM
int tamanho= 0; //numero de elementos na lista

void insereLista(int valor,int posicao);//insere valor em uma posição e verifica se ela é válida
void recuperaLista(int posicao); //mostra o valor inserido em uma determinada posição
void removeLista(int posicao);//remove um elemento de uma posição
void buscaLista(int valor);
void buscaRepetidosLista(int valor);
void imprime(); //imprime o conteúdo da lista além de verificar se ela está vazia

int main()
{
    cout << "Criando uma lista com os valores 0, 12, 2, 50, 4, 2 . . . \n\n";
    insereLista(0,0);
    insereLista(12,1);
    insereLista(2,2);
    insereLista(50,3);
    insereLista(4,4);
    insereLista(2,5);

    cout << "buscando valor 2 . . .\n" << endl;
    buscaLista(2);
    cout << "buscando valor 20 . . .\n" << endl;
    buscaLista(20);

    cout << "Verificando se o 2 eh repetido . . .\n" << endl;
    buscaRepetidosLista(2);
    cout << "Verificando se o 15 eh repetido . . .\n" << endl;
    buscaRepetidosLista(15);

    cout << "Verificando qual valor esta na posicao 3\n" << endl;
    recuperaLista(3);

    imprime();

    cout << "\nRemovendo elemento da posicao 2. . . \n" << endl;
    removeLista(2);

    imprime();

    return 0;
}

void insereLista(int valor, int posicao)
{
    if(tamanho == TAM)
    {
        cout << "Lista cheia" << endl;
        return;
    }
    if(posicao < 0 || posicao > tamanho)
    {
        cout << "Posicao invalida" << endl;
        return;
    }
    for(int i = tamanho-1; i > posicao; i--)
    {
        lista[i] = lista[i-1];
    }

    lista[posicao] = valor;
    tamanho++;
}

void buscaLista(int valor)
{
    if(tamanho == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    for(int i=0; i<tamanho; i++)
    {
        if(valor==lista[i])
        {
            cout << "O valor " << valor << " esta na posicao " << i << "\n" << endl;
            return;
        }
    }
    cout << "Valor nao encontrado :(\n" << endl;
}

void buscaRepetidosLista(int valor)
{
    int encontrado = 0;
    if(tamanho == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    for(int i=0; i<tamanho; i++)
    {
        if(valor == lista[i])
        {
            encontrado++;
            cout << "O valor esta na posicao " << i << "\n"<< endl;
        }
    }
    if(encontrado == 0)
    {
        cout << "O valor nao esta na lista\n" << endl;
    }
    else
    {
        cout << "O valor foi encontrado " << encontrado << " vezes\n" << endl;
    }
}

void recuperaLista(int posicao)
{
    if(tamanho == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    if(posicao < 0 || posicao >= tamanho)
    {
        cout << "Posicao invalida :( \n" << endl;
        return;
    }
    cout << "O valor que esta na posicao " << posicao << " eh " << lista[posicao] << "\n" << endl;
}

void imprime()
{
    if(tamanho == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    cout << "A sua lista eh:\n\n";
    for(int i=0; i<tamanho; i++)
    {
        cout << lista[i] << " ";
    }
    cout << "\n";
}

void removeLista(int posicao)
{
    if(tamanho == 0)
    {
        cout << "Lista vazia" << endl;
    }
    if(posicao < 0 || posicao >= tamanho)
    {
        cout << "Posicao invalida" << endl;
        return;
    }
    for(int i=posicao; i<tamanho-1; i++)
    {
        lista[i] = lista[i+1];
    }
    tamanho--;
    cout << "Elemento removido com sucesso.\n" << endl;
}

