//
// Created by louis-keolio on 27/11/2020.
//

#include "generate.h"

struct Tag * createTag(char * start, struct Attr ** attrList, int attrAmount, struct Tag **childList, int childAmount, char * content, char * end) {
    struct Tag * newTag = malloc(sizeof(Tag));

    newTag->start = malloc(sizeof(char) * strlen(start));
    strcpy(newTag->start, start);

    newTag->attributsAmount = attrAmount;
    newTag->attributs = attrList;

    newTag->childTags = childList;
    newTag->childsAmount = childAmount;

    newTag->content = malloc(sizeof(char) * strlen(content));
    strcpy(newTag->content, content);

    newTag->end = malloc(sizeof(char) * strlen(end));
    strcpy(newTag->end, end);

    return newTag;
}

struct DtdTag *createDtdTag(char *tagName, struct DtdAttr ** dtdAttrList, int dtdAttrAmount, struct DtdTag **childs, int childsAmount, char *contentType, int obligation) {
    struct DtdTag *dtdTag = malloc(sizeof(DtdTag));

    dtdTag->tagName = malloc(sizeof(char*) * strlen(tagName));
    strcpy(dtdTag->tagName, tagName);

    dtdTag->attributsAmount = dtdAttrAmount;
    //dtdTag->attributs = malloc(sizeof(DtdAttr) * dtdAttrAmount);
    dtdTag->attributs = dtdAttrList;

    dtdTag->childsAmount = childsAmount;
    dtdTag->childTags = childs;

    dtdTag->contentType = malloc(sizeof(char) * strlen(contentType));
    strcpy(dtdTag->contentType, contentType);

    dtdTag->obligation = obligation;

    return dtdTag;
}

struct DtdAttr *createDtdAttr(char *name, char ** values, int valuesSize, char * type) {
    struct DtdAttr *newDtdAttr = malloc(sizeof(DtdAttr));

    newDtdAttr->name = malloc(sizeof(char) * strlen(name));
    strcpy(newDtdAttr->name, name);

    if (valuesSize > 0) {
        newDtdAttr->type = NULL;
        newDtdAttr->valuesSize = valuesSize;
        newDtdAttr->values = malloc(sizeof(char *) * valuesSize);
        for (int i = 0; i < valuesSize; ++i) {
            newDtdAttr->values[i] = malloc(sizeof(char) * strlen(values[i]));
            strcpy(newDtdAttr->values[i], values[i]);
        }
    }
    else {
        newDtdAttr->type = malloc(sizeof(char) * 50);
        strcpy(newDtdAttr->type, type);
        newDtdAttr->values = NULL;
        newDtdAttr->valuesSize = 0;
    }

    newDtdAttr->obligation = 1;

    return newDtdAttr;
}

struct Attr *createAttr(char* name, char* value) {
    struct Attr * newAttr = malloc(sizeof(Attr));

    newAttr->name = malloc(sizeof(char) * strlen(name));
    strcpy(newAttr->name, name);
    newAttr->value = malloc(sizeof(char) * strlen(value));
    strcpy(newAttr->value, value);

    return newAttr;
}


