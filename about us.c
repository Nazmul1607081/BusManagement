#include<stdio.h>
void about_us()
{

    char *ppp;
    ppp = (char *)calloc(2000,1);
    FILE *pt;
    char s[2000];
    pt=fopen("about_us.txt","r");

    while(!feof(pt)){
        fgets(s,2000,pt);
        printf("%s",s);
    }
    rectangle(0,0,120,10);
    fclose(pt);
    gotoxy(24,21);
    printf("Please enter any key for back");
    getch();
    free(ppp);
    system("cls");
    main();


}
void notice()
{
    char *ppp;
    ppp = (char *)calloc(2000,1);
    system("cls");
    rectangle(0,0,120,15);
    gotoxy(57,3);printf("NOTICE");
    gotoxy(45,6);printf("Update any notice   [1]");
    gotoxy(45,7);printf("Today notice        [2]");
    gotoxy(45,8);printf("Main menu           [0]");
    gotoxy(45,13);printf("Chose a option: ");

    realloc(ppp, 40000);
    int n;
    int *p;
    p=&n;scanf("%d",&n);
    if(*p==1){
        updatenotice();
    }
    if(*p==2){
        todaynotice();
    }
    if(*p==0){
        firstpage();
    }
free(ppp);
}
void todaynotice()
{
    system("cls");
    FILE *fp;
        char s[4000],c;
        fp = fopen("todaynotice.txt","r");
        gotoxy(4,2);
        while(!feof(fp)){
            fgets(s,4000,fp);
            printf("%s ",s);


        }
        getch();
        fclose(fp);
        rectangle(0,0,120,12);
        printf("\n\n\n\nPlease enter any key for back.\n");

        notice();
}

void updatenotice()
{
    system("cls");
    FILE *fp;
    char s[20];
    fp = fopen("todaynotice.txt","w");

        printf("Ticket booking money increase :");scanf("%s",s);fprintf(fp,"Ticket booking money increased %s taka.",s);
        printf("Any tripe cancel :");scanf("%s",s);fprintf(fp,"Tripe no %s is cancelled.\n\n\n\n\n",s);
        printf("Please enter any key for back.\n");

    fclose(fp);

    notice();
}
void tandc()
{

    system("cls");
    FILE *pt;
    char s[2000];
    pt=fopen("tripecostdetails.txt","r");
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
