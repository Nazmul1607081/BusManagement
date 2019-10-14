#include<stdio.h>
void adminoption()
{

    system("cls");
    rectangle(0,0,120,27);
    rectangle(22,2,60,21);
    gotoxy(24,4);
    printf("ADMIN OPTION");
    gotoxy(26,9);
    printf("Add new passenger           [1]");
    gotoxy(26,11);
    printf("Show daily passengers list  [2]");
    gotoxy(26,13);
    printf("Search passengers details   [3]");
    gotoxy(26,15);
    printf("Delete passenger            [4]");
    gotoxy(26,17);
    printf("Close                       [5]");
    gotoxy(26,19);
    printf("Update                      [6]");
    gotoxy(24,25);
    printf("Please enter your choice: ");
    selectadminoption();

}
void selectadminoption()
{
    char chc[1];
    int choosenew,chooseshow,choosesearch,chooseremove,choseclose,choseupdate;
    scanf("%s",chc);
    choosenew=strcmp(chc,"1");
    chooseshow=strcmp(chc,"2");
    choosesearch=strcmp(chc,"3");
    chooseremove=strcmp(chc,"4");
    choseclose=strcmp(chc,"5");
    choseupdate=strcmp(chc,"6");
    if(!(choosenew==0||chooseshow==0||choosesearch==0||chooseremove==0||choseclose==0||choseupdate==0))
    {

        gotoxy(19,21);
        system("COLOR C");
        printf("INVALID INPUT!");
        gotoxy(34,21);
        system("COLOR 6");
        printf("press any key to continue.");
    }
    if(choosenew==0){
        system("cls");
        gotoxy(25,5);
        getdata(1);
    }
    else if(chooseshow==0){
        system("cls");
        getdata(2);
    }
    else if(choosesearch==0){
        system("cls");
        getdata(3);
    }
    else if(chooseremove==0){
        system("cls");
        getdata(4);
    }
    else if(choseclose==0){
        system("cls");
        main();
    }

    else if(choseupdate==0){
        system("cls");
        getdata(6);
    }
}


