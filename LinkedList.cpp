/* Linked List
 * Implementação de uma lista ligada não ordenada, em c++
*/

#include<iostream>
#include<cstdlib>

class Node {							//Classe principal para criação dos nós.
	public:
		Node* next;						//Atributos dos nós.
		int data;
};

using namespace std;

class LinkedList {
	public:
		int length;						//Variavel para armazenar o tamanho da lista.
		Node *head;						//Ponteiro para o ultimo elemento da lista.

		LinkedList();					//Construtor padrão
		~LinkedList();					//Deconstrutor padrão

		
		bool find(int data);			//Método para procurar um elemento na lista.
		void add(int data);				//Método para adicionar um dado na lista.
		bool remove(int data);			//Método para remover um dado da lista.
		void print();					//Método para printar todo o conteúdo da lista.
		bool empty();					//Método para verificar se a lista está vazia.
};

LinkedList::LinkedList() {				//Construtor da lista.
	this->length = 0;					//Seta o tamanho como zero.
	this->head = NULL;					//Seta o ponteiro para nulo.
}

LinkedList::~LinkedList(){				//Desconstrutor da Lista.
	free(head);							//Limpa o head da memória.
	std::cout << "Lista \"deletada\"";	//Apenas mostra na tela que a lista foi "Deletada" (Desconstruida).
}

void LinkedList::print(){									//Implementação do método print.
	Node* head = this->head;								//Seta o ponteiro do head.
	int i=1;												//Cria a variavel i para fazer a contagem de quantos itens existe dentro da lista.
	while(head){											//Enquanto houver um dado, continua executando seu escopo.
		std::cout << i << ": " << head->data << std::endl;	//Printa a posição atual da lista e pega o conteudo do head.
		head = head -> next;								//Atualiza o head.
		i++;												//Incrementa a variável i.
	}
}

void LinkedList::add(int data){			//Implementação do método de adicionar conteudo na lista.
	Node* node = new Node();			//Cria uma variável do tipo node.
	node->data = data;					//O nó recebe o dado.
	node->next = this->head;			//Seta o proximo nó para null.
	this->head = node;					//Seta o head para um novo nó.
	this->length++;						//Faz a contagem do tamanho da lista.
}

bool LinkedList::find(int data){							//Implementação do método find.
	Node *node = new Node;									//Criação de um ponteiro para um node.
	if (!head){												//Verifica se o HEAD está vazio.
		std::cout << "A lista está vazia! \n" << std::endl;	//Mostra mensagem avisando que a lista está vazia.
		return false;										//Retorna false.
	}
	node = head;											//Atribui o HEAD para o Node.
	for (; node; node = node->next){						//Percorre todos os nós.
		if (node->data == data){							//Verifica se o nó atual tem o mesmo atributo que foi passado.
			return true;									//Se a verificação for verdadeira, retorna true.
		}
	}
	return false;											//Se a verificação for falsa, retorna false.
}

bool LinkedList::remove(int data){							//Implementação do método para remover um conteúdo da lista.
	Node *node = new Node;									//Criação de um ponteiro para um node.
	if (!find(data)){										//Verifica se a lista está vazia.
		return false;										//Se tiver vazia, retorna false.
	}
	while (head->data == data){								//Atuali
		head = head->next;
	}
	if (!head){												//Verifica se o head não é nulo.
		return false;										//Retorna false se for nulo.
	}
	node = head;											//O nó recebe o head atualizado.
	while(node){											//Enquanto o node não for null, roda o loop.
		if(node->next){										//Se o próximo node não for null
			if(node->next->data == data){					//Se o proximo node tiver um atributo igual ao parametro passado
				Node *node2 = node->next->next;				//Cria-se um node temporário para guardar a referencia do próximo node que não será removido.
				free(node->next);							//Limpa de memória o proximo nó
				node->next = node2;							//Linka o segundo node com o próximo nó do node atual.
				length--;									//Decrementa o tamanho atual da lista.
			}
		}
		node = node->next;									//Atualiza o node atual.
	}
	return true;											//Retorna true.
}

bool LinkedList::empty() {									//Implementação do método empty para verificar se a lista está vazia.
	return (this->head == NULL);							//Retorna true or false se a lista estiver vazia.
}

void menu (LinkedList *lista) {											//Criação da função menu.
	int decision = 0;
	do{
		int value = 0;
		system("CLS");
		std::cout << "Oi, eu sou uma lista!\n\n" << std::endl;			//Printa as opções disponiveis para o usuário.
		std::cout << "1 - Printar a lista" << std::endl;
		std::cout << "2 - Adicionar valor a lista" << std::endl;
		std::cout << "3 - Remover valor da lista" << std::endl;
		std::cout << "4 - Procurar valor na lista" << std::endl;
		std::cout << "5 - Verificar o tamanho da lista" << std::endl;
		std::cout << "6 - Sair" << std::endl;
		std::cin >> decision;											//Guarda a decisão do usuário
		switch (decision){
			case 1:
				system("CLS");											//Limpa a tela (windows).
				lista->print();											//Chamada para o método print da lista.
				system("PAUSE");										//Pausa o programa (windows).
			break;
			case 2:
				system("CLS");
				std::cout << "Digite um valor para adicionar a lista:" << std::endl;
				std::cin >> value;
				lista->add(value);														//Chamada para o método add da lista.
				std::cout << "Valor adicionado!" << std::endl;
				system("PAUSE");
			break;
			case 3:
				system("CLS");
				std::cout << "Digite um valor para remover da lista:" << std::endl;
				std::cin >> value;
				if (lista->remove(value)){
					lista->remove(value);												//Chamada para o método remove da lista.
					std::cout << "Valor removido!!" << std::endl;
				}else{
					std::cout << "Valor não encontrado!!" << std::endl;
				}
				system("PAUSE");
			break;
			case 4:
				system("CLS");
				std::cout << "Digite um valor para procurar na lista:" << std::endl;
				std::cin >> value;
				if (lista->find(value)){
					lista->find(value);													//Chamada para o método find da lista.
					std::cout << "Valor " << value << " encontrado na lista!!" << std::endl;
				}else {
					std::cout << "Valor " << value << " nao encontrado na lista!!" << std::endl;
				}
				system("PAUSE");
			break;
			case 5:
				system("CLS");
				std::cout << "A lista tem atualmente " << lista->length << " de tamanho!" << std::endl;	//Printa o tamanho atual da lista.
				system("PAUSE");
			break;
			case 6:
				system("CLS");
				std::cout << "Obrigado por utilizar minha lista!! =)" << std::endl;
				exit(1);
			break;
			default:
				system("CLS");
				std::cout << "Opcao invalida, tente novamente!! \n\n" << std::endl;
				system("PAUSE");
		}
	}while(decision != 6);
}

int main (int argc, char const *argv[]) {								//Método main padrão.
	LinkedList* lista = new LinkedList();								//Cria a variável lista do tipo LinkedList.
	menu(lista);														//Chamada para o menu.
	return 0;
}
