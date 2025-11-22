#Project-1

#include <stdio.h>
#include<string.h>
#define MAX 500
#define key 0x5A
#define Datafile "password.txt"
typedef struct
{
    char sitename[MAX];
    char username[MAX];
    char password[MAX];
} record;

record r;

// Using XOR for encryption
char* encrypt(char str[MAX])
{
    for(int i = 0; i<MAX && str[i] != '\0'; i++)
    {
        str[i]^=key;
    }
    return str;
}

// Using XOR for decryption
char* decrypt(char str[MAX])
{
    for(int i = 0; i<MAX && str[i] != '\0'; i++)
    {
        str[i]^=key;
    }
    return str;
}

// Adding records
void addRecord()
{
    char encrypted[MAX];
    FILE *password;
    password = fopen(Datafile,"a");
    if(password==NULL)
    {
        printf("File is not opened");
    }
    else
    {
        printf("Enter sitename: ");
        scanf("%499s", r.sitename);
        printf("Enter username: ");
        scanf("%499s",&r.username);
        printf("Enter password: ");
        scanf("%499s",&encrypted);
        encrypt(encrypted);
        strcpy(r.password, encrypted);
        fprintf(password, "%s|%s|%s\n", r.sitename, r.username, r.password);
        printf("Record Added.\n");
    }
    fclose(password);
}

//Searching Records
void searchRecord(char site[MAX])
{
    FILE *f1;
    char line[MAX * 3];
    int found = 0;
    f1 = fopen("password.txt", "r");
    if(f1 == NULL)
    {
        printf("File not found!\n");
        return;
    }
    printf("\nSearching for: %s\n", site);
    while(fgets(line, sizeof(line), f1) != NULL)
    {
        char sitename[MAX], username[MAX], password[MAX];
        if(sscanf(line, "%[^|]|%[^|]|%[^\n]", sitename, username, password) == 3)
        {
            if(strcmp(sitename, site) == 0)
            {
                decrypt(password);  // Decrypt before displaying
                printf("\nRecord Found:\n");
                printf("Sitename: %s\n", sitename);
                printf("Username: %s\n", username);
                printf("Password: %s\n", password);
                found = 1;
            }
        }
    }
    if(!found)
    {
        printf("No record found for: %s\n", site);
    }
    fclose(f1);
}

int main()
{
    int i = 1;
    while (i!=0)
    {
        int choice;
        printf("1)Add record\n2)Search Record\n3)Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            addRecord();
        }
        else if(choice==2)
        {
            char search[MAX];
            printf("Enter sitename: ");
            scanf("%499s",&search);
            searchRecord(search);

        }
        else if(choice==3)
        {
            i=0;
        }
        else
        {
            printf("Error!!!\n");
            return 0;
        }
    }
    return 0;
}
