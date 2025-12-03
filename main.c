#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double ht(double a)
{
    if(a<=100)
    {
        return (a*4.43)+(a*10);
    }
    else if(a>100 && a<=300)
    {
        return (100*4.43)+((a-100)*9.64)+(a*10);
    }
    else if(a>300 && a<=500)
    {
        return (100*4.43)+(200*9.64)+((a-300)*12.83)+(a*10);
    }
    else if(a>500)
    {
        return (100*4.43)+(200*9.64)+(200*12.83)+((a-500)*14.33)+(a*10);
    }
    return 0;
}

double lt(double b)
{
    if(b<=100)
    {
        return (b*4.43)+100;
    }
    else if(b>100 && b<=300)
    {
        return (100*4.43)+((b-100)*9.64)+100;
    }
    else if(b>300 && b<=500)
    {
        return (100*4.43)+(200*9.64)+((b-300)*12.83)+100;
    }
    else if(b>500)
    {
        return (100*4.43)+(200*9.64)+(200*12.83)+((b-500)*14.33)+100;
    }
    return 0;
}

void main()
{
    long id,tel;
    int i=0;
    int j=0;
    int k=0;
    int type=0;
    int l1,l2;
    double taxc,taxd;
    double unit;
    char name[100];
    int choice;
    FILE *fp;
    char ch;

    while(1)
    {
        printf("\n\n--- MENU ---\n");
        printf("1. Calculate Bill\n");
        printf("2. Display Bill Receipt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                i = 0;
                j = 0;
                k = 0;

                while(i==0)
                {
                    printf("Enter Customer ID: ");
                    scanf("%ld",&id);
                    if (id == 0)
                    {
                        l1=1;
                    }
                    else
                    {
                        l1=floor(log10(fabs(id))) + 1;
                    }
                    if (l1>=10 && l1<=12)
                    {
                        i=1;
                    }
                    else
                    {
                        printf("Invalid Customer ID!\n\n");
                    }
                }
            
                printf("Enter Customer Name: ");
                scanf(" %[^\n]",name);

                while(j==0)
                {
                    printf("Enter Telephone No.:  ");
                    scanf("%ld",&tel);
                    if (tel == 0)
                    {
                        l2=1;
                    }
                    else
                    {
                        l2=floor(log10(fabs(tel))) + 1;
                    }
                    if (l2==10)
                    {
                        j=1;
                    }
                    else
                    {
                        printf("Invalid Telephone No.!\n\n");
                    }
                }
                while(k==0)
                {
                    printf("Enter Customer Type('1' for Commercial/'2' for Domestic): ");
                    scanf("%d",&type);
                    if(type==1 || type==2)
                    {
                        k=1;
                    }
                    else
                    {
                        printf("Invalid Type!\n\n");
                    }
                }
                
                printf("Enter amount of units consumed(kW): ");
                scanf("%lf",&unit);
                
                fp = fopen("bill.txt", "w"); 
                

                if(type==1)
                {
                    taxc=ht(unit);
                    fprintf(fp, "\n\n================================================\n");
                    fprintf(fp, "                ELECTRICITY BILL");
                    fprintf(fp, "\n================================================\n\n");
                    fprintf(fp, "Customer ID: %ld\n",id);
                    fprintf(fp, "Custmer Name: %s\n",name);
                    fprintf(fp, "Telephone No.: %ld\n",tel);
                    fprintf(fp, "Consumer Type: Commercial(HT)\n");
                    fprintf(fp, "Units Consumed: %lf\n",unit);
                    fprintf(fp, "\n================================================\n");
                    fprintf(fp, "          TOTAL AMOUNT:%lf",taxc);
                    fprintf(fp, "\n================================================\n");
                    
                    printf("\nBill calculated and saved successfully.\n");
                }
                else if(type==2)
                {
                    taxd=lt(unit);
                    fprintf(fp, "\n\n================================================\n");
                    fprintf(fp, "                ELECTRICITY BILL");
                    fprintf(fp, "\n================================================\n\n");
                    fprintf(fp, "Customer ID: %ld\n",id);
                    fprintf(fp, "Custmer Name: %s\n",name);
                    fprintf(fp, "Telephone No.: %ld\n",tel);
                    fprintf(fp, "Consumer Type: Domestic(LT)\n");
                    fprintf(fp, "Units Consumed: %lf\n",unit);
                    fprintf(fp, "\n================================================\n");
                    fprintf(fp, "          TOTAL AMOUNT: %lf",taxd);
                    fprintf(fp, "\n================================================\n");

                    printf("\nBill calculated and saved successfully.\n");
                }
                fclose(fp);
                break;

            case 2:
                fp = fopen("bill.txt", "r");
                if (fp == NULL)
                {
                    printf("\nError: File not found! Please calculate the bill first.\n");
                }
                else
                {
                    while ((ch = fgetc(fp)) != EOF)
                    {
                        printf("%c", ch);
                    }
                    fclose(fp);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option! Try again.\n");
        }
    }
}
