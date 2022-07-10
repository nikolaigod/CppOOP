#include <iostream>
#include "Event.h"
#include "EventLog.h"

int main()
{
    std::cout << "Enter description of the event" << std::endl;
    char tempDescription[50]{};
    std::cin.getline(tempDescription, 50);
    Event event(tempDescription);
    EventLog log(4);
    log.addEvent(event);
    log.printEvent();
    return 0;
}

