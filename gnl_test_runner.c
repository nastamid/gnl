#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define COLOR_RESET "\033[0m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"

void test_end_of_file()
{
    int fd;
    char *line;

    printf(COLOR_YELLOW "Test: End of File\n" COLOR_RESET);

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening test file");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    line = get_next_line(fd);
    printf("%s", "\n");
    if (line == NULL)
        printf(COLOR_GREEN "PASS: get_next_line returned NULL at end of file.\n" COLOR_RESET);
    else
        printf(COLOR_RED "FAIL: get_next_line did not return NULL at end of file.\n" COLOR_RESET);

    close(fd);
}

void test_invalid_fd()
{
    char *line;

    printf(COLOR_YELLOW "Test: Invalid File Descriptor\n" COLOR_RESET);

    line = get_next_line(-1);

    if (line == NULL)
        printf(COLOR_GREEN "PASS: get_next_line returned NULL for invalid file descriptor.\n" COLOR_RESET);
    else
        printf(COLOR_RED "FAIL: get_next_line did not return NULL for invalid file descriptor.\n" COLOR_RESET);
}

void test_newline_included()
{
    int fd;
    char *line;

    printf(COLOR_YELLOW "Test: Line Includes Newline Character\n" COLOR_RESET);

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening test file");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] != '\0' && line[strlen(line) - 1] != '\n' && get_next_line(fd) != NULL)
        {
            printf(COLOR_RED "FAIL: Line does not end with newline when expected.\n" COLOR_RESET);
        }
        free(line);
    }

    printf(COLOR_GREEN "PASS: Newline correctly included where expected.\n" COLOR_RESET);

    close(fd);
}

int main(void)
{
    test_end_of_file();
    test_invalid_fd();
    test_newline_included();
    return 0;
}
