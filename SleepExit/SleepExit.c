#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int timeToSleep, exitCode;
    //argv[0] is the program name ("SleepExit.exe")
    //argc is (therefore) 1 more then the number of (real) arguments
    if (argc < 3) {
        printf("There are %d arguments, while there must be exactly 2: the time to sleep (in seconds) and the exitcode.\n", argc-1);
        return(-1);
    }
    timeToSleep = atoi(argv[1]);
    exitCode = atoi(argv[2]);
    printf("Sleeping for %d seconds and then exiting with code %d\n", timeToSleep, exitCode);
    Sleep(1000 * timeToSleep);
    if (argc == 4) {
        FILE* fp;
        #pragma warning(suppress : 4996)
        fp = fopen(argv[3], "w");
        fprintf(fp, "After having waited %d seconds and writing this line to %s, the exit code will have been %d\n", timeToSleep, argv[3], exitCode);
        fclose(fp);
    }
    return exitCode;
}