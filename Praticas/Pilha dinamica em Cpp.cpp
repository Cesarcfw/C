#include <iostream>
#include <string>

class No {
public:
    std::string valor;
    No* proximo;

    No(const std::string& dado) : valor(dado), proximo(NULL) {}
};

class PilhaDinamica {
private:
    No* topoPilha;

public:
    PilhaDinamica() : topoPilha(NULL) {}

    bool estaVazia() {
        return topoPilha == NULL;
    }

    void empilhar(const std::string& valor) {
        No* novoNo = new No(valor);
        novoNo->proximo = topoPilha;
        topoPilha = novoNo;
    }

    std::string topo() {
        if (!estaVazia())
            return topoPilha->valor;
        else
            return "";
    }

    std::string desempilhar() {
        if (!estaVazia()) {
            std::string valorTopo = topoPilha->valor;
            No* temp = topoPilha;
            topoPilha = topoPilha->proximo;
            delete temp;
            return valorTopo;
        } else {
            return "";
        }
    }

    void imprimir() {
        if (!estaVazia()) {
            std::string conteudo;
            No* aux = topoPilha;
            while (aux != NULL) {
                conteudo = ", " + aux->valor + conteudo;
                aux = aux->proximo;
            }
            std::cout << "P: [ " << conteudo << " ]" << std::endl;
        } else {
            std::cout << "Pilha Vazia!" << std::endl;
        }
    }
};

int main() {
    PilhaDinamica pilha;

    pilha.empilhar("Elemento 1");
    pilha.empilhar("Elemento 2");
    pilha.empilhar("Elemento 3");

    pilha.imprimir();

    std::cout << "Elemento removido: " << pilha.desempilhar() << std::endl;

    std::cout << "Topo da pilha: " << pilha.topo() << std::endl;

    pilha.imprimir();

    return 0;
}

