#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void test_from_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error when opening file");
        return;
    }

    printf("\nReading file: %s\n\n", filename);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
	{
        printf("%s\n", line);
        free(line);
    }

    if (close(fd) < 0) perror("Error closing file");
	
	printf("\n---------------------------------------------------\n");

}

void test_from_stdin()
{
    printf("\nTEST FROM STDIN:\nType anything:\n");
    char *line;
    if ((line = get_next_line(STDIN_FILENO)) != NULL) {
        printf("\nRead line: %s\n", line);
        free(line);
    }
	printf("\n---------------------------------------------------\n");

}

int main(void) 
{
	printf("\n---------------------------------------------------\n");
    //test_from_file("smol_file.txt");

    //test_from_file("enormous_file.txt");
        int fd = open("empty_file.txt", O_RDONLY);
		char *name = "empty_file.txt";
        char *line;
		/* 1 */ printf("should: 0: then: %s",line = get_next_line(fd));
        free(line);
		/* 2 */ printf("should: (null): then: %s",line = get_next_line(fd));
        free(line);
		// set the next read call to return -1
        char *temp;
        do {
            temp = get_next_line(fd);
            free(temp);
        } while (temp != NULL);
		/* 3 */ printf("should: (null): then: %s\n",line = get_next_line(fd));
        close(fd);

    //test_from_file("empty_file.txt");

    //test_from_stdin();

/*     printf("\nINVALID INPUT TEST:\n");
    char *line = get_next_line(-1);
    if (!line) {
        printf("get_next_line returned NULL (as it should).\n");
    } else {
        printf("Error: NULL expected (A line was received instead).\n");
        free(line);
    }
	printf("\n---------------------------------------------------\n");
 */

    return 0;
}
