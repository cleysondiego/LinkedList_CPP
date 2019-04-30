/* Linked List
 * Implementa��o de uma lista ligada n�o ordenada, em c++
*/

#include<iostream>
#include<cstdlib>

class Node {							//Classe principal para cria��o dos n�s.
	public:
		Node* next;						//Atributos dos n�s.
		int data;
};

using namespace std;

class LinkedList {
	public:
		int length;						//Variavel para armazenar o tamanho da lista.
		Node *head;						//Ponteiro para o ultimo elemento da lista.

		LinkedList();					//Construtor padr�o
		~LinkedList();					//Destrutor padr�o

		
		bool find(int data);					//M�todo para procurar um elemento na lista.
		void add(int data);						//M�todo para adicionar um dado na lista.
		void add_end(int data);					//M�todo para adicionar um dado ao final da lista.
		void insert_after(int data, int prev);	//M�todo para adicionar um dado ap�s um dado espec�fico.
		bool remove(int data);					//M�todo para remover um dado da lista.
		void print();							//M�todo para printar todo o conte�do da lista.
		bool empty();							//M�todo para verificar se a lista est� vazia.
};

LinkedList::LinkedList() {				//Construtor da lista.
	this->length = 0;					//Seta o tamanho como zero.
	this->head = NULL;					//Seta o ponteiro para nulo.
}

LinkedList::~LinkedList(){				//Desconstrutor da Lista.
	free(head);							//Limpa o head da mem�ria.
	std::cout << "Lista \"deletada\"";	//Apenas mostra na tela que a lista foi "Deletada" (Desconstruida).
}

void LinkedList::print(){									//Implementa��o do m�todo print.
	Node* head = this->head;								//Seta o ponteiro do head.
	int i=1;												//Cria a variavel i para fazer a contagem de quantos itens existe dentro da lista.
	while(head){											//Enquanto houver um dado, continua executando seu escopo.
		std::cout << i << ": " << head->data << std::endl;	//Printa a posi��o atual da lista e pega o conteudo do head.
		head = head -> next;								//Atualiza o head.
		i++;												//Incrementa a vari�vel i.
	}
}

void LinkedList::add(int data){			//Implementa��o do m�todo de adicionar conteudo na lista.
	Node* node = new Node();			//Cria uma vari�vel do tipo node.
	node->data = data;					//O n� recebe o dado.
	node->next = this->head;			//Seta o proximo n� para null.
	this->head = node;					//Seta o head para um novo n�.
	this->length++;						//Faz a contagem do tamanho da lista.
}

void LinkedList::add_end(int data){		//Implementa��o do m�todo de adicionar conteudo no final da lista.
	Node* new_node = new Node();		//Cria uma variavel do tipo node.
	new_node->data = data;				//O node recebe o dado passado pelo parametro
	Node* list = head;					//Cria outro n� que recebe o head.
	while(list->next != NULL){			//Percorre toda a lista.
		list = list->next;				//Atualiza a lista para percorrer at� o final.
	}
	list->next = new_node;				//Adiciona o novo node quando o next da lista for nulo
	this->length++;						//Aumenta a contagem do tamanho da lista.
}

void LinkedList::insert_after(int data, int usr){	//Implementa��o do m�todo de adicionar conteudo apos um dado especifico
	Node *node = this->head;						//Cria um node com o head atual.
	Node *new_node = new Node();					//Cria um novo node
	new_node->data = data;							//O novo node recebe o dado passado pelo usuario
	while (node->data != usr){						//Faz o loop para achar o dado que o usuario passou
		node = node->next;							//Atualiza o node
	}
	if (node != NULL){								//Verifica se n�o � nulo
		new_node->next = node->next;				//O novo node recebe em seu next o node next atual
		node->next = new_node;						//O node next recebe o novo node.
	}else{
		std::cout << "Nao foi possivel adicionar o dado na lista!!" << std::endl;
	}
}

bool LinkedList::find(int data){							//Implementa��o do m�todo find.
	Node *node = new Node;									//Cria��o de um ponteiro para um node.
	if (!head){												//Verifica se o HEAD est� vazio.
		std::cout << "A lista est� vazia! \n" << std::endl;	//Mostra mensagem avisando que a lista est� vazia.
		return false;										//Retorna false.
	}
	node = head;											//Atribui o HEAD para o Node.
	for (; node; node = node->next){						//Percorre todos os n�s.
		if (node->data == data){							//Verifica se o n� atual tem o mesmo atributo que foi passado.
			return true;									//Se a verifica��o for verdadeira, retorna true.
		}
	}
	return false;											//Se a verifica��o for falsa, retorna false.
}

