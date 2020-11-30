#include <iostream>
using namespace std;

//It can be used class object instead of structure.
struct IndexPriceProfit
{
    int buy_index=0;
    int sell_index=0;
    int profit=0;
}ipp;

/*
#   In this function, we first find the local min and local maximum values
#   If there is only one day or price is decreases everyday, 
#   it writes on the screen impossible to make profit.
*/
void maxProfitAndBuyDayIndex(int number_of_days,int price_array[]){
    //  This struct object will hold the temprorary profit
    //  and its buy,sell day index.
    IndexPriceProfit temp_ipp;
    //That means that merchant can buy but there is
    //no another day to sell the product and make profit.
    if(number_of_days==1){
        cout<<"Impossible to make profit.";
        return; 
    }
    int index=0;

    while (index<number_of_days-1)
    {  
        //  This while finds the local minimum. 
        //  We buy the item in this day.
        while (price_array[index]>=price_array[index+1] && index<number_of_days-1)
        {
            index++;
        }
        if (index==number_of_days-1)
        {
            break;
        }
        temp_ipp.buy_index=index;

        //  This while loop is to find local max.
        //  This is the day we sell the product.
        while(index<number_of_days-1 &&(price_array[index+1]>price_array[index]))
        {
            index++;
        }
        temp_ipp.sell_index=index;

        //  After that we calculate the temporary profit value
        temp_ipp.profit=price_array[temp_ipp.sell_index]-price_array[temp_ipp.buy_index];

        //  Then I compare this temporary profit with the profit of ipp
        //  If temp profit is higher, then we update the ipp_profit and buy && sell index.
        if ((price_array[temp_ipp.sell_index]-price_array[ipp.buy_index])>ipp.profit)
        {
            ipp.profit=(price_array[temp_ipp.sell_index]-price_array[ipp.buy_index]);
            ipp.sell_index=temp_ipp.sell_index;
        }
        if(temp_ipp.profit>ipp.profit)
        {
            ipp.sell_index=temp_ipp.sell_index;
            ipp.buy_index=temp_ipp.buy_index;
            ipp.profit=temp_ipp.profit;
        }
    }   
    if(ipp.profit!=0){    
        cout<<ipp.profit<<endl;
        cout<<ipp.buy_index+1<<endl;
    }else
    {
        cout<<"Impossible to make profit.";
    }
    
}
int main(){
   
    int number_of_days;
    cin>>number_of_days;
    int price_array[number_of_days];
    for(int i=0;i<number_of_days;i++){
        cin>>price_array[i];
    }
    maxProfitAndBuyDayIndex(number_of_days,price_array);

    return 0;
}
