#ifndef VECTOR2_H
#define VECTOR2_H


struct Vector2
{

    float x;
    float y;


    Vector2()
    {
        x = 0.0f;
        y = 0.0f;
    }


    Vector2(float xValue,float yValue)
    {
        x = xValue;
        y = yValue;
    }

};


#endif