void getdata(int option )
{
    FILE *db,*tempdb;
    char anotherpass;
    int choice;
    int showmenu,posx,posy;
    char checksave,checkaddnew;
    int i;
//bngjidfkgdkfjgndkgjndklgnjsdlkgjldkgbjgkbjndkgsnlgjfgbldkgbjdlkg
    struct passangers
    {
        char firstname[25];
        char lastname[25];
        char password[30];
        char presentaddress[30];
        char permanentaddress[30];
        char contact_no[13];
        int seat_no;
        int tripe_no;
        int passengerid;
        char gender[7];

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
        switch(choice)
        {
        case 1:
            fseek(db,0,SEEK_END);
            anotherpass='y';

            while(anotherpass=='y'){
                checkaddnew=0;
                while(checkaddnew==0){
                    system("cls");
                    gotoxy(25,3);
                    printf("ADD A NEW PASSENGER");
                    gotoxy(13,30);
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
                        if(passengerdata.passengerid<20000)
                            passengerdata.passengerid=201700;
//jghfiogheioijrtyortjhojhirthjnkjgndikghndfogehdngiodgneiolgknegilkfdsjngdfkgbnfkgneig
                        passengerdata.passengerid=passengerdata.passengerid+1;
                        gotoxy(24,14);printf("Present Address :");scanf("%s",passengerdata.presentaddress);
                        gotoxy(24,16);printf("Permanent Address :");scanf("%s",passengerdata.permanentaddress);
                        gotoxy(24,18);printf("Mobile no: ");scanf("%s",passengerdata.contact_no);
                        gotoxy(24,20);printf("Gender: ");scanf("%s",passengerdata.gender);
                        //gotoxy(24,22);printf("Tripe no(1/2): ");scanf("%d",&passengerdata.tripe_no);
                        //if(passengerdata.tripe_no==1){trip();}
                        //system("cls");
                        //gotoxy(24,24);
                       // printf("Please enter seat no again :");
                        //scanf("%d",&passengerdata.seat_no);
                        gotoxy(22,26);
                        printf("Save passenger information? (y/n):");
                        checksave=getch();
                        if(checksave=='y'){
                            strcpy(passengerdata.firstname,firstnametemp);
                            strcpy(passengerdata.lastname,lastnametemp);
                            strcpy(passengerdata.password,password);
                            fwrite(&passengerdata,size,1,db);
                        }
                        gotoxy(22,27);
                        printf("             ");
                        gotoxy(22,28);
                        printf("Would you like to add another employ? (y/n):");
                        fflush(stdin);
                        anotherpass=getch();
                        printf("\n");
                    }

                }
            }
            break;
        case 2:
            system("cls");
            //gotoxy(21,2);
            printf("Passenger | Passenger      | Present     | Permanent  |Mobile no   |Tripe|Seat|Gender|\n");
            printf("   ID     |    name        | Address     |  Address   |            |  no | no |      |\n");
            gotoxy(1,2);
            printf("_____________________________________________________________________________________");
            rewind(db);
            posx=3;
            posy=4;
            while(fread(&passengerdata,size,1,db)==1){
                passengerdata.firstname[0]=toupper(passengerdata.firstname[0]);
                passengerdata.lastname[0]=toupper(passengerdata.lastname[0]);
                gotoxy(posx,posy);
                printf("%d",passengerdata.passengerid);
                gotoxy(posx+7,posy);
                printf("| %s %s",passengerdata.firstname,passengerdata.lastname);

                gotoxy(posx+24,posy);
                printf("| %s",passengerdata.presentaddress);
                gotoxy(posx+38,posy);
                printf("| %s",passengerdata.permanentaddress);
                gotoxy(posx+51,posy);
                printf("| %s",passengerdata.contact_no);
                gotoxy(posx+64,posy);
                printf("| %d",passengerdata.tripe_no);
                gotoxy(posx+70,posy);
                printf("| %d",passengerdata.seat_no);
                gotoxy(posx+75,posy);
                printf("| %s",passengerdata.gender);
                posy=posy+3;
            }
            getch();
            printf("\n");
            break;
//nigknfdiogkljngkldfjgnfdklbnjdkljdfmnldfkljgndolbjndfkldjnfdklbkndflkbjdfnblkdjlbn
        case 3:
            system("cls");

            printf("Please select a option to search :\n");
            printf("BY ID   [1]\n");
            printf("BY NAME [2]\n");

            int se;scanf("%d",&se);
        if(se==1){
            gotoxy(27,5);
            printf("SEARCH PASSENGER INFORMATION");
            gotoxy(25,9);
            printf("Enter passenger id to search: ");
            scanf("%d",&searchid);
            findpassenger='f';
            rewind(db);
            while(fread(&passengerdata,size,1,db)==1){
                if(passengerdata.passengerid==searchid){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Passenger information is available. ");
                    system("COLOR 6");
                    gotoxy(5,13);
                    printf("Passenger name is: %s %s  ,,,\nPassenger permanent address is :%s,,,\nPresent address is :%s,,,\nMobile no: %s,,,\nTripe no:%d,,,\nSeat no:%d,,,\n",passengerdata.lastname,passengerdata.firstname,passengerdata.permanentaddress,passengerdata.presentaddress,passengerdata.contact_no,passengerdata.tripe_no,passengerdata.seat_no);

                    findpassenger='t';
                    getch();
                }
            }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR 4E");
                printf("Passenger information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }
        }
        else{
                system("cls");
                char nname[30];
                gotoxy(25,9);
                printf("Enter passenger name to search: ");
                scanf("%s",nname);
                findpassenger='f';
                rewind(db);
                while(fread(&passengerdata,size,1,db)==1){

                if(!strcmp(nname,passengerdata.firstname)){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Passenger information is available. ");
                    system("COLOR 6");
                    gotoxy(5,13);
                    printf("Passenger name is: %s %s  ,,,\nPassenger permanent address is :%s,,,\nPresent address is :%s,,,\nMobile no: %s,,,\nTripe no:%d,,,\nSeat no:%d,,,\n",passengerdata.lastname,passengerdata.firstname,passengerdata.permanentaddress,passengerdata.presentaddress,passengerdata.contact_no,passengerdata.tripe_no,passengerdata.seat_no);

                    findpassenger='t';
                    getch();
            }
        }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR 4E");
                printf("Passenger information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }

    }

break;
        case 4:
            system("cls");
            gotoxy(25,5);
            printf("REMOVE A PASSENGER");
            gotoxy(25,9);
            printf("Enter passenger id to delete:");
            scanf("%d",&searchid);
            findpassenger='f';
            rewind(db);
            while(fread(&passengerdata,size,1,db)==1){
                if(passengerdata.passengerid==searchid){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Passenger information is available. ");
                    system("COLOR 6");
                    gotoxy(25,13);

                    findpassenger='t';
                }
            }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR E");
                printf("Passenger information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }
            if(findpassenger=='t'){
                gotoxy(29,15);
                printf("Do you want to delete this passenger? (y/n)");
                confirmdelete=getch();
                if(confirmdelete=='y'||confirmdelete=='Y'){
                    tempdb=fopen("tempo.txt","wb+");
                    rewind(db);
                    while(fread(&passengerdata,size,1,db)==1){
                        if(passengerdata.passengerid!=searchid){
                            fseek(tempdb,0,SEEK_END);
                            fwrite(&passengerdata,size,1,tempdb);
                        }
                    }
                    fclose(tempdb);
                    fclose(db);
                    remove("passengerbase.txt");
                    rename("tempo.txt","passengerbase.txt");
                    db=fopen("passengerbase.txt","rb+");
                }
            }
            break;
        case 5:
           firstpage();
           printf("\n");
           exit(0);
        case 6:
        system("cls");
        gotoxy(25,5);
        printf("SEARSE A PASSENGER");
        gotoxy(25,9);
        printf("Enter passenger id to update:");
        scanf("%d",&searchid);
        findpassenger='y';
        rewind(db);
        while(fread(&passengerdata,size,1,db)==1){
          if(passengerdata.passengerid==searchid){
            gotoxy(33,11);
            system("COLOR E");
            printf("Passenger information is available.\n\n");
            printf("Passenger name is: %s %s  ,,,\nPassenger permanent address is :%s,,,\nPresent address is :%s,,,\nMobile no: %s,,,\nTripe no:%d,,,\nSeat no:%d,,,\n",passengerdata.lastname,passengerdata.firstname,passengerdata.permanentaddress,passengerdata.presentaddress,passengerdata.contact_no,passengerdata.tripe_no,passengerdata.seat_no);



//gdhdghdghdghgdh


            findpassenger='t';
        }
    }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR E");
                printf("Passenger information is not available. Please modify this search.");

                getch();
            }
            if(findpassenger=='t'){
                gotoxy(29,15);
                printf("\n\n\n\nDo you want to update this passenger information ? (y/n)");

                confirmdelete=getch();

                if(confirmdelete=='y'||confirmdelete=='Y'){
                    updateview();
                    int uc;scanf("%d",&uc);
                    tempdb=fopen("tempo.txt","wb+");
                    rewind(db);
                    while(fread(&passengerdata,size,1,db)==1){
                        if(passengerdata.passengerid!=searchid){
                            fseek(tempdb,0,SEEK_END);
                            fwrite(&passengerdata,size,1,tempdb);
                        }
                        if(passengerdata.passengerid==searchid){
                            fseek(tempdb,0,SEEK_END);

                            if(uc==1){
                               printf("\n\n\n\nPlease enter your first name :\n\n");
                               printf("Passenger first name: ");scanf("%s",passengerdata.firstname);
                            }
                            if(uc==2){
                               printf("\n\n\n\nPlease enter your last name :\n\n");
                               printf("Passenger last name");scanf("%s",passengerdata.lastname);
                            }
                            if(uc==3){
                               printf("\n\n\n\nPlease enter your present address :\n\n");
                               printf("Passenger present address :");scanf("%s",passengerdata.presentaddress);
                            }
                            if(uc==4){
                               printf("\n\n\n\nPlease enter your permanent address :\n\n");
                               printf("passenger permanent address : ");scanf("%s",passengerdata.permanentaddress);
                            }
                            if(uc==5){
                               printf("\n\n\n\nPlease enter your mobile no :\n\n");
                               printf("Mobile no: ");scanf("%s",passengerdata.contact_no);
                            }
                            if(uc==6){
                               printf("\n\n\n\nPlease enter your tripe no :\n\n");
                               printf("passenger tripe no : ");scanf("%s",passengerdata.tripe_no);
                            }
                            if(uc==7){
                               printf("\n\n\n\nPlease enter your seat no :\n\n");
                               printf("passenger seat no : ");scanf("%s",passengerdata.seat_no);
                            }
                            if(uc==8){
                               printf("\n\n\n\nPlease enter your gender:\n\n");
                               printf("passenger gender : ");scanf("%s",passengerdata.gender);
                            }

                            fwrite(&passengerdata,size,1,tempdb);
                        }
                    }
                    fclose(tempdb);
                    fclose(db);
                    remove("passengerbase.txt");
                    rename("tempo.txt","passengerbase.txt");
                    db=fopen("passengerbase.txt","rb+");
                }
            }
            getch();
            break;


          }
        fclose(db);
        adminoption();

    }


}





