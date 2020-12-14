#include <iostream>

int month_days(int month,int year){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return int(31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return int(30);
            break;
        case 2:
            if(year % 100 == 0){
                if(year % 400 == 0)
                    return int(29);
                else
                    return int(28);
            }else if(year % 4 == 0){
                return int(29);
            }else
                return int(28);
            break;
        default :
            return 0;
            break;
    }
}

bool isSunday(int day){
    return bool(day % 7 == 6);
}

int count_sundays(int min_year, int max_year){
    int sum_sundays = 0;
    int days =1;
    for(int i = 1; i <= 12; i++ ){
            days += month_days(i, 1900);
    }
    for(int y = min_year; y < max_year; y++){
        days %= 7;
        for(int i = 1; i <= 12; i++ ){
             if(isSunday(days)){
                sum_sundays++;
            }
            days += month_days(i, y);
        }
    }
    return sum_sundays;
}


int main()
{
    std::cout << count_sundays(1901, 2001) << "\n";
    return 0;
}
