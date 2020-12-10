// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "person.h"

void Person::eat() { printf("eat ...\n"); }

Person::Person() : name_(""), age_(0) { printf("new Person\n"); }

Person::~Person() { printf("delete Person\n"); }
