#include <Stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Customer_details
{
    int cust_Num;
    char Name[50];
    long long int Acc_Num;
    char Password[15];
    int Balance;
    char Account_statement[500];
};
void create_acc(struct Customer_details *Customer);
void Customer_Interface(struct Customer_details *Customer, int *Ac_balance, int Fun_value);
void Withdraw(struct Customer_details *Customer, int *Ac_balance, int Fun_value);
void Deposit(struct Customer_details *Customer, int *Ac_balance, int Fun_value);
int search_acc(struct Customer_details *Customer);
void Print_Cus_detail(struct Customer_details *Customer, int i);
void Acc_statem(struct Customer_details *customer, int i, char DorC_status[35], int money);
 void footer();

// variable

int Expt_Cust = 200;
char input_cmd();
int Opt_cmd = 1;

int main()
{
    struct Customer_details Customer[Expt_Cust];
    do
    {

    printf("\n");
    system("cls"); // clear screen
    printf("-->-->--> WELCOME <--<--<--\n\n");
        printf("\n");
        printf("--> Log In  Type[L]\n");
        printf("--> Sign Up  Type[S]\n");
        printf("--> Exist  Type[E]\n\n\n\n");
        
        // footer();
        printf("\n");

        char Login_input;
        scanf(" %c", &Login_input);
        printf("\n");

        int Fun_value;

        switch (Login_input)
        {
        case 'L':
        case 'l':

            Fun_value = search_acc(Customer);
            if (Fun_value > 0)
            {
                int *Ac_balance = &Customer[Fun_value].Balance;
                Print_Cus_detail(Customer, Fun_value);
                Customer_Interface(Customer, Ac_balance, Fun_value);
            }

            break;

        case 'S':
        case 's':
        system("cls");
            create_acc(Customer);
            break;
        case 'E':
        case 'e':
            Opt_cmd = 0;
            break;
            ;

        default:
            break;
        }
    } while (Opt_cmd);

    printf("\n");
    printf("!!!!!!!!!!!!!!!!!!!!! System Sign Off !!!!!!!!!!!!!!!!!!!\n");

    getch();
    return 0;
}

// functions----------------------------------------------------------------

void Acc_statem(struct Customer_details *Customer, int i, char DorC_status[35], int money)
{
    char Account_statement[100];
    sprintf(Account_statement, "%s | %s | %s | %d  | %d\n", __DATE__, __TIME__, DorC_status, money, Customer[i].Balance);
    strcat(Customer[i].Account_statement, Account_statement);
}
// function to take input for running or terminating of loop
char input_cmd()
{
    char input_cmd;
    scanf(" %c", &input_cmd);
    printf("\n");
    return input_cmd;
}
// function to search accoun number for data base;
int search_acc(struct Customer_details *Customer)
{
    system("cls");
    int Login_check = 0;
    do
    {
        Opt_cmd = 1;

        printf("Enter your Account number:");
        long long int AcNum;
        scanf("%lld", &AcNum);

        printf("\n");
        int q;

        for (q = 1; q <= Expt_Cust; q++)
        {
            if (AcNum == Customer[q].Acc_Num)
            {
                Opt_cmd = 1;
                q = Expt_Cust + q;
            }
            else
            {
                Opt_cmd = 0;
            }
        }
        q = q - Expt_Cust - 1;
        if (Opt_cmd)

        {
            do
            {
                getchar();

                printf("Enter your password:");
                char Pass[15];
                fgets(Pass, 15, stdin);
                Pass[strcspn(Pass, "\n")] = '\0';

                Login_check = strcmp(Pass, Customer[q].Password);

                if (Login_check == 0)
                {
                    Login_check = q;
                    printf("Authenticating");
                    for (int w = 0; w < 50; w++)
                    {
                        printf(".");
                    }
                    printf("\n");
                    Opt_cmd = 0;
                }
                else
                {
                    Login_check = 0;
                    int local_cmd = 0;
                    do
                    {

                        printf("\n!!Invalid Password!!\n");
                        printf("\t-->For Reenter. Type[R] \n");
                        printf("\t-->For Exist. Type[E] \n");
                        switch (input_cmd())
                        {
                        case 'R':
                        case 'r':
                            Opt_cmd = 1;
                            local_cmd = 0;

                            break;
                        case 'E':
                        case 'e':
                            Opt_cmd = 0;
                            local_cmd = 0;
                            break;

                        default:
                            printf("!!Invalid Command!!");
                            local_cmd = 1;
                            break;
                        }
                    } while (local_cmd);
                }
            } while (Opt_cmd);
        }
        else
        {
            printf("!!Invalid Account Number!!\n");
            Opt_cmd = 1;
        }
    } while (Opt_cmd);
    Opt_cmd = 1;
    return Login_check;
}

// Function to create
void create_acc(struct Customer_details *Customer)

