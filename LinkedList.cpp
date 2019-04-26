/* Linked List
 * Implementação de uma lista ligada não ordenada, em c++
*/

#include<iostream>
#include<cstdlib>

class Node {							//Classe principal para criação dos nós.
	public:
		Node* next;						//Atributos da classe.
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

LinkedList::LinkedList() {				//Construtor.
	this->length = 0;					//Seta o tamanho como zero.
	this->head = NULL;					//Seta o ponteiro para nulo.
}

LinkedList::~LinkedList(){
	free(head);
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

bool LinkedList::find(int data){
	Node *node = new Node;
	if (!head){
		std::cout << "A lista está vazia! \n" << std::endl;		//Mostra mensagem avisando que a lista está vazia.
		return false;										//Pausa o programa.
	}
	node = head;
	for (; node; node = node->next){
		if (node->data == data){
			return true;
		}
	}
	return false;
}

bool LinkedList::remove(int data){								//Implementação do método para remover um conteúdo da lista.
	Node *node = new Node;
	if (!find(data)){
		return false;
	}
	while (head->data == data){
		head = head->next;
	}
	if (!head){
		return false;
	}
	node = head;
	while(node){
		if(node->next){
			if(node->next->data == data){
				Node *node2 = node->next->next;
				free(node->next);
				node->next = node2;
				length--;
			}
		}
		node = node->next;
	}
	return true;
}

bool LinkedList::empty() {										//Implementação do méotodo para verificar se a lista está vazia.
	return (this->head == NULL);								//Retorna true or false se a lista estiver vazia (ou não).
}

void menu (LinkedList *lista) {
	int decision = 0;
	do{
		int value = 0;
		system("CLS");
		std::cout << "Oi, eu sou uma lista!\n\n" << std::endl;
		std::cout << "1 - Printar a lista" << std::endl;
		std::cout << "2 - Adicionar valor a lista" << std::endl;
		std::cout << "3 - Remover valor da lista" << std::endl;
		std::cout << "4 - Procurar valor na lista" << std::endl;
		std::cout << "5 - Verificar o tamanho da lista" << std::endl;
		std::cout << "6 - Sair" << std::endl;
		std::cin >> decision;
		switch (decision){
			case 1:
				system("CLS");
				lista->print();
				system("PAUSE");
			break;
			case 2:
				system("CLS");
				std::cout << "Digite um valor para adicionar a lista:" << std::endl;
				std::cin >> value;
				lista->add(value);
				std::cout << "Valor adicionado!" << std::endl;
				system("PAUSE");
			break;
			case 3:
				system("CLS");
				std::cout << "Digite um valor para remover da lista:" << std::endl;
				std::cin >> value;
				if (lista->remove(value)){
					lista->remove(value);
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
					lista->find(value);
					printf("Valor %d encontrado na lista!!", value);
				}else {
					printf("Valor %d não encontrado na lista!!", value);
				}
				system("PAUSE");
			break;
			case 5:
				system("CLS");
				printf("A lista tem atualmente %d de tamanho!\n", lista->length);
				system("PAUSE");
			break;
			case 6:
				system("CLS");
				printf("Obrigado por utilizar minha lista! =)\n");
				exit(1);
			break;
			default:
				system("CLS");
				printf("Opcao invalida, tente novamente!! \n\n\n");
				system("PAUSE");
		}
	}while(decision != 6);
}

int main (int argc, char const *argv[]) {								//Método main padrão.
	LinkedList* lista = new LinkedList();								//Cria a variável lista do tipo LinkedList.
	menu(lista);														//Chamada para o menu.
	return 0;
}
