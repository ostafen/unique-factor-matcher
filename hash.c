
#define HASH uint16_t
#define TABLE_SIZE 65536

typedef struct HASHNODE
{
    struct HASHNODE *next;
    int pos;
    int len;
} HASH_NODE;

typedef struct HASHTABLE
{
    HASH_NODE *T[TABLE_SIZE];
    HASH_NODE *nd;
    int i;
} HASH_TABLE;

void hash_table_create(HASH_TABLE *ht, HASH_NODE *nd)
{
    ht->i = 0;
    ht->nd = nd;
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->T[i] = NULL;
}

void hash_insert(HASH_TABLE *ht, const char *factor, int len, int pos, HASH h)
{
    HASH_NODE *nd = &(ht->nd[ht->i]);
    nd->pos = pos;
    nd->len = len;
    nd->next = ht->T[h];
    ht->T[h] = nd;
    (ht->i)++;
}

int hash_search(HASH_TABLE *ht, const char *factor, int len, const char *x, HASH h)
{
    HASH_NODE *nd = ht->T[h];
    while (nd != NULL)
    {
        if (nd->len == len && !memcmp(x + nd->pos, factor, len))
            return nd->pos;
        nd = nd->next;
    }
    return -1;
}