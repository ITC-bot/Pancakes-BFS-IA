#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

/*Definiendo el nodo*/
typedef struct nodo
{
    char arr[MAX_SIZE];
    int n;
    struct nodo *next;
} Nodo;

/*Funcion de voltear los arreglos*/
void voltear(char arr[], int i)
{
    int inicio = 0;
    char temp;
    while (inicio < i)
    {
        temp = arr[inicio];
        arr[inicio] = arr[i];
        arr[i] = temp;
        inicio++;
        i--;
    }
}

/*Funcion para organizar los pancakes*/
void pancakes(char arr[], int n)
{
    for (int curr_size = n; curr_size > 1; curr_size--)
    {
        int max_i = 0;
        for (int i = 0; i < curr_size; i++)
        {
            if (arr[i] > arr[max_i])
            {
                max_i = i;
            }
        }
        if (max_i != curr_size - 1)
        {
            voltear(arr, max_i);
            voltear(arr, curr_size - 1);
        }
    }
}

/*Funcion para agregar*/
void agregar_cola(Nodo **frente, Nodo **atras, char arr[], int n)
{
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    strncpy(nuevo_nodo->arr, arr, n);
    nuevo_nodo->n = n;
    nuevo_nodo->next = NULL;
    if (*atras == NULL)
    {
        *frente = nuevo_nodo;
        *atras = nuevo_nodo;
    } else
    {
        (*atras)->next = nuevo_nodo;
        *atras = nuevo_nodo;
    }
}

/*Funcion para extraer*/
void eliminar_cola(Nodo **frente, Nodo **atras) {
    if (*frente == NULL) {
        return;
    }
    Nodo *temp = *frente;
    *frente = (*frente)->next;
    if (*frente == NULL) {
        *atras = NULL;
    }
    free(temp);
}

/*Funcion para ver si la cola esta vacia*/
int cola_vacia(Nodo *frente)
{
    return frente == NULL;
}

/*Funcion para la busqueda de amplitud*/
void bfs(char arr[], int n) {
    char temp[MAX_SIZE];
    Nodo *frente = NULL;
    Nodo *atras = NULL;
    agregar_cola(&frente, &atras, arr, n);
    while (!cola_vacia(frente)) {
        Nodo *curr = frente;
        frente = frente->next;
        printf("Nodos a visitar: ");
        for (int i = 2; i <= n; i++) {
            temp[MAX_SIZE];
            char temp[MAX_SIZE];
            strncpy(temp, curr->arr, curr->n);
            voltear(temp, i - 1);
            agregar_cola(&frente, &atras, temp, curr->n);
            printf("\n");
            imprimir_arreglo(temp, curr->n);
        }
        printf("\n");
        if (curr->n == n) {
            pancakes(curr->arr, curr->n);
            printf("Arreglo ordenado: ");
            imprimir_arreglo(curr->arr, curr->n);
            printf("\n");
            break;
        }
        free(curr);
    }
}

/*Funcion para imprimir el arreglo*/
void imprimir_arreglo(char *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%c", arr[i]);
    }
}

/*Funcion principal*/
int main()
{
    char arr[MAX_SIZE];
    printf("Ingrese los caracteres a ordenar: ");
    scanf("%s", arr);
    int n = strlen(arr);
    bfs(arr, n);
    return 0;
}
