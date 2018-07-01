#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
/* Argument check */
if (argc < 2){
printf ("ERROR: This binary expects atleast and only one command line argument");
/* bail out */
return 1;
}
char cmdbuf[256];
sprintf(cmdbuf,  "curl -T %s %s", argv[1], "https://transfer.sh");
system(cmdbuf);

return 0;
}
