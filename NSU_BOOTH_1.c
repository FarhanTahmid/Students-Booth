#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void mainMenu();
void clubmenu();
void checkBalance(double *balance);
double deposit(double *balance);
double withdraw(double *balance);
double tutionFee(double *balance,double credit);
double clubFee(double *balance, double fee);
void canteenFee(double);
void parkingFee(double);


struct sclubfee
{
    double fee;
    int clubID;
};
struct sclubfee sclub[3];

struct student
{
    char name[50];
    long int studentID;
    long int password;
    char major[50];
    double balance;
    int completedcredit;
    char semesterName[45];
    double cgpa;

};
struct student s[3];

int main()
{
    printf("                         \t\t\t******_______******               ");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t   WELCOME TO NSU STUDENT BOOTH\n");
    printf("\t\t\t\t\t   ____________________________");

    int i;
    struct student s[3]={[0].name="Farhan Ishrak Tahmid",[0].studentID=2031458642,[0].password=123456,
                        [0].major="Computer Science and Engineering",[0].balance=200000,
                        [0].completedcredit=10,[0].semesterName="Fall 2020",[0].cgpa=3.35,
                        [1].name="Nandini Das",[1].studentID=2031326642,[1].password=123456,
                        [1].major="Computer Science and Engineering",[1].balance=250000,
                        [1].completedcredit=12,[1].semesterName="Fall 2020",[1].cgpa=3.65,
                        [2].name="Humayra Jahan Shemushee",[2].studentID=2031454642,[2].password=123456,
                        [2].major="Computer Science and Engineering",[2].balance=300000,
                        [2].completedcredit=15,[2].semesterName="Fall 2020",[2].cgpa=3.85};

    FILE *ptr;
    ptr=fopen("All-student-info.txt","w");
    ptr=fopen("All-student-info.txt","a");
    if(ptr==NULL)
    {
        printf("Sorry unexpected error occurred\n");
    }
    else
    {
        fprintf(ptr,"\t\t\t\t\t\t\t\t\t   STUDENT DATABASE\n\n\n");
        fprintf(ptr,"Name            : %s\nNSU ID          : %li\nMajor           : %s\nBalance         : %.2lf\nCompleted course: %d\nSemester Name   : %s\nCGPA            : %.2lf",s[0].name,s[0].studentID,s[0].major,s[0].balance,s[0].completedcredit,s[0].semesterName,s[0].cgpa);
        fprintf(ptr,"\n\nName            : %s\nNSU ID          : %li\nMajor           : %s\nBalance         : %.2lf\nCompleted course: %d\nSemester Name   : %s\nCGPA            : %.2lf",s[1].name,s[1].studentID,s[1].major,s[1].balance,s[1].completedcredit,s[1].semesterName,s[1].cgpa);
        fprintf(ptr,"\n\nName            : %s\nNSU ID          : %li\nMajor           : %s\nBalance         : %.2lf\nCompleted course: %d\nSemester Name   : %s\nCGPA            : %.2lf",s[2].name,s[2].studentID,s[2].major,s[2].balance,s[2].completedcredit,s[2].semesterName,s[2].cgpa);
   }
   fclose(ptr);


   FILE *tptr;
   tptr = fopen("transaction_reciept.txt", "w");
   if(tptr==NULL)
   {
       printf("Error occured while creating transaction reciept! Please try again.");
   }
   else
   {
       fprintf(tptr,"\t\t\t\t\t\t\t\t\t  TRANSACTION RECIEPT\n\n\n");
   }
   fclose(tptr);

    struct sclubfee sclub[3]={[0].fee=2500,[0].clubID=2031458642,[1].fee=2500,[1].clubID=2031326642,[2].fee=2500,[2].clubID=2031454642};



    printf("\n\nPlease Login to access your account.\n");
    printf("\n");
    long int enteredusername;
    long int enteredpass;
    printf("Enter the user name(Your NSU ID): ");
    scanf("%li", &enteredusername);
    printf("\nEnter the password of your account: ");
    scanf("%li", &enteredpass);
    int flag;

    for(i=0;i<3;i++)
    {
        if((enteredusername!=s[i].studentID) && (enteredpass!=s[i].password))
        {

            printf("\n");
            printf("\n\t\t\t\t\tLogin unsuccessful. Please try again.\n\n.");
            return 0;
        }
        else if((enteredusername==s[i].studentID) && (enteredpass==s[i].password))
        {
            printf("\n");
            printf("\t\t\t\t\t\tLOGIN SUCCESSFUl!!!\n");
            flag =1;
            break;
        }

    }
    FILE *fptr;
    fptr=fopen("studentInformation.txt","w");

    if(flag==1)
    {
        for(i=0; i<3; i++)
        {
            if(enteredusername==s[i].studentID)
            {
                printf("\n");
                printf("\nStudent name : %s\nStudent ID   : %li\nCurrent major: %s", s[i].name,s[i].studentID,s[i].major);
                fptr=fopen("studentInformation.txt","a");
                if(fptr==NULL)
                {
                    printf("Unexpected error occured!\nPlease re-run the program");
                }
                else
                {
                    fprintf(fptr,"\nStudent name          : %s\nStudent ID            : %li\nCurrent major         : %s", s[i].name,s[i].studentID,s[i].major);
                    fprintf(fptr,"\nCurrent Semester      : %s\nTotal Completed Credit: %d\nCurrent CGPA          : %.2lf\n",s[i].semesterName,s[i].completedcredit,s[i].cgpa);
                    fprintf(fptr,"\nOngoing Theory Courses: CSE115\n                      : MAT116\n                      : ENG103\n\nOngoing Lab Courses   : CSE115L\n");
                }

                fclose(fptr);


            }
        }
        double studbalance;
        for(i=0; i<3; i++)
        {
            if(enteredusername==s[i].studentID)
            {
                studbalance=s[i].balance;
            }
        }
        printf("\n");
        printf("\n\t\t\t\t\t\t    Main Menu:\n");
        printf("\t\t\t\t\t\t   ------------\n");
        int anotherTransaction=1;
        mainMenu();

        while(anotherTransaction==1)
        {

            int option;
            printf("\nChoose an option: ");
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                    {
                        checkBalance(&studbalance);
                        break;
                    }
                case 2:
                    {
                        double depositresult=deposit(&studbalance);
                        printf("\nYour new balance is BDT %.2lf.\n",depositresult);
                        break;
                    }
                case 3:
                    {
                        double withdrawresult=withdraw(&studbalance);
                        printf("\nYour current balance is BDT %.2lf\n",withdrawresult);
                        break;
                    }
                case 4:
                    {

                        printf("\nHere, you can take theory courses for next semester:\nYou are allowed to take maximum 21 credits (7 courses) for your next semester as per your cgpa.\n");
                        printf("\nEnter theory courses name: (Input example: cse115 cse173 cse225)\n");

                        double count;
                        int i=1;
                        char string[250];
                        scanf(" ");
                        gets(string);
                        FILE *tptr;
                        char* token=strtok(string," ");
                        while(token)
                        {
                            printf("%d.%s\n",i++,token);
                            token=strtok(NULL," ");
                            count++;
                        }
                        tptr = fopen("transaction_reciept.txt", "a");
                        if (ptr == NULL)
                        {
                            printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                            exit(0);
                        }
                        else
                        {
                            fprintf(tptr, "\nYour total selected theory courses for next semester %.1lf\n", count);
                        }
                        fclose(tptr);

                        printf("\nYour have selected %.2lf theory courses for the next semester\n",count);

                        printf("\nYou have to take mandatory one lab course for this semester\nEnter your lab course name:(Input example: cse115L)\n");
                        char labcourse[10];
                        scanf(" ");
                        gets(labcourse);
                        printf("\nYour chosen lab course for next semester is: %s\n",labcourse);
                        double totalCredits= (count*3)+1;
                        printf("\nYou have taken total of %.1lf credits for the next semester.\n",totalCredits);
                        tptr = fopen("transaction_reciept.txt", "a");
                        if (tptr == NULL)
                        {
                            printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                            exit(0);
                        }
                        else
                        {
                            fprintf(tptr, "\nYour total selected credits for next semester %.1lf\n", totalCredits);
                        }
                        fclose(tptr);
                        double tutionFeeresult=tutionFee(&studbalance,totalCredits);
                        printf("\nYour current balance is %.2lf\n",tutionFeeresult);

                        break;
                    }
                case 5:
                    {
                        printf("\n\t\t\t\t\t\t    STUDENT STATUS");
                        printf("\n\t\t\t\t\t\t   ----------------");
                        char ch;
                        FILE *fptr;
                        fptr=fopen("studentInformation.txt","r");
                        if(fptr==NULL)
                        {
                            printf("\nSorry an unknown Error Occured! Please try again later!\n");
                        }
                        else
                        {
                            while(!feof(fptr))
                            {
                                ch=getc(fptr);
                                printf("%c",ch);
                            }
                        }
                        fclose(fptr);

                        break;
                    }
                case 6:
                    {
                        clubmenu();
                        int clubOption;
                        printf("\n\nEnter the option you want to select: ");
                        scanf("%d", &clubOption);
                        switch(clubOption)
                        {
                            case 1:
                                {
                                    int enteredID;
                                    printf("\nEnter your IEEE ID: ");
                                    scanf("%d",&enteredID);
                                        if(enteredID==2031458642)
                                        {
                                            printf("\nYour amount for payment is %.2lf\n", sclub[0].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[0].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                FILE *tptr;
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour IEEE club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[0].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }

                                        else if(enteredID==2031326642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[1].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[1].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour IEEE club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[1].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else if(enteredID==2031454642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[2].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[2].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour IEEE club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[2].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }

                                        }
                                        else
                                        {
                                            printf("\nWrong ID!");
                                            return 0;
                                        }
                                        break;

                                    }



                            case 2:
                                {
                                    int enteredID;
                                    printf("\nEnter your NSUAPC ID: ");
                                    scanf("%d",&enteredID);
                                        if(enteredID==2031458642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[0].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[0].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUAPC club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[0].fee, clubfeeresult);
                                                }
                                                fclose(tptr);

                                            }
                                        }

                                        else if(enteredID==2031326642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[1].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[1].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUAPC club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[1].fee, clubfeeresult);
                                                }
                                            }

                                        }
                                        else if(enteredID==2031454642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[2].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[2].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUAPC club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[2].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else
                                        {
                                            printf("\nWrong ID!");
                                            return 0;
                                        }



                                    break;
                                }

                                case 3:
                                    {
                                        int enteredID;
                                        printf("\nEnter your NSUYES ID: ");
                                        scanf("%d",&enteredID);
                                        if(enteredID==2031458642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[0].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[0].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUYESclub fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[0].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }

                                        else if(enteredID==2031326642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[1].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[1].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUYES club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[1].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else if(enteredID==2031454642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[2].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[2].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSUYES club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[2].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else
                                        {
                                            printf("\nWrong ID!");
                                            return 0;
                                        }

                                        break;
                                    }
                                case 4:
                                    {
                                        int enteredID;
                                        printf("\nEnter your Debate club ID: ");
                                        scanf("%d",&enteredID);
                                        if(enteredID==2031458642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[0].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[0].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSU Debate club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[0].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }

                                        else if(enteredID==2031326642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[1].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[1].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSU Debate club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[1].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else if(enteredID==2031454642)
                                        {

                                            printf("\nYour amount for payment is %lf\n", sclub[2].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[2].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSU Debate club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[2].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }
                                        else
                                        {
                                            printf("\nWrong ID!");
                                            return 0;
                                        }



                                        break;
                                    }
                                case 5:
                                    {
                                        int enteredID;
                                        printf("\nEnter your Cultural club ID: ");
                                        scanf("%d",&enteredID);
                                        if(enteredID==2031458642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[0].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[0].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSU Cultural club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[0].fee, clubfeeresult);
                                                }
                                                fclose(tptr);
                                            }
                                        }

                                        else if(enteredID==2031326642)
                                        {
                                            printf("\nYour amount for payment is %lf\n", sclub[1].fee);
                                            int confirmClubPay;
                                            printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                            scanf("%d",&confirmClubPay);
                                            if(confirmClubPay==1)
                                            {
                                                double clubfeeresult=clubFee(&studbalance,sclub[1].fee);
                                                printf("\nClub Fee paid successfully!\n");
                                                printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                tptr = fopen("transaction_reciept.txt", "a");
                                                if (tptr == NULL)
                                                {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    fprintf(tptr, "\nYour NSU Cultural club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[1].fee, clubfeeresult);
                                                }
                                                fclose(tptr);

                                            }
                                        }
                                            else if(enteredID==2031454642)
                                            {
                                                printf("\nYour amount for payment is %lf\n", sclub[2].fee);
                                                int confirmClubPay;
                                                printf("\nPress 1 to pay your club fee or press 0 to exit!\n");
                                                scanf("%d",&confirmClubPay);
                                                if(confirmClubPay==1)
                                                {
                                                    double clubfeeresult=clubFee(&studbalance,sclub[2].fee);
                                                    printf("\nClub Fee paid successfully!\n");
                                                    printf("\nYour current balance is %.2lf\n",clubfeeresult);
                                                    tptr = fopen("transaction_reciept.txt", "a");
                                                    if (tptr == NULL)
                                                    {
                                                    printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                                                    exit(0);
                                                    }
                                                else
                                                    {
                                                    fprintf(tptr, "\nYour NSU Cultural club fee is %.2lf\nAfter payment your current balance is %.2lf\n", sclub[2].fee, clubfeeresult);
                                                    }
                                                    fclose(tptr);

                                                }
                                            }
                                            else
                                            {
                                                printf("\nWrong ID!");
                                                return 0;
                                            }


                                        break;
                                    }

                        }
                        break;
                    }


                default:
                    {
                        printf("\nWrong input! Try again.\n");
                        return 0;
                    }
            }
            printf("\n\n Do you want to perform any other task using this booth?\n");
            printf("\nIf YES, press 1 to perform another task or press 0 to quit the booth.\n");

            scanf("%d",&anotherTransaction);
            if(anotherTransaction==1)
            {
                mainMenu();
            }
            else if(anotherTransaction==0)
            {
                int logoutoption;
                printf("\nPlease press 0 for logout.\n");
                scanf("%d",&logoutoption);
                if(logoutoption==0)
                {
                   printf("\nLogout successful\n");
                   return 0;
                }
                else
                {
                    printf("\nAccount logged out due to invalid selection.\n");
                }
            }
            else
            {
                printf("\nAccount logged out due to invalid selection. Please login again by restarting the program.\n");
            }
        }


    }


    return 0;
}
void checkBalance(double *balance)
{
    printf("\nYour current account balance is BDT %.2lf.\n\n", *balance);
    FILE *tptr;
    tptr = fopen("transaction_reciept.txt", "a");
    if (tptr == NULL)
    {
        printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
        exit(0);
    }
    else
    {
        fprintf(tptr, "\nYour Current balance: BDT %.2lf\n", *balance);
    }
    fclose(tptr);
    return;
}
double deposit(double *balance)
{
    double depositamount;
    printf("\n\nHow much money you want to deposit?\n");
    printf("- ");
    scanf("%lf",&depositamount);

    *balance+=depositamount;
    FILE *tptr;
    tptr = fopen("transaction_reciept.txt", "a");
    if (tptr == NULL)
    {
        printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
        exit(0);
    }
    else
    {
        fprintf(tptr, "\nDeposit amount: BDT %.2lf \nAfter depositing your Current balance: BDT %.2lf\n",depositamount, *balance);
    }
    fclose(tptr);

    return *balance;
}
double withdraw(double *balance)
{
    double withdrawAmount;
    printf("\nHow much money you want to withdraw: ");
    scanf("%lf",&withdrawAmount);
    if(*balance>withdrawAmount)
    {
        *balance-=withdrawAmount;
        printf("Your withdrawal amount is BDT %.2lf\n",withdrawAmount);
        FILE *tptr;
        tptr = fopen("transaction_reciept.txt", "a");
        if (tptr == NULL)
        {
            printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
            exit(0);
        }
        else
        {
            fprintf(tptr, "\nWithdrawal amount: BDT %.2lf \nAfter withdrawal your Current balance: BDT %.2lf\n", withdrawAmount, *balance);
        }
        fclose(tptr);
    }
    else
    {
        printf("\nYou don't have enough money to withdraw!");

    }
    return *balance;
}
double clubFee(double *balance, double fee)
{
    if(*balance>fee)
    {
        *balance-=fee;
    }
    else
    {
        printf("\nYou don't have enough money to pay for your club fee!");
    }
    return *balance;
}
void mainMenu()
{
    printf("1. Check your balance in NSU account\n");
    printf("2. Deposit money in NSU account\n");
    printf("3. Withdraw money from NSU account\n");
    printf("4. Select courses for your next semester and Pay your tution fee\n");
    printf("5. Check Student status\n");
    printf("6. Pay your NSU club fee.\n");
    return;
}

