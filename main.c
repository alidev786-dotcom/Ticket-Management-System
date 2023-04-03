#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

//############################### Variables to store ticket's prices ##############################

int courtSide_price    ;                //stores courtside ticket price entered by admin
int midLevel_price     ;                //stores midlevel ticket price entered by admin
int upperLevel_price   ;                //stores upperside ticket price entered by admin
int charity_percentage ;                //stores charity percentage entered by admin

int courtSide_sold  = 0  ;              //stores number of courtSide tickets sold out yet
int midLevel_sold   = 0  ;              //stores number of midLevel tickets sold out yet
int upperLevel_sold = 0  ;              //stores number of upperLevel tickets sold out yet

float total_tickets_sale = 0 ;          //stores total sales of ticket
float total_charity = 0 ;               //stores total charity

//############################### function which sets all the data to be entered by admin #####################
bool displayAdminMenu(){
    long int PIN  ;                  //stores pin entered by admin
    int try_count = 0 ;              //stores the number of tries admin has made to enter PIN
    printf("\n\n########################### Welcome To Admin Panel ###########################\n") ;
    printf("Enter admin pin to set up charity ticket sales: ") ;
    scanf("%d",&PIN) ;
    while(PIN!=4932)
    {
        if(try_count>=2)             //if tries are greater than 3, simply exit the program          
        {
            bool r = false ;
            return r ;
        }
        printf("\n\nError! Wrong PIN entered!\n\n") ;
        try_count++ ;
        printf("Enter admin pin to set up charity ticket sales: ") ;
        scanf("%d",&PIN) ;
    }
    char temp[100] ;
    printf("\n\n########################### Taking Tickets Data ###########################\n\n") ;
    printf("Enter the price for COURTSIDE seats: ") ;
    scanf("%s",temp) ;
    if(isdigit(temp[0])==false)
        temp[0] = '0' ;
    courtSide_price = atoi(temp) ;
    while(courtSide_price<=200 || courtSide_price>500)                      //validating input for courtSide ticket
    {
        printf("\n\nCourtSide Ticket price out of range!\n\n") ;
        printf("Enter the price for COURTSIDE seats($): ") ;
        scanf("%s",temp) ;
        if(isdigit(temp[0])==false)
            temp[0] = '0' ;
        if(isdigit(temp[strlen(temp)-1])==false)
            temp[strlen(temp)-1] = '\n' ;
        courtSide_price = atoi(temp) ;
    }
    printf("Enter the price for MIDLEVEL seats: ") ;
    scanf("%s",temp) ;  
    if(isdigit(temp[0])==false)
        temp[0] = '0' ;
    midLevel_price = atoi(temp) ;
    while(midLevel_price<=75 || midLevel_price>200)                         //validating input for mid level ticket
    {
        printf("\n\nmidLevel Ticket price out of range!\n\n") ;
        printf("Enter the price for MIDLEVEL seats($): ") ;
        scanf("%s",temp) ;
        if(isdigit(temp[0])==false)
            temp[0] = '0' ;
        if(isdigit(temp[strlen(temp)-1])==false)
            temp[strlen(temp)-1] = '\n' ;
        midLevel_price = atoi(temp) ;
    }
    printf("Enter the price for UPPERLEVEL seats: ") ;
    scanf("%s",temp) ;
    if(isdigit(temp[0])==false)
        temp[0] = '0' ;
    upperLevel_price = atoi(temp) ;
    while(upperLevel_price<10 || upperLevel_price>75)                       //validating input for upper level ticket
    {
        printf("\n\nupperLevel Ticket price out of range!\n\n") ;
        printf("Enter the price for UPPERLEVEL seats: ") ;
        scanf("%s",temp) ;
        if(isdigit(temp[0])==false)
            temp[0] = '0' ;
        if(isdigit(temp[strlen(temp)-1])==false)
            temp[strlen(temp)-1] = '\n' ;
        upperLevel_price = atoi(temp) ;
    }
    printf("\n\n########################### Taking Charity Data ###########################\n") ;
    printf("Enter the percentage of sales that will go to charity(%): ") ;
    scanf("%s",temp) ;
    if(isdigit(temp[0])==false)
        temp[0] = '0' ;
    charity_percentage = atoi(temp) ;
    while(charity_percentage<5 ||   charity_percentage>25)
    {
        printf("\n\nPercentage out of ranged entered!\n\n") ;
        printf("Enter the percentage of sales that will go to charity(%): ") ;
        scanf("%s",temp) ;
        if(isdigit(temp[0])==false)
            temp[0] = '0' ;
        if(isdigit(temp[strlen(temp)-1])==false)
            temp[strlen(temp)-1] = '\n' ;
        charity_percentage = atoi(temp) ;
    }
    return true ;
}


