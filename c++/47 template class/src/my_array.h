// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include <iostream>
#include <string>

template <typename T, uint8_t size>
class MyArray
{
public:
  void display();
  void set(uint8_t index, T value);
  MyArray();
  MyArray(const MyArray &arr);
  ~MyArray();

private:
  T *arr_;
};

template <typename T, uint8_t size>
void MyArray<T, size>::display()
{
  std::cout << "MyArray[";
  for (uint8_t i = 0; i < size - 1; i++)
  {
    std::cout << *(arr_ + i) << ", ";
  }
  std::cout << *(arr_ + size - 1) << "]" << std::endl;
}

template <typename T, uint8_t size>
void MyArray<T, size>::set(uint8_t index, T value)
{
  arr_[index] = value;
}

template <typename T, uint8_t size>
MyArray<T, size>::MyArray()
{
  arr_ = new T[size];
}

template <typename T, uint8_t size>
MyArray<T, size>::MyArray(const MyArray &arr)
{
  arr_ = new T[size];
  for (uint8_t i = 0; i < size; i++)
  {
    arr_[i] = arr.arr_[i];
  }
}

template <typename T, uint8_t size>
MyArray<T, size>::~MyArray()
{
  delete[] arr_;
  arr_ = NULL;
}
