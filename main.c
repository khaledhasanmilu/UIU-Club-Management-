#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define max 1000
struct upassin
{
    char user[12];
    char password[16];
} upass[max];
struct Member
{
    char fname[15];
    char lname[15];
    int id;
    int trimester;
    char adress[50];
    char interest[30];
};
void join();
void about();
void delete(char clubfile[50]);
void search(char fname[100]);
void adheader(int);
void memheader(int);
void adminmenu(int club);
void membermenu(char fname[]);
int clubList();
void mainMenu();
void login();
void authentication(int);
int main()
{
    while (1)
    {
        int choice;

        mainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            about();
            break;
        case 2:
            login();
            break;
        case 3:
            join();
            break;
        case 4:
            return 0;
            break;

        default:
            system("cls");
            printf("\t\t\tInvalid Choice !!!\n\n");
            break;
        }
        getchar();
    }

    return 0;
}
void mainMenu()
{   system("cls");
    printf("\n\n\t\t\t====== Club Forum Database Managment ======\n");
    printf("\t\t\t1. About UIU club Forum.\n");
    printf("\t\t\t2. Log in.\n");
    printf("\t\t\t3. How can I Join ?\n");
    printf("\t\t\t4. Exit.\n");
    printf("\t\t\t============================================\n");
    printf("\t\t\tEnter any choice value:");
}
void login()
{
    int x;
    system("cls");
    printf("\t\t\t============ Login Panel ============\n");
    printf("\t\t\t1. Admin Panel\n");
    printf("\t\t\t2. Member Panel\n");
    printf("\t\t\t3. Exit\n");
    printf("\t\t\t=====================================\n");
    printf("\t\t\tChoose your panel: ");
    scanf("%d", &x);
    if (x == 3)
    {
        return;
    }
    else if (x == 1)
    {   
        int ctrl = clubList();
        if (ctrl < 19 && ctrl > 0)
        {
            authentication(ctrl);
        }
        else if (ctrl == 19)
        {
            login();
        }
    }
    else if (x == 2)
    {
        int club = clubList();
        char fname[100] = "record/";

        if (club == 1)
        {
            strcat(fname, "robo.txt");
        }
        else if (club == 2)
        {
            strcat(fname, "comp.txt");
        }
        else if (club == 3)
        {
            strcat(fname, "app.txt");
        }
        else if (club == 4)
        {
            strcat(fname, "sport.txt");
        }
        else if (club == 5)
        {
            strcat(fname, "debat.txt");
        }
        else if (club == 6)
        {
            strcat(fname, "busin.txt");
        }
        else if (club == 7)
        {
            strcat(fname, "cultur.txt");
        }
        else if (club == 8)
        {
            strcat(fname, "sias.txt");
        }
        else if (club == 9)
        {
            strcat(fname, "elf.txt");
        }
        else if (club == 10)
        {
            strcat(fname, "tfc.txt");
        }
        else if (club == 11)
        {
            strcat(fname, "civil.txt");
        }
        else if (club == 12)
        {
            strcat(fname, "photo.txt");
        }
        else if (club == 13)
        {
            strcat(fname, "ssc.txt");
        }
        else if (club == 14)
        {
            strcat(fname, "mun.txt");
        }
        else if (club == 15)
        {
            strcat(fname, "eec.txt");
        }
        else if (club == 16)
        {
            strcat(fname, "mba.txt");
        }
        else if (club == 17)
        {
            strcat(fname, "market.txt");
        }
        else if (club == 18)
        {
            strcat(fname, "hr.txt");
        }
        else if (club == 19)
        {
            return;
        }
        else
        {
            printf("\t\t\tInvalid Choice!!");
        }
        membermenu(fname);
    }

    else
    {
        printf("InValid Choice!!");
        login();
    }
}
void authentication(int club)
{
    char username[12];
    char password[17];
    printf("\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\tEnter user password: ");
    scanf("%s", password);
    char fname[100] = "password/admin/";
    if (club == 1)
    {
        strcat(fname, "robo.txt");
    }
    else if (club == 2)
    {
        strcat(fname, "comp.txt");
    }
    else if (club == 3)
    {
        strcat(fname, "app.txt");
    }
    else if (club == 4)
    {
        strcat(fname, "sport.txt");
    }
    else if (club == 5)
    {
        strcat(fname, "debat.txt");
    }
    else if (club == 6)
    {
        strcat(fname, "busin.txt");
    }
    else if (club == 7)
    {
        strcat(fname, "cultur.txt");
    }
    else if (club == 8)
    {
        strcat(fname, "sias.txt");
    }
    else if (club == 9)
    {
        strcat(fname, "elf.txt");
    }
    else if (club == 10)
    {
        strcat(fname, "tfc.txt");
    }
    else if (club == 11)
    {
        strcat(fname, "civil.txt");
    }
    else if (club == 12)
    {
        strcat(fname, "photo.txt");
    }
    else if (club == 13)
    {
        strcat(fname, "ssc.txt");
    }
    else if (club == 14)
    {
        strcat(fname, "mun.txt");
    }
    else if (club == 15)
    {
        strcat(fname, "eec.txt");
    }
    else if (club == 16)
    {
        strcat(fname, "mba.txt");
    }
    else if (club == 17)
    {
        strcat(fname, "market.txt");
    }
    else if (club == 18)
    {
        strcat(fname, "hr.txt");
    }

    FILE *fp;
    fp = fopen(fname, "r");
    if (access(fname, F_OK))
    {
        printf("File Not Found.You Should create file first.\n");
    }
    else
    {
        int i = 0;
        while (!feof(fp))
        {

            fscanf(fp, "%s", upass[i].user);
            fscanf(fp, "%s", upass[i].password);
            if (strcmp(username, upass[i].user) == 0 && strcmp(password, upass[i].password) == 0)
            {
                system("cls");
                printf("\t\t\tLog in Successfully.\n");
                adminmenu(club);
                return;
            }
            i++;
        }
        printf("InValid User password.\n");
    }
}
int clubList()
{
    int y;
    system("cls");
    printf("\t\t\t======= Here all club list  =========\n\n");
    printf("\t\t\t1.UIU Robotics\n\t\t\t2.UIU Computer Club\n\t\t\t3.UIU APP Forum\n\t\t\t4.UIU Sports Club\n\t\t\t5.UIU Debate Club\n\t\t\t6.UIU Business Club\n\t\t\t7.UIU Cultural Club\n\t\t\t8.UIU Students International Affairs Society\n\t\t\t9.UIU English Language Forum\n\t\t\t10.UIU Theatre & Film Club\n\t\t\t11.UIU Civil Club\n\t\t\t12.UIU Photography Club\n\t\t\t13.UIU Social Services Club\n\t\t\t14.UIU MUN Club\n\t\t\t15.UIU Electrical and Electronics Club\n\t\t\t16.UIU MBA Club\n\t\t\t17.UIU Marketing Forum\n\t\t\t18.UIU HR Forum\n\t\t\t19.Exit\n");
    printf("\t\t\t=====================================\n\n");
    printf("\t\t\tEnter your Choice :");
    scanf("%d", &y);

    if (y > 0 && y < 20)
    {
        return y;
    }
    else
    {
        clubList();
    }
}

