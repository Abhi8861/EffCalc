#include "../EFF.h"

static u_int16 UID;//unique ID created for each file stored
u_int16 UID_generate(){
    return (S_UID+1);
}
    //taking the static UID and using it to update the same static UID and UID at the struct end
u_int8 Week_Update(CONSOLE_IO *C_IN)
{

}
CONSOLE_IO* init()
{
    CONSOLE_IO C_IN,*sp;

    C_IN.aims[]={};
    C_IN.completion_stat=0;
    C_IN.Current_Date[]={};
    C_IN.Current_Time[]={};
    C_IN.CURR_WEEK_NO=0;
    C_IN.percentage_completed=0;
    C_IN.percentage_required=0;
    *sp=&C_IN;
    return sp;
}
//File Handlers


bool Read_Data_from_console(CONSOLE_IO *C_IN)
{
    //record current time using macros
    C_IN->Current_Date=__DATE__;
    C_IN->Current_Time=__TIME__;
    Week_Update(C_IN);
    char scanned_ch;
    int i=0;
    //read data from user

    printf("Pl input your aims for the current day \n");
    while(scanned_ch!=-1)
    {
        scanned_ch=getchar();
        C_IN->aims[i]=scanned_ch;
        i++;
    }

}

bool Fill_Completed_Percentage(CONSOLE_IO *C_IN);//fill in completed or not mark and mark that with current stamo
bool Copy_to_File_Struct(FILE_In *file_manipulate); //modifies the time date etc in file handler
bool File_Write(FILE *fw,FILE_In *file_in);
//Display handlers on request

bool Request_Display(); //checks if the pre-assigned key to display is pressed during the course of the program run
bool Write_Data_to_console(CONSOLE_IO *C_out);// just display the struct including percentage completed,if not updated then show null
bool File_Read(FILE *fr,FILE_In *file_out);// Reads from the file and checks the UID in the file and then parses the file->outputs it to the structure to display->Copies this to another similar structure

