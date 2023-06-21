
#include <iostream>
#include <conio.h>

int main()
{
    
    
    int i = 0;
    while(i < 100000000000)
    {
        i++;
        char key = getch(); 
        if(key == 'q' ) // & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            std::cout << "Hello world" << std::endl;
            break;
        }
    }
    return 0;
}