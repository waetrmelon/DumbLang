#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void BeginLexxer(char *buffer) {
    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        int CharacterCode = buffer[i];
        char CurrentCharacter = buffer[i];
        if (CharacterCode < 0) { return; } // Gets rid of weird things
        printf("%c %d\n", CurrentCharacter, CharacterCode);
    }
}