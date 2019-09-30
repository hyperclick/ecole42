#include <stdio.h>
# include <stdlib.h>
#include <string.h>

unsigned char *str_to_byte_array(const char *str, size_t *len)
{
	char item[20];
	int p = 0;
	unsigned char *r = malloc(sizeof(unsigned char) * strlen(str));
	*len = 0;
	
	while (*str != 0)
	{
		if (*str == ',')
		{
			//printf("\nr[%lu] = %s\n",*len, item);
			r[*len] = atoi(item);
			*len = *len + 1;
			p = 0;
			str++;
			continue;
		}
		//printf("\titem = '%s', str = '%s' (%d)\n",item, str, *str);
		item[p++] = *str;
		str++;
	}
	if (p!=0)
	{
		//printf("\nr[%lu] = %s\n",*len, item);
		r[*len] = atoi(item);
		*len = *len + 1;
		p = 0;
	}
	return (r);
}

char	*byte_array_to_str(const unsigned char a[], const size_t len)
{
	if (len == 0)
	{
		return (NULL);
	}
	char *str = malloc(len * (2*sizeof(char)));
	char *str_start = str;
	char tmp[20];
	size_t i = 0;
	while (i < len)
	{
		//printf("a[%zu]=%d\n",i, a[i]);
		sprintf(tmp, "%d", a[i]);
		//printf("tmp = '%s'\n", tmp);
		strcpy(str, tmp);
		//printf("str_start = '%s', str = %p\n", str_start, str);
		str = str + strlen(tmp);
		*str = ',';
		//printf("str_start = '%s', str = %p\n", str_start, str);
		str++;
		i++;
	}
	*(str - 1) = 0;
	return (str_start);
}
