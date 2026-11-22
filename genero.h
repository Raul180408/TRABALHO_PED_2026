#ifndef GENERO_H
#define GENERO_H

#define MAX_GENEROS 20   // quantidade máxima de gêneros, não coloquei isso no sql, mas nesse 
                        // contexto não faz muito sentido ter tantos gêneros assim, por isso coloquei o limite de 20 


typedef struct {
    int  id_genero;        // chave primária que indentifica o genero de forma unica
    char nome[50];         // nome do genero (ex: "Ação", "Comédia", "Drama", etc.)
    char descricao[255];   // explicacao curta sobre o genero
} Genero;                  // coloquei o tamanho de acordo com o que fiz no sql


typedef struct {
    Genero itens[MAX_GENEROS];
    int qtd;    // quantos generos estao cadastrados
} ListaGenero;


/* inicia a lista vazia (qtd = 0).
 * parametros: lista - ponteiro para a lista.
 * retorna: 1 se ok, 0 se lista for NULL. */
int genero_criar_lista(ListaGenero *lista);

/* insere um genero no FIM do vetor.
 * parametros: lista - a lista; g - o genero a inserir.
 * retorna: 1 se inseriu; 0 se lista NULL, lista cheia,
 *          id repetido ou nome repetido. */
int genero_inserir(ListaGenero *lista, Genero g);

/* busca um genero pelo id (percorre o vetor do inicio ao fim).
 * parametros: lista - a lista; id - id procurado.
 * retorna: ponteiro para o genero, ou NULL se nao achou / lista vazia. */
Genero *genero_buscar_por_id(ListaGenero *lista, int id);

/* busca um genero pelo nome exato.
 * parametros: lista - a lista; nome - nome procurado.
 * retorna: ponteiro para o genero, ou NULL se nao achou / lista vazia. */
Genero *genero_buscar_por_nome(ListaGenero *lista, const char *nome);

/* mostra todos os generos na tela.
 * parametros: lista - a lista.
 * retorna: 1 se mostrou; 0 se lista NULL ou vazia. */
int genero_listar(ListaGenero *lista);

/* altera a descricao de um genero ja cadastrado.
 * parametros: lista - a lista; id - id do genero; nova_desc - novo texto.
 * retorna: 1 se alterou; 0 se nao encontrou ou parametro invalido. */
int genero_atualizar_descricao(ListaGenero *lista, int id, const char *nova_desc);

/* remove um genero pelo id. Os elementos seguintes sao deslocados
 * uma posicao para tras para nao deixar buraco no vetor.
 * parametros: lista - a lista; id - id do genero a remover.
 * retorna: 1 se removeu; 0 se lista vazia ou id nao encontrado. */
int genero_remover(ListaGenero *lista, int id);

#endif
