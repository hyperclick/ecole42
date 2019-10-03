#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"


void	assert_true(BOOL expected, BOOL actual)
{
	if (actual!=expected)
	{
		printf("\tFAILED:\nexpected: %d but was: %d\n", expected, actual);
		exit(1);
	}
	
}

void	assert_pvoid(const void* expected, const void* actual)
{
	if (actual!=expected)
	{
		printf("\tFAILED:\nexpected: %p but was: %p\n", expected, actual);
		exit(1);
	}
	
}

void	assert_int(const int expected, const int actual)
{
	if (actual != expected)
	{
		printf("\tFAILED:\nexpected: %d but was: %d\n", expected, actual);
		exit(1);
	}
	
}

void	assert_str(const char* expected, const char* actual)
{
	//printf("comparing '%s' and '%s'\n", expected, actual);
	if (expected == NULL)
	{
		if (actual == NULL)
		{
			return ;
		}
		printf("\tFAILED:\nexpected: '%s' but was: '%s'\n", expected, actual);
		exit(1);
	}
	if (strcmp(expected, actual)!=0)
	{
		printf("\tFAILED:\nexpected: '%s' but was: '%s'\n", expected, actual);
		exit(1);
	}
	
	//printf("equal\n");
}

void	assert_bytes(const unsigned char* expected, const unsigned char* actual, size_t len)
{
	while (len!=0)
	{
		if (expected[len]!=actual[len])
		{
			printf("\tFAILED:\ndifferent element at %zu expected: '%c'(%d) but was: '%c'(%d)\n", len, expected[len], expected[len], actual[len], actual[len]);
			exit(1);
		}
		len--;
	}
	
}
