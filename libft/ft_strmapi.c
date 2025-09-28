/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:10:25 by moabe             #+#    #+#             */
/*   Updated: 2025/05/08 15:10:25 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	p = ft_strdup(s);
	if (!p || !s || !f)
		return (NULL);
	i = 0;
	while (p[i])
	{
		p[i] = f(i, p[i]);
		i++;
	}
	return (p);
}

// // 例として使う関数1：インデックスが偶数なら大文字に変換
// char example_func1(unsigned int i, char c) {
//     if (i % 2 == 0 && c >= 'a' && c <= 'z')
//         return c - 32; // 小文字を大文字に
//     return c;
// }

// // 例として使う関数2：インデックスを無視してすべてを 'x' にする
// char example_func2(unsigned int i, char c) {
//     (void)i;
//     (void)c;
//     return 'x';
// }

// int main(void) {
//     char *result;

//     // テスト1："abcdef" → 偶数番目だけ大文字になるか？
//     result = ft_strmapi("abcdef", example_func1);
//     if (result) {
//         printf("Test 1: %s\n", result); // A b C d E f → "AbCdEf"
//         free(result);
//     } else {
//         printf("Test 1: NULL returned\n");
//     }


//     // テスト3："hello" → 全部が 'x' になるか？
//     result = ft_strmapi("hello", example_func2);
//     if (result) {
//         printf("Test 3: %s\n", result); // "xxxxx"
//         free(result);
//     } else {
//         printf("Test 3: NULL returned\n");
//     }

//     return 0;
// }
