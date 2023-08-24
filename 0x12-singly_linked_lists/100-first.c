#include <stdio.h>

void __attribute__((constructor)) pre_main_message(void);

/**
 * pre_main_message - Prints a message before the main function is executed.
 */

void pre_main_message(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
