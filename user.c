#include "user.h"

int load_file(LOGIN* list[], char* filename){
#ifdef DEBUG_MODE
	printf("DEBUG: load_file\n");
#endif
  int count=0;
  int menu;
  FILE *datafile = fopen(filename, "r");
  FILE *datafile2;
  if(datafile == NULL){ //데이터 파일이 없는 경우
	printf("%s file does not exist! Make anyway?(Yes 1, No 2) >> ",filename);
	scanf("%d",&menu);
	if(menu == 1) {
	  datafile2 = fopen(filename,"wt");
	  fclose(datafile2);
	  return 0;
	}
	else return -1;
  }else{
    while(!feof(datafile)){
      list[count]=(LOGIN*)malloc(sizeof(LOGIN));
      fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
      if(strcmp(list[count]->id,"\0"))	count++; //빈 줄 skip
    }
  }
  fclose(datafile);
  return count;
}

void join(LOGIN* list[], int *count){
#ifdef DEBUG_MODE
	printf("DEGUG: join\n");
#endif
  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<*count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[*count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[*count]->id, id);
      strcpy(list[*count]->password, pass);
      printf("New user added!\n");
      *count=*count+1;
      break;
    }
  }
}

int login(LOGIN* list[], int count){
#ifdef DEBUG_MODE
	printf("DEBUG: login\n");
#endif
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return -1;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

void logout(int* is_login){
#ifdef DEBUG_MODE
	printf("DEBUG: logout\n");
#endif
  *is_login = 0;
  printf("Bye!!\n");
}

void list(LOGIN* list[], int count){
#ifdef DEBUG_MODE
	printf("DEBUG: list\n");
#endif
   printf("User list (id/password)\n");
   for(int i=0;i<count;i++){
	printf("[%d] %s %s\n",i+1,list[i]->id,list[i]->password);
   }
}

void save_file(LOGIN* list[], int count, char* filename){  
#ifdef DEBUG_MODE
	printf("DEBUG: save_file\n");
#endif
  FILE *datafile = fopen(filename, "wt");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%d records saved to %s!\n", count,filename);
  fclose(datafile);
}
