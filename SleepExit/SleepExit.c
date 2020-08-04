#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int timeToSleep, exitCode;
    //argv[0] is the program name ("SleepExit.exe")
    //argc is (therefore) 1 more then the number of (real) arguments
    if (argc < 3) {
        printf("There are %d arguments, while there must be exactly 2 or 3:\n", argc - 1);
        printf("  1: the time to sleep (in seconds)\n");
        printf("  2: the exitcode.\n");
        printf("  3: a filename to write too (Optional)\n");
        return(-1);
    }
    timeToSleep = atoi(argv[1]);
    exitCode = atoi(argv[2]);
    printf("Sleeping for %d seconds and then exiting with code %d\n", timeToSleep, exitCode);
    
    //Sleeping :)
    Sleep(1000 * timeToSleep);

    //Write a file?
    if (argc == 4) {
        errno_t err;
        FILE *fp;
        err = fopen_s(&fp, argv[3], "w");
        if (err != 0) {
            printf("ERROR: File %s could not be opened for writing!", argv[3]);
        }
        if (fp) {
            fprintf(fp, "After having waited %d seconds and writing this line to %s, the exit code will have been set to %d.\n", timeToSleep, argv[3], exitCode);
            err = fclose(fp);
            if (err != 0) printf("ERROR: The file could not be closed cleanly!");
        }
    }

    //Exit with desired code :)
    return exitCode;
}