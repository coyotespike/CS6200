#include <stdio.h>
#include <pthread.h>

/* READERS */
Lock(counter_mutex) {
  while (resource_counter == -1) {
    wait(counter_mutex, read_phase);
      }
  resource_counter++;
}

// read data...

Lock(counter_mutex) {
  resource_counter--;
  if (readers == 0) {
    Signal(write_phase)
  }
  resource_counter++;
}

/* WRITER */
Lock(counter_mutex) {
  while (resource_counter != 0) {
    wait(counter_mutex, write_phase);
  }
  resource_counter = -1;
}
// write data ...

Lock(counter_mutex) {
  resource_counter = 0;
  Broadcast(read_phase)
  Signal(write_phase)
}

