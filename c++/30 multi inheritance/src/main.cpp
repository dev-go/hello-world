// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "farmer.h"
#include "migrant_worker.h"
#include "worker.h"

void test01(Worker w)
{
  std::cout << "test01 >>>>>>>>>>>>>>>>" << std::endl;
  w.work();
  std::cout << "test01 <<<<<<<<<<<<<<<<" << std::endl;
}

void test02(Worker &w)
{
  std::cout << "test02 >>>>>>>>>>>>>>>>" << std::endl;
  w.work();
  std::cout << "test02 <<<<<<<<<<<<<<<<" << std::endl;
}

void test03(Worker *w)
{
  std::cout << "test03 >>>>>>>>>>>>>>>>" << std::endl;
  w->work();
  std::cout << "test03 <<<<<<<<<<<<<<<<" << std::endl;
}

int main(int argc, char **argv)
{
  int64_t id = 2011135139;
  char *name = "Terrence";
  MigrantWorker *mw = new MigrantWorker(name, id);
  printf("=======================\n");
  std::cout << mw->Worker::to_string() << std::endl;
  printf("=======================\n");
  std::cout << mw->Farmer::to_string() << std::endl;
  printf("=======================\n");
  name = "Liu";
  mw->set_name(name);
  id = 2011135166;
  mw->set_id(id);
  printf("=======================\n");
  mw->work();
  printf("=======================\n");
  mw->sow();
  printf("=======================\n");
  test01(*mw);
  printf("=======================\n");
  test02(*mw);
  printf("=======================\n");
  test03(mw);
  printf("=======================\n");

  Worker w = *mw;
  printf("=======================\n");

  delete mw;
  mw = NULL;
  printf("=======================\n");

  return EXIT_SUCCESS;
}
