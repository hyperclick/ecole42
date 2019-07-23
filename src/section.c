#include "../includes/ft.h"
#include "../includes/section.h"

char		g_tmp[100];

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

t_section	*create_heap_copy(t_section d)
{
	t_section	*section;
	
	section = NULL;
	section = m_alloc(sizeof(t_section), sec_to_string(g_tmp, &d));
	if (section == NULL)
	{
		_log("ERROR\tcan't allocate memory for:\t");
		_log(g_tmp);
		_log("\n");
		return (NULL);
	}
	section->x = d.x;
	section->y = d.y;
	section->len = d.len;
	return (section);
}
