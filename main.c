#include "EFF.h"

void main()
{
    /*Main flowchart
        First create a instance of console structure
        init values to usual vars - Create struct var week no from file and all other to 0/null
        update week no from file.
        read the current date and time into the console object
        read the aims for the day to the console object
        pack the struct and copy it to file struct
        //File modification
        First send a [DATE] string and then send the date
        send a [TIME] string and then send the time
        send a [WEEK_NO] then send the week no
        send a [AIMS] string and then send the aims
        send a [%REQ] string and then send the percentage required with a '%'
        send a [%COMP] string and then send =NULL/0
        send a [COMPSTAT] string and then send FALSE
        then send a UID update : [UID] with UID no




    */
     CONSOLE_IO *C_IN;
     C_IN=init();

    //read data

    Read_Data_from_console(&C_IN);

}
