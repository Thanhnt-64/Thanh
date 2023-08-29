#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

struct contact{
    long ph;
    char name[20];
    char add[20];
    char email[30];
}list;


char query[20], name[20];
FILE *fp, *ft;

int i, n, ch, l, found;

int main(){
    main:
    system("cls");
    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\n\t\t\tMAIN MENU");
    printf("\n\t\t=======================");
    printf("\n\t\t[1] Add a new Contact");
    printf("\n\t\t[2] List all Contacts");
    printf("\n\t\t[3] Search for Contact");
    printf("\n\t\t[4] Edit a Contact");
    printf("\n\t\t[5] Delete a Contact");
    printf("\n\t\t[0] Exit");
    printf("\n\t\t=======================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);

    switch (ch)
    {
    case 0:
        printf("\n\n\t\t Are you sure want to exit");
        break;
    case 1:
        system("cls");// xóa màn hình
        fp=fopen("contact.dll","a");
        for(;;){
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName (Ues identical)");
            scanf("%[^\n]",&list.name);
            //stricmp tương tự strcmp, mà k so sánh hoa thường
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0){
                break;
            }
            fflush(stdin);
            printf("Phone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
    case 2:
        system("cls");
        printf("\n\t\t===========================");
        printf("\n\t\t\tLIST OF CONTACTS");
        printf("\n\t\t===========================");
        printf("\n\nName\t\tPhone No\t      Address\t\tE-mail ad.");
        printf("\n================================================\n\n");
        for (i = 97; i< 122; i++){
            fp = fopen("contact.dll","r");
            fflush(stdin);
            found = 0;
            while(fread(&list,sizeof(list),1,fp)==1){
                if(list.name[0] == i || list.name[0]==i-32){
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,
                    list.ph,list.add,list.email);
                    found++;
                }
            }
            if(found != 0){
                printf("==================================[%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
        }
        break;
    case 3:
        system("cls");
        do{
            found = 0;
            printf("\n\n\t..::CONTACT SEARCH\n\t===================\n\t..::Name of contact to search");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l = strlen(query);
            fp = fopen("contac.dll","r");
            system("cls");
            printf("..::Search result for '%s' \n=========================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1){
                for (i = 0;i<l;i++)
                   name[i] = list.name[i];
                   name[l]='\0'; 
                if(stricmp(name,query)==0){
                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;
                    if(found%4==0){
                        printf("..::Press any key to continue");
                        getch();
                    }
                }
            }
            if(found == 0){
                printf("\n..::No match found");
            }
            else 
            printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }while(ch == 1);
        break;
    case 4:
        system("cls");
        fp = fopen("contact.dll","r");
        ft = fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit contact\n=========================\n\n\t..::Enter the name of contact to edit:");
        scanf("%[^n]",name);
        while(fread(&list, sizeof(list),1,fp)==1){
            if(stricmp(name,list.name)!=0){
                fwrite(&list,sizeof(list),1,ft);
            }
        }
        fflush(stdin);
        printf("\n\n..::Editting '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::Address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::Email address:");
        scanf("%[^\n]",&list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::Delete a contact\n\t=======================") ;
        printf("\n\t..::Enter the name of contact to delete");
        scanf("%[^\n]",&name);
        fp = fopen("contact.dll","r");
        ft = fopen("temp.dat","w");
        while(fread(&list, sizeof(list),1,fp)!=0){
            if(stricmp(name,list.name)!=0){
                fwrite(&list,sizeof(list),1,ft);
            }
        }
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    default:
        printf("Invalid choice");
        break;
    }
    
    printf("\n\n\n..::Enter the choice:\n\n\t[1] Main Menu\t\t[0]Cut\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}