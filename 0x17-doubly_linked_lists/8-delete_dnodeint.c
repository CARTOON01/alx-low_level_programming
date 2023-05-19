#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a doubly linked list.
 * @head: Pointer to a pointer to the head of the doubly linked list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if deletion is successful, -1 if it fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
        return -1;

    dlistint_t *current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return 1;
    }

    unsigned int i = 0;

    while (i < index)
    {
        if (current == NULL)
            return -1;
        current = current->next;
        i++;
    }

    if (current == NULL)
        return -1;

    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    free(current);

    return 1;
}
