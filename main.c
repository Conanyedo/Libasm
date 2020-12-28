/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:50:35 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/28 15:54:32 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/syscall.h>

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, const void *buf, size_t nbyte);
char		*ft_strdup(const char *src);

int			main(void)
{
	int			bz;
	int 		fd1;
	int			fd2;
	ssize_t		n;
	char		s[64] = "Hello, World!";
	
	
	bz = 12;
	/* 
	 * write  
	 */
	printf("\n************ write **************\n");
 	fd1 = open("test1", O_WRONLY | O_CREAT, 0644);
	fd2 = open("test2", O_WRONLY | O_CREAT, 0644);
	n = ft_write(fd1, s, bz);
	printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
	printf("errno = |%d|", errno);
	n =    write(fd2, s, bz);
	printf("\n|O| ==> the return value of    write is |%ld|\n", n);
	printf("errno = |%d|\n", errno);
	close(fd1);
	close(fd2);
// 	/*
// 	 ** read 
// 	 */
	printf("\n************ read **************\n");
 	fd1 = open("test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	fd2 = open("test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	n = ft_read(fd1, s, bz);
	printf("\n|M| ==> the return value of ft_read is |%zd| and s=|%s|\n", n, s);
	printf("errno = |%d|\n", errno);
	n =    read(fd2, s, bz);
	printf("|O| ==> the return value of    read is |%zd| and s=|%s|\n", n, s);
	printf("errno = |%d|\n", errno);
	close(fd1);
	close(fd2); 
// 	/* 
// 	 * strdup 
// 	 */
	printf("\n************ strdup **************\n");
	printf("\n|M| ==> string by ft_strdup is |%s|\n", ft_strdup(s));
	printf("|O| ==> string by    strdup is |%s|\n",  strdup(s));
// 	/* 
// 	 * strlen 
// 	 */
	printf("\n************ stren **************\n");
 	printf("\n|M| ==> Return value by ft_strlen = |%zu|\n", ft_strlen(s));
	printf("|O| ==> Return value by    strlen = |%zu|\n\n", strlen(s)); 
// 	/* 
// 	 * strcpy 
	//  */
	printf("\n************ strcpy **************\n");
	printf("\n|M| ==> the dest1 by ft_strcpy is |%s|\n", ft_strcpy(s, "How are you ?"));
	printf("|O| ==> the dest2 by    strcpy is |%s|\n\n", strcpy(s, "How are you ?"));
	/* 
// 	 * strcmp 
// 	 */
	printf("\n************ strcmp **************\n");
	char		*s1;
	char		*s2;
	s1 = malloc(12);
	s2 = malloc(12);
	s1 = "abhw";
	s2 = "abhw2";
	
	printf("\n|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp(s1, s2));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp(s1, s2));
	
	return (0);
}