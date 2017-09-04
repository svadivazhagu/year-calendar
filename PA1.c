#include <stdio.h>
int numDays; // The number of days that have ever occured.
int numLeapYears; // The number of leap years that have ever occured.
int numCenturies; //The number of centuries that have ever occurred.
int num4Centuries; // The number of four centuries that have occurred.
int monthNum; // The current month number.
int numDaysPerWeek;  // determines the current day you are on, Sun. -> Sat.


/** Calculates whether the input year is a leap year.
Only works for years that are greater than zero.
  *@param inputYear Year (A.D.)
  *@return A 1 or 0 depending on whether the year is a leap year or not.
*/
int isLeapYear(int inputYear){
  if ((inputYear%4 == 0) && (inputYear%100 == 0) && (inputYear%400 == 0)) {
    return 1;
  } else if ((inputYear%4 == 0) && (inputYear%100 == 0) && (!inputYear%400 == 0)) {
    return 0;
  }
  else if ((inputYear%4 == 0) && inputYear < 100) {
    return 1;
  }
  else{
    return 0;
  }
}


/**Determines the starting day of the week for each year, where 7 is Saturday
and 1 is Sunday.
  *@param inputYear
  *@return The number of the day of the week that a year will start on (1 is
Sunday and 7 is Saturday.)*/
int startYear(int inputYear){
  numDays = inputYear * 365;
  numLeapYears = inputYear / 4;
  numCenturies  = inputYear / 100;
  num4Centuries = inputYear / 400;
  return (((numDays + numLeapYears) - numCenturies) + num4Centuries)%7 + 1;
}


/** Switch statement that takes the given year and month number as input and
then outputs the month name, number of days in that month, and the year as a
header above the calendar for each month.
 *@param inputYear Year (A.D.)
 *@param monthNum Month Number (1-12)
 *@return The number of days in the month, as well as a header for that month's
 calendar. */

int printMonthName(int inputYear, int monthNum){
  switch (monthNum) {
    case 1:
    printf("\n\nJanuary %d\n\n", inputYear);
    return 31;
    break;

    case 2:
    printf("\n\nFebruary %d\n\n", inputYear);
    return 28 + isLeapYear(inputYear);
    break;

    case 3:
    printf("\n\nMarch %d\n\n", inputYear);
    return 31;
    break;

    case 4:
    printf("\n\nApril %d\n\n", inputYear);
    return 30;
    break;

    case 5:
    printf("\n\nMay %d\n\n", inputYear);
    return 31;
    break;

    case 6:
    printf("\n\nJune %d\n\n", inputYear);
    return 30;
    break;

    case 7:
    printf("\n\nJuly %d\n\n", inputYear);
    return 31;
    break;

    case 8:
    printf("\n\nAugust %d\n\n", inputYear);
    return 31;
    break;

    case 9:
    printf("\n\nSeptember %d\n\n", inputYear);
    return 30;
    break;

    case 10:
    printf("\n\nOctober %d\n\n", inputYear);
    return 31;
    break;

    case 11:
    printf("\n\nNovember %d\n\n", inputYear);
    return 30;
    break;

    case 12:
    printf("\n\nDecember %d\n\n", inputYear);
    return 31;
    break;
  }
  return 0; // returns 0 if program runs successfully.
}


/** Function that prints the calendar for a single month. It returns the day
of the week that the month begins on.
 *@param inputYear Year (A.D)
 *@param monthNum Month Number (1-12)
 *@param startingDay Starting Day of the Month (1-31)
 *@return Starting day of the week (1-7) */
int printMonth(int inputYear, int monthNum, int startingDay){
  int monthLength = printMonthName(inputYear, monthNum);
  printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
  for(int startingDayofMonth = 0; startingDayofMonth <= startingDay - 2;
    startingDayofMonth++) {
      printf("     ");
    }
    for(int dayInMonth = 1; dayInMonth <= monthLength; dayInMonth++) {
      if (startingDay > 7) {
        startingDay = 1;
        printf("\n");
      }
      printf("%4d ", dayInMonth);
      startingDay++;
    }
    return (startingDay%7)+1;


  }
  /** printCalendar is a function that calls the printMonth function twelve \
  times in a for loop to print out the calendar for the year.
  *@param inputYear Year (A.D.).
  *@return The calendar for the year that was input. */
  int printCalendar(int inputYear, int startDay) {
    for (monthNum = 1; monthNum <= 12; monthNum++) {
      startDay = printMonth(inputYear, monthNum, startDay);
    }
    return 0;
  }



  /** Provides the user interface for the program, which prompts the user to
  enter the year they would like displayed in the calendar. Takes no input.
  *@return The twelve month calendar of a year decided by the user. */
  int ui(){
    int inputYear;
    printf("\t \t \t MONTHLY CALENDAR \n");
    printf("Please enter year for this calendar:- ");
    scanf("%d", &inputYear);
    if (inputYear < 1) {
      printf("Year inputted not supported by program.\n");
      return 1;
    }
    printf("\n \n");
    printf("\t*** CALENDAR for %d ***\n", inputYear);
    int start = startYear(inputYear);
    printCalendar(inputYear, start);
    return 0;
  }
  int main(void){
    ui();
    return 1;
  }
