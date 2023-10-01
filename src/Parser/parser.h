#ifndef PARSER_H
#define PARSER_H

#include <locale.h> // Для установки локали
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vertex { // описывает одну вершину
  double x;
  double y;
  double z;
  double w;
} vertex;

typedef struct polygon { // описывает один полигон обьекта
  int amount_f; // кол-во вершин в одном полигоне
  int *f; // содержит массив вершин одного полигона
} polygon;

typedef struct normalization { // описывает параметры необходимые для
                               // нормализации
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  double z_min;
  double z_max;
  double koef_n;
} normalization;

typedef struct object {
  vertex *v;  // массив вершин
  polygon *p; // массив полигонов

  int amount_v;
  int allocated_memory_v;

  int amount_p;
  int allocated_memory_p;

  normalization norm;

} object;

object parser(char *filename);

void vertex_handler(char *v_str, object *obj);
void polygon_handler(char *p_str, object *obj);

bool is_vertex_str(char *str);
bool is_polygon_str(char *str);

void init_object(object *obj);
void free_object(object *obj);

void normalization_object(object *obj);
void detect_extreme_value(object *obj, vertex v);

#ifdef __cplusplus
}
#endif

#endif // PARSER_H

/* Примечание:
- Если возвращенный object функции parser() нулевой размерности(obj.amount_p ==
0 || obj.amount_v == 0), то при считывании из файла произошла ошибка (файл не
существует, пустой либо некоректное содержимое)
*/
