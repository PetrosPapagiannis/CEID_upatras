#include <stdio.h>
#include <string.h>

struct order {
    int codenumber;
	char name[20];
    unsigned int day1;
	unsigned int month1;
	unsigned int year1;
    unsigned int day2;
	unsigned int month2;
	unsigned int year2;
	unsigned int smallb;
	unsigned int bigb;
    float cost;
	float finalcost;
    int excecuted_flag;
};
int User_Command(void);
struct order orders[100];
void Get_Order(int x);
void Calculate_Cost(void);
void Calculate_Final_Cost(void);
void Display_Unexcecuted_Orders(void);
void Display_orders(void);
//
//
void Display_Excecuted_Orders(void);
void Display_Customer_Order(void);
//
//
void print_order(void);

int main(){
    int user_choice;
    int i=0;
    do {
    user_choice=User_Command();
    switch(user_choice){
        case 0:
            puts("The application has ended.");
            break;
        case 1:
            Get_Order(i);
            i++;
            break;
        case 2:
            Display_orders();
            Calculate_Cost();
            break;
        case 3:
            Display_orders();
            Calculate_Final_Cost();
            break;
        case 4:
            Display_Unexcecuted_Orders();
            break;
        case 5:
            Display_Excecuted_Orders();
            break;
        case 6:
            Display_orders();
            Display_Customer_Order();
            break;
        default:
            puts("No valuable value.\n");
            break;
    }
    if (user_choice!=0){
        puts("Give your new choice:");
        puts("");
    }      
    } while (user_choice!=0);
    
    system("pause");
    return 0;
}

int User_Command(void){
    int check;
    printf("Give '0' to end.\nGive '1' to enter new order.\nGive '2' calculate the order's cost.\n");
    printf("Give '3' to calculate the order's final cost.\nGive '4' to see the unexcecuted orders.\nGive '5' to see the excecuted orders.\n");
    printf("Give '6' to see the orders from a customer of your choice.\n");
    printf("Give your choice:");
    scanf("%d", &check);
    return check;
}

void Get_Order(int x){
    printf("Give the code number of the order:");
    scanf("%d", &orders[x].codenumber);
    printf("Give customer's name:");
    scanf("%s", orders[x].name);
    printf("Give the day/month/year of the order:");
    scanf("%u/%u/%u", &orders[x].day1, &orders[x].month1, &orders[x].year1);
    printf("Give the number of the small botlles of the order:");
    scanf("%u", &orders[x].smallb);
    printf("Give the number of the big botlles of the order:");
    scanf("%u", &orders[x].bigb);
    orders[x].excecuted_flag=1;
}

void Calculate_Cost(void){
    int codenumber2;
    int i;
    int small, big;
    printf("Give the code number of the order:");
    scanf("%d", &codenumber2);
    for (i=0;i<100;i++){
        if (orders[i].codenumber==codenumber2 && orders[i].codenumber!=NULL){
            small=orders[i].smallb;
            big=orders[i].bigb;
            break;
        }
    }
    orders[i].cost=0.008*big+0.02*small;
    printf("The cost of the order witn code number %d is: %f\n", orders[i].codenumber, orders[i].cost);
    puts("");
}

void Calculate_Final_Cost(void){
	float kostos=0;
    int codenumber2;
    int i;
    int small=0, big=0;
    printf("Give the code number of the order:");
    scanf("%d", &codenumber2);
    for (i=0;i<100;i++){
        if (orders[i].codenumber==codenumber2 && orders[i].codenumber!=NULL){
            printf("Give the current date(DD/MM/YY):");
            scanf("%u/%u/%u", &orders[i].day2, &orders[i].month2, &orders[i].year2);
            small=orders[i].smallb;
            big=orders[i].bigb;
            break;
        }
    }
    kostos=0.008*big+0.02*small;
    if (kostos>600){
        kostos=kostos-kostos*0.2;
    }
    else if ((kostos>200 && kostos<=600) || small+big>3000) {
        kostos=kostos-kostos*0.08;
    }
    orders[i].finalcost=kostos;
    orders[i].excecuted_flag=2;
    printf("The final cost of the order witn code number %d is: %f\n", orders[i].codenumber, kostos);
}

void Display_Unexcecuted_Orders(void){
    int i,j=0;
    for(i=0;i<100;i++){
        if(orders[i].excecuted_flag==1 && orders[i].excecuted_flag != NULL){
            j++;
            printf("Code number:%d\nName:%s\nDate of the order's entry:%u/%u/%u\n", orders[i].codenumber, orders[i].name, orders[i].day1, orders[i].month1, orders[i].year1);
            printf("Small botles:%u\n", orders[i].smallb);
            printf("Big bottles:%u\n", orders[i].bigb);
            puts("");
        }
    }
    printf("The unexcecuted orders are %d.\n", j);
}

void Display_Excecuted_Orders(void){
    int i, j=0;
    for(i=0;i<100;i++){
        if(orders[i].excecuted_flag==2 && orders[i].excecuted_flag!=NULL){
            j++;
            printf("Code number:%d\nName:%s\nDate of the order's entry:%u/%u/%u\n", orders[i].codenumber, orders[i].name, orders[i].day1, orders[i].month1, orders[i].year1);
            printf("The date of the excecution is %d/%d/%d.\n", orders[i].day2, orders[i].month2, orders[i].year2);
            printf("The final cost is:%f.\n", orders[i].finalcost);
        }
    }
    printf("The excecuted orders are %d.\n", j); 
}

void Display_Customer_Order(void){
    char  z[20];
    int i;
    printf("Give the customer's name:");
    scanf("%s", z);
    printf("The customer's orders are:\n");
    puts("");
    for(i=0;i<100;i++){
        if (strcmp(orders[i].name,z)==0){
            if (orders[i].excecuted_flag==1 && orders[i].excecuted_flag!=NULL){
                printf("Code number:%d\nName:%s\nDate of the order's entry:%u/%u/%u\n", orders[i].codenumber, orders[i].name, orders[i].day1, orders[i].month1, orders[i].year1);
                printf("Small botles:%u\n", orders[i].smallb);
                printf("Big bottles:%u\n", orders[i].bigb);
                puts("The order is not excecuted.");
            }
            else {
                printf("Code number:%d\nName:%s\nDate of the order's entry:%u/%u/%u\n", orders[i].codenumber, orders[i].name, orders[i].day1, orders[i].month1, orders[i].year1);
                printf("Small botles:%u\n", orders[i].smallb);
                printf("Big bottles:%u\n", orders[i].bigb);
                printf("The date of the excecution is %d/%d/%d.\n", orders[i].day2, orders[i].month2, orders[i].year2);
                printf("The final cost is:%d.\n", orders[i].finalcost);
            }
        }
    }
}

void Display_orders(void){
    int i;
    puts("Select order.\n");
    for(i=0;i<100;i++){
        if(orders[i].codenumber!=0){
             printf("Code number:%d\t | Name:%s\t | Date of the order's entry:%u/%u/%u\t | ", orders[i].codenumber, orders[i].name, orders[i].day1, orders[i].month1, orders[i].year1);
            printf("Small botles:%u\t | ", orders[i].smallb);
            printf("Big bottles:%u\n", orders[i].bigb);
        }
    }
}