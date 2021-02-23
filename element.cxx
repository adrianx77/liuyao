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

const char * RelationNames[] = {
    RELATION_RESTRICT,
    RELATION_RESTRICTED,
    RELATION_SAME,
    RELATION_GENERATE,
    RELATION_GENERATED,
    RELATION_INVALID
};


typedef struct {
    ELEMENT_INDEX self;
    ELEMENT_INDEX generate;
    ELEMENT_INDEX restrict;
    ELEMENT_INDEX restricted;
    ELEMENT_INDEX generated;
}RELATIONS;


RELATIONS ElementRelation[]={
    {
        ELEMENTINDEX_JIN,
        ELEMENTINDEX_SHUI,
        ELEMENTINDEX_MU,
        ELEMENTINDEX_HUO,
        ELEMENTINDEX_TU
    },
    {
        ELEMENTINDEX_SHUI,
        ELEMENTINDEX_MU,
        ELEMENTINDEX_HUO,
        ELEMENTINDEX_TU,
        ELEMENTINDEX_JIN
    },
    {
        ELEMENTINDEX_MU,
        ELEMENTINDEX_HUO,
        ELEMENTINDEX_TU,
        ELEMENTINDEX_JIN,
        ELEMENTINDEX_SHUI
    },
    {
        ELEMENTINDEX_HUO,
        ELEMENTINDEX_TU,
        ELEMENTINDEX_JIN,
        ELEMENTINDEX_SHUI,
        ELEMENTINDEX_MU
    },
    {
        ELEMENTINDEX_TU,
        ELEMENTINDEX_JIN,
        ELEMENTINDEX_SHUI,
        ELEMENTINDEX_MU,
        ELEMENTINDEX_HUO
    }
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
    if(e1<0)
        return ER_INVALID;
    size_t count = sizeof(ElementRelation)/sizeof(ElementRelation[0]);
    if(e1>count || e2> count)
        return ER_INVALID;
    
    if(e1==e2)
        return ER_SAME;
    
    if(ElementRelation[e1].generate == e2)
        return ER_GENERATE;
    
    if(ElementRelation[e1].restrict == e2)
        return ER_RESTRICT;

    if(ElementRelation[e1].generated == e2)
        return ER_GENERATED;

    if(ElementRelation[e1].restricted == e2)
        return ER_RESTRICTED;
    
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
