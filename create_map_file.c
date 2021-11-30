#include "header.h"

void create_map_file(int nb_line, char *line)
{
    char buf[BUF];
    char tmpname[] = "new_map.txt" ;
    int fd;
    int str_len;
    int i;

    //ft_putstr("Write number of line followed by the caracters : (quit() to exit, end when finish)\n");
    //fd = open(tmpname, O_WRONLY | O_APPEND | O_CREAT, 0644);   //0644 (owning) User: read & write * Group: read * Other: read
    i = 0;
    fd = open(tmpname, O_WRONLY | O_CREAT, 0644);   //0644 (owning) User: read & write * Group: read * Other: read
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
        ft_putstr("Write number of line followed by the caracters : (quit() to exit)\n");
    char buffer[50];
    int nb_line;
    char *line;
    read(STDIN_FILENO, buffer, 50);         //lit l'entrée standard
    buffer[ft_strlen_input(buffer)] = '\0';

    ft_putstr(buffer);

    if(!ft_strncmp(buffer, "quit()\n", 6))
        exit(EXIT_SUCCESS);
    nb_line = check_first_line(buffer);
    line = ft_strdup(buffer);
    if (!line){
        exit(EXIT_SUCCESS);
    }
    if (!nb_line)
    {
        ft_putstr("Wrong input\n");
        standard_input_map(0);
    }
    else
        create_map_file(nb_line, line);
}

//void create_map_file(int nb_line, char *line)
//{
//    line[nb_line] = '\0';
//    nb_line = ft_atoi(line);
//    free(line);
//    ft_putstr(line);
