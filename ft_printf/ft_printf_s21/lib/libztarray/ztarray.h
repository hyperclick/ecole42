
#ifndef ZTARRAY_H
# define ZTARRAY_H

void	ft_free_array(void **r, int n);
int		ft_count_null_term_array(void **a);
void	ft_free_array2(void ***r);
void	ft_free_null_term_array(void **a);
void	zta_remove_at(void **a, int size, int n);

#endif