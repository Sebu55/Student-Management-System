#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

struct Account {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};
void maskPassword(char password[]){
char ch; int i=0;
while((ch=_getch())!=13){
    printf("*");
    password[i] = ch;
    i++;
}
password[i]='\0';

}
void encrypt(char password[], int key){
for(int i=0;i<strlen(password);i++){
password[i]= password[i]-key;
  }
}
void decrypt(char password[], int key){
for(int i=0;i<strlen(password);i++){
password[i]= password[i]+key;
  }
}

int login(const struct Account* accounts, int num_accounts) {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  maskPassword(password);
  encrypt(password,0XAED);
  printf("\n%s",password);
  decrypt(password,0XAED);
  printf("\n%s",password);

  printf("\n");




  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char** argv) {

  struct Account accounts[] = {
    {"Samia", "pass1234@"},
    {"Afsana", "pass20series"},
    {"Seba", "pass2023#"},
  };
  const int num_accounts = sizeof(accounts) / sizeof(accounts[0]);

  int is_logged_in = 0;
  while (!is_logged_in) {
    is_logged_in = login(accounts, num_accounts);
    if (!is_logged_in) {
      printf("Invalid username or password. Try again.\n");
    }
  }

  printf("Login successful!\n");
  return 0;
}
