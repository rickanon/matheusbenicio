/*    Funções da Árvore Genealógica    */


arvore *incluir(arvore *no, int nome, int dado){//Inserção de nós
	
	arvore *aux=NULL; //ponteiro auxiliar
	
	if(no == NULL){//Teste de validação do nó
		no=(arvore*)malloc(sizeof(arvore));//alocação de memória
		//inicialização
		no->nome= nome;
		no->dado= dado;
		
		no->esquerda= NULL;
		no->direita= NULL;
		
		
		no->conjuge= NULL;
		no->filho= no->esquerda;
		no->irmao=NULL;
		
		if( no->dado != 3)//inicialização do campo sexo
			no->sexo= dado;
		else{
			no->sexo= 0;
		}
		
		return no;
	}
	//Ordenação da árvore
	if(nome < no->nome){//Se nome é menor que nó->nome
		no->pai= no;//Atribuição do pai
		no->esquerda= incluir(no->esquerda, nome, dado);//insere recursivamente
	}
	else if(nome >no->nome){//Se nome é direita que nó->nome
		no->pai= no;//Atribuição do pai
		no->direita= incluir(no->direita, nome, dado);//insere recursivamente
		
	}
	return no;
}

void imprime(arvore *no){//Imprime de forma ordenada
	
	if(no != NULL){//se nó não é nulo
		
		imprime(no-> direita);//Imprime o lado direito recursivamente
			//Imprime as características
			printf("\n\tNome:%d- \n", no->nome);
			printf("\tSexo: %d- \n", no->sexo);
			printf("\tConjuge: %d- \n", no->conjuge);
		imprime(no->esquerda);//Imprime o lado esquerdo recursivamente
	}
}

arvore *Buscar(arvore *no, int nome){//Algoritmo de busca do nó infromado pelo usuário
	
	if(no == NULL)
		return no;
	
	if(no->nome == nome)//se forem iguais retorna o nó
		return no;
	
	if(nome > no->nome)//Se info(nó desejado) for maior que no->info(raiz) será buscado apenas do lado direito
		return Buscar(no->direita, nome);

	if(nome < no->nome)//Se info(nó desejado) for menor que no->info(raiz) será buscado apenas do lado esquerdo
		return Buscar(no->esquerda, nome);

}

void *buscapai(arvore *no, int nome){//Busca do pai de nó qualquer
	arvore *aux=NULL;//nó auxiliar
	
	aux= Buscar(no, nome);//Busca o nó
	
	if(aux != NULL){
		printf("O pai dessa pessoa e: %d\n", no->pai->nome);//Impressão dos pais do nó
		//printf("A mae dessa pessoa e: %d\n", no->pai->conjuge->nome);
	}
	
}

void *buscafilhos(arvore *no, int nome){//Busca dos filhos do nó
	arvore *aux=NULL;
	noTipoC *auxCas= NULL;//auxiliar para percorrer os conjuges
	
	aux= Buscar(no, nome);//Busca o nó desejado
	
	if(aux != NULL){
		
		if(aux->conjuge != NULL){
			auxCas= aux->direita;//aux recebe o ponteiro direito, que é o pai
			aux= auxCas->direita;//aux recebo o pai	
			
			printf("Os filhos dessa pessoa e: %d e %d\n", aux->filho, aux->filho->irmao);
		}
	}
}

int altura(arvore *r){// Calcula a altura da árvore
	int he;//altura esquerda
	int hd;//altura direita
	
	if(r == NULL)// se a árvore for nula
		return -1;
	else{
		
		he= altura(r->esquerda);//verifica a altura do lado esquerdo
		hd= altura(r->direita);//verifica a altura do lado direito
		
		if(he < hd)//se altura esquerda foi maior que a direita
			return (hd+1);
		else
			return (he+1);
	}
}

void casamento(arvore *no, arvore *no_aux){//Função para casamento dos nós
	
	arvore *aux=NULL;//auxiliar
	noTipoC *uniao= NULL;//variável que fará a união
	
	
	aux= Buscar(no, no->nome);
	
		if(aux != NULL){
			
			if((no->conjuge == NULL) && (no_aux->conjuge == NULL)){
				if (no->sexo =! no_aux->sexo) {
					//Atribuição dos ponteiros dos conjuges
					no->conjuge= no_aux;
					no_aux->conjuge= no;
					
					//Casamento:
					uniao->dado=3;//dado tipo casamento
					uniao->direita= no;//recebe o marido
					uniao->esquerda= no_aux;//recebe a esposa
					no->direita= uniao;//aponta para o nó que faz a ligação com a esposa
				}
				else{
					printf("Essas pessoas são no mesmo sexo.");
				}
			}	
			else{
				printf("Essa pessoa ja e casada.");
			}
		}
}

