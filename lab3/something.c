#include <stdio.h>
#include <string.h>

int main () {
   
   char command[50],command1[89];
	printf("Enter the command : ");
	scanf("%s",command1);
   strcpy(command, strcat(command1, " >> shivi.txt") );
   
   system(command) ;
	
   return(0);
} 
