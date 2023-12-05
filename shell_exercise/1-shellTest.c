#include <stdio.h>
#include "main.h"

int main() 
{
    // Example usage of shellHelper function with "/bin/ls" command
    char *args[] = {"/bin/ls", NULL};

    shellHelper(args);

    return 0;
}
