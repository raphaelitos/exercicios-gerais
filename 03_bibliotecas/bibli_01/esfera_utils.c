#include "esfera_utils.h"

float calcula_area(float R){
    return 4 * PI * (R * R);
}

float calcula_volume(float R){
    return (4 * (PI * R * R * R))/3;
}