#include<stdio.h>
void updateview()
{
    system("cls");
    printf("Please choose any option for update \n\n");
    printf("                     Update your first name             [1]\n");
    printf("                     Update your last  name             [2]\n");
    printf("                     Update your present address        [3]\n");
    printf("                     Update your permanent address      [4]\n");
    printf("                     Update your contact no             [5]\n");
    printf("                     Update your tripe no               [6]\n");
    printf("                     Update your seat no                [7]\n");
    printf("                     Update your gender                 [8]\n");
    printf(" please enter your choice :\n");

}
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}





void busticket()
{
    printf("Enter you ticket no\n");
    char x[3];scanf("%s",x);
    FILE *fptr1, *fptr2;
    char  c;int i;


    fptr1 = fopen("ticket.txt", "r+");
    if (fptr1 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }

    fptr2 = fopen("tempticket.txt", "w+");
    if (fptr2 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }


    c = fgetc(fptr1);
    while (c != EOF)
    {

        fputc(c, fptr2);
        c = fgetc(fptr1);

        if(x[0]==c){
            for(i=0;i<3;i++){

            }
        }
    }
//vbdflksgndfklgndfkslgnsdklfgbd fsokgfbfl kbsfkuuvsfkl bvdsfihvdfugbdhvbdjsgdkfhkrfhrkfjroefhiehdfkeshduiehfdiefiehfiehfieh


    fclose(fptr1);
    fclose(fptr2);

}
void adminoption1()
{

    system("cls");
    rectangle(0,0,120,27);
    rectangle(22,2,60,21);
    gotoxy(24,4);
    printf("Bus management");
    gotoxy(26,9);
    printf("Add new BUS                 [1]");
    gotoxy(26,11);
    printf("Show daily bus list         [2]");
    gotoxy(26,13);
    printf("Search bus details          [3]");
    gotoxy(26,15);
    printf("Delete bus                  [4]");
    gotoxy(26,17);
    printf("Close                       [5]");
    gotoxy(26,19);
    printf("Update                      [6]");
    gotoxy(24,25);
    printf("Please enter your choice: ");
    selectadminoption1();

}
void selectadminoption1()
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
        settripe(1);
    }
    else if(chooseshow==0){
        system("cls");
        settripe(2);
    }
    else if(choosesearch==0){
        system("cls");
        settripe(3);
    }
    else if(chooseremove==0){
        system("cls");

        settripe(4);
    }
    else if(choseclose==0){
        system("cls");
        firstpage();
    }
    else if(choseupdate==0){
        system("cls");
        settripe(6);
    }
}
void settripe(int option )
{
    FILE *db,*tempdb;
    int choice;
    int showmenu,posx,posy;
    char checksave,checkaddnew;
    int i;
//bngjidfkgdkfjgndkgjndklgnjsdlkgjldkgbjgkbjndkgsnlgjfgbldkgbjdlkg
    struct buses
    {
        char firstname[25];
        char lastname[25];

        char presentaddress[30];
        char starttime[20];
        char endtime[20];
        char permanentaddress[30];
        char contact_no[100];
        int seat_no;
        int tripe_no;
        int passengerid;
        char gender[7];
        int seatc;

    }passengerdata1;


    long int size;
    char lastnametemp[30],firstnametemp[30],password[30];
    int searchid;

    char findpassenger;
    char  confirmdelete;




    system("cls");


    db=fopen("passengerbase1.txt","rb+");
    if(db==NULL){
        db=fopen("passengerbase1.txt","wb+");
        if(db==NULL){
            printf("This file could not be opened.\n");
            exit(0);
        }
    }
    printf("Bus database \n");
    size = sizeof(passengerdata1);
    showmenu=0;
    while(showmenu==0){
        fflush(stdin);
        choice=option;
        switch(choice)
        {
        case 1:
            fseek(db,0,SEEK_END);
            char anotherpass='y';

            while(anotherpass=='y'){
                checkaddnew=0;
                while(checkaddnew==0){
                    system("cls");
                    gotoxy(25,3);
                    printf("ADD A NEW BUS");
                    gotoxy(5,8);
                    printf("Enter bus name: ");
                    scanf("%s",&firstnametemp);
                    gotoxy(5,10);
                    printf("Enter last name: ");
                    scanf("%s",&lastnametemp);
                    gotoxy(43,8);





                        checkaddnew=1;
                        rewind(db);
                        passengerdata1.passengerid=0;
                        while(fread(&passengerdata1,size,1,db)==1);
                        if(passengerdata1.passengerid<2000)
                            passengerdata1.passengerid=21700;
//jghfiogheioijrtyortjhojhirthjnkjgndikghndfogehdngiodgneiolgknegilkfdsjngdfkgbnfkgneig
                        passengerdata1.passengerid=passengerdata1.passengerid+1;
                        gotoxy(24,14);printf("Starting point :");scanf("%s",passengerdata1.presentaddress);
                        gotoxy(24,15);printf("Starting time :");scanf("%s",passengerdata1.starttime);

                        gotoxy(24,16);printf("End point:");scanf("%s",passengerdata1.permanentaddress);
                        gotoxy(24,17);printf("End  time :");scanf("%s",passengerdata1.endtime);
                        gotoxy(24,18);printf("Number of seat: ");scanf("%s",passengerdata1.contact_no);
                        gotoxy(24,20);printf("Bus type: ");scanf("%s",passengerdata1.gender);
                        gotoxy(24,22);printf("Tripe no: ");scanf("%d",&passengerdata1.tripe_no);


                        gotoxy(24,24);printf("Root no:");scanf("%d",&passengerdata1.seat_no);

                        gotoxy(22,26);
                        printf("Save bus information? (y/n):");
                        checksave=getch();
                        if(checksave=='y'){

                            strcpy(passengerdata1.firstname,firstnametemp);
                            strcpy(passengerdata1.lastname,lastnametemp);

                            fwrite(&passengerdata1,size,1,db);
                        }
                        gotoxy(22,27);
                        printf("             ");
                        gotoxy(22,28);
                        printf("Would you like to add another bus? (y/n):");
                        fflush(stdin);
                        anotherpass=getch();
                        printf("\n");


                }
            }
            break;
        case 2:
            system("cls");
            //gotoxy(21,2);
            printf("Bus   ID  |     Bus        |    Stat     |    End     | Number of  |Tripe|root|Type  |\n");
            printf("          |     name       | Point |Time |point | time|   seat     |  no | no |      |\n");
            gotoxy(1,2);
            printf("_____________________________________________________________________________________");
            rewind(db);
            posx=3;
            posy=4;
            while(fread(&passengerdata1,size,1,db)==1){
                passengerdata1.firstname[0]=toupper(passengerdata1.firstname[0]);
                passengerdata1.lastname[0]=toupper(passengerdata1.lastname[0]);
                gotoxy(posx,posy);
                printf("%d",passengerdata1.passengerid);
                gotoxy(posx+7,posy);
                printf("| %s %s",passengerdata1.firstname,passengerdata1.lastname);

                gotoxy(posx+24,posy);
                printf("| %s-%s",passengerdata1.presentaddress,passengerdata1.starttime);
                gotoxy(posx+38,posy);
                printf("| %s-%s",passengerdata1.permanentaddress,passengerdata1.endtime);
                gotoxy(posx+51,posy);
                printf("| %s",passengerdata1.contact_no);
                gotoxy(posx+64,posy);
                printf("| %d",passengerdata1.tripe_no);
                gotoxy(posx+70,posy);
                printf("| %d",passengerdata1.seat_no);
                gotoxy(posx+75,posy);
                printf("| %s",passengerdata1.gender);
                posy=posy+3;
            }
            getch();
            printf("\n");
            break;
//nigknfdiogkljngkldfjgnfdklbnjdkljdfmnldfkljgndolbjndfkldjnfdklbkndflkbjdfnblkdjlbn
        case 3:
            system("cls");

            printf("Please select a option to search :\n");
            printf("Bus ID   [1]\n");
            printf("BUS NAME [2]\n");

            int se;scanf("%d",&se);
        if(se==1){
            gotoxy(27,5);
            printf("SEARCH Bus INFORMATION");
            gotoxy(25,9);
            printf("Enter bus id to search: ");
            scanf("%d",&searchid);
            findpassenger='f';
            rewind(db);
            while(fread(&passengerdata1,size,1,db)==1){
                if(passengerdata1.passengerid==searchid){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Bus information is available. ");
                    system("COLOR 6");
                    gotoxy(5,13);
                    printf("Bus name is: %s %s  ,,,\nJourney starting point  is :%s,,,\n Journey end point  is :%s,,,\nNumber of seat: %s,,,\nTripe no:%d,,,\nRoot no:%d,,,\n",passengerdata1.lastname,passengerdata1.firstname,passengerdata1.permanentaddress,passengerdata1.presentaddress,passengerdata1.contact_no,passengerdata1.tripe_no,passengerdata1.seat_no);

                    findpassenger='t';
                    getch();
                }
            }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR 4E");
                printf("Bus information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }
        }
        else{
                system("cls");
                char nname[30];
                gotoxy(25,9);
                printf("Enter Bus name to search: ");
                scanf("%s",nname);
                findpassenger='f';
                rewind(db);
                while(fread(&passengerdata1,size,1,db)==1){
                if(!strcmp(nname,passengerdata1.firstname)){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Bus information is available. ");
                    system("COLOR 6");
                    gotoxy(5,13);
                    printf("Bus name is: %s %s  ,,,\nJourney starting point  is :%s,,,\n Journey end point  is :%s,,,\nNumber of seat: %s,,,\nTripe no:%d,,,\nRoot no:%d,,,\n",passengerdata1.lastname,passengerdata1.firstname,passengerdata1.permanentaddress,passengerdata1.presentaddress,passengerdata1.contact_no,passengerdata1.tripe_no,passengerdata1.seat_no);

                    findpassenger='t';
                    getch();
            }
        }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR 4E");
                printf("Bus information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }

    }

break;
        case 4:
            system("cls");
            gotoxy(25,5);
            printf("REMOVE A Bus");
            gotoxy(25,9);
            printf("Enter bus id to cancel:");
            scanf("%d",&searchid);
            findpassenger='f';
            rewind(db);
            while(fread(&passengerdata1,size,1,db)==1){
                if(passengerdata1.passengerid==searchid){
                    gotoxy(33,11);
                    system("COLOR E");
                    printf("Bus information is available. ");
                    system("COLOR 6");
                    gotoxy(25,13);

                    findpassenger='t';
                }
            }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR E");
                printf("Bus information is not available. Please modify this search.");
                system("COLOR 6");
                getch();
            }
            if(findpassenger=='t'){
                gotoxy(29,15);
                printf("Do you want to delete this bus? (y/n)");
                confirmdelete=getch();
                if(confirmdelete=='y'||confirmdelete=='Y'){
                    tempdb=fopen("tempo1.txt","wb+");
                    rewind(db);
                    while(fread(&passengerdata1,size,1,db)==1){
                        if(passengerdata1.passengerid!=searchid){
                            fseek(tempdb,0,SEEK_END);
                            fwrite(&passengerdata1,size,1,tempdb);
                        }
                    }
                    fclose(tempdb);
                    fclose(db);
                    remove("passengerbase1.txt");
                    rename("tempo1.txt","passengerbase1.txt");
                    db=fopen("passengerbase1.txt","rb+");
                }
            }
            break;
        case 5:
           firstpage();
           printf("\n");
           exit(0);
      /*  case 6:
        system("cls");
        gotoxy(25,5);
        printf("SEARSE A Bus");
        gotoxy(25,9);
        printf("Enter Bus id to update:");
        scanf("%d",&searchid);
        findpassenger='y';
        rewind(db);
        while(fread(&passengerdata,size,1,db)==1){
          if(passengerdata.passengerid==searchid){
            gotoxy(33,11);
            system("COLOR E");
            printf("Bus information is available.\n\n");
            printf("Bus name is: %s %s  ,,,\nJourney starting point  is :%s,,,\n Journey end point  is :%s,,,\nNumber of seat: %s,,,\nTripe no:%d,,,\nRoot no:%d,,,\n",passengerdata.lastname,passengerdata.firstname,passengerdata.permanentaddress,passengerdata.presentaddress,passengerdata.contact_no,passengerdata.tripe_no,passengerdata.seat_no);



//gdhdghdghdghgdh


            findpassenger='t';
        }
    }
            if(findpassenger!='t'){
                gotoxy(30,11);
                system("COLOR E");
                printf("Bus information is not available. Please modify this search.");

                getch();
            }
            if(findpassenger=='t'){
                gotoxy(29,15);
                printf("\n\n\n\nDo you want to update this Bus information ? (y/n)");

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
            break;*/


          }
        fclose(db);
        adminoption1();

    }
}
void tc()
{
    printf("\t\t Tripe cost details    [1]\n");
    printf("\t\t Root details          [2]\n");
    char cc=getch();
    if(cc=='1'){
        tandc();
    }
    if(cc=='2'){
        root();
    }
}
void root()
{
    system("cls");
    FILE *pt;
    char s[2000];
    pt=fopen("root.txt","r");
    while(!feof(pt)){
        fgets(s,2000,pt);
        printf("%s",s);
    }
    fclose(pt);
    rectangle(0,0,120,20);
    gotoxy(24,17);
    printf("Please press any key for back");
    getch();
    system("cls");

    main();

}
