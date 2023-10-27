#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

char buffer[512];
/* int write_string_to_file(const char *file, char *message)
{
    int fd = write(file, message, sizeof(message));

    if (fd < 0)
    {
        fprintf(1, "failed to open %s\n", file);
        exit(1);
    }

    // Tu doplnte kod

    exit(1);
}
*/
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(2, "Invalid usage! Correct usage: pfwriter <file1> <file2> <message>\n");
        exit(1);
    }

    int pid = fork();

    if (pid == 0)
    {
        int file1 = open(argv[1], O_WRONLY | O_CREATE);
        if (file1 < 0)
        {
            fprintf(2, "File sa nepodarilo otvorit");
        }
        else
        {
            /*      int dlzka = 0;

                  while (*argv[3] != '\0')
                  {
                      dlzka++;
                      argv[3]++;

                  }*/

            //      write(file1, argv[3] - dlzka, dlzka);
            write(file1, argv[3], strlen(argv[3]));

            // write_string_to_file(file2, argv[3]);
        }

        //            write_string_to_file(file1, argv[3]);
    }

    // Tu doplnte kod

    else if (pid > 0)
    {

        int file2 = open(argv[2], O_WRONLY | O_CREATE);
        if (file2 < 0)
        {
            fprintf(2, "File sa nepodarilo otvorit");
        }
        else
        {
            int dlzka = 0;

            while (*argv[3] != '\0')
            {
                dlzka++;
                argv[3]++;
                /* code */
            }

            write(file2, argv[3] - dlzka, dlzka);

            // write_string_to_file(file2, argv[3]);
        }
        // Tu doplnte kod
    }
    else
    {
        fprintf(2, "Fork Error! xD");
        exit(1);
    }

    exit(0);
}