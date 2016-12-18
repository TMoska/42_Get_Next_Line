Get Next Line - TMoska
===

Get Next Line allows to read file from a file description line-by-line. It supports multiple files in parallel and uses only 1 static variable & 5 functions.

It is a personal project to extend my C functions library [libft](https://www.github.com/TMoska/libft). This projects has been a part of curriculum for [42 University](https://www.42.us.org) Get Next Line project.

Using function
---

```
git clone https://github.com/TMoska/get_next_line.git
```
Add this line to your C code:

```C
#include "get_next_line.h"
```

Simple example
---

This example supports one file.


```C
#include <stdio.h>
#include "get_next_line.h"

int       main(int ac, char **av)
{
  char    *line;
  int     fd;

  if (ac != 2)
    return (0);
  if (!(fd = open(av[1], O_RDONLY)))
    return (0);
  while (get_next_line(fd, &line) > 0)
    printf("%s\n", line);
  return (0);
}
```
```
gcc -Wall -Werror -Wextra get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft
./a.out <file_name>
```
Studying at 42?
---

You might be interested in checking my other repositories:
- [libft](https://www.github.com/TMoska/libft)
- [sastantua](https://github.com/TMoska/sastantua)
- [42_exams](https://github.com/TMoska/42_exams)
- [fillit](https://github.com/TMoska/fillit)
- [piscine_reloaded](https://github.com/TMoska/piscine_reloaded)

Contributing
---

If you feel like contributing or adding new functions, feel free to submit a [Pull Request](https://github.com/TMoska/get_next_line/pulls).

License
---

MIT License

Copyright (c) 2016 Tomas Moska

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