//################################# Displays summary to admin and quits ##############################
void displaySummaryToAdmin(){
    float charity ;
    float price ;
    printf("\n\nSummary of ticket sales where %d%% goes to charity\n",charity_percentage) ;
    printf("%-15s","Level") ;
    printf("%-15s","Price") ;
    printf("%-15s","Sold") ;
    printf("%-15s","Sales_Total") ;
    printf("%-15s\n","Charity_Total") ;
    printf("%-15s","(C)ourtside") ;
    printf("$%-14d",courtSide_price) ;
    printf("%-15d",courtSide_sold) ;
    printf("$%-15.2d",courtSide_sold*courtSide_price) ;
    price = courtSide_sold*courtSide_price*1.0;
    charity = (charity_percentage/100.0) * price ;
    printf("$%-15.2f\n",charity) ;  

    printf("%-15s","(M)id") ;
    printf("$%-14d",midLevel_price) ;
    printf("%-15d",midLevel_sold) ;
    printf("$%-15.2d",midLevel_sold*midLevel_price) ;
    price = midLevel_price*midLevel_sold*1.0 ;
    charity = (charity_percentage/100.0) * price ;
    printf("$%-15.2f\n",charity) ;

    printf("%-15s","(U)pper") ;
    printf("$%-14d",upperLevel_price) ;
    printf("%-15d",upperLevel_sold) ;
    printf("$%-15.2d",upperLevel_sold*upperLevel_price) ;
    price = upperLevel_sold*upperLevel_price*1.0 ;
    charity = (charity_percentage/100.0) * charity ;
    printf("$%-15.2f\n",charity) ;

    printf("\n\nTotal Ticket Sales: $%.2f\n",total_tickets_sale) ;
    printf("Total Raised for charity: $%.2f\n",total_charity) ;
}


// ################################# Displays ticket's prices and charity to customer #######################
void displayTicketsInformation(){
    printf("\n\nYou can purchase tickets to the Nuggets game and %d%% of your ticket purchase will go to charity\n",charity_percentage) ;
    printf("%-15s","Level") ;
    printf("%-15s\n","Price per person") ;
    printf("%-15s","(C)ourtside") ;
    printf("$%-15d\n",courtSide_price) ;
    printf("%-15s","(M)id Level") ;
    printf("$%-15d\n",midLevel_price) ;
    printf("%-15s","(U)pper Level") ;
    printf("$%-15d",upperLevel_price) ;
    printf("\n\n") ;
}

