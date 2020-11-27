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
