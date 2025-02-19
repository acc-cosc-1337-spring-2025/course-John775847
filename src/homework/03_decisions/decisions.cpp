#include "decisions.h"

char get_letter_grade_using_if(int grade){
    if (grade > 89){
        return 'A';
    } else if (grade > 79){
        return 'B';
    } else if (grade > 69){
        return 'C';
    } else if (grade > 59){
        return 'D';
    } else{
        return 'F';
    }
}

char get_letter_grade_using_switch(int grade){
    grade = grade / 10; //taking advantage of the fact that "grade" is an int
    switch(grade){
        case 10:
            return 'A'; //"return" ends the entire function, so you dont need to break.
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        default:
            return 'F';
    }
}
