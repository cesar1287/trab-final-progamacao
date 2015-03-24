#include <stdio.h>
#include <string.h>
 
int main(void) {
    char str[] = "   am,vd,vm";
    int posW = 0, posR = 0;

    for(posR = 0; posR < strlen(str); posR++) {
        if(str[posR] == ' ') 
                continue;
        str[posW] = str[posR];
        posW++;
    }
    str[posW] = '\0';
        
    printf("%s\n", str);
    return 0;
}
