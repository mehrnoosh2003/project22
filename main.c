
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    char name[100];
    char names[300][20];

    char pass[100];
    char passes[300][20];

    char message[1000];
    char messagess[3000][200];

    char nm[100];
    char nam[100];
    char mess[100];
    char m[40];

    int mid[100];
    int message_c = 0;
    int user_id;
    int ucount=0;

    int i=0, x=1 ;
    FILE *fileusers;
    FILE *filepass;
    FILE *messages;
    FILE *message_id;

    registeration:

    fileusers=fopen("username.txt","a+");
    fgets(nam,100,fileusers);
    while(!feof(fileusers)){
        strcpy(names[ucount],nm);
        //printf("%s\n",names[ucount]);
        //printf("%s",nam);
        strncat(names[ucount],nam,(strlen(nam)-1));
        //printf("%s\n",names[ucount]);
        fgets(nam,100,fileusers);
        ucount++;
    }
    fclose(fileusers);

    i=0;
    filepass=fopen("passname.txt","a+");
    fgets(pass,100,filepass);
        while(!feof(filepass)){
            strncpy(passes[i],pass,(strlen(pass)-1));
            fgets(pass,100,filepass);
            i++;
        }
    fclose(filepass);

    message_c = 0;
    messages =fopen("message.txt" , "a+");
    fgets(message , 500, messages);
    while(!feof(messages)){
        strncpy(messagess[message_c], message, (strlen(message) - 1));
        fgets(message, 500, messages);
        message_c++;
    }
    fclose(messages);

    i = 0;
    message_id=fopen("message_id.txt" , "a+");
    fgets(mess , 100 , message_id);
    while(!feof(message_id)){
        if(strlen(mess) == 2){
            mid[i] = *mess- '0';
        }
        else if(strlen(mess) == 3){
           mid[i] = (*mess - '0') * 10 + *(mess + 1) - '0';
        }
        fgets(mess , 10, message_id);
        //printf("%d",mid[i]);
        i++;
    }
    fclose(message_id);


    for(x ; x < 100 ; x++){
        printf("user name : ");
        gets(name);

        printf("password : ");
        gets(pass);

        printf("\n1.login\n2.register\nselect action:");
        char num[50];
        int temp = 0;
        gets(num);
        temp = *num - '0';
        if (temp == 1){

            for(i = 0; i < ucount; i++){

                if(strcmp(name, names[i]) == 0){
                    if(strcmp(pass, passes[i]) == 0){
                        system("cls");
                        printf("HELLO!\n");
                        user_id = i;
                        goto mainmenu;
                    }
                    else{
                        system("cls");
                        printf("WRONG PASSWORD\n");
                        goto registeration;
                    }
                }
            }
            system("cls");
            printf("NO USER MATCHES.\n");
            goto registeration;
          }

        else if(temp == 2){
                for(i = 0; i < ucount; i++){
                  if(strcmp(name, names[i]) == 0){
                    system("cls");
                     printf("USER NAME ALREADY EXISTS!\n");
                     goto registeration;
                  }
                }

             strcpy(names[ucount], name);
             fileusers=fopen("username.txt","a+");
             fputs(name,fileusers);
             fputs("\n",fileusers);
             fclose(fileusers);

             strcpy(passes[ucount], pass);
             filepass=fopen("passname.txt","a+");
             fputs(pass,filepass);
             fputs("\n",filepass);
             fclose(filepass);

             user_id = ucount;
             ucount++;
             system("cls");
             printf("Wellcome!\n");
             goto mainmenu;
            }


        mainmenu:

        printf(" 1.send message\n 2.edit message\n 3.view all message\n 4.change password\n 5.messages\n 6.exit\n enter number of menu:");
        char m1[10];
        int m2;
        gets(m1);
        m2= *m1-48;
        if(m2==1){
                    sendmessage :

                    system ("cls");
                    printf("send message menu:\n 1.send message\n 2.exit\n enter a number of menu:");
                    char variable[10];
                    int var;
                    gets(variable);
                    var=*variable-'0';
                    if(var==1){

                            gets(message);
                            mid[message_c] = user_id;
                            message_id=fopen("message_id.txt","a+");
                            sprintf(mess, "%d", mid[message_c]);
                            fputs(mess,message_id);
                            fputs("\n",message_id);
                            fclose(message_id);

                            strcpy(messagess[message_c],message);
                            message_c++;
                            messages=fopen("message.txt","a+");
                            fputs(message,messages);
                            fputs("\n",messages);
                            fclose(messages);
                           printf("\nMessage sent!\n");
                           goto mainmenu;
                    }

                     else if(var==2){
                            system("cls");
                            goto mainmenu;
                     }
                     else{
                        printf("Error\n");
                        goto sendmessage;
                     }
    }
    if(m2==2){
                editmessage :

                system("cls");
                printf("Edit message menu:\n 1.edit message\n 2.exit\n enter a number of menu:");
                char variable[10];
                int var;
                gets(variable);
                var=*variable-'0';
                if(var==1){

                    system("cls");
                    printf("Enter the ID:");
                    char m1[10];
                    int m2;
                    editmessage1 :
                    gets(m1);
                    if(strlen(m1) == 1){
                     m2 = *m1 - 49;
                     }
                    else if(strlen(m1) == 2){
                     m2 = (*m1 - 48) * 10 + *(m1 + 1) - 49;
                     }
                    if (mid[m2] == user_id){
                        printf("\nEnter the new message:\n");
                        gets(message);
                        strcpy(messagess[m2],message);
                        messages=fopen("message.txt","w+");
                        for(size_t  j; j< message_c; j++){
                            fputs(messagess[j],messages);
                            fputs("\n",messages);
                        }
                        fclose(messages);
                        goto mainmenu;

                    }
                    else if (m2<0 || m2>= message_c){
                        system("cls");
                        printf("Error\nEnter another message ID:");
                        goto editmessage1;
                    }
                    else{
                        printf("This isn't your message");
                        system("cls");
                        goto editmessage1;
                    }

                }
                else if(var==2){
                    system("cls");
                    goto mainmenu;
                }
    }

if(m2 == 3)
    {
        system("cls");
        printf("View all messages menu\n 1.view all messages\n 2.exit\n Enter number of menu : ");
                    viewallmessage:
                    gets(m1);
                    m2 = *m1 - 48;
                    if(m2 == 2){
                            system("cls");
                            goto mainmenu;
                    }
                    system("cls");
                    for(int j = 0; j < message_c; j++){
                        printf("%d :\n%s : %s\n\n", j+1, names[mid[j]], messagess[j]);
                   }
                   printf("Press 2 to continue: ");
                   gets(m1);
                   m2 = *m1 - 48;
                    if(m2 == 2){
                            system("cls");
                            goto mainmenu;
                    }
                   goto mainmenu;
    }

if(m2==4){
    changepassword:

    printf("Change password menu\n1.change password\n2.exit\nenter number of menu : ");
    char variable[10];
                int var;
                gets(variable);
                var=*variable-'0';
                if(var==2){
                    system("cls");
                    goto mainmenu;
                 }
                 system("cls");
                 printf("Your new password :\n");
                 gets(pass);

                 strcpy(passes[user_id], pass);
                 filepass = fopen("pass.txt", "w+");
                 for(int j = 0; j < ucount; j++){
                    fputs(passes[j], filepass);
                    fputs("\n", filepass);
                 }
                 fclose(filepass);

                  printf("\nyour password changed.\n");
                  printf("Press 2 to continue: ");
                  gets(variable);
                  var=*variable-'0';
                  if(var==2){
                    system("cls");
                    goto mainmenu;
                  }
                  }
  if(m2==5){
        int menu;
        system("cls");
        printf("who do you want? :)");
        gets(m);
        if(strlen(m) == 1){
           menu = *m - 49;
        }
        else if(strlen(m) == 2){
           menu = (*m - 48) * 10 + *(m + 1) - 49;
         }
        for(int j = 0 ; j < message_c; j++){
            if(mid[j] == menu){
                printf("%d : %s : %s\n",j+1,names[menu],messagess[j]);
            }
       }
       printf("Press  2 to continue:");
       gets(m);
       menu=*m-'0';
                  if(menu==2){
                    system("cls");
                    goto mainmenu;
                  }
   }
if(m2==6){
exit:
    system("cls");
    goto registeration;}


return 0;
}}
