/*Declaração das funções e dos */
typedef struct arv {
	int nome;
	int dado;//guardará o dado de cada nó da árvore
	int sexo;//masculino=1 e feminino=2
	struct arv *pai;//Ponteiro para o pai
	struct arv *irmao;//ponteiro para o irmão
	struct arv *conjuge;//ponteiro para o conjuge
	struct arv *filho;//ponteiro para o filho
	struct arv *esquerda;//ponteiro para o lado esquerdo
	struct arv *direita;//ponteiro para o lado direito
}arvore;

typedef struct nocsmt{//No Casamento
	int dado;//Dado do tipo casamento
	arvore *esquerda;//ponteiro para o lado esquerdo 
	arvore *direita;//ponteiro para o lado direito
}noTipoC;

arvore *raiz;//Raiz da árvore, primeiro nó

/*         Funções        */
arvore *incluir(arvore *no, int nome, int dado);//Função de inserção dos nós
void imprime(arvore *no);//Função da impressão dos nós com algumas de suas caracteristicas
int altura(arvore *r);//Altura da árvore
arvore *Buscar(arvore *no, int nome);//Busca nó qualquer
void *buscapai(arvore *no, int nome);//Busca e imprime o pai de nó qualquer
void *buscafilhos(arvore *no, int nome);//Busca os filhos de nó qualquer