void adminmenu(int club)
{

    char fname[100] = "record/";

    if (club == 1)
    {
        strcat(fname, "robo.txt");
    }
    else if (club == 2)
    {
        strcat(fname, "comp.txt");
    }
    else if (club == 3)
    {
        strcat(fname, "app.txt");
    }
    else if (club == 4)
    {
        strcat(fname, "sport.txt");
    }
    else if (club == 5)
    {
        strcat(fname, "debat.txt");
    }
    else if (club == 6)
    {
        strcat(fname, "busin.txt");
    }
    else if (club == 7)
    {
        strcat(fname, "cultur.txt");
    }
    else if (club == 8)
    {
        strcat(fname, "sias.txt");
    }
    else if (club == 9)
    {
        strcat(fname, "elf.txt");
    }
    else if (club == 10)
    {
        strcat(fname, "tfc.txt");
    }
    else if (club == 11)
    {
        strcat(fname, "civil.txt");
    }
    else if (club == 12)
    {
        strcat(fname, "photo.txt");
    }
    else if (club == 13)
    {
        strcat(fname, "ssc.txt");
    }
    else if (club == 14)
    {
        strcat(fname, "mun.txt");
    }
    else if (club == 15)
    {
        strcat(fname, "eec.txt");
    }
    else if (club == 16)
    {
        strcat(fname, "mba.txt");
    }
    else if (club == 17)
    {
        strcat(fname, "market.txt");
    }
    else if (club == 18)
    {
        strcat(fname, "hr.txt");
    }
    else if (club == 19)
    {
        return;
    }
    else
    {
        printf("\t\t\tInvalid Choice!!");
    }

    while (1)
    {
        int n;
        adheader(club);
        printf("\n\n\t\t\tEnter your Choice :");
        scanf("%d", &n);
        if (n == 1)
        {
            FILE *fp;
            struct Member info;
            fp = fopen(fname, "a+");
            getchar();
            printf("\t\t\tEnter First name : "); // add member
            scanf("%s", info.fname);
            printf("\t\t\tEnter Last name : ");
            scanf("%s", info.lname);
            printf("\t\t\tEnter Student id : ");
            scanf("%d", &info.id);
            printf("\t\t\tEnter Trimester : ");
            scanf("%d", &info.trimester);
            getchar();
            printf("\t\t\tEnter Address : ");
            fgets(info.adress, sizeof(info.adress), stdin);
            printf("\t\t\tInterested In :");
            fgets(info.interest, sizeof(info.interest), stdin);
            fwrite(&info, sizeof(struct Member), 1, fp);
            fclose(fp);
            printf("\t\t\tPress any key to continue.....");
            getchar();
            system("cls");
            printf("\t\t\tData store successfully.\n");

        }
        else if (n == 2)
        {
            // record
            struct Member info;
            FILE *fp;
            fp = fopen(fname, "r");
            if (fp == NULL)
            {
                printf("\t\t\tUnable to open file\n\n");
            }
            else
            {
                system("cls");
                printf("\t\t\t======  Member record =======\n\n");
                while (fread(&info, sizeof(struct Member), 1, fp))
                {
                    printf("\t\t\tMember Name   : %s %s\n", info.fname, info.lname);
                    printf("\t\t\tID            : %d\n", info.id);
                    printf("\t\t\tTrimester     : %d\n", info.trimester);
                    printf("\t\t\tAddress       : %s", info.adress);
                    printf("\t\t\tInterested In : %s\n\n", info.interest);
                }
            }
            fclose(fp);
            printf("\t\t\tEnter any key to continue.....");

            getchar();
            getchar();
            system("cls");
        }
        else if (n == 3)
        {
            search(fname);
        }
        else if (n == 4)
        {
            delete (fname);
        }
        else if (n == 5)
        {
            system("cls");
            return;
        }
        else
        {
            printf("Invalid Input??");
        }
    }
}

