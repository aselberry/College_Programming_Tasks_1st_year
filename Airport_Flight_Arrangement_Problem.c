#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AIRPORT{
    char name[31];
    char city[31];
    int runways;
    int time;
}AIRPORT;

int compare(const void *a, const void *b){
    AIRPORT* left = (AIRPORT*)a;
    AIRPORT* right = (AIRPORT*)b;
    if(left -> runways != right -> runways){
        return -(left -> runways - right -> runways);
    }

    if(left -> time != right -> time){
        return -(left -> time - right -> time);
    }
    return strcmp(left -> name, right -> name);
}

int query(AIRPORT * airports, int length){
    int max = 0;
    for(int i=0; i<length;i++){
        if(airports[i].runways > max){
            max = airports[i].runways;
        }
    }

    return max;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        fprintf(stderr, "No input file is given! ");
        return 1;
    }
    FILE* fin = fopen(argv[1], "r");

    if(!fin){
        fprintf(stderr, "File Does not exist! ");
        return 2;
    } 

    AIRPORT airports[20];
    char line[102];
    int length = 0;

    while(fgets(line, 102, fin)){
        if(strcmp(line, "END\n") ==0){
            break;
        }
        line[strlen(line)-1] = '\0';
        strcpy(airports[length].name, strtok(line, ";"));
        strcpy(airports[length].city, strtok(NULL, ";"));
        airports[length].runways = atoi(strtok(NULL, ";"));
        airports[length].time = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(fin);

    qsort(airports, length, sizeof(AIRPORT), compare);

    if(argc < 3){
        fprintf(stderr, "Output file is not given! ");
        return 3;
    }

    FILE* fout = fopen(argv[2], "w");

    if(!fout){
        fprintf(stderr, "Output File cannot be opened! ");
        return 4;
    }

    for(int i = 0; i<length; i++){
        fprintf(fout, "%s;%s;%d;%d\n", airports[i].name, airports[i].city, airports[i].runways, airports[i].time);
    }
    fclose(fout);

    printf("%d", query(airports, length));

    return EXIT_SUCCESS;
}

//DO not forget of using string.h what you are tokenizing the strings. Query - when you are dealing with objects, you need to specify to which part of the object you are referring to! 

//line[102] - the reason of putting 102not 100 is because of the terminating null character that is added in the string character arrays as well as at the end of fgets. Therefore, because of these two additional null terminator characters, we are storing 102 elements to ensure that we can get atmost 100 desired characters form the input file! 

//If you indicate the type of the function with the asterx or as a pointer, you return value is also going to be a pointer/array
