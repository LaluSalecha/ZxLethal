#ifndef MATRIX4_H
#define MATRIX4_H


struct Matrix4
{

    float data[16];


    Matrix4()
    {
        for(int i=0;i<16;i++)
        {
            data[i]=0.0f;
        }
    }


    static Matrix4 Identity()
    {
        Matrix4 matrix;


        matrix.data[0] = 1.0f;
        matrix.data[5] = 1.0f;
        matrix.data[10] = 1.0f;
        matrix.data[15] = 1.0f;


        return matrix;
    }

};


#endif
