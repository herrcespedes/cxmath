/*       Name: array.c                                   */
/*       Created on: Jun 6, 2025                         */
/*                Author: rcespedes                      */
/* ····················································· */

#include "array.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Status min_max(double *array, int size, double *result) {

  
  double max = DBL_MIN; 
  double min = DBL_MAX; 
  
  double max_index = -1.0;
  double min_index = -1.0;

  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
      max_index = i;
    }
    if (array[i] < min) {
      min = array[i];
      min_index = i;
    }
  }

  result[0] = max;
  result[1] = max_index;
  result[2] = min;
  result[3] = min_index;

  return STATUS_SUCCESS;
}

Status rotate_1d(double *array, int size, int shift) {

  // find effective shift

  int eff_shift = shift % size; // Effective shift

  if (eff_shift < 0) {
    eff_shift += size;
  }

  if (eff_shift == 0) {
    return STATUS_SUCCESS;
  }

  double *temp_arr = (double *)malloc(eff_shift * sizeof(double));
  if (temp_arr == NULL) {
    // bad alloc
    return STATUS_ERROR_INVALID_MEMORY;
  }
  // store shifted off values
  int counter2 = 0;
  for (int i = size - eff_shift; i <= size - 1; i++) {
    temp_arr[counter2] = array[i];
    counter2++;
  }
  // shift right non wrap around values
  for (int i = size - 1; i >= eff_shift; i--) {
    array[i] = array[i - eff_shift];
  }
  // copy shifted off values to beginning
  counter2 = 0;
  for (int i = 0; i < eff_shift; i++) {
    array[i] = temp_arr[counter2];
    counter2++;
  }

  // need to free temp_array
  free(temp_arr);
  return STATUS_SUCCESS;
}

Status interpolate_1d_double(double *array, int array_size, double index_d, double *result) {

  if (array == NULL || result == NULL) {
    return STATUS_ERROR_INVALID_MEMORY;
  }

  double x = index_d;
  int x1 = floor(index_d);
  int x2 = ceil(index_d);

  if (x < 0.0 || x >= (double)array_size) {
    fprintf(stderr, "Error: Index %.2f is out of array bounds\n", x);
    return STATUS_ERROR_GENERIC;
  } else if (x1 == x2) {
    return array[x1]; // index_d is an integer
  } else {
    double y1 = array[x1];
    double y2 = array[x2];

    double y = y1 + (y2 - y1) * ((x - x1) / (x2 - x1));
    return STATUS_SUCCESS;
  }
}

Status threshold_1d(double *array, double threshold, int array_size, int start_index, double *x_threshold) {

  return STATUS_ERROR_GENERIC; // Or another appropriate error code
}