bool LinkedList::remove(int data){							//Implementa��o do m�todo para remover um conte�do da lista.
	Node *node = new Node;									//Cria��o de um ponteiro para um node.
	if (!find(data)){										//Verifica se a lista est� vazia.
		return false;										//Se tiver vazia, retorna false.
	}
	while (head->data == data){								//Atuali
		head = head->next;
	}
	if (!head){												//Verifica se o head n�o � nulo.
		return false;										//Retorna false se for nulo.
	}
	node = head;											//O n� recebe o head atualizado.
	while(node){											//Enquanto o node n�o for null, roda o loop.
		if(node->next){										//Se o pr�ximo node n�o for null
			if(node->next->data == data){					//Se o proximo node tiver um atributo igual ao parametro passado
				Node *node2 = node->next->next;				//Cria-se um node tempor�rio para guardar a referencia do pr�ximo node que n�o ser� removido.
				free(node->next);							//Limpa de mem�ria o proximo n�
				node->next = node2;							//Linka o segundo node com o pr�ximo n� do node atual.
				length--;									//Decrementa o tamanho atual da lista.
			}
		}
		node = node->next;									//Atualiza o node atual.
	}
	return true;											//Retorna true.
}

bool LinkedList::empty() {									//Implementa��o do m�todo empty para verificar se a lista est� vazia.
	return (this->head == NULL);							//Retorna true or false se a lista estiver vazia.
}

void menu (LinkedList *lista) {											//Cria��o da fun��o menu.
	int decision = 0;
	do{
		int value = 0;
		int prev = 0;
		system("CLS");
		std::cout << "Oi, eu sou uma lista!\n\n" << std::endl;			//Printa as op��es disponiveis para o usu�rio.
		std::cout << "1 - Printar a lista" << std::endl;
		std::cout << "2 - Adicionar valor a lista" << std::endl;
		std::cout << "3 - Adicionar valor ao final da lista" << std::endl;
		std::cout << "4 - Adicionar valor depois de um numero" << std::endl;
		std::cout << "5 - Remover valor da lista" << std::endl;
		std::cout << "6 - Procurar valor na lista" << std::endl;
		std::cout << "7 - Verificar o tamanho da lista" << std::endl;
		std::cout << "8 - Sair" << std::endl;
		std::cin >> decision;											//Guarda a decis�o do usu�rio
		switch (decision){
			case 1:
				system("CLS");											//Limpa a tela (windows).
				lista->print();											//Chamada para o m�todo print da lista.
				system("PAUSE");										//Pausa o programa (windows).
			break;
			case 2:
				system("CLS");
				std::cout << "Digite um valor para adicionar a lista:" << std::endl;
				std::cin >> value;
				lista->add(value);														//Chamada para o m�todo add da lista.
				std::cout << "Valor adicionado!" << std::endl;
				system("PAUSE");
			break;
			case 3:
				system("CLS");
				std::cout << "Digite um valor para adicionar ao final da lista:" << std::endl;
				std::cin >> value;
				lista->add_end(value);														//Chamada para o m�todo add ao final da lista.
				std::cout << "Valor adicionado!" << std::endl;
				system("PAUSE");
			break;
			case 4:
				system("CLS");
				std::cout << "Digite um valor para adicionar a lista:" << std::endl;
				std::cin >> value;
				std::cout << "Digite o numero anterior ao que voce quer adicionar: " << std::endl;
				std::cin >> prev;
				lista->insert_after(value, prev);														//Chamada para o m�todo insert after.
				std::cout << "Valor adicionado!" << std::endl;
				system("PAUSE");
			break;
			case 5:
				system("CLS");
				std::cout << "Digite um valor para remover da lista:" << std::endl;
				std::cin >> value;
				if (lista->remove(value)){
					lista->remove(value);												//Chamada para o m�todo remove da lista.
					std::cout << "Valor removido!!" << std::endl;
				}else{
					std::cout << "Valor n�o encontrado!!" << std::endl;
				}
				system("PAUSE");
			break;
			case 6:
				system("CLS");
				std::cout << "Digite um valor para procurar na lista:" << std::endl;
				std::cin >> value;
				if (lista->find(value)){
					lista->find(value);													//Chamada para o m�todo find da lista.
					std::cout << "Valor " << value << " encontrado na lista!!" << std::endl;
				}else {
					std::cout << "Valor " << value << " nao encontrado na lista!!" << std::endl;
				}
				system("PAUSE");
			break;
			case 7:
				system("CLS");
				std::cout << "A lista tem atualmente " << lista->length << " de tamanho!" << std::endl;	//Printa o tamanho atual da lista.
				system("PAUSE");
			break;
			case 8:
				system("CLS");
				std::cout << "Obrigado por utilizar minha lista!! =)" << std::endl;
				exit(1);
			break;
			default:
				system("CLS");
				std::cout << "Opcao invalida, tente novamente!! \n\n" << std::endl;
				system("PAUSE");
		}
	}while(decision != 8);
}

int main (int argc, char const *argv[]) {								//M�todo main padr�o.
	LinkedList* lista = new LinkedList();								//Cria a vari�vel lista do tipo LinkedList.
	menu(lista);														//Chamada para o menu.
	return 0;
}
