#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "element.hxx"
const char * ElementNames[] ={
    ELEMENT_JIN,
    ELEMENT_SHUI,
    ELEMENT_MU,
    ELEMENT_HUO,
    ELEMENT_TU
};

const ELEMENT_INDEX ElementRelation[] = {
    ELEMENTINDEX_JIN,
    ELEMENTINDEX_SHUI,
    ELEMENTINDEX_MU,
    ELEMENTINDEX_HUO,
    ELEMENTINDEX_TU
};


const char * RelationNames[] = {
    RELATION_RESTRICT,
    RELATION_RESTRICTED,
    RELATION_SAME,
    RELATION_GENERATE,
    RELATION_GENERATED,
    RELATION_INVALID
};

bool get_element_name(ELEMENT_INDEX element,char * name)
{
    if(element<0)
        return false;
    size_t count = sizeof(ElementNames)/sizeof(ElementNames[0]);
    if(element>=count)
        return false;
    strcpy(name,ElementNames[element]);
    return true;
}
ELEMENT_RELATION get_relation(ELEMENT_INDEX e1,ELEMENT_INDEX e2)
{
    for (size_t i = 0; i < sizeof(ElementRelation)/sizeof(ElementRelation[0]); i++)
    {
        if(ElementRelation[i] == e1)
        {
            for (size_t j = 0; j <  sizeof(ElementRelation)/sizeof(ElementRelation[0]); j++)
            {
                 if(ElementRelation[j] == e2)
                 {
                    if(i==j)
                        return ER_SAME;

                    //生
                    if(i==j+1)
                        return ER_GENERATE;
                    if(i==j+4)//金 -> 土
                        return ER_GENERATE;

                    //被生                    
                    if(i+1==j)
                        return ER_GENERATED;
                    if(i+4==j) //金 <- 土
                        return ER_GENERATED;

                    //克
                    if(i==j+2)
                        return ER_RESTRICT;
                    if(i+3==j) // 土 -> 水
                        return ER_RESTRICT;

                    //被克
                    if(i+2==j)
                        return ER_RESTRICTED;
                    if(i=j+3) // 土 <- 水
                        return ER_RESTRICTED;

                 }
                 return ER_INVALID;
            }
        }
    }
    return ER_INVALID;
}

bool get_relation_name(ELEMENT_RELATION r,char * name)
{
    if(r<0)
        return false;
    if(r>=ER_INVALID)
        return false;
    strcpy(name,RelationNames[r]);
    return true;
}