void membermenu(char fname[50])
{
   
    while (1)
    {    system("cls");
        printf("\n\t\t\t======== Welcome Back =========\n");
        printf("\t\t\tWhat can you do now?\n");
        printf("\t\t\t1. Search Member.\n\t\t\t2. Exit.\n");
        printf("\t\t\t=================================\n");
        printf("\t\t\tEnter your choice : ");
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            search(fname);
        }
        else if (n == 2)
        {
            break;
        }
        else{
            printf("\t\t\tInValid !!!\n");
            printf("\t\t\tEnter any key to continue.....!\n");
            getchar();
            getchar();

        }
    }
}
void adheader(int club)
{
    printf("\t\t\t============= Welcome ===============\n");
    printf("\t\t\tWhat can you do now?\n");
    printf("\t\t\t1. Add member.\n\t\t\t2. Member Records.\n\t\t\t3. Search Member Records.\n\t\t\t4. Delete Members Record.\n\t\t\t5. Exit.\n");
    printf("\t\t\t=====================================\n");
}

void search(char fname[100])
{
    FILE *fp;
    struct Member info;
    int sid, found = 0;
    fp = fopen(fname, "a+");
    getchar();
    printf("\t\t\tEnter ID to search : "); // search member
    scanf("%d", &sid);
    while (fread(&info, sizeof(struct Member), 1, fp))
    {
        if (sid == info.id)
        {
            found = 1;
            printf("\t\t\tMember Name   : %s %s\n", info.fname, info.lname);
            printf("\t\t\tID            : %d\n", info.id);
            printf("\t\t\tTrimester     : %d\n", info.trimester);
            printf("\t\t\tAddress       : %s", info.adress);
            printf("\t\t\tInterested In : %s\n\n", info.interest);
        }
    }
    if (!found)
    {
        printf("\t\t\tNot found any member");
    }
    fclose(fp);
}

