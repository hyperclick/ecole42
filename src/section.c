#include "../includes/ft.h"
#include "../includes/section.h"

char			*sec_to_table_entry(char buffer[], t_section *section)
{
	char	str[20];
	int		i;
	
	i = 0;
	ft_itoa(section->y, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_strcpy(buffer + i, "\t");
	i += 1;
	
	ft_itoa(section->x, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_itoa(section->len, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	return (buffer);
}
