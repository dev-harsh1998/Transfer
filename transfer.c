/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Copyright (C) 2018, Harshit Jain
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef GET_FILE_SIZE
/* ISSUE 1 File size */
#include <sys/stat.h>
#include <sys/types.h>
#endif

/* Implementation based on popen documentation */
bool can_run_command(const char *cmd) {
    if (strchr(cmd, '/')) {
        // if cmd includes a slash, no path search must be performed,
        // go straight to checking if it's executable

        /* ************************************** */
        // For current linux based systems this check is useless
        // but would rather be used when implementing this for windows
        // powershell.
        /* ************************************** */

        return access(cmd, X_OK) == 0;
    }
    const char *path = getenv("PATH");
    if (!path)
        return false; // something is horribly wrong...
    // we are sure we won't need a buffer any longer
    char *buf = malloc(strlen(path) + strlen(cmd) + 3);
    if (!buf)
        return false; // actually useless, see comment
    // loop as long as we have stuff to examine in path
    for (; *path; ++path) {
        // start from the beginning of the buffer
        char *p = buf;
        // copy in buf the current path element
        for (; *path && *path != ':'; ++path, ++p) {
            *p = *path;
        }
        // empty path entries are treated like "."
        if (p == buf)
            *p++ = '.';
        // slash and command name
        if (p[-1] != '/')
            *p++ = '/';
        strcpy(p, cmd);
        // check if we can execute it
        if (access(buf, X_OK) == 0) {
            free(buf);
            return true;
        }
        // quit at last cycle
        if (!*path)
            break;
    }
    // not found
    free(buf);
    return false;
}

int main(int argc, char *argv[]) {
    /* Linux curl check */
    char curl[5] = "curl";
    bool x;
    x = can_run_command(curl);
    /* Only run the uploader when curl binary is found & is executable */
    if (x) {
        /* Argument check */
        if (argc != 2) {
            printf("ERROR: This binary expects atleast and only one command "
                   "line argument\n");
            /* bail out */
            return -1;
        }

#ifdef GET_FILE_SIZE
        if (getenv("TRANSFER_DISABLE_FILESIZE") == NULL) {
            struct stat st;
            stat(argv[1], &st);
            // convert bytes to mb (devide by 1024*1024)
            float mb = st.st_size / 1048576;
            printf("The size of the file going to be uploaded is near to %.2f "
                   "megabytes\n",
                   mb); 
        }
#endif

        char cmdbuf[256];
        int ret;

#ifdef PROGRESS_BAR
        sprintf(cmdbuf, "curl --progress-bar -T %s %s | tee /dev/null", argv[1], "https://transfer.sh");
#else
        sprintf(cmdbuf, "curl -T %s %s", argv[1], "https://transfer.sh");
#endif

        ret = system(cmdbuf);
        printf("\n");
        return ret;
    } else {
        printf("Either curl binary is not installed or is corrupt somehow, "
               "This binary is based on curl and can't run without it\n");
        printf("Install curl from source or with the package manager of your "
               "choice \n");
        printf("ERROR\n");
        return -1;
    }
}
