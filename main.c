#include "minishell.h"

//!made to test how functions work
//!made to test how functions work
//!made to test how functions work
//!made to test how functions work
//!made to test how functions work

#define IN 1
#define OUT 0

size_t		ft_count_words(const char *str, int c)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	if (!str)
		return (count);
	while (*str)
	{
		if (*str != c)
		{
			tmp = (unsigned char*)str;
			while (*tmp != c && *tmp)
				tmp++;
			count++;
			tmp--;
			str = (char *)tmp;
		}
		str++;
	}
	return (count);
}

static char			**free_splitted_str(char **str, long pos)
{
	while (pos >= 0)
		free(str[pos--]);
	free(str);
	str = NULL;
	return (str);
}

static long			count_letters_in_word(char const *s, long *offset, char dil)
{
	int		is_in_word;
	long	counter;
	long	start;

	counter = 0;
	start = 0;
	is_in_word = OUT;
	while (s[start] != '\0')
	{
		if (s[start] != dil)
		{
			if (is_in_word == OUT)
				*(offset) += start;
			is_in_word = IN;
			counter++;
		}
		else if (is_in_word == IN)
			break ;
		start++;
	}
	return (counter);
}

char				**ft_strsplit1(char const *str, char c)
{
	long	nbr_of_words;
	long	i;
	char	**splitted_str;
	long	nbr_of_letters;
	long	offset;

	i = 0;
	offset = 0;
	if (str == NULL)
		return (NULL);
	nbr_of_words = ft_count_words(str, c);
	if (!(splitted_str = (char**)malloc(sizeof(char*) * nbr_of_words + 1)))
		return (NULL);
	while (i < nbr_of_words)
	{
		nbr_of_letters = count_letters_in_word(str, &offset, c);
		str += offset;
		if (!(splitted_str[i] = ft_strsub(str, 0, nbr_of_letters)))
			return (free_splitted_str(splitted_str, i));
		str += nbr_of_letters;
		offset = 0;
		i++;
	}
	splitted_str[i] = NULL;
	return (splitted_str);
}


int	main(int ac, char **args, char **envp)
{
	char	**str;
	char *line;

	line  = ft_strdup("ASD ;zxc");
	str = ft_strsplit1(line, ';');
	free(line);
	int i = 0;
	while (str[i])
	{
		ft_putendl(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
