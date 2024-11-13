#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lexxer.h"

int main(){
   FILE *file;
   char filename[] = "C:\\Users\\cheem\\OneDrive\\Desktop\\Programming Shizzles\\MidgetAssembler\\tests\\Declare.dl";
   char *buffer = NULL; // initialize buffer to NULL
   int buffer_size = 0;
   int i = 0;

   //Open file for reading
   file = fopen(filename, "r");

   //Check if file opened successfully
   if (file  == NULL) {
      printf("Error: Failed to open file '%s'.\n", filename);
      return 1;
   }

   int c;
   while ((c = fgetc(file)) != EOF) {
      if (i >= buffer_size) {
         buffer_size += 1000;
         buffer = realloc(buffer, buffer_size);
         if (buffer == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
         }
      }
      buffer[i] = c;
      i++;
   }
   fclose(file);

   BeginLexxer(buffer);

   free(buffer);

}