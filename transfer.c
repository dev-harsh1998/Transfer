#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

/* Implementation based on popen documentation */
bool can_run_command(const char *cmd){
if(strchr(cmd, '/')){
// if cmd includes a slash, no path search must be performed,
// go straight to checking if it's executable

/* ************************************** */
//For current linux based systems this check is useless
// but would rather be used when implementing this for windows powershell.
/* ************************************** */

return access(cmd, X_OK)==0;
}
const char *path = getenv("PATH");
if(!path) return false; // something is horribly wrong...
// we are sure we won't need a buffer any longer
char *buf = malloc(strlen(path)+strlen(cmd)+3);
if(!buf) return false; // actually useless, see comment
// loop as long as we have stuff to examine in path
for(; *path; ++path) {
// start from the beginning of the buffer
char *p = buf;
// copy in buf the current path element
for(; *path && *path!=':'; ++path,++p) {
*p = *path;
}
// empty path entries are treated like "."
if(p==buf) *p++='.';
// slash and command name
if(p[-1]!='/') *p++='/';
strcpy(p, cmd);
// check if we can execute it
if(access(buf, X_OK)==0) {
free(buf);
return true;
}
// quit at last cycle
if(!*path) break;
}
// not found
free(buf);
return false;
}

int main(int argc, char *argv[]){
/* Linux curl check */
char curl[5]="curl";
bool x;
x = can_run_command(curl);
/* Only run the uploader when curl binary is found & is executable */
if (x){
/* Argument check */
if (argc < 2){
printf ("ERROR: This binary expects atleast and only one command line argument");
/* bail out */
return -1;
}
char cmdbuf[256];
sprintf(cmdbuf,  "curl -T %s %s", argv[1], "https://transfer.sh");
system(cmdbuf);
return 0;
}
else{
printf("Either curl binary is not installed or is corrupt somehow, This binary is based on curl and can't run without it\n");
printf("Install curl by running 'sudo apt install curl' \n");
printf("ERROR\n");
return -1;
}
}