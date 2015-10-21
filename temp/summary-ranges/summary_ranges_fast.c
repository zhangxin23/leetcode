#include <stdio.h>

#define LENGTH	11

int main()
{
	int array[LENGTH] = {1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 15};
	int start = 0, end = 0;
	int index = 0;

	for(index = 0; index < LENGTH; index++) {
		if(array[index] - array[end] == 1) {
			end++;
		}
		else if(array[index] - array[end] > 1) {
			if(start == end)
				printf("\"%d\"  \n", array[start]);
			else
				printf("\"%d-->%d\"  \n", array[start], array[end]);

			start = index;
			end = index;
		}

		if(index == LENGTH - 1) {
			if(start == end)
				printf("\"%d\"  \n", array[start]);
			else
				printf("\"%d-->%d\"  \n", array[start], array[end]);			
		}
	}
}
