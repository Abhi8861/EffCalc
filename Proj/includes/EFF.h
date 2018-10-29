/*
Task :
1) Key in the day,month,year and date .
2) Create the "AIMS for the day" with date stamp and time stamp.Replace the day to the date+day+month+year
3) From the console->Key in the the aims for the day.
4) Detection of the point no should be there and spacing between each point must be there,also all the input should be taken
5) All these should be timestamped and stored in a file - 1month = 1 folder and then files inside dated
6) At the end of the day the person should be able to : 1) Give the percentage of completion 2) mark it as done
7) The non completed task should be carried over to the next day and percentage remaining should be displayed
8) The commands to the software should be query and request basis only.
*/

/*
Types of vars required?:

1)  A struct to store the date month year and day + one more variable which is shared between other structure (unique ID)
2)  Struct :  to store the aims for the corresponding unique ID with variables current time and current date+modified date+
    modified time and percentage of completion +percentage carried over
3)  Struct to store the format which is needed to be written onto the file
4) LOCK variable should be extern/static -DECIDE
5)
*/

// ALL structs typedefs
#include<stdio.h>
#include<string.h>
typedef int u_int16;
typedef short int u_int8;
typedef char* String;
typedef char* Small_Str;
typedef double u_double;
typedef enum{TRUE=1,FALSE=0}bool;
typedef enum{
                MON,
                TUE,
                WED,
                THURS,
                FRI,
                SAT,
                SUN
            }DAYS;

typedef enum{
                JAN,
                FEB,
                MAR,
                APR,
                MAY,
                JUN,
                JUL,
                AUG,
                SEP,
                OCT,
                NOV,
                DEC
            }MONTHS;
            /*
typedef struct {
                    MONTHS month_NO;
                    DAYS day_type;
                    u_int16 year;
                    u_int8 date_no; //ranges from 1-31
                    int U_I_D;//shared ID
                    //TOTAL size = 72 bits = 9 bytes -wraps to 16 bytes
               }STAMP_DATE;
               */
typedef struct {
                   // MONTHS current_month;
                    //DAYS current_day;
                   // u_int16 current_year;
                    //u_int8 current_date;
                    Small_Str Current_Date;
                    Small_Str Current_Time;
                    u_double percentage_required; //read only after 1 write
                    u_double percentage_completed;
                    u_int8 CURR_WEEK_NO;
                    String aims;
                    bool completion_stat;

               }CONSOLE_IO;

// specified file format to be written completely into a file
typedef struct {
                    u_int8 fill_date;
                    MONTHS fill_month;
                    u_int16 fill_years;
                    DAYS fill_day;
                    u_double percentage_required; //read only after 1 write
                    u_double percentage_completed;
                    u_int8 fill_WEEK_NO;
                    String fill_Aims;
                    bool completion_stat; //end of the day no re write;

               }FILE_In;

//Functions
u_int16 UID_generate();//taking the static UID and using it to update the same static UID and UID at the struct end
u_int8 Week_Update(CONSOLE_IO *C_in);
bool init();
u_int8 Week_no_from_File(FILE *fin);
//File Handlers

bool File_Write(FILE *fw,FILE_In *file_in);
bool Read_Data_from_console(CONSOLE_IO *C_IN);// update the AIM stamos
bool Fill_Completed_Percentage(CONSOLE_IO *C_IN);//fill in completed or not mark and mark that with current stamo
bool Copy_to_File_Struct(FILE_In *file_manipulate); //modifies the time date etc in file handler

//Display handlers on request

bool Request_Display(); //checks if the pre-assigned key to display is pressed during the course of the program run
bool Write_Data_to_console(CONSOLE_IO *C_out);// just display the struct including percentage completed,if not updated then show null
bool File_Read(FILE *fr,FILE_In *file_out);// Reads from the file and checks the UID in the file and then parses the file->outputs it to the structure to display->Copies this to another similar structure


