#include <stdio.h>
#include <string.h>

typedef struct Elem Elem;

struct Elem {
  int value;
  Elem *next;
};



int main(void) {
  Elem *list = NULL;

  char cmd[256];
  while (scanf("%s", cmd) != EOF) {
    if (strcmp(cmd, "push-front") == 0) {
      Elem *next = list;
      list = malloc(sizeof(Elem));
      scanf("%d", &list->value);
      list->next = next;
      printf("%d\n", list->value);
    } else if (strcmp(cmd, "pop-front") == 0) {
      if (list == NULL) {
        printf("empty\n");
      } else {
        Elem *next = list->next;
        printf("%d\n", list->value);
        free(list);
        list = next;
      }
    } else if (strcmp(cmd, "push-back") == 0) {
      if (list == NULL) {
        list = malloc(sizeof(Elem));
        scanf("%d", &list->value);
        list->next = NULL;
        printf("%d\n", list->value);
      } else {
        Elem *next = list;
        while (next->next != NULL) {
          next = next->next;
        }
        next->next = malloc(sizeof(Elem));
        scanf("%d", &next->next->value);
        next->next->next = NULL;
        printf("%d\n", next->next->value);
      }
    } else if (strcmp(cmd, "peek-front") == 0) {
      if (list == NULL) {
        printf("empty\n");
      } else {
        printf("%d\n", list->value);
      }
    } else if (strcmp(cmd, "peek-back") == 0) {
      if (list == NULL) {
        printf("empty\n");
      } else {
        Elem *next = list;
        while (next->next != NULL) {
          next = next->next;
        }
        printf("%d\n", next->value);
      }
    } else if (strcmp(cmd, "size") == 0) {
      int n = 0;
      Elem *next = list;
      while (next != NULL) {
        n++;
        next = next->next;
      }
      printf("%d\n", n);
    } else if (strcmp(cmd, "clear") == 0) {
      while (list != NULL) {
        Elem *del = list;
        list = list->next;
        free(del);
      }
      printf("empty\n");
    } else if (strcmp(cmd, "dump") == 0) {
      if (list == NULL) {
        printf("empty\n");
      } else {
        printf("%d", list->value);
        Elem *next = list->next;
        while (next != NULL) {
          printf(" %d", next->value);
          next = next->next;
        }
        printf("\n");
      }
    } else {
      printf("error\n");
      return 0;
    }
  }
  return 0;
}
