#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * multiply - Multiplies two strings containing numeric values.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 *
 * Return: A string representing the product of num1 and num2.
 */
char *multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int lenRes = len1 + len2;
	char *result;

	result = malloc(sizeof(char) * (lenRes + 1));
	if (!result)
		exit(98);
	int i, j;

	for (i = 0; i < lenRes; i++)
		result[i] = '0';
	result[lenRes] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul;
			int sum;

			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + (result[i + j + 1] - '0');
			result[i + j + 1] = (sum % 10) + '0';
			result[i + j] += sum / 10;
		}
	}
	return (result);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 98 on errors.
 */
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	char *result;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	for (int i = 0; i < _strlen(num1); i++)
		if (num1[i] < '0' || num1[i] > '9')
		{
			write(1, "Error\n", 6);
			exit(98);
		}
	for (int i = 0; i < _strlen(num2); i++)
		if (num2[i] < '0' || num2[i] > '9')
		{
			write(1, "Error\n", 6);
			exit(98);
		}
	result = multiply(num1, num2);

	int i = 0;

	while (result[i] == '0' && result[i + 1] != '\0')
		i++;
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(result);
	return (0);
}

