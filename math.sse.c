#include "fdf.h"
#include <immintrin.h>
#include <xmmintrin.h>

t_point	point_matrix_multiply_sse(t_matrix4f m, t_point v)
{
	t_point	result;

    __m128 vx = _mm_set1_ps(v.x);
    __m128 vy = _mm_set1_ps(v.y);
    __m128 vz = _mm_set1_ps(v.z);
    __m128 vw = _mm_set1_ps(v.w);

    __m128 mx = _mm_set_ps(m.m[0][3], m.m[0][2], m.m[0][1], m.m[0][0]);
    __m128 my = _mm_set_ps(m.m[1][3], m.m[1][2], m.m[1][1], m.m[1][0]);
    __m128 mz = _mm_set_ps(m.m[2][3], m.m[2][2], m.m[2][1], m.m[2][0]);
    __m128 mw = _mm_set_ps(m.m[3][3], m.m[3][2], m.m[3][1], m.m[3][0]);
 
    vx = _mm_mul_ps(mx, vx);
    vy = _mm_mul_ps(my, vy);
    vz = _mm_mul_ps(mz, vz);
    vw = _mm_mul_ps(mw, vw);

    __m128 vr = _mm_add_ps(vx, vy);
    vr = _mm_add_ps(vr, vz);
    vr = _mm_add_ps(vr, vw);
    
    _mm_store_ps((float*)&result, vr);
    
	return (result);
}