void menu(){
	int op;//Opção do menu
	int h;//Recebe a altura da árvore
	int nome;//nome da pessoa a ser inserida
	int dado;//dado de cada pessoa, homem, mulher ou casamento
	arvore *aux;
	arvore *noaux= (arvore*)malloc(sizeof(arvore)); 
	
	while(1){
		system("cls");
		printf("\t\t =========== ARVORE GENEALOGICA ===========\n\n");
		printf("  | 1 - Insere membro na familia; \n ");
		printf(" | 2 - Realizar casamento;\n ");
		printf(" | 3 - Imprimir; \n ");
		printf(" | 4 - Buscar pessoa; \n ");
		printf(" | 5 - Verificar Altura;\n ");
		printf(" | 6 - Buscar pai; \n ");
		printf(" | 7 - Buscar filho; \n ");
		printf(" | 8 - Sair. \n ");
		scanf("%d", &op);
		
		switch (op) {
			
			case 1:
				if(altura(raiz) != -1){//Se a raiz da arvore não é nula
					if((raiz->direita ==NULL)&&(raiz->esquerda==NULL)){//se os ponteiros da raiz não são nulos
						printf("Informe o nome do conjuge d@ 'patriarca':  ");//Será realizado o 1º casamento
						scanf("%d", &nome);
						printf("\nEscolha o tipo de dado:\n");
						printf("1- Masculino;\n");
						printf("2- Feminino;\n");
						scanf("%d", &dado);
						noaux= incluir(noaux, nome, dado);
						
						if(noaux == NULL)
							printf("Conjuge nao inserido!");
						
						casamento(raiz, noaux);
						break;
					}	
					else if(raiz->conjuge =! NULL){
							printf("\nEscolha o tipo de dado:\n");
							printf("1-nascimento de um menino;\n");
							printf("2-nascimento de uma menina;\n");
							scanf("%d", &dado);
							fflush(stdin); 
							printf("\n  |_Nome da pessoa:   ");
			    			scanf("%d", &nome );
							
							raiz= incluir( raiz, nome, dado);
					}
				}else{
					printf("\nEscolha o tipo de dado:\n");
					printf("1-nascimento de um menino;\n");
					printf("2-nascimento de uma menina;\n");
					scanf("%d", &dado);
					fflush(stdin); 
					printf("\n  |_Nome da pessoa:   ");
			    	scanf("%d", &nome );
							
					raiz= incluir( raiz, nome, dado);
				}
				system("pause");
				break;
				
			case 2:
				printf("Informe o nome da pessoa que ira casar: ");
				scanf("%d", &aux->nome);
				printf("Informe o nome do conjuge:  ");//Será realizado o casamento
				scanf("%d", &nome);
				printf("\nEscolha o tipo de dado:\n");
				printf("1- Masculino;\n");
				printf("2- Feminino;\n");
				scanf("%d", &dado);
				noaux= incluir(noaux, nome, dado);//Inserção do conjuge
						
					if(noaux == NULL)//Teste de erro
						printf("Conjuge nao inserido!");
						
				casamento(aux, noaux);//chamada da função para a realização do matrimônio
				system("pause");
				break;
			case 3:
				imprime(raiz);
				system("pause");
				break;
			case 4:{
				printf("Informe a pessoa que busca: ");
				scanf("%d", &nome);
				
				aux= Buscar(raiz, nome);
				
				if (aux == NULL)
					printf("Pessoa n%co encontrada!\n", 198);
				else
				printf("Pessoa localizada.\n\n");
				
				system("Pause");
				break;
			}
			case 5:{
				h= altura(raiz);
				printf("A altura da %crvore %c: %d.\n", 160, 130, h);
				system("Pause");
				break;
			}
			case 6:
				printf("Informe o nome da pessoa: ");
				scanf("%d", &nome);
				buscapai(raiz, nome);
				system("pause");
				break;
				
			case 7:
				printf("Informe o nome do pai: ");
				scanf("%d", &nome);
				buscafilhos(raiz, nome);
				system("pause");
				break;
			case 8:	
				exit(0);
			
			default:
				printf("\n Op%c%co Inv%clida!\n", 135, 198, 160);
				system("Pause");
				break;
			
		}
	}
	
}

