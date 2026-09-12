#include <stdio.h>

int main() {
    int f[50], index, n, i, block;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter index block: ");
    scanf("%d", &index);

    if(f[index] == 1) {
        printf("Index block already allocated.\n");
        return 0;
    }

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    f[index] = 1;

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &block);

        if(f[block] == 0) {
            f[block] = 1;
        }
        else {
            printf("Block %d already allocated.\n", block);
        }
    }

    printf("\nAllocated Blocks:\n");
    printf("Index Block: %d\n", index);

    printf("File Blocks: ");
    for(i = 0; i < 50; i++) {
        if(f[i] == 1 && i != index)
            printf("%d ", i);
    }

    return 0;
}