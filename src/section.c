#include "../includes/ft.h"
#include "../includes/section.h"

char			*sec_to_string(char buffer[], t_section *section)
{
	char	str[20];
	int		i;
	
	i = 0;
	
	ft_strcpy(buffer + i, "y: ");
	i += 3;
	
	ft_itoa(section->y, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_strcpy(buffer + i, ", x: ");
	i += 4;
	
	ft_itoa(section->x, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_strcpy(buffer + i, ", len: ");
	i += 7;
	
	ft_itoa(section->len, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	return (buffer);
}
