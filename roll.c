
/*
 * roll.c
 *
 * Simulates dice rolls from the command line.  Can specify multiple dice rolls,
 * but must be of the format <X>d<Y>.
 *
 *
 * Command line arguments:
 *   <X>d<Y> - Dice roll, eg. 1d20, 3d6, etc.
 *
 * Author: E. Chris Pedro
 * Version: 2019-04-18
 *
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org>
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * roll_dice - Rolls dice, input must be in the format <X>d<Y>.
 * @str: the string to parse.
 */
void roll_dice(char *str)
{
  int i, n, d, sum = 0;
  sscanf(str, "%dd%d", &n, &d);

  srandomdev();
  for (i = 0; i < n; ++i)
    sum += (random() % d) + 1;
  printf("%dd%d = %d\n", n, d, sum);
}

/*
 * main 
 */
int main(int argc, char *argv[])
{
  int n, d;

  if (argc < 2)
  {
    printf("usage: %s <X>d<Y> [<X>d<Y> ...]\n", argv[0]);
    return EXIT_FAILURE;
  }

  for (--argc, ++argv; argc; --argc, ++argv)
    roll_dice(argv[0]);

  return EXIT_SUCCESS;
}


