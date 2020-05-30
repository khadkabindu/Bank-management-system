#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>


struct user {
    char name[20];
    int age;
    char gender[10];
    char address[20];
    char account_type[20];
    char occupation[20];
    int monthly_income;
    int Phone_number;
    int pin_number;
    int current_amount;
};

struct user a;
void selecting_options(struct user);

void withdraw_cash(struct user);         // Functions

void balance_enquiry(struct user a);

void change_pin_number(struct user);

void fund_transfer(struct user a);

void login_to_account(struct user a);


void repeat_task(struct user);

int insert_user(struct user a);
int parseResult(void *, int, char **, char **);

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;

}

int rc;
sqlite3 *db;
char *zErrMsg = 0;
char *sql;
char **argv;
struct user a;
int r;
int r1;
int main() {

    int choice1;


    /* Open database */
    rc = sqlite3_open("bank.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    printf("\t\t\t\t __________________________________________________________________\n");
    printf("\t\t\t\t|                 Welcome To Sagarmatha ATM Service                |\n");
    printf("\t\t\t\t|__________________________________________________________________|\n");
    printf("\t\t\t\t|                     1.Create an account                          |\n");
    printf("\t\t\t\t|                     2.Login to your account                      |\n");
    printf("\t\t\t\t|__________________________________________________________________|\n\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice1);

    switch (choice1) {
        case 1:
            insert_user(a);
            break;
        case 2:
            login_to_account(a);
            break;
    }

//    insert_user(a);
//    selecting_options(a);
//
//    repeat_task(a);

    return 0;
}

int insert_user(struct user a) {
    printf("\t\t\t\t __________________________________________________________________\n");
    printf("\t\t\t\t|          To create account fill up the following details         |\n");
    printf("\t\t\t\t|__________________________________________________________________|\n");
    printf("\n Name: ");
    scanf("%s", a.name);
    printf(" Age: ");
    scanf("%d", &a.age);
    printf(" Gender: ");
    scanf("%s", a.gender);
    printf(" Address: ");
    scanf("%s", a.address);
    printf(" Account type: ");
    scanf("%s", a.account_type);
    printf(" Occupation: ");
    scanf("%s", a.occupation);
    printf(" Monthly income: ");
    scanf("%d", &a.monthly_income);
    printf(" Phone number: ");
    scanf("%d", &a.Phone_number);
    printf(" Four digit pin number:");
    scanf("%d", &a.pin_number);
    printf(" Your current amount:");
    scanf("%d", &a.current_amount);
    sql = "Create table user_data ("\
   "id  INTEGER PRIMARY KEY NOT NULL, name text, age integer not null, gender text, address text, account_type text, occupation text, "
          "monthly_income integer not null, phone_number integer, pin_number integer not null,current_amount integer not null,account_number not null);";

    int r = rand() % 2 + 4500;
    char *query = sqlite3_mprintf(
            "insert into user_data (name, age, gender, address, account_type,occupation, monthly_income, phone_number, "
            "pin_number,current_amount,account_number) "
            "values ('%q', '%u', '%q', '%q','%q','%q','%u','%u','%u','%u','%d');",
            a.name,
            a.age,
            a.gender, a.address, a.account_type, a.occupation, a.monthly_income, a.Phone_number, a.pin_number,
            a.current_amount,r);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, query, callback, 0, &zErrMsg);


    printf("\t\t\t\t<------------------------------------------------------------------->\n");
    printf("\t\t\t\t                    Welcome to Your account %s                  \n",a.name);
    printf("\t\t\t\t<------------------------------------------------------------------->\n");
    printf("\t\t\t\t                Your account number is %d                      \n", r);
    printf("\t\t\t\t<------------------------------------------------------------------->\n");






    selecting_options(a);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "\nTable created successfully\n");
    }
    sqlite3_close(db);
    return 0;

}

void selecting_options(struct user a) {

    int choice2;
    printf("\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t|               1.Withdraw Cash      2.Balance Enquiry              |\n");
    printf("\t\t\t\t|               3.Change pin number  4.Fund Transfer                |\n");
    printf("\t\t\t\t|               5.Deposit cash                                      |\n");
    printf("\t\t\t\t|___________________________________________________________________|\n");

    printf("\nEnter your choice  for further process: ");
    scanf("%d", &choice2);
    switch (choice2) {
        case 1:
            withdraw_cash(a);
            break;
        case 2:
            balance_enquiry(a);
            break;
        case 3:
            change_pin_number(a);
            break;

        case 4: fund_transfer(a);
            break;

    }
}


void withdraw_cash(struct user a) {

    int amt_to_be_withdrawn, current_balance = 0;
    printf("Enter amount to be Withdrawn: ");
    scanf("%d", &amt_to_be_withdrawn);
    if (amt_to_be_withdrawn > (a.current_amount - 500)) {
        printf("Not sufficient balance.");
    } else {
        current_balance = a.current_amount - amt_to_be_withdrawn;
        printf("\t\t\t\t ___________________________________________________________________\n");
        printf("\t\t\t\t|                please collect your cash                           |\n");
        printf("\t\t\t\t|___________________________________________________________________|\n");
        printf("\t\t\t\t           Your current balance is %d                         \n", current_balance);
        printf("\t\t\t\t|___________________________________________________________________|\n\n");

        char *query = sqlite3_mprintf("UPDATE user_data SET current_amount=%d where pin_number=%d",current_balance,a.pin_number);
        rc = sqlite3_exec(db, query, callback, 0, &zErrMsg);


    }
//    repeat_task(a);


}

