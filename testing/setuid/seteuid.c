#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static uid_t euid, uid;

int main(int argc, char *argv[]){
    FILE *file;
    
    /* get the current real and effective user IDs */
    uid = getuid();
    euid = geteuid();
    /* drop privilege */
    seteuid(uid);
    printf("%d, %d\n", uid, euid);
    /* raise privilege */
    //seteuid(euid);
    file = fopen("test.txt", "a");
    fprintf(file, "Someone used this file.\n");
    /* drop privilege */
    seteuid(uid);
    fclose(file);
    
    return 0;
}
