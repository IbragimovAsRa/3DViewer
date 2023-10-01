#include "parser.h"

object parser(char *filename) {
  setlocale(LC_ALL,
            "C"); // Установка локали "C" для точки в качестве разделителя

  object obj;
  FILE *fp;

  init_object(&obj);
  fp = fopen(filename, "r");

  if (fp != NULL) {
    char buffer_str[BUFFER_SIZE];
    while (fgets(buffer_str, BUFFER_SIZE, fp) != NULL) {
      if (is_vertex_str(buffer_str)) {
        vertex_handler(buffer_str, &obj);
      } else if (is_polygon_str(buffer_str)) {
        polygon_handler(buffer_str, &obj);
      }
    }
    fclose(fp);
  }
  normalization_object(&obj);
  return obj;
}

void detect_extreme_value(object *obj, vertex v) {
  if (obj->norm.x_min > v.x) {
    obj->norm.x_min = v.x;
  } else if (obj->norm.x_max < v.x) {
    obj->norm.x_max = v.x;
  }

  if (obj->norm.y_min > v.y) {
    obj->norm.y_min = v.y;
  } else if (obj->norm.y_max < v.y) {
    obj->norm.y_max = v.y;
  }

  if (obj->norm.z_min > v.z) {
    obj->norm.z_min = v.z;
  } else if (obj->norm.z_max < v.z) {
    obj->norm.z_max = v.z;
  }
}

void normalization_object(object *obj) {
  // сдвиг обьекта в центр

  int shift_x = (obj->norm.x_min - obj->norm.x_max) / 2 - obj->norm.x_min;
  int shift_y = (obj->norm.y_min - obj->norm.y_max) / 2 - obj->norm.y_min;
  int shift_z = (obj->norm.z_min - obj->norm.z_max) / 2 - obj->norm.z_min;

  // нахождение коэффициента нормализации
  if (fabs(obj->norm.x_min - obj->norm.x_max) > obj->norm.koef_n) {
    obj->norm.koef_n = fabs(obj->norm.x_min - obj->norm.x_max) / 2.0;
  }

  if (fabs(obj->norm.y_min - obj->norm.y_max) > obj->norm.koef_n) {
    obj->norm.koef_n = fabs(obj->norm.y_min - obj->norm.y_max) / 2.0;
  }

  if (fabs(obj->norm.z_min - obj->norm.z_max) > obj->norm.koef_n) {
    obj->norm.koef_n = fabs(obj->norm.z_min - obj->norm.z_max) / 2.0;
  }
  // привидение к рамкам от -1 до 1

  for (int i = 0; i < obj->amount_v; i++) {
    obj->v[i].x = (obj->v[i].x + shift_x) / obj->norm.koef_n;
    obj->v[i].y = (obj->v[i].y + shift_y) / obj->norm.koef_n;
    obj->v[i].z = (obj->v[i].z + shift_z) / obj->norm.koef_n;
  }
}

void init_object(object *obj) {
  obj->v = NULL;
  obj->p = NULL;

  obj->allocated_memory_p = 0;
  obj->allocated_memory_v = 0;

  obj->amount_p = 0;
  obj->amount_v = 0;

  obj->norm.koef_n = 0.001;

  obj->norm.x_max = 0;
  obj->norm.x_min = 0;
  obj->norm.y_max = 0;
  obj->norm.y_min = 0;
  obj->norm.z_max = 0;
  obj->norm.z_min = 0;
}

bool is_vertex_str(char *str) {
  bool result = false;
  if (strncmp(str, "v ", 2) == 0) {
    result = true;
  }
  return result;
}

bool is_polygon_str(char *str) {
  bool result = false;
  if (strncmp(str, "f ", 2) == 0) {
    result = true;
  }
  return result;
}

void vertex_handler(char *v_str, object *obj) {
  vertex tmp_v;
  int amount_read_arg = 0;
  tmp_v.w = 1;
  amount_read_arg = sscanf(v_str, "v %lf %lf %lf %lf", &(tmp_v.x), &(tmp_v.y),
                           &(tmp_v.z), (&tmp_v.w));

  if (amount_read_arg == 3 || amount_read_arg == 4) { // строка некоректная
    if (obj->amount_v ==
        obj->allocated_memory_v) { // подготовка памяти (проверка хватает
      // ли памяти для записи)

      obj->v = (vertex *)realloc(
          obj->v, sizeof(vertex) * (obj->allocated_memory_v * 2 + 1 + 50000));
      obj->allocated_memory_v = obj->allocated_memory_v * 2 + 1 + 50000;
    }

    detect_extreme_value(obj, tmp_v);

    (obj->v + obj->amount_v)->x = tmp_v.x;
    (obj->v + obj->amount_v)->y = tmp_v.y;
    (obj->v + obj->amount_v)->z = tmp_v.z;
    (obj->v + obj->amount_v)->w = tmp_v.w;

    obj->amount_v = obj->amount_v + 1;
  }
}

void polygon_handler(char *p_str, object *obj) {
  int f = 0;
  p_str = p_str + 2;

  char *sub_str = strtok(p_str, " ");

  if (obj->amount_p ==
      obj->allocated_memory_p) { // подготовка памяти (проверка хватает
    // ли памяти для записи)

    obj->p = (polygon *)realloc(
        obj->p, sizeof(polygon) * (obj->allocated_memory_p * 2 + 1 + 50000));
    obj->allocated_memory_p = obj->allocated_memory_p * 2 + 1 + 50000;
  }

  polygon *curent_p = obj->p + obj->amount_p;

  curent_p->amount_f = 0;
  curent_p->f = NULL;

  while (sub_str != NULL && *sub_str != '#') {
    if (sscanf(sub_str, "%i/", &f) > 0) {
      curent_p->f =
          (int *)realloc(curent_p->f, (curent_p->amount_f + 1) * sizeof(int));
      curent_p->f[curent_p->amount_f] = f;
      curent_p->amount_f++;
      sub_str = strtok(NULL, " ");
    } else {
      sub_str = NULL;
    }
  }
  if (curent_p->amount_f >= 3) {
    obj->amount_p = obj->amount_p + 1;
  } else {
    free(curent_p->f);
  }
}

void free_object(object *obj) {
  if (obj->allocated_memory_v != 0) {
    free(obj->v);
  }

  if (obj->allocated_memory_p != 0) {
    for (int i = 0; i < obj->amount_p; i++) {
      free(obj->p[i].f);
    }
    free(obj->p);
  }
  init_object(obj);
}

/* Примечание:
- Построчная обработка файла
*/
