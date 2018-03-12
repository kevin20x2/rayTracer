#include "Transform.hpp"

Matrix4x4::Matrix4x4(float mat[4][4])
{
    for(int i = 0;i<4;++i)
    for(int j = 0;j<4;++j)
        this->m[i][j] = mat[4][4];
}
Matrix4x4::Matrix4x4(float t00,float t01,float t02,float t03,
              float t10,float t11 ,float t12,float t13,
              float t20,float t21,float t22,float t23,
              float t30,float t31,float t32,float t33)
{
    m[0][0] = t00;m[0][1] = t01;m[0][2] =t02;m[0][3]=t03;
    m[1][0] = t10;m[1][1] = t11;m[1][2] =t12;m[1][3]=t13;
    m[2][0] = t20;m[2][1] = t21;m[2][2] =t22;m[2][3]=t23;
    m[3][0] = t30;m[3][1] = t31;m[3][2] =t32;m[3][3]=t33;

}

Matrix4x4 Matrix4x4::Transpose(const Matrix4x4 &m)
{
    return Matrix4x4(
        m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
        m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
        m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
        m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
    );
}
Matrix4x4 Mul(const Matrix4x4 &m1,const Matrix4x4 &m2)
{
    Matrix4x4 r;
    for(int i = 0;i<4;++i)
        for (int j = 0; j < 4; ++j)
        {
            r.m[i][j] = m1.m[i][0]*m2.m[0][j] +
            m1.m[i][1] *m2.m[1][j] + 
            m1.m[i][2] *m2.m[2][j] +
            m1.m[i][3] *m2.m[3][j];
        }
    return r;
}
Matrix4x4 Inverse(const Matrix4x4 & m)
{

}