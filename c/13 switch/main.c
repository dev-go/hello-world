// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define D_UP 1
#define D_DOWN 2
#define D_LEFT 3
#define D_RIGHT 4

uint8_t const UP = 1;
uint8_t const DOWN = 2;
uint8_t const LEFT = 3;
uint8_t const RIGHT = 4;

int main(int argc, char const *argv[])
{
    uint8_t direction = 0;
    puts("↑:1  ↓:2  ←:3  →:4  enter a number(1~4)");
    scanf(" %hhu", &direction);
    switch (direction)
    {
    case D_UP:
        puts("D_UP");
        break;
    case D_DOWN:
        puts("D_DOWN");
        break;
    case D_LEFT:
        puts("D_LEFT");
        break;
    case D_RIGHT:
        puts("D_RIGHT");
        break;
    default:
        puts("INVALID");
        break;
    }

    // switch (direction)
    // {
    // case UP: // error: case label does not reduce to an integer constant
    //     puts("UP");
    //     break;
    // case DOWN: // error: case label does not reduce to an integer constant
    //     puts("DOWN");
    //     break;
    // case LEFT: // error: case label does not reduce to an integer constant
    //     puts("LEFT");
    //     break;
    // case RIGHT: // error: case label does not reduce to an integer constant
    //     puts("RIGHT");
    //     break;
    // default:
    //     puts("INVALID");
    //     break;
    // }

    return EXIT_SUCCESS;
}