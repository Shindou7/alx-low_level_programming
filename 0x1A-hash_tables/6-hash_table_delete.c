#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash
 * @ht: pointer hash table
 * Return: no return
 */
void hash_table_delete(hash_table_t *ht)
{
		hash_node_t *current;
    unsigned long int i;
    
    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        while (ht->array[i] != NULL)
        {
            current = ht->array[i];
            ht->array[i] = current->next;
            free(current->key);
            free(current->value);
            free(current);
        }
    }

    free(ht->array);
    free(ht);
}
