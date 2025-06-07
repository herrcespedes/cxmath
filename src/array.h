/*
 * array.h
 *
 *  Created on: Jun 6, 2025
 *      Author: rcespedes
 */

#ifndef ARRAY_H_
#define ARRAY_H_

typedef enum {
  STATUS_SUCCESS = 0,
  STATUS_ERROR_GENERIC = 1,
  STATUS_ERROR_INVALID_ARGUMENT = 2,
  STATUS_ERROR_INVALID_MEMORY = 3,
  STATUS_ERROR_PERMISSION_DENIED = 4
} Status;


Status max_min(double *array, int size, double *result);

Status rotate_1d(double *array, int size, int shift);
// interpolate a 1d array with a fractional or integer index
Status interpolate_1d_int(int *array, int array_size, double indexd);
// float interpolate_1d_float(float *array, int array_size, float indexd);
Status interpolate_1d_double(double *array, int array_size, double indexd, double *result);


#endif /* ARRAY_H_ */
