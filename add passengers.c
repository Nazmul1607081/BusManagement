#include<stdio.h>
FILE *db,*tempdb;
    char anotherpass;
    int choice;
    int showmenu,posx,posy;
    char checksave,checkaddnew;
    int i;

    struct passangers
    {
        char firstname[25];
        char lastname[25];
        char password[30];
        int contact__no;
        int seat_no1;
        int tripe_no;
        int passengerid;
    }passengerdata;

    char confirmpassword[30];
    long int size;
    char lastnametemp[30],firstnametemp[30],password[30];
    int searchid;
    char pass[30];
    char findpassenger;
    char  confirmdelete;




    system("cls");


    db=fopen("passengerbase.txt","rb+");
    if(db==NULL){
        db=fopen("passengerbase.txt","wb+");
        if(db==NULL){
            printf("This file could not be opened.\n");
            exit(0);
        }
    }
    printf("Application database \n");
    size = sizeof(passengerdata);
    showmenu=0;
    while(showmenu==0){
        fflush(stdin);
        choice=option;
void addpassenger()
{
    fseek(db,0,SEEK_END);
            anotherpass='y';

            while(anotherpass=='y'){
                checkaddnew=0;
                while(checkaddnew==0){
                    system("cls");
                    gotoxy(25,3);
                    printf("ADD A NEW PASSENGER");
                    gotoxy(13,22);
                    printf("Warning password must contain 6(six) alphanumeric digits.");
                    gotoxy(5,8);
                    printf("Enter first name: ");
                    scanf("%s",&firstnametemp);
                    gotoxy(5,10);
                    printf("Enter last name: ");
                    scanf("%s",&lastnametemp);
                    gotoxy(43,8);
                    printf("Enter password: ");
                    for(i=0;i<6;i++){
                        password[i]=getch();
                        printf("* ");
                    }
                    password[6]='\0';
                    while(getch()!=13);

                    gotoxy(43,10);
                    printf("Confirm password: ");
                    for(i=0;i<6;i++){
                        confirmpassword[i]=getch();
                        printf("* ");
                    }
                    confirmpassword[6]='\0';
                    while(getch()!=13);

                    if(strcmp(password,confirmpassword)){
                        gotoxy(24,12);
                        printf("Password do not match. ");
                        gotoxy(23,13);
                        printf("Press any key to continue.");
                        getch();
                    }
                    else{
                        checkaddnew=1;
                        rewind(db);
                        passengerdata.passengerid=0;
                        while(fread(&passengerdata,size,1,db)==1);
                        if(passengerdata.passengerid<2000)
                            passengerdata.passengerid=20400;

                        passengerdata.passengerid=passengerdata.passengerid+1;
                        gotoxy(29,16);
                        printf("Save passenger information? (y/n):");
                        checksave=getch();
                        if(checksave=='y'){
                            strcpy(passengerdata.firstname,firstnametemp);
                            strcpy(passengerdata.lastname,lastnametemp);
                            strcpy(passengerdata.password,password);
                            fwrite(&passengerdata,size,1,db);
                        }
                        gotoxy(28,16);
                        printf("             ");
                        gotoxy(28,16);
                        printf("Would you like to add another employ? (y/n):");
                        fflush(stdin);
                        anotherpass=getch();
                        printf("\n");
                    }

                }
            }
            break;
}
