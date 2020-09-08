#include <stdio.h>

int main() {

         char command[200];
         
         while(1){
                  fgets(command, sizeof(command),stdin);
                  if(strcmp("exit\n",command)==0)
                       break;
                       
                  fork();
                  system(command);
         
         }

}
