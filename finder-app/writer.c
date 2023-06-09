#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    openlog(NULL, LOG_PERROR, LOG_USER);

    // get argument numbers (do not forget argv[0] which is the executable name)
    if(argc != 3) {
        syslog(LOG_ERR, "Requires 2 arguments:\n writefile: file to be written\n writestr: string to write");
        return 1;
    }

    FILE *fp = fopen(argv[1], "w");
    if(fp == NULL) {
        syslog(LOG_ERR, "Error opening file to write: %s", strerror(errno));
        return 1;
    }

    fprintf(fp, "%s", argv[2]);
    fclose(fp);

    return 0;
}
