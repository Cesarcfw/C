#include <iostream>
#include <string>

class Pilha {
private:
    int indiceTopo; // Topo da Pilha
    int capacidadeMaxima; // Tamanho da Pilha
    std::string* elementos; // Elementos da Pilha (usando string para simplificar)

public:
    // M�todo que inicializa a Pilha no estado vazia
    Pilha() {
        indiceTopo = -1;
        capacidadeMaxima = 30;
        elementos = new std::string[capacidadeMaxima];
    }

    // M�todo que verifica se a Pilha est� Vazia
    bool estaVazia() {
        return (indiceTopo == -1);
    }

    // M�todo que verifica se a Pilha est� cheia
    bool estaCheia() {
        return (indiceTopo == capacidadeMaxima - 1);
    }

    // M�todo para inserir um valor na Pilha
    void empilhar(const std::string& valor) {
        if (!estaCheia()) {
            indiceTopo++;
            elementos[indiceTopo] = valor;
        } else {
            std::cout << "Pilha Cheia!!" << std::endl;
        }
    }

    // M�todo para exibir o conte�do da Pilha
    void imprimir() {
        if (!estaVazia()) {
            std::string mensagem = "";
            for (int i = 0; i <= indiceTopo; i++) {
                mensagem += elementos[i] + ", ";
            }
            std::cout << "P: [ " << mensagem << " ]" << std::endl;
        } else {
            std::cout << "Pilha Vazia!!" << std::endl;
        }
    }

    // M�todo para retornar o topo da Pilha e remov�-lo
    std::string desempilhar() {
        if (!estaVazia())
            return elementos[indiceTopo--];
        else
            return "";
    }

    // M�todo que retorna o topo da pilha sem remov�-lo
    std::string topo() {
        if (!estaVazia())
            return elementos[indiceTopo];
        else
            return "";
    }

    // Destrutor para liberar a mem�ria alocada
    ~Pilha() {
        delete[] elementos;
    }
};

int main() {
    Pilha pilha;

    // Testando a inser��o de elementos na pilha
    pilha.empilhar("Elemento 1");
    pilha.empilhar("Elemento 2");
    pilha.empilhar("Elemento 3");

    // Exibindo o conte�do da pilha
    pilha.imprimir();

    // Removendo o topo da pilha
    std::cout << "Elemento removido: " << pilha.desempilhar() << std::endl;

    // Exibindo o topo da pilha sem remov�-lo
    std::cout << "Topo da pilha: " << pilha.topo() << std::endl;

    // Exibindo o conte�do da pilha novamente
    pilha.imprimir();

    return 0;
}

