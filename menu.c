#include "menu.h"

int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
#ifdef DEBUG_MODE
	printf("DEBUG: ask_menu\n");
#endif
  int menu;
  int i = 0;
  char *p;
  char com[100];
  while(1){
    if(is_login==0){
  	printf("> ");
  	scanf("%s",com);
	if(strcmp("join",com)==0){
	  menu = 1; 
	  break;
	}else if(strcmp("login",com)==0) {
	  menu = 2; 
	  break;
	}else if(strcmp("list",com)==0) {
	  menu = 4; 
	  break;
	}else if(strcmp("exit",com)==0) {
	  menu =0; 
	  break;
	}else printf("No such Command!\n");
    }else if(is_login==-1){
	menu = -1;
	break;
    }else{
	printf("# ");
	if(i == 0) {
	  getchar();
	  i++;
	}
	fgets(com,sizeof(com),stdin);
	if((p=strchr(com,'\n'))!= NULL) *p ='\0';
	if(strcmp("logout",com)==0) {
	  menu = 3; 
	  break;
	}else printf("%s\n",com);	
    }
  }
  return menu;
}
