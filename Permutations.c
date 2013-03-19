// This short C program lists all the permutations of any given word.
// Mind-bending Recursion
// Usage eg. Permutations abcdefgh

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void createComb(char *memory, char index, char numComb);
void printComb(char *memory, char numComb);
char *lookupTable = NULL;

int main(int argc, char **argv)
{
	char numComb = 0;
	char *combMem = NULL;
	int i;
	
	numComb = strlen(argv[1]);
	lookupTable = (char *)malloc(sizeof(char) * numComb);
	
    for (i = 0; i < numComb; i++) {
		lookupTable[i] = argv[1][i];
	}
    
	combMem = (char *)malloc(sizeof(char) * numComb);
	createComb(combMem, 0, numComb);
    
	return 0;
}

void createComb(char *memory, char index, char numComb)
{
	int i, j;
    
	for (i = 0; i < numComb; i++) {
		for (j = 0; j < index; j++) {
			if (memory[j] == i) break;
		}
		
		if (j == index) {
			memory[index] = i;
			
			if (index == (numComb - 1)) {
				printComb(memory, numComb);
				return;
			} else {
				createComb(memory, index + 1, numComb);
			}
		}
	}
}

void printComb(char *memory, char numComb)
{
	int i;
	static int count = 1;
    
	printf("%d: ", count++);
    
	for (i = 0; i < numComb; i++) {
		printf("%c", lookupTable[memory[i]]);
	}
    
	printf("\n");
    
}