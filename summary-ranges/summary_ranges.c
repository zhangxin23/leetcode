#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int src_length = 100;
    int src_index = 0;
    int *src = (int*)malloc(sizeof(int) * src_length);
    memset(src, 0, sizeof(int) * src_length);

    while(1) {
        int input;
        int result = scanf("%d", &input);
        if(result == EOF) {
            printf("STDIN is bad.\n");
            break;
        }
        
        if(result == 0) {
            printf("input invalid integer.\n");
            break;
        }
        
        if(src_index < src_length) {
            src[src_index] = input;
            src_index++;
        } else {
            src_length = src_length * 2;
            int *new_src = (int*)malloc(sizeof(int) * src_length);
            memset(new_src, 0, sizeof(int) * src_length);
            memcpy(new_src, src, sizeof(int) * src_length / 2);
            free(src);
            src = new_src;
            src[src_index] = input;
            src_index++;
        }
    }
    

    int min = src[0];
    int max = src[9];
    
    int start = 0;
    int end = 0;

    if(min < 0)
        start = -min;
    else
        start = 0;

    if(max < 0)
        end = 0;
    else
        end = max;

    int length = start + end + 1;
    int *index_map = (int*)malloc(sizeof(int) * length);
    memset(index_map, 0, sizeof(int) * length);

    int index = 0;
    for(index = 0; index < src_index; index++) {
        printf("%d  ", src[index]);
        index_map[src[index] - min] = 1;
    }

    printf("\n");

    for(index = 0; index < length; index++) {
        printf("%d  ", index_map[index]);
    }
    printf("\n");

    start = end = -1;

    printf("[");
    for(index = 0; index < length; index++) {
        if(index_map[index] == 1 && start == -1)
            start = index;

        if(index_map[index] == 0 && start != -1) {
            end = index - 1;
            if(start == end)
                printf("\"%d\" ", start + min);
            else
                printf("\"%d-->%d\" ", start + min, end + min);
            
            start = end = -1;
        }

        if(index == length - 1 && index_map[index] == 1) {
            end = index;
            
            if(start == end)
                printf("\"%d\"", start + min);
            else
                printf("\"%d-->%d\"", start + min, end + min);
        }
    }
    printf("]\n");

    free(index_map);
}
