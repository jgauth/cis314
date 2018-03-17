// Author: John Gauthier
// Description: Simulates a 64B direct-mapped cache with 4B blocks
// Sources: course/assignment material

#include "stdio.h"
#include "stdlib.h"

#define BLOCK_SIZE 4
#define NUM_SETS 16

struct CacheBlock {
	unsigned char valid;
	unsigned int tag;
	unsigned char value[BLOCK_SIZE];
};

// *NOTE* getOffset, getSet, and getTag only work with defined values above

unsigned int getOffset(unsigned int address) {

	return (address & 0x3);
}

unsigned int getSet(unsigned int address) {

	address = address & 0x3C;
	return (address >> 2);
}

unsigned int getTag(unsigned int address) {

	return (address >> 6);
}

unsigned int getHexInput() {

	char buffer[256];
	char *ptr;
	unsigned int ret;

	// Get input string
	fgets(buffer, 256, stdin);
	// Convert string to unsigned int
	ret = (unsigned int)strtoul(buffer, &ptr, 16);
	return ret;
}

void printBytes(unsigned char *start, int len) {

	for (int i = 0; i < len; i++) {
		printf(" %.2X", start[i]);
	}
	printf("\n");
}

void writeValue(struct CacheBlock *cache) {

	// Prompt user for 32-bit hex address (unsigned int) assume multiple of 4
	printf("Enter 32-bit unsigned hex address: ");
	unsigned int address = getHexInput();

	// Prompt user for 32-bit hex value
	printf("Enter 32-bit unsigned hex value: ");
	unsigned int value = getHexInput();
	printf("\n");
	
	// Separate address into appropriate variables
	unsigned int tag = getTag(address);
	unsigned int set = getSet(address);

	// Evict existing block if necessary
	if (cache[set].valid) {
		printf("Evicted Block | set: %d | tag: %d | value:", set, cache[set].tag);
		printBytes(cache[set].value, BLOCK_SIZE);
	}

	// Set valid and tag bits
	cache[set].valid = 1;
	cache[set].tag = tag;
	
	// Write 4-byte value to appropriate location in cache for given address
	// From piazza post, casts int value to char array to easily copy to cache.value
	unsigned char *valueChar = (unsigned char *) &value; 
	for (int i = 0; i < BLOCK_SIZE; ++i) {
		cache[set].value[i] = valueChar[i];
	}

	// Print set-index, tag, and value of the new block
	printf("Wrote Block   | set: %d | tag: %d | value:", set, cache[set].tag);
	printBytes(cache[set].value, BLOCK_SIZE);
	printf("\n");
}

void readValue(struct CacheBlock *cache) {

	// Prompt user for 32-bit hex address (unsigned int)
	printf("Enter 32-bit unsigned hex address: ");
	unsigned int address = getHexInput();
	printf("\n");

	// Print the set index and tag corresponding to the address
	unsigned int tag = getTag(address);
	unsigned int set = getSet(address);
	unsigned int offset = getOffset(address);

	// Weird spacing on all these print statements is to line them up in the output 
	printf("Reading       | set: %d | tag: %d |\n", set, tag);


	// If the cache contains a valid value corresponding to the address print 'hit' and the value of the byte
	// Otherwise print 'miss' and the reason for the miss
	if (!cache[set].valid) {
		printf("Miss! No valid set found\n\n");
	}
	else {
		printf("Found         | set: %d | tag: %d | offset: %d | value: %X\n", set, cache[set].tag, offset, cache[set].value[offset]);
		if (cache[set].tag != tag) {
			printf("Miss! Tag mismatch\n\n");
		}
		else {
			printf("Hit!\n\n");
		}
	}
}

void printCache(struct CacheBlock *cache) {

	// Prints the set index, tag, and value for all valid blocks in the cache
	for (int i = 0; i < NUM_SETS; ++i) {
		if (cache[i].valid) {
			printf("              | set: %d | tag: %d | value:", i, cache[i].tag);
			printBytes(cache[i].value, BLOCK_SIZE);
		}
	}
	printf("\n");
}

int main() {

	// Malloc array of CacheBlocks
	struct CacheBlock *cache = malloc(sizeof(struct CacheBlock) * NUM_SETS);

	// Input loop from the professor's piazza post
	char buffer[256];
	char c;
	do {
		printf("enter 'w' to write, 'r' to read, 'p' to print, 'q' to quit: ");
		fgets(buffer, 256, stdin);
		c = buffer[0];

		if (c == 'w') {
	        writeValue(cache);
		} else if (c == 'r') {
	        readValue(cache);
		} else if (c == 'p') {
			printf("\n");
	        printCache(cache);
		}
	} while (c != 'q');
	printf("Exiting\n");
}