{
    Customer[0].cust_Num += 1;
    int i = Customer[0].cust_Num;

    Customer[i].Acc_Num = 18001906907 + i;
    // Customer[0].Acc_Num=Customer[0].Acc_Num++;
    long long int Ac = Customer[i].Acc_Num;

    getchar();
    printf("Enter Your Name:");
    fgets(Customer[i].Name, 50, stdin);
    Customer[i].Name[strcspn(Customer[i].Name, "\n")] = '\0';

    printf("Create your password :");
    fgets(Customer[i].Password, 15, stdin);
    Customer[i].Password[strcspn(Customer[i].Password, "\n")] = '\0';
    printf("\n\n");

    system("cls");
    printf("Hello! %s,\n", Customer[i].Name);
    printf("Your Customer number is: #_%d\n", i);
    printf("Your Account Number is %lld\n", Ac);
    printf("Your Password is: %s\n\n", Customer[i].Password);

    printf("Note it for login\n\n");
    printf("-->-->-->Congrataulation!!Your account has been created successfully <--<--<--\n\n\n");
    footer();
    getch();
    system("cls");
}

// Function to create customer interface -- logging;
void Customer_Interface(struct Customer_details *Customer, int *Ac_balance, int Fun_value)
{

    do
    {
        Opt_cmd = 1;
        printf("HOME\n\t-->For Deposit. Type[D]\n\t-->For Withdraw. Type[W]\n\t-->For Account Balance enquiry. Type[B]\n\t-->For Account Statement. Type[S] \n\t-->For Return to main menu. Type[R]\n\n\n\n\n");

        footer();

        switch (input_cmd())
        {

        case 'D':
        case 'd':
            Deposit(Customer, Ac_balance, Fun_value);
            break;
        case 'W':
        case 'w':
            Withdraw(Customer, Ac_balance, Fun_value);
            break;
        case 'B':
        case 'b':
            system("cls");
            printf("Your Current Account balance is Rs%d.\n\n", *Ac_balance);
            break;
        case 'S':
        case 's':
        system("cls");
        printf("Account statement:\n");
            printf("%s\n\n\n\n\n", Customer[Fun_value].Account_statement);
            footer();
            printf("Press Enter for Return to Previous menu\n\n");
            getch();
            break;
        case 'R':
        case 'r':
            Opt_cmd = 0;
            break;

        default:
            printf("Invalid Command!. Type again\n");
            input_cmd();

            break;
        }
    } while (Opt_cmd);
    Opt_cmd = 1;
}

void Deposit(struct Customer_details *Customer, int *Ac_balance, int Fun_value)
{
    int Money;
    do
    {

        printf("Enter the Amount for deposit: Rs");

        scanf("%d", &Money);
        printf("\n");
        *Ac_balance = *Ac_balance + Money;
        printf("Deposited successfully!\n");
        printf("Your Current Account balance is Rs%u\n.\n", *Ac_balance);
        Acc_statem(Customer, Fun_value, "Debited ", Money);
        int local_case;
        do
        {
            local_case = 1;

            printf("\t-->For Deposit again. Type[D]\n");
            printf("\t-->For Return. Type[R]\n");
            switch (input_cmd())
            {
            case 'D':
            case 'd':
                Opt_cmd = 1;
                local_case = 0;
                break;
            case 'R':
            case 'r':
                Opt_cmd = 0;
                local_case = 0;
                system("cls");
                break;

            default:
                printf("Invalid Command!\n Type Again!\n");
            }
        } while (local_case);

    } while (Opt_cmd);
    Opt_cmd = 1;
}
void Withdraw(struct Customer_details *Customer, int *Ac_balance, int Fun_value)

{
    int Money;
    do
    {

        printf("Enter the Amount for Withdraw: Rs");

        scanf("%d", &Money);
        printf("\n");
        *Ac_balance = *Ac_balance - Money;
        printf("Rs%d Withdraw!\n", Money);
        printf("Your Current Account balance is Rs%u\n.\n", *Ac_balance);
        Acc_statem(Customer, Fun_value, "Credited", Money);
        int local_case;
        do
        {
            local_case = 1;

            printf("\t-->For Withdraw again. Type[w]\n");
            printf("\t-->For Return Previous Menu. Type[R]\n");
            switch (input_cmd())
            {
            case 'W':
            case 'w':
                Opt_cmd = 1;
                local_case = 0;
                break;
            case 'R':
            case 'r':
                Opt_cmd = 0;
                local_case = 0;
                break;

            default:
                printf("Invalid Command!\n Type Again!\n");
            }
        } while (local_case);

    } while (Opt_cmd);
    Opt_cmd = 1;
}

// function to print detail;
void Print_Cus_detail(struct Customer_details *Customer, int i)
{
    system("cls");
    printf("Hello! %s\n", Customer[i].Name);
    printf("Your Bank Details:\n");
    printf("\t-->Your Customer Id is:#00%d\n", i);
    printf("\t-->Account Number:%lld\n", Customer[i].Acc_Num);
    printf("\t-->Account Balance:%d\n", Customer[i].Balance);
}
void footer()
{
    printf("\n\n");
    printf("Copyright reserved by\n");
    printf("_____________________________________________________________________________________\n\n");
    printf("     **********     **      **     ***** *        **********     **********\n");
    printf("     **             **      **     **      *      **      **           **  \n");
    printf("     **             **      **     **       *     **      **           **  \n");
    printf("     **             **      **     **      *      **      **           **  \n");
    printf("     **********     **      **     **    *        **********     **    **  \n");
    printf("             **     **      **     *** *          **      **     **    **  \n");
    printf("             **     **      **     **    *        **      **     **    **  \n");
    printf("             **     **      **     **      *      **      **     **    **  \n");
    printf("     **********     **********     **       *     **      **     ********  \n");
    printf("_____________________________________________________________________________________\n");
}
