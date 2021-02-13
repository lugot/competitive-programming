#include<stdio.h>
#include<string.h>



int main(){
    int D,M,day;
    scanf("%d %d",&D,&M);
    
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    switch(M){
        case(1):
            day=0;
            break;
        case(2):
            day=31;
            break;
        case(3):
            day=59;
            break;
        case(4):
            day=90;
            break;
        case(5):
            day=120;
            break;
        case(6):
            day=151;
            break;
        case(7):
            day=181;
            break;
        case(8):
            day=212;
            break;
        case(9):
            day=243;
            break;
        case(10):
            day=273;
            break;
        case(11):
            day=304;
            break;
        case(12):
            day=334;
            break;
    }
    
    day+=D;
    day = day % 7;
    
    switch(day){
        case(1):
            printf("Thursday\n");
            return 0;
        case(2):
            printf("Friday\n");
            return 0;
        case(3):
            printf("Saturday\n");
            return 0;
        case(4):
            printf("Sunday\n");
            return 0;
        case(5):
            printf("Monday\n");
            return 0;
        case(6):
            printf("Tuesday\n");
            return 0;
        case(0):
            printf("Wednesday\n");
            return 0;
    }
}
