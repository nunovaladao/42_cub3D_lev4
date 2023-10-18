/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:13:34 by nsoares-          #+#    #+#             */
/*   Updated: 2023/03/07 22:32:47 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * nmemb);
	return (ptr);
}

/*int main()
{
    int i, n;
    int *a;

    printf("Number of elements to be entered:");
    scanf("%d",&n);

    a = (int*)ft_calloc(n, sizeof(int));
    
    printf("Enter %d numbers:\n",n);
    for( i=0 ; i < n ; i++ ) {
        scanf("%d",&a[i]);
    }

    printf("The numbers entered are: ");
    for( i=0 ; i < n ; i++ ) {
        printf("%d ",a[i]);
    }
}*/
