
#include "testPrint.cpp"

int main()
{
    bool ok = true;

    if( printLowAlarm() )       
    {
        std::cout << "\nLOW ALARM OK " << std::endl;
    }
    else 
    { 
        std::cout << "\nLOW ALARM NOK " << std::endl;
        ok = false;
    } 




    if (printMediumAlarm() )    
    {
        std::cout << "\nMEDIUM ALARM OK " << std::endl;
    }
    else 
    { 
        std::cout << "\nMEDIUM ALARM NOK " << std::endl;        
        ok = false;
    } 



    
    if (printHighAlarm() )      
    {
        std::cout << "\nHIGH ALARM OK " << std::endl;
    }
    else 
    {
        std::cout << "\nHIGH ALARM NOK " << std::endl;        
        ok = false;
    } 

    if(ok) std::cout << "Printing alarms OK" << std::endl;
    else std::cout << "ERROR(S) in printing alarms !" << std::endl;
    return 0;
}