#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "hash.c"
#include "include/main.h"

#define DSIGMA 65536
#define HS(x, i) (x[i] << 3) + (x[i + 1] << 2) + (x[i + 2] << 1) + x[i + 3]
#define Q 4

#define ABSENT 0
#define UNIQUE 1
#define REPEATED 2

void preprocessing(unsigned char *x, int m, int *dist, HASH_TABLE *ht, HASH_NODE *nd)
{
    uint8_t S[DSIGMA];
    for (int i = 0; i < DSIGMA; i++)
    {
        S[i] = ABSENT;
        dist[i] = -1;
    }

    uint16_t c;
    for (int i = 0; i < m - Q + 1; i++)
    {
        c = HS(x, i);
        if (S[c] == ABSENT)
            S[c] = UNIQUE;
        else
            S[c] = REPEATED;
    }

    int lastUnique = -1;
    for (int i = 0; i < m - Q + 1; i++)
    {
        c = HS(x, i);

        switch (S[c])
        {
        case REPEATED:
            if (lastUnique >= 0)
            {
                int d = (i - lastUnique);
                if (d > dist[c])
                    dist[c] = d;
            }
            else
                dist[c] = i;
            break;

        case UNIQUE:
            lastUnique = i;
            dist[c] = 0;
            break;
        }
    }

    ht->nd = nd;
    hash_table_create(ht, nd);
    for (int i = 0; i < m - Q + 1; i++)
    {
        c = HS(x, i);
        int len = dist[c] + Q;

        if (i + Q >= len)
            hash_insert(ht, x + i + Q - len, len, i + Q - len, c);
    }
}

int search(unsigned char *x, int m, unsigned char *y, int n)
{
    if (m < Q)
        return -1;

    uint16_t c;
    int dist[DSIGMA];
    HASH_NODE nd[m];
    HASH_TABLE ht;

    BEGIN_PREPROCESSING
    preprocessing(x, m, dist, &ht, nd);
    END_PREPROCESSING

    BEGIN_SEARCHING
    int count = 0;
    int j = m - Q;
    while (j < n)
    {
        c = HS(y, j);

        int d = dist[c];
        if (d >= 0)
        {
            int l = d + Q;
            int p = hash_search(&ht, y + j - d, l, x, c);
            j -= d + (l != m);

            if (p >= 0)
            {
                int k = 0;
                while (k < p && x[p - 1 - k] == y[j - k])
                    k++;

                if (k == p)
                {
                    if (k + l == m)
                        count++;
                    else
                        j -= k;
                }
            }
        }
        j += m - Q + 1;
    }
    END_SEARCHING
    return count;
}