void clubmenu()
{
    printf("\t\t\t\t\t\t    CLUB MENU\n");
    printf("\t\t\t\t\t\t   ------------");
    printf("\n1.Pay your IEEE club fee.");
    printf("\n2.Pay your NSUAPC club fee.");
    printf("\n3.Pay your NSU YES club fee.");
    printf("\n4.Pay your Debate club fee.");
    printf("\n5.Pay your Cultural club fee.");
    return;
}
double tutionFee(double *balance,double credit)
{
    double tutionFeeAmount;
    tutionFeeAmount= (6500*credit)+9500;

    printf("\nYour tuition fees for next semester is BDT %.2lf\n",tutionFeeAmount);
    int confirmTransact;
    if(*balance>tutionFeeAmount)
    {
        printf("\nPlease enter 1 to pay for your tuition fees and transact the money.\n");
        scanf("%d",&confirmTransact);
        if(confirmTransact==1)
        {
            *balance-=tutionFeeAmount;
            printf("\nTransaction Successful! Your tuition fees: BDT %.2lf has been paid.\n",tutionFeeAmount);
            FILE *tptr;
            tptr = fopen("transaction_reciept.txt", "a");
            if (tptr == NULL)
            {
                printf("\nUnexpected error ocuured! Sorry for the inconvenience.\n");
                exit(0);
            }
            else
            {
                fprintf(tptr, "\nYour tuition fee: BDT %.2lf \nAfter paying tuition fee your Current balance: BDT %.2lf\n", tutionFeeAmount, *balance);
            }
            fclose(tptr);
        }
    }
    else
    {
        printf("\nYou don't have enough money in your account to pay for your tuition fees!\n");
        return 0;
    }
    return *balance;
}
