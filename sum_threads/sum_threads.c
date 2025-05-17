#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
  int start, end;
  long long partial;
} Task;

void *workder(void *arg) {
  Task *t = arg;
  long long s = 0;
  for (int i = t->start; i < t->end; i++) {
    s += i;
    usleep(10000);
  }
  t->partial = s;
  return NULL;
}

int main(void) {
  const int STEP = 200;
  pthread_t th[5];
  Task task[5];

  for (int k = 0; k < 5; k++) {
    task[k] = (Task){.start = k * STEP, .end = (k + 1) * STEP, .partial = 0};
    pthread_create(&th[k], NULL, workder, &task[k]);
  }
  long long total_sum = 0;
  for (int k = 0; k < 5; k++) {
    pthread_join(th[k], NULL);
    total_sum += task[k].partial;
  }
  printf("sum of 1..1000 = %lld\n", total_sum);
  return 0;
}
