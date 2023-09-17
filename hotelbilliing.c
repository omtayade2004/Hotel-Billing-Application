#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("|------MENU------|\n");
    printf("| 1.Samosa 30/-  |\n");
    printf("| 2.Dosa   50/-  |\n");
    printf("| 3.Tea    10/-  |\n");
    printf("| 0.Exit   >>>>  |\n");
    printf("|-----Thanks-----|\n");
}

int OrderSamosa(int total) {
    int plates, price = 30;
    printf("|Wow! It's a Nice Choice |\n");
    printf("|Your Choice: Samosa 30/-|\n\n");
    printf("<<Enter the Quantity:");
    scanf("%d", &plates);
    total += plates * price;
    printf("<<Your total is %d       \n", total);
    return total;
}

int OrderDosa(int total) {
    int plates, price = 50;
    printf("|Wow! It's a Nice Choice |\n");
    printf("|Your Choice: Dosa 50/-  |\n\n");
    printf("<<Enter the Quantity:");
    scanf("%d", &plates);
    total += plates * price;
    printf("<<Your total is %d       \n", total);
    return total;
}

int OrderTea(int total) {
    int plates, price = 10;
    printf("|Wow! It's a Nice Choice |\n");
    printf("|Your Choice: Tea 10/-   |\n\n");
    printf("<<Enter the Quantity:");
    scanf("%d", &plates);
    total += plates * price;
    printf("<<Your total is %d       \n", total);
    return total;
}

int main() {
    int choice = 1, repeatorder = 1, total = 0, billtopay;

    while (repeatorder) {
        displayMenu();
        printf("\n<<<Enter your Choice:");
        scanf("\n%d", &choice);

        switch (choice) {
            case 1:
                total = OrderSamosa(total);
                break;

            case 2:
                total = OrderDosa(total);
                break;

            case 3:
                total = OrderTea(total);
                break;

            case 0: {
                printf("|Your Overall Total is %d |\n\n", total);

                do {
                    printf("Please Enter Payment Amount (or 0 to cancel): ");
                    scanf("%d", &billtopay);

                    if (billtopay == 0) {
                        printf("Payment Canceled\n");
                        break;
                    }

                    if (billtopay > 0) {
                        if (billtopay >= total) {
                            printf("\n<<Thank You for Paying the Bill!!!>>\n");
                            if (billtopay > total) {
                                printf("Your Change:%d\n", billtopay - total);
                            }
                            repeatorder = 0;
                        } else {
                            printf("Payment is Insufficient\n");
                            printf("Pay the Remaining Amount:%d\n", total - billtopay);
                        }
                        total -= billtopay;
                    } else {
                        printf("Invalid payment amount. Please enter a positive amount or 0 to cancel.\n");
                    }
                } while (total > 0);

                break;
            }

            default:
                printf("|The Choice is Not Valid|\n");
                printf("|<<<<Please Choose Again|\n");
                printf("|<Thank You Visit Again>|\n");
                break;
        }
    }

    return 0;
}
