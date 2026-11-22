#ifndef CONTEUDO_H
#define CONTEUDO_H


#define MAX_GENEROS_POR_CONTEUDO 5   // assim como no genero.h, considerando o contexto não faz muito sentido 
#define ATIVO 'A'                  // ter um conteúdo com tantos gêneros, então limitei a 5
#define INATIVO 'I'


typedef struct {
    int  id_conteudo;                              // chave primária
    char titulo[150];                              // titulo do filme/serie
    char descricao[500];                           // sinopse
    int  ano_lancamento;                           // ex.: 2021
    int  duracao_minutos;                          // duração em minutos
    char classificacao_indicativa[10];             // ex.: "L", "12", "16"
    char tipo_conteudo[50];                        // ex: filme, série, documentário, etc.
    char situacao;                                 // 'A' = ativo, 'I' = inativo
    int  generos[MAX_GENEROS_POR_CONTEUDO];        // ids dos generos (N:N)
    int  qtd_generos;                              // quantos ids estao em uso
} Conteudo;


typedef struct {
    Conteudo *itens;
    int qtd;
    int capacidade;
} ListaConteudo;


/* aloca o vetor inicial do catalogo e deixa a lista vazia.
 * parametros: lista - a lista; capacidade_inicial - tamanho inicial (> 0).
 * retorna: 1 se ok; 0 se parametro invalido ou falha no malloc. */
int conteudo_criar_lista(ListaConteudo *lista, int capacidade_inicial);

/* libera a memoria do vetor. Deve ser chamada ao final do programa.
 * parametros: lista - a lista.
 * retorna: nada. */
void conteudo_liberar_lista(ListaConteudo *lista);

/* cadastra um conteudo no FIM do vetor. Se estiver cheio, dobra a
 * capacidade com realloc. A situacao inicial fica 'A' (ativo) e
 * qtd_generos e zerado (generos entram depois, via conteudo_adicionar_genero).
 * parametros: lista - a lista; c - o conteudo a cadastrar.
 * retorna: 1 se cadastrou; 0 se lista invalida, id repetido
 *          ou falha no realloc. */
int conteudo_cadastrar(ListaConteudo *lista, Conteudo c);

/* busca um conteudo pelo id (percorre o vetor do inicio ao fim).
 * parametros: lista - a lista; id - id procurado.
 * retorna: ponteiro para o conteudo, ou NULL se nao achou / lista vazia. */
Conteudo *conteudo_buscar_por_id(ListaConteudo *lista, int id);

/* busca o primeiro conteudo com o titulo exato informado.
 * parametros: lista - a lista; titulo - titulo procurado.
 * retorna: ponteiro para o conteudo, ou NULL se nao achou / lista vazia. */
Conteudo *conteudo_buscar_por_titulo(ListaConteudo *lista, const char *titulo);

/* mostra na tela todos os conteudos (ativos e inativos).
 * parametros: lista - a lista.
 * retorna: 1 se mostrou; 0 se lista NULL ou vazia. */
int conteudo_listar(ListaConteudo *lista);

/* marca um conteudo como inativo (NAO apaga, para manter o historico).
 * parametros: lista - a lista; id - id do conteudo.
 * retorna: 1 se inativou; 0 se nao encontrou ou parametro invalido. */
int conteudo_inativar(ListaConteudo *lista, int id);

/* marca um conteudo como ativo novamente.
 * parametros: lista - a lista; id - id do conteudo.
 * retorna: 1 se reativou; 0 se nao encontrou ou parametro invalido. */
int conteudo_reativar(ListaConteudo *lista, int id);

/* associa um genero (pelo id) a um conteudo ja cadastrado.
 * parametros: lista - a lista; id_conteudo - conteudo alvo;
 *             id_genero - id do genero a associar.
 * retorna: 1 se associou; 0 se conteudo nao existe, ja tem 5 generos
 *          ou o genero ja estava associado. */
int conteudo_adicionar_genero(ListaConteudo *lista, int id_conteudo, int id_genero);

/* mostra todos os conteudos que possuem determinado genero.
 * parametros: lista - a lista; id_genero - id do genero procurado.
 * retorna: quantidade de conteudos encontrados (0 se nenhum ou lista vazia). */
int conteudo_listar_por_genero(ListaConteudo *lista, int id_genero);

#endif