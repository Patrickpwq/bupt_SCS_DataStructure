#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * convert(char * s, int numRows){
    if (numRows == 1) {
        return s;
    }
    int len = strlen(s);
    char *convertString = malloc(len + 1);
    char map[numRows][len];
    memset(map, -1, sizeof(map));
    int i, j, count;
    i = j = count = 0;
    int direction = 1; //0 for up, 1 for down
    while (count < len) {
        map[i][j] = s[count];
        count++;
        if (direction == 1) {
            if (i == numRows - 1) { //at the bottom
                direction = 0;
                i -= 1;
                j += 1;
            }
            else {
                i += 1;
            }   
        }
        else {
            if (i == 0) {   //at the top
                direction = 1;
                i += 1;
            }
            else {
                i -= 1;
                j += 1;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] != -1) {
                convertString[k++] = map[i][j];
            }
        }
    }
    convertString[k] = '\0';
    return convertString;
}

int main()
{
    char s[1001] = "ABCD";
    int numRows = 1;
    printf("%s", convert(s, numRows));
}