#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return NULL;

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    memset(ht->array, 0, sizeof(shash_node_t *) * size);
    ht->shead = NULL;
    ht->stail = NULL;

    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current, *prev = NULL;

    if (ht == NULL || key == NULL || value == NULL)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return 1;
        }
        prev = current;
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;
    new_node->sprev = NULL;
    new_node->snext = NULL;

    if (prev == NULL)
        ht->array[index] = new_node;
    else
        prev->next = new_node;

    if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
    {
        new_node->snext = ht->shead;
        if (ht->shead != NULL)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        current = ht->shead;
        while (current->snext != NULL && strcmp(key, current->snext->key) > 0)
            current = current->snext;

        new_node->snext = current->snext;
        new_node->sprev = current;
        if (current->snext != NULL)
            current->snext->sprev = new_node;
        current->snext = new_node;
    }

    if (ht->stail == NULL || strcmp(key, ht->stail->key) > 0)
        ht->stail = new_node;

    return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL)
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }

    return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->shead;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->snext != NULL)
            printf(", ");
        current = current->snext;
    }
    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->stail;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->sprev != NULL)
            printf(", ");
        current = current->sprev;
    }
    printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            temp = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = temp;
        }
    }

    free(ht->array);
    free(ht);
}
