#include <stdio.h>
#include <string.h>
int isbns[100], quantities[100];
char titles[100][50];
float price[100];

void Add(int isbn, int qty, char name[], float rate, int ind){
    int found=0;
    for(int i=0;i<ind;i++)
        if(isbns[i]==isbn)
            found=1;
    if(!found && ind<100){
        isbns[ind]=isbn;
        quantities[ind]=qty;
        price[ind]=rate;
        strcpy(titles[ind], name);
    }
    else if(ind==100)
        printf("Library Is Full\n");
    else
        printf("ISBN Already Available\n");
}
void Low_stock(int ind){
    printf("| %-15s | %-15s | %-10s |\n", "ISBN NO:", "BOOK TITLE", "Quantity");
    for(int i=0;i<ind;i++)
        if(quantities[i]<5)
            printf("| %-15d | %-15s | %-10d |\n",isbns[i],titles[i],quantities[i]);

}
float Process_Sale(int ind){
    float bill=0;
    int isbn;
    float qty;
    while(1){
        printf("Enter ISBN AND Quantity\n");
        scanf("%d%f",&isbn,&qty);
        for(int i=0;i<ind;i++)
            if(isbns[i]==isbn)
                if(quantities[i]<qty)
                    printf("Invalid Input\n");
                else{
                    bill+=(price[i]*qty);
                    quantities[i]-=qty;
                }
        if(bill!=0)
            break;
        printf("Enter Invalid ISBN Number Or Quantity Number\n");
    }
    return bill;
}
int main(){
    int ind=0;
    while(1)
    {
        char choice;
        printf("Enter A For Add Book, P For Sale Book And E For Exit: ");
        scanf("%c",&choice);
        printf("\n");
        int isbn, qty;
        char name[100];
        float rate;
        if(choice=='A'){
            printf("Enter ISBN NO:, Book Title, Quantity And Price Of Book:");
            scanf("%d%s%d%f",&isbn,name,&qty,&rate);
            printf("\n");
            Add(isbn,qty,name,rate,ind);
            ind++;
        }
        else if(choice=='P')
            printf("Total Bill: %f\n",Process_Sale(ind));
        else{
            printf("Program Exit\n");
            return 0;
        }
    }
    return 0;
}