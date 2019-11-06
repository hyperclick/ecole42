
#include "libft.h"

#include <stdio.h>


void log_log (const char *str)
{
	return ;
	FILE * fp;
	/* open the file for writing*/
	fp = fopen ("/Users/darugula/log.txt","a");
	//fp = fopen ("log.txt","a");
	
	fprintf (fp, "%s",str);
	
	/* close the file*/
	fclose (fp);
}

void	log_line(const char *str)
{
	log_log(str);
	log_log("\n");
}