void repeat_task(struct user a) {
    int choice3;
    printf("\t\t\t\t __________________________________________________________________\n");
    printf("\t\t\t\t|         Do you want to perform another task?                      |\n");
    printf("\t\t\t\t|___________________________________________________________________|\n");
    printf("\t\t\t\t|        If yes then press '1' else press '2'                       |\n");
    printf("\t\t\t\t|___________________________________________________________________|\n");
    printf("\n\nEnter one among '1' and '2': ");
    scanf("%d", &choice3);
    if (choice3 == 1) {
        selecting_options(a);
    } else if (choice3 == 2) {
        printf("\t\t\t\t ___________________________________________________________________\n");
        printf("\t\t\t\t|               Thank you!! please visit again :-)                   |\n");
        printf("\t\t\t\t|____________________________________________________________________|\n");

    }


}

void balance_enquiry(struct user a) {

    printf("\t\t\t\t<------------------------------------------------------------------->\n");
    printf("\t\t\t\t       Your total balance is %d ", a.current_amount);
    printf("\t\t\t\t<------------------------------------------------------------------->\n");


}

void change_pin_number(struct user a) {
    int new_pin, check_pin;
    printf("\nPlease enter your previous pin number: ");
    scanf("%d", &check_pin);
    printf("%d : %d",a.pin_number,check_pin);
    if(check_pin == a.pin_number)
    {
        printf("\n\nPlease enter your new pin number: ");
        scanf("%d", &new_pin);
        char *query = sqlite3_mprintf("UPDATE user_data SET pin_number=%d WHERE pin_number= %d", new_pin, a.pin_number);
        rc = sqlite3_exec(db, query, callback, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            printf("\t\t\t\t ____________________________________________________________________\n");
            printf("\t\t\t\t|                 Pin number changed successfully                    |\n");
            printf("\t\t\t\t|____________________________________________________________________|\n");
            printf("\t\t\t\t|                   Your new pin number is %d                    |\n", new_pin);
            printf("\t\t\t\t|____________________________________________________________________|\n");

        }

    } else {
        printf("\t\t\t\t ____________________________________________________________________\n");
        printf("\t\t\t\t|                   Please enter a valid pin number                  |\n");
        printf("\t\t\t\t|____________________________________________________________________|\n");
    }

//    repeat_task(a);


}

void login_to_account(struct user a) {

    int test_pin_no;
    printf("Enter your pin number: ");
    scanf("%d", &test_pin_no);

    char *query = sqlite3_mprintf("select * from user_data WHERE pin_number= %d", test_pin_no);
    rc = sqlite3_exec(db, query, parseResult, 0, &zErrMsg);

//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//
//    }
}

int parseResult(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;

    printf("\t\t\t\t<------------------------------------------------------------------->\n");
    printf("\t\t\t\t                  Welcome to Your account %s                            \n", argv[1]);
    printf("\t\t\t\t<------------------------------------------------------------------->\n");


    a.pin_number = atoi(argv[9]);
    a.current_amount = atoi(argv[10]);
    r = atoi(argv[11]);
    r = atoi(argv[11]);


    selecting_options(a);
    repeat_task(a);

    return 0;
}


void fund_transfer(struct user a)
{
    int recipient_ac_no, user_ac_no,sending_amt;

    printf("Enter your account number:");
    scanf("%d",&user_ac_no);

    char *query2 = sqlite3_mprintf("SELECT * from user_data where account_number= %d",user_ac_no);
    rc = sqlite3_exec(db, query2, callback, 0, &zErrMsg);

    printf("%d:%d",r,user_ac_no);


    printf("Enter account number of recipient:");
    scanf("%d",&recipient_ac_no);

    char *query3 = sqlite3_mprintf("SELECT * from user_data where account_number= %d",recipient_ac_no);
    rc = sqlite3_exec(db, query3, callback, 0, &zErrMsg);

    printf("%d : %d",r1,recipient_ac_no);

    if(user_ac_no == r && recipient_ac_no == r1)
    {
        printf("Enter the amount to be send: ");
        scanf("%d",&sending_amt);

        char *query4 = sqlite3_mprintf("UPDATE user_data set current_amount = %d + %d where account_number = %d",a.current_amount,sending_amt,recipient_ac_no);
        rc = sqlite3_exec(db, query4, callback, 0, &zErrMsg);

        char *query5 = sqlite3_mprintf("UPDATE user_data set current_amount = %d - %d where account_number = %d",a.current_amount,sending_amt,user_ac_no);
        rc = sqlite3_exec(db, query5, callback, 0, &zErrMsg);

        printf("\t\t\t\tAmount transferred successfully\n");
        printf("\t\t\t\tYour remaining balance is %d",a.current_amount);
    }
    else
    {
        printf("\t\t\t\tPlease enter a valid account number\n");
    }


}
