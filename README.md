<h1 align="center" id="title">get_next_line</h1>

<p align="center"><img src="https://socialify.git.ci/nkarapet42/get_next_line/image?font=KoHo&language=1&logo=https%3A%2F%2Fgithub.com%2Fnkarapet42%2Fget_next_line%2Fassets%2F157054887%2F26b7d94a-ccc6-4306-8d8d-1db92a1aa18d&name=1&owner=1&pattern=Brick%20Wall&theme=Light" alt="get_next_line"/></p>

## Grade: 125/100

### Description
get_next_line is a function written in the C programming language designed to read and output lines from a file one line at a time. It serves as a useful tool for processing text files, especially those too large to be loaded into memory all at once.

## How to Use

Include get_next_line.h in your project.</br>
Call the get_next_line function with the file descriptor as a parameter.</br>
The function will return the next line from the file on each call.</br>

### Basic Usage
For example, let's create a ``main.c`` file.

```c
// Include the header
#include "get_next_line.h"
#include "get_next_line_bonus.h"
// Include for printf
#include <stdio.h>

int main(void)
{
      int  fd;
      int  df;

      fd = open("filename", O_RDONLY);
      df = open("filename2", O_RDONLY)
      // Call the function
      printf("%s", get_next_line(fd));
      printf("%s", get_next_line_bonus(df));
      printf("%s", get_next_line_bonus(fd));
      return (0);
}
```

Compile the ``main.c`` file with the `*.c` and run the program:
```bash
cc main.c *.c && ./a.out
```
Output should be:
```
filname 1-st line
filname2 1-st line
filname 2-nd line
```
