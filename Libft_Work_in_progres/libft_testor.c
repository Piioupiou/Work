/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_testor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:20:55 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/21 19:47:23 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <xlocale.h>
#include "libft.h"

int		main(void)
{
	char	str[256];

	printf("\n>--------------------------------------------------------------------<\n\n");
	printf("function: ");
	scanf("%s", str);
	ft_putchar('\n');
/*
**	MEMSET
*/
	if (strcmp(str, "memset") == 0)
	{
		char			b[256];
		char			*b2;
		char			c;
		char			c2;
		int				len;
		int				len2;

		printf("void	*memset(void *b, int c, size_t len);\n");
		printf("b = ");
		scanf("%s", b);
		printf("c = ");
		scanf("%s", &c);
		printf("len = ");
		scanf("%d", &len);
		b2 = strdup(b);
		c2 = c;
		len2 = len;
		printf("\nmemset(\"%s\", '%c', %d) :\n", b, c, len);
		printf("%s\n", (char *)memset(b, c, len));
		printf("b = %s\n", b);
		printf("\nft_memset(\"%s\", '%c', %d) :\n", b2, c2, len2);
		printf("%s\n", (char *)ft_memset(b2, c2, len2));
		printf("b = %s\n", b2);
		free(b2);
	}
/*
**	BZERO
*/
	else if (strcmp(str, "bzero") == 0)
	{
		char			s[256];
		char			*s2;
		int				n;
		int				n2;
		int				len;
		int				i;

		printf("void	bzero(void *s, size_t n);\n");
		printf("s = ");
		scanf("%s", s);
		printf("n = ");
		scanf("%d", &n);
		len = ((int)ft_strlen(s) + 1 > n) ? (int)ft_strlen(s) + 1 : n;
		s2 = strdup(s);
		n2 = n;
		printf("\nbzero(\"%s\", %d) :\n", s, n);
		bzero(s, n);
		i = 0;
		while (i < len)
		{
			printf("s[%d] = '%c'\n", i, s[i]);
			i++;
		}
		printf("\nft_bzero(\"%s\", %d) :\n", s2, n2);
		ft_bzero(s2, n2);
		i = 0;
		while (i < len)
		{
			printf("s[%d] = '%c'\n", i, s2[i]);
			i++;
		}
		free(s2);
	}
/*
**	MEMCPY

	else if (strcmp(str, "memcpy") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		n;
		int		n2;

		printf("void	*memcpy(void *s1, const void *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nmemcpy(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%s\n", (char *)memcpy(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_memcpy(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
		printf("%s\n", (char *)ft_memcpy(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	} */
/*
**	MEMCCPY

	else if (strcmp(str, "memccpy") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		c;
		int		c2;
		int		n;
		int		n2;

		printf("void	*memccpy(void *s1, const void *s2, int c, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("c = ");
		scanf("%d", &c);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		c2 = c;
		n2 = n;
		printf("\nmemccpy(\"%s\", \"%s\", %d, %d) :\n", s1, s2, c, n);
		printf("%s\n", (char *)memccpy(s1, s2, c, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_memccpy(\"%s\", \"%s\", %d, %d) :\n", s12, s22, c2, n2);
		printf("%s\n", (char *)ft_memccpy(s12, s22, c2, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	MEMMOVE

	else if (strcmp(str, "memmove") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		n;
		int		n2;

		printf("void	*memmove*(void *s1, const *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s",s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nmemmove(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%s\n", (char *)memmove(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_memmove(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
		printf("%s\n", (char *)ft_memmove(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	MEMCHR

	else if (strcmp(str, "memchr") == 0)
	{
		char			s[256];
		char			*s2;
		char			c;
		char			c2;
		int				n;
		int				n2;

		printf("void	*memchr(void *s, int c, size_t n);\n");
		printf("s = ");
		scanf("%s", s);
		printf("c = ");
		scanf("%s", &c);
		printf("n = ");
		scanf("%d", &n);
		s2 = strdup(s);
		c2 = c;
		n2 = n;
		printf("\nmemchr(\"%s\", '%c', %d) :\n", s, c, n);
		printf("%s\n", (char *)memchr(s, c, n));
		printf("s = %s\n", s);
		printf("\nft_memchr(\"%s\", '%c', %d) :\n", s2, c2, n2);
		printf("%s\n", (char *)ft_memchr(s2, c2, n2));
		printf("s = %s\n", s2);
		free(s2);
	}

**	MEMCMP

	else if (strcmp(str, "memcmp") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		n;
		int		n2;

		printf("int	memcmp(const void *s1, const void *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nmemcmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%d\n", memcmp(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_memcmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
		printf("%d\n", ft_memcmp(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}*/
/*
**	STRLEN
*/
	else if (strcmp(str, "strlen") == 0)
	{
		char	s[256];
		char	*s2;

		printf("size_t	strlen(const char *s);\n");
		printf("s = ");
		scanf("%s", s);
		s2 = strdup(s);
		printf("\nstrlen(\"%s\") :\n", s);
		printf("%d\n", (int)strlen(s));
		printf("s = %s\n", s);
		printf("\nft_strlen(\"%s\") :\n", s2);
		printf("%d\n", (int)ft_strlen(s2));
		printf("s = %s\n", s2);
		free(s2);
	}
/*
**	STRDUP

	else if (strcmp(str, "strdup") == 0)
	{
		char	s1[256];
		char	*s12;
		char	*sdup;

		printf("char	*strdup(const char *s1);\n");
		printf("s1 = ");
		scanf("%s", s1);
		s12 = strdup(s1);
		printf("\nstrdup(\"%s\") :\n", s1);
		printf("%s\n", sdup = strdup(s1));
		free(sdup);
		printf("\nft_strdup(\"%s\") :\n", s12);
		printf("%s\n", sdup = strdup(s12));
		free(sdup);
	}

**	STRCPY

	else if (strcmp(str, "strcpy") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;

		printf("char	*strcpy(char *s1, const char *s2);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		s12 = strdup(s1);
		s22 = strdup(s2);
		printf("\nstrcpy(\"%s\", \"%s\") :\n", s1, s2);
		printf("%s\n", strcpy(s1, s2));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strcpy(\"%s\", \"%s\") :\n", s12, s22);
		printf("%s\n", ft_strcpy(s12, s22));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	STRNCPY

	else if (strcmp(str, "strncpy") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		n;
		int		n2;

		printf("char	*strncpy(char *s1, const char *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nstrncpy(\"%s\", \"%s\") :\n", s1, s2);
		printf("%s\n", strncpy(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strncpy(\"%s\", \"%s\") :\n", s12, s22);
		printf("%s\n", ft_strncpy(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	STRCAT

	else if (strcmp(str, "strcat") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;

		printf("char	*strcat(char *s1, const char *s2);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		s12 = strdup(s1);
		s22 = strdup(s2);
		printf("\nstrcat(\"%s\", \"%s\") :\n", s1, s2);
		printf("%s\n", strcat(s1, s2));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strcat(\"%s\", \"%s\") :\n", s12, s22);
		printf("%s\n", ft_strcat(s12, s22));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	STRNCAT

	else if (strcmp(str, "strncat") == 0)
	{
		char	s1[256];
		char	*s12;
		char	s2[256];
		char	*s22;
		int		n;
		int		n2;

		printf("char	*strncat(char *s1, const char *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nstrncat(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%s\n", strncat(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strncat(\"%s\", \"%s\", %d) :\n", s12, s22, n);
		printf("%s\n", ft_strncat(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s12);
		free(s22);
	}

**	STRLCAT

	else if (strcmp(str, "strlcat") == 0)
	{
		char	dst[256];
		char	*dst2;
		char	src[256];
		char	*src2;
		int		size;
		int		size2;

		printf("char	*strlcat(char *dst, const char *src, size_t size);\n");
		printf("dst = ");
		scanf("%s", dst);
		printf("src = ");
		scanf("%s", src);
		printf("size = ");
		scanf("%d", &size);
		dst2 = strdup(dst);
		src2 = strdup(src);
		size2 = size;
		printf("\nstrlcat(\"%s\", \"%s\", %d) :\n", dst, src, size);
		printf("%d\n", (int)strlcat(dst, src, size));
		printf("dst = %s\n", dst);
		printf("src = %s\n", src);
		printf("\nft_strlcat(\"%s\", \"%s\", %d) :\n", dst2, src2, size2);
		printf("%d\n", (int)ft_strlcat(dst2, src2, size));
		printf("dst = %s\n", dst2);
		printf("src = %s\n", src2);
		free(dst2);
		free(src2);
	}

**	STRCHR

	else if (strcmp(str, "strchr") == 0)
	{
		char			s[256];
		char			*s2;
		char			c;
		char			c2;

		printf("char	*strchr(const char *s, int c);\n");
		printf("s = ");
		scanf("%s", s);
		printf("c = ");
		scanf("%s", &c);
		s2 = strdup(s);
		c2 = c;
		printf("\nstrchr(\"%s\", '%c') :\n", s, c);
		printf("%s\n", strchr(s, c));
		printf("s = %s\n", s);
		printf("\nft_strchr(\"%s\", '%c') :\n", s2, c2);
		printf("%s\n", ft_strchr(s2, c2));
		printf("s = %s\n", s2);
		free(s2);
	}

**	STRRCHR

	else if (strcmp(str, "strrchr") == 0)
	{
		char			s[256];
		char			*s2;
		char			c;
		char			c2;

		printf("char	*strrchr(const char *s, int c);\n");
		printf("s = ");
		scanf("%s", s);
		printf("c = ");
		scanf("%s", &c);
		s2 = strdup(s);
		c2 = c;
		printf("\nstrrchr(\"%s\", '%c') :\n", s, c);
		printf("%s\n", strrchr(s, c));
		printf("s = %s\n", s);
		printf("\nft_strrchr(\"%s\", '%c') :\n", s2, c2);
		printf("%s\n", ft_strrchr(s2, c2));
		printf("s = %s\n", s2);
		free(s2);
	}

**	STRSTR

	else if (strcmp(str, "strstr") == 0)
	{
		char			s1[256];
		char			*s12;
		char			s2[256];
		char			*s22;

		printf("char	*strstr(const char *s1, const char *s2);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		s12 = strdup(s1);
		s22 = strdup(s2);
		printf("\nstrstr(\"%s\", \"%s\") :\n", s1, s2);
		printf("%s\n", strstr(s1, s2));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strstr(\"%s\", \"%s\") :\n", s12, s22);
		printf("%s\n", ft_strstr(s12, s22));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s22);
	}

**	STRNSTR

	else if (strcmp(str, "strnstr") == 0)
	{
		char			s1[256];
		char			*s12;
		char			s2[256];
		char			*s22;
		int				n;
		int				n2;

		printf("char	*strnstr(const char *s1, const char *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nstrnstr(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%s\n", strnstr(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strnstr(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
		printf("%s\n", ft_strnstr(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s22);
	}

**	STRCMP

	else if (strcmp(str, "strcmp") == 0)
	{
		char			s1[256];
		char			*s12;
		char			s2[256];
		char			*s22;

		printf("int	strcmp(const char *s1, const char *s2);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s", s2);
		s12 = strdup(s1);
		s22 = strdup(s2);
		printf("\nstrcmp(\"%s\", \"%s\") :\n", s1, s2);
		printf("%d\n", strcmp(s1, s2));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strcmp(\"%s\", \"%s\") :\n", s12, s22);
		printf("%d\n", ft_strcmp(s12, s22));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s22);
	}

**	STRNCMP

	else if (strcmp(str, "strncmp") == 0)
	{
		char			s1[256];
		char			*s12;
		char			s2[256];
		char			*s22;
		int				n;
		int				n2;

		printf("int	strncmp(const char *s1, const char *s2, size_t n);\n");
		printf("s1 = ");
		scanf("%s", s1);
		printf("s2 = ");
		scanf("%s2", s2);
		printf("n = ");
		scanf("%d", &n);
		s12 = strdup(s1);
		s22 = strdup(s2);
		n2 = n;
		printf("\nstrncmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
		printf("%d\n", strncmp(s1, s2, n));
		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		printf("\nft_strncmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
		printf("%d\n", ft_strncmp(s12, s22, n2));
		printf("s1 = %s\n", s12);
		printf("s2 = %s\n", s22);
		free(s22);
	}

**	ATOI

	else if (strcmp(str, "atoi") == 0)
	{
		char			s[256];
		char			*s2;

		printf("int	atoi(const char *str);\n");
		printf("s = ");
		scanf("%s", s);
		s2 = strdup(s);
		printf("\natoi(\"%s\") :\n", s);
		printf("%d\n", atoi(s));
		printf("\nft_atoi(\"%s\") :\n", s2);
		printf("%d\n", ft_atoi(s2));
	}

**	ISALPHA
*/
	else if (strcmp(str, "isalpha") == 0)
	{
		char			c;
		char			c2;

		printf("int	isalpha(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\nisalpha('%c') :\n", c);
		printf("%d\n", isalpha(c));
		printf("\nft_isalpha('%c') :\n", c2);
		printf("%d\n", ft_isalpha(c2));
	}
/*
**	ISDIGIT
*/
	else if (strcmp(str, "isdigit") == 0)
	{
		char		c;
		char		c2;

		printf("int	isdigit(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\nisdigit('%c') :\n", c);
		printf("%d\n", isdigit(c));
		printf("\nft_isdigit('%c') :\n", c2);
		printf("%d\n", ft_isdigit(c2));
	}
/*
**	ISALNUM
*/
	else if (strcmp(str, "isalnum") == 0)
	{
		char		c;
		char		c2;

		printf("int	isalnum(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\nisalnum('%c') :\n", c);
		printf("%d\n", isalnum(c));
		printf("\nft_isalnum('%c') :\n", c2);
		printf("%d\n", ft_isalnum(c2));
	}
/*
**	ISASCII
*/
	else if (strcmp(str, "isascii") == 0)
	{
		char		c;
		char		c2;

		printf("int	isascii(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\nisascii('%c') :\n", c);
		printf("%d\n", isascii(c));
		printf("\nft_isascii('%c') :\n", c2);
		printf("%d\n", ft_isascii(c2));
	}

/*
**	ISPRINT
*/
	else if (strcmp(str, "isprint") == 0)
	{
		char		c;
		char		c2;

		printf("int	isprint(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\nisprint('%c') :\n", c);
		printf("%d\n", isprint(c));
		printf("\nft_isprint('%c') :\n", c2);
		printf("%d\n", ft_isprint(c2));
	}
/*
**	TOUPPER
*/
	else if (strcmp(str, "toupper") == 0)
	{
		char		c;
		char		c2;

		printf("int toupper(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\ntoupper('%c') :\n", c);
		printf("%c\n", (char)toupper(c));
		printf("c = %c\n", c);
		printf("\nft_toupper('%c') :\n", c2);
		printf("%c\n", (char)ft_toupper(c2));
		printf("c = %c\n", c2);
	}
/*
**	TOLOWER
*/
	else if (strcmp(str, "tolower") == 0)
	{
		char		c;
		char		c2;

		printf("int tolower(int c);\n");
		printf("c = ");
		scanf("%s", &c);
		c2 = c;
		printf("\ntolower('%c') :\n", c);
		printf("%c\n", (char)tolower(c));
		printf("c = %c\n", c);
		printf("\nft_tolower('%c') :\n", c2);
		printf("%c\n", (char)ft_tolower(c2));
		printf("c = %c\n", c2);
	}
	else
		printf("This function does not exist.\n");
	main();
	return (0);
}
