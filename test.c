#include <stdio.h>
#include <stdlib.h>
int main(){
    
    while(1){
        char string[6] = {0}, input;
        printf("enter string: ");
        for(int i = 0; i < 6; i++){
            input = getchar();
            if(input == '\n'){
                break;
            }
            string[i] = input;
        }
        while (input != '\n') input = getchar();
        for(int i = 0; i < 6; i++){
            printf("%d ", string[i]);
        }
    }
}