void delete(char clubfile[50])
{
    struct Member info;
    FILE *fp, *fp1;

    int did, found = 0;
    fp = fopen(clubfile, "r");

    char tempfile[100];
    strcpy(tempfile, clubfile);
    strcat(tempfile, ".txt");

    fp1 = fopen(tempfile, "w");
    printf("\t\t\t\tEnter ID no : ");
    scanf("%d", &did);
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }

    while (fread(&info, sizeof(struct Member), 1, fp))
    {
        if (info.id == did)
        {

            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct Member), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        printf("\n\t\t\t\tRecord not found\n");
    }
    if (found)
    {
        remove(clubfile);
        rename(tempfile, clubfile);

        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }

    getchar();
}
void about()
{
    system("cls");
    while (1)
    {   printf("\t\t=========== club list ==========\n\n");
        printf("\t\t\t1.UIU Robotics\n\t\t\t2.UIU Computer Club\n\t\t\t3.UIU APP Forum\n\t\t\t4.UIU Sports Club\n\t\t\t5.UIU Debate Club\n\t\t\t6.UIU Business Club\n\t\t\t7.UIU Cultural Club\n\t\t\t8.UIU Students International Affairs Society\n\t\t\t9.UIU English Language Forum\n\t\t\t10.UIU Theatre & Film Club\n\t\t\t11.UIU Civil Club\n\t\t\t12.UIU Photography Club\n\t\t\t13.UIU Social Services Club\n\t\t\t14.UIU MUN Club\n\t\t\t15.UIU Electrical and Electronics Club\n\t\t\t16.UIU MBA Club\n\t\t\t17.UIU Marketing Forum\n\t\t\t18.UIU HR Forum\n\t\t\t19.Exit\n");
        printf("\t\t================================\n");
        int n4;
        printf("\n\n\t\t\tMore about any club?\n\t\t\tClick:");
        scanf("%d", &n4);
        system("cls");
        switch (n4)
        {
        case 1:
            printf("\t\t\t\t\t----UIU Robotics Club----\n");
            printf("UIU Robotics club is one of the most renowned club in the versity of UIU.UIU Robotics is a student-run club of undergraduate and graduate students from United International University. The purpose of the Organization is to explore new engineering technology, learn crucial skills and promote the field of robotics.\n");
            break;
        case 2:
            printf("\t\t\t\t\t----UIU Computer Club----\n");
            printf("UIU Computer Club has objectives are to widen the scope of our members to make them prepare for the competitive software and IT industry.They have aim to impart knowledge that is not usually covered in mainstream areas therefore it will be beneficial to our members.\n");
            break;
        case 3:
            printf("\t\t\t\t\t----UIU APP Forum----\n");
            printf("UIU APP Forum is an initiative of UIU CCC. It's the platform to bring App Idea, Experience Design, Programming and Marketing on one table.\n");
            break;
        case 4:
            printf("\t\t\t\t\t----UIU Sports Club----\n");
            printf("UIU Sports club is one of the most renowable club in the versity of UIU.It's a page for United International University's sports club where everyone can find the news and updates of UIU sports.\n");
            break;
        case 5:
            printf("\t\t\t\t\t----UIU Debate Club----\n");
            printf("UIU Debate Club participated in World University Debate Championship (WUDC) 2013, at four different universities in the United Kingdom (UK)\n");
            break;
        case 6:
            printf("\t\t\t\t\t----UIU Business Club----\n");
            printf("UIU Business Club is committed to providing thought leadership to entrepreneurs and those who seek to support entrepreneurs.\n");
            break;
        case 7:
            printf("\t\t\t\t\t----UIU Cultural Club----\n");
            printf("UIU cultural club is the place where students can showcase what they have got. It helps to discover their talent and give opportunity show an  incredible way to present.\n");
            break;
        case 8:
            printf("\t\t\t\t\t----UIU Students International Affairs Society----\n");
            printf("UIU Students International Affairs Society is one of the most renowable club in the versity of UIU.Its work for students whom are interested to go abroad for study.\n");
            break;
        case 9:
            printf("\t\t\t\t\t----UIU English Language Forum---\n");
            printf("UIU English Language Forum consists of the students of UIU who are eager to improve their English language proficiency & Career also. To develop our language skills, seminar, workshops, interactive sessions, study circle etc will be arranged.\n");
            break;
        case 10:
            printf("\t\t\t\t\t----UIU Theatre & Film Club----\n");
            printf("UIU theatre club is for students in pursuit of an acting career in film or theatre.The experience of a lifetime! UIU Theatre & Film Club welcomes all theatre & film lovers to bring new energy in the every new semester.\n");
            break;
        case 11:
            printf("\t\t\t\t\t----UIU Civil Club----\n");
            printf("UIU Civil club is one of the most renowable club in the versity of UIU.This club build their member thought for todays competitive world.\n");
            break;
        case 12:
            printf("\t\t\t\t\t----UIU Photography Club----\n");
            printf("UIU photography club is one of the most renowable club in the versity of UIU.Lots have students and faculty are interested about photography.This club work for this type of excelent work.\n");
            break;
        case 13:
            printf("\t\t\t\t\t----UIU Social Services Club----\n");
            printf("UIU Social Service Club is formed to help students to gather experiences, stay active, share life experiences, be social, and so on.\n");
            break;
        case 14:
            printf("\t\t\t\t\t----UIU MUN Club----\n");
            printf("The UIU MUN Club aspires to create global leaders by organising workshops which will help students acquire leadership and diplomatic skills.\n");
            break;
        case 15:
            printf("\t\t\t\t\t----UIU Electrical and Electronics Club----\n");
            printf("UIUEEC is the first engineering students' club of UIU. The club works with the motto “Innovation and Excellence to Asymptote”.\n");
            break;
        case 16:
            printf("\t\t\t\t\t----UIU MBA club-----\n");
            printf("UIU MBA Forum is a forum for students to exhibit their talents and discover new ones.\n");
            break;
        case 17:
            printf("\t\t\t\t\t----UIU Marketing Forum----\n");
            printf("UIU Marketing Forum-UIUMF commemorates this day by recognizing the daily struggles of workers and laborers world wide and applauding their efforts in UIU.\n");
            break;
        case 18:
            printf("\t\t\t\t\t----UIU HR Forum---\n");
            printf("UIU HR Forum is a non-profit association which is run by a group of individuals covering a wide range of diversity and interests who share a common belief in young business student’s ability to innovate and improvise skill in a way that will ensure higher organizational excellence.\n");
            break;
        case 19:
            system("cls");
            return;
            break;
        default:
            printf("\t\t\tInvalid Input!!\n");
            break;
        }

        printf("\n\n\t\t\t\t\tPress any key to continue.....");
        getchar();
        getchar();
        system("cls");
    }
}

void join()
{   int n;
    system("cls");
    printf("\t\t\t================  Join =====================\n");
    printf("\t\t\t1.Club Committe.\n\t\t\t2.General Member.\n");
    printf("\t\t\t============================================\n\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d", &n);
    switch (n)
    {
    case 1:

        printf("\n\t\t\tGo to Home page and click-2 then choose your selective panel.\n\t\t\tThank you.\n");
        printf("\t\t\tEnter any key to continue....");
        getchar();
        getchar();
        system("cls");
        main();
        break;
    case 2:
        printf("\n\t\t\tGo to Home page and Click-2 then choose your selective panel.\n\t\t\tThank You.\n");
        printf("\t\t\tEnter any key to continue....");
        getchar();
        getchar();
        system("cls");
        main();
        break;
    default:
        system("cls");
        printf("\n\n\t\t\tINvalid!!\n\n\n");
        printf("\t\t\tEnter any key to continue....");
        getchar();
    }
}