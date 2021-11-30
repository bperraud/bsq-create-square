#include "header.h"

void	ft_putstr(char *str)
{
    int		i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}


void create_file_map()
{
    char buffer[10];
    read(STDIN_FILENO, buffer, 10);         //lit l'entrée standard

    buffer[9] = '\0';

//    n = check_first_line(line);
//    nbr = ft_strdup(line);
//    if (!nbr)
//        return (0);
//    nbr[n] = '\0';
//    n = ft_atoi(nbr);
//    free(nbr);

    // commence par lire le nombre de ligne

    ft_putstr(buffer);


//    char buf[1];
//
//    char tmpname[] = "mymap.txt" ;
//    int fd;
//
//    fd = open(tmpname, O_WRONLY | O_APPEND | O_CREAT, 0644);   //0644 (owning) User: read & write * Group: read * Other: read

//    while(read(STDIN_FILENO, buf, sizeof(buf))>0) {
//        // read() here read from stdin charachter by character
//        // the buf[0] contains the character got by read()
//        write(fd, )
//    }


}