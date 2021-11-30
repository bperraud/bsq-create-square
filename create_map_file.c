#include "header.h"

void create_map_file(int nb_line, char *line)
{
    char buf[BUF];
    char tmpname[] = "new_map.txt" ;
    int fd;
    int str_len;
    int i;

    i = 0;
    fd = open(tmpname, O_WRONLY | O_CREAT, 0644);   //0644 (owning) User: read & write * Group: read * Other: read
    write(fd, line, ft_strlen(line));
    write(fd, "\n", 1);
    while(i < nb_line)
    {
        read(STDIN_FILENO, buf, sizeof(buf));
        str_len = ft_strlen_input(buf);
        if(!ft_strncmp(buf, "quit()\n", 6))
            exit(EXIT_SUCCESS);
        if(!ft_strncmp(buf, "end\n", 3))
            break;
        write(fd, &buf, str_len);
        i++;
    }
    close(fd);
}


void standard_input_map(int isfirst)
{
    if (isfirst)
        ft_putstr("Write number of line followed by the characters : (quit() to exit)\n");
    char buffer[50];
    char *line;

    read(STDIN_FILENO, buffer, 50);
    buffer[ft_strlen_input(buffer) - 1] = '\0';
    if(!ft_strncmp(buffer, "quit()\n", 6))
        exit(EXIT_SUCCESS);
    line = ft_strdup(buffer);
    if (!line){
        exit(EXIT_SUCCESS);
    }
    if (!check_first_line(buffer))
    {
        ft_putstr("Wrong input\n");
        standard_input_map(0);
    }
    else
        create_map_file(ft_atoi(buffer), line);
}