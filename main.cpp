#include <iostream>
#include <string>
#include "ListaEncadeada.hpp"

int main()
{
    ListaEncadeada<int> lista;
    std::cout << "A lista esta vazia? " << lista.isVazia() << std::endl;
    std::cout << "Tamanho da lista: " << lista.tamanho() << std::endl;
    lista.print();

    lista.inserir(80, 1);
    lista.print();

    lista.inserir(10, 1);
    lista.print();

    lista.inserir(30, 2);
    lista.print();

    lista.inserir(20, 3);
    lista.print();

    lista.inserir(50, 5);
    lista.print();
    std::cout << "Tamanho da lista: " << lista.tamanho() << std::endl;

    std::cout << "Removido pos(1): " << lista.remover(1) << std::endl;
    lista.print();
    
    std::cout << "Removido pos(3): " << lista.remover(3) << std::endl;
    lista.print();

    std::cout << "Elemento da 3 posicao da lista: " << lista.posicao(3) << std::endl;
    std::cout << "A lista esta vazia? " << lista.isVazia() << std::endl;
    std::cout << "Tamanho da lista: " << lista.tamanho() << std::endl;
    
    return 0;
}