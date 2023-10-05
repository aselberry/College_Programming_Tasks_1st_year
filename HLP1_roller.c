#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct ROLLER_COASTER{
     char name[31];
     char world[31];
     int height;
     int time;
}ROLLER_COASTER;

int cmp(const void *a, const void *b){
    ROLLER_COASTER *left = (ROLLER_COASTER*)a;
    ROLLER_COASTER *right = (ROLLER_COASTER*)b;

    if(left -> time != right -> time){
        return (left->time - right-> time);
    }
    if(left -> height != right -> height){
        return -(left->height - right -> height);
    }

    return strcmp(left -> name, right->name);
}

int query(ROLLER_COASTER* roller, int length){
    int min = roller[0].time;
    for(int i=1; i<length; i++){
        if(roller[i].time > min){
            min = roller[i].time;
        }
    }

    return min; 
}

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "No input file was given.\n");
        return 1;
    }
    FILE *fin = fopen(argv[1], "r");
    if(!fin){
        fprintf(stderr, "File does not exist!");
        return 2;
    }

    char n;
    int number_of_records = 0;
    char line[102];
    ROLLER_COASTER roller[20];
    int length = 0;

    if(fscanf(fin, "%c", &n) != 1) {
    fprintf(stderr, "Error reading value of n\n");
    return 5;
    }
    number_of_records = n - '0';
    while(fgets(line, 102, fin)){
        /*if(strcmp(line, "END\n") == 0){
            break;
        }*/
        line[strlen(line)-1] = '\0';
        strcpy(roller[length].name, strtok(line, ";"));
        strcpy(roller[length].world, strtok(NULL, ";"));
        roller[length].height = atoi(strtok(NULL, ";"));
        roller[length].time = atoi(strtok(NULL, ";"));
        length++;
        
    }
    
    //according to the instructions, the last line "END" should not be processed. How could we implement this condition? Is it okay if we write if(fgets(line, 102, fin) = strtok("END", ";") {
    //    break;
    //}

    fclose(fin);
    qsort(roller, length, sizeof(ROLLER_COASTER), cmp);

   if(argc<3){
        fprintf(stderr, "No output file is given");
        return 3;
    }

    FILE *fout = fopen(argv[2], "w");
    if(!fout){
        fprintf(stderr, "Output file cannot be opened");
        return 4;
    }

    for(int i=0; i< length; i++){
        fprintf(fout, "%s (%s) : %d\n", roller[i].name, roller[i].world, roller[i].time);

    }
    fclose(fout);

    printf("%d", query(roller, length));

    return EXIT_SUCCESS;
}