//################################ Displays receipt to customer #########################
void displayReceipt(char* seat_level, int package, float cost, float charity){
    printf("\n\nDetroit Pistions Charity Ticket Receipt\n") ;
    if(strcmp(seat_level, "C") == 0 || strcmp(seat_level, "c") == 0)
    {
        printf("(C)ourtside\n") ;
    }
    else if(strcmp(seat_level, "M") == 0 || strcmp(seat_level, "m") == 0)
    {
        printf("(M)idlevel\n") ;
    }
    else if(strcmp(seat_level, "U") == 0 || strcmp(seat_level, "u") == 0)
    {
        printf("(U)pperlevel\n") ;
    }
    //displaying package
    if(package==1)
    {
        printf("1: Single Pack\n") ;
    }
    else if(package==2)
    {
        printf("2: Double Pack\n") ;
    }
    else if(package==3)
    {
        printf("3: Triple Pack\n") ;
    }
    else if(package==4)
    {
        printf("4: Family Pack\n") ;
    }
    //displaying total cost
    printf("Total cost: $%.2f\n",cost) ;
    printf("Donation to Charity: %.2f\n",charity) ;
}

//############################# Displays customer menu and book tickets for customer #########################
void displayCustomerMenu(){
    displayTicketsInformation() ;                //displaying all the tickets information to user
    char seat_level[3] ;                            //stores a charater for seat level
    char selection[3]  ;                            //stores for valid selection or not
    printf("Enter your seat level: ") ; int temp ;
    scanf("%s",seat_level) ;
    while(strcmp(seat_level, "C") != 0 && strcmp(seat_level, "c") != 0 && strcmp(seat_level, "M") != 0 && strcmp(seat_level, "m") != 0 && strcmp(seat_level, "U") != 0 && strcmp(seat_level, "u") != 0)
    {
        printf("\n\nPlease enter valid seat level!\n\n") ;
        printf("Enter your seat level: ") ; int temp ;
        scanf("%s",seat_level) ;
    }
    printf("Is this selection [Selection] correct (y)es or (n)o?") ;
    scanf("%s",selection) ;
    if(strcmp(selection, "Y") == 0 || strcmp(selection, "y") == 0)
    {
        int sel ;
        float cost ;
        printf("\n\n#################### Package selection ####################\n\n") ;
        printf("1: Single Pack (1 ticket)\n")  ;
        printf("2: Double Pack (2 tickets)\n") ;
        printf("3: Triple Pack (3 tickets)\n") ;
        printf("4: Family Pack (4 tickets)\n")   ;
        printf("Enter your selection(1-4):") ;
        scanf("%d",&sel) ;
        while(sel<1 || sel>4)
        {
            printf("\n\nPlease enter valid selection!\n\n") ;
            printf("1: Single Pack (1 ticket)\n")  ;
            printf("2: Double Pack (2 tickets)\n") ;
            printf("3: Triple Pack (3 tickets)\n") ;
            printf("4: Family Pack (4 tickets)\n")   ;
            printf("Enter your selection(1-4):") ;
            scanf("%d",&sel) ;
        }
        switch (sel)
        {
        case 1:
        {
            if(strcmp(seat_level, "C") == 0 || strcmp(seat_level, "c") == 0)
            {
                courtSide_sold++ ;
                cost = courtSide_price*1.0 ;
                // printf("check : %f\n",cost) ;
            }
            else if(strcmp(seat_level, "M") == 0 || strcmp(seat_level, "m") == 0)
            {
                midLevel_sold++ ;
                cost = midLevel_price*1.0 ;
            }
            else if(strcmp(seat_level, "U") == 0 || strcmp(seat_level, "u") == 0)
            {
                upperLevel_sold++ ;
                cost = upperLevel_price*1.0 ;
            }
            break;
        }
        case 2:
        {
            if(strcmp(seat_level, "C") == 0 || strcmp(seat_level, "c") == 0)
            {
                courtSide_sold+= 2 ;
                cost = courtSide_price*2.0 ;
            }
            else if(strcmp(seat_level, "M") == 0 || strcmp(seat_level, "m") == 0)
            {
                midLevel_sold+= 2 ;
                cost = midLevel_price*2.0 ;
            }
            else if(strcmp(seat_level, "U") == 0 || strcmp(seat_level, "u") == 0)
            {
                upperLevel_sold+=2 ;
                cost = upperLevel_price*2.0 ;
            }
            break ;
        }
        case 3:
        {
            if(strcmp(seat_level, "C") == 0 || strcmp(seat_level, "c") == 0)
            {
                courtSide_sold+= 3 ;
                cost = courtSide_price*3.0 ;
            }
            else if(strcmp(seat_level, "M") == 0 || strcmp(seat_level, "m") == 0)
            {
                midLevel_sold+= 3 ;
                cost = midLevel_price*3.0 ;
            }
            else if(strcmp(seat_level, "U") == 0 || strcmp(seat_level, "u") == 0)
            {
                upperLevel_sold+=3 ;
                cost = upperLevel_price*3.0 ;
            }
            break ;
        }
        case 4:
        {
            if(strcmp(seat_level, "C") == 0 || strcmp(seat_level, "c") == 0)
            {
                courtSide_sold+= 4.0 ;
                cost = courtSide_price*4.0 ;
            }
            else if(strcmp(seat_level, "M") == 0 || strcmp(seat_level, "m") == 0)
            {
                midLevel_sold+= 4.0;
                cost = midLevel_price*4.0 ;
            }
            else if(strcmp(seat_level, "U") == 0 || strcmp(seat_level, "u") == 0)
            {
                upperLevel_sold+=4 ;
                cost = upperLevel_price*4.0 ;
            }
            break ;
        }
        default:
            break;
        }
        long int ZIP ;
        // printf("\nt: %f\n",cost) ;
        float charity = (charity_percentage/100.0) * cost ;
        // adding cost to total cost and charity to total charity
        total_tickets_sale += cost ;
        total_charity += charity ; 
        char receipt ;
        //now displaying cost to user and asking for credit
        printf("\n\nYour cost is %.2f. Enter your 5 digit ZIP code: ",cost) ;
        scanf("%d",&ZIP) ;
        //input validation for zip code
        while(ZIP<11111 || ZIP>99999)
        {
            printf("\n\nPlease enter valid ZIP code\n\n") ;
            printf("\n\nYour cost is %.2f. Enter your 5 digit ZIP code: ",cost) ;
            scanf("%d",&ZIP) ; 
        }
        printf("Thank you for purchasing tickets. %.2f of the ticket sales will go to charity. Do you want a receipt (y)es or (n)o?",charity);
        scanf("%s",&receipt) ;
        //validation
        while(receipt!='Y' && receipt!='y' && receipt!='N' && receipt!='n')
        {
            printf("Thank you for purchasing tickets. %.2f of the ticket sales will go to charity. Do you want a receipt (y)es or (n)o?",charity);
            scanf("%s",&receipt) ;
        }
        if(receipt=='Y' || receipt=='y')
        {
            displayReceipt(seat_level,sel,cost,charity) ;
        }
        //now asking other customer to book tickets
        displayCustomerMenu() ;
    }
    else if(strcmp(selection, "N") == 0 || strcmp(selection, "n") == 0)
    {
        displayCustomerMenu() ;
    }
    else if (strcmp(selection, "Q") == 0 || strcmp(selection, "q") == 0)
    {
        //asking for admin PIN
        long int PIN  ;                  //stores pin entered by admin
        int try_count = 0 ;              //stores the number of tries admin has made to enter PIN
        printf("\n\n########################### Welcome To Admin Panel ###########################\n") ;
        printf("Enter admin pin: ") ;
        scanf("%d",&PIN) ;
        while(PIN!=4932)
        {
            if(try_count>=2)             //if tries are greater than 3, simply exit the program          
                return  ;
            printf("\n\nError! Wrong PIN entered!\n\n") ;
            try_count++ ;
            printf("Enter admin pin: ") ;
            scanf("%d",&PIN) ;
        }
        displaySummaryToAdmin() ;
        return ;
    }
}   


int main()
{
    // displayTicketsInformation() ;
    bool r = displayAdminMenu() ;
    if(r==true)
    {
        displayCustomerMenu() ;
    }
    return  0 ;
}