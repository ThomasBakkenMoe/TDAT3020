#include <stdio.h>
#include <string.h>

const char* stringReplace(char input[20]) {
    char output[100];

    int i;

    int offset = 0;

    for(i = 0; i < (sizeof(input)/sizeof(input[0])); i++){

        switch(input[i]){

            case '&':
                output[i + offset] = '&';
                output[i + offset + 1] = 'a';
                output[i + offset + 2] = 'm';
                output[i + offset + 3] = 'p';
                output[i + offset + 4] = ';';
                offset = offset + 5;

                break;
            
            case '<':
                output[i + offset] = '&';
                output[i + offset + 1] = 'l';
                output[i + offset + 2] = 't';
                output[i + offset + 3] = ';';
                offset = offset + 4;

                break;

            case '>':
                output[i + offset] = '&';
                output[i + offset + 1] = 'g';
                output[i + offset + 2] = 't';
                output[i + offset + 3] = ';';
                offset = offset + 4;

                break;
            
            default:
                output[i + offset] = input[i];
                break;

        }
    }

    return output;
}

int main() {
    char input[20];
    printf("Please enter your input (20 characters max)");
    scanf("%s", input);
    printf("Your input is: %s\n", input);
    printf("Your alterd input: %s\n", stringReplace(input));

    return 0;
}