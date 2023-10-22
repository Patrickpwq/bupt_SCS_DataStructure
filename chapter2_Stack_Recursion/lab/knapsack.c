#include <stdio.h>
#include <string.h>
#define N 100
typedef struct
{
    int size;
    int val;
} Item;
typedef struct
{
    int n;
    int capacity;
    Item items[N];
} Sample;
int selected[N], bestSelection[N];
int knapsackHelper(int n, int capacity, Item *items, int level)
{
    int space, total;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        space = capacity - items[i].size;
        for (int j = level; j < N; j++)
        {
            selected[j] = -1;
        }
        if (space >= 0)
        {
            // 暂时记录这个选择
            selected[level] = i;

            total = items[i].val + knapsackHelper(n, space, items, level + 1);
            if (total > max)
            {
                max = total;
                memcpy(bestSelection, selected, N);
            }
        }
    }

    return max;
}
void knapsack(Sample knapsack)
{
    for (int j = 0; j < N; j++)
    {
        selected[j] = -1;
        bestSelection[j] = -1;
    }
    int maxValue = knapsackHelper(knapsack.n, knapsack.capacity, knapsack.items, 0);

    printf("The max value is %d, with selection:", maxValue);
    for (int j = 0; j < N; j++)
    {
        if (bestSelection[j] == -1)
        {
            break;
        }
        printf("%d ", bestSelection[j] + 1);
    }
    printf("\n");
}

int main()
{
    Sample samples[] = {
        {3,
         5,
         {{2, 3},
          {3, 4},
          {4, 5}}},
        {3,
         10,
         {{2, 2},
          {5, 10},
          {3, 8}}},
        {4,
         8,
         {{3, 5},
          {5, 8},
          {2, 3},
          {4, 7}}},
        {5,
         17,
         {{3, 4},
          {4, 5},
          {7, 10},
          {8, 11},
          {9, 13}}}};
    int sampleCount = sizeof(samples) / sizeof(Sample);

    for (int s = 0; s < sampleCount; s++)
    {
        printf("Sample %d:\n", s + 1);
        printf("物品数量: %d\n", samples[s].n);
        printf("背包最大容量: %d\n", samples[s].capacity);
        for (int i = 0; i < samples[s].n; i++)
        {
            printf("物品%d: 重量=%d, 价值=%d\n", i + 1, samples[s].items[i].size, samples[s].items[i].val);
        }
        knapsack(samples[s]);
        printf("\n");
    }

    return 0;
}