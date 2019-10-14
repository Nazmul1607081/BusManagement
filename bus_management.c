#include<stdio.h>

void firstpage()
{
    system("cls");
    rectangle(0,7,120,23);
    rectangle(22,8,60,20);
    gotoxy(40,3);
    system("COLOR A4");
    printf("****************************************");
    gotoxy(40,4);
    printf("WELCOME TO KHULNA TO BAGERHAT BUS JOUNEY");
    gotoxy(40,5);
    printf("////////////////////////////////////////");
    gotoxy(37,6);
    printf("/////////////////////////////////////////////");
    gotoxy(34,7);
    printf("///////////////////////////////////////////////////\n");
    gotoxy(24,21);
    printf("Please enter your choice: ");
    gotoxy(24,10);
    printf("Ticket booking                 [1]");
    gotoxy(24,11);
    printf("Passengers                     [2]");
    gotoxy(24,12);
    printf("Tripe cost details             [3]");
    gotoxy(24,13);
    printf("Notice                         [4]");
    gotoxy(24,14);
    printf("About us                       [5]");
    gotoxy(24,15);
    printf("Bus management                 [6]");
    gotoxy(24,16);
    printf("Exist                          [0]");

    int n;
    gotoxy(50,21);
    scanf("%d",&n);
    system("cls");
    if(n==1){
        busticket();
    }
    if(n==2){
        adminoption();
    }
    if(n==3){
        tc();
    }
    if(n==4){
        notice();
    }
    if(n==5){
        about_us();
    }
    if(n==6){
        adminoption1();
    }
    if(n==0){
        return 0;
    }


}




void trip()
{
    system("cls");
    seatview();
    int i=0, booking[36];
    int p,posy=3;gotoxy(35,27);scanf("%d",&p);
    system("cls");
    if(p==0){
        trip();
    }

    if(p>0&&p<36){
        for(i=0;i<35;i++){
            if(booking[p-1]==5){
                gotoxy(30,posy);system("COLOR 2");printf("|%d ||BOOKED",i+1);
            }
            else if(booking[p-1]!=5){
                gotoxy(30,posy);system("COLOR 2");printf("|%d ||      ",i+1);
            }
            posy++;
        }
        printf("\n\nSeat no(you want to book): ");scanf("%d",&p);
        printf("If you do not want to book now please enter 0");
        firstpage();
        if(getch()=='0'){}
        if(booking[p-1]==5){printf("\nIt is booked.Please try again:\n");getch();trip();}
        if(booking[p-1]!=5){booking[p-1]=5;printf("\nBooked successful.\n");getch();

        }


    }
}

void seatview()
{
    system("cls");
    system("COLOR 3C");
    gotoxy(58,3);
    printf("***DRIVER****");
    gotoxy(39,3);
    printf("**********");
    gotoxy(39,4);printf("**      **");
    gotoxy(39,5);printf("**ENGINE**");
    gotoxy(39,6);printf("**      **");
    gotoxy(39,7);printf("**********");
    gotoxy(20,3);
    printf("****MANAGER****\n");
    gotoxy(20,10);printf("|| 1||        || 2||           || 3||        || 4||");
    gotoxy(20,11);printf("|| 5||        || 6||           || 7||        || 8||");
    gotoxy(20,12);printf("|| 9||        ||10||           ||11||        ||12||");
    gotoxy(20,13);printf("||13||        ||14||           ||15||        ||16||");
    gotoxy(20,14);printf("||17||        ||18||           ||19||        ||20||");
    gotoxy(20,15);printf("||21||        ||22||           ||23||        ||24||");
    gotoxy(20,16);printf("||25||        ||26||           ||27||        ||28||");
    gotoxy(20,17);printf("||29|| ||30|| ||31||   ||32||  ||33|| ||34|| ||35||");

    gotoxy(20,23);printf("Please enter any seat no to see which seat is booked or not");
    gotoxy(20,25);printf("please enter 0 for back");



}








