/*
 * array.h
 *
 *  Created on: Jun 6, 2025
 *      Author: rcespedes
 */

#ifndef ARRAY_H_
#define ARRAY_H_

/**
 * @brief Return status enum
 */
typedef enum {
  STATUS_SUCCESS = 0,
  STATUS_ERROR_GENERIC = 1,
  STATUS_ERROR_INVALID_ARGUMENT = 2,
  STATUS_ERROR_INVALID_MEMORY = 3,
  STATUS_ERROR_PERMISSION_DENIED = 4
} Status;

  /**
   * @brief Searches through a double array finding the minimum and maximum values.
   * 
   * This function iterates through a 1D double array to identify its
   * minimum and maximum values, along with their respective indices.
   * The results are stored in a `dim3` array provided by the caller.
   * Parameters:
   *
   * @param array The array to search. must be 1d
   * @param size The array size
   * @param result The memory to store the results. the result is a dim3 array where,
   * - [0] = min value
   * - [1] = min value index
   * - [2] = max value
   * - [3] = max value index
   *
   * @return return	Status code
   *
   **************************************************************/
Status min_max(double *array, int size, double *result);
  
/**
 * @brief Rotates a 1d array based on the shift parameter
 * 
 * This function ...
 * 
 * @param array The array to rotate in place
 * @param size The array size
 * @param shift The amount to shift by
 * @return Status Status Code
 */
Status rotate_1d(double *array, int size, int shift);

/**
 * @brief Interpolate an array based on the equation y = y1 + (y2 - y1) * ((x - x1) / (x2 - x1))
 * 
 * @param array 
 * @param array_size 
 * @param index_d 
 * @param result 
 * @return Status 
 */
Status interpolate_1d_int(int *array, int array_size, double indexd);

/**
 * @brief 
 * 
 * @param array 
 * @param array_size 
 * @param indexd 
 * @param result 
 * @return Status 
 */
Status interpolate_1d_double(double *array, int array_size, double indexd, double *result);

#endif /* ARRAY_H_ */
