// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 128

#define GET_ID(v) _Generic((v),        \
						   teacher_t   \
						   : ((v).id), \
							 student_t \
						   : ((v).id), \
							 default   \
						   : -1)

#define GET_NAME(v) _Generic((v),          \
							 teacher_t     \
							 : ((v).name), \
							   student_t   \
							 : ((v).name), \
							   default     \
							 : "?")

#define TO_STRING(p) _Generic((p),                    \
							  teacher_t *             \
							  : teacher_to_string(p), \
								student_t *           \
							  : student_to_string(p), \
								default               \
							  : "???")

typedef struct
{
	int64_t id;
	char name[];
} teacher_t;

char *teacher_to_string(void *p)
{
	teacher_t *t = (teacher_t *)p;
	char *str = (char *)malloc(2 * NAME_LEN);
	sprintf(str, "teacher_t{id: %ld, name: %s}", t->id, t->name);
	return str;
}

typedef struct
{
	int64_t id;
	char name[];
} student_t;

char *student_to_string(void *p)
{
	student_t *s = (student_t *)p;
	char *str = (char *)malloc(2 * NAME_LEN);
	sprintf(str, "student_t{id: %ld, name: %s}", s->id, s->name);
	return str;
}

int main(int argc, char const *argv[])
{
	teacher_t *t1 = (teacher_t *)malloc(sizeof(teacher_t) + NAME_LEN * sizeof(char));
	student_t *s1 = (student_t *)malloc(sizeof(student_t) + NAME_LEN * sizeof(char));

	t1->id = 135;
	strcpy(t1->name, "t1");

	s1->id = 139;
	strcpy(s1->name, "s1");

	char *str_1 = TO_STRING(t1);
	char *str_2 = TO_STRING(s1);
	printf("t1: id=%ld, name=%s, info=%s\n", GET_ID(*t1), GET_NAME(*t1), str_1);
	printf("s1: id=%ld, name=%s, info=%s\n", GET_ID(*s1), GET_NAME(*s1), str_2);
	free(str_1);
	free(str_2);

	free(s1);
	free(t1);

	return EXIT_SUCCESS;
}