#include <stdio.h>
#include<stdlib.h>
int etc(FILE *src,FILE *dest);
int ead(FILE *src,FILE *dest);
int ets(FILE *src,FILE *dest);

int main(int argc, const char *argv[])
{
   // int *src = NULL;
   // int *dest = NULL;
    FILE *src = fopen(argv[1],"r");
    FILE *dest = fopen(argv[2],"w");
 /*   if(!src){
         fclose(src);
         printf("Faile to open!\n");
         return 0;
    }
    if(!dest){
         fclose(dest);
         printf("Faile to open!\n");
         return 0;
    }*/
         
//  while(1){
    printf("1.cp by char\n");
    printf("2.cp by record\n");
    printf("3.cp by row\n");
    printf("Your choice:");
    int a;
    scanf("%d",&a);
   // while(1){
       switch(a){
          case 1:
           etc(src,dest);break;
          case 2:
           ead(src,dest);break;
          case 3:
           ets(src,dest);break;
          default:
                   exit(0);
       }

   // }
    fclose(src);
    fclose(dest);
/*if(!src){
            fclose(src);
              printf("Faile to open!\n");
               return 0;
           }
            if(!dest){
                  fclose(dest);
                   printf("Faile to open!\n");
                    return 0;
                }
*/
    
    
    return 0;

}
int etc(FILE *src,FILE *dest){
   int ch;
   /*
   ch = fgetc(src);
   while(!feof(src)){
    fputc(ch,dest);
    ch = fgetc(src);
    */
   // fputc(ch,dest);
   while( (ch = fgetc(src)) != EOF){
    
        if( fputc(ch,dest) == EOF)break;
   
   }

  return 0;
}

int ead(FILE *src,FILE *dest){
   char j[1024] = {0};
   while(!feof(src)){
    fread(j,1,1,src);
    fwrite(j,1,1,dest);
  }
   return 0;
}

int ets(FILE *src,FILE *dest){
   char k[1024] = {0};
   while(fgets(k,sizeof(k),src)!=NULL){
   fputs(k,dest);
  } 
  return 0;
}
