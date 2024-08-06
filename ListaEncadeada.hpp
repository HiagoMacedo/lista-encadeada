#pragma once
#include "No.hpp"
#include <stdexcept>
#include <iostream>


template <typename Tipo>
class ListaEncadeada
{
public:
    ListaEncadeada()
    {
        m_cabeca = nullptr;
        m_tamanho = 0;
    }

    ~ListaEncadeada()
    {
        delete m_cabeca;
    }

    bool isVazia()
    {
        return m_tamanho == 0;
    }

    int tamanho()
    {
        return m_tamanho;
    }

    Tipo posicao(int pos)
    {
        if (pos < 1 || pos > m_tamanho)
        {
            throw std::invalid_argument("Posicao invalida");
        }

        No<Tipo> *temp = m_cabeca;
        for (int i = 1; i < pos; ++i)
        {
            if (temp != nullptr)
            {
                temp = temp->getProximo();
            }
        }
        return temp->getConteudo();
    }

    bool inserir(Tipo dado, int pos)
    {
        if (pos < 1 || pos > (m_tamanho + 1))
        {
            return false;
        }
        if (pos == 1)
        {
            inserirInicio(dado);
        }
        else if (pos == (m_tamanho + 1))
        {
            inserirFim(dado);
        }
        else
        {
            inserirMeio(dado, pos);
        }
        return true;
    }

    Tipo remover(int pos)
    {
        if (isVazia())
        {
            throw std::invalid_argument("A lista esta vazia");
        }

        if (pos == 1)
        {
            return removerInicio();
        }
        else
        {
            return removerMeio(pos);
        }
    }

    void print()
    {
        No<Tipo> *aux = m_cabeca;
        std::cout << "[ "; 
        for (int i = 0; i < m_tamanho; ++i)
        {
            if(aux != nullptr)
            {
                std::cout << aux->getConteudo() << " ";
                aux = aux->getProximo();
            }
        }
        std::cout << "]" << std::endl;
    }

private:
    bool inserirInicio(Tipo dado)
    {
        No<Tipo> *novoNo = new No<Tipo>();
        novoNo->setConteudo(dado);
        novoNo->setProximo(m_cabeca);
        m_cabeca = novoNo;
        m_tamanho++;
        return true;
    }

    bool inserirMeio(Tipo dado, int pos)
    {
        if (pos < 1 || pos > m_tamanho)
        {
            return false;
        }

        No<Tipo> *novoNo = new No<Tipo>;
        No<Tipo> *atual = m_cabeca;
        No<Tipo> *antecessor;

        for (int i = 0; i < pos-1; ++i)
        {
            if (atual != nullptr)
            {
                antecessor = atual;
                atual = atual->getProximo();
            }
        }

        novoNo->setConteudo(dado);
        novoNo->setProximo(atual);
        antecessor->setProximo(novoNo);

        m_tamanho++;
        return true;
    }

    bool inserirFim(Tipo dado)
    {
        No<Tipo> *novoNo = new No<Tipo>;
        No<Tipo> *aux = m_cabeca;
        for (int i = 0; i < m_tamanho-1; ++i)
        {
            if (aux != nullptr)
            {
                aux = aux->getProximo();
            }
        }

        if (aux == nullptr)
        {
            return false;
        }

        novoNo->setConteudo(dado);
        novoNo->setProximo(nullptr);
        aux->setProximo(novoNo);

        m_tamanho++;
        return true;
    }

    Tipo removerInicio()
    {
        No<Tipo> *aux = m_cabeca;
        m_cabeca = m_cabeca->getProximo();
        Tipo dado = aux->getConteudo();
        m_tamanho--;
        delete aux;
        return dado;
    }

    Tipo removerMeio(int pos)
    {
        No<Tipo> *atual = m_cabeca;
        No<Tipo> *antecessor;
        for (int i = 0; i < pos-1; ++i)
        {
            if (atual != nullptr)
            {
                antecessor = atual;
                atual = atual->getProximo();
            }
        }
        if (atual == nullptr)
        {
            throw std::invalid_argument("Pos invalido");
        }
        Tipo dado = atual->getConteudo();
        antecessor->setProximo(atual->getProximo());
        m_tamanho--;
        
        delete atual;
        return dado;
    }
    
private:
    No<Tipo>    *m_cabeca;
    int         m_tamanho;
};

// #include "ListaEncadeada.cpp"