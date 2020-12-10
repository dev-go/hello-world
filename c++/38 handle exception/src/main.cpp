// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "error_impl.h"

Error *IndexError = new ErrorImpl((char *)"index out of range");
Error *ParamError = new ErrorImpl((char *)"invalid parameter");

int main(int argc, char **argv)
{
  try
  {
    // throw (char *)"hello";
    // throw 3.14;
    throw IndexError;
    printf("you should not see this line!!!");
  }
  catch (Error *e)
  {
    printf("throw Error: %s\n", e->error());
  }
  catch (double d)
  {
    printf("throw double: %lf\n", d);
  }
  catch (...)
  {
    printf("throw unknow exception\n");
  }

  return EXIT_SUCCESS;
}
