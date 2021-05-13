
#include <stdio.h>
int main (int argc, char* argv[]) {
    char line[256];
    FILE* fs = fopen(argv[1],"r");
    FILE* fp = fopen(argv[2],"w");
    while (fgets(line,256,fs) != NULL) {

        for (int i = 0, j; line[i] != '\0'; ++i) {
            while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == ' ') && !(line[i] == '\0')) {
                for (j = i; line[j] != '\0'; ++j) {
                    line[j] = line[j + 1];
                }
                line[j] = '\0';
            }
        }

        fprintf(fp,"%s\n",line);
    }


    return 0;
}