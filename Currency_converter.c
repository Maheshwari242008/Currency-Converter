#include <stdio.h>

// Function to get exchange rate
float exchange_rate(int from_currency, int to_currency) 
{
    // Exchange rates (We have to update these rates whenever any changes take place in real time)

    float rates[5][5] = 
    {
        {1.0, 0.012, 0.011, 0.0095, 1.70}, // INR to INR, USD, EUR, GBP, JPY
        {83.00, 1.0, 0.92, 0.79, 142.50}, // USD to INR, USD, EUR, GBP, JPY
        {90.00, 1.09, 1.0, 0.86, 155.00}, // EUR to INR, USD, EUR, GBP, JPY
        {105.00, 1.27, 1.16, 1.0, 180.00}, // GBP to INR, USD, EUR, GBP, JPY
        {0.55, 0.007, 0.0065, 0.0055, 1.0} // JPY to INR, USD, EUR, GBP, JPY
    };

    return rates[from_currency][to_currency];
}

int unit(int to_currency)
{
    switch(to_currency)
    {
        case 0:
            printf("INR\n");
        break;
        case 1:
            printf("USD\n");
        break;
        case 2:
            printf("EUR\n");
        break;
        case 3:
            printf("GBP\n");
        break;
        case 4:
            printf("JPY\n");
        break;
    }
}

int main() 
{
    int from_currency, to_currency;
    float amount, converted_amount;
    //float (*ptr)(int,int);
    //ptr =  exchange_rate;
    
    for(int i=1; ; i++)
    {
        // Display currency options
        printf("----------------------\n");
        printf("| Currency Converter |\n");
        printf("----------------------\n");
        printf("Select the source currency:\n");
        printf("0. Indian Rupee (INR)\n");
        printf("1. US Dollar (USD)\n");
        printf("2. Euro (EUR)\n");
        printf("3. British Pound (GBP)\n");
        printf("4. Japanese Yen (JPY)\n");
        printf("5. Exit\n");
        printf("Enter your choice (0-5): ");
        scanf("%d", &from_currency);
        if(from_currency == 5)
        {
            printf("\nExit the program. Thank You.\n\n");
            break;
        }
    
        printf("\n-------------------------------------------------------\n\n");
        printf("Select the target currency:\n");
        printf("0. Indian Rupee (INR)\n"); //coverts into INR
        printf("1. US Dollar (USD)\n"); //coverts into USD
        printf("2. Euro (EUR)\n"); //coverts into EUR
        printf("3. British Pound (GBP)\n"); //coverts into GBP
        printf("4. Japanese Yen (JPY)\n"); //coverts into JPY
        printf("Enter your choice (0-4): ");
        scanf("%d", &to_currency);
    
        printf("\n------------------------------------------------------\n\n");

        // Check for valid input
        if (from_currency < 0 || from_currency > 5 || to_currency < 0 || to_currency > 4) 
        {
            printf("Invalid choice! Please enter numbers between 0 and 4.\n\n");
            break;
        }

        // Take amount input
        printf("Enter the amount to convert: ");
        scanf("%f", &amount);

        printf("\n-------------------------------------------------------\n\n");

        // Get exchange rate and convert into target currency

        float rate = exchange_rate(from_currency, to_currency);
        converted_amount = amount * (rate);

        // Display result
        printf("Converted amount: %.2f ",converted_amount);
        unit(to_currency);
        printf("\n\n");

    }
    return 0;
}