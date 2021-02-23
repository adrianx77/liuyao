#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "basedef.hxx"
const char * ElementTable[] ={
    ELEMENT_JIN,
    ELEMENT_SHUI,
    ELEMENT_MU,
    ELEMENT_HUO,
    ELEMENT_TU
};


bool get_element_name(ELEMENT_INDEX element,char * name)
{
    if(element<0)
        return false;
    size_t count = sizeof(ElementTable)/sizeof(ElementTable[0]);
    if(element>=count)
        return false;
    strcpy(name,ElementTable[element]);
    return true;
}
