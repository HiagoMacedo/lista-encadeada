#pragma once

template <typename Tipo>
class No
{
private:
    Tipo   m_conteudo;
    No  *m_proximo;
public:
    No()
    {
        m_proximo = nullptr;
    }

    No(Tipo conteudo) : No()
    {
        m_conteudo = conteudo;
    }

    ~No() = default;

    void setConteudo(Tipo conteudo)
    {
        m_conteudo = conteudo;
    }

    void setProximo(No *proximo)
    {
        m_proximo = proximo;
    }

    Tipo getConteudo()
    {
        return m_conteudo;
    }

    No* getProximo()
    {
        return m_proximo;
    }
};
