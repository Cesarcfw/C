#include <iostream>
#include <string>

class Pilha {
private:
    int indiceTopo; // Topo da Pilha
    int capacidadeMaxima; // Tamanho da Pilha
    std::string* elementos; // Elementos da Pilha (usando string para simplificar)

public:
    // Método que inicializa a Pilha no estado vazia
    Pilha() {
        indiceTopo = -1;
        capacidadeMaxima = 30;
        elementos = new std::string[capacidadeMaxima];
    }

    // Método que verifica se a Pilha está Vazia
    bool estaVazia() {
        return (indiceTopo == -1);
    }

    // Método que verifica se a Pilha está cheia
    bool estaCheia() {
        return (indiceTopo == capacidadeMaxima - 1);
    }

    // Método para inserir um valor na Pilha
    void empilhar(const std::string& valor) {
        if (!estaCheia()) {
            indiceTopo++;
            elementos[indiceTopo] = valor;
        } else {
            std::cout << "Pilha Cheia!!" << std::endl;
        }
    }

    // Método para exibir o conteúdo da Pilha
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

    // Método para retornar o topo da Pilha e removê-lo
    std::string desempilhar() {
        if (!estaVazia())
            return elementos[indiceTopo--];
        else
            return "";
    }

    // Método que retorna o topo da pilha sem removê-lo
    std::string topo() {
        if (!estaVazia())
            return elementos[indiceTopo];
        else
            return "";
    }

    // Destrutor para liberar a memória alocada
    ~Pilha() {
        delete[] elementos;
    }
};

int main() {
    Pilha pilha;

    // Testando a inserção de elementos na pilha
    pilha.empilhar("Elemento 1");
    pilha.empilhar("Elemento 2");
    pilha.empilhar("Elemento 3");

    // Exibindo o conteúdo da pilha
    pilha.imprimir();

    // Removendo o topo da pilha
    std::cout << "Elemento removido: " << pilha.desempilhar() << std::endl;

    // Exibindo o topo da pilha sem removê-lo
    std::cout << "Topo da pilha: " << pilha.topo() << std::endl;

    // Exibindo o conteúdo da pilha novamente
    pilha.imprimir();

    return 0;
}

