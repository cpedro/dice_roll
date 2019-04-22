#!/usr/bin/env python3
"""
roll.py

Simulates dice rolls from the command line.  Can specify multiple dice rolls,
but must be of the format <X>d<Y>.

Command line arguments:
    <X>d<Y> - Dice roll, eg. 1d20, 3d6, etc.

Author: E. Chris Pedro
Version: 2019-04-22

Some code taken from Mike Pound's script that does the same.  Mike's script
can be found here: <https://github.com/mikepound/pwned-search>

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
"""

import sys

from random import SystemRandom
gen = SystemRandom()


def roll(dice):
    s = 0

    n, d = map(int, dice.split('d'))
    for i in range(n):
        s += (gen.randint(1, d))
    print('{0}d{1} = {2}'.format(n, d, s))


if __name__ == '__main__':
    for dice in sys.argv[1:]:
        roll(dice)


